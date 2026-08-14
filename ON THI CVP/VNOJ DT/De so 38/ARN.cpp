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
    #define taskname "ARN"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s,x;
    cin >> s >> x;
    ll n = s.size(),m = x.size();
    ll j = 0,cnt = 0;
    for(int i = 0;i < n;i++) {
        if(s[i] == x[j]) {
            j++;
            if(j == m) {
                cnt++;
                j = 0;
            }
        }
        else {
            j = 0;
            if(s[i] == x[j]) j++;
        }
    }
    cout << cnt;
    return 0;
}