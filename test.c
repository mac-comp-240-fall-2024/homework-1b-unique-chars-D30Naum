/*
 * TODO: Add an appropriate descriptive comment here
 */

#include <stdio.h>    // printf
#include <stdbool.h>  // to define a boolean type and true, false
#include <string.h>   // strcpy  to copy a string
#include <assert.h>


// declaration of function from hasUniqueChars.c
bool hasUniqueChars(char * inputStr);


int main() {

  // -------------------------------------------------------------
  // Thorough and exhaustive tests of hasUniqueChars()  
  bool ok;    // holds the result of hasUniqueChars(); used in asserts

  // Test 1 - Should pass with unique mix of letters, numbers, and symbols
  char string3[128];
  strcpy(string3, "AbC123$%^&*()");
  ok = hasUniqueChars(string3);
  if (ok) {
    printf("Test 1 passed: Unique mix of letters, numbers, and symbols.\n");
  } else {
    printf("Test 1 failed.\n");
  }
  assert(ok);

  // Test 2 - Should fail because of repeated spaces
  strcpy(string3, "No duplicates but   spaces");
  ok = hasUniqueChars(string3);
  if (!ok) {
    printf("Test 2 passed: Detected repeated spaces.\n");
  } else {
    printf("Test 2 failed.\n");
  }
  assert(!ok);

  // Test 3 - Should pass with a long string of unique characters (127 total)
  strcpy(string3, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{};:'\",.<>?/`~|");
  ok = hasUniqueChars(string3);
  if (ok) {
    printf("Test 3 passed: Long string of unique characters.\n");
  } else {
    printf("Test 3 failed.\n");
  }
  assert(ok);

  // Test 4 - This should fail because of the special newline character (\n)
  strcpy(string3, "a b cc\n");
  ok = hasUniqueChars(string3);
  if (!ok) {
    printf("Test 4 passed: Detected newline character.\n");
  } else {
    printf("Test 4 failed.\n");
  }
  assert(!ok);

  // Test 5 - Should fail due to null character (\0) and duplicates
  strcpy(string3, "test\0ing");
  ok = hasUniqueChars(string3);
  if (!ok) {
    printf("Test 5 passed: Detected null character and duplicates.\n");
  } else {
    printf("Test 5 failed.\n");
  }
  assert(!ok);

  // Test 6 - Should fail due to the escape tab character (\t)
  strcpy(string3, "abc\tdefg");
  ok = hasUniqueChars(string3);
  if (!ok) {
    printf("Test 6 passed: Detected tab character.\n");
  } else {
    printf("Test 6 failed.\n");
  }
  assert(!ok);

  // Test 7 - Should pass for unique uppercase and lowercase letters
  strcpy(string3, "aBcDeFgHiJkLmNoP");
  ok = hasUniqueChars(string3);
  if (ok) {
    printf("Test 7 passed: Unique uppercase and lowercase letters.\n");
  } else {
    printf("Test 7 failed.\n");
  }
  assert(ok);

  // Test 8 - Should fail because of repeated number '9'
  strcpy(string3, "1234567890987654321");
  ok = hasUniqueChars(string3);
  if (!ok) {
    printf("Test 8 passed: Detected repeated numbers.\n");
  } else {
    printf("Test 8 failed.\n");
  }
  assert(!ok);

  return 0;
}