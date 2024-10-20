//Chapter 2 - Simulation prefix sum 1-array
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

int n;
int A[MAX+2];
int SUM[MAX+2];

void input(){
    cin >> n;
    int c;
    for(int i = 1; i <= n; i++){
        cin >> c;
        A[i] = A[i-1] + c;
    }
}

int sum(int s, int e){
    return A[e] - A[s-1];
}

void solution(){
    int c;
    int s,e;
    cin >> c;
    for(int i = 1; i <= c; i++){
        cin >> s >> e;
        SUM[i] = sum(s,e);
    }
     for(int i = 1; i <= c; i++){
         cout << SUM[i] << endl;    
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    memset(A,0,sizeof(A));
    memset(SUM,0,sizeof(SUM));
    input();
    solution();
    return 0;
}