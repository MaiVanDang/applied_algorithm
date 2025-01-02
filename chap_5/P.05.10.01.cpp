#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;
#define MAX_N 100001

int n;
vector<int> A[MAX_N];
vector<int> A1[MAX_N]; // residual graph

// data structure for DFS
int f[MAX_N]; // finishing time
char color[MAX_N];
int t;
int icc[MAX_N]; // icc[v]: index of the strongly connected component containing v
int ncc; // number of connected components in the second DFS
int x[MAX_N]; // sorted-list (decreasing of finishing time) of nodes visited by DFS
int idx;

// Vector to store all strongly connected components
vector<vector<int>> sccComponents;

void buildResidualGraph() { // xây dựng đồ thị dư
    for (int u = 1; u <= n; u++) {
        for (int j = 0; j < A[u].size(); j++) {
            int v = A[u][j];
            A1[v].push_back(u);
        }
    }
}

void init() {
    for (int v = 1; v <= n; v++) {
        color[v] = 'W';
    }
    t = 0;
}

// DFS on the original graph
void dfsA(int s) {
    t++;
    color[s] = 'G';
    for (int j = 0; j < A[s].size(); j++) {
        int v = A[s][j];
        if (color[v] == 'W') { dfsA(v); }
    }
    t++;
    f[s] = t;
    color[s] = 'B';
    idx++;
    x[idx] = s;
}

void dfsA() {
    init();
    idx = 0;
    for (int v = 1; v <= n; v++) {
        if (color[v] == 'W') {
            dfsA(v);
        }
    }
}

// DFS on the residual graph
void dfsA1(int s, vector<int>& component) {
    color[s] = 'G'; 
    icc[s] = ncc; 
    component.push_back(s); // Thêm đỉnh vào thành phần
    for (int j = 0; j < A1[s].size(); j++) {
        int v = A1[s][j];
        if (color[v] == 'W') { 
            dfsA1(v, component); 
        }
    }
    color[s] = 'B';
}

void dfsA1() {
    init();
    ncc = 0; 
    for (int i = n; i >= 1; i--) {
        int v = x[i]; 
        if (color[v] == 'W') {
            ncc++; // Tăng số thành phần liên thông mạnh
            vector<int> component; // Vector để lưu thành phần liên thông
            dfsA1(v, component); // Gọi DFS cho thành phần mới
            sccComponents.push_back(component); // Lưu thành phần vào danh sách
        }
    }
}

void solve() {
    dfsA(); 
    buildResidualGraph(); 
    dfsA1(); 
    
    // In ra số thành phần liên thông mạnh
    cout << ncc << endl;
    
    // In ra các thành phần liên thông mạnh
    // for (const auto& component : sccComponents) {
    //     for (int vertex : component) {
    //         cout << vertex << " ";
    //     }
    //     cout << endl; // Xuống dòng sau mỗi thành phần
    // }
}

void input() {
    int m;
    cin >> n >> m; 
    for (int k = 1; k <= m; k++) {
        int u, v;
        cin >> u >> v; 
        A[u].push_back(v); // Thêm cạnh vào đồ thị
    }
}

int main() {
    input(); 
    solve(); 
    return 0;
}