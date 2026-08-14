#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

ll check(string k){
    for(int i = 0;i < k.size();i++) 
        if(k[i] != k[k.size()-i-1]) return 0;
    return 1;
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
    ll n;
    cin >> n;
    string s,k;
    cin >> s;
    if(check(s)) {
        cout << s.size();
        return 0;
    }
    for(int i = 0;i < s.size();i++) {
        k += s[i];
        string a = k;
        reverse(a.begin(),a.end());
        if(check(s+a)) {
            cout << s.size()+a.size();
            return 0;
        }
    }
    return 0;
}