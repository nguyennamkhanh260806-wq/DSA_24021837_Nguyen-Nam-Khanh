#include <iostream>
#include <algorithm>

using namespace std;


void sink(int *a, int n, int k) {
    while (2 * k <= n) {
        int j = 2 * k; 
        
        
        if (j < n && a[j] < a[j + 1]) {
            j++;
        }
        
        
        if (a[k] >= a[j]) {
            break;
        }
        
        
        swap(a[k], a[j]);
        k = j;
    }
}


void heapSort(int *a, int n) {
    
    for (int i = n / 2; i >= 1; i--) {
        sink(a, n, i);
    }

   
    for (int i = n; i > 1; i--) {
        swap(a[1], a[i]); // Đưa phần tử lớn nhất về đúng vị trí cuối heap hiện tại
        sink(a, i - 1, 1); // Đưa gốc mới chìm xuống đúng chỗ với kích thước heap giảm đi 1
    }
}

// Hàm in mảng (bỏ qua vị trí 0 do dùng 1-based index)
void printArray(int *a, int n) {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    // Vì dùng 1-based index, ta để ô a[0] trống và đưa dữ liệu vào từ ô a[1] đến a[n]
    // Giả sử mảng có 6 phần tử: {12, 11, 13, 5, 6, 7}
    int n = 6;
    int *a = new int[n + 1]; // Cấp phát kích thước n + 1
    
    int raw_data[] = {12, 11, 13, 5, 6, 7};
    for (int i = 0; i < n; i++) {
        a[i + 1] = raw_data[i];
    }

    cout << "Mang ban dau: ";
    printArray(a, n);

    // Gọi hàm Heap Sort
    heapSort(a, n);

    cout << "Mang sau khi sap xep (Heap Sort tang dan): ";
    printArray(a, n);

    // Giải phóng bộ nhớ
    delete[] a;

    return 0;
}
