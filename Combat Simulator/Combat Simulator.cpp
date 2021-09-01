#include <iostream>
#include <chrono>
#include <thread>
int combatMcree(int roadhogHealth, bool hooked);
int combatRoadHog(int roadhogHealth, bool hooked);
int gameOver(int roadhogHealth, int mcreeHealth, bool gameLoop);


int main() {

    //variables that control the games loop and timekeeping
    const int delta_time = 1;
    int clock = 0;
    bool gameLoop = true;
    bool getOverHere = false;
    int loopCount = 0;

    //Mcree stats
    int mcreeHealth = 200;
    int mcreeMagazine = 6;
    bool reloadingMcree = false;
    int reloadingTimeMcree = 0;


    //Roadhog stats
    int roadhogHealth = 600;
    int roadhogMagazine = 4;
    bool reloadingRoadhog = false;
    int reloadingTimeRoadhog = 0;

    while (gameLoop) {
        clock += delta_time;
        loopCount += 1;
        std::chrono::milliseconds timespan(1000); //Includerade detta + <chrono> + <thread> för att det skulle bli fancy och spela ut i realtid. Alla räkningar och liknande funkar fortfarande bara via simulering av tid.
        std::this_thread::sleep_for(timespan);

        if (reloadingMcree != true) { //Mcree rootin tootin cowboy shootin, Mcree shoots every available round
            if(mcreeMagazine > 0) {
                mcreeMagazine -= 1;
                roadhogHealth = combatMcree(roadhogHealth, getOverHere);
                std::cout << "Mcree's got: " << mcreeMagazine << " bullets left! \n";
            }
            else {
                reloadingMcree = true;
                reloadingTimeMcree = 15;
                std::cout << "Mcree is reloading, he won't be able to shoot for another " << reloadingTimeMcree << " seconds!\n";
            }
        }
        if (clock % 2 != 0 && reloadingRoadhog != true) { //RoadHog is blasting away here, RoadHog only shoots every other round
            if (roadhogMagazine > 0) {
                roadhogMagazine -= 1;
                mcreeHealth = combatRoadHog(mcreeHealth, getOverHere);
                std::cout << "Roadhog's got: " << roadhogMagazine << " bullets left! \n";
            }
            else {
                reloadingRoadhog = true;
                reloadingTimeRoadhog = 15;
                std::cout << "Roadhog is reloading, he won't be able to shoot for another " << reloadingTimeRoadhog << " seconds!\n";
            }
        }
        if (reloadingTimeMcree > 0) {//Reloading code for cowboy
            reloadingTimeMcree -= 1;
            if (reloadingTimeMcree <= 0) {
                mcreeMagazine = 6;
                reloadingMcree = false;
            }
        }
        if(reloadingTimeRoadhog > 0) {//Reloading code for Roadie
            reloadingTimeRoadhog -= 1;
            if(reloadingTimeRoadhog <= 0) {
                roadhogMagazine = 4;
                reloadingRoadhog = false;
            }
        }
        gameOver(roadhogHealth, mcreeHealth, gameLoop);
        std::cout << std::endl;
    }
}

int combatMcree(int roadhogHealth, bool hooked) { //Mcree's rootin tootin cowboy shootin function, handles both close and far ranged combat. Returns the opponents health
    const int damageClose = 70;
    const int damageRanged = 35;
    if (hooked == true) {
        roadhogHealth -= damageClose;
        std::cout << "Mcree did: " << damageClose << " damage to RoadHog!\n" << "RoadHog now has: " << roadhogHealth << " left!\n";
        return roadhogHealth;
    }
    else {
        roadhogHealth -= damageRanged;
        std::cout << "Mcree did: " << damageRanged << " damage to RoadHog!\n" << "RoadHog now has: " << roadhogHealth << " left!\n";
        return roadhogHealth;
    }
}

int combatRoadHog(int mcreeHealth, bool hooked) { // Roadie is mad and also wants to shoot the cowboy with a particular name. Shame blizzard did what they did
    const int damageClose = 255;
    const int damageRanged = 20;
    if (hooked == true) {
        mcreeHealth -= damageClose;
        std::cout << "Roadhog did: " << damageClose << " damage to Mcree!\n" << "Mcree now has: " << mcreeHealth << " left!\n";
        return mcreeHealth;
    }
    else{
        mcreeHealth -= damageRanged;
        std::cout << "Roadhog did: " << damageRanged << " damage to Mcree!\n" << "Mcree now has: " << mcreeHealth << " left!\n";
        return mcreeHealth;
    }
}

int gameOver(int roadhogHealth, int mcreeHealth, bool gameLoop) {
    if (roadhogHealth <= 0 || mcreeHealth <= 0) {//Checks if any participant has lost all their health and subsequently lost the duel.
        if (roadhogHealth <= 0) {
            std::cout << "Mcree wins!\n" << "Mcree had: " << mcreeHealth << " health left!\n";
            gameLoop = false;
        }
        else if (mcreeHealth <= 0) {
            std::cout << "Roadhog wins!\n" << "Roadhog had: " << roadhogHealth << " health left!\n";
            gameLoop = false;
        }
        exit(0);
    }
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
