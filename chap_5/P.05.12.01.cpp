//Max Flow
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000; // Số đỉnh tối đa
const int MAXM = 1000000; // Số cạnh tối đa

// Định nghĩa cấu trúc cạnh
struct Edge {
    int to, capacity, flow, reverseIndex;
};

vector<Edge> graph[MAXN]; // Đồ thị
int level[MAXN]; // Mức độ của các đỉnh
int n, m; // Số đỉnh và số cạnh

// Hàm thêm cạnh vào đồ thị
void addEdge(int from, int to, int capacity) {
    graph[from].push_back({to, capacity, 0, (int)graph[to].size()});
    graph[to].push_back({from, 0, 0, (int)graph[from].size() - 1}); // Cạnh ngược
}

// Hàm BFS để tìm đường đi tăng
bool bfs(int source, int sink) {
    fill(level, level + n + 1, -1);
    queue<int> q;
    q.push(source);
    level[source] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const auto& edge : graph[u]) {
            if (level[edge.to] < 0 && edge.flow < edge.capacity) {
                level[edge.to] = level[u] + 1;
                q.push(edge.to);
                if (edge.to == sink) return true; // Đến đích
            }
        }
    }
    return false; // Không tìm thấy đường đi
}

// Hàm DFS để tìm dòng chảy tối đa
int dfs(int u, int flow, int sink) {
    if (u == sink) return flow;

    for (auto& edge : graph[u]) {
        if (level[edge.to] == level[u] + 1 && edge.flow < edge.capacity) {
            int currentFlow = min(flow, edge.capacity - edge.flow);
            int tempFlow = dfs(edge.to, currentFlow, sink);
            if (tempFlow > 0) {
                edge.flow += tempFlow; // Cập nhật dòng chảy
                graph[edge.to][edge.reverseIndex].flow -= tempFlow; // Cập nhật dòng chảy ngược
                return tempFlow;
            }
        }
    }
    return 0; // Không có dòng chảy
}

// Hàm tính dòng chảy cực đại
int edmondsKarp(int source, int sink) {
    int totalFlow = 0;
    while (bfs(source, sink)) {
        while (int flow = dfs(source, INT_MAX, sink)) {
            totalFlow += flow;
        }
    }
    return totalFlow;
}

// Hàm in ra luồng tối đa
void printMaxFlow(int source, int sink) {
    cout << "Max flow along the edges:" << endl;
    for (int u = 1; u <= n; u++) {
        for (const auto& edge : graph[u]) {
            if (edge.flow > 0 && edge.to != source) { // In ra nếu có dòng chảy
                cout << u << " -> " << edge.to << " with flow " << edge.flow << endl;
            }
        }
    }
}

int main() {
    cin >> n >> m; // Nhập số đỉnh và số cạnh
    int s, t;
    cin >> s >> t; // Nhập nguồn và đích

    for (int i = 0; i < m; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity; // Nhập các cạnh
        addEdge(u, v, capacity); // Thêm cạnh vào đồ thị
    }

    int maxFlow = edmondsKarp(s, t); // Tính dòng chảy cực đại
    cout << "Maximum flow: " << maxFlow << endl; // In ra kết quả

    printMaxFlow(s, t); // In ra luồng tối đa

    return 0;
}