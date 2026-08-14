#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
double X[MM],Y[MM];


double cntdist(double a,double b,double c,double d,double U,double V)
{
    double x = d - b;
    double y = a - c;
    double dist = abs(x * U + y * V - (x * a + y * b)) / (sqrt(x * x + y * y));
    return dist;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int j = 1,k = 1;
    for(int i = 1;i <= 6;i++) {
        if(i % 2 == 1) cin >> X[j++];
        else cin >> Y[k++];
    }
    double max_edge = oo;
    int X1 = 0,Y1 = 0,X2 = 0,Y2 = 0;
    if(cntdist(X[1],Y[1],X[2],Y[2],X[3],Y[3]) < max_edge) {
        max_edge = cntdist(X[1],Y[1],X[2],Y[2],X[3],Y[3]);
        X1 = X[1]; Y1 = Y[1];
        X2 = X[2]; Y2 = Y[2];
    }
    if(cntdist(X[1],Y[1],X[3],Y[3],X[2],Y[2]) < max_edge) {
        max_edge = cntdist(X[1],Y[1],X[3],Y[3],X[2],Y[2]);
        X1 = X[1]; Y1 = Y[1];
        X2 = X[3]; Y2 = Y[3];
    }
    if(cntdist(X[3],Y[3],X[2],Y[2],X[1],Y[1]) < max_edge) {
        max_edge = cntdist(X[3],Y[3],X[2],Y[2],X[1],Y[1]);
        X1 = X[2]; Y1 = Y[2];
        X2 = X[3]; Y2 = Y[3];
    }

    cout << X1 << ' ' << Y1 << ' ' << X2 << ' ' << Y2;
    return 0;
}