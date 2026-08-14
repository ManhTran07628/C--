#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[61];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    for(int i = 1;i <= s1;i++)
        for(int j = 1;j <= s2;j++)
            for(int k = 1;k <= s3;k++)
                a[i+j+k]++;
    int ans = 0,cnt = 0;
    for(int i = 1;i <= s1+s2+s3;i++) 
        if(a[i] > cnt) {
            ans = i;
            cnt = a[i];
        }
    cout << ans;
    return 0;
}