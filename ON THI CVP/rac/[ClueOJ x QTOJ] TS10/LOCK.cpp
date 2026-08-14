#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
string x,y;
int k;

void th1()
{
    int ans = 0;
    for(int i = 0;i < 4;i++) {
        int d1 = x[i]-'0';
        int d2 = y[i]-'0';
        if(d1 <= d2) ans += d2-d1;
        else ans += (10-d1+d2);
    }
    cout << ans;
}

void th2()
{
    int ans = 0;
    for(int i = 0;i < 4;i++) {
        int d1 = x[i]-'0';
        int d2 = y[i]-'0';
        if(d1 >= d2) ans += abs(d2-d1);
        else ans += (d1+10-d2);
    }
    cout << ans;
}

void th3()
{
    int ans = 0;
    for(int i = 0;i < 4;i++) {
        int d1 = x[i]-'0';
        int d2 = y[i]-'0';
        int s = 0; // 2 9
        if(d1 >= d2) s = min(abs(d1-d2),10-d1+d2);
        else s = min(abs(d1-d2),d1+10-d2);
        ans += s;
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "lock"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> k;
    cin >> x >> y;
    if(k == 1) th1();
    if(k == 2) th2();
    if(k == 3) th3();
    return 0;
}