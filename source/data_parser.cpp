#include "data_parser.h"

#include <sstream>
#include <iostream>

using namespace std;
using namespace serial;
using namespace serial_utils;

ByteArray DataParser::StringToArray(const string input)
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

Byte DataParser::StringToByte(const string input)
{
    int result;
    stringstream stream;
    stream << hex << input;
    stream >> result;

    return result;
}

void DataParser::PrintArray(const ByteArray input)
{
    for ( int i = 0; i < input.size(); i++ )
    {
        cout << hex << (int)input[i] << " ";
    }

    cout << endl;
}
