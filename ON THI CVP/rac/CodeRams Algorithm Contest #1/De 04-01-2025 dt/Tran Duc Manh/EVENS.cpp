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
    #define taskname "EVENS"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,ans = 0;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        bool ck = 1;
        for(char i:s) {
            if((i-'0') % 2 == 1) {
                ck = 0;
                break;
            }
        }
        if(ck) ans++;
    }
    cout << ans;
    return 0;
}