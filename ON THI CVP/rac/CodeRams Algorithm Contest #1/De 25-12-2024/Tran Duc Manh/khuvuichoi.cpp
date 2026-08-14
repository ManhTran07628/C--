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
    #define taskname "khuvuichoi"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int gbd,gkt;
    cin >> gbd >> gkt;
    int ans = 0,cnt = 1;
    while(gbd < gkt) {
        if(gbd == 12) {
            if(cnt > 4) ans += 5;
            else ans += 10;
            gbd++;
            cnt++;
            continue;
        }
        if(cnt > 4) {
            if(gbd < 12) ans += 3;
            else if(gbd >= 12) ans += 5;
        }
        else if(cnt <= 4){
            if(gbd < 12) {
                ans += 6;
            }
            else if(gbd >= 12) {
                ans += 10;
            }
        }
        gbd++;
        cnt++;
    }
    cout << ans;
    return 0;
}