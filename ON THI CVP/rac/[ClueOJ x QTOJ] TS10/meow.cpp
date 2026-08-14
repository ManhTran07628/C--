#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],p[MAXN],w[MAXN];
int n;


void sieve()
{
    for(int i = 2;i*i < MAXN;i++) {
        if(p[i] == 0) {
            for(int j = i*2;j < MAXN;j+=i) {
                if(p[j] == 0) 
                    p[j] = i;
            }
        }
    }
    for(int i = 2;i < MAXN;i++) {
        if(p[i] == 0) p[i] = i;
    }
}

void sub1()
{
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        int sum = 1;
        for(int j = i;j <= n;j++) {
            sum *= a[j];
            int p = sqrt(sum);
            if(p*p == sum) ans = max(ans,j-i+1);
        }
    }       
    cout << ans;
}

void sub2()
{
    unordered_map<int,int> lt;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i;j <= n;j++) {
            int val = a[j];
            while(val > 1) {
                lt[p[val]]++;
                val /= p[val];
            }
            bool ok = 1;
            for(auto i:lt) 
                if(i.se % 2 == 1) {
                    ok = 0;
                    break;
                }
            if(ok) ans = max(ans,j-i+1);
        }
        lt.clear();
    }
    cout << ans;
}
void sub3()
{
    unordered_map<int,int> lt;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i;j <= n;j++) {
            lt[a[j]]++;
            bool ok = 1;
            for(auto i:lt) 
                if(i.se % 2 == 1) {
                    ok = 0;
                    break;
                }
            if(ok) ans = max(ans,j-i+1);
        }
    }
    cout << ans;
}
void sub4()
{
    unordered_map<int,int> lt,d;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i;j <= n;j++) {
            lt[2] += d[a[j]];
            if(lt[2]%2==0) ans = max(ans,j-i+1);
        }
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "meow"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    cin >> n;
    bool l1 = 1,l2 = 1;
    unordered_map<int,int> d;
    for(int i = 1;i < 25;i++) {
        int c = pow(2,i);
        d[c] = i;
    }
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        w[i] = a[i];
        if(p[a[i]] != a[i]) l1 = 0;
        if(d.find(a[i]) == d.end()) l2 = 0;
    }
    sort(w+1,w+n+1);
    if(n <= 10 && w[n] <= 50) sub1();
    if(n <= 1000 && w[n] <= 1000) sub2();
    if(l1) sub3();
    if(l2) sub4();
    return 0;
}