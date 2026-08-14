#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+7;
ll a[N],b[N],max1 = -1e9;
vector<ll> f;
ll n,c;

void inans()
{
    ll sum = 0;
    for(auto i:f) sum += i;
    max1 = max(max1,sum);
}


void bt(ll tmp)
{
    if(tmp > c) return;
    if(tmp <= c) {
        inans();
        return;
    }
    for(int i = 1;i <= n;i++) {
        if(b[i] == 0) {
            b[i] = 1;
            f.push_back(a[i]);
            bt(tmp + a[i]);
            f.pop_back();
            b[i] = 0;
        }
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
    cin >> n >> c;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    bt(1);
    cout << max1;
    return 0;
}