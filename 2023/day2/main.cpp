#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void tokenize(vector<int> & v, string s){
    bool colon = false;
    for(int i = 0; i < s.size(); i++){
        string num = "";
        while(!colon && isdigit(s[i])){
            num += s[i];
            i++;
        }
        if(s[i] == ':'){
            v.push_back(stoi(num));
            colon = true;
        }
        if(!colon) continue;
        num = "";

        if(isdigit(s[i])){
             while(isdigit(s[i])){
                 num += s[i];
                 i++;
            }
            v.push_back(stoi(num));

            // Check type
            i++;
            if(s[i] == 'r'){
                v.push_back(0);
            } else if(s[i] == 'g') {
                v.push_back(1);
            } else {
                v.push_back(2);
            }
        } 

    }

}

int main() {
    fstream inputFile("input.txt");
    freopen("output.txt", "w", stdout); 
    string line;
    int ans = 0;
    int red = 12, green = 13, blue = 14;
    while(getline(inputFile, line)) {
        vector<int> tokens;
        tokenize(tokens, line);
        bool winnable = true;
        vector<int> mn(3,0);
        for(int i = 1; i < tokens.size(); i+=2){
            mn[tokens[i+1]] = max(mn[tokens[i+1]], tokens[i]);
        }
        int res = 1;
        cout << "Min set: ";
        for(int i = 0; i < 3; i++){
            res *= mn[i];
            cout << mn[i] << ' ';
        }
        cout << "\nres : " << res << '\n';
        ans += res;
    }
    cout << ans << '\n';
    return 0;
}
