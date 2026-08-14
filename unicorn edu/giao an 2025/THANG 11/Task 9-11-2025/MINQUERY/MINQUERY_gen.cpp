#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MAXN = 2e6+7;




int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    mt19937_64 rand(stoull(argv[1]));

    auto rd = [&] (ll l, ll r) {
        return l + rand() % (r - l + 1);
    };

    // sinh do thi dang cay
//    vector<pair<int,int>> edges;
//    for (int i = 2; i <= n; i++) {
//        int p = rd(1,i-1);
//        edges.push_back({p, i});
//    }
//
//    for (auto &e : edges) {
//        cout << e.first << " " << e.second << "\n";
//    }


    // maxlimit n , q <= 1000
    int n = rd(5000,5000), q = rd(5000,5000);
    cout << n << ' ' << q << '\n';
    for(int i = 1;i <= n;i++) {
        int a = rd(1,(int) 1e9);
        cout << a << ' ';
    }
    cout << '\n';
    while(q--) {
        int type = rd(1,2);
        cout << type << ' ';
        if(type == 1) {
            int l = rd(1,n), val = rd(1,(int) 1e9);
            cout << l << ' ' << val;
        }
        else if(type == 2) {
            int l = rd(1,n);
            int r = rd(l,n);
            cout << l << ' ' << r;
        }
        cout << '\n';
    }

    return 0;
}


