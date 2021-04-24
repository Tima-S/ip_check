#include <string>
#include "ip_check_lib.h"
#include "gtest/gtest.h"

TEST(ip_check_lib_tests, valid_ip)
{
    std::string s = "192.168.1.1";
    ip_checker * ipcheck = ip_checker::GetInstance();
    bool valid = ipcheck->is_ip_valid(s);

    EXPECT_TRUE(valid);

}

TEST(ip_check_lib_tests, invalid_ip)
{
    std::string s = "192.453.1.1";
    ip_checker * ipcheck = ip_checker::GetInstance();
    bool valid = ipcheck->is_ip_valid(s);

    EXPECT_FALSE(valid);

}

TEST(ip_check_lib_tests, invalid_ip_long)
{
    std::string s = "192.45.5.1.1";
    ip_checker * ipcheck = ip_checker::GetInstance();
    bool valid = ipcheck->is_ip_valid(s);

    EXPECT_FALSE(valid);
}

TEST(ip_check_lib_tests, invalid_ip_short)
{
    std::string s = "192.4.1";
    ip_checker * ipcheck = ip_checker::GetInstance();
    bool valid = ipcheck->is_ip_valid(s);

    EXPECT_FALSE(valid);
}

TEST(ip_check_lib_tests, invalid_ip_letter)
{
    std::string s = "192.45.j.1";
    ip_checker * ipcheck = ip_checker::GetInstance();
    bool valid = ipcheck->is_ip_valid(s);

    EXPECT_FALSE(valid);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}