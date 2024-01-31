#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    ll a[3];

    for(int i = 0; i < 3; i++) cin >> a[i];
    sort(a, a+3);

    if(a[1]-a[0] == 1 && a[2]-a[1] == 1) cout << "0\n0\n";
    else if(a[2]-a[1] == 2 || a[1]-a[0] == 2) cout << "1\n" << max(abs(a[1] - a[0]), abs(a[1] - a[2]))-1 << "\n";
    else cout << "2\n" << max(abs(a[1] - a[0]), abs(a[1] - a[2]))-1 << "\n";

    return 0;
}