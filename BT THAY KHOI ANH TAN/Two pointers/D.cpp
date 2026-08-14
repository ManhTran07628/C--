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
    int i = 0,j = s.size()-1;
    int d = 0;
    while(i <= j) {
        if(s[i] == s[j]) {
            i++;j--;
        }
        else {
            if(s[i] == 'm') {
                i++;d++;
            }
            else if(s[j] == 'm') {
                j--;d++;
            }
            else if(s[i] != 'm' && s[j] != 'm') {
                d = -1;
                break;
            }
        }
    }
    cout << d;
    return 0;
}