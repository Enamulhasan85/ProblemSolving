#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using ll = long long;
using namespace std;

ll mod = 998244353;
ll t[100006][18];

void build(vector<ll>& v){
    ll n = v.size();
    for(ll i=0;i<n;i++) t[i][0] = v[i];
    for(ll k=1;k<18;k++){
        for(ll i=0;i+(1<<k)-1<n;i++){
            t[i][k] = min(t[i][k-1], t[i+(1<<k-1)][k-1]);
        }
    }
}

ll query(ll l, ll r){
    ll sz = 31 - __builtin_clz(r-l+1);
    return min(t[l][sz], t[r-(1<<sz)+1][sz]);
}

void solve(ll cs){
    ll a=0, x, y, k, b=0, j, i, c, q, n, m, d, mn = 0, mx;

    cin >> n;
    vector<ll> v(n);

    for(auto &x : v) cin >> x;

    build(v);

    cin >> q;

    while(q--){
        cin >> a >> b;

        cout << query(a, b) << endl;

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
    //cin >> t;
    while(t--){
        solve(cs++);
    }
}

