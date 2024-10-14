#include<bits/stdc++.h>
using namespace std;
int n;
set<int> S;

void input(){
    cin >> n;
    int value;
    for(int i = 0; i < n; i++){
        cin >> value;
        S.insert(value);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    input();
    string tmp;
    int v;
    while(cin >> tmp){
        if(tmp == "#") break;
        if(tmp == "min_greater_equal"){
            int value;
            cin >> value;
            auto it = S.lower_bound(value);
            if (it != S.end()) {
                cout << *it << endl;
            } else {
                cout << "NULL" << endl;
            }
        }
        if(tmp == "min_greater"){
            int value;
            cin >> value;
            auto it = S.upper_bound(value);
            if (it != S.end()) {
                cout << *it << endl;
            } else {
                cout << "NULL" << endl;
            }
        }
        if(tmp == "insert"){
            int value;
            cin >> value;
            S.insert(value);
        }
        if(tmp == "remove"){
            int value;
            cin >> value;
            if(S.find(value) != S.end()){
                S.erase(value); 
            }
        }
    }
    
    return 0;
}