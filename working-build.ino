

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
int data = 0;
int data2 = 0;
int buttonstate = 0;

//feed back rescorse
const int greenled = 7;
const int redled = 8;
const int vibe = 9;
const int piezo = 10;
const int alarm = 11;

//display pin a4-a5 hex address ox3c

//input for button
const int upbutton = 2;
const int downbutton = 3;
const int leftbutton = 4;
const int rightbutton = 5;
const int enterbutton = 6;



// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  
  pinMode(greenled, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(vibe, OUTPUT);
  pinMode(piezo, OUTPUT);
  pinMode(alarm, OUTPUT);


  pinMode(upbutton, INPUT);
  pinMode(downbutton, INPUT);
  pinMode(leftbutton, INPUT);
  pinMode(rightbutton, INPUT);
  pinMode(enterbutton, INPUT);
  
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
Logo(); // calls boot logo
}

void loop() {
 
  checkbutton();
 if (data == 3){
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  // Display static text
  display.println("3 Enterd");
  display.display(); 
  vibebuzz();
  delay(2000);
  display.clearDisplay();
  display.display();
  data = 0;
  
 }
  
}


void Logo(){ //runs boot logo
  display.clearDisplay();

  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  // Display static text
  display.println("Solar  Station");
  display.display(); 
  delay(2000);
  display.clearDisplay();
  display.display();
}


void checkbutton(){


// up button----------------------------------
  buttonstate = digitalRead(upbutton);

  // check if upbutton is pressed
  if (buttonstate == LOW) {
    data++;
     display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  // Display static text
  display.println(data);
  display.display(); 
  delay(1000);
  display.clearDisplay();
  display.display();
  }

//-----------------------------------------------

//down button-----------------------------------------------
buttonstate = digitalRead(downbutton);

  // check if upbutton is pressed
  if (buttonstate == LOW) {
     display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  // Display static text
  display.println("Down Button");
  display.display(); 
  delay(1000);
  display.clearDisplay();
  display.display();
  digitalWrite(alarm,HIGH);
  delay(50);
  digitalWrite(alarm,LOW);
  }

//-------------------------------------------

//left button-------------------------------------------------
buttonstate = digitalRead(leftbutton);

  // check if upbutton is pressed
  if (buttonstate == LOW) {
     display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  // Display static text
  display.println("Left Button");
  display.display(); 
  delay(1000);
  display.clearDisplay();
  display.display();
  }
//----------------------------------------------------------------------------


//right button -------------------------------------------------------

buttonstate = digitalRead(rightbutton);

  // check if upbutton is pressed
  if (buttonstate == LOW) {
     display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  // Display static text
  display.println("right Button");
  display.display(); 
  delay(1000);
  display.clearDisplay();
  display.display();
  }

//---------------------------------------------------------------------------------



// enter button-----------------------------------------
buttonstate = digitalRead(enterbutton);

  // check if upbutton is pressed
  if (buttonstate == LOW) {
     display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  // Display static text
  display.println("Enter Button");
  display.display(); 
  delay(1000);
  display.clearDisplay();
  display.display();
  }


}


void vibebuzz(){

digitalWrite(vibe,HIGH);
  delay(100);
  digitalWrite(vibe,LOW);
  delay(100);
  digitalWrite(vibe,HIGH);
  delay(100);
  digitalWrite(vibe,LOW);
  delay(100);
  
  

  
}
  
