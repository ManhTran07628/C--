#include<bits/stdc++.h>
using namespace std;
const int N = 30;
const int INF = 2*1e9;
long long n,l, ans = 0;
struct item {
    long long h,w,c;
};
bool cmp(item x, item y)
{
    return (x.w + x.c) > (y.w + y.c);
}
item a[N];
void check(int x)
{
    vector <item> b;
    b.clear();
    long long k = 0;
    //cout << "start \n" ;
    for (int i=0; i<n; i++)
         if ((x >> i)&1){
             b.push_back(a[i]);
             k+= a[i].h;
           //  cout << b[i].h << " " << b[i].w << " " << b[i].c << endl;
         }
        if (k < l) return;
    sort(b.begin(),b.end() ,cmp);
    k = INF;
    for (auto u : b ){
        if (k < u.w) return;
        else
        k = min(u.c,k - u.w);
    }
  //  cout << k;
    ans = max(ans, k);

}
int main()
{
     ios_base::sync_with_stdio(0);
            cin.tie(0);
    cin >> n >> l;
    for (int i=0; i<n; i++)
       cin >> a[i].h >> a[i].w >> a[i].c;
    for (int i=1; i<(1<<n); i++)
       check(i);
    cout << (ans == 0 ? -1 : ans);
    return 0;
}