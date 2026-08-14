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
    p[1] = p[0] = 0;
    for(int i = 2;i*i < N;i++)
        if(p[i])
            for(int j = i*2;j < N;j+=i) 
                p[j] = 0;
}

bool check(int a)
{
    int cnt = 0;
    while(a > 0)
    {
        int tmp = (a % 10);
        cnt += tmp * tmp;
        a /= 10;
    }
    return p[cnt];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "sodep"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    int n;
    cin >> n;
    int c = 0;
    for(int i = 1;i <= N;i++)
    {
        if(check(i)) c++;
        if(c == n)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}