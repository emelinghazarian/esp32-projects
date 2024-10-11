#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Emelin";
const char* password = "23232323";

WebServer server(80);//Creates an instance of the WebServer class listening on port 80, which is the default port for HTTP.


void handleRoot() {
  server.send(200, "text/html", "<h1>Hello World</h1>"); //will handle HTTP requests to the root URL ("/").
  //Sends an HTTP response with a status code of 200 (OK), content type "text/html", and body "<h1>Hello World</h1>". This will display "Hello World" in a heading when accessed via a web browser.
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  
  Serial.println("Connected!");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);//Registers the handleRoot function to handle HTTP GET requests to the root URL ("/").
  // When the root URL is accessed, handleRoot is called.
  

  server.begin();// allowing it to listen for incoming HTTP requests.
  Serial.println("HTTP server started");
}


void loop() {
  // put your main code here, to run repeatedly:
   server.handleClient();
   //Handles incoming client requests. This function checks if a client has made a request to the server and processes it accordingly.

}
