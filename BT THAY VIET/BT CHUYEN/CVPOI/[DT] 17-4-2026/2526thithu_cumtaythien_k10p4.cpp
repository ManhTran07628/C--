#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int k,m,n;
string s;

namespace subtask1
{
    void solve()
    {
        while(n--) {
            int a,b,c; cin >> a >> b >> c;
            string subs;
            for(int i = a;i < b;i++) subs.push_back(s[i]);
            int sz = s.size() - 1;
            string prefix,suffix;
            for(int i = 0;i < c;i++) prefix.push_back(s[i]);
            for(int i = c;i <= sz;i++) suffix.push_back(s[i]);
            s = prefix + subs + suffix;
            while(s.size() > m) s.pop_back();
        }
        for(int i = 0;i < k;i++) cout << s[i];
    }
}

namespace subtask2
{
    int pos[MM],a[MM],b[MM],c[MM];
    void solve()
    {
        for(int i = 0;i < k;i++)
            pos[i] = i;
        for(int i = 1;i <= n;i++) cin >> a[i] >> b[i] >> c[i];
        for(int i = n;i >= 1;i--) {
            int len = b[i] - a[i];
            for(int j = 0;j < k;j++) {
                if(pos[j] < c[i]) continue;
                else if(c[i] <= pos[j] && pos[j] < c[i] + len) pos[j] = a[i] + (pos[j] - c[i]);
                else if(pos[j] >= c[i] + len) pos[j] -= len;
            }
        }
        
        for(int i = 0;i < k;i++) cout << s[ pos[i] ];
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "CAU4"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> k >> m;
    cin >> s;
    cin >> n;
    subtask2::solve();
    return 0;
}