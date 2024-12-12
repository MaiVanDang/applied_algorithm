//Chapter 2 - Segment Tree Simulation - query Max
#include<bits/stdc++.h>
#define oo -1e+6
#define MAX 100000
using namespace std;
int n;
int a[MAX+1];
int m;
int maxVal[4*MAX];
void input(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
}
void build(int id, int L, int R) {
    if (L == R) {
        maxVal[id] = a[L];
    } else {
        int m = (L + R) / 2;
        build(id * 2, L, m);
        build(id * 2 + 1, m + 1, R); 
        maxVal[id] = max(maxVal[id * 2], maxVal[id * 2 + 1]); 
    }
}
int getmaxfromNode(int id, int L, int R, int i, int j){
    if(i > R || j < L) return oo;
    if(i <= L && j >= R) return maxVal[id];
    int m = (L+R)/2;
    int LC = id*2;
    int RC = id*2+1;
    int maxLeft = getmaxfromNode(LC, L, m, i, j);
    int maxRight = getmaxfromNode(RC, m+1, R, i, j);
    return max(maxLeft, maxRight);
}
int GetMax(int i, int j){
    return getmaxfromNode(1, 1, n, i, j);
}
void updatefromNode(int id, int L, int R, int index, int value){
    if(L > R) return;
    if(index < L || index > R) return;
    if(L==R){
        maxVal[id] = value;
        return;
    } 
    int m = (L+R)/2;
    int LC = id*2;
    int RC = id*2+1;
    updatefromNode(LC, L, m, index, value);
    updatefromNode(RC, m+1, R, index, value);
    maxVal[id] = max(maxVal[LC], maxVal[RC]);
}
void Update(int i, int v){
    updatefromNode(1, 1, n, i, v);
}
int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    build(1, 1, n);
    for(int i = 1; i <= m; i++){
        string c;
        cin >> c;
        if(c == "get-max"){
            int left,right;
            cin >> left >> right;
            cout << GetMax(left,right) << endl;
        }
        if(c == "update"){
           int index,value;
           cin >> index >> value;
           Update(index,value);
        }
    }
    return 0;
}