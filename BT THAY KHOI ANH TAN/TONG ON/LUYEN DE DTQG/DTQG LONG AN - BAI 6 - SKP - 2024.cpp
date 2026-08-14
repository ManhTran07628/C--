#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 3e5 + 7;
ll n,h[MM];
ll b[MM],st[MM * 4],lazy[MM * 4],dp[MM];

void fix(int id,int l,int r)
{
    if(!lazy[id]) return;
    st[id] = st[id] + lazy[id];
    if(l != r) {
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
    }
    lazy[id] = 0;
}

void update(int id,int l,int r,int u,int v,ll val)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id] += val;
        fix(id,l,r);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id] = max(st[id*2],st[id*2+1]);
}

ll get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return -oo;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return max(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "SKP"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> h[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    stack<int> st;
    // for(int i = 1;i < MM * 4;i++) lazy[i] = oo;

    // st.push(0); h[0] = -oo;
    for(int i = 1;i <= n;i++) {
        update(1,1,n,i,i,dp[i-1]);

        int cur = i;
        while(!st.empty() && h[ st.top() ] >= h[i]) {
            cur = st.top();
            st.pop();
            int L = 1;
            if(!st.empty()) L = st.top() + 1;
            update(1,1,n,L,cur,-b[cur]);
            cur = L;
        }
        update(1,1,n,cur,i,b[i]); 
        st.push(i);
        dp[i] = get(1,1,n,1,i);
        // cout << dp[i] << ' ';
    }
    cout << dp[n];
    return 0;
}