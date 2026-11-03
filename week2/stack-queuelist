#include<bits/stdc++.h>
using namespace std;
int arr[100];
int n = 0; 
// Duyet xuôi 
void duyetXuoi() {
    if (n == 0) {
        cout << "Mang rong!\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Duyet nguoc
void duyetNguoc() {
    if (n == 0) return;
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



// Chèn vào cuoi mang - O(1)
void chenCuoi(int x) {
    if (n >= 100) return; 
    arr[n] = x;
    n++;
}

// Chèn vào dau mang - O(n)
void chenDau(int x) {
    if (n >= 100) return;
  
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
    n++;
}

// Chèn vào vi trí k 
void chenViTri(int x, int k) {
    if (n >= 100 || k < 0 || k > n) return;
    
    
    for (int i = n; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
    n++;
}



// Xóacuoi - O(1)
void xoaCuoi() {
    if (n > 0) {
        n--; 
    }
}

// Xóa  dau - O(n)
void xoaDau() {
    if (n == 0) return;
    
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

// Xóa vi trí k 
void xoaViTri(int k) {
    if (n == 0 || k < 0 || k >= n) return;
    
   
    for (int i = k; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}
void push(int x) {
    chenCuoi(x); 
}
int top() {
    if (n == 0) {
        cout << "Stack rong!\n";
        return -1; 
    }
    return arr[n - 1]; 
}
int pop() {
    if (n == 0) {
        cout << "Stack rong!\n";
        return -1;
    }
    int val = top(); 
    xoaCuoi();      
    return val;
}
void enqueue(int x) {
    chenCuoi(x);
}
int front() {
    if (n == 0) {
        cout << "Queue rong!\n";
        return -1;
    }
    return arr[0]; 
}
int dequeue() {
    if (n == 0) {
        cout << "Queue rong!\n";
        return -1;
    }
    int val = front(); 
    xoaDau();          
    return val;
}
int main() {
    chenCuoi(10);
    chenCuoi(20);
    chenCuoi(30);
    duyetXuoi(); // 10 20 30
    chenDau(5);
    duyetXuoi(); // 5 10 20 30
    chenViTri(15, 2);
    duyetXuoi(); // 5 10 15 20 30
    xoaDau();
    duyetXuoi(); // 10 15 20 30
    xoaCuoi();
    duyetXuoi(); // 10 15 20
    xoaViTri(1);
    duyetXuoi(); // 10 20
    duyetNguoc(); // 20 10
// Test Stack
    cout << "--- STACK ---" << endl;
    push(10);
    push(20);
    push(30);
    cout << "Top: " << top() << endl; // 30
    cout << "Pop: " << pop() << endl; // 30
    cout << "Pop: " << pop() << endl; // 20
    
    // Xóa s?ch m?ng tru?c khi test Queue
    while(n > 0) pop(); 

    // Test Queue
    cout << "\n--- QUEUE ---" << endl;
    enqueue(100);
    enqueue(200);
    enqueue(300);
    cout << "Front: " << front() << endl; // 100
    cout << "Dequeue: " << dequeue() << endl; // 100
    cout << "Dequeue: " << dequeue() << endl; // 200
    return 0;
}
