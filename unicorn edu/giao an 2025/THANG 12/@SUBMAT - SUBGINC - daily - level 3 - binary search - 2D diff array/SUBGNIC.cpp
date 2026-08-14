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
const int N = 1e3 + 2;
const int MOD = 1e9 + 7;
int n,m,a[N][N],s[N][N],q,h;
struct dta
{
    int x,y,u,v,d;
} b[N*N];
bool check(int k)
{
    memset(s,0,sizeof(s));
    for (int i=1;i<=k;i++)
    {
        s[b[i].x][b[i].y]+=b[i].d;
        s[b[i].x][b[i].v+1]-=b[i].d;
        s[b[i].u+1][b[i].y]-=b[i].d;
        s[b[i].u+1][b[i].v+1]+=b[i].d;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
    {
        s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        if (s[i][j]+a[i][j]<h) return false;
        //cout<<s[i][j]<<(j==m ? '\n' : ' ');
    }
    return true;
}
int tknp(int l,int r)
{
    int mid;
    while (l+1<r)
    {
        mid=(l+r)/2;
        if (check(mid)) r=mid; else l=mid+1;
    }
    if (check(l)) return l;
    return r;
}
int main()
{
#define TASKNAME "subginc"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(TASKNAME".inp","r" ))
    {
        freopen(TASKNAME".inp","r",stdin);
        freopen(TASKNAME".out","w",stdout);
    }
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) cin>>a[i][j];
    cin>>q>>h;
    for (int i=1;i<=q;i++) cin>>b[i].x>>b[i].y>>b[i].u>>b[i].v>>b[i].d;
    cout<<tknp(1,q);
    return 0;
}