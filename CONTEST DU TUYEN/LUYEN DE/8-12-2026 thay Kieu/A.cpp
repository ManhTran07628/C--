#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n;

struct Node{ll tl,en;} events[MM];

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
        cin >> events[i].tl >> events[i].en;
    }

    sort(events + 1,events + n + 1,[] (Node a,Node b){return a.en < b.en;});
    int res = 0;
    ll T = 0;
    priority_queue<ll> q;
    for(int i = 1;i <= n;i++) {
        T += events[i].tl;
        q.push(events[i].tl);
        while(!q.empty() && T > events[i].en) {
            T -= q.top();
            q.pop();
        }
    }
    cout << q.size();
    return 0;
}