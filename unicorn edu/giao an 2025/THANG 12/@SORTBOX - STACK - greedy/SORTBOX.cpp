#include <bits/stdc++.h>
using namespace std;
int n,t=0;
bool kt[2501];
struct dta
   {
       int w,c;
   } a[2501];
   bool comp(dta x,dta y)
     {
         return x.w+x.c<y.w+y.c;
     }
    int main()
        {
            ios_base::sync_with_stdio(0);
            cin.tie(0);
            cin>>n;
            for (int i=1;i<=n;i++) cin>>a[i].w;
            for (int i=1;i<=n;i++) cin>>a[i].c;
            sort(a+1,a+n+1,comp);
            int ans=0;
            memset(kt,false,sizeof(kt));
            for (int i=1;i<=n;i++)
            {
                if (a[i].c>=t)
                {
                    kt[i]=true;
                    t+=a[i].w;
                    ans++;
                } else
                 {
                     int pos=-1;
                     for (int j=i-1;j>=1;j--)
                        if (a[j].w>a[i].w && a[i].c>=t-a[j].w && kt[j])
                        {
                            if (pos==-1) pos=j; else
                                if (a[j].w>a[pos].w) pos=j;
                        }
                     if (pos==-1) continue; else
                     {
                         kt[pos]=false;
                         kt[i]=true;
                         t=t-a[pos].w+a[i].w;
                     }
                 }
            }
            cout<<ans;
            return 0;
        }