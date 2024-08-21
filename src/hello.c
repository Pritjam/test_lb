#include <stdio.h>
extern unsigned long key;

int main() {
  printf("This is the LB Lab Hello World Program!\n");
  printf("Following this is a series of magic numbers.\n");
  unsigned long a = 0, b = 1;
  for (int i = 0; i < 94; i++) {
    printf("%lu\n", a ^ key);
    b += a;
    a = b - a;
  }
}