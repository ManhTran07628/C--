#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
ll n,k,cnt = 0;
vector<ll> v;


void backtrack(ll pos,ll crr,ll sum)
{
    if(sum > n) return;
    if(pos == k-1) {
        if(n - sum >= crr) cnt++;
        return;
    }
    for(int i = crr;i <= n;i++) {
        backtrack(pos+1,i,sum+i);
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
    cin >> n >> k;
    backtrack(0,1,0);
    cout << cnt;
    return 0;
}