#include"ship.h"
class Cruiser :public Ship {
	int length = 3;
	const int id = 2;
	int shots = 0;
	public:
		int getShipLength();
		void decrementLength(int length);
		const int getShipId();
		int getShots();
		void incremeantShots(int shots);
};