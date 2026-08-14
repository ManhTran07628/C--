#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n;
struct dl
{
    string a,b,c;
} a[MM]; map<string,int> mp;

vector<dl> v;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].a >> a[i].b >> a[i].c;
        mp[ a[i].a ]++;
        mp[ a[i].b ]++;
    }

    for(int i = 1;i <= n;i++) {
        if(mp[ a[i].a ] == 1) v.push_back({a[i].a, a[i].b, a[i].c});
        else v.push_back({a[i].c, a[i].a, a[i].b });
    }
    sort(v.begin(),v.end(), [] (dl a,dl b){
        return a.a < b.a;
    });
    for(auto x:v) cout << x.a << ' ' << x.b << ' ' << x.c << '\n';
    return 0;
}