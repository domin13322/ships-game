#include<iostream>
#include"ship.h"
using namespace std;

int* Ship::getPositionY()
{
    return this->frontY;
}

int* Ship::getPositionX()
{
    return this->frontX;
}

int Ship::getShipIndex()
{
    return this->shipIndex;
}

char* Ship::getShipClass()
{
    return shipClass;
}

void Ship::setExist(int ex)
{
    this->exist = ex;
}

int Ship::getExist()
{

    return exist;
}

void Ship::setDirection(char d)
{
    this->direction = d;
}

int Ship::getEnginePositionX()
{
    return this->enginePositionX;
}

int Ship::getEnginePositionY()
{
    return this->enginePositionY;
}

void Ship::setEnginePositionY(int eY)
{
    this->enginePositionY = eY;
}

void Ship::setEnginePositionX(int eX)
{
    this->enginePositionX = eX;
}

int Ship::getCannonPositionX()
{
    return this->cannonPositionX;
}

int Ship::getCannonPositionY()
{
    return this->cannonPositionY;
}

void Ship::setCannonPositionY(int cY)
{
    this->cannonPositionY = cY;
}

void Ship::setCannonPositionX(int cX)
{
    this->cannonPositionX = cX;
}

void Ship::setShotTo0(int shots)
{
    shots = 0;
}

float Ship::getShotDistance(int cannonPositionY, int cannonPositionX, int y, int x)
{
    float distance = 0;
    distance = (((cannonPositionY-y)* (cannonPositionY - y))+ ((cannonPositionX - x) * (cannonPositionX -x)));


    return sqrt(distance);
}

void Ship::placeShip(int*yy, int*xx, char d, int i) {
    *frontY = *yy;
    *frontX = *xx;
    this->shipIndex = i;
    this->direction = d;
}

char Ship::getDirection()
{
    return this->direction;
}
