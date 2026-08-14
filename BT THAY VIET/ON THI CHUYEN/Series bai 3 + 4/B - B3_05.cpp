#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
vector<char> v{'H','P','S'};
int h[N],p[N],s[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "hps"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        char a;
        cin >> a;
        h[i] = h[i-1] + (a=='H');
        p[i] = p[i-1] + (a=='P');
        s[i] = s[i-1] + (a=='S');
    }
    int ans = 0;
    for(int i = 0;i < 3;i++) {
        for(int j = 0;j < 3;j++) {
            for(int k = 0;k <= n;k++) {
                int cnt = 0;
                if(v[i] == 'H') cnt += p[k];
                if(v[i] == 'P') cnt += s[k];
                if(v[i] == 'S') cnt += h[k];

                if(v[j] == 'H') cnt += p[n] - p[k];
                if(v[j] == 'P') cnt += s[n] - s[k];
                if(v[j] == 'S') cnt += h[n] - h[k];
                ans = max(ans,cnt);
            }
        }
    }
    cout << ans;
    return 0;
}