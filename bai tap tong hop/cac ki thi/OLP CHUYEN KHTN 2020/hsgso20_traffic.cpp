#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,k,x[MM],v[MM];

namespace subtask1
{
    struct Node
    {
        int x,y;
        double Time;
    };
    vector<Node> meet;

    bool cmp(Node a,Node b)
    {
        return a.Time < b.Time;
    }

    bool opposite(ll v1,ll v2)
    {
        if(v1 > 0 && v2 < 0) return 1;
        return 0;
    }

    bool rush(ll v1,ll v2)
    {
        if(v1 < 0 && v2 < 0 && abs(v1) < abs(v2)) return 1;
        if(v1 > 0 && v2 > 0 && abs(v1) > abs(v2)) return 1;
        return 0;
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) {
            for(int j = i + 1;j <= n;j++) {
                double x1 = x[i], x2 = x[j];
                ll v1 = v[i], v2 = v[j];
                if(opposite(v1,v2)) {
                    v1 = abs(v1), v2 = abs(v2);
                    double Time = (x2 - x1) / (v1 + v2);
                    meet.push_back({i,j,Time});
                }
                else if(rush(v1,v2)) {
                    double Time = (x2 - x1) / abs(v1 - v2);
                    meet.push_back({i,j,Time});
                }
                // cout << x1 << ' ' << x2 << '\n';
            }
        }
        sort(meet.begin(),meet.end(),cmp);
        for(int i = 0;i < meet.size();i++) cout << i + 1 << ' ' << meet[i].x << ' ' << meet[i].y << ' ' << meet[i].Time << '\n';
        cout << meet[k-1].x << ' ' << meet[k-1].y;
    }
}

namespace subtask2
{
    struct Node
    {
        int x,y;
        double Time;
    };

    bool opposite(ll v1,ll v2)
    {
        if(v1 > 0 && v2 < 0) return 1;
        return 0;
    }

    bool rush(ll v1,ll v2)
    {
        if(v1 < 0 && v2 < 0 && abs(v1) < abs(v2)) return 1;
        if(v1 > 0 && v2 > 0 && abs(v1) > abs(v2)) return 1;
        return 0;
    }

    struct cmp{bool operator() (Node a,Node b){return a.Time < b.Time;}};

    priority_queue<Node,vector<Node>,cmp> q;

    void solve()
    {
        for(int i = 1;i <= n;i++) {
            for(int j = i + 1;j <= n;j++) {
                double x1 = x[i], x2 = x[j];
                ll v1 = v[i], v2 = v[j];
                if(opposite(v1,v2)) {
                    v1 = abs(v1), v2 = abs(v2);
                    double Time = (x2 - x1) / (v1 + v2);
                    q.push({i,j,Time});
                }
                else if(rush(v1,v2)) {
                    double Time = (x2 - x1) / abs(v1 - v2);
                    q.push({i,j,Time});
                }
                while(q.size() > k) q.pop();
            }
        }


        ll rx = q.top().x,ry = q.top().y,cnt = 1;
        // while(!q.empty()) {
        //     rx = q.top().x, ry = q.top().y; q.pop();
        //     // if(q.size() == 1) break;
        //     cout << cnt << ' ' << rx << ' ' << ry << '\n';
        //     cnt++;
        // }
        cout << rx << ' ' << ry;
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
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> x[i] >> v[i];
    subtask2::solve();
    return 0;
}
