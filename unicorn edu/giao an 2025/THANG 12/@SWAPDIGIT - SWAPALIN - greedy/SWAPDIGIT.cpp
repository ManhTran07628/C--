#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b / __gcd(a,b)
#define I first
#define II second
#define pb push_back
#define ii pair<int,int>
const int INF = 2 * 1e9;
const int N = 1e5 + 1;
const int MOD = 1e9 + 7;
    int main()
        {
        #define TASKNAME "swapalin"
            ios_base::sync_with_stdio(0);
            cin.tie(0);
        if (fopen(TASKNAME".inp","r" )) {
            freopen(TASKNAME".inp","r",stdin);
            freopen(TASKNAME".out","w",stdout); }
            string s;
            while (cin>>s)
            {
               vector<char> x;
               int n=s.size();
               for (int i=0;i<n/2;i++)
                if (s[i]!=s[n-i-1]) x.pb(s[i]),x.pb(s[n-i-1]);
               sort(x.begin(),x.end());
               int m=x.size();
               if (m==0) cout<<"YES"<<'\n'; else
                 if (m==4 && x[0]==x[1] && x[2]==x[3]) cout<<"YES"<<'\n'; else
                    if (m==2 && n%2==1 && (x[0]==s[n/2] || x[1]==s[n/2])) cout<<"YES"<<'\n'; else cout<<"NO"<<'\n';
            }
            return 0;
        }