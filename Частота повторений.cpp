/*************************
* Автор: Базанов В.В. *
* Название: Вариант №1 *
*************************/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

int main() {
  ifstream file("filename.txt");
  string text;
  char ch;
  
  while (file.get(ch)) {
    text += ch;
  }

  file.close();

  map<char, int> letterCount;

  for (size_t index = 0; index < text.size(); ++index) {
    if (isalpha(text[index])) {
      char lowerChar = tolower(text[index]);
      letterCount[lowerChar]++;
    }
  }
  
  map<string, int> pairCount;

  for (size_t index = 0; index + 1 < text.size(); ++index) {
    if (isalpha(text[index]) && isalpha(text[index + 1])) {
      char firstChar = tolower(text[index]);
        char secondChar = tolower(text[index + 1]);
          string pair = "";
          pair += firstChar;
          pair += secondChar;
          pairCount[pair]++;
    }
  }

  cout << "Character frequencies:\n";
  for (pair <char, int> item : letterCount) {
    cout << item.first << ": " << item.second << endl;
  }

  cout << "Two-character frequencies:\n";
  for (pair <char, int> item : pairCount) {
    cout << item.first << ": " << item.second << endl;
  }

  return 0;

}

