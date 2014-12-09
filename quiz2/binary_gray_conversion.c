#include <stdio.h>

typedef unsigned short uint16_t; 

uint16_t gray_to_binary(uint16_t gray)
{
  uint16_t bin = gray;

  printf("The gray code is %u \n", gray);
  while ((gray = gray >> 1) != 0) {
	bin = bin ^ gray;
    }
  printf("The binary value is %u\n", bin);
  return bin;
}
	
uint16_t binary_to_gray(uint16_t binary)
{
	uint16_t gray = (binary >> 1) ^ binary;
        printf("The binary value is %u\n", binary);
        printf("The gray code is %u \n", gray);

	return gray;
}

int main()
{
   uint16_t a, b, c;

   a = 3;
   b = gray_to_binary(a);
   c = binary_to_gray(a);
}
