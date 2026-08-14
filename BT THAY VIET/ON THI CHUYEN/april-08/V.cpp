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
    for(int i = 0;i < n;i++) {
        if(s[i] == 'J') s[i] = 'O';
        else if(s[i] == 'O') s[i] = 'I';
        else s[i] = 'J';
    }
    cout << s;
    return 0;
}