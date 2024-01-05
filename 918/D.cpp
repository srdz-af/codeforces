#include <bits/stdc++.h>
using namespace std;
#define ll long long

set<char> V = {'a', 'e'};
set<char> C = {'b', 'c', 'd'};

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    ll t;
    cin >> t;

    while(t--){

        bool tog = true;
        ll n;
        string s;
        cin >> n >> s;
        set<ll> sep;
        for(int i = 0; i < n-1; i++){
            if(C.count(s[i]) && C.count(s[i+1])) sep.insert(i-1);            
        }
        if(C.count(s[n-1])) sep.insert(n-2);
        for(int i = 0; i < n; i++){
            cout << s[i];
            if(sep.count(i)) tog = !tog;
            if(i%2 == tog && i < n-1) cout << '.';
        }
        cout << "\n";
    }

    return 0;
}