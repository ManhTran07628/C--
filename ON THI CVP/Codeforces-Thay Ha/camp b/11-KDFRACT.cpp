#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll k,p,b;
long double a;
string prep()
{
    ll m = a * 1e18;
    if(m % b == 0) {
        ll f = a / b * 1e18;
        string s = to_string(f);
        int i = s.size()-1;
        while(s[i] == '0') {
            s.pop_back();
            i--;
        }
        return s;
    }
    ll f = a / b * 1e18;
    string s = to_string(f);
    int j = 1;
    for(int i = 1;i < s.size()/2;i++) {
        string t = s.substr(0,i);
        string t2 = s.substr(i,i+t.size()-j);
        j++;
        if(t == t2) {
            return t;
        }
    }
}
bool val()
{
    ll m = a * 1e18;
    if(m % b == 0) return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> a >> b >> k >> p;
    string s = prep();
    //cout << s;
    // string t = s;
    // for(int i = 1;i <= 10;i++) {
    //     s = s + t;
    // }
    cout << s;
    //for(int i = (k % s.size());i < k+p-1;i++) cout << s[i] << ' ';
    return 0;
}