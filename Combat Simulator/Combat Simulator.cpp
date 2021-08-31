#include <iostream>
//functions for Mcree's damage and shooting rate at various distances
int closeCombatMcree(float health);
int rangedCombatMcree(float health);


//functions for Roadhogs's damage and shooting rate at various dintances
int closeCombatRoadhog(float health);
int rangedCombatRoadhog(float health);

int main() {

    //variables that control the games loop and timekeeping
    const float delta_time = 0.1f;
    float clock = 0.0f;
    bool gameLoop = true;
    bool getOverHere = false;
    int loopCount = 0;

    //Mcree stats
    float mcreeHealth = 200.0f;
    const int mcreeMagazine = 4;
    const float mcreereloadSpeed = 1.5f;

    //Roadhog stats
    float roadhogHealth = 600.0f;
    const int roadhogMagazine = 4;
    const float roadhogreloadSpeed = 1.5f;

    while (gameLoop) {
        clock += delta_time;
        loopCount += 1;
        std::cout << "Mcrees health is at: " << mcreeHealth << std::endl;
        std::cout << "Roadhogs health is at: " << roadhogHealth << std::endl;
        std::cout << clock << " seconds have elappsed.\n";
        if(clock == 0.5f) {//TODO, kolla upp hur man kan jämföra numret för att kolla om det är jämnt eller ojämnt. Väldigt konstigt iochmed att det är en float. Just nu körs den här endast 1 gång. Funderade på att resetta loopcount och ha den som jämförelse för clock men det skulle inte fungera.
            if (getOverHere == true) { //TODO fixa en räknare med delta_time och clock som medf hjälp av if-satser kollar när de får skjuta och inte. Kollar även magasin och reloading här
                //TODO, sätt upp separata if-satser för Mcree och Roadhog så att de kan attackera oberoende av varandra. TODO sätt upp så att Roadhog kan hooka direkt och skriv ut det i konsollen. TODO, sätt in wait-funktioner så att det spelar ut i realtid.
                //TODO, bryt ut allt detta i en egen fil eller funktion så att väldigt lite ligger i int Main.
                //TODO, överkurs men sätt upp construktor så att det skulle vara lätt att göra nya karaktärer med sina egna stats och eventuellt abilities.
                //TODO, gör som Numberphile sa, istället för float för floatpoint comparison så kör man int och bara multiplicerar eller dividerar för att få det att bli som en float. Då vet jag att % 2 == 0 kommer att fungera. Om varje loop blir 1 sekund och då skjuter Mcree varje loop och Roadhog skjuter varannan loop. Det skulle funka men vet inte om det skulle vara det bösta,
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
        }
        if (roadhogHealth <= 0 || mcreeHealth <= 0) {//Checks if any participant has lost all their health and subsequently lost the duel.
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
int closeCombatMcree(float health){//Separate functions for each character for if they're close to eacher or not. Deals the damage to the enemies health then returns that value to the Main function
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
