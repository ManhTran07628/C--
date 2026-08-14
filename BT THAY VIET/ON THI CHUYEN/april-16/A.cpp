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
    cin >> s >> t;
    s = s + s;
    for(int i = 0;i < t.size();i++) {
        string tmp = s.substr(i,t.size());
        if(tmp == t) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}