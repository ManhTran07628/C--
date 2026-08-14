#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll vt[N];

struct host
{
    int a,b;
    bool operator<(const host &other)
    const
    {
        if(a == other.a) return other.b < b;
        return a < other.a;
    }
};
vector<host> mang;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CHONSACH"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;

    return 0;
}


