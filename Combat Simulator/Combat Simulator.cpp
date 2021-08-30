#include <iostream>
//functions for Mcree's damage and shooting rate at various distances
int closeCombatMcree(float health);
int rangedCombatMcree(float health);


//functions for Roadhogs's damage and shooting rate at various dintances
int closeCombatRoadhog(float health);
int rangedCombatRoadhog(float health);

int main() {

    const float delta_time = 0.1f;
    float clock = 0.0f;
    bool gameLoop = true;
    bool getOverHere = false;

    //Mcree stats
    float mcreeHealth = 200.0f;

    const int mcreeMagazine = 4;
    const float mcreereloadSpeed = 1.5f;

    //Roadhog stats
    float roadhogHealth = 600.0f;
    const int roadhogMagazine = 4;
    const float roadhogreloadSpeed = 1.5f;

    while (gameLoop) {

        std::cout << "Mcrees health is at: " << mcreeHealth << std::endl;
        std::cout << "Roadhogs health is at: " << roadhogHealth << std::endl;

        if (getOverHere == true) {
            float tempDmgRoadhog = roadhogHealth;
            roadhogHealth = closeCombatMcree(roadhogHealth);
            std::cout << "Mcree did: " << tempDmgRoadhog - roadhogHealth << " damage to Roadhog!\n";

            float tempDmgMcree = mcreeHealth;
            mcreeHealth = closeCombatRoadhog(mcreeHealth);
            std::cout << "Roadhog did: " << tempDmgMcree - mcreeHealth << " damage to Mcree!\n";
        }
        else if (getOverHere == false) {
            float tempDmgRoadhog = roadhogHealth;
            roadhogHealth = rangedCombatMcree(roadhogHealth);
            std::cout << "Mcree did: " << tempDmgRoadhog - roadhogHealth << " damage to Roadhog!\n";

            float tempDmgMcree = mcreeHealth;
            mcreeHealth = rangedCombatRoadhog(mcreeHealth);
            std::cout << "Roadhog did: " << tempDmgMcree - mcreeHealth << " damage to Mcree!\n";
        }

        if (roadhogHealth < 0 || mcreeHealth < 0) {
            if (roadhogHealth <= 0) {
                std::cout << "Mcree wins!\n" << "Mcree had:" << mcreeHealth << " health left!\n";
                gameLoop = false;
            }
            else if (mcreeHealth <= 0) {
                std::cout << "Roadhog wins!\n" << "Roadhog had:" << roadhogHealth << " health left!\n";
                gameLoop = false;
            }
            return 0;
        }
        std::cout<<std::endl;
    }
}
int closeCombatMcree(float health){
    const float mcreeCloseDmg = 70.0f;
    health -= mcreeCloseDmg;
    return health;
}

int rangedCombatMcree(float health){
    const float mcreeRangedDmg = 35.0f;
    health -= mcreeRangedDmg;
    return health;
}

int closeCombatRoadhog(float health) {
    const float roadhogCloseDmg = 255.0f;
    health -= roadhogCloseDmg;
    return health;
}

int rangedCombatRoadhog(float health) {
    const float roadhogRangedDmg = 20.0f;
    health -= roadhogRangedDmg;
    return health;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
