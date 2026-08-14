#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],b[N];
set<ll> f;
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
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= k;i++) {
        cin >> a[i];
        b[a[i]]++;
        f.insert(a[i]);
    }
    sort(a+1,a+n+1);
    ll sum = 0;
    for(auto c:f) sum += c;
    if(f.size() == n) {
        cout << sum;
        return 0;
    }
    ll pos = f.size();
    for(int i = 1;i <= k;i++) {
        if(b[a[i]] == 1) continue;
        else {
            if(pos + b[a[i]]-1 < n) {
                sum = sum - a[i];
                pos += b[a[i]]-1;
            }
            else break;
        }
        cout << pos << " ";
    }
    //cout << sum;
    return 0;
}