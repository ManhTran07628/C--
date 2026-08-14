#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;

vector<char> s{'R','O','Y','G','B','I','V'};
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
    ll cnt = 0;
    string ans;
    for(int i = 0;i < n-3;i++) {
        ans += s[i%7];
    }
    for(int i = 0;i < 7;i++) {
        string s = ans+s[i];
        for(int j = i+1;j < 7;j++) {
            for(int k = j+1;k < 7;k++) {
                
            }
        }
    }
    return 0;
}