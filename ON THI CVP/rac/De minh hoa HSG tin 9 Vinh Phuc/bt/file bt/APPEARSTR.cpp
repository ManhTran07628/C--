#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

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
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++) {
        a[s[i]]++;
    }
    for(char i = '0';i <= '9';i++) 
        if(a[i] != 0) 
            cout << i << " " << a[i] << '\n';
    for(char i = 'A';i <= 'Z';i++) 
        if(a[i] != 0) 
            cout << i << " " << a[i] << '\n';
    for(char i = 'a';i <= 'z';i++) 
        if(a[i] != 0) 
            cout << i << " " << a[i] << '\n';
    return 0;
}