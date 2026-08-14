#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "query"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,k,p;
    cin >> n >> k >> p;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for(int i = 1;i <= n+n;i++) {
        a[i] += a[i-1];
    }
    multiset<int> ms;
    for(int i = 0;i <= n-k;i++) {
        ms.insert(a[i+k]-a[i]);
    }
    for(int i = 1;i <= n+n-k;i++) {
        b[i] = *ms.rbegin();
        auto x = ms.find(a[i+k-1]-a[i-1]);
        ms.erase(x);
        ms.insert(a[i+n]-a[i+n-k]);
    }
    int e = n+1;
    string q;
    cin >> q;
    for(char i:q) {
        if(i == '!') {
            e--;
            if(e == 1) e = n+1;
        }
        else cout << b[e] << '\n';
    }
    return 0;
}