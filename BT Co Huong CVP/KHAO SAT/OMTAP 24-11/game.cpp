#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int t,prime[MM];
int a,b,c,d;
void sieve()
{
    for(int i = 2;i < MM;i++) prime[i] = 1;

    for(ll i = 2;i * i < MM;i++)    
        if(prime[i])
            for(ll j = i*i;j < MM;j+=i)
                prime[j] = 0;
}



bool solve()
{
    for(int i = a;i <= b;i++) {
        int ok = 1;
        for(int j = c;j <= d;j++) {
            if(prime[i+j]) ok = 0;
        }
        if(ok) return 1;
    }
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "game"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d;
        cout << (!solve() ? "Cam" : "Tam") << '\n';
    }
    return 0;
}