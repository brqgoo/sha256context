//
//  main.cpp
//  sha256context
//
//  Created by Burak on 16.08.2022.
//

#include <iostream>
#include "sha256.h"
#include <sstream>
#include "Bytestring.hpp"

std::string sha256context(std::string in) {
    
    ByteString bs(in);
    std::string s = bs.fromHexString();
    
    const unsigned char* t = reinterpret_cast<const unsigned char*>(s.c_str());

    CSHA256 cs;
    cs.SafeWrite(t, s.size());

    std::vector<unsigned char> l;
    l = cs.Save();

    std::string string;

    char const hex_chars[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

    for( int i = 0; i < l.size(); ++i )
    {
        char const byte = l[i];

        string += hex_chars[ ( byte & 0xF0 ) >> 4 ];
        string += hex_chars[ ( byte & 0x0F ) >> 0 ];
    }

    return string;
}

int main() {
    std::cout << "Enter data for SHA256 context > " << std::flush;
    std::string input;
    std::cin >> input;
    std::cout << "SHA256 context is:" << std::endl;
    std::cout << sha256context(input) << std::endl;
    return 0;
}
