#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl '\n'

using ll = long long;
using namespace std;

ll mod = 100000007;

void solve(ll cs){
    ll j, i, n, k, p, q;

    cin >> n >> k;
    
    vector<ll> val(n), cnt(n);
    
    for(auto &x : val) cin >> x;
    for(auto &x : cnt) cin >> x;
    
    
    ll dp[k+1];
    for(i=0;i<=k;i++) dp[i] = 0;
    
    dp[0] = 1;
    for(i=0;i<n;i++){
        for(p=k;p>-1;p--){
            if(dp[p]==0) continue;
            for(j=1;j<=cnt[i] and p+val[i]*j<=k and dp[p+val[i]*j]==0;j++){
                dp[p+val[i]*j] = 1;
            }
        }
    }
    ll b = 0;
    for(i=1;i<=k;i++) b += dp[i];
    cout << "Case " << cs << ": " << b << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //seive(1e6+2);
    //For getting input from input.txt file
    //freopen("output3.txt", "r", stdin);

    //Printing the Output to output.txt file
    //freopen("output6.txt", "w", stdout);


    ll t=1, cs=1;
    cin >> t;
    while(t--){
        solve(cs++);
    }
}
