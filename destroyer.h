#include"ship.h"
class Destroyer: public Ship
{
	const int id = 3;
	int length = 2;
	int shots = 0;
	public:
		int getShipLength();
		void decrementLength(int length);
		const int getShipId();
		int getShots();
		void incremeantShots(int shots);
};