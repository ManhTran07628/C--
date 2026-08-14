#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e6+7;
vector<int> v;
int visited[MM];

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 2;i*i <= u;i++) {
            if(i > u/i) break;
            if(u % i == 0) {
                int new_nums = (i-1)*(u/i+1); 
                if(!visited[new_nums]) {
                    visited[new_nums] = 1;
                    v.push_back(new_nums);
                    q.push(new_nums);
                }
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    bfs(n);
    v.push_back(0);
    sort(v.begin(),v.end());
    cout << v.size() << '\n';
    for(auto i:v) cout << i << ' ';
    return 0;
}