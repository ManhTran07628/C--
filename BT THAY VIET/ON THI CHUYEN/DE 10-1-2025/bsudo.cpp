#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[100][100];
int b[101];
vector<int> c,h,f;
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
    for(int i = 1;i <= 9;i++) {
        bool kt = 1;
        for(int j = 1;j <= 9;j++) {
            cin >> a[i][j];
            if(b[a[i][j]] == 0) b[a[i][j]]++;
            else kt = 0;
        }
        if(kt) c.push_back(i);
        for(int j = 1;j <= 9;j++) b[j] = 0;
    }
    for(int j = 1;j <= 9;j++) {
        bool kt = 1;
        for(int i = 1;i <= 9;i++) {
            if(b[a[i][j]] == 0) b[a[i][j]]++;
            else kt = 0;
        }
        if(kt) h.push_back(j);
        for(int i = 1;i <= 9;i++) b[i] = 0;
    }
    for(auto i:c) b[i]++;
    for(int i = 1;i <= 9;i++) {
        if(b[i] == 0) f.push_back(i);
        b[i] = 0;
    }
    for(auto i:h) b[i]++;
    for(int i = 1;i <= 9;i++) {
        if(b[i] == 0) f.push_back(i);
        b[i] = 0;
    }
    h.clear();
    c.clear();
    int x = f[0],y = f[1];
    int val = a[x][y];
    for(int k = 1;k <= 9;k++) {
        if(k == val) continue;
        a[x][y] = k;
        for(int i = 1;i <= 9;i++) {
            bool kt = 1;
            for(int j = 1;j <= 9;j++) {
                cin >> a[i][j];
                if(b[a[i][j]] == 0) b[a[i][j]]++;
                else kt = 0;
            }
            if(kt) c.push_back(i);
            for(int j = 1;j <= 9;j++) b[j] = 0;
        }
        for(int j = 1;j <= 9;j++) {
            bool kt = 1;
            for(int i = 1;i <= 9;i++) {
                if(b[a[i][j]] == 0) b[a[i][j]]++;
                else kt = 0;
            }
            if(kt) h.push_back(j);
            for(int i = 1;i <= 9;i++) b[i] = 0;
        }
        bool kt = 1;
        for(auto i:c) b[i]++;
        for(auto i:h) b[i]++;
        for(int i = 1;i <= 9;i++) {
            if(b[i] != 2) {
                kt = 0;
                break;
            }
        }
        if(kt) {
            cout << k;
            return 0;
        }
        for(int i = 1;i <= 9;i++) b[i] = 0;
        h.clear();
        c.clear();
    }
    return 0;
}