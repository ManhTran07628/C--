
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 1;
ll b[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define taskname "DEMTAMGIAC"
    if (fopen(taskname ".inp", "r"))
    {
        freopen(taskname ".inp", "r", stdin);
        freopen(taskname ".out", "w", stdout);
    }
    map<array<int, 3>,int> a;
    ll n;
    cin >> n;
    ll i = 0;
    while(n--) {
        int a1,a2,a3;
        for(int i = 0;i < 3;i++) {
            cin >> b[i];
        }
        sort(b,b+3);
        a1 = b[0],a2 = b[1],a3 = b[2];
        a[{a1,a2,a3}]++;
    }
    ll dem = 0;
    for(auto& c:a) {
        if(c.second == 1) {
            dem++;
        }
    }
    cout << dem;
    return 0;
}
// 5
// 7 6 5
// 5 7 6
// 8 2 9
// 2 3 4
// 2 4 3