#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 3e7+7;
int p[MAXN];
void sieve()
{
    fill(p+1,p+MAXN+1,1);
    p[1] = p[0] = 0;
    for(int i = 1;i*i < MAXN;i++)
        if(p[i])
            for(int j = i*i;j < MAXN;j+=i)
                p[j] = 0;
    
}

bool isprime(ll k)
{
    if(k < 2) return 0;
    for(int i = 2;i*i <= k;i++) if(k%i==0)return 0;
    return 1;
}

bool palindcheck(ll k)
{
    string s = to_string(k);
    string s1 = s;
    reverse(s1.begin(),s1.end());
    return s1 == s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int a,b;
    cin >> a >> b;
    for(int i = a;i <= b;i++) {
        if(i >= MAXN) {
            if(isprime(i)&&palindcheck(i))cout<<i<<'\n';
        }
        else {
            if(p[i]&&palindcheck(i))cout<<i<<'\n';
        }
    }
    return 0;
}