#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll d1[N],d2[N],row[N];
ll n,cnt = 0;
vector<ll> f;
void solve(ll y)
{
    for(int x = 1;x <= n;x++) {
        ll dg1 = x + y;
        ll dg2 = x - y + 11;
        if(d1[dg1]) continue;
        if(d2[dg2]) continue;
        if(row[x]) continue;
        d1[dg1] = 1;
        d2[dg2] = 1;
        row[x] = 1;
        f.push_back(y);
        if(f.size() == n) cnt++;
        else solve(y+1);
        f.pop_back();
        d1[dg1] = 0;
        d2[dg2] = 0;
        row[x] = 0;

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    solve(1);
    cout << cnt;
    return 0;
}