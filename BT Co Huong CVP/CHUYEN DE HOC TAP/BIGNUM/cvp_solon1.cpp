#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
string s;
int a,b;

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

string mul_single_bignum(string a,int b)
{
    string res;
    int rem = 0;
    for(int i = a.size() - 1;i >= 0;i--) {
        int mul = (a[i] - '0') * b + rem;
        res.push_back((char) mul % 10 + '0');
        rem = mul / 10;
    }
    while(rem > 0) {
        res.push_back(char(rem % 10 + '0'));
        rem /= 10;
    }
    reverse(res.begin(),res.end());
    return res;
}

string mul_bignum(string a,string b)
{
    string res;
    for(int i = b.size() - 1;i >= 0;i--) {
        int x = b[i] - '0';
        string k = mul_single_bignum(a,x);
        int j = i;
        while(j < b.size() - 1) {
            k.push_back('0');
            j++;
        }
        if(res.empty()) res = k;
        else res = add_bignum(res,k);
    }
    return res;
}

string binpow(string a,int b)
{
    if(b == 0) return "1";
    string res = a; b--;
    while(b > 0) {
        res = mul_bignum(res,a);
        b--;
    }
    return res;
}

string change_to_base10(string s,int cur_base)
{
    string res = "0";
    int sz = s.size();
    for(int i = 0,j = sz - 1;i < sz;i++,j--) {
        int nums;
        if('0' <= s[i] && s[i] <= '9') nums = s[i] - '0';
        else nums = s[i] - 'A' + 10;
        string x = binpow(to_string(cur_base),j);
        res = add_bignum(res, mul_bignum( to_string(nums) , x ) );
    }
    return res;
}

int find_mod(string x,int mod)
{
    int res = 0;
    for(auto c:x) {
        res = (res * 10 + (c - '0')) % mod;
    }
    return res;
}

string del_zero(string &s)
{
    reverse(s.begin(),s.end());
    while(s.size() > 1 && s[ s.size() - 1 ] == '0') s.pop_back();
    reverse(s.begin(),s.end());
    return s;
}

string div_nums(string s,int k)
{
    string res;
    int rem = 0;
    for(auto c:s) {
        rem = rem * 10 + (c - '0');
        res.push_back((char) rem / k + '0');
        rem %= k;
    }
    del_zero(res);
    if(res.empty()) return "0";
    return res;
}

vector<int> change_to_base_b(string s,int cur_base)
{
    vector<int> v;
    while(s != "0") {
        // cout << s << ' ' << find_mod(s,cur_base) << '\n';
        v.push_back(find_mod(s,cur_base));
        s = div_nums(s,cur_base);
    }
    // cout << s << '\n';
    return v;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> a >> b;
    if(s == "0") {
        cout << 0;
        return 0;
    }
    // cout << find_mod("50",2);
    // cout << add_bignum("123","456");
    // cout << mul_single_bignum("350",3);
    // cout << mul_bignum("123","456");
    // cout << binpow("123",3);
    // cout << change_to_base10(s,a);
    // cout << div_nums("36000",4);
    s = change_to_base10(s,a);
    // cout << s << '\n';
    vector<int> res = change_to_base_b(s,b);
    reverse(res.begin(),res.end());
    for(auto x: res) {
        if(x < 10) cout << x;
        else cout << char('A' + x - 10);
    }
    return 0;
}