#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int m[101],p[101];
set<int> lt1[101],lt2[101];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> m[i];
        for(int j = 1;j <= m[i];j++) {
            int x;
            cin >> x;
            lt1[i].insert(x);
            lt2[i].insert(x);
        }
    }

    for(int k = 1;k <= n;k++) {
        for(int i:lt1[k]) {
            int cnt = 0;
            for(int j = 1;j <= n;j++) {
                if(lt2[j].find(i) != lt2[j].end()) lt2[j].erase(i);
                if(lt2[j].empty()) cnt++;
            }
            if(cnt > 1) break;
            if(cnt == 1) {
                for(int j = 1;j <= n;j++) {
                    if(lt2[j].empty()) p[j] = 1;
                }
                break;
            }
        }
        for(int j = 1;j <= n;j++) lt2[j] = lt1[j];
    }
    for(int i = 1;i <= n;i++) cout << (p[i] ? "YES" : "NO") << '\n';
    return 0;
}