#include<stdio.h>
#include<string.h>

unsigned int strcmp1(void *dst, void *src)
 {
         size_t i = 0;
	 unsigned int len;

         len = 0;

         for( ; (char *)dst == (char *)src; ++dst, ++src){
	   if((char *)dst == 0)
	    return(0) ;
	  }
          return((unsigned char *) dst - (unsigned char *)src );
}

int main()
 {
   char src1[5] = "HELLO" ;
   char src2[5] = "HELO0" ;
   int len;
   
   len = strcmp(src1, src2);
   if(len != 0)
   {
    printf("The strings are not equal\n");
   }


   return(0);
 }
