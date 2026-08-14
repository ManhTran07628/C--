#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (int) 1e18
const int MM = 1e5 + 7;
const int MOD = 1e9 + 7;
int n,a[MM],Lmax[MM],Lmin[MM],Rmax[MM],Rmin[MM];
int psmin[MM],psmax[MM],presum[MM];

int add(ll a,ll b) {return (a + b) % MOD;}
int del(ll a,ll b) {return (a % MOD - b % MOD + MOD) % MOD;}
int mul(ll a,ll b) {return (a % MOD * b % MOD) % MOD;}

int dnc(int L,int R)
{
    if(L == R) return mul(a[L],a[L]);

    int mid = (L + R) / 2;

    int sum = add(dnc(L,mid),dnc(mid + 1,R));

    Lmin[mid + 1] = oo; Lmax[mid + 1] = 0;
    for(int i = mid;i >= L;i--) {
        Lmin[i] = min(Lmin[i + 1],a[i]);
        Lmax[i] = max(Lmax[i + 1],a[i]);
    }

    Rmin[mid] = oo; Rmax[mid] = 0;
    for(int i = mid + 1;i <= R;i++) {
        Rmin[i] = min(Rmin[i - 1],a[i]);
        Rmax[i] = max(Rmax[i - 1],a[i]);
    }

    psmin[mid] = 0; psmax[mid] = 0; presum[mid] = 0;
    for(int i = mid + 1;i <= R;i++) {
        psmin[i] = add(psmin[i - 1],Rmin[i]);
        psmax[i] = add(psmax[i - 1],Rmax[i]);
        presum[i] = add(presum[i - 1],mul(Rmin[i],Rmax[i]));
    }

    for(int l = mid,j = mid + 1,k = mid + 1;l >= L;l--) {
        while(j <= R && Lmin[l] < Rmin[j]) j++;
        while(k <= R && Lmax[l] > Rmax[k]) k++;

        int posj = j - 1, posk = k - 1;
        if(posj < posk) {
            int t1 = mul( mul(Lmin[l],Lmax[l]), (posj - mid) );
            sum = add(sum,t1);
            int t2 = mul(Lmax[l],del(psmin[posk],psmin[posj]));
            sum = add(sum,t2);
            int t3 = del(presum[R],presum[posk]);
            sum = add(sum,t3);  
        }
        else {
            int t1 = mul( mul(Lmin[l],Lmax[l]), (posk - mid) );
            sum = add(sum,t1);
            int t2 = mul(Lmin[l],del(psmax[posj],psmax[posk]));
            sum = add(sum,t2);
            int t3 = del(presum[R],presum[posj]);
            sum = add(sum,t3);
        }
    }
    
    return sum;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    cout << dnc(1,n);
    return 0;
}