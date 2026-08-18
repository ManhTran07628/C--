#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
ll L,R,K;
ll dp[19][2][2][10][4][20];

// dp[id][lead][tight][last_num][last_opt][seg_cnt]

// last_opt : 
// 0 -> = 
// 1 -> +
// 2 -> -

int cmp_operator(int a,int b)
{
    if(a == b) return 0;
    if(a < b) return 1;
    return 2;
}

ll f(int id,int lead,int tight,int last_num,int last_opt,int seg_cnt,const string &s,string cur_num)
{
    if(id == s.size()) {
        return seg_cnt + 1 <= K;
    }
    ll memo = dp[id][lead][tight][last_num][last_opt][seg_cnt];
    if(memo != -1) return memo;
    memo = 0;
    int lim = (tight ? s[id] - '0' : 9);
    for(int i = 0;i <= lim;i++) {
        int new_lead = (lead && i == 0);
        int new_tight = (tight && i == lim);

        if(i == 0) {
            if(new_lead) memo += f(id+1,new_lead,new_tight,0,3,0,s,cur_num + char(i + '0'));
            else {
                int new_last_num = i;
                if(lead && !new_lead) last_num = i;
                int nxt_opt = cmp_operator(last_num,new_last_num);

                if(nxt_opt == 0) nxt_opt = last_opt;

                if(last_opt == 3) {
                    memo += f(id+1,new_lead,new_tight,new_last_num,nxt_opt,seg_cnt,s,cur_num + char(i + '0'));
                    continue;
                }

                if(last_opt != nxt_opt && last_opt != 0 && nxt_opt != 0)
                    memo += f(id+1,new_lead,new_tight,new_last_num,nxt_opt,seg_cnt + 1,s,cur_num + char(i + '0'));
                else memo += f(id+1,new_lead,new_tight,new_last_num,nxt_opt,seg_cnt,s,cur_num + char(i + '0'));
            }
        }
        else {
            int new_last_num = i;
            if(lead && !new_lead) last_num = i;
            int nxt_opt = cmp_operator(last_num,new_last_num);

            if(nxt_opt == 0) nxt_opt = last_opt;

            if(last_opt == 3) {
                memo += f(id+1,new_lead,new_tight,new_last_num,nxt_opt,seg_cnt,s,cur_num + char(i + '0'));
                continue;
            }

            if(last_opt != nxt_opt && last_opt != 0 && nxt_opt != 0)
                 memo += f(id+1,new_lead,new_tight,new_last_num,nxt_opt,seg_cnt + 1,s,cur_num + char(i + '0'));
            else memo += f(id+1,new_lead,new_tight,new_last_num,nxt_opt,seg_cnt,s,cur_num + char(i + '0'));
        }
    }

    dp[id][lead][tight][last_num][last_opt][seg_cnt] = memo;

    return memo;
}

ll solve(string a)
{
    memset(dp,-1,sizeof(dp));
    return f(0,1,1,0,3,0,a,"");
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> L >> R >> K;
    cout << solve(to_string(R)) - solve(to_string(L - 1));
    return 0;
}