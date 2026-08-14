#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int S,A,B,H,M;
struct dl{int time;string type;int per;};
vector<dl> sch;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> S >> A >> B >> H >> M;
    int cur_clock = H * 60 + M;

    int cur_time = 8 * 60;

    if(cur_clock == cur_time) {
        cout << A;
        return 0;
    }
    

    sch.push_back({cur_time,"STUDY",1}); // bat dau tiet
    for(int i = 1;i <= 12;i++) {
        cur_time += S;
        sch.push_back({cur_time,"BREAK",i}); // bat dau buoi ra choi
        if(i == 3 || i == 9) cur_time += B;
        else cur_time += A;
        sch.push_back({cur_time,"STUDY",i+1});
    }

    // for(auto i:sch) cout << i.time << ' ' << i.type << ' ' << i.per << '\n';

    int id = 0;
    for(int i = 0;i < sch.size();i++) {
        if(sch[i].time >= cur_clock) {

            if(sch[i].type == "STUDY") { // dang ra choi
                int timeleft = sch[i].time - cur_clock;

                if(timeleft >= A) { // co the mua luon
                    cout << "NOW";
                    return 0;
                }
                else {
                    cout << timeleft + S;
                    return 0;
                }

            }
            else if(sch[i].type == "BREAK") { // dang trong tiet hoc
                if(sch[i].time - cur_clock == 0) cout << "NOW";
                else cout << sch[i].time - cur_clock;
                return 0;
            }

        }
    }
    return 0;
}