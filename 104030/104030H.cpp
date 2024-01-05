#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[200005];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    ll n, hmax = -1;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> arr[i];

    for(int i = 2; i < n; i++){
        if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1]){
            ll j = i, lmin = LLONG_MAX, rmin = LLONG_MAX;

            while(j >= 2 && arr[j] >= arr[j-1]){
                lmin = arr[j-1];
                j--;
            }

            j = i;
            while(j < n && arr[j] >= arr[j+1]){
                rmin = arr[j+1];
                j++;
            }
            hmax = max(min(arr[i]-lmin, arr[i]-rmin), hmax);
            i = j;
        }
    }

    cout << hmax << "\n";

    return 0;
}