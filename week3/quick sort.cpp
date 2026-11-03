#include <iostream>
#include <vector>

using namespace std;

// Hàm phân hoạch (Partition) mảng
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Chọn phần tử chốt là phần tử cuối
    int i = (low - 1);     // Chỉ số của phần tử nhỏ hơn

    for (int j = low; j <= high - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++; // Tăng chỉ số của phần tử nhỏ hơn
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Hàm đệ quy thực hiện Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi là chỉ số nơi phần tử chốt đã về đúng vị trí
        int pi = partition(arr, low, high);

        // Đệ quy sắp xếp các phần tử trước và sau phân hoạch
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Khởi tạo mảng (tương thích cả C++98 cũ hoặc C++11 trở lên)
    int raw_arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(raw_arr) / sizeof(raw_arr[0]);
    
    vector<int> arr(raw_arr, raw_arr + n);

    cout << "Mang ban dau: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Gọi hàm Quick Sort
    quickSort(arr, 0, n - 1);

    cout << "Mang sau khi sap xep (Quick Sort): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
