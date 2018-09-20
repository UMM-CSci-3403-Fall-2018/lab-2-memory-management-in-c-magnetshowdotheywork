#include <stdlib.h>

#include "disemvowel.h"

char *disemvowel(char *str) {
  char *consonants = "BbCcDdFfGgHhJjKkLlMmNnPpQqRrSsTtVvWwXxYyZz";
  int conLen = 42;
  int resultLen = 0;
  strLen = strlen(str);
  // Create a temporary string for the result that is bigger than we need
  char *tempResult = (char*) calloc(strLen + 1, sizeof(char));
  
  // If a letter is a consonant, add it to the result
  for (int i = 0; i < strLen; i++) {
    for (int j = 0; j < conLen; j++) {
      if(str[i] == consonants[j]) {
       	tempResult[resultLen] = str[i];
	resultLen++;
	break;
      }
    }
  }

  // If str was all consonants, just return it
  if( strLen == resultLen ) {
    //free(consonants);
    free(tempResult);
    return str;
  }
  
  // Create the empty result
  char *result = (char*) calloc(resultLen + 1, sizeof(char));

  // Copy the characters from tempResult to result
  memcpy(result, tempResult, resultLen);

  // add the null terminator to the end of result
  result[resultLen] = '/0';

  //free(consonants);
  free(tempResult);
    
  return result;
}
