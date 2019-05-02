#include <string>
#include "SmartGuesser.hpp"
using namespace std;
using namespace bullpgia;
// void bullpgia::SmartGuesser:: learn(string solutions) {

// return;
// }

SmartGuesser::SmartGuesser()
{

    this->index = 0;
    this->bull = 0;
    // for(int i=0;i<this->length;++i)
    // {
    //     cout<<i<<endl;
    // this->MyGuess+="0";
    // }
}
string bullpgia::SmartGuesser::guess()
{
    ///////////////////////////////////////////////////////////// cout<<"countBull="<<this->countBull<<endl<<"bull="<<this->bull<<endl;
    if (bull != this->countBull)
    {
        ++this->bull;
        ++this->index;
    }
    if (this->MyGuess[index] == 57)
    {
        ++this->index;
    }

    //////////////////////////////////////////////////////////  // cout<<"&&&&&&"<<MyGuess<<endl<<endl;
    // int temp=stoi(""+(&this->MyGuess)[index])+1;
    int temp = (this->MyGuess)[index] + 1;
    //  cout<<"============  "<<temp<<endl;
    // cout<<"============  "<<temp<<endl;
    this->MyGuess[index] = (char)temp;
    // cout<<"============  "<<MyGuess<<endl;

    return MyGuess;
}
void bullpgia::SmartGuesser::startNewGame(uint length)
{
    // cout<<"Aaaaaaaaaaaa"<<endl;
    this->MyGuess = "";
    this->length = length;
    for (int i = 0; i < this->length; ++i)
    {
        
        // cout<<i<<endl;
        this->MyGuess += "0";
        cout<<this->MyGuess<<endl;
    }
}
