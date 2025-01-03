#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Hàm tính bảng last
void computeLast(const string &p, vector<int> &last) {
    for (int c = 0; c < 256; c++) {
        last[c] = -1; // Khởi tạo giá trị last cho tất cả ký tự
    }
    
    int k = p.length();
    for (int i = k - 1; i >= 0; i--) {
        if (last[p[i]] == -1) {
            last[p[i]] = i; // Lưu vị trí xuất hiện cuối cùng của ký tự
        }
    }
}

// Hàm tìm kiếm Boyer-Moore
int boyerMoore(const string &P, const string &T) {
    vector<int> last(256); // Bảng last cho 256 ký tự ASCII
    computeLast(P, last);
    
    int s = 0; // Vị trí bắt đầu trong văn bản
    int cnt = 0; // Đếm số lần xuất hiện
    int N = T.length();
    int M = P.length();
    
    while (s <= N - M) {
        int j = M - 1; // Bắt đầu từ cuối mẫu
        while (j >= 0 && T[s + j] == P[j]) {
            j--; // So sánh từ phải sang trái
        }
        
        if (j < 0) {
            cnt++; // Nếu tìm thấy, tăng số lần xuất hiện
            s++; // Di chuyển 1 vị trí
        } else {
            int k = last[T[s + j]]; // Lấy vị trí xuất hiện cuối cùng của ký tự
            s += max(1, j - k); // Di chuyển vị trí bắt đầu
        }
    }
    
    return cnt;
}

int main() {
    string pattern, text;
    getline(cin, pattern);
    getline(cin, text);

    int result = boyerMoore(pattern, text);
    cout << result << endl;

    return 0;
}