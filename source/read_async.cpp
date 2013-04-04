#include <iostream>
#include <libserial/serial_server.h>

#include "program_options.h"
#include "data_parser.h"

using namespace std;
using namespace serial;
using namespace serial_utils;

void PrintUsage()
{
    cout << "Usage: read-async [options]" << endl;
    cout << "Options:" << endl;
    cout << "\t-f FILE\t\tDevice file of the serial port" << endl;
    cout << "\t-b BAUDRATE\tBaud rate value" << endl;
    cout << "\t-h\t\tPrint option help" << endl << endl;
    cout << "Example to read:" << endl;
    cout << "\tread-async -f /dev/ttyS0 -b 57600" << endl << endl;

    exit(0);
}

void ReceiveHandler(const ByteArray& array)
{
    DataParser::PrintArray(array);
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

    boost::asio::io_service io_service;
    SerialServer server(io_service);
    server.SetReceiveHandler(ReceiveHandler);
    server.StartServerAndReceive(dev_file, baud_rate);
    io_service.run();

    return 0;
}
