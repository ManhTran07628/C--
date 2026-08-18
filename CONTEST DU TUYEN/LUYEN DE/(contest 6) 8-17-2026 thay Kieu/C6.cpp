#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,q;
string s;

namespace subtask1
{
    void solve()
    {
        while(q--) {
            int l,r; cin >> l >> r;
            stack<int> st;
            int res = 0;
            for(int i = l;i <= r;i++) {
                if(s[i] == '(') st.push(i);
                else {
                    if(st.empty()) {
                        res++;
                        continue;
                    }
                    st.pop();
                }
            }
            res += st.size();
            cout << res << '\n';
        }
    }
}

namespace subtask2
{
    int ans[MM];
    void solve()
    {
        stack<int> st;
        int cur_res = 0;
        for(int i = 1;i <= n;i++) {
            if(s[i] == '(') st.push(i);
            else {
                if(st.empty()) {
                    cur_res++;
                    ans[i] = cur_res + st.size();
                    continue;
                }
                st.pop();
            }
            ans[i] = cur_res + st.size();
        }

        while(q--) {
            int l,r; cin >> l >> r;
            cout << ans[r] << '\n';
        }
    }
}

namespace subtask3
{
    bool checksub3()
    {
        int pos1 = 0, pos2 = n + 1;
        for(int i = 1;i <= n;i++) {
            if(s[i] == '(') {
                pos1 = i;
                continue;
            }
            break;
        }

        for(int i = n;i >= 1;i--) {
            if(s[i] == ')') {
                pos2 = i;
                continue;
            }
            break;
        }

        return (pos1 + 1 == pos2);
    }


    int open[MM],closed[MM];
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            open[i] = open[i - 1] + (s[i] == '(');
            closed[i] = closed[i - 1] + (s[i] == ')');
        }

        while(q--) {
            int l,r; cin >> l >> r;
            int left = open[r] - open[l - 1];
            int right = closed[r] - closed[l - 1];

            cout << abs(right - left) << '\n';
        }
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
    cin >> n >> q;
    cin >> s; s = ' ' + s;
    if(n <= 2000 && q <= 2000) subtask1::solve();
    if(subtask3::checksub3()) subtask3::solve();
    else subtask2::solve();
    return 0;
}