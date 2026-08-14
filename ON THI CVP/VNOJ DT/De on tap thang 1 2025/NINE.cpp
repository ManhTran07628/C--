#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "NINE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll k;
    cin >> k;
    while(k--)
    {
        ll n;
        cin >> n;
        for(int i = 1;i <= n-1;i++) {
            cout << 9;
        }
        cout << 8;
        for(int i = 1;i <= n-1;i++) {
            cout << 0;
        }
        cout << 1 << '\n';
    }
    return 0;
}