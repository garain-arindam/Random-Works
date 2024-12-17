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

// finding the instruction format 
int getInstFormat(unsigned int inst){
    
    if ( inst <= 0xff) {
        return 1;
    }
    else if ( inst <= 0xffff) {
        return 2;
    }
    else if (inst <= 0xffffff){
        return 3;
    }
    else if (inst <= 0xffffffff){
        return 4;
    }
}

// validity of the instruction
bool isValidInst(unsigned int inst){
     switch (getInstFormat(inst))
    {
    case 1 :
        return ( (inst & 0x03) == 0 );
        break;
    case 2 :
        return ( (inst & 0x0300)  == 0 );
        break;
    case 3 :
        return ( (inst & 0x030000)  == 0 );

        break;    
    case 4 :
        return ( (inst & 0x03000000)  == 0 );

        break;
    default:
        break;
    }
}

// getting OPCODE
string getOpCode(unsigned int inst){
    string opCode;
    int opcodeval;
   
    unsigned int opcodeval;

    return opCode;
}






string getAddressModes(string inst){
    string addrModes; 
    return addrModes;
}

string getnixbpe( unsigned int inst){
    unsigned int instfrmt = 0xffff;
    unsigned int limit = 0XFFFFFF;
    unsigned int nixbpe = inst & 0x03F000;
    
    if ( inst <= instfrmt){
        return "No nixbpe bits";
    }

    if ( inst <= limit){
        nixbpe = inst & 0x03F000;
        nixbpe = nixbpe >> 12 ;
    }
    else {
        nixbpe = inst & 0x3F00000;
        nixbpe = nixbpe >> 20;
    }

    return decToBinary(nixbpe);
}

unsigned int getTargetAddress(unsigned int inst){
    unsigned int ta;
    
    return ta;
}



int main() {
    // Write C++ code here
    unsigned int inst;
   
    unsigned int nixbpe; 

    cout << "Enter Hex: ";
    cin >> hex >> inst; 
    cout << "nixbpe: " << getnixbpe(inst) << endl;
    
    return 0;
}
