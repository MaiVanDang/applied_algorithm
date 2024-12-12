//Chapter 4 - Job Selection & Planning
#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

int n;
int totalProfit = 0;
struct Job{
    int dealine;
    int profit;
};
vector<Job> job(MAX);
bool compare(Job a, Job b){
    return a.profit > b.profit;
}
void input(){
    cin >> n;
    job.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> job[i].dealine >> job[i].profit;
    }
    sort(job.begin(), job.end(), compare);
}
void solve(){
    vector<bool> timeSlot(n, false);
    for(int i = 0; i < n; i++){
        for(int j = min(n,job[i].dealine); j > 0; j--){
            if(!timeSlot[j]){
                timeSlot[j]=true;
                totalProfit += job[i].profit;
                break;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();
    cout << totalProfit;
    return 0;
}