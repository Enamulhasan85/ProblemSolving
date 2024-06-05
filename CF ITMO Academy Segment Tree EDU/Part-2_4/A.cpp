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
        type.resize(4*sz, 0);
        lazy.resize(4*sz, -1);
    }

    ll n;
    vector<ll> tree;
    vector<ll> type;
    vector<ll> lazy;

    void push(ll i, ll l, ll r){
        if(lazy[i]==-1) return;
        if(l!=r){
            if(lazy[i*2]!=-1){
                if(type[i]==1){
                    lazy[i*2] = lazy[i];
                    type[i*2] = type[i];
                }
                else{
                    lazy[i*2] += lazy[i];
                }
            }
            else{
                lazy[i*2] = lazy[i];
                type[i*2] = type[i];
            }

            if(lazy[i*2+1]!=-1){
                if(type[i]==1){
                    lazy[i*2+1] = lazy[i];
                    type[i*2+1] = type[i];
                }
                else{
                    lazy[i*2+1] += lazy[i];
                }
            }
            else{
                lazy[i*2+1] = lazy[i];
                type[i*2+1] = type[i];
            }
            //lazy[i*2] += lazy[i];
            //lazy[i*2] %= mod;
            //lazy[i*2+1] += lazy[i];
            //lazy[i*2+1] %= mod;
        }

        if(type[i]==1){
            tree[i] = (r-l+1)*lazy[i];
        }
        else tree[i] += (r-l+1)*lazy[i];
        //tree[i] %= mod;
        lazy[i] = -1;
    }

    ll combine(ll a, ll b){
        return a+b;
    }

    void combineind(ll i, ll i1, ll i2){
        return ;
    }

    void build(ll i, ll l, ll r, vector<ll> &v){
        if(l==r) {
            lazy[i] = v[l];
            push(i, l, r);
            return;
        }
        ll mid = (l+r)/2;
        build(i*2, l, mid, v);
        build(i*2+1, mid+1, r, v);

        tree[i] = combine(tree[i*2], tree[i*2+1]);
        //combineind(i, l, mid+1, i<<1, i<<1|1);
    }
    void Build(vector<ll> &v){
        build(1, 0, n-1, v);
    }

    void update(ll i, ll l, ll r, ll b, ll e, ll val, ll t){
        push(i, l, r);
        if(b<=l and r<=e) {
            lazy[i] = val;
            type[i] = t;
            push(i, l, r);
            return;
        }
        if(e<l or r<b) return;
        ll mid = (l+r)/2;
        update(i*2, l, mid, b, e, val, t);
        update(i*2+1, mid+1, r, b, e, val, t);
        tree[i] = combine(tree[i*2], tree[i*2+1]);
        //combineind(i, i*2, i*2+1);
    }
    void Update(ll i, ll j, ll val, ll t){
        update(1, 0, n-1, i, j, val, t);
    }

    ll query(ll i, ll l, ll r, ll b, ll e, ll val){
        push(i, l, r);
        if(b<=l and r<=e) {
            return tree[i];
        }
        if(e<l or r<b) return 0;

        ll mid = (l+r)/2;
        return combine(query(i*2, l, mid, b, e, val), query(i*2+1, mid+1, r, b, e, val));
    }
    ll Query(ll i, ll j, ll val){
        return query(1, 0, n-1, i, j, val);
    }
};

void solve(ll cs){
    ll j, i, p, q, a, b, c, m, n, k, g, mn = 0, sum, mx = 0;

    string s;

    cin >> n >> q;

    //vector<ll> v(n);
    //for(auto &x : v) cin >> x;

    segtree st = segtree(n);

    //st.Build(v);
    //cin >> q;

    while(q--){
        cin >> k;

        if(k==1) {
            cin >> a >> b >> p;

            st.Update(a, b-1, p, 1);
        }
        else if(k==2){
            cin >> a >> b >> p;

            st.Update(a, b-1, p, 2);
        }
        else{
            cin >> a >> b;
            cout << st.Query(a, b-1, 0) << endl;
        }
    }

    //cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //seive(1e6+2);
    //For getting input from input.txt file
    //freopen("output3.txt", "r", stdin);

    //Printing the Output to output.txt file
    //freopen("output6.txt", "w", stdout);

    ll t=1, cs=1;
    //cin >> t;
    while(t--){
        //string str;
        //getline(cin, str);
        solve(cs++);
    }
}

