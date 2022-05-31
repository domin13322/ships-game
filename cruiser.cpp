#include"cruiser.h"
#include<iostream>
using namespace std;

int Cruiser::getShipLength()
{
    return length;
}

void Cruiser::decrementLength(int length)
{
    this->length -= 1;
}

const int Cruiser::getShipId()
{
    return this->id;
}
int  Cruiser::getShots() {
    return this->shots;
}
void Cruiser::incremeantShots(int shots)
{
    this->shots += 1;
}
