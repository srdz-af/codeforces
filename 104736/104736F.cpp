#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool pcheck(vector<ll> n){
    ll l = 0, r = n.size()-1;
    while(l < r){
        if(n[l] != n[r]) return false;
        l++; r--;
    }
    return true;
}

vector<ll> bconv(ll n, ll b){
    vector<ll> nb;
    while(n > 0){
        nb.push_back(n%b);
        n /= b;
    }
    return nb;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    
    ll n;
    cin >> n;
    set<ll> ans;

    if(n == 2){
        cout << "*\n";
        return 0;
    } 

    for(int i = 2; i <= sqrt(n-1); i++){
        if(pcheck(bconv(n, i))) ans.insert(i);
    }

    for(int i = 1; i <= sqrt(n+1)-1; i++){
        if((n-i) % i == 0 && n-i > i) ans.insert((n-i)/i);
    }

    for(auto it: ans){
        cout << it << " ";
    }

    if(!ans.size()) cout << "*";
    cout << "\n";

    return 0;
}

