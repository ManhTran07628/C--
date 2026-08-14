#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

vector<string> f;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tachmaso"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++) {
        if(isdigit(s[i])) {
            string t;
            while(isdigit(s[i]) && i < s.size()) {
                t += s[i];
                i++;
            }
            f.push_back(t);
        }
    }
    sort(f.begin(),f.end());
    for(auto c:f) {
        cout << c << " ";
    }
    return 0;
}