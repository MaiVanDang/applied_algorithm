//hortest Path between 2 nodes on a directed graph with non-negative weights
#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 7;
const int INF = 1e9; // Đại diện cho vô cùng
int n, m;
vector<pair<int, int>> adj[N]; // Danh sách kề để lưu trữ (đỉnh, trọng số)
int dist[N]; // Khoảng cách ngắn nhất từ s đến các đỉnh
int s, t;
vector<int> path; // Vector để lưu các đỉnh đã đi

void input() {
    cin >> n >> m;
    int u, v, weight;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> weight;
        adj[u].emplace_back(v, weight); // Thêm cung (u, v) với trọng số
    }
    cin >> s >> t; // Đọc hai nút s và t
}

void dijkstra() {
    fill(dist, dist + N, INF); // Đặt khoảng cách ban đầu là vô cùng
    dist[s] = 0; // Khoảng cách từ s đến s là 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap
    pq.emplace(0, s); // Đưa đỉnh s vào hàng đợi ưu tiên

    while (!pq.empty()) {
        int d = pq.top().first; // Trọng số hiện tại
        int u = pq.top().second; // Đỉnh hiện tại
        pq.pop();

        // Nếu trọng số hiện tại lớn hơn khoảng cách đã lưu, bỏ qua
        if (d > dist[u]) continue;

        // Duyệt qua các đỉnh kề
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) { // Nếu tìm thấy đường đi ngắn hơn
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v); // Cập nhật trọng số và thêm vào hàng đợi
                path.push_back(v); // Lưu đỉnh đã đi
            }
        }
    }
}

void printPath() {
    cout << "Các đỉnh đã đi: ";
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input(); // Nhập dữ liệu
    path.push_back(s); // Bắt đầu từ đỉnh s
    dijkstra(); // Thực hiện thuật toán Dijkstra

    // Kết quả
    if (dist[t] == INF) {
        cout << -1 << endl; // Không tìm thấy đường đi
    } else {
        cout << "Độ dài đường đi từ " << s << " đến " << t << ": " << dist[t] << endl;
        printPath(); // In ra các đỉnh đã đi
    }

    return 0;
}#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 7;
const int INF = 1e9; // Đại diện cho vô cùng
int n, m;
vector<pair<int, int>> adj[N]; // Danh sách kề để lưu trữ (đỉnh, trọng số)
int dist[N]; // Khoảng cách ngắn nhất từ s đến các đỉnh
int s, t;
vector<int> path; // Vector để lưu các đỉnh đã đi

void input() {
    cin >> n >> m;
    int u, v, weight;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> weight;
        adj[u].emplace_back(v, weight); // Thêm cung (u, v) với trọng số
    }
    cin >> s >> t; // Đọc hai nút s và t
}

void dijkstra() {
    fill(dist, dist + N, INF); // Đặt khoảng cách ban đầu là vô cùng
    dist[s] = 0; // Khoảng cách từ s đến s là 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap
    pq.emplace(0, s); // Đưa đỉnh s vào hàng đợi ưu tiên

    while (!pq.empty()) {
        int d = pq.top().first; // Trọng số hiện tại
        int u = pq.top().second; // Đỉnh hiện tại
        pq.pop();

        // Nếu trọng số hiện tại lớn hơn khoảng cách đã lưu, bỏ qua
        if (d > dist[u]) continue;

        // Duyệt qua các đỉnh kề
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) { // Nếu tìm thấy đường đi ngắn hơn
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v); // Cập nhật trọng số và thêm vào hàng đợi
                path.push_back(v); // Lưu đỉnh đã đi
            }
        }
    }
}

void printPath() {
    cout << "Các đỉnh đã đi: ";
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input(); // Nhập dữ liệu
    path.push_back(s); // Bắt đầu từ đỉnh s
    dijkstra(); // Thực hiện thuật toán Dijkstra

    // Kết quả
    if (dist[t] == INF) {
        cout << -1 << endl; // Không tìm thấy đường đi
    } else {
        cout << "Độ dài đường đi từ " << s << " đến " << t << ": " << dist[t] << endl;
        printPath(); // In ra các đỉnh đã đi
    }

    return 0;
}