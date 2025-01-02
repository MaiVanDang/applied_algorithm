//Minimum Spanning Tree - Kruskal
#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u, v;
    int w;
};

const int maxn  = 1000001;
int n, m;
int parent[maxn], sz[maxn];
vector<edge> canh;

void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false; // Khong the gop a va b voi nhau
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        edge e = {x, y, w};
        canh.push_back(e);
    }
}

bool cmp(edge a, edge b){
    return a.w < b.w;
}

void kruskal(){
    //Tao cay khung cuc tieu rong
    vector<edge> mst;
    int total_weight = 0;
    //sort danh sach canh theo chieu dai tang danh
    sort(canh.begin(), canh.end(), cmp);
    //Buoc 3 lap
    for(int i = 0; i< m; i++){
        if(mst.size() == n - 1) break;
        edge e = canh[i]; // chon canh e la canh nho nhat
        if(Union(e.u, e.v)){
            mst.push_back(e);
            total_weight += e.w;
        }
    }
    
    //Tra ve ket qua
    if(mst.size() != n-1){
        cout << "Do thi khong lien thon !\n";
    }
    else{
        //cout << "MST: " << total_weight << endl;
        cout << total_weight << endl;
        // for(auto it : mst){
        //     cout << it.u << " " << it.v << endl;
        // }
    }
}

int main(){
    input();
    make_set();
    kruskal();
    return 0;
}