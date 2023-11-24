#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using namespace std;
using ll = long long;

vector<pair<ll, ll>> v[200005], path;
vector<bool> vis;
vector<ll> dis;
ll ans = 0, root = 0;

void bfs(ll i, ll n){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pair<ll, ll> pii = {0, i};
    dis[pii.se] = 0;
    pq.push(pii);
    path.pb({pii.se, pii.se});
    while(!pq.empty()){
        pii = pq.top();
        pq.pop();

        for(auto x : v[pii.se]){
            if(dis[x.se]>max(x.fi, pii.fi)){
                path.pb({x.se, pii.se});
                dis[x.se]=max(x.fi, pii.fi);
                pq.push({dis[x.se], x.se});
            }
        }
    }

    path.clear();
}


void solve(ll cs){
    ll n, m, a=0, x, y, k, w, b=0, j, i, c, q, mn = 1e12, mx, mod = 998244353;

    cin >> n >> m;

    for(i=0;i<n;i++) v[i].clear();
    while(m--){
        cin >> i >> j >> w;
        v[i].pb({w, j});
        v[j].pb({w, i});
    }

    ll t;
    cin >> t;

    vis = vector<bool> (n+1, 0);
    dis = vector<ll> (n+1, 1e9);
    dis[t] = 0;

    bfs(t, n);

    cout << "Case " << cs << ": " << endl;
    for(i=0;i<n;i++){
        if(dis[i]==1e9) cout << "Impossible" << endl;
        else  cout << dis[i] << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //seive(1e6+2);
    //For getting input from input.txt file
    //freopen("watering_well_chapter_2_validation_input.txt", "r", stdin);

    //Printing the Output to output.txt file
    //freopen("output.txt", "w", stdout);

    ll t=1, cs=1;
    cin >> t;
    string str;
    while(t--){
        getline(cin, str);
        solve(cs++);
    }
}
