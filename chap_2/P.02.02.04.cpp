//Chapter 2 - Longest Bounded SubSequence
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int n,Q;
vector<int> A;

void input(){
    cin >> n >> Q;
    A.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
}

int solution(){
    input();
    int res = 0;
    int L = 1;
    int S = 0;
    for(int R = 1; R <= n; R++){
        S += A[R];
        while(S > Q){
            S -= A[L];
            L += 1;
        }
        res = max(res,R-L+1);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cout << solution();
    return 0;
}