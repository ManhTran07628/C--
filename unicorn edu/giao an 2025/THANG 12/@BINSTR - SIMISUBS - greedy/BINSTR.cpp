#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    #define TASKNAME "simisubs"
    if( fopen(TASKNAME".inp", "r") ){
        freopen(TASKNAME".inp", "r", stdin);
        freopen(TASKNAME".out", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int n = s.size();
    int l = 0, r = n-1;
    while (s[l] != s[n-1]) l++;
    while (s[r] != s[0]) r--;
    int x = n - l, y = r + 1;
    if (x > y)
        cout << l+1 << " " << n-1 << " " << l+2 << " " << n;
    else
    cout << 1 << " " << r << " " << 2 << " " << r+1;
    return 0;
}