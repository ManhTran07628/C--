#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e5+7;
vector<string> f;
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
    sort(s.begin(),s.end());
    f.push_back(s);
    while(next_permutation(s.begin(),s.end())) f.push_back(s);
    cout << f.size() << '\n';
    for(auto c:f) {
        cout << c << '\n';
    }
    return 0;
}