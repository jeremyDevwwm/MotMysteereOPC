//
//  gameLoop.cpp
//  TP_Mot_Mystere
//
//  Created by Dijoux Jérémy on 16/06/2021.
//

#include "gameLoop.hpp"
#include <string>
#include <iostream>
#include "str_mix_up.hpp"

using namespace std;

bool game (true);

string response;
string displayedWord;
string submittedValue;

int choice;
int rematch;


void gameplay(){
    displayedWord = stringMixUp(response);
    bool goodAnswer(false);
    int trys(0);
    do {
        ++trys;
        cout << "Quel est ce mot ? " << displayedWord << endl;
        cin >> submittedValue;
        if(submittedValue == response){
            if(trys==1){
                cout << "Quel talent ! Tu dois être un génie du scrabble !" << endl;
                goodAnswer=true;
            } else {
                cout << "Bien joué ! Tu as trouvé le mot mystère en : " << trys << " essais !" <<endl;
                goodAnswer=true;
            }
        } else {
            cout << "Ce n'est pas le mot !" << endl;
        }
    } while(!goodAnswer);
    
}


void gameLoop(){
    cout << "Bienvenue dans Mot Mystère !"<< endl;
    cout << "################################" << endl;
    cout << "Joueur 1, veuillez entrer le mot mystère !" << endl;
    cin >> response;
    cout << "Validez vous votre réponse ?" << endl;
    cout << "1 - Oui" << endl;
    cout << "2 - Non" << endl;
    cin >> choice;

        do {
           
                if(choice == 1){
                    
                    gameplay();
                    
                } else if (choice == 2) {
                    cout << "Veuillez entrer à nouveau votre mot mystère" << endl;
                    cin >> response;
                    gameplay();
                } else {
                    cout << "Choix incorrect, Validez vous votre réponse ?" <<endl;
                    cout << "1 - Oui" << endl;
                    cout << "2 -  Non" << endl;
                    cin >> choice;
                    gameplay();
                }
            cout << "Souhaitez vous rejouer ? " << endl;
            cout << "1 - Oui" << endl;
            cout << "2 - Non" << endl;
            cin >> rematch;
            
            if(rematch==1){
                cout << "Joueur 1, veuillez entrer le mot mystère !" << endl;
                cin >> response;
                cout << "Validez vous votre réponse ?" << endl;
                cout << "1 - Oui" << endl;
                cout << "2 - Non" << endl;
                cin >> choice;
                
            } else if (rematch==2){
                cout << "Merci d'avoir joué au mot mystère !" << endl;;
                game = false;
            } else {
                cout << "Erreur lors du choix : "<< endl;
                cout << "Souhaitez vous rejouer ? " << endl;
                cout << "1 - Oui" << endl;
                cout << "2 - Non" << endl;
                cin >> rematch;
            }
            
            
            
            
        } while(game);
        
   
}




