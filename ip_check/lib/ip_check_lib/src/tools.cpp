#include "tools.h"

using namespace std;

list<string> str_tools::split_str(string str, string delimiter)
{
    size_t delimiter_len = delimiter.length();
    size_t str_len = str.length();

    list<string> lst = list<string>();

    if (str_len > delimiter_len) 
    {

        size_t pos = 0;
        size_t start_pos = 0;

        while (start_pos < str_len)       
        {
            pos = str.find(delimiter, start_pos);
            if (pos == string::npos)
            {
                // if we mot found a delimiter,
                // we use end of the str. 
                pos = str_len;
            }
            size_t count = pos - start_pos;
            string s = str.substr(start_pos, count);
            lst.push_front(s);

            start_pos = pos + delimiter_len;
        }
    }

    return lst;
}

bool str_tools::check_valid_chars(std::string str, std::vector<char> chars)
{
    if (str.empty()) 
    {
        return false;
    }

    string::iterator it = str.begin();
    while (it != str.end()) 
    {
        char c = *it;

        if (is_vector_contains(c, chars) == false)
        {
            return false;
        }
  
        it++;
    }

    return true;
}

    bool str_tools::is_vector_contains(char c, std::vector<char> chars)
    {
        if (std::find(chars.begin(), chars.end(), c) != chars.end()) 
        {
           return true;  
        } 
        return false;
    }