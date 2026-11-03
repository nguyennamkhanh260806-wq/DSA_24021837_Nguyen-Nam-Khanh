#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev; 
};
typedef struct node node;



// 1. Chèn vào dau$O(1)$
void themdau(node *&head, int x) {
    node *newNode = new node;
    newNode->data = x;
    newNode->next = head;
    newNode->prev = NULL;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// 2. Chèn vào cuoi o(n)
void themcuoi(node *&head, int x) {
    node *newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp; 
}

// 3. Chèn vào vi trí k o(n)
void themk(node *&head, int x, int k) {
    if (k <= 1) {
        themdau(head, x);
        return;
    }
    
    node *temp = head;
    
    for (int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        themcuoi(head, x);
        return;
    }
    
    node *newNode = new node;
    newNode->data = x;
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}



// 4. Xóa ph?n tu dau o(1)
void xoadau(node *&head) {
    if (head == NULL) return;
    
    node *temp = head;
    head = head->next;
    
    if (head != NULL) {
        head->prev = NULL; 
    }
    delete temp;
}

// 5. Xóa phan tu cuoi o(n)
void xoacuoi(node *&head) {
    if (head == NULL) return;
    
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->prev->next = NULL; 
    delete temp;
}

// 6. Xóa phan tu vi trí k o(n)
void xoak(node *&head, int k) {
    if (head == NULL) return;
    if (k <= 1) {
        xoadau(head);
        return;
    }
    
    node *temp = head;
    
    for (int i = 1; i < k && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) return;
    
    
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    delete temp;
}



// 7. Duyet xuôi o(n)
void duyetxuoi(node *head) {
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// 8. Duyet nguoc o(n)
void duyetnguoc(node *head) {
    if (head == NULL) return;
    
    node *temp = head;
   
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
   
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}


int main() {
    node *head = NULL;
    
 
    themdau(head, 10);
    themdau(head, 20); // 20 <-> 10
    themcuoi(head, 30); // 20 <-> 10 <-> 30
    themk(head, 15, 2); // 20 <-> 15 <-> 10 <-> 30
    
    cout << "Duyet xuoi: ";
    duyetxuoi(head);
    
    cout << "Duyet nguoc (khong dung de quy): ";
    duyetnguoc(head);
    
    
    xoadau(head); // 15 <-> 10 <-> 30
    xoacuoi(head); // 15 <-> 10
    themk(head, 25, 2); // 15 <-> 25 <-> 10
    xoak(head, 2); // 15 <-> 10
    
    cout << "Sau khi xoa, Duyet xuoi: ";
    duyetxuoi(head);
    
    return 0;
}
