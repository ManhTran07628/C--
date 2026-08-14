#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
string s;
void luat11()
{
    for(int i = 0;i < s.size();i++) {
        ll W = 0,L = 0;
        ll count = 0;
        while(i < s.size()) {
            if(s[i] == 'W') W++;
            else if(s[i] == 'L') L++;
            i++;
            count++;
            if(W >= 11 && W-L >= 2) break;
            else if(L >= 11 && L-W>=2) break;
        }
        i--;
        cout << W << ":" << L << '\n';
    }
    cout << '\n';
}
void luat21()
{
    for(int i = 0;i < s.size();i++) {
        ll W = 0,L = 0;
        ll count = 0;
        while(i < s.size()) {
            if(s[i] == 'W')W++;
            else if(s[i] == 'L') L++;
            i++;
            count++;
            if(W >= 21 && W-L >= 2) break;
            else if(L >= 21 && L-W>=2) break;
        }
        i--;
        cout << W << ":" << L << '\n';
    }
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
    char c;
    while(cin >> c) {
        if(c == 'E') break;
        s += c;
    }
    luat11();
    luat21();
    return 0;
}