//Parallel Job Execution
#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
int n;
vector<int> a(MAX);
int Te = 0, Ts[MAX];
void input(){
    cin >> n;
    a.resize(n+1);
    memset(Ts, 0, n + 1);
    for(int i = 1; i <= n; i++){
      cin >> a[i];  
    }
    sort(a.begin(), a.end(), greater<int>());
}
void solve(){
    for(int i = 0; i < n; i++){
        Ts[i+1] = i;
        if(Te < a[i] + Ts[i+1])
            Te = a[i] + Ts[i+1];
    }
}
int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();
    cout << Te;
    return 0;
}