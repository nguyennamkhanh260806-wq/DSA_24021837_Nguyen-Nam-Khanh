#include <iostream>
#include <string>

using namespace std;

struct Symbol {
    string name;
    string type;
    Symbol* next;
    
    // Constructor khởi tạo tự động
    Symbol(string n, string t, Symbol* nxt = nullptr) 
        : name(n), type(t), next(nxt) {}
};

class SymbolTable {
private:
    Symbol* head;
    
public:
    SymbolTable() : head(nullptr) {}

    // Thêm mới hoặc Cập nhật (Upsert)
    void insert(const string& name, const string& type) {
        // 1. Duyệt tìm xem name đã tồn tại chưa
        for (Symbol* p = head; p != nullptr; p = p->next) {
            if (p->name == name) {
                p->type = type; // Nếu có, cập nhật type mới
                return;
            }
        }
        
        // 2. Nếu chưa có, tạo Node mới và đẩy ngay vào đầu danh sách (chỉ tốn 1 dòng)
        head = new Symbol(name, type, head);
    }

    // Tìm kiếm (trả về con trỏ tới Node)
    Symbol* lookup(const string& name) {
        for (Symbol* p = head; p != nullptr; p = p->next) {
            if (p->name == name) return p;
        }
        return nullptr;
    }

    // Xóa (Tối ưu bằng Con trỏ kép - Pointer to Pointer)
    void remove(const string& name) {
        Symbol** indirect = &head; // Con trỏ trỏ tới con trỏ (ban đầu trỏ vào head)
        
        while (*indirect != nullptr) {
            if ((*indirect)->name == name) {
                Symbol* target = *indirect;       // Bắt lấy Node cần xóa
                *indirect = (*indirect)->next;    // Khâu thẳng node trước đó vào node phía sau
                delete target;                    // Giải phóng bộ nhớ
                return;
            }
            indirect = &((*indirect)->next);      // Tiến con trỏ kép về phía trước
        }
    }

    // Hiển thị
    void display() {
        cout << "\nName\t\tType\n";
        cout << "------------------------\n";
        for (Symbol* p = head; p != nullptr; p = p->next) {
            cout << p->name << "\t\t" << p->type << endl;
        }
        cout << endl;
    }

    // Destructor (Dọn dẹp bộ nhớ)
    ~SymbolTable() {
        while (head != nullptr) {
            Symbol* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SymbolTable st;

    // Test thêm dữ liệu
    st.insert("counter", "int");
    st.insert("average", "float");
    st.insert("isValid", "bool");
    cout << "Sau khi them 3 bien:";
    st.display();

    // Test cập nhật (đổi isValid từ bool sang int)
    st.insert("isValid", "int");
    cout << "Sau khi cap nhat isValid thanh int:";
    st.display();

    // Test lookup
    Symbol* s = st.lookup("average");
    if (s) {
        cout << "[Tim kiem] Tim thay: " << s->name << " kieu " << s->type << "\n";
    }

    // Test xóa ở ngay đầu, ở giữa và xóa phần tử không tồn tại
    st.remove("isValid"); // Thử xóa node nằm sâu
    st.remove("counter"); // Thử xóa node vừa chèn (ở đầu)
    st.remove("unknown"); // Xóa biến không có thật
    
    cout << "\nSau khi xoa counter va isValid:";
    st.display();

    return 0;
}
