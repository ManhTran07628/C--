#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
vector<char> a{'8','0','2','4','6'};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "E"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }   
    string s;
    ll n;
    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    while(n > 1) {
        s += a[(n%5)];
        n = (n+4)/5;
    }
    reverse(s.begin(),s.end());
    cout << s;
    return 0;
}