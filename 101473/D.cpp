#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define f first
#define s second
using namespace std;

vector<ll> og;
vector<ll> rs;

set<vector<ll>> ojo;

vector<ll> fold(ll n, vector<ll> vec){

    vector<ll> res;

    if(n == vec.size()){
        res = vec;
        reverse(res.begin(), res.end());
        return res;
    }

    if(n <= vec.size()/2){

        for(int i = vec.size()-1; i >= n*2; i--){
            res.push_back(vec[i]);
        }
        ll l = 0, r = (n*2)-1;
        while(l < r){
            res.push_back(vec[l] + vec[r]);
            l++; r--;
        }

    } else {

        ll l = vec.size()-(vec.size()-n)*2, r = vec.size()-1;
        for(int i = 0; i < l; i++){
            res.push_back(vec[i]);
        }
        while(l < r){
            res.push_back(vec[l] + vec[r]);
            l++; r--;
        }

    }


    return res;

}

void rec(vector<ll> & vec){
    if(vec.size() <= 1){
        ojo.insert(vec);
        return;
    }
    for(int i = 1; i < vec.size(); i++){
        auto res = fold(i, vec);
        if(!ojo.count(vec)) rec(res);
        ojo.insert(res);
    }
    ojo.insert(fold(0, vec));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    ll n,m;

    cin >> n;
    
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        og.push_back(a);
    }

    cin >> m;

    for(int i = 0; i < m; i++){
        ll a; cin >> a;
        rs.push_back(a);
    }


    rec(og);
    ojo.insert(og);


    if(ojo.count(rs)) cout << "S\n";
    else cout << "N\n";
    
    return 0;
}