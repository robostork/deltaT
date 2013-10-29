char* mon[] = {"JAN", "FEB", "MAR", "APR",
                  "MAY", "JUN", "JUL", "AUG",
                  "SEP", "OCT", "NOV", "DEC"};
char* weekd[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

void basicdigital() {
  display.fillScreen(WHITE);
  int h = hourFormat12();
  int m = minute();
  int s = second();
  
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(2,2);
  display.print(weekd[weekday()-1]);
  display.setCursor(2,19);
  display.print(mon[month()-1]);
  display.setCursor(2,36);
  display.print(day());
  display.setCursor(2,53);
  display.print(year());
  
  if(h >= 10) {
    placeNum(2, h,51,3,4);
  } else {
    placeNum(2, h,75,3,4);
  }
  
  if(m >= 10) {
    placeNum(2, m,51,34,4);
  } else {
    placeNum(2, m,75,34,4);
  }
  
  if(s >= 10) {
    placeNum(2, s,51,65,4);
  } else {
    placeNum(2, s,75,65,4);
  }
  
  display.refresh();
}

void placeNum(int s, int num, int x, int y, int siz) {
  char buf[s+1];
  
  itoa(num, buf, 10);
  
  for(int i = 0; i < s; i++) {
    display.drawChar(x+(6*siz)*i,y,buf[i], BLACK, WHITE, siz);
  }
}

void blank() {
  display.fillScreen(WHITE);
  display.refresh();
}
