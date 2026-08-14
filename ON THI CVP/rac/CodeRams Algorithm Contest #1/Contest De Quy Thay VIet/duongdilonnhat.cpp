#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[10][10],ans = 0;
vector<ll> f;

void backtrack(ll i,ll j)
{
    if(f.size() == 6) {
        ll sum = 0;
        for(auto i:f) {
            sum+=i;
            //cout << i << " ";
        }
        //cout << '\n';
        ans = max(ans,sum);
    }
    f.push_back(a[i][j]);
    if(i+1 <= 4 && j <= 4) backtrack(i+1,j); 
    if(j+1 <= 4 && i <= 4) backtrack(i,j+1);
    f.pop_back();

}

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
    for(int i = 1;i <= 4;i++) {
        for(int j = 1;j <= 4;j++) {
            cin >> a[i][j];
        }
    }
    //f.push_back(a[1][1]);
    backtrack(1,1);
    cout << ans+a[4][4];
    return 0;
}