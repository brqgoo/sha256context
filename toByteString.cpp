//
//  toByteString.cpp
//  sha256context
//
//  Created by Burak on 16.08.2022.
//

#include "toByteString.hpp"
#include <sstream>
#include <string>

std::string converToByteString(std::string in){
    std::stringstream ss;

    for (int i=0; i < in.size()/2; i++) {

        std::stringstream icat;
        icat << in[i*2] << in[i*2+1];

        std::string icatstr = icat.str();

        unsigned char hexNumber;

        sscanf(icatstr.c_str(), "%x", &hexNumber);
        ss << hexNumber;
    }
    
    return ss.str();
}
