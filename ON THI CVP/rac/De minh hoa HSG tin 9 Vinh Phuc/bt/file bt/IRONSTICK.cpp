#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 1;
ll a[N],t1,t2,t3,t4,t5;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "ARRSUM"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll A,B,C;
    cin >> A >> B >> C;
    ll cachxet = 0;
    cachxet += min(A/2,B/2);
    cachxet += min(A/3,C);
    cachxet += min(A,C/2);
    cachxet += A / 5;
    cachxet += min(B/2,C);
    cout << cachxet;
}
//
//2 2 3 3
//2 2 2 4
//2 4 4
//2 2 2 2 2
//3 3 4
