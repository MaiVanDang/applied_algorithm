//Chapter 3 - Cut Material
#include<bits/stdc++.h> 
using namespace std;

int H,W;
int n;
int h[11],w[11];
bool visted[11][11];
int result = 0;

void input() {
    cin >> H >> W;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> w[i];
    }
    memset(visted, false, sizeof(visted));
}

bool check1(int x, int y, int h, int w){
    if (x + h - 1 > H || y + w - 1 > W) {
        return false;
    }
    
    for(int i = x; i < x+h; i++){
        for(int j = y; j < y+w; j++){
            if(visted[i][j]) return false;
        }
    }
    return true;
}

int check2(int x, int y, int h, int w){
    if (x + w - 1 > H || y + h - 1 > W) {
        return false;
    }
    
    for(int i = x; i < x+w; i++){
        for(int j = y; j < y+h; j++){
            if(visted[i][j]) return false;
        }
    }
    return true;
}

void update1(int x, int y, int hi, int wi){
    for(int i = x; i < x+hi; i++){
        for(int j = y; j < y+wi; j++){
            visted[i][j] = true;
        }
    }
}

void update2(int x, int y, int hi, int wi){
    for(int i = x; i < x+wi; i++){
        for(int j = y; j < y+hi; j++){
            visted[i][j] = true;
        }
    }
}

void reagain1(int x, int y, int hi, int wi){
    for(int i = x; i < x+hi; i++){
        for(int j = y; j < y+wi; j++){
            visted[i][j] = false;
        }
    }
}

void reagain2(int x, int y, int hi, int wi){
    for(int i = x; i < x+wi; i++){
        for(int j = y; j < y+hi; j++){
            visted[i][j] = false;
        }
    }
}

void TRY(int k){
    if(k > n){
        result = 1;
        return;
    }
    
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(check1(i,j,h[k],w[k])){
                update1(i,j,h[k],w[k]);
                TRY(k+1);
                reagain1(i,j,h[k],w[k]);
            }
            if(check2(i,j,h[k],w[k])){
                update2(i,j,h[k],w[k]);
                TRY(k+1);
                reagain2(i,j,h[k],w[k]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    input();
    TRY(1);
    cout << result;
    return 0;
}