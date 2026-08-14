#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> m >> n >> k;
    int team = min(m/2,n);
    int male_left = n-team;
    int female_left = m-team*2;
    if(male_left + female_left < k) {
        k = k - (male_left + female_left);
        team = team - (k+2)/3;
    } 
    cout << team;
    return 0;
}