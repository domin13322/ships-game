#include"ship.h"
class Battleship:public Ship
{
	const int id = 1;
	int length = 4;
	int shots = 0;
	public:
	int getShipLength();
	int getShots();
	void incremeantShots(int shots);
	const int getShipId();
};