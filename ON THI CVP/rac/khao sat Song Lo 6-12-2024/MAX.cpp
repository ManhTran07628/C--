#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "MAX"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s,k;
    cin >> s;
    for(auto c:s) {
        if(isdigit(c)) k += c;
    }
    sort(k.begin(),k.end(),greater<char>());
    if(k[0] == '0'&& k[k.size()-1] == '0') {
        cout << 0;
        return 0;
    }
    cout << k;
    return 0;
}