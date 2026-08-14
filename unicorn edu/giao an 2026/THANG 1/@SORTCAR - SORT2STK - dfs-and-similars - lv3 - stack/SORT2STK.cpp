#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b / __gcd(a,b)
#define I first
#define II second
#define pb push_back
#define ii pair<int,int>
const int INF = 2 * 1e9;
const int N = 1e3 + 1;
const int MOD = 1e9 + 7;
stack<int> q[3];
int n,d[N];
int main()
{
#define TASKNAME "*"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(TASKNAME".inp","r" ))
    {
        freopen(TASKNAME".inp","r",stdin);
        freopen(TASKNAME".out","w",stdout);
    }
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;cin>>x;
        d[x]=1;q[1].push(x);
        cout<<1<<'\n';
    }
    for (int i=1;i<=n;i++)
    {
        int x=d[i],y=(d[i]==1 ? 2 : 1);
        while (q[x].top()!=i)
        {
            int u=q[x].top();q[x].pop();
            cout<<x<<y<<'\n';q[y].push(u);d[u]=y;
        }
        cout<<'-'<<x<<'\n';q[x].pop();
    }
    return 0;
}