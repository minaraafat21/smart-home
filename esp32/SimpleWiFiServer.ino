#include <WiFi.h>
#include <HTTPClient.h>


const char* ssid = ""; // wifi network name
const char* password = ""; // wifi password

const char* htmlServerUrl = "http://127.0.0.1:5500/index.html"; // External server URL for HTML file

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);  // Set the LED pin mode

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
    String request = client.readStringUntil('\r'); // Read the HTTP request
    client.flush();

    // Match the request and fetch the HTML file from the external server
    if (request.indexOf("GET / ") >= 0) {
      WiFiClientSecure secureClient;
      secureClient.setInsecure();  // Disable SSL certificate validation (useful for testing)

      HTTPClient http;
      http.begin(secureClient, htmlServerUrl);  // Specify the URL of the external server
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
      Serial.print("H");
    }
    if (request.indexOf("GET /L") >= 0) {
      digitalWrite(2, LOW);   // GET /L turns the LED off
      Serial.print("L");
    }
    if (request.indexOf("GET /O") >= 0) {
      Serial.print("O");
    }
    if (request.indexOf("GET /S") >= 0) {
      Serial.print("S");
    }
    if (request.indexOf("GET /W") >= 0) {
      Serial.print("W");
    }

    // Clear out any remaining input from the client to prevent the issue of repeated characters
    while (client.available()) {
      client.read();
    }

    // Close the connection
    client.stop();
  }
}
