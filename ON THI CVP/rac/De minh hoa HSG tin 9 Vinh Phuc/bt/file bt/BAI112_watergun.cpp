#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "cut"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,doi1 = 0,doi2 = 0,tg1 = -1,tv1 = 0;
    int tg2 = -1,tv2 = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int t,a,b;
        cin >> t >> a >> b;
        if(a <= 4) {
            doi1 += 100;
            if(tg1 + 10 >= t && tv1 == a) {
                doi1+=50;
            }
            else tg1 = t;
            tv1 = a;
        }
        else {
            doi2 += 100;
            if(tg2 + 10 >= t && tv2 == a) doi2 += 50;
            else tg2 = t;
            tv2 = a;
        }
    }
    return 0;
}

