#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;

ll xuly(string a)
{
    ll p = a.size()-1;
    ll sum = 0;
    for(int i = 0;i < a.size();i++) {
        ll s = pow(2,p)*(a[i]-'0');
        sum += s;
        p--;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    cin >> a >> b;
    ll a1 = xuly(a),b1 = xuly(b);
    a1 = ceil(sqrt(a1));
    b1 = sqrt(b1);
    cout << b1-a1+1;
    return 0;
}