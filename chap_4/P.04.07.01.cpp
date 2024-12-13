//Chapter 4 - Inversion
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long merge(vector<int>& arr, int left, int mid, int right){
    vector<int> a;
    
    int i = left, j = mid + 1;
    long long split = 0;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            a.push_back(arr[i]);
            i++;
        }else{
            a.push_back(arr[j]);
            split += mid - i + 1;
            j++;
        }
    }
    while(i <= mid){
        a.push_back(arr[i]);
        i++;
    }
    while(j <= right){
        a.push_back(arr[j]);
        j++;
    }
    for(int num = 0; num < a.size(); num++){
        arr[left + num] = a[num];
    }
    return split;
}
long long mergesort(vector<int>& arr, int left, int right){
    if(left >= right) return 0;
    int mid = left + (right - left) / 2;
    long long leftMergeSort = mergesort(arr, left, mid);
    long long rightMergeSort = mergesort(arr,mid+1,right);
    long long split = merge(arr, left, mid, right);
    return (leftMergeSort + rightMergeSort + split) % MOD;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << mergesort(arr, 0, n - 1) << endl;
    return 0;
}