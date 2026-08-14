#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    int i = 0;
    if(x+y+z < n) z = z + (n-x-y-z);
    string ans;
    while(z--) {
        if(i%2==0) ans += '0';
        else if(i%2==1) ans += '1';
        i++;
    }
    i = 0;
    while(x--) {
        if(i%2==0) ans += 'A';
        else if(i%2==1) ans += 'B';
        i++;
    }
    i = 0;
    while(y--) {
        if(i%2==0) ans += 'a';
        else if(i%2==1) ans += 'b';
        i++;
    }
    cout << ans << '\n';
    return 0;   
}