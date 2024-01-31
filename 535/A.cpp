#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    ll t;
    cin >> t;
    while(t--){
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        cout << l1 << " ";
        if(l1 != r2) cout << r2 << "\n";
        else cout << l2 << "\n";
    }

    return 0;
}
