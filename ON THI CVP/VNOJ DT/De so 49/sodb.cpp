#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+7;
ll a[N],p[N],n;
vector<ll> f;
void sieve()
{
    fill(p+1,p+N+1,1);
    p[1] = p[0] = 0;
    for(int i = 1;i < sqrt(N);i++)
        if(p[i])
            for(int j = i*i;j < N;j+=i)
                p[j] = 0;
    
}

ll checkchuso(ll k)
{
    ll odd = 0,even = 0;
    while(k > 0) {
        ll tmp = k % 10;
        if(tmp % 2 == 0) even++;
        else odd++;
        k /= 10;
    }
    return odd != even;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "sodb"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(p[a[i]]) {
            if(checkchuso(a[i])) f.push_back(a[i]);
        }
    }
    cout << f.size();
    return 0;
}