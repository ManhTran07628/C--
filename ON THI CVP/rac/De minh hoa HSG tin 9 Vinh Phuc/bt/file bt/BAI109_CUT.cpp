#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
map<ll,ll> a,b;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "cut"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int max1 = -1e6;
    for(int i = 0;i < n;i++) {
        int dem = 0;
        for(int j = 0;j <= i;j++) {
            a[s[j]] = 1;
        }
        for(int j = i+1;j < n;j++) {
            b[s[j]] = 1;
        }
        for(char j = 'a';j <= 'z';j++) {
            if(b[j] == 1 && a[j] == 1) dem++;
        }
        max1 = max(max1,dem);
        a.clear();
        b.clear();
    }
    cout << max1;
    return 0;
}

