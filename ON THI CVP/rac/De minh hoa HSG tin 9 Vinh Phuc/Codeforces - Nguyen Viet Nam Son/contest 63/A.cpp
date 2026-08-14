#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll l,r;
ll check(ll k)
{
    ll l = 0,r = 0;
    r = k % 10;
    while(k > 0) {
        l = k % 10;
        k /= 10;
    }
    if(l == r) return 1;
    else return 0;
}

void sub1()
{
    ll cnt = 0;
    for(int i = l;i <= r;i++) {
        if(check(i)) cnt++;
    }
    cout << cnt;
}

void sub2()
{
    
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
    cin >> l >> r;
    return 0;
}