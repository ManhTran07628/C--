#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll x[21];
map<ll,ll> lt;
ll n,k,ans = 0;
vector<ll> p;
bool prime(ll k)
{
    if(k < 2) return 0;
    for(ll i = 2;i*i <= k;i++) 
        if(k%i==0) return 0;
    return 1;
}

void backtracking(ll sum,ll id,ll d)
{
    if(d == k) {
        if(prime(sum)) {
            ans++;
            // for(auto i:p) cout << i << ' ';
            // cout << '\n'; 
        }
        return;
    }
    for(int i = id;i <= n;i++) {
        if(lt[i]==0) {
            p.push_back(x[i]);
            lt[i]=1;
            backtracking(sum+x[i],i,d+1);
            lt[i]=0;
            p.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> x[i];
    }
    backtracking(0,1,0);
    cout << ans;
    return 0;
}