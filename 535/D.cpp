#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    char xd[3] = {'R', 'G', 'B'};

    ll n, cnt = 0, j = 0;
    string s, tmp;
    cin >> n >> s;
    tmp = s;

    for(int i = 0; i < n; i++){

        if(i == n-1){
            while(s[n-1] == s[n-2]){
                s[n-1] = xd[(j++)%3];
            }
            continue;
        }

        if(s[i] == s[i-1] || s[i] == s[i+1]){
            i++;
            while(s[i] == s[i-1] || s[i] == s[i+1]){
                s[i] = xd[(j++)%3];
            }
        }

    }

    for(int i = 0; i < n; i++) if(tmp[i] != s[i]) cnt++;
    cout << cnt << "\n" << s << "\n";

    return 0;
}