#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int d = 0;
    for(int i = s.size()-1;i >= 0;i--) {
        if(s[i]=='0') d++;
        else break;
    }
    cout << d;
    return 0;
}
