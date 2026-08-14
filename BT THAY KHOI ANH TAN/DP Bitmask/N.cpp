#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
const int MM = 2e6+7;
int n,s_mask = 0;
string S;
int dist[MM];

void readinput()
{
    cin >> n >> S;
    for(int i = 0;i < n;i++) {
        s_mask |= ((S[i] - 'A') << i);
    }
}

void bfs()
{
    for(int i = 0;i < (1 << n);i++) dist[i] = oo;
    queue<int> q;
    q.push(s_mask);
    dist[s_mask] = 0;
    while(!q.empty()) {
        int mask = q.front(); q.pop();
        for(int i = 0;i < n;i++) {
            int cur_mask = mask;
            if(i+1 < n) {
                cur_mask ^= (1 << i);
                cur_mask ^= (1 << (i+1));
                if(dist[cur_mask] == oo) {
                    q.push(cur_mask);
                    dist[cur_mask] = dist[mask] + 1;
                }
            }

            if(i+2 < n) {
                cur_mask ^= (1 << (i+2));
                if(dist[cur_mask] == oo) {
                    q.push(cur_mask);
                    dist[cur_mask] = dist[mask] + 1;
                }
            }
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    bfs();
    cout << min(dist[0],dist[(1 << n)-1]);
    return 0;   
}