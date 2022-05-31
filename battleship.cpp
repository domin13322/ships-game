#include"battleship.h"
#include<iostream>
using namespace std;

int Battleship::getShipLength()
{
    return length;
}
const int Battleship::getShipId()
{
    return this->id;
}
int  Battleship::getShots() {
    return this->shots;
}
void Battleship::incremeantShots(int shots)
{
    this->shots += 1;
}
