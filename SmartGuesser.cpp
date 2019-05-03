#include <string>
#include "SmartGuesser.hpp"
using namespace std;
using namespace bullpgia;


SmartGuesser::SmartGuesser()
{

}
string bullpgia::SmartGuesser::guess()
{
    if (this->MyGuess[index] == '*')
    {
        this->MyGuess[index] = '0';
    }
    if (flag)
    {
        if (bull != this->countBull)
        {
            ++this->bull;
            ++this->index;
            this->flag = false;
            if (this->MyGuess[index] == '*')
            {
                this->MyGuess[index] = '0'-1;
            }
        }
       
        int temp = (this->MyGuess)[index] + 1;
        this->MyGuess[index] = (char)temp;            
    }
    else
    {
        flag = true;
    }
    return MyGuess;
}
void bullpgia::SmartGuesser::startNewGame(uint length)
{
    this->MyGuess = "";
    this->index = 0;
    this->bull = 0;
    this->countBull = 0;
    this->flag = false;
    this->length = length;
    for (int i = 0; i < this->length; ++i)
    {
        this->MyGuess += "*";
    }
}
