#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int cnt_x[MM],cnt_y[MM];

bool isvalid(int i,int a,int b)
{
    if(i == 1) return (1 <= a && a <= 9 && 0 <= b && b <= 9);
    return (0 <= a && a <= 9 && 0 <= b && b <= 9);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "digits"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string x,y; cin >> x >> y;
    int x_size = x.size(), y_size = y.size();
    x = ' ' + x;
    y = ' ' + y;

    for(int i = 1;i <= x_size;i++)
        cnt_x[ x[i] - '0' ]++;

    for(int i = 1;i <= y_size;i++)
        cnt_y[ y[i] - '0' ]++;

    bool flag = 1;
    for(int d = 0;d <= 9;d++) 
        if((cnt_x[d] == 0 && cnt_y[d] == 0) ||
            (cnt_x[d] > 0 && cnt_y[d] > 0)) continue;
        else {flag = 0;break;}
    if(flag) {
        cout << "friends";
        return 0;
    }

    for(int i = 1;i < x_size;i++) {
        int a = x[i] - '0', b = x[i+1] - '0';
        
        if(isvalid(i,a - 1,b + 1)) {
            bool ok = 1;
            int n_a = a - 1, n_b = b + 1;
            cnt_x[a]--; cnt_x[b]--;
            cnt_x[n_a]++; cnt_x[n_b]++;
            
            for(int d = 0;d <= 9;d++) 
                if((cnt_x[d] == 0 && cnt_y[d] == 0) ||
                    (cnt_x[d] > 0 && cnt_y[d] > 0)) continue;
                else {
                    ok = 0;
                    break;
                }


            cnt_x[n_a]--; cnt_x[n_b]--;
            cnt_x[a]++; cnt_x[b]++;

            if(ok) {cout << "almost friends";return 0;}
        }

        if(isvalid(i,a + 1,b - 1)) {
            bool ok = 1;
            int n_a = a + 1, n_b = b - 1;
            cnt_x[a]--; cnt_x[b]--;
            cnt_x[n_a]++; cnt_x[n_b]++;
            
            for(int d = 0;d <= 9;d++) 
                if((cnt_x[d] == 0 && cnt_y[d] == 0) ||
                    (cnt_x[d] > 0 && cnt_y[d] > 0)) continue;
                else {
                    ok = 0;
                    break;
                }
    
            cnt_x[n_a]--; cnt_x[n_b]--;
            cnt_x[a]++; cnt_x[b]++;

            if(ok) {cout << "almost friends";return 0;}
        }

    }

    for(int i = 1;i < y_size;i++) {
        int a = y[i] - '0', b = y[i+1] - '0';
        
        if(isvalid(i,a - 1,b + 1)) {
            bool ok = 1;
            int n_a = a - 1, n_b = b + 1;
            cnt_y[a]--; cnt_y[b]--;
            cnt_y[n_a]++; cnt_y[n_b]++;
            
            for(int d = 0;d <= 9;d++) 
                if((cnt_x[d] == 0 && cnt_y[d] == 0) ||
                    (cnt_x[d] > 0 && cnt_y[d] > 0)) continue;
                else {
                    ok = 0;
                    break;
                }


            cnt_y[n_a]--; cnt_y[n_b]--;
            cnt_y[a]++; cnt_y[b]++;

            if(ok) {cout << "almost friends";return 0;}
        }

        if(isvalid(i,a + 1,b - 1)) {
            bool ok = 1;
            int n_a = a + 1, n_b = b - 1;
            cnt_y[a]--; cnt_y[b]--;
            cnt_y[n_a]++; cnt_y[n_b]++;
            
            for(int d = 0;d <= 9;d++) 
                if((cnt_x[d] == 0 && cnt_y[d] == 0) ||
                    (cnt_x[d] > 0 && cnt_y[d] > 0)) continue;
                else {
                    ok = 0;
                    break;
                }
    
            cnt_y[n_a]--; cnt_y[n_b]--;
            cnt_y[a]++; cnt_y[b]++;

            if(ok) {cout << "almost friends";return 0;}
        }

    }

    cout << "nothing";
    return 0;
}