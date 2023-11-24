#include<bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'

using ll = long long;
using namespace std;

ll mod = 1e9+7;
vector<pair<ll, ll>> v[60005];
map<ll, ll> dis, disr;

ll djk(ll i, ll n){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dis[i] = 0;
    pq.push({dis[i], i});

    pair<ll, ll> pi;
    while(!pq.empty()){
        pi = pq.top();
        pq.pop();

        for(auto x : v[pi.second]){
            if(dis[x.first]>dis[pi.second]+x.second){
                dis[x.first] = dis[pi.second]+x.second;
                pq.push({dis[x.first], x.first});
            }
        }
    }

}

void solve(ll cs){
    ll n, m=0, j, q, k=0, i=0, t, x=0, y, a, b, c, ans = 0;

    cin >> n >> q;

    for(auto &x : v) x.clear();

    for(i=0;i<=n;i++) dis[i] = 1e12;
    while(q--){
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    djk(1, n);
    for(auto x : dis) disr[x.first] = x.second;
    for(i=0;i<=n;i++) dis[i] = 1e12;
    djk(n, n);

    ans = 1e9;
    for(i=1;i<=n;i++){
        for(auto x : v[i]){
            ll tmp = x.second + dis[x.first] + disr[i];
            if(tmp>disr[n]){
                ans = min(ans, tmp);
            }
        }
    }


    cout << "Case " << cs << ": " << ans << endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll t = 1, cs = 0;
    cin >> t;
    while(t--){
        solve(++cs);
    }
}
