#include"destroyer.h"
#include<iostream>
using namespace std;

int Destroyer::getShipLength()
{
    return length;
}

void Destroyer::decrementLength(int length)
{
    this->length -= 1;
}

const int Destroyer::getShipId()
{
    return this->id;
}
int  Destroyer::getShots() {
    return this->shots;
}
void Destroyer::incremeantShots(int shots)
{
    this->shots += 1;
}
