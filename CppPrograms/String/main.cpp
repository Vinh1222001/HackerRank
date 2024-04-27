#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a, b;
    cin >> a >> b;

    cout << a.size() << " " << b.size()<< endl;
    
    string c = a + b;
    cout << c << endl;
    
    char first_char = a[0];
    a[0] = b[0];
    b[0] = first_char;
    cout << a << " " << b << endl;
    return 0;
}