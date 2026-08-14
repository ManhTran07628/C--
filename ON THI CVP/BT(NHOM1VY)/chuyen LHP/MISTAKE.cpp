#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;

ll nhonhat(string a,string b)
{
    for(int i = 0;i < a.size();i++) {
        if(a[i] == '6') a[i] = '5';
    }
    for(int i = 0;i < b.size();i++) {
        if(b[i] == '6') b[i] = '5';
    }
    ll a1 = stoll(a);
    ll b1 = stoll(b);
    return a1+b1;
}
ll lonnhat(string a,string b)
{
    for(int i = 0;i < a.size();i++) {
        if(a[i] == '5') a[i] = '6';
    }
    for(int i = 0;i < b.size();i++) {
        if(b[i] == '5') b[i] = '6';
    }
    ll a1 = stoll(a);
    ll b1 = stoll(b);
    return a1+b1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    cin >> a >> b;
    cout << nhonhat(a,b) << ' ' << lonnhat(a,b);
    return 0;
}