#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll MM = 1e9+7;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll l,r;
    cin >> l >> r;
    ll chuki_l = sqrt(l-1)+1;
    ll soptu_l = chuki_l*2-1;
    ll vitrileft = l-((soptu_l-3)/2+1)*((soptu_l-3)/2+1);
    ll tongleft = 0;
    if(vitrileft > soptu_l/2+1) tongleft = (soptu_l-vitrileft+2)*(soptu_l-vitrileft+1)/2;
    else tongleft = chuki_l*chuki_l-(vitrileft-1)*vitrileft/2;
    // cout << soptu_l << ' ' << vitrileft << ' ' << tongleft;

    ll tongright = 0;
    ll chuki_r = sqrt(r-1)+1;
    ll soptu_r = chuki_r*2-1;
    ll vitriright = r-(chuki_r-1)*(chuki_r-1);
    if(vitriright > soptu_r/2+1)  tongright = chuki_r*chuki_r-(soptu_r-vitriright)*(soptu_r-vitriright+1)/2;
    else tongright = (vitriright+1)*vitriright/2;
    ll ans1 = chuki_r*(chuki_r+1)*(chuki_r*2+1)/6-chuki_l*(chuki_l+1)*(chuki_l*2+1)/6;
    return 0;
}
