//Max Even SubSequence
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6+1;
int n;
long long a[MAX];
long long S0[MAX];
long long S1[MAX];
bool B0[MAX];
bool B1[MAX];

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solve(){
    if(a[1]%2 == 0){
        S0[1] = a[1];
        B0[1] = true;
        B1[1] = false;
    }else{
        S1[1] = a[1];
        B1[1] = true;
        B0[1] = false;
    }
    for(int i = 2; i <= n; i++){
        if(a[i]%2==0){
            if(B0[i-1]){
                if(S0[i-1] > 0) S0[i] = S0[i-1] + a[i];
                else S0[i] = a[i];
                B0[i] = true;
            }else{
                S0[i] = a[i];
                B0[i] = true;
            }
            if(B1[i-1]){S1[i] = S1[i-1] + a[i]; B1[i] = true;} 
            else{B1[i] = false;}
        }else{
            if(B1[i-1]){
                S0[i] = S1[i-1] + a[i];
                B0[i] = true;
            }else{
                B0[i] = false;
            }
            if(B0[i-1]){
                if(S0[i-1] > 0){
                    S1[i] = S0[i-1] + a[i];
                }else{
                   S1[i] = a[i]; 
                } 
                B1[i] = true;
            }else{
                S1[i] = a[i];
                B1[i] = true;
            }
        }
    }
    long long ans = -1e18;
    for(int i = 1; i <= n; i++){
        if(B0[i] && ans < S0[i]){
            ans = S0[i];
        }
    }
    if(ans < 0 ) cout << "NOT_FOUND" << endl;
    else cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}