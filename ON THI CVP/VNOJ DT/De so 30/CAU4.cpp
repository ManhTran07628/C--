#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CAU4"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int k;
    string s;
    cin >> k;
    cin.ignore();
    getline(cin,s);
    vector<char> f;
    for(int i = 0;i < s.size();i++) {
        if(s[i] != ' ') {
            char tmp;
            if(s[i] - k < 'A') {
                tmp = 'Z' + (s[i]-'A') - k + 1;
                f.push_back(tmp);
            }
            else f.push_back(char(s[i]-k));
        }
        else f.push_back(s[i]);
    }
    for(int i = 0;i < s.size();i++) {
        cout << f[i];
    }
    return 0;
}