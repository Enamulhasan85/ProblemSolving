#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using namespace std;
using ll = long long;

ll mod = 1e9+7;

struct segtree{
    segtree(ll sz){
        n = sz;
        tree.resize(4*sz, 0);
        mn.resize(4*sz, 0);
        mx.resize(4*sz, 0);
        lazy.resize(4*sz, {-1, -1});
    }

    ll n;
    vector<ll> tree;
    vector<ll> mn;
    vector<ll> mx;
    vector<pair<ll, ll>> lazy;

    void push(ll i, ll l, ll r){
        if(lazy[i].fi==-1) return;
        if(l!=r){
            if(lazy[i*2].fi==-1) {
                lazy[i*2] = lazy[i];
            }
            else if(lazy[i*2].se<=lazy[i].fi){
                lazy[i*2] = {lazy[i].fi, lazy[i].fi};
            }
            else if(lazy[i].se<=lazy[i*2].fi){
                lazy[i*2] = {lazy[i].se, lazy[i].se};
            }
            else{
                lazy[i*2].fi = max(lazy[i].fi, lazy[i*2].fi);
                lazy[i*2].se = min(lazy[i].se, lazy[i*2].se);
            }

            if(lazy[i*2+1].fi==-1) {
                lazy[i*2+1] = lazy[i];
            }
            else if(lazy[i*2+1].se<=lazy[i].fi){
                lazy[i*2+1] = {lazy[i].fi, lazy[i].fi};
            }
            else if(lazy[i].se<=lazy[i*2+1].fi){
                lazy[i*2+1] = {lazy[i].se, lazy[i].se};
            }
            else{
                lazy[i*2+1].fi = max(lazy[i].fi, lazy[i*2+1].fi);
                lazy[i*2+1].se = min(lazy[i].se, lazy[i*2+1].se);
            }
        }

        if(mx[i]<=lazy[i].fi){
            mn[i] = mx[i] = lazy[i].fi;
        }
        else if(lazy[i].se<=mn[i]){
            mn[i] = mx[i] = lazy[i].se;
        }
        else if(l!=r){
            mn[i] = max(mn[i], lazy[i].fi);
            mx[i] = min(mx[i], lazy[i].se);
        }

        lazy[i] = {-1, -1};
    }

    ll combine(ll a, ll b){
        return 0 ;
    }

    void combineind(ll i, ll l, ll r){
        return ;
    }

    void build(ll i, ll l, ll r, vector<ll> &v){
        if(l==r) {
            return;
        }
        ll mid = (l+r)/2;
        build(i*2, l, mid, v);
        build(i*2+1, mid+1, r, v);

        //tree[i] = combine(tree[i*2], tree[i*2+1]);
        //combineind(i, i<<1, (i<<1)|1, l, r);
    }
    void Build(vector<ll> &v){
        build(1, 0, n-1, v);
    }

    void update(ll i, ll l, ll r, ll b, ll e, ll val, ll t){
        push(i, l, r);
        if(b<=l and r<=e) {
            //lazy[i] = val;
            if(t==1) lazy[i] = {val, 1e15};
            else lazy[i] = {0, val};
            push(i, l, r);
            return;
        }
        if(e<l or r<b) return;
        ll mid = (l+r)/2;
        update(i*2, l, mid, b, e, val, t);
        update(i*2+1, mid+1, r, b, e, val, t);

        mn[i] = min(mn[i*2], mn[i*2+1]);
        mx[i] = max(mx[i*2], mx[i*2+1]);
        //tree[i] = combine(tree[i*2], tree[i*2+1]);
        //combineind(i, i*2, i*2+1);
    }
    void Update(ll i, ll j, ll val, ll t){
        update(1, 0, n-1, i, j, val, t);
    }

    ll query(ll i, ll l, ll r, ll b, ll e){
        push(i, l, r);
        if(b<=l and r<=e) {
            return mn[i];
        }
        if(e<l or r<b) return -1;

        ll mid = (l+r)/2;
        auto pi1 = query(i*2, l, mid, b, e);
        auto pi2 = query(i*2+1, mid+1, r, b, e);
        if(pi1==-1) return pi2;
        else return pi1;
    }
    ll Query(ll i, ll j){
        return query(1, 0, n-1, i, j);
    }
};

void solve(ll cs){
    ll j, i, p, q, a, b, c, d, m, n, k, g, mn = 0, sum, mx = 0;

    cin >> n >> q;
    segtree st = segtree(n);
    //st.Build(v);
    //cin >> q;
    while(q--){
        cin >> k >> a >> b >> p;
        st.Update(a, b, p, k);
    }

    for(i=0;i<n;i++){
        cout << st.Query(i, i) << endl;
    }
    //cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll t=1, cs=1;
    //cin >> t;
    while(t--){
        solve(cs++);
    }
}
