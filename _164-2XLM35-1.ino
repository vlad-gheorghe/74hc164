const int clock = 3; //CP
const int data = 2;  //DAT
//int val;
float tensiune = 0.; // valoare tensiune
  int digit[] ={ B00000001, // right segment
                B00000010,
                B00000100,
                B00001000,
                B00010000,
                B00100000,
                B01000000,
                B10000000}; // left segment
                
  byte value[] ={  B00000011, // 0
                B10011111, // 1  
                B00100101, // 2
                B00001101, // 3
                B10011001, // 4
                B01001001, // 5
                B01000001, // 6
                B00011111, // 7
                B00000001, // 8
                B00001001, // 9
                B11111110, // dot
                B00111001, // grad
                B01100011, //C
                B11111111};// display nothing
 //byte value[dot]={B11111110};
byte d1[8]= {B00000001}; //ABCDEFG.
byte d2[8]= {B00000010};
byte d3[8]= {B00000100};
byte d4[8]= {B00001000};
byte d5[8]= {B00010000};
byte d6[8]= {B00100000};
byte d7[8]= {B01000000};
byte d8[8]= {B10000000};

byte zero[8]= {B00000011};
byte unu[8]= {B10011111};
byte doi[8]= {B00100101};
byte trei[8]= {B00001011};
byte patru[8]= {B10010010};
byte cinci[8]= {B10011001};
byte sase[8]= {B01000001};
byte sapte[8]= {B00011111};
byte opt[8]= {B00000001};
byte noua[8]= {B00001001};
byte gol[8]= {B11111111};
byte grad[8]= {B00111001};
byte C[8]= {B01100011};
byte dot[8]= {B11111110};

int trtensiune = 0;
float tensiune1 = 0.; // valoare tensiune
float sumatensiune1 = 0.;  

int trtensiune2 = 0;
float tensiune2 = 0.; // valoare tensiune
float sumatensiune2 = 0.;  
                
 void setup() {
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
   shiftOut(data,clock,MSBFIRST,B11111111);
  shiftOut(data,clock,MSBFIRST,B00000000);

  
 }
/*void loop() {
 shiftOut(data,clock,LSBFIRST,B10011111);// 1 SEGMENT STINS X,DP,G,F, E,D,C,A//ABCDEFGdp
  shiftOut(data,clock,LSBFIRST,B11111110);// 1 DIGIT ACTIV
delay(2500);
shiftOut(data,clock,MSBFIRST,B11111111);
  shiftOut(data,clock,MSBFIRST,B00000000);
shiftOut(data,clock,LSBFIRST,B10011101);// 1 SEGMENT STINS X,DP,G,F, E,D,C,A//ABCDEFGdp
  shiftOut(data,clock,LSBFIRST,B11111100);// 1 DIGIT ACTIV
  delay(2500);
}
*/
void loop(){
 
  
 //float tensiune = 32.4;


//shiftOut(data,clock,MSBFIRST,B11111111);
 // shiftOut(data,clock,MSBFIRST,B00000000);
 // delay(1);

 

trtensiune = analogRead(A0);
float mv = (  trtensiune/1024.0)*5000; 
  float celsius = mv/10;

  float tensiune = celsius;

trtensiune2 = analogRead(A1);
float mv2 = (  trtensiune2/1024.0)*5000; 
  float celsius2 = mv2/10;

  float tensiune2 = celsius2;

int tensiune_100 = tensiune * 100;
 
  int first_digit = tensiune_100 / 10000;
  int rem_after_first = tensiune_100 % 10000;
 
  int second_digit = rem_after_first / 1000;
  int rem_after_second = rem_after_first % 1000; 
 
  int third_digit = rem_after_second / 100;
  int rem_after_third = rem_after_second % 100; 
 
  int forth_digit = rem_after_third / 10;
  int rem_after_forth = rem_after_third % 10; 
 
  int fifth_digit = rem_after_forth / 1;
  int rem_after_fifth = rem_after_forth % 1; 

int tensiune2_100 = tensiune2 * 100;
 
  int first_digit2 = tensiune2_100 / 10000;
  int rem_after_first2 = tensiune2_100 % 10000;
 
  int second_digit2 = rem_after_first2 / 1000;
  int rem_after_second2 = rem_after_first2 % 1000; 
 
  int third_digit2 = rem_after_second2 / 100;
  int rem_after_third2 = rem_after_second2 % 100; 
 
  int forth_digit2 = rem_after_third2 / 10;
  int rem_after_forth2 = rem_after_third2 % 10; 
 
  int fifth_digit2 = rem_after_forth2 / 1;
  int rem_after_fifth2 = rem_after_forth2 % 1; 

// shiftOut(data,clock, LSBFIRST, tensiuneone);
//  shiftOut(data,clock, LSBFIRST,B10000000);
 // delay(50);
int i;
 for (i=50;i>0;--i)
 {
  //}
  shiftOut(data,clock, LSBFIRST, value[second_digit]); //delay(5);//NR
  shiftOut(data,clock, LSBFIRST, digit[3]);
  delay(2);
// delayMicroseconds(4000);
  shiftOut(data,clock, LSBFIRST, value[third_digit]); //delay(5);//NR
  shiftOut(data,clock, LSBFIRST, digit[2]);
  delay(2);
 // delayMicroseconds(4000);
   shiftOut(data,clock, LSBFIRST, value[10]); //delay(5);//NR
  shiftOut(data,clock, LSBFIRST, digit[2]);
  delay(2);
 // delayMicroseconds(4000);
  
  shiftOut(data,clock, LSBFIRST, value[forth_digit]); //delay(5);//NR
  shiftOut(data,clock, LSBFIRST, digit[1]);
  delay(2);
 // delayMicroseconds(4000);
  shiftOut(data,clock, LSBFIRST, value[fifth_digit]); //delay(5); //DIGIT
  shiftOut(data,clock, LSBFIRST,digit[0]);
  delay(2);
 // delayMicroseconds(4000);
  // shiftOut(data,clock, LSBFIRST, B00001111);
 // shiftOut(data,clock, LSBFIRST,B01000000);
 // delay(5);
 
  shiftOut(data,clock, LSBFIRST, value[second_digit2]); //delay(5);//NR
  shiftOut(data,clock, LSBFIRST, digit[7]);
  delay(2);
 // delayMicroseconds(7000);
  shiftOut(data,clock, LSBFIRST, value[third_digit2]); //delay(5);//NR
  shiftOut(data,clock, LSBFIRST, digit[6]);
  delay(2);
 // delayMicroseconds(7000);
   shiftOut(data,clock, LSBFIRST, value[10]); //delay(5);//NR
  shiftOut(data,clock, LSBFIRST, digit[6]);
  delay(2);
 // delayMicroseconds(7000);
  //shiftOut(data,clock, LSBFIRST, B00100101); //delay(5); //DIGIT
  //shiftOut(data,clock, LSBFIRST,B01000000);
 // delay(8);
  shiftOut(data,clock, LSBFIRST, value[forth_digit2]); //delay(5);//NR
  shiftOut(data,clock, LSBFIRST, digit[5]);
  delay(2);
 // delayMicroseconds(7000);
  shiftOut(data,clock, LSBFIRST, value[fifth_digit2]); //delay(5); //DIGIT
  shiftOut(data,clock, LSBFIRST,digit[4]);
  delay(2);
  //delayMicroseconds(7000);

}
}

