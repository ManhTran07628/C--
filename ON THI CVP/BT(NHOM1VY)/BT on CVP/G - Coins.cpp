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
    int n = 0,m = 0,k = 0;
    for(int i = 1;i <= 3;i++) {
        string s;
        cin >> s;
        if(s[0] == 'A') {
            if(s[1] == '>') n++;
            else {
                if(s[2] == 'B') m++;
                else k++;
            }
        }
        if(s[0] == 'B') {
            if(s[1] == '>') m++;
            else {
                if(s[2] == 'A') n++;
                else k++;
            }
        }
        if(s[0] == 'C') {
            if(s[1] == '>') k++;
            else {
                if(s[2] == 'A') n++;
                else m++;
            }
        }
    }
    if(n == m || m == k || k == n) {
        cout << "Impossible";
        return 0;
    }
    if(min({n,m,k}) == n) {
        if(min(m,k) == m) cout << "ABC";
        else cout << "ACB";
    }
    if(min({n,m,k}) == m) {
        if(min(n,k) == n) cout << "BAC";
        else cout << "BCA";
    }
    if(min({n,m,k}) == k) {
        if(min(m,n) == n) cout << "CAB";
        else cout << "CBA";
    }
    return 0;
}