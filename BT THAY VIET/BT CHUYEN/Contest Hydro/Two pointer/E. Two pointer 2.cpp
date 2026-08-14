#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,k;
string s;
pair<char,int> t[MM];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> s;
    s = ' ' + s;
    int i = 1,j = 0;
    for(;i <= n;) {
        j++;
        t[j].fi = s[i];
        if(s[i] == '1') {
            t[j].se = 1;
            i++;
        }
        else {
            int cnt = 0;
            while(i <= n && s[i] == '0') {
                cnt++;
                i++;
            }
            t[j].se = cnt;
        }
    }
    n = j;
    i = 1,j = 1;
    int cur_seg = 0,ans = 0,cnt = 0;
    for(;j <= n;j++) {
        if(t[j].fi == '1') cur_seg++;
        else {
            if(cnt < k) {
                cur_seg += t[j].se;
                cnt++;
            }
            else {
                while(i <= n && t[i].fi != '0') {
                    cur_seg--;
                    i++;
                }
                cur_seg -= t[i].se;
                i++;
                cur_seg += t[j].se;
            }
        }
        ans = max(ans,cur_seg);
    }
    cout << ans;
    // for(int i = 1;i <= n;i++) cout << t[i].fi << ' ' << t[i].se << '\n';
    return 0;
}