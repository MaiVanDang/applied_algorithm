#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 7;
int n;
unordered_map<int, unordered_map<int, int>> w;
vector<int> adj[N];  //luu canh ke
vector<int> parent(N, -1); // Lưu cha của mỗi đỉnh
int d[N];

void input(){
    cin >> n;
    int u, v, distance;
    for (int i = 0; i < n-1; i++) {
		cin >> u >> v >> distance;
		adj[u].push_back(v);
		adj[v].push_back(u);
		w[u][v] = w[v][u] = distance;
	}
}

void dfs(int u) {
	for (int v : adj[u]) {
		if (d[v] == -1) {
			d[v] = d[u] + w[u][v];
			parent[v] = u; // Lưu cha
			dfs(v);
		}
	}
}

int LongestPath(vector<int>& path) {
	memset(d, -1, sizeof(d));
	d[1] = 0;// Khởi tạo khoảng cách từ đỉnh gốc
	dfs(1);// Thực hiện DFS từ đỉnh 1
	int x = 1, maxDist = 0;
	for (int u = 1; u <= n; u++) {
		if (d[u] > maxDist) {
			maxDist = d[u];
			x = u;
		}
	}
	parent.assign(N, -1); // Đặt lại cha
	memset(d, -1, sizeof(d));
	d[x] = 0; // Khởi tạo khoảng cách từ đỉnh x
	dfs(x);
	int y = x; 
	maxDist = 0;
	for (int u = 1; u <= n; u++) {
		if (d[u] > maxDist) {
			maxDist = d[u];
			y = u;
		}
	}
	
	// Lưu đường đi
    for (int v = y; v != -1; v = parent[v]) {
        path.push_back(v);
    }
	return d[y];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    vector<int> path; // Vector để lưu đường đi
    int longestDistance = LongestPath(path);
    
    cout << "Độ dài đường đi dài nhất: " << longestDistance << endl;
    cout << "Đường đi: ";
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}