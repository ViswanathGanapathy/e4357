#include "mbed.h"
#include "EthernetInterface.h"
//#include "HTTPClient.h"

EthernetInterface eth;
//HTTPClient http;
char stream[1000];

int main() {
    EthernetInterface eth;
    int ret1;
    
    ret1 = eth.init(); //Use DHCP
    
    if (ret1 == 0) {
        printf("Ethernet Connection successful...\n");
    }
    else {
        printf("***ERROR: could not establish ethernet connection: return status= %d\n", ret1);
    }
    
    eth.connect();
    printf("IP Address is %s\n", eth.getIPAddress());
 /*   printf("\r\nConnection OK, quering data...\n\r");
    HTTPResult r=http.get("http://www.embeddedacademic.com/mbed/mbedclienttest.txt", stream, 1000, 30000);
    if (r == HTTP_OK) {
        printf("Read %d characters\n", strlen(stream));
        printf("Result :\n\r\"%s\"\n\r", stream);
    }
    else {
        printf("Error r= %d, HTTP return code= %d\n", r, http.getHTTPResponseCode());
    } */
    TCPSocketConnection sock;
    sock.connect("mbed.org", 80);
    
    char http_cmd[] = "GET /media/uploads/mbed_official/hello.txt HTTP/1.0\n\n";
    sock.send_all(http_cmd, sizeof(http_cmd)-1);
    
    char buffer[300];
    int ret;
    while (true) {
        ret = sock.receive(buffer, sizeof(buffer)-1);
        if (ret <= 0)
            break;
        buffer[ret] = '\0';
        printf("Received %d chars from server:\n%s\n", ret, buffer);
    }
    Serial pc(USBTX, USBRX);
    sock.close();
    
    eth.disconnect();
    
    while(1) {}
}

