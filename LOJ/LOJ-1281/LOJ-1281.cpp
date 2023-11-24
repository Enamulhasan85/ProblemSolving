#include<bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'

using ll = long long;
using namespace std;

ll mod = 1e9+7;

struct edge{
    ll cost;
    ll ro;
    ll ty;
    edge(ll ro, ll cost, ll ty){
        this->cost = cost;
        this->ro = ro;
        this->ty = ty;
    }
};

struct node{
    ll dis;
    ll cn;
    ll dd;
    node(ll dis, ll cn, ll dd){
        this->dis = dis;
        this->cn = cn;
        this->dd = dd;
    }
};

vector<edge> v[60005];
ll dis[10005][12];

ll djk(ll i, ll d, ll n){
    queue<node> pq;
    node cur = node(0, 0, 0);
    pq.push(cur);

    while(!pq.empty()){
        node pi = pq.front();
        pq.pop();

        for(auto x : v[pi.cn]){
            if(x.ty + pi.dd <= d){
                node cur = node(0, 0, 0);
                cur.dd = x.ty + pi.dd;
                if(dis[x.ro][cur.dd] > pi.dis + x.cost){
                    cur.cn = x.ro;
                    cur.dis = pi.dis + x.cost;
                    dis[x.ro][cur.dd]  = cur.dis;
                    pq.push(cur);
                }
            }
        }
    }

    ll ans = 1e12;
    for(i=0;i<=d;i++){
        ans = min(ans, dis[n][i]);
    }
    return ans;

}

void solve(ll cs){
    ll n, m=0, j, q, k=0, i=0, t, x=0, y, a, b, d, c, ans = 0;

    cin >> n >> q >> k >> d;

    for(i=0;i<n;i++){
        v[i].clear();
        for(j=0;j<=d;j++) dis[i][j] = 1e12;
    }

    while(q--){
        cin >> a >> b >> c;
        edge nd = edge(b, c, 0);
        v[a].push_back(nd);
    }

    while(k--){
        cin >> a >> b >> c;
        edge nd = edge(b, c, 1);
        v[a].push_back(nd);
    }

    ans = djk(0, d, n-1);

    if(ans==1e12)  cout << "Case " << cs << ": Impossible" << endl;
    else   cout << "Case " << cs << ": " << ans << endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll t = 1, cs = 0;
    cin >> t;
    while(t--){
        solve(++cs);
    }
}
