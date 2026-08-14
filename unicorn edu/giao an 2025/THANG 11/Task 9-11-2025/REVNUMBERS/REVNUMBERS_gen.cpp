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
    int q = rd(100,5000);
    cout << q << '\n';
    while(q--) {
        string s;
        int n = rd(1,5000);
        for(int i = 1;i <= n;i++) {
            int c = rd(0,9);
            if(i == 1) c = rd(1,9);
            s.push_back( char('0' + c) );
        }
        cout << s << '\n';
    }

    return 0;
}


