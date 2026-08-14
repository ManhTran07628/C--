#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;

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
    ll dem = 0;
    ll n = 4;
    while(n--)
    {
        string k;
        cin >> k;
        ll ans = 0;
        for(int i = 0;i < 2;i++) {
            ans = ans * 10 + (k[i] - '0');
        }
        if(k[k.size()-1] == 'A') dem++;
        cout << ans << " ";
    }
    cout << dem;
    return 0;
}