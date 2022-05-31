#pragma once
#include<math.h>
class Ship
{
protected: 
	int totalShots = 0;
	int shotsUsed = 0;
	int x = 0, y = 0;
	int shipIndex=0;
	int *frontY=&y;
	int* frontX=&x;
	char direction = '\n';
	char shipClass[4]="nic";
	int length = 0;
	int exist = 0;
	int cannonPositionY = 0;
	int cannonPositionX = 0;
	int enginePositionX = 0;
	int enginePositionY = 0;
public:
	virtual void placeShip(int*,int*,char,int);
	virtual char getDirection();
	virtual int* getPositionY();
	virtual int* getPositionX();
	virtual int getShipIndex();
	virtual char* getShipClass();
	virtual int getShipLength()=0;
	virtual void incremeantShots(int shots)=0;
	virtual int getShots()=0;
	virtual void setExist(int ex);
	virtual int getExist();
	virtual void setDirection(char d);
	virtual const int getShipId() = 0;
	virtual int getEnginePositionX();
	virtual int getEnginePositionY();
	virtual void setEnginePositionY(int eY);
	virtual void setEnginePositionX(int eX);
	virtual int getCannonPositionX();
	virtual int getCannonPositionY();
	virtual void setCannonPositionY(int cY);
	virtual void setCannonPositionX(int cX);
	virtual	void setShotTo0(int shots);
	virtual float getShotDistance(int cannonPositionY, int cannonPositionX,int y,int x);
};