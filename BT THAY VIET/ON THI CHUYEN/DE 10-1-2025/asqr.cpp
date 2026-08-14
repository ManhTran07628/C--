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
    int x1,y1,w1,h1,x3,y3,w3,h3;
    cin >> x1 >> y1 >> w1 >> h1 >> x3 >> y3 >> w3 >> h3;
    int x2,y2,x4,y4;
    x2 = x1+w1;y2 = y1+h1;
    x4 = x3+w3;y4 = y3+h3;
    
    int s1 = w1*h1;
    int s2 = w3*h3;
    int s3 = max(0,(min(x2,x4)-max(x1,x3)))*max(0,(min(y2,y4) - max(y1,y3)));
    cout << s1 + s2 - s3*2;
    return 0;
}