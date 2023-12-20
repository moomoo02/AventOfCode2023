#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int res = 0;
    string s;
    while(cin >> s) {
       char first = -1, second = -1;
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                if(first == -1){
                    first = s[i];
                 }
                 second = s[i];
            }
        }
        string ans = "";      
        ans += first;
        ans += second;
        res += stoi(ans);
    }
    cout << res << '\n';
    return 0;
}
