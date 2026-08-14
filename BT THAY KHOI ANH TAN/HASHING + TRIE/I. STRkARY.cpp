#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
const int base = 256;
const int MOD = 1e9 + 2277;
ll hashA[MM],Pow[MM],n,hashP[MM]; 
vector<int> res,Div;
string s,t;

ll getHash(int l,int r,ll hashA[])
{
    return (hashA[r] - hashA[l - 1] * Pow[r - l + 1] % MOD + MOD) % MOD;
}

bool check(int length,string x)
{
    x = ' ' + x + x;
    for(int i = 1;i <= length * 2;i++) 
        hashP[i] = (hashP[i-1] * base + x[i] - '0' + 1) % MOD;



    for(int i = 1;i <= n;i += length) {

        bool ok = 0;
        for(int j = 1;j <= length * 2;j++) 
            if(getHash(i, i + length - 1,hashA) == getHash(j, j + length - 1,hashP)) {
                ok = 1;
                break;
            }

        if(!ok) return 0;
    }
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = s.size();
    s = s + s;
    s = ' ' + s;
    Pow[0] = 1;
    for(int i = 1;i < MM;i++) {
        Pow[i] = (Pow[i-1] * base) % MOD;
    }

    for(int i = 1;i <= n+n;i++)
        hashA[i] = (hashA[i-1] * base + s[i] - '0' + 1) % MOD;


    int j = 1;
    for(int i = 1;i * i <= n;i++) {
        if(n % i == 0) {
            Div.push_back(i);
            if(n / i != i) Div.push_back(n / i);
        }
    }
    sort(Div.begin(),Div.end());

    // chia lam 2 doan 
    // cout << check(4,"abba");

    for(auto X:Div) {
        while(t.size() < X) {
            t.push_back(s[j]);
            j++;
        }

        // chia do dai X
        if(check(X,t)) {
            res.push_back(n / X); // chia duoc n / X doan
        }
    }
    sort(res.begin(),res.end());
    cout << res.size() << '\n';
    for(auto x:res) cout << x << ' ';
    return 0;
}