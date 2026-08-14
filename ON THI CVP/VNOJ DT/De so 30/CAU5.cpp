#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
const int N = 1e6+7;
int a[N],n;
vector<int> f;

void div(ll k)
{
    for(int i = 1;i <= sqrt(k);i++) {
        if(k % i == 0) {
            f.pb(i);
            if(k % i != i) f.pb(k/i);
        }
    }
    sort(f.begin(),f.end());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CAU5"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    int p = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        p += a[i];
    }
    int ans = 1;
    div(p);
    for(auto i:f) {
        int cnt = 0,sum = 0,c = 1;
        for(int j = 1;j <= n;j++) {
            sum += a[j];
            //cout << sum << " ";
            if(sum == i) {
                cnt++;
                sum = 0;
            }
            else if(sum > i){
                c = 0;
                break;
            }
        }
        //cout << '\n';
        if(c) ans = max(ans,cnt);
    }
    cout << ans;
    return 0;
}