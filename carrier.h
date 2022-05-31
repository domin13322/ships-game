#include"ship.h"
class Carrier :public Ship
{
	const int id = 0;
	int length = 5;
	int shots = 0;
	public:
		int getShipLength();
		void decrementLength(int length);
		const int getShipId();
		int getShots();
		void incremeantShots(int shots);
};
