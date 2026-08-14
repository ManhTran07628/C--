#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rd(ll l,ll r)
{
    return rng() % (r - l + 1) + l;
}

struct Edge{int u,v,w;};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    srand(time(NULL));

    for(int test = 1;test <= 100;test++) {
        ofstream inp("NGUONGNOI.inp");

        int n = rd(5,6);
        vector<Edge> edges;
        for(int i = 2;i <= n;i++) {
            int u = i, v = rd(1,i - 1), w = rd(1,10);
            edges.push_back({u,v,w});
        }

        int m = 8 - (n - 1);
        for(int i = 1;i <= m;i++) {
            int u = rd(1,n - 1);
            int v = rd(u + 1,n);
            int w = rd(1,10);
            edges.push_back({u,v,w});
        }

        shuffle(edges.begin(),edges.end(),rng);

        int q = rd(1,5);
        inp << n << ' ' << 8 << ' ' << q << '\n';
        for(auto E:edges) {
            inp << E.u << ' ' << E.v << ' ' << E.w << '\n';
        }
        while(q--) {
            int u = rd(1, n - 1);
            int v = rd(u + 1,n);
            int k = rd(1,n);
            inp << u << ' ' << v << ' ' << k << '\n';
        }

        inp.close();
        system("NGUONGNOI.exe");
        system("NGUONGNOI_brute.exe");
        if(system("fc NGUONGNOI.out NGUONGNOI.ans > rc") == 1) {
            cerr << "WRONG ANS: " << ' ' << test << '\n';
            break;
        }
        cerr << "CORRECT ANS: " << ' ' << test << '\n';
    }
    return 0;
}