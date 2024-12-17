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
    
string getAddressModes(string nixbpe){
    
    if (nixbpe.substr(0,2) = '11' || ){
        
    }
    
}

string getnixbpe( unsigned int hexval){
    unsigned int limit = 0XFFFFFF;
    unsigned int nixbpe = hexval & 0x03F000;
    
    if ( hexval <= limit){
        nixbpe = hexval & 0x03F000;
        nixbpe = nixbpe >> 12 ;
    }
    else {
        nixbpe = hexval & 0x3F00000;
        nixbpe = nixbpe >> 20;
        cout << "nixbpe value"<< ) << endl ;
    }

    return decToBinary(nixbpe);
}

unsigned int getTargetAddress(unsigned int hexvalue)}{
    unsigned int ta;
    
    return ta;
}

string getInstFormat(unsigned int hexvalue){
    string instFrmt;

    return instFrmt;
}

int main() {
    // Write C++ code here
    unsigned int hexval;
   
    unsigned int nixbpe; 

    cout << "Enter Hex: ";
    cin >> hex >> hexval; 
    
    

    return 0;
}
