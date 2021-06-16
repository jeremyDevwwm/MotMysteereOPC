//
//  gameLoop.cpp
//  TP_Mot_Mystere
//
//  Created by Dijoux Jérémy on 16/06/2021.
//

#include "gameLoop.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <algorithm>
#include "str_mix_up.hpp"

using namespace std;

bool game (true);
bool soloGame(true);

string response;
string displayedWord;
string submittedValue;


int choice;
int rematch;

void answerCheck(string response){
    
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


void gameplay(){
    
    if(soloGame || rematch==1){
        ifstream file("/TP_Mot_Mystere/component/dico.txt");
        if(file){
            
            vector<string> fetchedFile;
            string fileLine;

            
            while(getline(file,fileLine)){
                fetchedFile.push_back(fileLine);
            }
            shuffle(fetchedFile.begin(), fetchedFile.end(), std::default_random_engine(time(0)));
            cout << fetchedFile[0];
            fetchedFile[0].pop_back();
            response = fetchedFile[0];
            
            answerCheck(response);
            
            soloGame=false;
            
        } else {
            
            cout << "Erreur lors de l'ouverture du fichier"<< endl;
        }
        
    } else {
        answerCheck(response);
    }
}


void gameLoop(){
    cout << "Bienvenue dans Mot Mystère !"<< endl;
    cout << "################################" << endl;
    cout << "Souhaitez vous jouer en solo ou en multijoueur ?"<< endl;
    cout << "1 -  Solo "<< endl;
    cout << "2 - Multijoueur "<< endl;
    cin >> choice;
    
    if(choice== 1){
        soloGame=true;
        do {
        gameplay();
            cout << "Souhaitez vous rejouer ? " << endl;
            cout << "1 - Oui" << endl;
            cout << "2 - Non" << endl;
            cin >> rematch;
            
            if(rematch==1){
                gameplay();
                cout << "Souhaitez vous rejouer ? " << endl;
                cout << "1 - Oui" << endl;
                cout << "2 - Non" << endl;
                cin >> rematch;
                
            }
            
            if (rematch==2){
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
        
    } else if (choice == 2){
        
    soloGame=false;
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
        
    } else {
        cout << "Erreur lors du choix "<< endl;
        cout << "Souhaitez vous jouer en solo ou en multijoueur ?"<< endl;
        cout << "1 -  Solo "<< endl;
        cout << "2 - Multijoueur "<< endl;
        cin >> choice;
    }
}




