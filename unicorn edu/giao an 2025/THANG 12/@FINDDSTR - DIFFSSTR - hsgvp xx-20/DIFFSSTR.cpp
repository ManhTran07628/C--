#include<bits/stdc++.h>
using namespace std;
string s;
long long n,res,i;
int main(){
    cin>>n;
    cin>>s;
    res=1;
    while(res<=n){
        map<string,int> dem;
        int kt=0;
        for(i=0;i<n-res+1;i++){
            string s1=s.substr(i,res);
            if(dem[s1]>0){
                kt++;
                break;
            }
            dem[s1]++;
        }
        if(kt==0){
            cout<<res;
            return 0;
        }
        res++;
    }
return 0;
}