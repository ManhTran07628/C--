#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e6+7;
int n,k,sz[MM],parent[MM],cows[MM];

void make_set()
{
    for(int i = 1;i <= n;i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find_set(int a)
{
    if(a == parent[a]) return a;
    return find_set(parent[a]);
}

void union_sets(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(sz[a] < sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
        cows[a] += cows[b];
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    make_set();
    while(k--) {
        string t;
        int x,y;
        cin >> t;
        if(t == "join") {
            cin >> x >> y;
            union_sets(x,y);
        }
        else if(t == "add") {
            cin >> x >> y;
            
        }
        else {
            cin >> x;
            cout << cows[x] << '\n';
        }
    }
    return 0;
}