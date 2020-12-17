
//Arduino: Ethernet UDP Receive Data Switch LED
#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

int Pin5 = 5;                                                // Switch Pin 5
int Pin6 = 6;                                                // Switch Pin 6
int Pin7 = 7;                                                // Switch Pin 7


byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

IPAddress ip(192, 168, 0, 51);  // Ardunio ip

unsigned int localPort = 49250;      // local port to listen on

EthernetUDP Udp;// An EthernetUDP instance to let us send and receive packets over UDP

IPAddress remoteIP(192, 168, 0, 52);
unsigned int remotePort = 49250;

byte content[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
void setup() {

  Serial.begin(19200);
  pinMode(Pin5, OUTPUT);                                     // attach the pin
  pinMode(Pin6, OUTPUT);                                     // attach the pin
  pinMode(Pin7, OUTPUT);                                     // attach the pin

  digitalWrite(Pin5, LOW);                                   // tell the pin to turn off
  digitalWrite(Pin6, LOW);                                   // tell the pin to turn off
  digitalWrite(Pin7, LOW);                                   // tell the pin to turn off

  Ethernet.begin(mac, ip);                                   // start the Ethernet and UDP:
  Udp.begin(localPort);
}
void loop() {

  byte packetSize = Udp.parsePacket();
  if (packetSize) {
    Serial.println(); +
    Serial.print("Recived packet of size");
    Serial.println(packetSize);
    Udp.read(content, UDP_TX_PACKET_MAX_SIZE);   // read the packet into packetBufffer
  }

  for (byte i = 0; i < 40 ; i++) //UDP_TX_PACKET_MAX_SIZE
  {
    Serial.print((byte)content[i], 16);
    Serial.print(" ");
  }


//   switch (    ) {

//case '0':                                                   // if 0 is sent via udp then do this -->>   BL Air off 4F10100
//  digitalWrite(Pin5, HIGH);                                   // Turn PinA Off
//  break;                                                      // end of case 0
// case '1':                                                   // if 1 is sent via udp then do this -->>  BL AIR on  4F101FF
 // digitalWrite(Pin5, LOW);                                  // Turn PinA On
 // break;                                                      // end of case 1


  //      case '2':                                                   // if 2 is sent via udp then do this -->>
  //        digitalWrite(Pin6, LOW);                                   // Turn PinB Off
  //        break;                                                      // end of case 2
  //      case '3':                                                   // if 3 is sent via udp then do this -->>
  //        digitalWrite(Pin6, HIGH);                                  // Turn PinB On
  //        break;                                                      // end of case 3
  //      case '4':                                                   // if 4 is sent via udp then do this -->>
  //      digitalWrite(Pin7, LOW);                                   // Turn PinC Off
  //       break;                                                      // end of case 4
  //     case '5':                                                   // if 5 is sent via udp then do this -->>
  //       digitalWrite(Pin7, HIGH);                                  // Turn PinC Off
  //        break;                                                      // end of case 5;
  //      default :                                                   // if recived info via udp and not found in the case do this -->>
  //        Serial.print("No Case Found for: ");                     // if case not found send info via serial
  //        Serial.print(ch);                                        // send udp info back to serial
  //        break;                                                      // end of case not found
  //    }
  //  }
  //
  delay(15);                                                 // waits 15ms for udp input wait ...
    }
//  }
            // end system run, but now loop and start
