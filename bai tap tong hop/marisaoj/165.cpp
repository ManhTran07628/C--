#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
const int MOD[] = {(int) 1e9 + 2277,(int) 1e9 + 5277};
const int NMOD = 2;
const int base = 256;
ll POW[NMOD + 5][MM],hashT[NMOD + 5][MM],hashS[NMOD + 5];
string s,t;

ll getHash(int l,int r,int K)
{
    return (hashT[K][r] - hashT[K][l-1] * POW[K][r - l + 1] % MOD[K] + MOD[K]) % MOD[K];
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> s;
    int lenS = s.size(), lenT = t.size();
    s = ' ' + s; t = ' ' + t;
    
    for(int j = 0;j < NMOD;j++) {
        POW[j][0] = 1;

        for(int i = 1;i <= lenT;i++) 
            POW[j][i] = (POW[j][i-1] * base) % MOD[j];
        
        for(int i = 1;i <= lenT;i++)
            hashT[j][i] = (hashT[j][i-1] * base + t[i] - '0' + 1) % MOD[j];
    }

    for(int j = 0;j < NMOD;j++) {

        for(int i = 1;i <= lenS;i++) {
            hashS[j] = (hashS[j] * base + s[i] - '0' + 1) % MOD[j];
        }

    }

    int cnt = 0;

    for(int i = 1;i <= lenT-lenS+1;i++) {

        bool ok = 1;
        for(int j = 0;j < NMOD;j++) {
            if(getHash(i,i+lenS-1,j) != hashS[j]) ok = 0;
        }
        cnt += ok;

    }
    cout << cnt;

    

    return 0;
}