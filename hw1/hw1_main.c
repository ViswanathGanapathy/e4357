#include<stdio.h>
#include<string.h>

void *memcpy(void *dst, const void *src, size_t len)
 {
         size_t i;
 
         if ((((size_t)dst % sizeof(long)) == 0) && (((size_t)src % sizeof(long)) == 0) && (len % sizeof(long) == 0)) {
                 long *d = dst;
                 const long *s = src;
 
                 for (i=0; i<len/sizeof(long); i++) {
                         d[i] = s[i];
                 }
         }
         else {
                 char *d = dst;
                 const char *s = src;
 
                 for (i=0; i<len; i++) {
                         d[i] = s[i];
                }
         }

         return dst;
}

int main()
 {
   char src[5] = "HELLO" ;
   char dst[5];

   memcpy(dst, src, strlen(src));

   return(0);
 }
