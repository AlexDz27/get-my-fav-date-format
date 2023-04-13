#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// TODO: check my questions. then probably brush up the knowledge on pointers and stuff
int main() {
  // Get time
  time_t now = time(0);
  tm* nowStruct = localtime(&now);
  // Get appropriate values
  int year = nowStruct->tm_year + 1900;
  int month = nowStruct->tm_mon + 1;
  string monthStr;
  if (month < 10) monthStr = "0" + to_string(month);
  else monthStr = to_string(month);
  int day = nowStruct->tm_mday;
  string dayStr;
  if (day < 10) dayStr = "0" + to_string(day);
  else dayStr = to_string(day);
  int hours = nowStruct->tm_hour;
  string hoursStr;
  if (hours < 10) hoursStr = "0" + to_string(hours);
  else hoursStr = to_string(hours);
  int minutes = nowStruct->tm_min;
  string minutesStr;
  if (minutes < 10) minutesStr = "0" + to_string(minutes);
  else minutesStr = to_string(minutes);
  // Glue appropriate values together
  string finalString = to_string(year) + "-" + monthStr + "-" + dayStr + " " + hoursStr + ":" + minutesStr;

  cout << finalString << endl;
  system("PAUSE");
}