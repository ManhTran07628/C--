#include<bits/stdc++.h>
using namespace std;
const int P = 1e9+7;
const int N = 5*1e5+1;
string s;
long long ans, t, a[N];
int main()
{
    cin >> s;
    a[s.size()]=0;
    for (int i=s.size()-1; i>=0; i--)
         a[i] = (a[i+1]*10 + 1) % P;
    for (int i=0; i<s.size(); i++)
    if (s[i]!='0'){
        long long k = s[i]-'0';
        t++;
        k = (t*k*a[i]) % P;
        ans = (ans+k) % P;
    }
    cout << ans;
    return 0;
}