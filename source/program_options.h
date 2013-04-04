#ifndef PROGRAM_OPTIONS_H
#define PROGRAM_OPTIONS_H

#include <string>

#include "types_serial_utils.h"

namespace serial_utils
{

class ProgramOptions
{
public:
    ProgramOptions(const char** begin, const char** end) : begin_(begin), end_(end) {};

    const char* GetString(const std::string& option) const;
    int GetInt(const std::string& option) const;
    bool IsExist(const std::string& option) const;

private:
    const char** begin_;
    const char** end_;

    DISALLOW_COPY_AND_ASSIGN(ProgramOptions)
};

}

#endif
