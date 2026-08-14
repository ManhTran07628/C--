#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
int main()
{
    string l;
    cin >> l;
    ll solc = 0,solo = 0,solr = 0,soln = 0,sola = 0;
    for(int i = 0;i < l.size();i++) {
        if(l[i] == 'C') solc++;
        if(l[i] == 'O') solo++;
        if(l[i] == 'R') solr++;
        if(l[i] == 'A') sola++;
        if(l[i] == 'N') soln++;
    }
    solo /= 2;
    ll kq = min(solc,min(solo,solr));
    kq = min(kq,min(soln,sola));
    cout << kq;
    return 0;
}


