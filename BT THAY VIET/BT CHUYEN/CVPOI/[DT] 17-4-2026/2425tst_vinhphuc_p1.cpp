#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e5 + 7;
ll q,sz = 0,state[MM];
ll dp[20][2];
pii qr[MM];
vector<ll> idx,v;

bool is68(string s)
{
    if(s.size() < 2) return 0;
    for(int i = 0;i < s.size() - 1;i++) {
        if(s[i] == '6' && s[i+1] == '8') return 1;
    }
    return 0;
}

ll CountNo68(string s)
{
    ll cnt = 0;
    bool num6 = 0;
    for(int i = 0;i < s.size();i++) {
        int cur = s[i] - '0';
        int left = s.size() - i - 1;
        for(int nxt_cur = 0;nxt_cur < cur;nxt_cur++) {
            if(num6 == 1 && nxt_cur == 8) continue;
            bool new_num6 = nxt_cur == 6;
            cnt += dp[left][new_num6];
        }

        if(num6 == 1 && cur == 8) return cnt;

        num6 = (cur == 6);
    }
    return cnt + 1;
}

int added[MM],removed[MM];

void update_add(int x,int val)
{
    for(;x <= sz;x += x & (-x)) added[x] += val;
} 

int get_add(int x)
{
    int res = 0;
    for(;x > 0;x -= x & (-x)) res += added[x];
    return res;
}

void update_removed(int x,int val)
{
    for(;x <= sz;x += x & (-x)) removed[x] += val;
} 

int get_removed(int x)
{
    int res = 0;
    for(;x > 0;x -= x & (-x)) res += removed[x];
    return res;
}

ll Count(ll V)
{
    int pos = upper_bound(idx.begin(),idx.end(),V) - idx.begin() - 1;
    return V - (CountNo68(to_string(V)) - 1) + get_add(pos);
}

ll bins(ll k)
{
    ll L = 1, R = 1e18, res = 67;
    while(L <= R) {
        ll mid = (L + R) / 2;
        if(Count(mid) >= k) {
            res = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    return res;
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
    cin >> q;
    dp[0][0] = 1, dp[0][1] = 1;
    for(int i = 1;i <= 18;i++) {
        dp[i][0] = 9 * dp[i-1][0] + dp[i-1][1];
        dp[i][1] = 8 * dp[i-1][0] + dp[i-1][1];
    }
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].fi >> qr[i].se;
        if(qr[i].fi == 1) {
            v.push_back(qr[i].se);
        }
    }
    idx.push_back(0);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    sz = MM;
    for(int i = 0;i < v.size();i++) {
        if( is68( to_string(v[i]) ) ) state[i+1] = 1;
        idx.push_back(v[i]);
    } 
    for(int i = 1;i <= q;i++) {
        int t = qr[i].fi;
        if(t == 1) {
            ll y = qr[i].se;
            int pos = lower_bound(idx.begin(),idx.end(),y) - idx.begin();
            if(state[pos] == 0) { //add
                update_add(pos,1);
            }
            else { // remove
                update_add(pos,-1);
            }
            state[pos] ^= 1;
        }
        else {
            ll k = qr[i].se;
            cout << bins(k) << '\n';
        }
    }
    return 0;
}
