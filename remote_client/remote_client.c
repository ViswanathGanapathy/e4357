#include "EthernetNetIf.h"
#include "HTTPClient.h"

EthernetNetIf eth(
   IpAddr(192,168,0,101),   //IP Address
   IpAddr(255,255,255,0),   //Network Mask
   IpAddr(192,168,0,1),     //Gateway
   IpAddr(192,168,0,1)      //DNS
);

HTTPClient http;

HTTPText txt;

Serial pc (USBTX,USBRX);

int main() {

  pc.printf("\r\nSetting up network connection…\n\r");

  eth.setup();

  pc.printf("\r\nSetup OK. Querying data…\r\n");

  // attempt to access file ‘mbedclienttest.txt’ through the Internet…

  HTTPResult r=http.get("http://www.embeddedacademic.com/mbed/mbedclienttest.txt", &txt);

  pc.printf("Result :\n\r\"%s\"\n\r", txt.gets());
  } */
  
#include "mbed.h"
#include "EthernetNetIf.h"
#include "HTTPServer.h"
LocalFileSystem fs("webfs");

EthernetNetIf eth(
  IpAddr(192,168,0,101),        //IP Address
  IpAddr(255,255,255,0),        //Network Mask
  IpAddr(192,168,0,1),          //Gateway
  IpAddr(192,168,0,1)           //DNS
);

HTTPServer svr;

DigitalOut led1(LED1, "led1");         // define mbed object

int main() {
  Base::add_rpc_class<DigitalOut>();   // RPC base command
  eth.setup();                         // Ethernet setup
  FSHandler::mount("/webfs", "/");     // Mount /webfs path on root
  svr.addHandler<FSHandler>("/");      //Default handler
  svr.addHandler<RPCHandler>("/rpc");  // Define RPC handler
  svr.bind(80);

  while(1) {
    Net::poll();
  }
}
