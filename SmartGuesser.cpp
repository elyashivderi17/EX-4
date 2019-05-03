#include <string>
#include "SmartGuesser.hpp"
using namespace std;
using namespace bullpgia;
// void bullpgia::SmartGuesser:: learn(string solutions) {

// return;
// }

SmartGuesser::SmartGuesser()
{

    // for(int i=0;i<this->length;++i)
    // {
    //     cout<<i<<endl;
    // this->MyGuess+="0";
    // }
}
string bullpgia::SmartGuesser::guess()
{
    // cout<<this->index<<" , "<<this->countBull<<endl;
    //    if(this->MyGuess[index]=='0')
    //     {
    //         ++this->index;
    //     }

    ///////////////////////////////////////////////////////////// cout<<"countBull="<<this->countBull<<endl<<"bull="<<this->bull<<endl;
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
        // else if(this->MyGuess[index]=='0')
        // {
        //     ++this->index;
        // }

        // if (this->MyGuess[index] == 57)        //////////maybe important
        // {
        //     ++this->index;
        //      this->flag = false;
        // }

        //////////////////////////////////////////////////////////  // cout<<"&&&&&&"<<MyGuess<<endl<<endl;
        // int temp=stoi(""+(&this->MyGuess)[index])+1;
        int temp = (this->MyGuess)[index] + 1;
        //  cout<<"============  "<<temp<<endl;
        // cout<<"============  "<<temp<<endl;
        this->MyGuess[index] = (char)temp;
        // cout<<"============  "<<MyGuess<<endl;

                                                                     // cout << "================" << MyGuess << endl
            
    }
    else
    {
        flag = true;
    }

    return MyGuess;
}
void bullpgia::SmartGuesser::startNewGame(uint length)
{
    // cout<<"Aaaaaaaaaaaa"<<endl;
    this->MyGuess = "";
    this->index = 0;
    this->bull = 0;
    this->countBull = 0;
    this->flag = false;
    this->length = length;
    for (int i = 0; i < this->length; ++i)
    {

        // cout<<i<<endl;
        this->MyGuess += "*";
        // cout<<this->MyGuess<<endl;
    }
}
