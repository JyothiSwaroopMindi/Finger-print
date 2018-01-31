


#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

int getFingerprintIDez();


SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()  
{
  while (!Serial);  
  
  Serial.begin(9600);
  Serial.println(" finger detect test");
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1);
  }
  Serial.println("Waiting for valid finger...");
  delay(1000); 
  getFingerprintIDez();
}

void loop()               
{
  
  //delay(500);          
}

uint8_t getFingerprintID() 
{
  uint8_t l = finger.getImage();
  switch (l) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return l;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return l;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return l;
    default:
      Serial.println("Unknown error");
      return l;
  }
l = finger.image2Tz();
  switch (l) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return l;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return l;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return l;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return l;
    default:
      Serial.println("Unknown error");
      return l;
  }
  l = finger.fingerFastSearch();
  if (l == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (l == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return l;
  } else if (l == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return l;
  } else {
    Serial.println("Unknown error");
    return l;
  }   
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 
}


int getFingerprintIDez()
{
  uint8_t l = finger.getImage();
  if (l != FINGERPRINT_OK) 
  {
    return -1;  
  }
  l = finger.image2Tz();
  if (l != FINGERPRINT_OK)  {
    Serial.println("Fingerprint not found");
    return -1; 
  }
  l = finger.fingerFastSearch();
  if (l != FINGERPRINT_OK)   {
    Serial.println("Fingerprint not found");
    return -1;  
  }
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
}
