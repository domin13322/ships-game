#include"carrier.h"
#include<iostream>
using namespace std;

int Carrier::getShipLength()
{
	return this->length;
}

void Carrier::decrementLength(int length)
{
	this->length -= 1;
}

const int Carrier::getShipId()
{
	return this->id;
}
int  Carrier::getShots() {
	return this->shots;
}
void Carrier::incremeantShots(int shots)
{
	this->shots += 1;
}
