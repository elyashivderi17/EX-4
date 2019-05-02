#include<iostream>
#include "Guesser.hpp"
using namespace std;
namespace bullpgia{
  class SmartGuesser: public bullpgia::Guesser{

    private :
    string MyGuess=""; 
    int index;
    int bull;

    public :
    SmartGuesser();
    // SmartGuesser(const string& temp){}
    ~SmartGuesser(){}
    // void learn(string solutions) override;
    string guess() override;
    void startNewGame(uint length) override;

  };
};