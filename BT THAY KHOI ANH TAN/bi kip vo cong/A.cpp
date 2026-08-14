#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];
deque<int> dqM;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int i = 1,j = 1;
    while(i <= n && j <= n) {
        if(a[j] > dqM.front()) dqM.push_back(a[j]);
        else dqM.push_front(a[j]);
        if(j-i+1 > k){
            while(dqM.back() >= a[i]&& dqM.size()>0) dqM.pop_back(); 
            i++;
        }
        if(j-i+1 == k) cout << dqM.front() << ' ';
        j++;
    }
    return 0;
}