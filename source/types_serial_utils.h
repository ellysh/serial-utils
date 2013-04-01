#ifndef TYPES_SERIAL_UTILS_H
#define TYPES_SERIAL_UTILS_H

namespace serial_utils
{

static const int kMaxBufferSize = 1024;

/* A macro to disallow the copy constructor and operator= functions.
 * This should be used in the private: declarations for a class. */
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
private: \
    TypeName(const TypeName&);               \
    TypeName& operator=(const TypeName&);

}

#endif
