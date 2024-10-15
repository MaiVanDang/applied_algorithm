//Chapter 1 - Simulation Queue
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    queue<int> Q;
    string tmp;
    while(cin >> tmp){
        if(tmp == "#") break;
        if(tmp == "PUSH"){
            int value;
            cin >> value;
            Q.push(value);
        }
        if(tmp == "POP"){
            if(Q.empty()){
                cout << "NULL" << endl;
            }else{
                cout << Q.front() << endl;
                Q.pop();
            }
        }
    }
    return 0;
}