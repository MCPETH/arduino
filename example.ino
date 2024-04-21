#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SH110X.h>
#include <Adafruit_GFX.h>


#define SCREEN_WIDTH 128 // pixel ความกว้าง
#define SCREEN_HEIGHT 64 // 
#define OLED_RESET     -1 //ขา reset เป็น -1 ถ้าใช้ร่วมกับขา Arduino reset

Adafruit_SH1106G OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



// ', 128x64px
const unsigned char mybitmap [] PROGMEM = {
	//bitmap here 
};


const int mybitmapallArray_LEN = 1;
const unsigned char* mybitmapallArray[1] = {
	mybitmap
};



void setup() {
  Serial.begin(9600);
  if (!OLED.begin()) { // Use default I2C address 0x3C
    Serial.println("OLED allocation failed");
  } else {
    Serial.println("OLED initialized");
  }
}

void loop() {
  OLED.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
  OLED.drawBitmap(3,3, mybitmap, 128, 64, SH110X_WHITE);
  OLED.setTextColor(SH110X_WHITE);  //กำหนดข้อความสีขาว
  OLED.display();
}
