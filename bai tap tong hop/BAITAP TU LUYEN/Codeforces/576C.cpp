#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
const int blockSize = 1001;
int n;
struct QR{int l,r,id;} qr[MM + 7];

bool cmp(QR a,QR b)
{
    int Pa = (a.l + blockSize - 1) / blockSize;
    int Pb = (b.l + blockSize - 1) / blockSize;
    if(Pa != Pb) return Pa < Pb;

    if(Pa % 2 == 1) return a.r < b.r;
    else return a.r > b.r;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> qr[i].l >> qr[i].r;
        qr[i].id = i;
    }
    sort(qr+1,qr+n+1,cmp);
    for(int i = 1;i <= n;i++) cout << qr[i].id << ' ';

    return 0;
}