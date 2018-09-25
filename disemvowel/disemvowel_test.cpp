#include <gtest/gtest.h>

#include "disemvowel.h"
void disemvowel_test(char *str, char *expected) {
	char *noVowels = disemvowel(str);
	ASSERT_STREQ(expected, noVowels);
	if(noVowels != "") {
	  free(noVowels);
	}
}

TEST(Disemvowel, HandleEmptyString) {
  //ASSERT_STREQ("", disemvowel((char*) ""));
  disemvowel_test("","");
}

TEST(Disemvowel, HandleNoVowels) {
  //ASSERT_STREQ("pqrst", disemvowel((char*) "pqrst"));
  disemvowel_test("pqrst","pqrst");
}

TEST(Disemvowel, HandleOnlyVowels) {
  //ASSERT_STREQ("", disemvowel((char*) "aeiouAEIOUOIEAuoiea"));
  disemvowel_test("aeiouAEIOUOIEAuoiea","");
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  //ASSERT_STREQ("Mrrs, Mnnst",
  //		      disemvowel((char*) "Morris, Minnesota"));
  disemvowel_test("Morris, Minnesota","Mrrs, Mnnst");
}

TEST(Disemvowel, HandlePunctuation) {
  //ASSERT_STREQ("n (nxplnd) lphnt!", 
  //		      disemvowel((char*) "An (Unexplained) Elephant!"));
  disemvowel_test("An (Unexplained) Elephant!","n (nxplnd) lphnt!");
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  //ASSERT_STREQ("xyz", disemvowel(str));
  disemvowel_test(str, "xyz");

  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
