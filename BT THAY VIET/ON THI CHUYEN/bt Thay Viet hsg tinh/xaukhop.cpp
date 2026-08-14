#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
string s;
const string check = "abcdefghijklmnopqrstuvwxyz";
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
    cin >> n >> s;
    ll j = 0;
    ll ans = 0;
    for(int i = 0;i < n;i++) {
        if(s[i] == check[j] && j < check.size()) {
            ans++;
            j++;
        }
        else break;
    }
    cout << ans;
    return 0;
}