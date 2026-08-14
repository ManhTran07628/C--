#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
map<int,ll> lt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    for(int i = 0;i < s.size();i++) {
        if(s[i] != '0') {
            swap(s[0],s[i]);
            break;
        }
    }
    cout << s;
    return 0;
}