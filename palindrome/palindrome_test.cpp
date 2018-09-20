#include <gtest/gtest.h>

#include "palindrome.h"

// Nic wanted us to make a function for the reused logic - Nic said he probably wouldn't give us extra credit for doing so, BUT, probably means there's a non-zero chance. Just thought I'd mention it :)

void palindrome_test(char const *str, char const *yesno) {
  char *answer = palindrome(str);
  ASSERT_STREQ(answer, yesno);
  free(answer);
}

void is_palindrome(char const *str) {
  palindrome_test(str, "Yes");
}

void not_palindrome(char const *str) {
  palindrome_test(str, "No");
}

TEST(Palindrome, HandlesEmptyString) {
  is_palindrome("");
}

TEST(Palindrome, HandlesSingletons) {
  is_palindrome("a");
  is_palindrome("b");
  is_palindrome("c");
}

TEST(Palindrome, HandlesLengthTwo) {
  is_palindrome("aa");
  is_palindrome("bb");
  not_palindrome("ab");
}

TEST(Palindrome, HandlesLengthThree) {
  is_palindrome("aaa");
  is_palindrome("bab");
  not_palindrome("abc");
  not_palindrome("abb");
}

TEST(Palindrome, HandlesLengthFour) {
  is_palindrome("aaaa");
  is_palindrome("baab");
  not_palindrome("abcd");
  not_palindrome("aabb");
  not_palindrome("abbc");
  not_palindrome("abca");
}

TEST(Palindrome, HandlesLongerStrings) {
  is_palindrome("aaaaaaaaaaa");
  is_palindrome("aaaaaaaaaaaa");
  is_palindrome("abcdefgfedcba");
  is_palindrome("abcdefggfedcba");
  not_palindrome("abcdefghijk");
  not_palindrome("aaaaaaaaaaaabaaaa");
  not_palindrome("abcdxfgfedcba");
  not_palindrome("abcdefggfexcba");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
