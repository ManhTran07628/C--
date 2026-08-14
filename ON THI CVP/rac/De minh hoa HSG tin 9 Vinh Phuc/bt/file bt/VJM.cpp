#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+1;
ll a[3][N];
ll n;
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
    ll t;
    cin >> t;
    while(t--)
    {
        ll kq = 1;
        cin >> n;
        string s1,s2;
        cin >> s1 >> s2;
        for(int i = 0;i < n;i++) {
            if(s1[i] == '1' && s2[i] == '1') {
                kq = 0;
                break;
            }
        }
        if(kq) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}