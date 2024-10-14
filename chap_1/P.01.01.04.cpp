//Simulation Upper Bound of an element in a sequence
// #include<bits/stdc++.h>
// using namespace std;

// int n;
// vector<int> A;

// void input(){
//     cin >> n;
//     A.resize(n);
//     for(int i = 0; i <n; i++){
//         cin >> A[i];
//     }
//     sort(A.begin(), A.end());
// }

// int findMIN(int k){
//     for(int i = 0; i < n; i++){
//         if(A[i] > k){
//             return A[i];
//         }
//     }
//     return -1;
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL); cout.tie(NULL);
    
//     string tmp;
//     int c;
//     input();
//     while(cin>>tmp){
//         if(tmp == "#") break;
//         cin >> c;
//         cout << findMIN(c) << endl;
//     }
    
//     return 0;
// }

//Update time

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to handle input
void input(vector<int>& A, int& n) {
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
}

// Function to find the smallest element greater than k using binary search
int findNextGreater(const vector<int>& A, int k) {
    auto it = upper_bound(A.begin(), A.end(), k);
    if (it == A.end()) {
        return -1; // No element greater than k
    }
    return *it; // Return the smallest element greater than k
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    vector<int> A;
    int n;
    input(A, n);
    
    // Sort the array for binary search
    sort(A.begin(), A.end());
    
    string query;
    int k;
    while (cin >> query) {
        if (query == "#") break; // End of queries
        cin >> k; // Read the value of k
        cout << findNextGreater(A, k) << endl; // Output the result
    }
    
    return 0;
}
