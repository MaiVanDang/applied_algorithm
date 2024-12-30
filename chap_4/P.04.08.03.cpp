//Chapter 4 - Warehouse
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int T,N,D;
int a[MAX+2];
int t[MAX+2];
int f[MAX+2][102]; //2D array for dynamic programming, where f[i][k] represents the maximum goods collected by visiting up to station i with total time k.
int res;

void input(){
    cin >> N >> T >> D;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> t[i];
    }
}

void solve(){
    for(int i = 1; i <= N; i++){
        for(int k = t[i]; k <= T; k++){
            for(int j = max(0,i-D); j <= i - 1; j++){
                f[i][k] = max(f[i][k], f[j][k - t[i]] + a[i]);
            }
            res = max(res, f[i][k]);
        }
    }
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}