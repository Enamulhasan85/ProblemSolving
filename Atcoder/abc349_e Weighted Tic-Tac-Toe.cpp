#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using namespace std;
using ll = long long;

ll mod = 1000000007;

ll dp[1<<9][1<<9], ans = 0;
vector<vector<ll>> v;

bool iswon(ll m1){
    ll i, j;
    for(i=0;i<3;i++) {
        if(m1&(1<<(3*i)) and m1&(1<<(3*i+1)) and m1&(1<<(3*i+2))) return 1;
    }

    for(i=0;i<3;i++) {
        if(m1&(1<<(i)) and m1&(1<<(i+3)) and m1&(1<<(i+6))) return 1;
    }

    if(m1&(1<<(0)) and m1&(1<<(4)) and m1&(1<<(8))) return 1;
    if(m1&(1<<(2)) and m1&(1<<(4)) and m1&(1<<(6))) return 1;

    return 0;
}

ll check(ll m1, ll m2){
    ll res = -1;
    if(iswon(m1)) res = 1;
    if(iswon(m2)) res = 0;

    return res;
}

ll DP(ll mask1, ll mask2, ll sc1, ll sc2, ll turn){
    ll res = check(mask1, mask2);
    //cout << res;
    if(res!=-1) return res;
    if((mask1|mask2) == ((1<<9)-1)) return (sc1>sc2) ? 1 : 0;
    if(dp[mask1][mask2]!=-1) return dp[mask1][mask2];

    ll ans = -1, cnt1 = 0, cnt2 = 0;
    for(ll i=0;i<9;i++){
        if((mask1&(1<<i)) or (mask2&(1<<i))) continue;

        if(turn==0){
            ll tmp = DP(mask1|(1<<i), mask2, sc1+v[i/3][i%3], sc2, 1);
            if(tmp==1) cnt1++;
            else cnt2++;
        }
        else{
            ll tmp = DP(mask1, mask2|(1<<i), sc1, sc2+v[i/3][i%3], 0);
            if(tmp==1) cnt1++;
            else cnt2++;
        }
    }

    ans = turn;
    if(turn==0 and cnt1>0) ans = 1;
    if(turn==1 and cnt2>0) ans = 0;

    return dp[mask1][mask2] = ans;
}

void solve(ll cs)
{
    ll n, m, i, a, b, c, d, j, k, mn = 1e15, mx, cnt, q;

    string s, s1, s2;

    v = vector<vector<ll>> (3, vector<ll> (3));
    for(auto &x : v) for(auto &xx : x) cin >> xx;

    memset(dp, -1, sizeof(dp));
    //ans = 0;
    ll pi = DP(0, 0, 0, 0, 0);

    //cout << "Case " << cs << ": ";
    if(pi==1) cout << "Takahashi";
    else cout << "Aoki";

    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll t=1, cs=0;
    //cin >> t;
    while(t--){
        solve(++cs);
    }
    return 0;
}

