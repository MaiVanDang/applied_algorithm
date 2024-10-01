#include<bits/stdc++.h>
using namespace std;

int n,K;
bool visited[11]={false};
int load = 0;
int x[11];
int d[121][121];
int f=0,f_MIN=2147483647;

void updateDistance(){
    for(int i = 0; i <= 2*n; i++)
        for(int j = 0; j <= 2*n; j++)
            cin >> d[i][j];
}

bool check(int v, int k){
    if(visited[v]) return false;
    if(v > n){
        if(!visited[v-n]) return false;
    }else{
        if( load + 1 > K ) return false;
    }
    return true;
}

void updateBest(){
    if(f + d[x[2*n]][0] < f_MIN){
        f_MIN = f + d[x[2*n]][0];
    }
}

int Cmin(){
    int value = 2147483647;
    for(int i = 0; i <= 2*n; i++)
        for(int j = 0; j <= 2*n; j++)
            if(visited[i] == false || visited[j] == false){
                if(d[i][j] < value && j != i) value = d[i][j];
            } 
            return value;
}

void TRY(int k){
    for(int v = 1; v <= 2*n; v++){
        if(check(v,k)){ 
            x[k]=v;
            f += d[x[k-1]][x[k]];
            visited[v] = true;
            load += (v <= n ? 1 : -1);
            if( k == 2*n ) updateBest();
            else{
                if(f + Cmin() * (2*n+1-k) < f_MIN) 
                    TRY(k+1);
            }
            load += (v <= n ? -1 : 1);
            f = f - d[x[k-1]][x[k]];
            visited[v] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    
    x[0]=0;
    cin >> n >> K ;
    updateDistance();
    TRY(1);
    cout << f_MIN ; 
    return 0;
}
