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
    static serial::ByteArray StringToArray(std::string input, size_t start, size_t end);

private:
    virtual void ParseFileLine(std::string& line) = 0;

    void ParseFile(std::string& filename);

    static serial::ByteArray ParseRequest(std::string& request);
};

}

#endif
