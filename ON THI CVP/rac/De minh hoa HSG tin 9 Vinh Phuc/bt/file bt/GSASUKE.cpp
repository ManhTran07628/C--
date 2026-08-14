#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],f[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "GSASUKE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    f[1] = a[1];
    f[2] = f[1]+abs(a[1]-a[2]);
    for(int i = 3;i <= n;i++) {
        f[i] = min(f[i-1]+abs(a[i]-a[i-1]),f[i-2]+2*abs(a[i]-a[i-2]));
    }
    cout << f[n];
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
const int N=1e7+5;
long long n,a[N],dp[N];
int main() {
#define taskname "LARES"
if(fopen(taskname ".inp" , "r")){
    freopen(taskname ".inp" , "r" , stdin);
    freopen(taskname ".out" , "w" , stdout);
}
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    dp[1]=a[1];
    dp[2]= abs(a[1]-a[2]);
    for (int i=3;i<=n;i++){
        dp[i]=min(dp[i-1]+abs(a[i-1]-a[i]),dp[i-2]+2*abs(a[i-2]-dp[i]));
    }
    cout<<dp[n];
    return 0;
}