#include "RPG.h"
#include <iostream>
#include<cstdlib>
using namespace std;
/// @brief 
/// @param player1 
/// @param player2 
void displayStats(RPG player1, RPG player2){
    printf("%s health: %i\n", player1.getName().c_str(), player1.getHealth());
    printf("%s health: %i\n", player2.getName().c_str(), player2.getHealth());
}
/// @brief 
/// @param player1 
/// @param player2 
void displayEnd(RPG player1, RPG player2){
    if (player1.isAlive()){
        printf("%s defeated %s! Good game!\n", player1.getName().c_str(), player2.getName().c_str());
    }
    else{
        printf("%s defeated %s! Good game!\n", player2.getName().c_str(), player1.getName().c_str());
    }

}
/// @brief 
/// @param player1 
/// @param player2 
void gameLoop(RPG * player1, RPG * player2){
    while((*player1).isAlive() == true & (*player2).isAlive()==true){
        displayStats((*player1), (*player2));
        printf("%s's turn\n",(*player1).getName().c_str());
        (*player1).useSkill(player2);
        printf("--------------------------\n");

        displayStats((*player1), (*player2));
        printf("%s's turn\n",(*player2).getName().c_str());
        (*player2).useSkill(player1);
        printf("--------------------------\n");
    }

}
int main(){
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage");
    RPG p2 = RPG();

    gameLoop(&p1, &p2);
    displayEnd(p1, p2);

    printf("%s Current Stats\n" , p1.getName().c_str());
    printf("Health: %i\t Strength: %i\t Defense: %i\n", p1.getHealth(), p1.getStrength(),p1.getDefense());

    printf("%s Current Stats\n" , p2.getName().c_str());
    printf("Health: %i\t Strength: %i\t Defense: %i\n", p2.getHealth(), p2.getStrength(),p2.getDefense());

    p1.updateHealth(0);

    cout<<p1.getHealth()<<endl; 

    cout<<p1.isAlive()<<endl;
    cout<<p2.isAlive()<<endl;

    return 0;

}