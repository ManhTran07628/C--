#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N=5001;
pair<pair<int,int>,int> t[N];
pair<int,int> f[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "TOWER"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(c>b) swap(b,c);
        if(b>a) swap(a,b);
        if(c>b) swap(b,c);
        t[i]={{a,b},c};        
    }
    sort(t,t+n);
    //for(int i=0;i<n;i++) cout<<i<<' '<<t[i].fi.fi<<' '<<t[i].fi.se<<' '<<t[i].se<<'\n';
    f[0]={t[0].se,1};
    int ma=0,cntma=0;
    for(int i=1;i<n;i++)
    {
        f[i]={t[i].se,1};
        for(int j=0;j<i;j++)
        {
            if(t[i].fi.fi>=t[j].fi.fi&&t[i].fi.se>=t[j].fi.se)
            {
                if(f[j].fi+t[i].se>f[i].fi)
                {
                    f[i].fi=f[j].fi+t[i].se;
                    f[i].se=f[j].se+1;
                }
                else if(f[j].fi==f[i].fi)
                    f[i].se=max(f[i].se,f[j].se+1);
            }
        }
        if(f[i].fi>ma)
        {
            ma=f[i].fi;
            cntma=f[i].se;
        }
        else if(f[i].fi==ma) cntma=max(cntma,f[i].se);
        //cout<<i<<' '<<f[i].fi<<' '<<f[i].se<<'\n';
    }
    cout<<cntma<<' '<<ma;
}