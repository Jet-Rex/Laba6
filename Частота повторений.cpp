/*************************
* Автор: Базанов В.В. *
* Название: Вариант №1 *
*************************/

using namespace std;

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>

int main() {
  ifstream file("filename.txt");
  string text;
  char ch;
  
  while (file.get(ch)) {
    text += ch;
  }

  file.close();

  map<char, int> letterCount;

  for (size_t i = 0; i < text.size(); i++) {
    if (isalpha(text[i])) {
      char lowerChar = tolower(text[i]);
      letterCount[lowerChar]++;
    }
  }
  
  map<string, int> pairCount;

  for (size_t i = 0; i + 1 < text.size(); i++) {
    if (isalpha(text[i]) && isalpha(text[i + 1])) {
      char c1 = tolower(text[i]);
        char c2 = tolower(text[i + 1]);
          std::string pair = "";
          pair += c1;
          pair += c2;
          pairCount[pair]++;
    }
  }

  cout << "Частоты букв:\n";
  for (auto const& item : letterCount) {
    cout << item.first << ": " << item.second << endl;
  }

  cout << "Частоты двухбуквенных сочетаний:\n";
  for (auto const& item : pairCount) {
    cout << item.first << ": " << item.second << endl;
  }

  return 0;
}