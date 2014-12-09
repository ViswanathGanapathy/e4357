/*#include "mbed.h"
#include "EthernetInterface.h"
#include "HTTPClient.h"
#include "HTTPText.h"

EthernetInterface eth;
HTTPClient http;
char stream[1000];

DigitalOut myled(LED1);

int main() {
    EthernetInterface eth;
    HTTPClient http;
    char stream[1000];
     
    //int ret = eth.init("192.168.0.101", "255.255.255.0", "192.168.0.1");
    int ret = eth.init();
    if (ret == 0) {
        printf("Ethernet Connection successful...\n");
    }
    else {
        printf("***ERROR: could not establish ethernet connection: return status= %d\n", ret);
    }
    
    Serial pc(USBTX, USBRX);
    
    pc.printf("\r\nSetting up network connection...\n\r");
    ret = eth.connect();
    if (ret == 0) {
        printf("Ethernet Connection successful...\n");
    }
    else {
        printf("***ERROR: could not establish ethernet connection: return status= %d\n", ret);
    }
    pc.printf("\r\nConnection OK, quering data...\n\r");
    HTTPResult r=http.get("http://www.embeddedacademic.com/mbed/mbedclienttest.txt", stream, 1000, 30000);
    if (r == HTTP_OK) {
        printf("Read %d characters\n", strlen(stream));
        pc.printf("Result :\n\r\"%s\"\n\r", stream);
    }
    else {
        printf("Error r= %d, HTTP return code= %d\n", r, http.getHTTPResponseCode());
    }
} */
#include "mbed.h"
#include "EthernetNetIf.h"
#include "HTTPClient.h"
 
EthernetNetIf eth;
HTTPClient http;
  
int main() {
 
  printf("Setting up...\n");
  EthernetErr ethErr = eth.setup();
  if(ethErr)
  {
    printf("Error %d in setup.\n", ethErr);
    return -1;
  }
  printf("Setup OK\n");
  
  HTTPText txt;
  
  HTTPResult r = http.get("http://mbed.org/media/uploads/donatien/hello.txt", &txt);
  if(r==HTTP_OK)
  {
    printf("Result :\"%s\"\n", txt.gets()); 
  }
  else
  {
    printf("Error %d\n", r);
  }
  
  while(1)
  {
  
  }
  
  return 0;
  
}
