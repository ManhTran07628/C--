#include<bits/stdc++.h>
using namespace std;
const int N=100000 ;
long long i,j,n,s,ans;
long long a[N+5],pre[N+5],pos[N+5];
vector<pair<long long, long long> > vt ;
int st[4*N+5] ;
void up(int id, int l, int r, int u){
    if(l==r){
        st[id]=vt[u].second ;
        return ;
    }
    int mid=(l+r)/2 ;
    if(u<=mid) up(2*id,l,mid,u) ;
    else up(2*id+1,mid+1,r,u) ;
    st[id]=max(st[2*id], st[2*id+1]) ;
    return ;
}
int get(int id, int l, int r, int u, int v){
    if(r<u || v<l) return -1 ;
    if(u<=l && r<=v) return st[id] ;
    int mid=(l+r)/2 ;
    return max(get(2*id,l,mid,u,v), get(2*id+1,mid+1,r,u,v)) ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #define NAME "XOADOAN"
    if(fopen(NAME".inp", "r")){
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
    memset(st,-1,sizeof(st)) ;
    cin >> n;
    ans=n+1 ;
    vt.push_back({0,0}) ;
    for(i=1;i<=n;i++){
        cin >> a[i] ;
        pre[i]=pre[i-1]+a[i] ;
        vt.push_back({pre[i],i}) ;
    }
    cin >> s;
    if(pre[n]<=s){
        cout << 0 ;
        return 0 ;
    }
    sort(vt.begin(), vt.end()) ;
    for(i=0;i<=n;i++) pos[vt[i].second]=i ;
    up(1,0,n,pos[0]) ;
    for(i=1;i<=n;i++){
        if(vt[0].first <= s+pre[i]-pre[n]){
            pair<long long, long long> st={s+pre[i]-pre[n],n+1};
            int k=upper_bound(vt.begin(), vt.end(), st)-vt.begin() ;
            k--;
            j=get(1,0,n,0,k) ;
            if(j!=-1) ans=min(ans, i-j) ;
        }
        up(1,0,n,pos[i]) ;
    }
    if(ans==n+1) ans=-1 ;
    cout << ans ;
    return 0;
}
