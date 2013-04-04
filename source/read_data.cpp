#include <iostream>
#include <libserial/serial_connection.h>

#include "program_options.h"
#include "data_parser.h"

using namespace std;
using namespace serial;
using namespace serial_utils;

void PrintUsage()
{
    cout << "Usage: read-data [options]" << endl;
    cout << "Options:" << endl;
    cout << "\t-f FILE\t\tDevice file of the serial port" << endl;
    cout << "\t-b BAUDRATE\tBaud rate value" << endl;
    cout << "\t-h\t\tPrint option help" << endl << endl;
    cout << "Example to read three bytes:" << endl;
    cout << "\tread-data -f /dev/ttyS0 -b 57600 -s 3" << endl << endl;

    exit(0);
}

int main(int argc, const char *argv[])
{
    ProgramOptions options(argv, argv+argc);

    if ( options.IsExist("-h") )
        PrintUsage();

    string dev_file = "";
    if ( options.IsExist("-f") )
        dev_file = options.GetString("-f");
    else
        PrintUsage();

    int baud_rate;
    if ( options.IsExist("-b") )
        baud_rate = options.GetInt("-b");
    else
        PrintUsage();

    SerialConnection connection(dev_file, baud_rate);

    ByteArray array;
    while (true)
    {
        array = connection.ReceiveData(kMaxBufferSize);

        DataParser::PrintArray(array);
    }

    return 0;
}
