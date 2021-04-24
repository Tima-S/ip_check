#ifndef _IP_CHECK_LIB_H_
#define _IP_CHECK_LIB_H_

#include <string>
#include <vector>

///
/// \mainpage A library for validating ip addresses.
/// Please see the ip_checker class to understanding the library. 
/// The ip_checker class is a central class of this library.
///

///
/// A simgleton class for checking ip address.
/// This class checks whether ip adderess is valid or not.
/// GetInstance() method can be used to get a single object of this class.
///
class ip_checker 
{
    private:
        ip_checker(ip_checker &other);
        void operator = (const ip_checker &);

    protected:
        ip_checker() {}
        static ip_checker * instance;

        bool check_part(std::string part);

        ///
        /// Valid chars in ip address string.
        ///
        std::vector<char> valid_chars = {'.', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

    public:
        ///
        /// This method returns single object of the class.
        ///
        static ip_checker * GetInstance();

        ///
        /// This method can be used to check ip address.
        /// \param ip is a string which contains an ip.
        /// \return true when ip is valid, false when it is not valid.
        ///
        bool is_ip_valid(std::string ip);

        
};

#endif //_IP_CHECK_LIB_H_
