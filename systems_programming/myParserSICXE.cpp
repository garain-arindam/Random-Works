#include <iostream>
#include <string>
#include <bitset>
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
int getInstFormat(string inst){
    if (inst.size() % 2  == 0)
        if ((inst.size()/2 >=1) && (inst.size()/2 <= 4))
            return inst.size()/2;
        else return 0;
    else    
        return 0;
}

// getting OPCODE
string getOpCode(string inst){
    string code = string();
    unsigned long instruction = stoul(inst, nullptr, 16);
    if (getInstFormat(inst) == 1) {
        std::bitset<8> opCode1(instruction);
        code = opCode1.to_string();
    } 
    else if (getInstFormat(inst) == 2) {
        std::bitset<16> opCode2(instruction);
        std::bitset<16> opBits2(0xfc00); // for getting the 8 bits opcode
        code = ((opCode2 & opBits2).to_string()).substr(0, 8);
    } 
    else if (getInstFormat(inst) == 3) {
        std::bitset<24> opCode3(instruction);
        std::bitset<24> opBits3(0xfc0000); // for getting the 8 bits opcode
        code = ((opCode3 & opBits3).to_string()).substr(0, 8);
    } 
    else if (getInstFormat(inst) == 4) {
        std::bitset<32> opCode4(instruction);
        std::bitset<32> opBits4(0xfc000000); // for getting the 8 bits opcode
        code = ((opCode4 & opBits4).to_string()).substr(0, 8);
    }
    return code; // returns empty string
}

/**
// validity of the instruction
bool isValidInst(string inst){
    int size = 8 * getInstFormat(inst);
    unsigned long int instruction = stoul(inst, nullptr,16); 
    switch (size)
    {
    case 8 :
        bitset<8> 
        return ( (inst & 0x03) == 0 );
        break;
    case 16 :
        return ( (inst & 0x0300)  == 0 );
        break;
    case 24 :
        cout << "inside isvalid: frmt 3 -> inst & 0x030000 "<< (inst & 0x030000) << endl;////////
        return ( (inst & 0x030000)  == 0 );

        break;    
    case 32 :
        return ( (inst & 0x03000000)  == 0 );

        break;
    default:
        //return false;
        break;
    }
    return false;
}



// getting nixbpe
string getnixbpe( unsigned int inst){
    unsigned int instfrmt = 0xffff; // format 2
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
        nixbpe = inst & 0x03F00000;
        nixbpe = nixbpe >> 20;
    }

    return decToBinary(nixbpe);
}


// addressing modes
string getAddressModes(unsigned int inst){
    cout << "inside adr mode : " << isValidInst(inst) << endl;//////////////////////
    if (isValidInst(inst) && (getInstFormat(inst) >= 3) ){
        string nixbpe = getnixbpe(inst);
        cout << "inside adr mode " << nixbpe << endl;///////////////////////
        //if (nixbpe[0] == '0' && nixbpe[1] == '0' && nixbpe[2] == '0' ) || (nixbpe[0] == '0' && nixbpe[1] == '0' && nixbpe[2] == '1' )
        if (nixbpe.substr(0,2) == "000" || nixbpe.substr(0,2) == "001"){
            return "Simple";
        }
        if (nixbpe[0] == '0'&& nixbpe[1] == '1')
            return "Immediate";
        else if (nixbpe[0] == '1' && nixbpe[1] == '0')
            return "Indirect";
        else if (nixbpe[0] == '1' && nixbpe[1] == '1')
            return "Simple";
    }
    return "Invalid Instruction";
}



unsigned int getTargetAddress(unsigned int inst){
    unsigned int ta;
    if (isValidInst(inst)){
        if ( getInstFormat(inst) == 3){
            return (inst & 0x000fff);
        if (getInstFormat(inst) == 4)
            return (inst & 0x000fffff);
        }
    }
    return 0;
}

*/

int main() {
    // Write C++ code here
    string inst;
   
    unsigned int nixbpe; 

    cout << "Enter instruction in hex: ";
    cin >> inst; 
    cout << "Format " << getInstFormat(inst) << endl;
    cout << "Opcode " << getOpCode(inst) << endl;
    //inst = 0x241024;
    
    // bitset<24> hex(0x241024);
    // bitset<24> ext(0x03F000);
    // string nixbpes=(hex & ext).to_string();
    // cout << "hex " << hex << endl <<  "ext " << ext << endl;
    // cout << "nixbpe: " << nixbpes << "only part: " << nixbpes.substr(6,6) << endl ;
    // cout << "inst in bin " <<  decToBinary(inst) << inst << ": " << decToBinary(0x030000) << endl;
    // cout << "nixbpe: " << getnixbpe(inst) << endl;
    // cout << "adr mode: " << getAddressModes(inst) << endl;
    // cout << "target address: " << decToBinary(getTargetAddress(inst)) << endl;
    // cout << "format:  " << getInstFormat(inst) << endl;

    
    return 0;
}
