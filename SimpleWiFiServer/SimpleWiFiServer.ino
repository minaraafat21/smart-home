// /*
//  WiFi Web Server LED Blink

//  A simple web server that lets you blink an LED via the web.
//  This sketch will print the IP address of your WiFi Shield (once connected)
//  to the Serial monitor. From there, you can open that address in a web browser
//  to turn on and off the LED on pin 5.

//  If the IP address of your shield is yourAddress:
//  http://yourAddress/H turns the LED on
//  http://yourAddress/L turns it off

//  This example is written for a network using WPA2 encryption. For insecure
//  WEP or WPA, change the Wifi.begin() call and use Wifi.setMinSecurity() accordingly.

//  Circuit:
//  * WiFi shield attached
//  * LED attached to pin 5

//  created for arduino 25 Nov 2012
//  by Tom Igoe

// ported for sparkfun esp32
// 31.01.2017 by Jan Hendrik Berlin

//  */

// #include <WiFi.h>

// const char *ssid = "mina,sara";
// const char *password = "samsung123";

// NetworkServer server(80);

// void setup() {
//   Serial.begin(115200);
//   pinMode(2, OUTPUT);  // set the LED pin mode

//   delay(10);

//   // We start by connecting to a WiFi network

//   Serial.println();
//   Serial.println();
//   Serial.print("Connecting to ");
//   Serial.println(ssid);

//   WiFi.begin(ssid, password);

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("");
//   Serial.println("WiFi connected.");
//   Serial.println("IP address: ");
//   Serial.println(WiFi.localIP());

//   server.begin();
// }

// void loop() {
//   NetworkClient client = server.accept();  // listen for incoming clients

//   if (client) {                     // if you get a client,
//     Serial.println("New Client.");  // print a message out the serial port
//     String currentLine = "";        // make a String to hold incoming data from the client
//     while (client.connected()) {    // loop while the client's connected
//       if (client.available()) {     // if there's bytes to read from the client,
//         char c = client.read();     // read a byte, then
//         Serial.write(c);            // print it out the serial monitor
//         if (c == '\n') {            // if the byte is a newline character

//           // if the current line is blank, you got two newline characters in a row.
//           // that's the end of the client HTTP request, so send a response:
//           if (currentLine.length() == 0) {
//             // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
//             // and a content-type so the client knows what's coming, then a blank line:
//             client.println("HTTP/1.1 200 OK");
//             client.println("Content-type:text/html");
//             client.println();

//             // the content of the HTTP response follows the header:
//             client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
//             client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 5 off.<br>");

//             // The HTTP response ends with another blank line:
//             client.println();
//             // break out of the while loop:
//             break;
//           } else {  // if you got a newline, then clear currentLine:
//             currentLine = "";
//           }
//         } else if (c != '\r') {  // if you got anything else but a carriage return character,
//           currentLine += c;      // add it to the end of the currentLine
//         }

//         // Check to see if the client request was "GET /H" or "GET /L":
//         if (currentLine.endsWith("GET /H")) {
//           digitalWrite(2, HIGH);  // GET /H turns the LED on
//         }
//         if (currentLine.endsWith("GET /L")) {
//           digitalWrite(2, LOW);  // GET /L turns the LED off
//         }
//       }
//     }
//     // close the connection:
//     client.stop();
//     Serial.println("Client Disconnected.");
//   }
// }
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "mina,sara";
const char* password = "samsung123";
const char* htmlServerUrl = "http://127.0.0.1:5500/finalProject/index.html"; // External server URL for HTML file

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);  // set the LED pin mode

  // Connect to Wi-Fi
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // Print a message out in the serial port
    String currentLine = "";                // Make a String to hold incoming data from the client
    String request = client.readStringUntil('\r'); // Read the HTTP request
    Serial.println(request);
    client.flush();

    // Match the request and fetch the HTML file from the external server
    if (request.indexOf("GET / ") >= 0) {
      HTTPClient http;
      http.begin(htmlServerUrl);  // Specify the URL of the external server
      int httpResponseCode = http.GET();  // Send the GET request

      if (httpResponseCode > 0) {
        String payload = http.getString();  // Get the response payload (HTML content)

        client.println("HTTP/1.1 200 OK");
        client.println("Content-type:text/html");
        client.println();

        // Send the fetched HTML to the client
        client.print(payload);
      } else {
        Serial.print("Error on HTTP request: ");
        Serial.println(httpResponseCode);
      }

      http.end();  // Close the connection
    }

    // Check to see if the client request was "GET /H" or "GET /L":
    if (request.indexOf("GET /H") >= 0) {
      digitalWrite(2, HIGH);  // GET /H turns the LED on
      Serial.println("LED ON");
    }
    if (request.indexOf("GET /L") >= 0) {
      digitalWrite(2, LOW);   // GET /L turns the LED off
      Serial.println("LED OFF");
    }
    if (request.indexOf("GET /T") >= 0) {
      digitalWrite(2, LOW);   // GET /L turns the LED off
      delay(1000);
      digitalWrite(2, HIGH);
      delay(1000); 
    }

    // Close the connection
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
