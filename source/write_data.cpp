#include <iostream>
#include <libserial/serial_connection.h>

#include "program_options.h"
#include "data_parser.h"

using namespace std;
using namespace serial;
using namespace serial_utils;

void PrintUsage()
{
    cout << "Usage: write-data [options]" << endl;
    cout << "Options:" << endl;
    cout << "\t-f FILE\t\tDevice file of the serial port" << endl;
    cout << "\t-b BAUDRATE\tBaud rate value" << endl;
    cout << "\t-d DATA\t\tString with data to write" << endl;
    cout << "\t-h\t\tPrint option help" << endl << endl;
    cout << "Example to write three bytes 0x01, 0xA0 and 0xFF:" << endl;
    cout << "\twrite-data -f /dev/ttyS0 -b 57600 -d 01A0FF" << endl << endl;

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

    string data;
    if ( options.IsExist("-d") )
        data =  options.GetString("-d");
    else
        PrintUsage();

    SerialConnection connection(dev_file, baud_rate);

    ByteArray array = DataParser::StringToArray(data);

    connection.SendData(array);

    return 0;
}
