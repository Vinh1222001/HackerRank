#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> result;
    stringstream ss(str);

    int temp;
    while(ss >> temp){

        char char_temp;
        ss >> char_temp;
        result.push_back(temp);

        // str.erase();
    }
    return result;
}

int main() {
    string str;
    cin >> str;

    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}