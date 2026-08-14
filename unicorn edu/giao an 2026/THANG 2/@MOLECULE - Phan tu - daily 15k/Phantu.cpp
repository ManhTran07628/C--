#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin >> s;
    int t = 0, d = 0, b = 0, w = 0;
    if (s[0] == 'B' && s[s.size()-1] == 'W') t++;
    if (s[0] == 'B') b++;
    else w++;
    for (int i=1; i<s.size(); i++){
        if (s[i] != s[i-1] && s[i] == 'B') t++;
        if (s[i] == 'B') b++;
        else w++;
    }
    if (b == s.size() || w == s.size())
        cout << 0;
    else
        cout << t-1;
    return 0;
}