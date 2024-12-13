//Chapter 4 - Max-Distance Sub-Sequence
#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

int T, N, C;
long long x[MAX+1];
bool check(long long distance){
    int sl = 1;
    long long point = x[1];
    
    while(true){
        point += distance;
        auto it = lower_bound(x + 1,x + N + 1,point);
        if(it == x + 1 + N) return false;
        sl++;
        if(sl >= C) return true;
        point = *it;
    }
}
long long MaxQuence(){
    long long l = 0;
    long long r = x[N] - x[1];
    while(l <= r){
        long long mid = l + (r-l)/2;
        if(check(mid))  l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N >> C;
        for(int i = 1; i <= N; i++) cin >> x[i];
        sort(x+1, x+N+1);
        cout << MaxQuence()<<endl;
    }
    return 0;
}