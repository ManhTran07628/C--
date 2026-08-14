#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
string a[1001];

string bignums_plus(string a,string b)
{
    while(a.size() != b.size()) {
        if(a.size() > b.size()) b = '0' + b;
        if(a.size() < b.size()) a = '0' + a;
    }
    string c = "";
    int nho = 0;
    for(int i = a.size()-1;i >= 0;i--) {
        int d = a[i]-'0'+b[i]-'0'+nho;
        char ch = (d%10)+'0';
        nho = d / 10;
        c += ch;
    }
    if(nho > 0) c += '1';
    reverse(c.begin(),c.end());
    return c;
}


void solve()
{
    int n;
    cin >> n;
    a[1] = a[2] = "1";
    for(int i = 3;i <= n;i++) {
        string c = bignums_plus(a[i-1],a[i-2]);
        a[i] = c;
    }
    cout << a[n];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}