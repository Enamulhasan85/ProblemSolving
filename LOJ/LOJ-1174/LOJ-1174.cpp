#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using ll = long long;
using namespace std;

vector<ll> parent;
vector<vector<ll>> edge;


void solve(ll cs){
    ll n, m, a=0, x, y, k, b=0, j, i, c, q, mn = 1e12, mx, mod = 998244353;

    cin >> n >> m;

    vector<vector<ll>> v(n, vector<ll> (n, 1e5));

    while(m--){
        cin >> a >> b;
        v[a][b] = v[b][a] = 1;
    }

    ll s, d;
    cin >> s >> d;

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j) v[i][j] = 0;
                else v[i][j] = min(v[i][j], v[i][k]+v[k][j]);
            }
        }
    }

    ll ans = 0;
    for(i=0;i<n;i++){
        ans = max(ans, v[s][i]+v[i][d]);
    }

    cout << "Case " << cs << ": " << ans << endl;

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
    while(t--){
        solve(cs++);
    }
}
