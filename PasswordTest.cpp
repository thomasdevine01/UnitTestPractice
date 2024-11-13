/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual); // true
}
TEST(PasswordTest, single_letter_password_zzz)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZZZZLwdejwdbed");
	ASSERT_EQ(6, actual); // 6
}
TEST(PasswordTest, has_mixed_case_single_letter_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("Z");
	ASSERT_EQ(0, actual); // false
}
TEST(PasswordTest, has_mixed_case_all_lower)
{
	Password my_password;
	int actual = my_password.has_mixed_case("dddddddddd");
	ASSERT_EQ(0, actual); // false
}
TEST(PasswordTest, has_mixed_case_all_upper)
{
	Password my_password;
	int actual = my_password.has_mixed_case("DDDDDDDDDD");
	ASSERT_EQ(0, actual); // false
}
TEST(PasswordTest, has_mixed_case_mixed_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("PaSsWorD");
	ASSERT_EQ(1, actual); // true
}
TEST(PasswordTest, has_mixed_case_zero_length)
{
	Password my_password;
	int actual = my_password.has_mixed_case("");
	ASSERT_EQ(0, actual); // false
}
TEST(PasswordTest, has_mixed_case_all_numbers)
{
	Password my_password;
	int actual = my_password.has_mixed_case("00012312312398823742734097324070123");
	ASSERT_EQ(0, actual); // false
}

