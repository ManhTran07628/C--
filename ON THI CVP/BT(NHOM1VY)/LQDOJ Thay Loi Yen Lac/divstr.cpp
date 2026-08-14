#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
string s1,s2;

ll check(string k1)//,string k2)
{
    for(int i = 0;i < s1.size();i += k1.size()) {
        string k;
        for(int j = i;j < i+k1.size();j++) k += s1[j];
        if(k != k1) return 0;
    }
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
    cin >> s1 >> s2;
    if(s1.size() < s2.size()) swap(s1,s2);
    ll cnt = 0;
    for(int i = 0;i < s2.size();i++) {
        string k = s2.substr(0,i+1);
        if(check(k)) cnt++;
        //cout << k << '\n';
    }
    cout << cnt;
    return 0;
}