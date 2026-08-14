#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0;i < s.size();i++) {
        if(s[i] == '(') sum++;
        else if(s[i] == ')') sum--;
        if(sum < 0) {
            cout << "NO";
            return 0;
        }
    }
    cout << (sum == 0 ? "YES" : "NO");
    return 0;
}