#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "DIVISIBLE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--)
    {
        string a;
        ll b;
        cin >> a >> b;
        ll tong = 0;
        if(a[0] == '-') a = a.substr(1);
        for(auto c : a) {
            tong = (tong * 10 + c -'0') % b;
        }
        if(tong == 0) cout << "divisible" << '\n';
        else  cout << "not divisible" << '\n';
    }
    return 0;
}
