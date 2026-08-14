#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+7;

vector<char> a{'R','B','W'};
ll t = 1e7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "COLORS"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(ll i = 0;i <= N;i++) {
        ll x1 = i*(i+1)/2;
        ll x2 = (i+1)*(i+2)/2;
        if(x1 <= n && n <= x2) {
            cout << a[i%3];
            return 0;
        }
    }
    return 0;
}