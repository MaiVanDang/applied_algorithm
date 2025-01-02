//Bridges and Articulation Points
#include <bits/stdc++.h>
#define ft(i,x,y) for(int i = x; i<=y;i++)
using namespace std;

int n,m;
int num[100001], low[100001], cnt= 0;
bool critical_point[100001];

int p[100001];
vector <int> X[100001];

int edge = 0;
int point = 0;

void run(int u)
{
    num[u]=low[u] = ++cnt;
    int numChild = 0;
    for(int v: X[u])
    {
        if(p[u] == v) continue;
        if(num[v])
        {                                                                                                                    
            low[u] = min(low[u], num[v]);                                                  
        }
        else
        {
            p[v] = u;
            run(v);
            low[u] = min(low[u], low[v]);
            numChild ++;
            if(low[v] >= num[v]) edge ++;
            if(u == p[u])
            {
                if(numChild >= 2)
                {
                    critical_point[u] = true;
                }
            }
            else
            {
                if(low[v] >= num[u])
                {
                    critical_point[u] = true;
                }
            }
        }
    }
}
int main()
{
    // freopen("./text.input","r",stdin);
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        X[a].push_back(b);
        X[b].push_back(a);
    }
    ft(i, 1, n)
    {
        p[i] = i;
    }
    ft(i,1, n)
    {
        if(!num[i]) run(i);
    }
    ft(i,1,n)
    {
        point += critical_point[i];
    }
    cout<<point<<" "<<edge;
    return 0;
}