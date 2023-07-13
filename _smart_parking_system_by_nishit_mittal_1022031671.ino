#include<LiquidCrystal.h> 
#include<Servo.h> 

Servo S1,S2; //Objects of servo type

#define IR_Slot1 7 //Define pins
#define IR_Slot2 8
#define IR_entry 6
#define IR_exit 13

int pos=0; //Initial position of servo motor
//initialize the library with nos of interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  
  S1.attach(10);
  S2.attach(9);
  
  S1.write(pos);//Initial pos at 0 for both motors
  S2.write(pos);
  
  pinMode(IR_Slot1, INPUT);
  pinMode(IR_Slot2, INPUT);
  pinMode(IR_entry, INPUT);
  pinMode(IR_exit, INPUT);
  
  
  lcd.begin(16,2); //Initialize the 16x2 lcd
  
  //Print headline to the LCD
  lcd.print(" Smart  Parking");
  lcd.setCursor(0, 1); //Set cursor to col 1, row 2
  lcd.print("     System");
  delay(2000);
  lcd.clear(); //To clear the lcd screen
  lcd.setCursor(0, 0);
  lcd.print("Slot 1 = Avail");
  lcd.setCursor(0, 1);
  lcd.print("Slot 2 = Avail");
  delay(2000);
}

void loop()
{
  if(digitalRead(IR_Slot1)==HIGH)
  {
    lcd.setCursor(0, 0);
    lcd.print("Slot 1 = N.Ava");//when car is parked in slot 1
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("Slot 1 = Avail");
  }
  if(digitalRead(IR_Slot2)==HIGH)
  {
    lcd.setCursor(0, 1);
    lcd.print("Slot 2 = N.Ava");//when car is parked in slot 2
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print("Slot 2 = Avail");
  }
  
  if(digitalRead(IR_entry)==HIGH)
  {
    S1.write(pos+90); //The barrier will lift up if car enters
  }
  else
  {
    S1.write(pos);
  }
  
  if(digitalRead(IR_exit)==HIGH)
  {
    S2.write(pos+90); //The barrier will lift up if car exits
  }
  else
  {
    S2.write(pos);
  }
  if(digitalRead(IR_Slot1)==HIGH&&digitalRead(IR_Slot2)==HIGH)
  {
    lcd.clear();
    lcd.print("Parking FULL!!");
    delay(2000);
    
  }
}
  