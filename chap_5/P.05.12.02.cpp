//Max Matching on Bipartie Graph
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000; // Số lượng nhiệm vụ và nhân viên tối đa

vector<int> graph[MAXN + 1]; // Đồ thị để lưu trữ mối quan hệ giữa nhiệm vụ và nhân viên
int match[MAXN + 1]; // Mảng lưu trữ ghép cặp cho nhân viên
bool visited[MAXN + 1]; // Mảng đánh dấu các nhiệm vụ đã được thăm

// Hàm DFS để tìm ghép cặp
bool dfs(int task) {
    for (int staff : graph[task]) {
        if (!visited[staff]) {
            visited[staff] = true; // Đánh dấu nhân viên đã thăm

            // Nếu nhân viên chưa có nhiệm vụ nào hoặc nếu có thể ghép cặp lại
            if (match[staff] == -1 || dfs(match[staff])) {
                match[staff] = task; // Ghép cặp nhân viên với nhiệm vụ
                return true;
            }
        }
    }
    return false; // Không tìm thấy ghép cặp
}

// Hàm tính ghép cặp tối đa
int maxMatching(int n) {
    fill(match, match + MAXN + 1, -1); // Khởi tạo mảng ghép cặp
    int result = 0;

    for (int task = 1; task <= n; task++) {
        fill(visited, visited + MAXN + 1, false); // Đặt lại mảng đã thăm
        if (dfs(task)) {
            result++; // Nếu tìm thấy ghép cặp, tăng số lượng
        }
    }
    return result;
}

int main() {
    int n, m; // Số nhiệm vụ và nhân viên
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int k; // Số nhân viên có thể thực hiện nhiệm vụ i
        cin >> k;
        for (int j = 0; j < k; j++) {
            int staff;
            cin >> staff; // Nhân viên có thể thực hiện nhiệm vụ i
            graph[i].push_back(staff); // Thêm vào đồ thị
        }
    }

    int result = maxMatching(n); // Tính ghép cặp tối đa
    cout << result << endl; // In ra kết quả

    return 0;
}