#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;

string padWithZero(int num);
void copyStringToClipboard(string _string);

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
  copyStringToClipboard(finalString);
}

string padWithZero(int num) {
  string finalString;
  if (num < 10) finalString = "0" + to_string(num);
  else finalString = to_string(num);

  return finalString;
}

void copyStringToClipboard(string _string) {
  // Open the clipboard
  if (!OpenClipboard(NULL)) {
    cout << "Failed to open clipboard" << endl;
    system("PAUSE");
  }

  // Allocate memory for the string and copy it
  HGLOBAL clipBuffer = GlobalAlloc(GMEM_DDESHARE, 100);
  if (clipBuffer == NULL) {
    cout << "Failed to allocate memory for clipboard" << endl;
    CloseClipboard();
    system("PAUSE");
  }
  char* buffer = (char*)GlobalLock(clipBuffer);
  strcpy(buffer, _string.c_str());
  GlobalUnlock(clipBuffer);

  // Empty the clipboard and set the new data
  EmptyClipboard();
  SetClipboardData(CF_TEXT, clipBuffer);

  // Clean up and exit
  CloseClipboard();
  GlobalFree(clipBuffer);
}