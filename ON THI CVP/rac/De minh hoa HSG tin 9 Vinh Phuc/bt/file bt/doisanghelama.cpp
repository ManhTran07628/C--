#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1001;
ll a[N];
int main()
{
    //freopen("BAI1.INP","r",stdin);
    //freopen("BAI1.OUT","w",stdout);
    ll n;
    vector<pair<ll,string>> lama = {
            {1000, "M"},{900, "CM"},{500, "D"},{400, "CD"},
            {100, "C"},{90, "XC"},{50, "L"},{40, "XL"},
            {10, "X"},{9, "IX"},{5, "V"},{4, "IV"},{1, "I"}
    };
    while(cin >> n)
    {
        string k;
        for(pair<ll,string> c: lama) {
            while(n >= c.first) {
                k += c.second;
                n -= c.first;
            }
        }
        cout << k << endl;
    }
    return 0;
}
