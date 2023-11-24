#include<bits/stdc++.h>
#define ll long long

using namespace std;


void solve(ll cs){
    ll n, x, y, k, j, i, sum=0;
    double ab, ac, bc, ad, ae, de, rat;
    cin >> ab >> ac >> bc >> rat;
    double l=0, r=ab, mid;
    while(r-l>=1e-12){
        ad = (l+r)/2;
        ae = (ad/ab)*ac;
        de = (ad/ab)*bc;
        double s = (ad+ae+de)/2;
        double s1 = (ab+ac+bc)/2;
        s = sqrt(s*(s-ad)*(s-ae)*(s-de));
        s1 = sqrt(s1*(s1-ab)*(s1-bc)*(s1-ac))-s;
        double rat1 = s/s1;
        if(rat1<rat) l = ad;
        else r = ad;
    }
    printf("Case %ld: %.12lf\n",cs,l);
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t=1, c=0;
    cin >> t;
    while(t--){
        solve(++c);
    }
}
