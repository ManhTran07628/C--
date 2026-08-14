#include<bits/stdc++.h>
using namespace std;
const int N=200000 ;
long long i,j,n,k,s1,s2,l,r,ans ;
long long a[N+5] ;
bool check(long long x){
    vector<long long> f(n+5,0),s1(n+5,0), s2(n+5,0) ;
    long long lt=sqrt(x) ;
    long long res=0 ;
    for(i=1;i<=n;i++){
        f[i]+=f[i-1] ;
        s2[i]+=s2[i-1];
        s1[i]+=s1[i-1] ;
        long long w=f[i]*x-(i*i*f[i]-2*i*s2[i]+s1[i]) ;
        if(w<a[i]){
            long long cnt=(a[i]-w)/x ;
            if((a[i]-w)%x!=0) cnt++ ;
            f[i+1]+=cnt ;
            res+=cnt ;
            s1[i+1]+=cnt*i*i ;
            s2[i+1]+=cnt*i ;
            if(i+lt+1<=n){
                f[i+lt+1]-=cnt ;
                s1[i+lt+1]-=cnt*i*i ;
                s2[i+lt+1]-=cnt*i ;
            }
        }
    }
    if(res<=k) return 1 ;
    else return 0 ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #define NAME "BANSUNG"
    if(fopen(NAME".inp", "r")){
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
    cin >> n >> k;
    for(i=1;i<=n;i++){
        cin >> a[i] ;
    }
    l=1 ;r=(long long)1e18 ;
    while(l<=r){
        long long mid=(l+r)/2 ;
        if(check(mid)){
            //cout << r << '\n' ;
            r=mid-1;
            ans=mid;
        }else l=mid+1 ;
    }
    cout << ans ;
    return 0;
}
