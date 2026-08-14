#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
map<int,int> p;
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
    int n,n1;
    cin >> n;
    n1 = n;
    for(int i = 2;i <= n;i++) {
        while(n % i == 0) {
            p[i]++;
            n /= i;
        }
    }
    cout << n1 << " = ";
    int j = 0;
    for(pair<int,int> i: p) {
        if(j == p.size()-1) cout << i.fi << " ^ " << i.se;
        else cout << i.fi << " ^ " << i.se << " * ";
        j++;
    }
    return 0;
}