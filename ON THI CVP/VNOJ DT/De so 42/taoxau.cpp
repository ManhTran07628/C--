#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "taoxau"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string x,y;
    cin >> x;

    for(int i = x.size()-1;i >= 0;i-=2) {
        y += x[i];
    }

    for(int i = (x.size() % 2 == 0 ? 0 : 1);i < x.size();i+=2) {
        y += x[i];
    }
    cout << y;
    return 0;
}