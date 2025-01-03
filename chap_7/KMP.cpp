#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hàm tạo bảng LPS
vector<int> computeLPS(const string &pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int length = 0; // Độ dài của prefix hiện tại
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Hàm tìm kiếm chuỗi
int KMP(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPS(pattern);
    int i = 0; // Chỉ số cho text
    int j = 0; // Chỉ số cho pattern
    int count = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            count++; // Tìm thấy một lần xuất hiện
            j = lps[j - 1]; // Tiếp tục tìm kiếm
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return count;
}

int main() {
    string pattern, text;
    getline(cin, pattern);
    getline(cin, text);

    int result = KMP(text, pattern);
    cout << result << endl;

    return 0;
}