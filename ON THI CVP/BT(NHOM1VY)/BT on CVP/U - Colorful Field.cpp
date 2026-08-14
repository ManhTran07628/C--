#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
vector<int> f;
int p[N];
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
    int n,m,k,t;
    cin >> n >> m >> k >> t;
    for(int i = 0;i < k;i++) {
        int a,b;
        cin >> a >> b;
        p[i] = (a-1)*m+b;
    }  
    sort(p,p+k);
    f.push_back(p[0]);
    for(int i = 1;i < k;i++) {
        f.push_back(p[i]);
    }
    sort(f.begin(),f.end());
    while(t--) {
        int i,j;
        cin >> i >> j;
        int pos = lower_bound(f.begin(),f.end(),(i-1)*m+j)-f.begin();
        //cout << pos << '\n';
        int ans = ((i-1)*m+j-pos);
       // cout << ans << '\n';
        if(f[pos] == (i-1)*m+j) {
            cout << "Waste" << '\n';
            continue;
        }
        else {
            int ans = ((i-1)*m+j-pos)%3;
            if(ans == 0) cout << "Grapes" << '\n';
            if(ans == 1) cout << "Carrots" << '\n';
            if(ans == 2) cout << "Kiwis" << '\n';
        }
    }
    return 0;
}