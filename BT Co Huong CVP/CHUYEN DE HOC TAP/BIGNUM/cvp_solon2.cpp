#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;


string add_bignum(string a,string b)
{
    string res;
    while(a.size() != b.size()) {
        if(a.size() < b.size()) a = '0' + a;
        else b = '0' + b;
    }
    int rem = 0;
    for(int i = a.size() - 1;i >= 0;i--) {
        int nums = (a[i] - '0') + (b[i] - '0') + rem;
        res.push_back((char) nums % 10 + '0');
        rem = nums / 10;
    }
    if(rem > 0) res.push_back('1');
    reverse(res.begin(),res.end());
    return res;
}

string minus_bignum(string a,int b)
{
    string res;
    int rem = 0;
    for(int i = a.size() - 1;i >= 0;i--) {
        int cur = 10 + (a[i] - '0') - b;
        
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    return 0;
}