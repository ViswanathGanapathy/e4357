//The Digital Output withoout MBED libraries

void delay(void);

#define FIO2DIR0 (*(volatile unsigned char *)(0x2009C040))
#define FIO2PIN0 (*(volatile unsigned char *)(0x2009C054))

int main(){
    
    FIO2DIR0 = 0xFF;
    while(1) {
        FIO2PIN0 |= 0x01;
        delay();
        FIO2PIN0 &= ~0x01;
        delay();
        }
    }
    
void delay(void){
    int j;
    for(j=0; j<2000000; j++)
    {
        j++;
        j--;
        }
    }
