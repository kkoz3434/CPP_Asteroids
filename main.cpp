#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <iostream>
#include <valarray>
#include "GameSetup.h"
#include "SpaceObject.h"
#include "GameEngine.h"

using namespace sf;

const float degreeRadian = M_PI / 180;


int main() {
    GameEngine gameEngine;
    gameEngine.game();
    /*
    std::list<int> a= {1,2,3,4,5,6,7,8,9,10};
    for (auto i = a.begin();  i!=a.end();) {
        if(i%2==0){
            i=a.erase(i);
        }
        else i++;
    }
    for (auto i = a.begin();  i!=a.end();) {
        std::cout<<*i<<std::endl;
        i++;
    }

     */


    return 0;
}
