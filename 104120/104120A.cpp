#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    ll n, div;
    cin >> n;
    div = (3000/n) + (3000 % n != 0);
    cout << min((ll)15, div) << "\n";
    return 0;
}