#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
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
    ll n;
    cin >> n;
    ll n1 = n;
    ll maxn = 0,minn = 1e9;
    while(n1--) {
        ll l,r;
        cin >> l >> r;
        a[l]++;
        a[r]--;
        maxn = max(maxn,r);
        minn = min(minn,l);
    }
    ll max1 = 0,max2 = 0;
    for(int i = minn;i <= maxn;i++) {
        a[i] = a[i-1] + a[i];
        //cout << a[i] << " ";
    }

    ll pos1 = 0;
    for(int i = minn;i <= maxn;i++) {
        if(a[i] >= 1) pos1++;
        else {
            max1 = max(max1,pos1);
            pos1 = 0;
        }
    }
    pos1 = 0;
    for(int i = minn;i <= maxn;i++) {
        if(a[i] <= 0) pos1++;
        else {
            max2 = max(max2,pos1);
            pos1 = 0;
        }
    }


    cout << max1 << " " << max2;
    return 0;
}