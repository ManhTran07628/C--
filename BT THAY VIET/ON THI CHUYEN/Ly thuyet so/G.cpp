#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int p[N];
void sieve()
{
    fill(p+1,p+N+1,1);
    p[0] = p[1] = 0;
    for(int i = 2;i <= sqrt(N);i++) 
        if(p[i])
            for(int j = i*i;j <= N;j+=i) 
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
    int kt = 0;
    for(int i = 2;i <= n-2;i++) {
        if(p[i] && p[i+2]) {    
            cout << i << ' ' << i+2 << '\n';
            kt = 1;
        }
    }
    if(!kt) cout << "empty";
    return 0;
}