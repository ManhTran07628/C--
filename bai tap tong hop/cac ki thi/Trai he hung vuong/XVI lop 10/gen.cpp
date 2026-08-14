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
        ofstream inp("sol.inp");

        int n = 1, T = rd(1,6);
        inp << n << ' ' << T << '\n';
        inp << rd(1,5);

        inp.close();
        system("sol.exe");
        system("sol_brute.exe");
        if(system("fc sol.out sol.ans > rc") == 1) {
            cout << "WRONG ANS: " << ' ' << test << '\n';
            break;
        }
        cout << "CORRECT ANS: " << ' ' << test << '\n';
    }
    return 0;
}