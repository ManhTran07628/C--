#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
vector<ll> lt;
vector<ll> s[10000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll m = 1e5;
    for(ll i = 1;i <= m;i++) lt.push_back(i);
    for(ll it:lt) {
        ll k = it,cnt = 1;
        for(int i = 2;i*i <= k;i++) {
            ll m = 0;
            while(k % i == 0) {
                k /= i;
                m++;
            }
            cnt *= (2*m+1);
        }
        if(k > 1) cnt *= 3;
        s[cnt].push_back(it*it);
    }   
    int q;
    cin >> q;
    while(q--) {
        ll k,l,h;
        cin >> k >> l >> h;
        ll left = lower_bound(s[k].begin(),s[k].end(),l)-s[k].begin();
        ll right = upper_bound(s[k].begin(),s[k].end(),h)-s[k].begin();
        cout << right-left<< '\n';
    }
    return 0;
}