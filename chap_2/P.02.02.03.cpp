//Chapter 2 - Sum pair of sequence equal to a number
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int n,M;
vector<int> A;

void input(){
    cin >> n >> M;
    A.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
}

int solution(){
    input();
    int res = 0;
    int i = 1, j = n;
    while(i < j){
        if(A[i] + A[j] == M){
            res += 1; i += 1; j -= 1;
        }
        else if(A[i] + A[j] < M){
            i += 1;
        }else{
            j -= 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cout << solution();
    return 0;
}