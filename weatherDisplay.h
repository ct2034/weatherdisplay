bool updated; //wether there is new data
struct data { //to store the weather data
   char day;
   char wday;
   char stateCurrent;
   char stateDaily[7];
   signed int tempDaily[7];
   signed int tempHourly[8];
   int time;
};

void updateDisplay();

