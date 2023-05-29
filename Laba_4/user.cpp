#include "user.h"
#include "header.h"




bool checkHexa(string str) {
    string validChars = "0123456789ABCDEF";
    for (char c : str) {
        if (validChars.find(toupper(c)) == string::npos)
            return false;
    }
    return true;
}


bool checkDec(int num) {
    if (!std::isdigit(num)) {
        return false;
    }
    else {
        return true;
    }
}
