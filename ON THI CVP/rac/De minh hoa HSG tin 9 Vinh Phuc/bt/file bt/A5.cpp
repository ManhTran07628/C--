#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
map<ll,ll> a;

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
    ll n,cnt = 0;
    cin >> n;
    while(n--) {
        string s;
        ll x;
        cin >> s;
        if(s == "size") {
            cout << cnt << '\n';
        }
        else {
            cin >> x;
            if(s == "add") {
                a[x]++;
                if(a[x] == 1) cnt++;
            }
            if(s == "del") {
                if (a[x] > 0) {
                if (a[x] == 1) cnt--; 
                a[x]--;
    }
            }
            if(s == "count") cout << a[x] << '\n';
        }

    }
    return 0;
}