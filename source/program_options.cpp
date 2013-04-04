#include "program_options.h"

#include <algorithm>

using namespace std;
using namespace serial_utils;

const char* ProgramOptions::GetString(const string& option) const
{
    const char** itr = find(begin_, end_, option);

    if ( (itr != end_) && (++itr != end_) )
        return *itr;
    else
        return "";
}

int ProgramOptions::GetInt(const string& option) const
{
    const char* value = GetString(option);

    return atoi(value);
}

bool ProgramOptions::IsExist(const string& option) const
{
    return find(begin_, end_, option) != end_;
}
