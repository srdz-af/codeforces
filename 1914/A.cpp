#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        string s;
        cin >> n >> s;
        map<char, ll> fq;
        ll ans = 0;
        for(auto it: s) fq[it]++;
        for(auto it: fq) if(it.second >= (it.first -'A'+1)) ans++;
        cout << ans << "\n";
    }
    return 0;
}