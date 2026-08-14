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
    int q;
    cin >> q;
    while(q--) {
        int x,k;
        cin >> x >> k;
        if(x == 1) {
            f.push_back(k);
        }
        else {
            int ans = 0,cnt = 1;
            for(int i = f.size()-1;i >= 0;i--) {
                if(cnt == k) {
                    ans = f[i];
                    break;
                }
                cnt++;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}