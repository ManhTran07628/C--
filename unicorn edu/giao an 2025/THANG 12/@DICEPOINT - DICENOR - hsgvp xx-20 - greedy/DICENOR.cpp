#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
    cin>>n;
    m=n/6;
    if(n%6!=0) m+=7-n%6;
    cout<<m<<" "<<n*6;
return 0;
}