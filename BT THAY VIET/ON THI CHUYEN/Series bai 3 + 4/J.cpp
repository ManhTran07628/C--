#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool check = 0;
        for(int i = 0;i < s.size();i++) {
            int crr = 0;
            while(s[i] == '*') {
                crr++;
                i++;
            }
            if(crr >= k) {
                check = 1;
                break;
            }
        }
        if(check) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}