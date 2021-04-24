#include "version.h"

#include <iostream>
#include <string>

#include "ip_check_lib.h"

using namespace std;

int main(int argc, char *argv[]) 
{
    cout << "IPCheck version " << IPCHECK_VERSION_MAJOR << "."
                               << IPCHECK_VERSION_MINOR << "."
                               << IPCHECK_VERSION_PATCH << endl;
    cout << "IP address validation programm" << endl;

    if (argc < 2) 
    {
        cout << "IP address is not defined" << endl;
        return 0;
    }

    string s(argv[1]);
    cout << "IP address is " << s << endl;

    ip_checker * ipcheck = ip_checker::GetInstance();
    bool valid = ipcheck->is_ip_valid(s);
    
    if (valid)
    {
        cout << "The address is valid." << endl;
    }
    else 
    {
        cout << "The address is not valid." << endl;
    }

    return 0;
}