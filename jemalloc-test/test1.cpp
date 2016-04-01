#include <cstdio>
#include "jemalloc\jemalloc.h"

int test_count = 1;
#define TEST(func) do { std::printf("Test %02d: '" #func "' ... ", test_count++); std::puts(func() ? "Success" : "Failed"); } while(0);

#define ARRAY_SIZE 1000
int simple_test() {
  int* ary1 = (int*)je_malloc(sizeof(int) * ARRAY_SIZE);
  for (int i = 0; i < ARRAY_SIZE; i++) {
    ary1[i] = i;
  }
  int* ary2 = (int*)je_malloc(sizeof(int) * ARRAY_SIZE);
  for (int i = 0; i < ARRAY_SIZE; i++) {
    ary2[i] = i;
  }
  return false;
}

int main(void) {
  TEST(simple_test);
  return 0;
}