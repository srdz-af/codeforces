#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    set<ll> ojo;
    vector<ll> nb;
    ll t, maxn = 0, maxm = 0;
    cin >> t;

    for(int i = 0; i < t; i++){
        ll aux;
        cin >> aux;
        nb.push_back(aux);
        maxn = max(aux, maxn);
    }

    for(auto it: nb){
        if(maxn % it){
            maxm = max(it, maxm);
        } else {
            if(ojo.count(it)){
                maxm = max(it, maxm);
            }
            ojo.insert(it);
        }
    }

    if(!maxm) maxm = maxn;

    cout << maxn << " " <<  maxm << "\n";
    return 0;
}