#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// decimal to binary
string decToBinary(int dec)
    {
        string binary;
        int rem;
        do{
            rem = dec % 2;
            dec = dec / 2;
            binary.append(to_string(rem));

        } while ( dec > 0);
        
        reverse(binary.begin(), binary.end());
        return binary;
    }
    
string printAM(string nixbpe){
    
    cout << "am: " << nixbpe.substr(0,2) << endl;
    return am;
}
int main() {
    // Write C++ code here
    unsigned int hexval;
    unsigned int limit = 0XFFFFFF;
    unsigned int nixbpe; 

    cout << "Enter Hex: ";
    cin >> hex >> hexval; 
    
    if ( hexval <= limit){
        nixbpe = hexval & 0x03F000;
        nixbpe = nixbpe >> 12 ;
        // nixbpe = nixbpe & 0XC00000;
        cout << "nixbpe value"<< decToBinary(nixbpe) << endl ;
        printAM(decToBinary(nixbpe));
    }
    else {
        nixbpe = hexval & 0x3F00000;
        nixbpe = nixbpe >> 20;
        cout << "nixbpe value"<< decToBinary(nixbpe) << endl ;
    }

    return 0;
}
