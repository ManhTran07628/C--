#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    freopen("tinhtong.inp","r",stdin);
    freopen("tinhtong.out","w",stdout);
    long long n;
    cin>>n;
    long long temp=0;
    for(int i=0;i<n;i++){
        if(i%2==0)
        temp+=i;
    }
    cout<<temp;
    return 0;
}

