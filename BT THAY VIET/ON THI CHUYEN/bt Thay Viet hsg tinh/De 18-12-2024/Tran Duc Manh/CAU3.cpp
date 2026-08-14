#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N];





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
    string s;
    cin >> s;
    int n = s.size(),cnt = 0,sum = 0,pf = 0;
    for(int i = 0;i < n;i++) {
        sum += s[i]-'0';
    }
    b[0] = 1;
    sum = sum % 3;
    for(int i = 0;i < n;i++) {
        pf = (pf + s[i]-'0') %  3;
        cnt += b[sum];
        b[pf]++;
    }
    cout << cnt;
    return 0;
}