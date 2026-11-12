#include <bits/stdc++.h>
using namespace std;

// 1. Hàm swim (Dùng cho 1-based index: cha là k/2)
void swim(int *a, int k) {
    while (k > 1 && a[k / 2] < a[k]) { 
        swap(a[k], a[k / 2]);
        k = k / 2;
    }
}

// 2. Hàm insert (Có t? d?ng c?p phát l?i khi m?ng d?y)
void insert(int *&a, int &n, int &capacity, int x) {
    if (n + 1 >= capacity) { // Ki?m tra n?u vu?t quá dung lu?ng
        capacity *= 2;
        int *new_a = new int[capacity];
        for (int i = 0; i <= n; i++) {
            new_a[i] = a[i];
        }
        delete[] a;
        a = new_a;
    }
    
    n++;
    a[n] = x;
    swim(a, n);
}

// 3. Ðã s?a l?i v? trí d?u ngo?c nh?n c?a hàm sink
void sink(int *a, int n, int k) {
    while (2 * k <= n) {
        int j = 2 * k;
        // Tìm con l?n hon gi?a con trái (j) và con ph?i (j + 1)
        if (j < n && a[j] < a[j + 1]) {
            j++;
        }
        
        // N?u nút cha l?n hon ho?c b?ng con l?n nh?t thì d?ng
        if (a[k] >= a[j]) {
            break;
        }
        
        // Ngu?c l?i thì d?i ch? và ti?p t?c sink xu?ng du?i
        swap(a[k], a[j]);
        k = j;
    }
}

// 4. Hàm delMax (L?y g?c a[1])
int delMax(int *a, int &n) {
    if (n < 1) return -1; // Heap tr?ng
    
    int maxVal = a[1];
    a[1] = a[n]; // Ðua ph?n t? cu?i lên g?c
    n--;
    sink(a, n, 1);
    
    return maxVal;
}

// In heap t? v? trí 1 d?n n
void printHeap(int *a, int size) {
    for (int i = 1; i <= size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int capacity = 5; // Kh?i t?o dung lu?ng ban d?u
    int size = 0;     // S? lu?ng ph?n t? hi?n t?i (g?c ? v? trí 1)
    int *a = new int[capacity]; // C?p phát d?ng

    insert(a, size, capacity, 10);
    insert(a, size, capacity, 20);
    insert(a, size, capacity, 15);
    insert(a, size, capacity, 30);
    insert(a, size, capacity, 40);

    cout << "Heap sau khi insert (10, 20, 15, 30, 40): ";
    printHeap(a, size);

    // L?y ra ph?n t? l?n nh?t
    cout << "Phan tu lon nhat vua xoa (delMax): " << delMax(a, size) << endl;
    cout << "Heap sau khi delMax: ";
    printHeap(a, size);

    // Gi?i phóng b? nh?
    delete[] a;

    return 0;
}
