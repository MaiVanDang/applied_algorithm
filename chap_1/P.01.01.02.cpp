#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    stack<int> S;
    string tmp;
    int s;
    while(cin >> tmp){
        if(tmp == "#") break;
        if(tmp == "PUSH"){
            cin >> s;
            S.push(s);
        }
        if(tmp == "POP"){
            if(S.empty()){
                cout << "NULL" << endl;
            }
            else{
                cout << S.top() << endl;
                S.pop();
            }
        }
    }
    
    return 0;
}