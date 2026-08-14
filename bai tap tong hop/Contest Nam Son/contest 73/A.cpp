#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    cin >> s;
    char pre = 'A';
    for(int i = 0;i < s.size();i++) {
        if(i == 0) {
            t += s[i];
            pre = s[i];
            continue;
        }
        if(pre != s[i]) t += s[i];
        pre = s[i];
    }
    cout << t;
    return 0;
}