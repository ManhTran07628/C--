#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
vector<string> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "thongke"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string t;
        getline(cin,t);
        string s = t.substr(t.size()-4);
        a.push_back(s);
    }
    ll max1 = -1,dau = 0,cuoi = 0;
    sort(a.begin(),a.end());
    // for(auto c:a) {
    //     cout << c << '\n';
    // }
    for(int i = 0;i < a.size()-1;i++) {
        ll s1 = stoll(a[i]);
        ll s2 = stoll(a[i+1]);
        if(abs(s2-s1-2) > max1) {
            dau = s1;
            cuoi = s2;
            max1 = abs(s2-s1-2);
        }
        //cout << s1 << " " << s2 << '\n';
    }
    if(max1 == -1) cout << -1;
    else {
        cout << max1+1 << '\n';
        cout << dau+1 << " " << cuoi-1;
    }
    return 0;
}