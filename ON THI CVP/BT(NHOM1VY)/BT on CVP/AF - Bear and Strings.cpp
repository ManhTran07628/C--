#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
char a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int ans = 0,k = 0;
    int n = s.size();
    for(int i = 0;i < n;i++) {
        if(s[i] == 'b' && s[i+1] == 'e' && s[i+2] == 'a' && s[i+3] == 'r') {
            ans += (n-i-3)*(i+1-k);
            k = i+1;
        }
    }
    cout << ans;
    return 0;
}