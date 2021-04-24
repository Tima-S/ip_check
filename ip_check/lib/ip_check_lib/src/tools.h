#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <string>
#include <list>
#include <vector>

///
/// This namespace contains functions for work with strings.
///
namespace str_tools 
{
    ///
    /// This function splits string with delimiter.
    /// \param str it is a string which should be split. 
    /// \param delimiter it is a delimiter for splitting a string.
    /// \return list of strings after the str was split. It is empty on fail.
    ///
    std::list <std::string> split_str(std::string str, std::string delimiter);

    ///
    /// This function checks a string which should contains only valid chars.
    /// \param str it is a string which should be checked.
    /// \param chars it is chars for checking. 
    /// \return true if the string contains only valid chars. Otherwise, the result is false.
    /// 
    bool check_valid_chars(std::string str, std::vector<char> chars);

    ///
    /// This function checks a char is exist in a vector of chars.
    /// \param c it is a char which should be checked.
    /// \param chars it is vector of chars for checking. 
    /// \return true if the vector contains the char. Otherwise, the result is false.
    /// 
    bool is_vector_contains(char c, std::vector<char> chars);

}

#endif // _TOOLS_H_