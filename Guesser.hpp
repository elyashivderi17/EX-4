
#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
using std::string;

namespace bullpgia
{

class Guesser
{

public:
  unsigned int length;
  int countBull = 0;
  int countPgia = 0;

  virtual string guess() = 0;
  virtual void startNewGame(uint length)
  {
    this->length = length;
  };
  void learn(string results)
  {
    string delimiter = ",";
    string bull = results.substr(0, results.find(delimiter));
    string pgia = results.substr(results.find(delimiter) + 1);

    this->countPgia = stoi(pgia);

    this->countBull = stoi(bull);
  };
};

} // namespace bullpgia
