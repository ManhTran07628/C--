#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7, LOG = 20;
int n,q,c[MM];

namespace subtask1
{
    bool check()
    {
        if(*max_element(c+1,c+n+1) == *min_element(c+1,c+n+1)) return 1;
        return 0;
    }

    void solve()
    {
        while(q--) {
            int l,r; cin >> l >> r;
            if((r - l + 1) % 2 == 0) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
    }
}

namespace subtask3
{
    void solve()
    {
        while(q--) {
            int l,r; cin >> l >> r;
            stack<int> st;
            for(int i = l;i <= r;i++) {
                if(st.empty()) {
                    st.push(c[i]);
                }
                else {
                    if(st.top() == c[i]) st.pop();
                    else st.push(c[i]);
                }
            }

            cout << st.size() << '\n';
        }
    }
}


namespace sol
{
    int up[MM][LOG + 1],h[MM];
    int cur_id = 0;
    
    map<int,int> child[MM];

    int S[MM];

    void add(int &cur,int val,int id)
    {
        int &nxt = child[cur][val];
        if(nxt == 0) {
            nxt = ++cur_id;
            
            int u = cur, v = nxt;
            h[v] = h[u] + 1;
            up[v][0] = u;
        }
        cur = nxt;
        S[id] = nxt;
    }

    void process()
    {
        up[1][0] = 1;
        for(int j = 1;j <= LOG;j++)
            for(int i = 1;i <= cur_id;i++)   
                up[i][j] = up[ up[i][j-1] ][j-1];
    }

    int LCK(int u,int v)
    {
        if(h[v] > h[u]) swap(u,v);
        for(int i = LOG;i >= 0;i--)
            if(h[ up[u][i] ] >= h[v])
                u = up[u][i];
        if(u == v) return u;
        for(int i = LOG;i >= 0;i--)
            if(up[u][i] != up[v][i])
                u = up[u][i], v = up[v][i];
        return up[u][0];
    }

    void solve()
    {
        S[0] = ++cur_id;
        int cur = 1;
        stack<int> st;
        for(int i = 1;i <= n;i++) {
            if(st.empty()) {
                st.push(i);
                add(cur,c[i],i);
            }
            else {
                if(c[st.top()] == c[i]) {
                    cur = up[cur][0];
                    S[i] = cur;
                    st.pop();
                }
                else {
                    st.push(i);
                    add(cur,c[i],i);
                }
            }
        }

        process();
        while(q--) {
            int l,r; cin >> l >> r;
            int lck = LCK(S[l - 1],S[r]);
            cout << h[ S[l - 1] ] + h[ S[r] ] - 2 * h[ lck ] << '\n';
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
    for(int i = 1;i <= n;i++) cin >> c[i];
    sol::solve();
    // if(subtask1::check()) subtask1::solve();
    // else subtask3::solve();
    return 0;
}