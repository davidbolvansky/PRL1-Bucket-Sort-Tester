#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte_t;

int main(void) {
  FILE *input = fopen("numbers", "rb");
  fseek(input, 0L, SEEK_END);
  size_t count = ftell(input);
  fseek(input, 0L, SEEK_SET);

  byte_t * numbers = (byte_t *)malloc(sizeof(byte_t) * count);
  size_t n = fread(numbers, sizeof(byte_t), count, input);
  fclose(input);

  for (size_t i = 0; i < n; i++)
    printf((i < n - 1) ? "%u " : "%u\n", numbers[i]);

  std::sort(numbers, numbers + n);

  for (size_t i = 0; i < n; i++)
    printf("%u\n", numbers[i]);

  free(numbers);
  return 0;
}