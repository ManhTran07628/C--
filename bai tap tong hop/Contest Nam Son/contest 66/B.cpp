#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


int check(int k)
{
    int cnt = 0;
    while(k > 0) {
        if(k & 1 == 1) cnt++;
        k >>= 1;
    }
    return cnt == 2;
}



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
    for(int i = 1;i <= 100;i++) {
        if(check(i)) cout << i << '\n';
    }
    return 0;
}