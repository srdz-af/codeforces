#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        for(int i = 1; i < k+1; i++){
            cout << i << " ";
        }
        for(int i = n; i > k; i--){
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}