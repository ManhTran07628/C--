    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define fi first
    #define se second
    #define oo (ll) 1e18
    const int MM = 1e6 + 3;
    const int MOD = 998244353;
    int add(int a,int b)
    {
        return (a % MOD + b % MOD) % MOD;
    }
    int dp[MM],sumdiv[MM],Next[MM],s;
    string n;
    void min_prime()
    {
        for(int i = 1;i < MM;i++)
            for(int j = i;j < MM;j += i)
                sumdiv[j] += i;
    }
 
    signed main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        #define taskname "sumdiv"
        if(fopen(taskname ".inp","r")) {
            freopen(taskname ".inp","r",stdin);
            freopen(taskname ".out","w",stdout);
        }
        min_prime();
        cin >> s >> n;
        int sz = n.size();
        n = ' ' + n;


        Next[sz] = sz + 1;
        for(int i = sz - 1;i >= 0;i--) {
            if(n[i + 1] != '0') Next[i] = i + 1;
            else Next[i] = Next[i + 1];
        }

        dp[0] = 1;
        for(int i = 0;i < sz;i++) {
            for(int j = Next[i];j <= min(Next[i] + 5,sz);j++) {

                int nums = 0;
                for(int k = Next[i];k <= j;k++)
                    nums = nums * 10 + (n[k] - '0');

                if(0 < nums && nums < MM && sumdiv[nums] <= s) dp[j] = add(dp[i],dp[j]);

            }
        }
        cout << dp[sz];
        return 0;
    }