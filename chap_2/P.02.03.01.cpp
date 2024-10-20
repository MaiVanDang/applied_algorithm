//Chapter 2 - Range Minimum Query
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int N;
vector<int> a;
int M[20][MAX+1];

void input(){
    cin >> N;
    a.resize(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
}

void preprocessing(){
    for(int i = 0; i < N; i++){
        M[0][i] = i;
    }
    
    for(int j = 1; (1<<j) <= N; j++){
        for(int i = 0; i + (1<<j) - 1 < N; i++){
            if(a[M[j-1][i]] < a[M[j-1][i+(1<<(j-1))]]){
                M[j][i] = M[j-1][i];
            }else{
                M[j][i] = M[j-1][i+(1<<(j-1))];
            }
        }
    }
}

int RMQ(int i, int j){
    int k = log2(j-i+1);
    if(a[M[k][i]] <= a[M[k][j-(1<<k) + 1]]){
        return a[M[k][i]];
    }else{
        return a[M[k][j-(1<<k) + 1]];
    }
}

int sum(){
    int m;
    int result = 0;
    cin >> m;
    for(int i = 1; i <= m; i++){
        int L,R;
        cin >> L >> R;
        result += RMQ(L,R);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    input();
    preprocessing();
    cout << sum();
    return 0;
}