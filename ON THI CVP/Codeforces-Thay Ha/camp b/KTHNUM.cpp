#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+7;
ll s[N];

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
    ll t;   
    cin >> t;
    while(t--)
    {
        ll n,k,a,b,c,d;
        cin >> n >> k >> a >> b >> c >> d;
        s[1] = a;
        for(int i = 2;i <= n;i++) {
            s[i] = ((s[i-1]%d)*(b%d) + c % d) % d;
        }
        sort(s+1,s+n+1);
        cout << s[k] << '\n';
    }
    return 0;
}