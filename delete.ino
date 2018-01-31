

#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

uint8_t getFingerprintEnroll(uint8_t id);
uint8_t deleteFingerprint(uint8_t il);

SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);



void setup()  
{
  Serial.begin(9600);
  Serial.println("Delete Finger");

  finger.begin(57600);
  
  if (finger.verifyPassword()) 
  {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1);
  }
}

void loop()                  
{
  while (!Serial);  
  delay(500);

  Serial.println("Type in the ID # you want delete...");
  uint8_t id = 0;
  while (true) {
    while (! Serial.available());
    char c = Serial.read();
    if (! isdigit(c)) break;
    id *= 10;
    id += c - '0';
  }
  Serial.print("deleting ID #");
  Serial.println(id);
  
  deleteFingerprint(id);
}

uint8_t deleteFingerprint(uint8_t id) {
  uint8_t k = -1;
  
  k = finger.deleteModel(id);

  if (k == FINGERPRINT_OK) {
    Serial.println("Deleted!");
  } else if (k == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return k;
  } else if (k == FINGERPRINT_BADLOCATION) {
    Serial.println("Could not delete in that location");
    return k;
  } else if (k == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
    return k;
  } else {
    Serial.print("Unknown error: 0x"); Serial.println(k, HEX);
    return k;
  }   
}
