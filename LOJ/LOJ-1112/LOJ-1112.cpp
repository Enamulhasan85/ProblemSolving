#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define mod 1e9+7

using namespace std;

vector<ll> v, seg;
vector<ll> le, ri;

void init(ll node, ll l, ll r){
    if(l==r){
        seg[node] = v[l];
        return;
    }
    ll mid = (l+r)/2;
    init(2*node, l, mid);
    init(2*node+1, mid+1, r);
    seg[node] = seg[2*node] + seg[2*node+1];
}

ll query(ll node, ll l, ll r, ll a, ll b){
    if(l>=a and r<=b) return seg[node];
    if(b<l or r<a) return 0;
    ll mid = (l+r)/2;
    ll left = query(2*node, l, mid, a, b);
    ll right = query(2*node+1, mid+1, r, a, b);
    return left+right;
}

void update(ll node, ll l, ll r, ll p, ll k){
    if(l==r and l==p){
        seg[node] = k;
        return;
    }
    if(p<l or r<p) return;
    ll mid = (l+r)/2;
    update(2*node, l, mid, p, k);
    update(2*node+1, mid+1, r, p, k);
    seg[node] = seg[2*node]+seg[2*node+1];
}

void solve(ll cs){
    ll n, m, i, z, q, h, w, e, k=1, j, a=1e10, b=1e10, ans=1e18, mn=1e12;
    cin >> n >> q;
    v = vector<ll>(n);
    seg = vector<ll>(4*n);

    for(auto &x : v) cin >> x;

    init(1, 0, n-1);
    cout << "Case " << cs << ": " << endl;
    while(q--){
        cin >> z;
        if(z==1){
            cin >> i;
            cout << v[i] << endl;
            v[i] = 0;
            update(1, 0, n-1, i, v[i]);
        }
        else if(z==2){
            cin >> i >> k;
            v[i] += k;
            update(1, 0, n-1, i, v[i]);
        }
        else{
            cin >> i >> j;
            ll ans = query(1, 0, n-1, i, j);
            cout << ans << endl;
        }
    }

    v.clear();
    seg.clear();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //seive(1e6+2);
    ll t=1, cs=1;
    cin >> t;
    string s;
    while(t--){
        //getline(cin, s);
        solve(cs++);
    }
}
