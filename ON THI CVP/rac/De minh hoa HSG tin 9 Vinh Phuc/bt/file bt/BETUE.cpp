#include <bits/stdc++.h>
const int M = 3E5+2;
using namespace std;
int i, n, m;
int a[M];
bool kt (int x){
int s = 0;
for (int i = 1; i <= n; i++){
s = s+ a[i] / x;
if (a[i] % x != 0) s = s +1;
}
return (s <= m);
}
void solve (){
int res = 0;
int dau = 1, cuoi = 1E9;
while (dau <= cuoi){
int giua = (dau+cuoi) / 2;
if (kt(giua)){
res = giua;
cuoi = giua - 1;
} else dau = giua + 1;
}
cout << res;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie (0); cout.tie (0);
cin >> n >> m;
for (int i = 1; i <= n; i++) cin >> a[i];
solve();
return 0;
}
