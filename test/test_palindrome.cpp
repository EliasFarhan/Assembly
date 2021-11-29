//
// Created by efarhan on 11/29/21.
//

#include "gtest/gtest.h"
#include "palindrome.h"

TEST (PalindromeCpp, NotPalindrome)
{
    static constexpr std::string_view not_palindrome = "not palindrome";
    EXPECT_FALSE(is_palindrome(not_palindrome.data(), not_palindrome.size()));
}

TEST(PalindromeCpp, Palindrome4)
{
    static constexpr std::string_view palindrome = "abba";
    EXPECT_TRUE(is_palindrome(palindrome.data(), palindrome.size()));
}

TEST(PalindromeCpp, Palindrome5)
{
    static constexpr std::string_view palindrome = "radar";
    EXPECT_TRUE(is_palindrome(palindrome.data(), palindrome.size()));
}

TEST(PalindromeCpp, Palindrome0)
{
    static constexpr std::string_view palindrome;
    EXPECT_TRUE(is_palindrome(palindrome.data(), palindrome.size()));
}

TEST (PalindromeAsm, NotPalindrome)
{
    static constexpr std::string_view not_palindrome = "not palindrome";
    EXPECT_FALSE(is_palindrome_asm(not_palindrome.data(), not_palindrome.size()));
}

TEST(PalindromeAsm, Palindrome4)
{
    static constexpr std::string_view palindrome = "abba";
    EXPECT_TRUE(is_palindrome_asm(palindrome.data(), palindrome.size()));
}

TEST(PalindromeAsm, Palindrome5)
{
    static constexpr std::string_view palindrome = "radar";
    EXPECT_TRUE(is_palindrome_asm(palindrome.data(), palindrome.size()));
}

TEST(PalindromeAsm, Palindrome0)
{
    static constexpr std::string_view palindrome;
    EXPECT_TRUE(is_palindrome_asm(palindrome.data(), palindrome.size()));
}