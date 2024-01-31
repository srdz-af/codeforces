#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> st;
    for(int i = 0; i < n; i++){
        ll s, t, b;
        cin >> s >> t >> b;
        st.push_back({s, b});
        st.push_back({t, -b});
    }

    sort(st.begin(), st.end());
    
    ll nmax = -1;
    ll acc = 0;

    for(auto it: st){
        acc += it.second;
        nmax = max(nmax, acc);
    }

    cout << nmax << "\n";
}