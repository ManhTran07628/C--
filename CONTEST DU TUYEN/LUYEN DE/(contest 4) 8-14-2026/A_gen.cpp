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
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    srand(time(NULL));
    for(int test = 1;test <= 100;test++) {
        ofstream inp("B00493.inp");

        int n = rd(1,15);
        ll K = rd(1,50);
        ll D = rd(1,n);
        inp << n << ' ' << K << ' ' << D << '\n';
        for(int i = 1;i <= n;i++) {
            int type = rd(0,1);
            ll a = rd(1,K - 1);
            if(type == 0) inp << a << ' ';
            else inp << -a << ' ';
            // inp << rd(1,1e9) << ' ';
        }


        inp.close();
        system("B00493.exe");
        system("B00493_brute.exe");
        if(system("fc B00493.out B00493.ans > rc")) {
            cerr << "WRONG ANSWER ON TESTCASE: " << test;
            break;
        }
        cerr << "CORRECT ANSWER ON TESTCASE: " << test << '\n';

    }
    return 0;
}