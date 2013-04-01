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
    cout << "\t-s SIZE\t\tSize of reading data" << endl;
    cout << "\t-h\t\tPrint option help" << endl << endl;
    cout << "Example to read three bytes:" << endl;
    cout << "\tread-data -f /dev/ttyS0 -b 57600 -s 3" << endl << endl;

    exit(0);
}

int main(int argc, char *argv[])
{
    ProgramOptions options(argv, argv+argc);

    if ( options.IsOptionExist("-h") )
        PrintUsage();

    string dev_file = "";
    if ( options.IsOptionExist("-f") )
        dev_file = options.GetString("-f");
    else
        PrintUsage();

    int baud_rate;
    if ( options.IsOptionExist("-b") )
        baud_rate = options.GetInt("-b");
    else
        PrintUsage();

    int size;
    if ( options.IsOptionExist("-s") )
        size =  options.GetInt("-s");
    else
        PrintUsage();

    SerialConnection connection(dev_file, baud_rate);

    ByteArray array;
    while (true)
    {
        array = connection.ReceiveData(size);

        DataParser::PrintArray(array);
    }

    return 0;
}
