#include "data_parser.h"

#include <sstream>

using namespace std;
using namespace serial;
using namespace serial_utils;

Byte DataParser::StringToByte(string input)
{
    int result;
    stringstream stream;
    stream << hex << input;
    stream >> result;

    return result;
}

ByteArray DataParser::StringToArray(string input)
{
    if ( input.empty() )
        return ByteArray();

    ByteArray result;
    string byte;
    for ( int i = 0; i < input.size(); i+=2 )
    {
        byte.append(1, input[i]);
        byte.append(1, input[i+1]);

        result.push_back(StringToByte(byte));

        byte.clear();
    }

    return result;
}
