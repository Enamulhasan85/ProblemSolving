#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using namespace std;
using ll = long long;

ll mod = 1000000007;

ll dp[(1LL<<15)+1][16];
vector<vector<ll>> vps, vcomps;
vector<string> vs;

ll pref(string s1, string s2){
    string s = s1+"#"+s2;
    vector<ll> pi(s.size(), 0);
    for(ll i=1,j=0;i<s.size();i++){
        while(j>0 && s[i]!=s[j]) j = pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i] = j;
    }
    return pi.back();
}

ll DP(ll last, ll mask){
    if(mask==(1LL<<vs.size())-1) return vs[last].size();
    if(dp[mask][last+1]!=-1) return dp[mask][last+1];

    ll ind = -1, res = 1e9;
    for(ll i=0;i<vs.size();i++){
        if(mask&(1LL<<i)) continue;
        ll tmp = DP(i, mask|(1LL<<i));
        if(last != -1) tmp += vs[last].size() - vps[last][i];
        if(res>tmp) {
            res = tmp;
            ind = i;
        }
        else if(res==tmp and last!=-1 and vcomps[last][ind]>vcomps[last][i]){
            res = tmp;
            ind = i;
        }
    }
    //cout << ind << " ";
    ll ans = res;

    return dp[mask][last+1] = ans;
}

void WalkDP(ll last, ll mask){
    if(mask==(1LL<<vs.size())-1) return ;

    ll ind = -1, res = 1e9;
    for(ll i=0;i<vs.size();i++){
        if(mask&(1LL<<i)) continue;
        ll tmp = DP(i, mask|(1LL<<i));
        if(last != -1) tmp += vs[last].size() - vps[last][i];
        if(res>tmp) {
            res = tmp;
            ind = i;
        }
        else if(res==tmp and last!=-1 and vcomps[last][ind]>vcomps[last][i]){
            res = tmp;
            ind = i;
        }
    }

    ll i = 0;
    if(last!=-1) i += vps[last][ind];
    for(;i<vs[ind].size();i++) cout << vs[ind][i];

    WalkDP(ind, mask|(1LL<<ind));

    return;
}

void solve(ll cs)
{
    ll n, m, i, a, b, c, d, j, k, ans=0, mn = 1e15, mx, cnt, q;

    string s, s1, s2;

    cin >> n;

    //vector<ll> v(n);
    vs = vector<string>(n);

    for(auto &x : vs) cin >> x;

    vector<string> v;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j and vs[j]!=vs[i] and vs[j].find(vs[i])!=string::npos) break;
        }
        if(j<n) continue;
        v.pb(vs[i]);
    }

    vs = v;
    sort(vs.begin(), vs.end());

    //for(auto x : vs) cout << x << " ";
    n = vs.size();

    vps = vector<vector<ll>> (n, vector<ll> (n, 0));
    vcomps = vector<vector<ll>> (n, vector<ll> (n, 0));
    for(i=0;i<n;i++){
        vector<pair<string, ll>> vsort;
        for(j=0;j<n;j++){
            if(i==j) continue;
            vps[i][j] = pref(vs[j], vs[i]);
            string ss = vs[i];
            for(k=vps[i][j];k<vs[j].size();k++) ss += vs[j][k];
            vsort.pb({ss, j});
            //cout << vps[i][j] << " ";
        }
        sort(vsort.begin(), vsort.end());
        for(j=0;j<vsort.size();j++) vcomps[i][vsort[j].se] = j;
        //for(auto x : vcomps[i]) cout << x << " ";
        //cout << endl;
    }

    memset(dp, -1, sizeof(dp));
    ll st = DP(-1, 0);

    cout << "Case " << cs << ": ";
    //cout << st;

    WalkDP(-1, 0);

    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll t=1, cs=0;
    cin >> t;
    while(t--){
        solve(++cs);
    }
    return 0;
}

