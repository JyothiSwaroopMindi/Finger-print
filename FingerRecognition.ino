

#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

uint8_t id;

uint8_t getFingerprintEnroll();
int getFingerprintIDez();
uint8_t deleteFingerprint(uint8_t il);


SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);



void setup()  
{
  while (!Serial);  
  delay(500);
  
  Serial.begin(9600);
 

  finger.begin(57600);
  
  if (finger.verifyPassword()) {
   // Serial.println("Found fingerprint sensor!");
  } else {
   // Serial.println("Did not find fingerprint sensor :(");
    while (1);
  }
}

uint8_t readnumber(void) {
  uint8_t num = 0;
  boolean validnum = false; 
  while (1) {
    while (! Serial.available());
    int c = Serial.read();
    if (isdigit(c)) {
       num *= 10;
       num += c - '0';
       validnum = true;
//} else if (validnum) { 
      return num;
    }
  }
}

void loop()                    
{

  if(Serial.available()){
    char data = Serial.read();
    switch(data){

    case 'e':
        id = readnumber();
        while (!  getFingerprintEnroll() );
        
        break;  
    case 'm':
        delay(3000);
        getFingerprintIDez();
        
        break;
        
    case 'd': 
        uint8_t il;
        il=readnumber();
        deleteFingerprint(il);
        break;
  }
  }

}

// for fingerprint matching
int getFingerprintIDez()
{
  uint8_t l = finger.getImage();
  if (l != FINGERPRINT_OK) 
  {
    Serial.println("Fingerprint not Recieved");
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
 // 
  Serial.print("Found FingerPrint with ID ");  
  Serial.println(finger.fingerID);
  //Serial.println(" with confidence of "); 
  //Serial.println(finger.confidence);
  return finger.fingerID; 
}



//for deleting fingerprint
uint8_t deleteFingerprint(uint8_t il) {
  uint8_t k = -1;
  
  k = finger.deleteModel(il);

  if (k == FINGERPRINT_OK) {
   // Serial.print("Deleted FingerPrint with ID ");
   // Serial.print(il);
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


//for enrolling fingerprint
uint8_t getFingerprintEnroll() {
  //Serial.println("Please place your Finger ");
  int p = -1;
  //Serial.print("Please keep your finger to enroll with "); 
  //Serial.println(id);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Done");
      break;
    case FINGERPRINT_NOFINGER:
      
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      break;
    default:
      Serial.println("Unknown error");
      break;
    }
  }

  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
      //Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  Serial.println("Remove finger");
  delay(3000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  //Serial.print("ID "); Serial.println(id);
  p = -1;
  Serial.println("Place same finger again");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      //Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      break;
    default:
      Serial.println("Unknown error");
      break;
    }
  }

  

  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      //Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  
  //Serial.print("Creating model for #");  Serial.println(id);
  
  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    Serial.println("Prints Matched!");
    Serial.print("Enrolled FingerPrint with ID ");
     Serial.println(id);
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } 
  else if (p == FINGERPRINT_ENROLLMISMATCH) {
    Serial.println("Fingerprints did not match");
    return p;
  }else {
    Serial.println("Unknown error");
    return p;
  }   
  
 // Serial.print("ID "); Serial.println(id);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
   // Serial.print("Enrolled Successful with id ");
    //Serial.println(id);
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("Could not store in that location");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
}
