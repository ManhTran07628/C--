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

int prime[MM];
vector<int> vec;
void sieve()
{
    fill(prime+1,prime+MM,1);
    for(ll i = 2;i * i < MM;i++)
        if(prime[i])
            for(ll j = i * i;j < MM;j += i)
                prime[j] = 0;

    for(int i = 2;i < MM;i++)
        if(prime[i])
            vec.push_back(i);
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
    sieve();
    vec.push_back(1);
    srand(time(NULL));
    for(int test = 1;test <= 1e3;test++) {
        ofstream inp("E.inp");

        int l = rd(1,1e3);
        int r = rd(l,1e4);
        inp << l << ' ' << r << '\n';
        int sz = rd(1,3);
        for(int i = 1;i <= sz;i++) inp << rd(0,9);

        inp.close();
        system("E.exe");
        system("E_brute.exe");
        if(system("fc E.out E.ans > rc")) {
            cerr << "WRONG ANSWER ON TESTCASE: " << test;
            break;
        }
        cerr << "CORRECT ANSWER ON TESTCASE: " << test << '\n';

    }
    return 0;
}