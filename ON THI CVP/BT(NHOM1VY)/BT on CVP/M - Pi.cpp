#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N],p[N];
void sieve()
{
    fill(p+1,p+N+1,1);
    p[1] = p[0] = 0;
    for(int i = 1;i < sqrt(N);i++)
        if(p[i])
            for(int j = i*i;j < N;j+=i)
                p[j] = 0;
    
}

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
    sieve();
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) {
        for(int j = i+1;j <= n;j++) {
            if(p[a[i]] && p[a[j]]) cout << a[i] << ' ' << a[j] << '\n';
        }
    }
    return 0;
}