#include "ip_check_lib.h"
#include "tools.h"

using namespace std;

ip_checker * ip_checker::instance = nullptr;

ip_checker * ip_checker::GetInstance()
{
    if (instance == nullptr) 
    {
        instance = new ip_checker();
    }
    return instance;
}

bool ip_checker::is_ip_valid(string ip)
{
    bool isValidChars = str_tools::check_valid_chars(ip, valid_chars);
    if (isValidChars == false) 
    {
        return false;
    }

    list<string> parts = str_tools::split_str(ip, ".");

    if (parts.size() == 4) 
    {
        list<string>::iterator it = parts.begin();
        while (it != parts.end())
            {
            if (check_part(*it))
            {
                it++;
            } else {
                return false;
            }
        }
        return true;
    }

    return false;
}

bool ip_checker::check_part(string part)
{
    try {
        int i = stoi(part);
        if (i >= 0 && i <= 255) 
        {
            return true;
        }
    } 
    catch (invalid_argument e)
    {
        return false;
    }

    return false;
}