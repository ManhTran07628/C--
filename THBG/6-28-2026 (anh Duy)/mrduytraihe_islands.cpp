#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 1e6 + 7;
int n,m,x[MM],a[MM];

namespace subtask1
{
    int d[1001][1001],f[1001][1001];

    void bfs(int st)
    {
        for(int i = 1;i <= n;i++) d[st][i] = oo;
        d[st][st] = 0;
        queue<int> q;
        q.push(st);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            int v1 = (u - 1 == 0 ? n : u - 1);
            int v2 = (u + 1 > n ? 1 : u + 1);
            if(d[st][v1] > d[st][u] + 1) {
                d[st][v1] = d[st][u] + 1;
                q.push(v1);
            }
            if(d[st][v2] > d[st][u] + 1) {
                d[st][v2] = d[st][u] + 1;
                q.push(v2);
            }
        }
    }

    void solve()
    {
        for(int u = 1;u <= n;u++) {
            int v1 = (u - 1 == 0 ? n : u - 1);
            int v2 = (u + 1 > n ? 1 : u + 1);
            d[u][v1] = d[v1][u] = 1;
            d[u][v2] = d[v2][u] = 1;
        }

        for(int i = 1;i <= n;i++) {
            bfs(i);
        }

        int ans = oo;

        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++) 
                f[i][j] = d[i][j];

        for(int st = 1;st <= n;st++) {

            for(int u = 1;u <= n;u++) d[u][st] = 1;

            int cur = x[1], sum = 0;
            for(int i = 2;i <= m;i++) {
                sum += min(d[cur][st] + d[st][ x[i] ], d[cur][ x[i] ]);
                cur = x[i]; 
            }

            ans = min(ans,sum);

            for(int u = 1;u <= n;u++) d[u][st] = f[u][st];
        }

        cout << ans;
    }
}

namespace subtask2
{
    int cnt[MM],d[MM],ps[MM];
    void process(int cur_pos, int next_pos,int dist)
    {
        int L = next_pos - (dist - 2);
        int R = next_pos + (dist - 2);
        int mid = next_pos;

        d[L] -= (L - 1);
        d[mid] += (L - 1);
        cnt[L]++;
        cnt[mid]--;

        ps[next_pos] += dist - 1;

        d[R] -= (L - 1);
        d[mid] += (L - 1);
        cnt[R]++;
        cnt[mid]--;
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) {
            a[i] = i;
            a[i + n] = i;
            a[i + n + n] = i;
        }

        for(int i = 1;i <= m - 1;i++) {
            int d1 = x[i], d2 = x[i + 1];

            int dis = min(d1 - d2,n - d1 + d2);

            int cur_pos = d1 + n;

            int p1,p2;
            if(d1 < d2) {
                p1 = d2; 
                p2 = d2 + n;
            }   
            else {
                p1 = d2 + n;
                p2 = d2 + n + n;
            }

            process(cur_pos,p1,dis);
            process(cur_pos,p2,dis);
        }

        for(int i = 1;i <= 3 * n;i++) {
            cnt[i] += cnt[i-1];
            d[i] += d[i-1];
            cout << ps[i] + cnt[i] * i + d[i] << ' ';
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
    cin >> n >> m;
    for(int i = 1;i <= m;i++) cin >> x[i];
    subtask2::solve();
    return 0;
}
