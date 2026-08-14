#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 1e5+7;
int n,k,a[MM],b[MM];
map<pii,int> mp;

bool check(int i,int j)
{
    return (i <= n && j <= n);
}

struct cmp
{
    bool operator() (pii i,pii j)
    {
        return a[i.fi] + b[i.se] < a[j.fi] + b[j.se];
    }
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    a[n+1] = -oo; b[n+1] = -oo;
    priority_queue<pii,vector<pii>,cmp> q;
    q.push({1,1});
    int cnt = 0;
    vector<int> val;
    while(cnt < k) {
        pii U = q.top(); q.pop();
        int i = U.fi, j = U.se;

        if(mp[{i,j}]) continue;
        mp[{i,j}] = 1;

        cnt++;
        cout << a[i] + b[j] << ' ';
        q.push({i+1,j});
        q.push({i,j+1});
    }
    return 0;
}