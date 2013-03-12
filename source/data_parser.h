#ifndef DATA_PARSER_H
#define DATA_PARSER_H

#include <string>

#include <libserial/types_serial.h>

namespace serial_utils
{

class DataParser
{
public:
    static serial::ByteArray StringToArray(const std::string input);
    static void PrintArray(const serial::ByteArray input);

private:
    static serial::Byte StringToByte(const std::string input);
};

}

#endif
