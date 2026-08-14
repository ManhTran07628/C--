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
    int n;
    string s;
    cin >> n >> s;
    s += "///";
    for(int i = 0;i <= s.size()-1;i++) {
        if(s[i] == 'o' && s[i+1] == 'o' && s[i+2] == 'o') {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}