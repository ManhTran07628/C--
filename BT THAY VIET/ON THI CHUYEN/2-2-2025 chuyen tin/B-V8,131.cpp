#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
vector<int> f;
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
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) f.push_back(i);
    int i = 0;
    while(f.size() > 1) {
        i += (k-1);
        if(i >= f.size()) i %= f.size();
        f.erase(f.begin()+i);
    }
    cout << f[0];
    return 0;
}