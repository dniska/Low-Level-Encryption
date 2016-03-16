#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/** Converts letter 
 *  by +13 chars
 **/
void ROT13(char& ch) {

  if(ch >= 78 && ch <= 90)
    ch = (ch + 13) - 26;
  else if (ch >= 110 && ch <= 122)
    ch = (ch + 13) - 26;
  else
    ch = ch + 13;
}

/** Converts digit 
 *  by +5 digits
 **/
void ROT5(char& ch) {

  if(ch >= 53 && ch <= 57)
    ch = (ch + 5) - 10;
  else
    ch = ch + 5;
}

/** Does nothing
 *  to special chars
 **/
void ROT0(char& ch) {

  ch = ch + 0;
}
/** Checks whether char 
 *  or digit
 */
void charRecognition(char& ch) {

  if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) //Letter, uppercase and lowercase
    ROT13(ch);
  else if(ch >= 48 && ch <= 57) //Digit
    ROT5(ch);
  else if((ch >= 32 && ch <= 47) && (ch >= 58 && ch <= 64) && (ch >= 91 && ch <= 96) && (ch >= 123 && ch <= 126)) //Special chars
    ROT0(ch);
}
int main() {

  string str;
  string input;

  cout << "Enter a string: ";
  getline(cin, str);

  for_each(str.begin(), str.end(), charRecognition);
  cout << "Converted string is now: " << str << endl;
}
