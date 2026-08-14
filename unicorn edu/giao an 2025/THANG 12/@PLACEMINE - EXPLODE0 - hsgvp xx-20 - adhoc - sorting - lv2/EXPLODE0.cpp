#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define task "election"
const ll Z= 20122007;
using namespace std;
int i,n,p=1,z,t,k,rs=0;
vector<int>f;
map<int,int>dem;

int boom(int y)
{   int i,n,p=1,z,t,k,rs=0;
    k=f[f.size()-1];
         i=f[y]; int j; t=1;
         while(i<f[f.size()-1])
         {  rs=0;
             for(j=i+1;j<=i+p;j++)
             {
                 if(dem[j]!=0) {rs=1; z=j; t++;}
             }
             i=z; p++;
             if(rs==0) break;
         }
     k=f[0]; i=f[y]; p=1;
     while(i>k)
     {
         rs=0;
         for(j=i-1;j>=i-p;j--)
         {
             if(dem[j]!=0) {rs=1; z=j; t++;}
         }
         i=z; p++;
             if(rs==0) break;
     }
      return t;
}
int main ()
{
  if(fopen(task".inp","r"))
    {
      freopen(task".inp","r",stdin);
      freopen(task".out","w",stdout);
    }
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       cin>>n;
       for(i=1;i<=n;i++)
       {
           cin>>z;
           f.pb(z);
           dem[z]++;
       }
       sort(all(f));
       for(i=0;i<f.size();i++)
           rs=max(boom(i),rs);
        cout<<rs;
return 0;
}