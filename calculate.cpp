#include "calculate.hpp"

using std::string,std::to_string;
using namespace bullpgia;
#include <cstdlib>

string bullpgia::calculateBull_And_Cows(string choice, string guess) {
int Count_Pgia = 0; 
int Count_Bull =0;
    int size=choice.length();
         for (size_t i = 0; i < size; i++){
        for (size_t j = 0; j < size; j++)
        {
           if(choice[i] == guess[j]){
               if(i == j){
               Count_Pgia++;
               break;
               }
               else{
                Count_Bull++ ;        
             }
           }
        }
        
    }

string ans = to_string(Count_Pgia)+","+to_string(Count_Bull);

    return ans;
}
