#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define mod 1e9+7

using namespace std;
vector<ll> v, seg;

void init(ll node, ll l, ll r){
    if(l==r){
        seg[node] = v[l];
        return;
    }
    ll mid = (l+r)/2;
    init(2*node, l, mid);
    init(2*node+1, mid+1, r);
    seg[node] = min(seg[2*node],seg[2*node+1]);
}

ll query(ll node, ll l, ll r, ll a, ll b){
    if(b<l or r<a) return 1e9;
    if(l>=a and r<=b) return seg[node];
    ll mid = (l+r)/2;
    ll left = query(2*node, l, mid, a, b);
    ll right = query(2*node+1, mid+1, r, a, b);
    return min(left,right);
}

void solve(ll cs){
    ll n, m, i, z, q, h, w, e, k=1, j, a=1e10, b=1e10, ans=1e18, mn=1e12;
    cin >> n >> q;
    v = vector<ll>(n);
    seg = vector<ll>(3*n);
    for(auto &x : v) cin >> x;
    init(1,0,n-1);
    cout << "Case " << cs << ": " << endl;
    while(q--){
        cin >> a >> b;
        ans = query(1, 0, n-1, a-1, b-1);
        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //seive(1e6+2);
    ll t=1, cs=1;
    cin >> t;
    string s;
    while(t--){
        getline(cin, s);
        solve(cs++);
    }
}
