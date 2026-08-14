#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+7;

ll check(ll k)
{
    ll tmp = 0,scs = 0;
    while(k > 0) {
        tmp += k % 10;
        scs++;
        k /= 10;
    }
    if(tmp % scs == 0) return 1;
    else return 0;
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
    ll cnt = 1;
    ll n;
    cin >> n;
    for(int i = 1;i <= N;i++) {
        if(check(i)) {
            if(cnt == n) {
                cout << i;
                return 0;
            }
            cnt++;
        }
    }
    return 0;
}