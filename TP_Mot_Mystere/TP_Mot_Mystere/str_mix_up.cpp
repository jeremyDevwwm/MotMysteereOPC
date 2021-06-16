//
//  str_mix_up.cpp
//  TP_Mot_Mystere
//
//  Created by Dijoux Jérémy on 16/06/2021.
//

#include "str_mix_up.hpp"
#include <string>
#include <vector>
#include <random>
using namespace std;

string stringMixUp(string response){
    vector<char> splittedStr(response.size());
    
    for(int i = 0; i<response.size(); i++){
        splittedStr[i] = response[i];
    }
    
    shuffle(splittedStr.begin(), splittedStr.end(), std::default_random_engine());
    string finalVal(splittedStr.begin(), splittedStr.end());
    
    return finalVal;
   
}
