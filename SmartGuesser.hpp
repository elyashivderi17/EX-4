#include<iostream>
#include "Guesser.hpp"
using namespace std;
namespace bullpgia{
  class SmartGuesser: public bullpgia::Guesser{

    private :
    string MyGuess=""; 
    int index;
    int bull;
    bool flag;

    public :
    SmartGuesser();
    ~SmartGuesser(){}
    string guess() override;
    void startNewGame(uint length) override;

  };
};