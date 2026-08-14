#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
string bignum_plus(string a,string b)
{
    while(a.size() != b.size()) {
        if(a.size() < b.size()) {
            a = '0' + a;
        }
        else b = '0' + b;
    }
    string ans;
    int rm = 0;
    for(int i = a.size()-1;i >= 0;i--) {
        ll tmp = (a[i]-'0') + (b[i]-'0') + rm;
        char m = tmp % 10 + '0';
        ans += m;
        rm = tmp / 10;
    }
    if(rm > 0) ans += '1';
    reverse(ans.begin(),ans.end());
    return ans;
}

string small_mul(string a,ll b)
{
    string ans;
    ll crr = 0;
    for(int i = a.size()-1;i >= 0;i--) {
        ll tmp = (a[i]-'0')*b + crr;
        ans += (tmp%10+'0');
        crr = tmp / 10;
    }
    if(crr != 0) {
        ans += (crr+'0');
    }
    reverse(ans.begin(),ans.end());
    int i = 0;
    for(i = 0;ans[i];i++) {
        if(ans[i] != '0') break;
    }
    ans = ans.substr(i);
    return ans;

}

string bignum_mnus(string a,string b)

{
    while(a.size() != b.size()) {
        if(a.size() < b.size()) {
            a = '0' + a;
        }
        else b = '0' + b;
    }
    string ans;
    ll rm = 0;
    for(int i = a.size()-1;i >= 0;i--) {
        ll tmp,c = 0;
        if(a[i] < b[i]) {
            tmp = 10+(a[i]-'0') - (b[i]-'0') + rm;
            c = 1;
        }
        else {
            tmp = (a[i]-'0') - (b[i]-'0') + rm;
            if(tmp == -1) {
                tmp = 9;
                c = 1;
            }
        }
        if(c) rm = -1;
        else rm = 0;
        char crr = tmp + '0';
        ans += crr;
    }
    reverse(ans.begin(),ans.end());
    int i = 0;
    for(i = 0;ans[i];i++) {
        if(ans[i] != '0') break;
    }
    ans = ans.substr(i);
    return ans;
}

string big_mul(string a,string b)
{
    string ans;
    ll crr = 0;
    for(int i = a.size()-1;i >= 0;i--) {
        string tmp = small_mul(b,a[i]-'0');
        ll c = i;
        while(c < a.size()-1) {
            tmp = tmp + '0';
            c++;
        }
        ans = bignum_plus(ans,tmp);
    }
    return ans;
}

string div4(string a)
{
    string ans;
    ll r = 0;
    for(auto i:a) {
        r = r * 10 + (i-'0');
        if(r >= 4) {
            ans += (r/4+'0');
            r %= 4;
        }
        else ans += '0';
    }
    int i = 0;
    for(i = 0;ans[i];i++) {
        if(ans[i] != '0') break;
    }
    ans = ans.substr(i);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tong"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string n;
    cin >> n;
    string t1 = big_mul(bignum_mnus(n,"1"),bignum_plus(n,"1"));
    string t2 = big_mul(t1,bignum_plus(n,"2"));
    string t3 = div4(big_mul(t2,n));
    // //cout << (n-1)*(n+1)*(n+2)*n/4;
    cout << t3;
    return 0;
}