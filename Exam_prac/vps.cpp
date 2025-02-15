// 백준 9012번
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string VPS(string in){
    stack<char> vps;
    for(int i = 0; i < in.size(); i++){
        if(in[i] == '('){
            vps.push('(');
        }
        else{
            if(vps.empty()){
                return "NO";
            }
            vps.pop();
        }
    }

    if(vps.empty()){
        return "YES";
    }
    else {
        return "NO";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        
        cout << VPS(s) << "\n";
    }
}