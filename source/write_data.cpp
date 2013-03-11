#include <iostream>
#include <libserial/serial_connection.h>

#include "program_options.h"

using namespace std;
using namespace serial;
using namespace serial_utils;

void PrintUsage()
{
    cout << "Usage: write-data [options]" << endl;
    cout << "Options:" << endl;
    cout << "\t-f FILE\t\tDevice file of the serial port" << endl;
    cout << "\t-b BAUDRATE\t\tBaud rate value" << endl;
    cout << "\t-d DATA\t\tString with data to write" << endl;
    cout << "\t-h\t\t\tPrint option help" << endl;
    cout << "Example to write three bytes 0x01, 0xA0 and 0xFF:" << endl;
    cout << "\twrite-data -f /dev/ttyS0 -b 57600 -d 01A0FF" << endl;
}

int main(int argc, char *argv[])
{
    ProgramOptions options(argv, argv+argc);

    if ( options.IsOptionExist("-h") )
    {
        PrintUsage();
        return 1;
    }

    string dev_file = "";
    if ( options.IsOptionExist("-f") )
        dev_file = options.GetString("-f");

    int baud_rate;
    if ( options.IsOptionExist("-b") )
        baud_rate = options.GetInt("-b");

    SerialConnection connection(dev_file, baud_rate);

    /* FIXME: Implement the data string parsing to ByteArray */

    /* FIXME: Send data to the port */

    return 0;
}
