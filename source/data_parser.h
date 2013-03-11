#ifndef DATA_PARSER_H
#define DATA_PARSER_H

#include <string>

#include <libserial/types_serial.h>

namespace serial_utils
{

class DataParser
{
public:
    static serial::Byte StringToByte(std::string input);
    static serial::ByteArray StringToArray(std::string input);
};

}

#endif
