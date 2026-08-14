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
    int n,k;
    cin >> n >> k;
    if(k == 1) {
        cout << 1;
    }
    else if(k == 2) {
        int x = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = i+1;j+i <= n;j++) {
                if(i < j && i + j == n) x++;
            }
        }
        cout << x;
    }
    else if(k == 3) {
        int x = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = i+1;j+i <= n;j++) {
                for(int k = j+1;k+j+i <= n;k++) {
                    if(i < j && j < k && i+j+k == n) x++;
                }
            }
        }
        cout << x;
    }
    else {
        int x = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = i+1;j+i <= n;j++) {
                int t = n - i - j;
                x += max(0,(t-1)/2-j);
            }
        }
        cout << x;
    }
    return 0;
}