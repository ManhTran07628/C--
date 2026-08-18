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

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    srand(time(NULL));
    for(int test = 1;test <= 100;test++) {
        ofstream inp("CANDIES.inp");

        int n = rd(1,100);
        int k = rd(1,n);
        inp << n << ' ' << k << '\n';
        for(int i = 1;i <= n;i++) inp << rd(0,9);


        inp.close();
        system("CANDIES.exe");

        // system("CANDIES_brute.exe");
        // if(system("fc CANDIES.out CANDIES.ans > rc")) {
        //     cerr << "WRONG ANSWER ON TESTCASE: " << test;
        //     break;
        // }
        // cerr << "CORRECT ANSWER ON TESTCASE: " << test << '\n';

    }
    return 0;
}