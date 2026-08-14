#include<bits/stdc++.h>
using namespace std;
#define taskname ""
#define ll long long
const int N = 1e6+5;
ll t;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    if(fopen(taskname ".inp", "r")){
        freopen(taskname ".inp","r", stdin);
        freopen(taskname ".out", "w", stdout);
    }
    cin>>t;
    while(t--){
        int a , b , x,ans = 1e9,di=0,dj=0;
        cin>>a>>b>>x;
        ans = min(ans, abs(a - b));
        for(int i = a ; i > 0 ; i /=x){
            dj = 0;
            for(int j = b ; j > 0 ; j/=x){
                ans = min(ans,abs(i-j)+ di + dj);
                dj++;
            }
            di++;
        }
        di = dj = 0;
        while(a > 0){
            a/=x;
            di++;
        }
        while(b > 0){
            b/=x;
            dj++;
        }
        ans = min(ans ,di+dj);
        cout<<ans<<'\n';
    }
    return 0;
}