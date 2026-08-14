#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size();
    while(q--) {
        int i;
        cin >> i;
        reverse(s.begin()+i-1,s.end()-i+1);
    }
    cout << s;
    return 0;
}