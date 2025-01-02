//Sum of length of paths from root on a tree
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, weight;
};

vector<Edge> tree[100001];
long long d[100001], //tổng độ dài đường đi từ các đỉnh con cháu của u đến u
          f[100001], //tổng độ dài đường đi từ các đỉnh khác đến u trên T
          N[100001];
int p[100001];
int n;

void DFS1(int u) {
    N[u] = 1; // Khởi tạo số đỉnh con cháu
    for (const auto& edge : tree[u]) {
        int v = edge.to;
        if (p[v] == 0) { // Nếu v chưa được thăm
            p[v] = u; // Gán cha
            DFS1(v); // Thăm đỉnh con
            d[u] += d[v] + (long long)N[v] * edge.weight; // Cập nhật d(u)
            N[u] += N[v]; // Cập nhật N(u)
        }
    }
}

void DFS2(int u) {
    for (const auto& edge : tree[u]) {
        int v = edge.to;
        if (p[v] == u) { // Nếu v là con của u
            long long F = f[u] - (d[v] + (long long)N[v] * edge.weight); // Tính F
            f[v] = F + d[v] + (long long)edge.weight * (n - N[v]); // Tính f(v)
            p[v] = u; // Gán cha
            DFS2(v); // Thăm đỉnh con
        }
    }
}

void Phase1(int root) {
    fill(p, p + n + 1, 0); // Đặt cha về 0 (chưa thăm)
    fill(d, d + n + 1, 0); // Khởi tạo d(v)
    fill(N, N + n + 1, 1); // Khởi tạo N(v) là 1 (tự chính nó)
    fill(f, f + n + 1, 0); // Khởi tạo f(v)
    
    p[root] = root; // Gán cha cho gốc
    DFS1(root); // Bắt đầu từ gốc
    f[root] = d[root]; // Đặt f(root) = d(root)
}

void Phase2(int root) {
    fill(p, p + n + 1, 0); // Đặt cha về 0 (chưa thăm)
    p[root] = root; // Gán cha cho gốc
    DFS2(root); // Bắt đầu từ gốc
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    // Tính toán f(1) đầu tiên
    Phase1(1);
    DFS2(1); // Tính toán f cho tất cả các đỉnh

    // Tìm giá trị lớn nhất của f(u)
    long long max_f = *max_element(f + 1, f + n + 1);
    cout << "Maximum path length sum: " << max_f << endl;

    return 0;
}