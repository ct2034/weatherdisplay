// My fucking amazing weather display
#include "T6963.h"
//#include <ArduinoJson.h>
#include <Time.h>  

#include "weatherDisplay.h"
#include "pix.h"
#include "Tahoma_6.h"

#include "examples.h"

#define CONTRAST_PIN 11

T6963 LCD(160,128,8,32);
data latestData;

void setup(){
  pinMode(CONTRAST_PIN, OUTPUT);
  analogWrite(CONTRAST_PIN, 127);  
  delay(100);
  
  LCD.Initialize(true);
  LCD.DefineCharacter(140, (unsigned char *) deg);

  LCD.TextGoTo(6,7);
  LCD.writeString("Wetter?!"); 
  delay(500);

  Serial.begin(9600);
  Serial.println("init..");
  
  updated = true;
}

void loop(){
  parseJson();
  delay(100);
  
  if(updated){  
    updateDisplay();  
    updated = false;
  }  
}

void updateDisplay(){
  LCD.clearText();
  LCD.clearGraphic(); 

  // TODAY
  LCD.TextGoTo(0,0);
  LCD.drawPic(checkWidth(latestData.tempHourly[0])*8, 4*8, (prog_uchar*) deg, 8, 1 );
  // icon
  LCD.drawPic(8, 8, (prog_uchar*) icons[latestData.stateCurrent], 16, 2 );
  
  // temp
  char str[5];
  sprintf(str, "%d C", latestData.tempHourly[0]);
  LCD.TextGoTo(0,4);
  LCD.writeString(str);
  // date
  sprintf(str, "%s%2d", wdays[latestData.wday], latestData.day);
  LCD.TextGoTo(0,5);
  LCD.writeString(str);

  // BORDERS
  LCD.createLine(5*8-1, 0, 5*8-1, 7*8-1, 1);
  LCD.createLine(5*8-1, 7*8-1, 0, 7*8-1, 1);

  // +1 DAY
  LCD.glcd_print1_P(0, 0, "Mo", &Tahoma__6, 0);

  // icon
  LCD.drawPic(7*8, 0, (prog_uchar*) d3, 16, 2 );  

  // +2 DAY

  // icon
  LCD.drawPic(11*8, 0, (prog_uchar*) d9, 16, 2 );  

  // +3 DAY

  // icon
  LCD.drawPic(15*8, 0, (prog_uchar*) d10, 16, 2 );  

  // +4 DAY

  // icon
  LCD.drawPic(7*8, 4*8, (prog_uchar*) d11, 16, 2 );  

  // +5 DAY

  // icon
  LCD.drawPic(11*8, 4*8, (prog_uchar*) d13, 16, 2 );  

  // +6 DAY

  // icon
  LCD.drawPic(15*8, 4*8, (prog_uchar*) d50, 16, 2 );  


  // HOURLY
  signed int minim = latestData.tempHourly[0];
  signed int maxim = latestData.tempHourly[0];
  for (int i = 1; i<8; i++)
  {
    if (latestData.tempHourly[i] < minim) minim = latestData.tempHourly[i];
    if (latestData.tempHourly[i] > maxim) maxim = latestData.tempHourly[i];  
  }
  int d = (maxim-minim)/6;
  if (d<2) { // not filled
    d = 2;
  }
  else // filled
  {
    
  }

  //yaxis
  LCD.TextGoTo(0,8);
  char strma[5];
  sprintf(strma, "%d", maxim);  
  LCD.writeString(strma);
  LCD.TextGoTo(0,11);
  char strmid[5];
  sprintf(strmid, "%d", minim+(maxim-minim)/2);  
  LCD.writeString(strmid);
  LCD.TextGoTo(0,14);
  char strmi[5];
  sprintf(strmi, "%d", minim);
  LCD.writeString(strmi);
  
  //xaxis
  LCD.TextGoTo(2,15);
  char strtime[5];
  sprintf(strtime, "%d:00", latestData.time);
  LCD.writeString(strtime);
  LCD.TextGoTo(10,15);
  char strtimem[5];
  sprintf(strtimem, "%d:00", (latestData.time+12)%24);
  LCD.writeString(strtimem);
    
  //grid
  for(int i=8*8+3; i<120; i+=8){
    for(int j=8*4; j<159; j+=17){
      LCD.writePixel(j,i,1);
    } 
  }
  
  //graph
  int dy = maxim-minim/6;
  int oldy = yFromTemp(latestData.tempHourly[0], minim, maxim);
  int nexty;
  for(int i=1; i<=7; i++){
    int j = (1+i)*17-2;
    nexty = yFromTemp(latestData.tempHourly[i], minim, maxim);
    LCD.createLine(j,oldy,j+17,nexty,1);
    oldy=nexty;
  }

  delay(1000);
}

char checkWidth(int num){
  if (num<=-10) return 3;
  if (num<=-1) return 2;
  if (num<=9) return 1;
  else return 2;
}

char yFromTemp(int temp, int min, int max){
  float dy = 8*6.0/(max-min);
  int dtemp = temp-min;
  return 15*8-5-(dtemp*dy);
}

char iconFromDString(char* in){
  if(strcmp(in, "01d")  == 0) return 0;
  else if(strcmp(in, "\"02d\"")  == 0) return 1;
  else if(strcmp(in, "\"03d\"")  == 0) return 2;
  else if(strcmp(in, "\"04d\"")  == 0) return 3;
  else if(strcmp(in, "\"09d\"")  == 0) return 4;
  else if(strcmp(in, "\"10d\"")  == 0) return 5;
  else if(strcmp(in, "\"11d\"")  == 0) return 6;
  else if(strcmp(in, "\"13d\"")  == 0) return 7;
  else if(strcmp(in, "\"50d\"")  == 0) return 8;
  else return 9; //d99
}

void parseJson(){
  // parsing current conditions
  // ... ... ...  
  char* lastFind;
  char* temp = "      "; //5
  lastFind = findAParameter(current, temp, "\"temp\"");
  int iTemp = atoi(temp);
  
  char* date = "          "; //10
  lastFind = findAParameter(lastFind, date, "\"dt\"");
  setTime(atoi(date));
  int iDay = day(); 
  int iWday = weekday();
  
  char* state = "     "; //5
  lastFind = findAParameter(lastFind, state, "\"icon\"");
  int iState = iconFromDString(state);
  
  // parsing daily conditions
  // ... ... ...  
  
  latestData = {
    // day
    iDay,
    // weekday
    iWday,
    // weather
    iState,
    {
      1,2,3,4,5,6,7}
    ,{
      22,23,24,23,23,23,18}
    ,{
      iTemp,24,23,15,12,13,12,15}
    ,16
  };
  
  delay(1000);
}

char* findAParameter(char* input, char* output, char* search){
  char* findStr = strstr(input, search);
  char* lastFind = findStr+sizeof(search)+5;
  strncpy(output, lastFind, strlen(output));
  
  //DEBUG
  Serial.print(">");
  Serial.print(search);
  Serial.print("<-->");
  Serial.print(output);
  Serial.print("<\n");
  
  return lastFind;
}

int plusDay(int in){
  return 3;
}
