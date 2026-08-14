#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;


void Try(int lim,int id,ll nums,ll mul,ll sum)
{
    if(id > lim) {
        if(mul % sum == 0) {
            cout << nums << '\n';
            exit(0);
        }
        return;
    }
    for(int i = 1;i <= 9;i++) {
        Try(lim,id + 1,nums * 10 + i,mul * i,sum + i);    
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    Try(14,1,0,1,0);
    return 0;
}