#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<char, char> keypad = {{'a', '2'}, {'b', '2'}, {'c', '2'}, {'d', '3'}, {'e', '3'}, {'f', '3'}, {'g', '4'}, {'h', '4'}, 
                        {'i', '4'}, {'j', '5'}, {'k', '5'}, {'l', '5'}, {'m', '6'}, {'n', '6'}, {'o', '6'}, {'p', '7'}, 
                        {'q', '7'}, {'r', '7'}, {'s', '7'}, {'t', '8'}, {'u', '8'}, {'v', '8'}, {'w', '9'}, {'x', '9'}, 
                        {'y', '9'}, {'z', '9'}};

string conv(string s){
    string ans = "";
    for(auto it: s){
        ans+=keypad[it];
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    ll n, q;
    cin >> n >> q;
    map<string, ll> idn;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        idn[conv(s)]++;
    }

    for(int i = 0; i < q; i++){
        string s;
        cin >> s;
        cout << idn[s] << "\n";
    }

    return 0;
}