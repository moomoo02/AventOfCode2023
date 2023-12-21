#include <iostream>
#include <map>
#include <string>
using namespace std;
int getInt(string s, int i){
    map<string, int> mp;
    // Initialize the map
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;
    mp["four"] = 4;
    mp["five"] = 5;
    mp["six"] = 6;
    mp["seven"] = 7;
    mp["eight"] = 8;
    mp["nine"] = 9;
    for(auto it = mp.begin(); it != mp.end(); it++){
        string subStr = s.substr(i, it->first.size());
        if(subStr == it->first){
            return it->second;
        }
    }
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    int res = 0;
    string s;
    while(cin >> s) {
       char first = -1, second = -1;
        for(int i = 0; i < s.size(); i++){
            int digitStr = getInt(s,i);
            if(digitStr){
                cout << "digitStr: " << digitStr << '\n';
                if(first == -1){
                   first = (char)(digitStr + '0');
                }
                second = (char)(digitStr + '0');
            }else if(isdigit(s[i])){
                cout << "isDigit: " << s[i] << '\n';
                if(first == -1){
                    first = s[i];
                 }
                 second = s[i];
            }
            cout << first << ' ' << second << '\n';
        }
        string ans = "";      
        ans += first;
        ans += second;
        cout << "Ans : " << ans << '\n';
        res += stoi(ans);
    }
    cout << res << '\n';
    return 0;
}
