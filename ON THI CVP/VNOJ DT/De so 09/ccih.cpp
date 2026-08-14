#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "ccih"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s;
    getline(cin,s);
    for(int i = 0;s[i];i++) {
        if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
    }
    cout << s;
    return 0;
}