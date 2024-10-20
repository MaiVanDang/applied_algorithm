//Chapter 2 - Simulation prefix Sum on 2D array
#include<bits/stdc++.h>
using namespace std;
#define MAX1 1000
#define MAX2 100000

int n,m;
int A[MAX1+2][MAX1+2];
int SUM[MAX2+1];

void input(){
    cin >> n >> m;
    int c;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> c;
            A[i][j] = A[i][j-1] + c;
        }
}

int sum(int r1, int c1, int r2, int c2){
    int s = 0;
    for(int i = r1; i <= r2; i ++){
        s += A[i][c2] - A[i][c1-1];
    }
    return s;
}

void solution(){
    int c;
    int r1, c1, r2, c2;
    cin >> c;
    for(int i = 1; i <= c; i++){
        cin >> r1 >> c1 >> r2 >> c2;
        SUM[i] = sum(r1,c1,r2,c2);
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