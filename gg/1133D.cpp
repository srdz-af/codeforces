#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define f first
#define s second

ll a[MAXN];
ll b[MAXN];

pair<ll, ll> reduce(pair <ll, ll> r){
    if(r.f == 0 || r.s == 0) return {0, 1};
    else if(r.s < 0) r = {-r.f, -r.s};
    return {r.f/gcd(r.f, r.s), r.s/gcd(r.f, r.s)};
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    
    ll n, maxf = 0, z = 0;
    cin >> n;

    map<pair<ll, ll>, ll> freq;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];

        if(a[i] == 0){
            if(b[i] == 0) z++;
            continue;
        }

        freq[reduce({-b[i], a[i]})]++;
        maxf = max(maxf, freq[reduce({-b[i], a[i]})]);
    }

/*     for(auto it: freq){
        cout << "{" << it.f.f << "/" << it.f.s << "}: " << it.s << "\n";
    } */
    cout << maxf+z << "\n";


    return 0;
}