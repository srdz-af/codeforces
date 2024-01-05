#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[200005];
ll aac[200005];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    ll n, m, acc = 0, pass;
    cin >> n >> m;
    pass = n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    for(int i = 0; i < n; i++){
        acc+=arr[i];
        aac[i] = acc;
    }

    while(m--){
        ll s;
        cin >> s;

        ll l = 0, r = pass, mid;

        while(l < r){
            mid = (l+r)/2;
            if(arr[mid] <= s){
                l = mid+1;
            } else {
                r = mid;
            }
        }

        acc = aac[r-1] + (n-r)*s;
        arr[r] = s;
        pass = r;

        cout << acc << "\n";

    }
    return 0;
}