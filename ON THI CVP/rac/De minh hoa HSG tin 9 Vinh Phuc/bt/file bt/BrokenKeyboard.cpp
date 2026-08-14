#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
map<ll,ll> a,b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BrokenKeyboard"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    while(n--){
        string s,t;
        cin >> s >> t;
        for(int i = 0;i < s.size();i++) {
            a[s[i]]++;
        }
        for(int i = 0;i < t.size();i++) {
            b[t[i]]++;
        }
        if(a.size() != b.size()) {
            cout << "NO" << '\n';
            continue;
        }
        bool kt = 1;
        for(char i = 'a';i <= 'z';i++) {
            if(a[i] != b[i]) {
                kt = 0;
                break;
            }
        }
        if(kt) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        a.clear();
        b.clear();
    }
    return 0;
}
