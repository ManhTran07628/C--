#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5+10;
long long n, a[N], s[N];
vector <int> q;
int main()
{
      #define name "viewdist"
    ios_base::sync_with_stdio(0);
            cin.tie(0);
    if ( fopen ( name".inp", "r") )
    {
        freopen (name".inp", "r", stdin);
        freopen (name".out", "w", stdout);
    }
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    long long ans = 0;
    q.push_back(1);
    for (int i=2; i<=n; i++){
      //  if (q.empty()){ q.push_back(i); continue;}
        while(!q.empty() && a[q.back()] < a[i]){
            ans += i-q.back()+1;
            q.pop_back();
        }
        if (!q.empty()) ans += i-q.back()+1;
        q.push_back(i);
    }
    cout << ans;
    return 0;
}