#include <string>
#include "calculate.hpp"
#include <iostream>

using namespace std;

string bullpgia::calculateBull_And_Cows(string x, string y)
{
    int bull = 0;
    int pgia = 0;
    for (int i = 0; i < x.length(); i++)
    {

        if (x[i] == y[i])
        {
            bull++;
            y[i] = x[i] = '/';
        }
    }
    if (bull != x.length())
    {
        for (int i = 0; i < x.length(); i++)
        {
            for (int j = 0; j < x.length(); j++)
            {
                if (x[i] != '/' && x[i] == y[j])
                {
                    pgia++;
                    y[j] = '/';
                    continue;
                }
            }
        }
    }
    string ans = to_string(bull);
    ans += ",";
    ans += to_string(pgia);


    return ans;
}