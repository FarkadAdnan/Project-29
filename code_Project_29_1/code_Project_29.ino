/*
 By:Farkad Adnan
 E-mail: farkad.hpfa95@gmail.com
 inst : farkadadnan
 #farkadadnan , #farkad_adnan , فرقد عدنان#
 FaceBook: كتاب عالم الاردوينو
 inst : arduinobook
 #كتاب_عالم_الاردوينو  #كتاب_عالم_الآردوينو 
 */
 #include <Adafruit_TFTLCD.h> 
#include <Adafruit_GFX.h>    
#include <TouchScreen.h>

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

#define TS_MINX 204
#define TS_MINY 195
#define TS_MAXX 948
#define TS_MAXY 910

#define YP A2  
#define XM A3  
#define YM 8   
#define XP 9  
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
boolean buttonEnabled = true;
void setup() {
  Serial.begin(9600);
  Serial.print("Starting...");
  tft.reset();
  tft.begin(0x9325);
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  tft.drawRect(0,0,319,240,WHITE);
    tft.setCursor(100,30);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.print("Hello");
    tft.setCursor(80,100);
  tft.setTextColor(RED);
  tft.setTextSize(4);
  tft.print("YouTube!");
    tft.fillRect(60,180, 200, 40, RED);
  tft.drawRect(60,180,200,40,WHITE);
  tft.setCursor(80,188);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Subscribe!");
}
void loop() {
  TSPoint p = ts.getPoint();  //Get touch point 
  if (p.z > ts.pressureThreshhold) {
   Serial.print("X = "); Serial.print(p.x);
   Serial.print("\tY = "); Serial.print(p.y);
   Serial.print("\n");
   p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
   p.y = map(p.y, TS_MAXY, TS_MINY, 0, 240);
       
   if(p.x>60 && p.x<260 && p.y>180 && p.y<220 && buttonEnabled){
    buttonEnabled = false; //Disable button
        
   pinMode(XM, OUTPUT);
   pinMode(YP, OUTPUT);
        tft.fillScreen(BLACK);
        tft.drawRect(0,0,319,240,WHITE);
    
    tft.setCursor(50,50);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.print("Thank you for\n\n   subscribing!");
   }
   delay(10);  
  }
}
