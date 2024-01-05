#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    
    ll t;
    cin >> t;
    map<ll, ll> freq;
    for(int i = 0; i < 3*t; i++){
        ll aux;
        cin >> aux;
        freq[aux]++;
    }

    for(auto it: freq){
        if(it.second % 3){
            cout << "Y\n";
            return 0;
        }
    }

    cout << "N\n";
    return 0;
}
