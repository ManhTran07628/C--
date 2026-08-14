#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll p[N];
vector<ll> f;
void sieve()
{
    fill(p+1,p+N+1,1);
    p[0] = p[1] = 0;
    for(int i = 2;i < sqrt(N);i++)
        if(p[i])   
            for(int j = i*2;j < N;j+=i)
                p[j] = 0;
    for(int i = 1;i < N;i++)
        if(p[i]) f.push_back(i);
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
    sieve();
    ll t;
    cin >> t;
    while(t--) {
        ll x,y;
        cin >> x >> y;
        ll p = upper_bound(f.begin(),f.end(),x+y) - f.begin();
        cout << f[p] - x - y << '\n';
    }
    return 0;
}