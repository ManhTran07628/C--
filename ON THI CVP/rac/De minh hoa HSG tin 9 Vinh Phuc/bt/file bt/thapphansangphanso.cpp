#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    long long d=0;
    for(long long  i=0;i<s.size();i++){
    if(s[i]=='.'){
        i++;
        while(isdigit(s[i]) && i < s.size()) {
            d++;
            i++;
        }
    }
    }
     long long ans=1;
     while(d--)
     {
         ans=ans*10;
     }
     long long p = stod(s) * ans;
     long long u = __gcd(ans,p);
     cout<<p/u<<" "<<ans/u;
    return 0;
}
