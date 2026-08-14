#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+3;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "APPEARSTR"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s;
    cin >> s;
    for(auto i:s) {
        a[i]++;
    }
    for(char i = '0';i <= 'z';i++) {
        if(a[i] > 0) {
            cout << i << " " << a[i] << '\n';
        }
    }
    return 0;
}
