#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
const int N = 1e7+7;
ll a[N];
vector<ll> p;
int n;
void cntdiv(ll k,ll t)
{
    for(ll i = 1;i <= sqrt(k);i++) {
        if(k % i == 0) {
            if(i >= t) p.pb(i);
            if(k / i != i) {
                if(k/i >= t) p.pb(k/i);
            }
        }
    }
    sort(p.begin(),p.end());
}


void sub1() // n <= 1000 && a[i] <= 1e6
{
    ll ans = 1;
    for(auto i:p) {
        ll cnt = 0,sum = 0,c = 1;
        for(int j = 1;j <= n;j++) {
            sum += a[j];
            if(sum == i) {
                cnt++;
                sum = 0;
            }
            else if(sum > i) {
                c = 0;
                break;
            }
        }
        if(c) {
            ans = cnt;
            break;
        }
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "Phandoan"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    ll s = 0,maxe = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        s += a[i];
        maxe = max(maxe ,a[i]);
    }
    cntdiv(s,maxe);
    sub1();
    // for(auto i:p) {
    //     cout << i << " ";
    // }


    return 0;
}

