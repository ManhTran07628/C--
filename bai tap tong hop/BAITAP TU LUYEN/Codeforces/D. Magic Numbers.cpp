#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
const int MOD = 1e9+7;
int m,d;
ll dp[20][2][2001][20][20];
string a,b;
// zero - 1 cac vi tri truoc do bau dau la 0     
// - 0 cac vi tri truoc do khong bat dau = 0 
ll f(int id,int tight,int num,int zero,int cur_id,string s)
{
    int n = s.size();
    if(id == n) return num == 0;
    ll memo = dp[id][tight][num][zero][cur_id];
    if(memo != -1) return memo;

    int lim = !tight ? 9 : s[id] - '0';
    memo = 0;
    for(int i = 0;i <= lim;i++) {
        int new_tight = tight && i == lim;
        int new_num = (num*10+i) % m;
        int new_zero = zero && i == 0;
        if(new_zero == 1) { // truoc do va hien tai deu la 0
            memo += f(id+1,new_tight,new_num,new_zero,cur_id,s);
            memo %= MOD;
        }
        else { // cac vi tri truoc do khong bat dau = 0 
            if(((cur_id+1) % 2 == 1 && i != d) || ((cur_id+1) % 2 == 0 && i == d)) {
                memo += f(id+1,new_tight,new_num,new_zero,cur_id+1,s);
                memo %= MOD;
            } 
        }
    }
    dp[id][tight][num][zero][cur_id] = memo;
    return memo;
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    ll Left = f(0,1,0,1,0,a);
    memset(dp,-1,sizeof(dp));
    ll Right = f(0,1,0,1,0,b);
    cout << Right - Left << '\n';
}

string bignum_minus(string a)
{
    string b = "1";
    while(a.size() != b.size()) {
        b = '0' + b;
    }
    int rem = 0;
    string ans;
    for(int i = a.size()-1;i >= 0;i--) {
        int num = (a[i]-'0') - (b[i]-'0') - rem;
        if(num < 0) {
            rem = 1;
            num = 9;
        }
        else rem = 0;
        char c = num + '0';
        ans += c;
    }
    while(ans[ans.size()-1] == '0') ans.erase(ans.size()-1,1);
    reverse(ans.begin(),ans.end());
    if(ans.size() == 0) ans += '0';
    return ans;
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> d >> a >> b;
    a = bignum_minus(a);
    solve();
    return 0;
}