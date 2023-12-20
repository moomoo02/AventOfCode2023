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
    string line;
    int ans = 0;
    int red = 12, green = 13, blue = 14;
    while(getline(inputFile, line)) {
        vector<int> tokens;
        tokenize(tokens, line);
        bool winnable = true;
        for(int i = 1; i < tokens.size(); i+=2){
            cout << tokens[i] << ' ' << tokens[i+1] << '\n';
            if(tokens[i+1] == 0 && tokens[i] > red) winnable = false;
            if(tokens[i+1] == 1 && tokens[i] > green) winnable = false;
            if(tokens[i+1] == 2 && tokens[i] > blue) winnable = false;
        }
        cout << line << " : " << winnable << '\n';
        if(winnable) ans += tokens[0];
    }
    cout << ans << '\n';
    return 0;
}
