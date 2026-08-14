#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n;
struct Box{ll weight,s,val;} boxes[MM];
bool cmp(Box a,Box b) {
    if(a.s != b.s) return a.s < b.s;
    if(a.weight != b.weight) return a.weight < b.weight;
    return a.val > b.val;
}

namespace subtask1
{
    ll dp[10][MM];
    void solve()
    {
        memset(dp,-1,sizeof(dp));
        dp[0][0] = 0;

        ll max_w = 0;
        for(int i = 1;i <= n;i++) max_w = max(max_w,boxes[i].s);

        for(int i = 1;i <= n;i++) {
            for(int k = max_w;k >= 0;k--) {
                if(dp[i - 1][k] == -1) continue;
                dp[i][k] = dp[i - 1][k];

                if(k <= boxes[i].s) {
                    int new_k = k + boxes[i].weight;
                    dp[i][new_k] = max(dp[i][new_k],dp[i - 1][k] + boxes[i].val);
                }
            }   
        }

        ll res = 0;
        for(int i = 1;i <= max_w;i++) res = max(res,dp[n][max_w]);
        cout << res;
    }
}

namespace subtask2
{
    struct Node{ll weight,val;};
    struct cmp{bool operator() (Node a,Node b){
        if(a.weight != b.weight) return a.weight > b.weight;
        return a.val > b.val;
    }};

    void solve()
    {
        priority_queue<Node,vector<Node>,cmp> q;
        ll max_w = boxes[n].s;
        ll cur_w = 0, cur_val = 0, res = 0;
        for(int i = 1;i <= n;i++) {
            cur_w += boxes[i].weight;
            cur_val += boxes[i].val;
            while(!q.empty() && cur_w > max_w) {
                Node u = q.top(); q.pop();
                cur_w -= u.weight;
                cur_val -= u.val;
            }

            res = max(res,cur_val);
        }

        cout << res;
    }
}

namespace subtask3
{
    bool check()
    {
        for(int i = 1;i <= n;i++) if(boxes[i].weight != 1) return 0;
        return 1;
    }

    void solve()
    {
        sort(boxes+1,boxes+n+1,[] (Box a,Box b){return a.val > b.val;});
        ll max_w = 0,pos = 1;
        ll res = 0;
        for(int i = 1;i <= n;i++) {
            if(max_w < boxes[i].s) {
                max_w = boxes[i].s;
                res = boxes[i].val;
                pos = i;
            }
        }

        for(int i = 1;i <= n;i++) {
            if(i == pos) continue;
            if(max_w > 0) {
                res += boxes[i].val;
                max_w--;
            }
            else break;
        }
        cout << res;
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
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> boxes[i].weight >> boxes[i].s >> boxes[i].val;
    }
    sort(boxes+1,boxes+n+1,cmp);
    for(int i = 1;i <= n;i++) {
        // cout << boxes[i].weight << ' ' << boxes[i].s << ' ' << boxes[i].val << '\n';
    }
    if(subtask3::check()) subtask3::solve();
    else subtask2::solve();
    // subtask3::solve();
    return 0;
}