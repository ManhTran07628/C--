#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 2e3+7;
const int base = 256;
const int MOD[] = {(int) 1e9 + 2277,(int) 2e9 + 11,(int) 1e9 + 5577};
const int MS = 2;
ll Pow[MS + 3][MM],Hash[MS + 3][MM],good[MM],n,k;
string s,t;
map< pair<ll,ll> , ll> mp;

ll gethash(int l,int r,int k)
{
    return (Hash[k][ r ] - Hash[k][ l-1 ] * Pow[k][ r-l+1 ] % MOD[k] + MOD[k]) % MOD[k];
}

void Hashing()
{
    for(int j = 0;j < MS;j++) {
        Pow[j][ 0 ] = 1;
        for(int i = 1;i <= n;i++)
            Pow[j][ i ] = (Pow[j][ i-1 ] * base) % MOD[j];

    }
    for(int j = 0;j < MS;j++) 
        for(int i = 1;i <= n;i++) 
            Hash[j][ i ] = (Hash[j][ i-1 ] * base + s[ i ] - 'a' + 1) % MOD[j];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t >> k;
    n = s.size();
    s = ' ' + s;
    for(int i = 0;i < t.size();i++) good[ i ] = t[i] - '0';

    Hashing();



    int res = 0;
    for(int i = 1;i <= n;i++) {
        int cntbad = 0;

        for(int j = i;j <= n;j++) {
            int val = (good[ s[ j ] - 'a' ] ? 0 : 1);
            
            if(cntbad + val > k) break;
            
            cntbad += val;
            bool ok = 1;

            if(mp[ {gethash(i,j,0),gethash(i,j,1)} ] == 0) res++;
            mp[ {gethash(i,j,0),gethash(i,j,1)} ] = 1;

        }

    }

    cout << res;
    return 0;
}