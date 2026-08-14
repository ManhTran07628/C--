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
    string s;
    cin >> s;
    for(int i = s.size()-2;i >= 0;i--) {
        if(s[i]-'0' > 0 && s[i+1]-'0' < 9) {
            s[i+1]++;
            s[i]--;
            cout << s;
            return 0;
        }
    }
    cout << 0;
    return 0;
}