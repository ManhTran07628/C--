#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
set<int> s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,k,c,d,q;
    cin >> a >> b >> k >> c >> d >> q;
    for(int i = a;i <= b;i++) 
        if(i % k == 0) s.insert(i);
    for(int i = c;i <= d;i++) 
        if(i % q == 0) s.insert(i);
    cout << s.size();
    return 0;
}