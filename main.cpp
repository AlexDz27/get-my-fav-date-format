#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string padWithZero(int num);

// TODO: check my questions. then probably brush up the knowledge on pointers and stuff
int main() {
  // Get time
  time_t now = time(0);
  tm* nowStruct = localtime(&now);
  // Get appropriate values
  int year = nowStruct->tm_year + 1900;
  int month = nowStruct->tm_mon + 1;
  string monthStr = padWithZero(month);
  int day = nowStruct->tm_mday;
  string dayStr = padWithZero(day);
  int hours = nowStruct->tm_hour;
  string hoursStr = padWithZero(hours);
  int minutes = nowStruct->tm_min;
  string minutesStr = padWithZero(minutes);
  // Glue appropriate values together
  string finalString = to_string(year) + "-" + monthStr + "-" + dayStr + " " + hoursStr + ":" + minutesStr;

  cout << finalString << endl;
  system("PAUSE");
}

string padWithZero(int num) {
  string finalString;
  if (num < 10) finalString = "0" + to_string(num);
  else finalString = to_string(num);

  return finalString;
}