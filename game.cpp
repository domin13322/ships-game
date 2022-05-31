#include"game.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

Game::Game(int** board,int sizeX, int sizeY,int*parts) {
	this->parts = new int[playersNumber];
	this->sizeY = sizeY;
	this->sizeX = sizeX;
	this->board = new int* [sizeY];
	this->isVisible = new bool* [sizeY];
	this->isVisibleB = new bool* [sizeY];
	this->aShooted = false;
	for (int i = 0;i < sizeY;i++) {
		this->board[i] = new int[sizeX];
		this->isVisible[i] = new bool[sizeX];
		this->isVisibleB[i] = new bool[sizeX];
	}
	for (int i = 0;i < 4;i++) {
		shipsPlacedA[i] = 0;
		shipsPlacedB[i] = 0;
	}
	for (int i = 0;i < 15;i++) {
		forbiddenX[i] = 0;
		forbiddenY[i] = 0;
	}
	
	boundYmin[0] = 0;
	boundYmax[0] = 9;
	boundXmin[0] = 0;
	boundXmax[0] = 9;
	boundYmin[1] = 11;
	boundYmax[1] = 20;
	boundXmin[1] = 0;
	boundXmax[1] = 9;
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 10;j++) {
			trafione[i][j] = '\0';
		}
	}
}

void Game::setBoardSize(int sizeY, int sizeX, int** board) {
	this->board = new int* [sizeY];
	this->isVisible = new bool* [sizeY];
	this->isVisibleB = new bool* [sizeY];
	for (int i = 0;i < sizeY;i++) {
		this->board[i] = new int[sizeX];
		this->isVisible[i] = new bool[sizeX];
		this->isVisibleB[i] = new bool[sizeX];
	}
	setBoard(board);
}

void Game::setParts(int* parts) {
	this->parts[playerA] = 0;
	this->parts[playerB] = 0;
}

void Game::shoot(int* positionY, int* positionX, int** board)
{
	if (*kolejka == playerA) setShooted(true);
	
	cin >> *positionY >> (*positionX);

	if (allShipsPlaced == false) {
		cout << invalidOperation << " \"SHOOT " << *positionY << " " << *positionX << "\": NOT ALL SHIPS PLACED" << endl;
		endOfGame = true;
		
	}
	
	
	if (*positionY < sizeY && *positionX < sizeX && *positionX>=0 && positionY>=0)
	{
		if (board[*positionY][*positionX]!=reef && this->board[*positionY][*positionX]>=taken && board[*positionY][*positionX] != damaged) {
			this->board[*positionY][*positionX] = damaged;
			if (*kolejka == playerA) {
				parts[playerB]--;
		}
			else if (*kolejka == playerB){ 
				parts[playerA]--;
	}
			
		}
	}

	else {
		
		 cout << invalidOperation << " \"SHOOT " << *positionY << " " << *positionX << "\": FIELD DOES NOT EXIST" << endl;
		endOfGame = true;
	}
	if (aShooted == false && (*kolejka == playerB) && allShipsPlaced == true) {

		cout << invalidOperation << " \"[playerB] \": THE OTHER PLAYER EXPECTED" << endl;
		endOfGame = true;
	}
	
}
void Game::setBoard(int** board)
{
	for (int i = 0;i < this->sizeY;i++) {
		for (int j = 0;j < sizeX;j++) {
			this->board[i][j] = empty;
			this->isVisible[i][j] = false;
			this->isVisibleB[i][j] = false;
		}
	}
}

void Game::displayBoard(int** board) {
	for (int i = 0;i < sizeY;i++) {
		for (int j = 0;j < sizeX;j++) {
			if (playerPrintingOn) {
				if ((*kolejka == playerA && isVisible[i][j]==true)|| (*kolejka==playerB && isVisibleB[i][j])) {
					if ((this->board[i][j] >= taken) && this->board[i][j] != damaged && this->board[i][j] != reef) cout << "+";
					else if (this->board[i][j] == damaged) cout << "x";
					else if (this->board[i][j] == empty) cout << " ";
					else cout << " ";
				}

			else cout << "?";
			}
			else {
				if ((this->board[i][j] >= taken) && this->board[i][j] != damaged && this->board[i][j] != reef) cout << "+";
				else if (this->board[i][j] == damaged) cout << "x";
				else if (this->board[i][j] == empty) cout << " ";
				else cout << " ";
			}
}
		cout << endl;
	}
}
void Game::extendedPrinting(int** board)
{
	int xCounter = 0;

	cout<<endl <<"  ";
	if (sizeX > 10) {
		for (int i = 0;i < sizeX;i++) {
			if (i % 10 == 0 && i > 1) xCounter++;
			cout << xCounter;
		}
	}
	cout << endl<<"  ";
	int temp = 0;
	for (int i = 0;i < sizeX;i++) {
		if (i < 10)
			cout <<i;
		else if (i>=10) 
		{
			if (i % 10 == 0) {
				temp = i;
			}
			cout << (i -temp);
		}
	}
	cout << endl;

	for (int i = 0;i < sizeY;i++) {
		if (i < 10) {
			cout << 0 << i;
		}
		else cout<<i;
		for (int j = 0;j < sizeX;j++) {
			if (playerPrintingOn) {

				if ((*kolejka == playerA && isVisible[i][j] == true) || (*kolejka == playerB && isVisibleB[i][j])) {
					if ((this->board[i][j] == taken)) cout << "+";
					else if (this->board[i][j] == damaged) cout << "x";
					else if (this->board[i][j] == empty) cout << " ";
					else if (this->board[i][j] == radar) cout << "@";
					else if (this->board[i][j] == cannon) cout << "!";
					else if (this->board[i][j] == engine) cout << "%";
					else if (this->board[i][j] == reef) cout << "#";
				}
				else cout << "?";
			}
			else {
				if ((this->board[i][j] == taken)) cout << "+";
				else if (this->board[i][j] == damaged) cout << "x";
				else if (this->board[i][j] == empty) cout << " ";
				else if (this->board[i][j] == radar) cout << "@";
				else if (this->board[i][j] == cannon) cout << "!";
				else if (this->board[i][j] == engine) cout << "%";
				else if (this->board[i][j] == reef) cout << "#";
			}
		}
		cout << endl;
	}
}

Game::~Game() {
	for (int i = 0; i < sizeY; ++i) {
		delete[] this->board[i];
		delete[] this->isVisible[i];
		delete[] this->isVisibleB[i];

	}
	delete[] this->board;
	delete[] this->isVisible;
	delete[] this->isVisibleB;
	delete[] this->parts;
	delete[]cruisers;
	delete[]destroyers;
	delete[]carriers;
	delete[]battleships;
	delete[]cruisersB;
	delete[]destroyersB;
	delete[]carriersB;
	delete[]battleshipsB;
}
void Game::setFleet(Ship* pointer, int* positionY, int* positionX, char player,int *parts) {
	
	cin >> player;
		
		if (player=='A') {
			*kolejka =playerA;
			cin >> numberOfCarriers >> numberOfBattleships >> numberOfCruisers >> numberOfDestroyers;
		}
		else if(player == 'B') {
			*kolejka = playerB;
			cin >>numberOfCarriersB >> numberOfBattleshipsB >> numberOfCruisersB >> numberOfDestroyersB;
		}
	

	carriers = new Carrier[numberOfCarriers];
	battleships = new Battleship[numberOfBattleships];
	cruisers = new Cruiser[numberOfCruisers];
	destroyers = new Destroyer[numberOfDestroyers];
	carriersB = new Carrier[numberOfCarriersB];
	battleshipsB = new Battleship[numberOfBattleshipsB];
	cruisersB = new Cruiser[numberOfCruisersB];
	destroyersB = new Destroyer[numberOfDestroyersB];

	totalFleetA = numberOfCarriers + numberOfBattleships + numberOfCruisers + numberOfDestroyers;
	totalFleetB= numberOfCarriersB + numberOfBattleshipsB + numberOfCruisersB + numberOfDestroyersB;

}

void Game::takePlaces(Ship* pointer, int** board, int length, char direction, int* positionY, int* positionX)
{
	int tempY = *pointer->getPositionY();
	int tempX = *pointer->getPositionX();
	for (int i = 0;i < 4;i++) {
		tempY += directionArray[i][0];
		tempX += directionArray[i][1];
		if ((tempY) < sizeY && (tempX) < sizeX && tempX>=0 && tempY>=0) {
			if (board[tempY][tempX] >= taken) {
				shipToClose = true;
		}
			
		}
		tempY -= directionArray[i][0];
		tempX -= directionArray[i][1];
	}

	if (*pointer->getPositionX() < sizeX && *pointer->getPositionY() < sizeY) {
		this->board[*pointer->getPositionY()][*pointer->getPositionX()] = radar;
	}
	
	for (int i = 0;i <(pointer->getShipLength() - 1);i++) {
		tempY += directionArray[directionNumber][0];
		tempX += directionArray[directionNumber][1];
		if ((tempY) < sizeY && (tempX) < sizeX && tempX >= 0 && tempY >= 0) {
			if (this->board[tempY][tempX] == empty) {
				this->board[tempY][tempX] = taken;
			}
			else if (this->board[tempY][tempX] == reef) {
				onReef = true;
			}
			for (int i = 0;i < 4;i++) {
				if((tempY + directionArray[i][0])<sizeY && (tempX + directionArray[i][1]) < sizeX && (tempY + directionArray[i][0])>=0 && (tempX + directionArray[i][1])>=0)
				if (board[tempY + directionArray[i][0]][tempX + directionArray[i][1]] >= taken)
				{
					if (i != oppositeDirectionNumber) {
						shipToClose = true;
					}
				}
			}
		}
		else outside = true;
	}
	setEngine(pointer, positionY, positionX, pointer->getShipLength(), direction);
	radarRange(pointer);
}
void Game::radarRange(Ship* pointer)
{
	for (int i = 0; i < sizeY;i++) {
		for (int j = 0;j < sizeX;j++) {
			if (pointer->getShotDistance(*positionY, *positionX, i, j) <= pointer->getShipLength() && board[i][j]!=reef && isVisible[i][j]==false) {
				if (*kolejka == playerA) {
					isVisible[i][j] = true;
				}
				else if (*kolejka == playerB) { isVisibleB[i][j] = true; 
				}
			}
		}
	}
	
}
char* Game::getTrafione(char tarfione[][10], Ship* pointer, int length,bool A) {
	int tempX = *pointer->getPositionX();
	int tempY = *pointer->getPositionY();
	if (pointer->getDirection() == north) directionNumber = 0;
	else if (pointer->getDirection() == south) directionNumber = 1;
	else if (pointer->getDirection() == west) directionNumber = 2;
	else if (pointer->getDirection() == east) directionNumber = 3;
	for (int i = 0;i < length;i++) {
		if (i != 0) {
			tempY += directionArray[directionNumber][0];
			tempX += directionArray[directionNumber][1];
		}
		if (tempX >= 0 && tempY >= 0 && tempY < sizeY && tempX < sizeX) {
			if (this->board[tempY][tempX] == damaged) {
				if (A) {
					trafione[pointer->getShipId()][i] = '0';
				}
				else trafione[pointer->getShipId()+4][i] = '0';
			}
			else { 
				if (A)	trafione[pointer->getShipId()][i] = '1';
				else trafione[pointer->getShipId() + 4][i] = '1';
			}
		}
	}
	if (A) {
		return trafione[pointer->getShipId()];
	}
	else return trafione[pointer->getShipId()+4];
}
void Game::saveGame()
{
	cout << "[state]" << endl;
	cout << "BOARD_SIZE " << sizeY << " " << sizeX << endl;
	if (nextPlayerUsed[playerA]) cout << "NEXT_PLAYER A" << endl;
	cout << "INIT_POSITION A " << boundYmin[playerA] << " " << boundXmin[playerA] << " " << boundYmax[playerA] << " " << boundXmax[playerA] << endl;
	cout << "SET_FLEET A "<<numberOfCarriers<<" "<<numberOfBattleships<<" "<<numberOfCruisers<<" "<<numberOfDestroyers<<endl;
	for (int i = 0;i <shipsPlacedA[carrier];i++) {
		cout << "SHIP A " << *carriers[i].getPositionY() << " " << *carriers[i].getPositionX() << " " << carriers[i].getDirection() << " " << i << " " << "CAR "<<getTrafione(trafione,&carriers[i],carriers[i].getShipLength(),true) << endl;
	}
	for (int i = 0;i < shipsPlacedA[battleship];i++) {
		cout << "SHIP A " << *battleships[i].getPositionY() << " " << *battleships[i].getPositionX() << " " << battleships[i].getDirection() << " " << i << " " << "BAT "<< getTrafione(trafione, &battleships[i], battleships[i].getShipLength(),true) << endl;
	}
	for (int i = 0;i < shipsPlacedA[cruiser];i++) {
		cout << "SHIP A " << *cruisers[i].getPositionY() << " " << *cruisers[i].getPositionX() << " " << cruisers[i].getDirection() << " " << i << " " << "CRU "<< getTrafione(trafione, &cruisers[i], cruisers[i].getShipLength(),true) << endl;
	}
	for (int i = 0;i < shipsPlacedA[destroyer];i++) {
		cout << "SHIP A " << *destroyers[i].getPositionY() << " " << *destroyers[i].getPositionX() << " " << destroyers[i].getDirection() << " " << i << " " << "DES "<< getTrafione(trafione, &destroyers[i], destroyers[i].getShipLength(),true) << endl;
	}
	if (nextPlayerUsed[playerB]) cout << "NEXT_PLAYER B" << endl;
	cout << "INIT_POSITION B " << boundYmin[playerB] << " " << boundXmin[playerB] << " " << boundYmax[playerB] << " " << boundXmax[playerB] << endl;
	cout << "SET_FLEET B " << numberOfCarriersB << " " << numberOfBattleshipsB << " " << numberOfCruisersB << " " << numberOfDestroyersB << endl;
	for (int i = 0;i < shipsPlacedB[carrier];i++) {
		cout << "SHIP B " << *carriersB[i].getPositionY() << " " << *carriersB[i].getPositionX() << " " << carriersB[i].getDirection() << " " << i << " " << "CAR "<< getTrafione(trafione, &carriersB[i], carriersB[i].getShipLength(),false) << endl;
	}
	for (int i = 0;i < shipsPlacedB[battleship];i++) {
		cout << "SHIP B " << *battleshipsB[i].getPositionY() << " " << *battleshipsB[i].getPositionX() << " " << battleshipsB[i].getDirection() << " " << i << " " << "BAT "<< getTrafione(trafione, &battleshipsB[i], battleshipsB[i].getShipLength(),false) << endl;
	}
	for (int i = 0;i < shipsPlacedB[cruiser];i++) {
		cout << "SHIP B " << *cruisersB[i].getPositionY() << " " << *cruisersB[i].getPositionX() << " " << cruisersB[i].getDirection() << " " << i << " " << "CRU "<< getTrafione(trafione, &cruisersB[i], cruisersB[i].getShipLength(),false) << endl;
	}
	for (int i = 0;i < shipsPlacedB[destroyer];i++) {
		cout << "SHIP B " << *destroyersB[i].getPositionY() << " " << *destroyersB[i].getPositionX() << " " << destroyersB[i].getDirection() << " " << i << " " << "DES "<< getTrafione(trafione, &destroyersB[i], destroyersB[i].getShipLength(),false) << endl;
	}
	for (int i = 0;i < numberOfReefs;i++) {
		cout << "REEF " << forbiddenY[i] << " " << forbiddenX[i] << endl;
	}
	cout << "[state]" << endl;
}

void Game::turn() {
	
	char command[50];
	char playerStateCommand[20];


	cin >> playerStateCommand;
	if (strcmp(playerStateCommand, "[playerA]") == 0) { *kolejka = playerA; 
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			shotsTakenA[i][j] = 0;
			shotsTakenB[i][j] = 0;
			movesMadeA[i][j] = 0;
			movesMadeB[i][j] = 0;
		}
	}
	}
	else if (strcmp(playerStateCommand, "[playerB]") == 0) { *kolejka = playerB; 
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			shotsTakenA[i][j] = 0;
			shotsTakenB[i][j] = 0;
			movesMadeA[i][j] = 0;
			movesMadeB[i][j] = 0;
		}
	}
	}

	do {

		cin >> command;
		if (cin.peek() == EOF) exit(0);

		if (strcmp(playerStateCommand, "[state]") == 0) {

			if (strcmp(command, "SET_FLEET") == 0) {
				setFleet(pointer, positionY, positionX, player, parts);
			}
			else if (strcmp(command, "EXTENDED_SHIPS") == 0) {
				extendedShips = true;
			}
			else if (strcmp(command, "PRINT") == 0)
			{
				playerPrintingOn = false;
				int x;
				cin >> x;
				if (x == 0) {
					displayBoard(this->board);
				}
				else if (x == 1) {
					extendedPrinting(board);

				}
				if (parts[playerA] > 0 || parts[playerB] > 0)
					cout << "PARTS REMAINING:: A : " << parts[playerA] << " B : " << parts[playerB] << endl;

			}
			else if (strcmp(command, "REEF") == 0) {
				setReef();
			}
			else if (strcmp(command, "SAVE") == 0) {
				saveGame();
			}
			else if (strcmp(command, "BOARD") == 0) {
				cin >> sizeY >> sizeX;
				setBoardSize(sizeY, sizeX, board);
			}


			else if (strcmp(command, "SHIP") == 0) {
				setShip(pointer, true);
			}

			else if (strcmp(command, "NEXT_PLAYER") == 0) {
				char gracz;
				cin >> gracz;
				if (gracz == 'A' || gracz == 'a') {
					*kolejka = playerA;
					nextPlayerUsed[playerA] = true;
				}
				else if (gracz == 'B' || gracz == 'b') {
					*kolejka = playerB;
					nextPlayerUsed[playerB] = true;
				}
				for (int i = 0;i < 4;i++) {
					for (int j = 0;j < 4;j++) {
						shotsTakenA[i][j] = 0;
						shotsTakenB[i][j] = 0;
						movesMadeA[i][j] = 0;
						movesMadeB[i][j] = 0;
					}
				}
			}
			else if (strcmp(command, "INIT_POSITION") == 0) {
				initPosition();
			}
		}
		else if (strcmp(playerStateCommand, "[playerA]") == 0 || strcmp(playerStateCommand, "[playerB]") == 0) {


			if (strcmp(command, "SHOOT") == 0) {
				if (extendedShips == false)shoot(this->positionY, this->positionX, this->board);
				else extendedShooting(pointer);
			}

			else if (strcmp(command, "PLACE_SHIP") == 0) {
				setShip(pointer, false);
			}
			else if (strcmp(command, "MOVE") == 0) {

				moveShip(pointer, command);
			}
			else if (strcmp(command, "SPY") == 0) {
				spy(positionY, positionX);
			}
			else if (strcmp(command, "PRINT") == 0)
			{
				playerPrintingOn = true;
				int x;
				cin >> x;
				if (x == 0) {
					displayBoard(this->board);
				}
				else if (x == 1) {
					extendedPrinting(board);
				}
		}

}
		
		else break;
		
		if (endOfGame) break;
	} 
	while (strcmp(command, playerStateCommand) != 0);
	
}


void Game::resetLeft(int**board,int length,int*positionY,int*positionX) {

	for (int i = 0;i < length;i++) {
		if (((*positionY < sizeY) && (*positionX - i) < sizeX) && (*positionY) >= 0 && (*positionX - i) >= 0)
			this->board[*positionY][*positionX - i]= empty;
		else break;
	}
}

void Game::resetDown(int** board, int length, int* positionY, int* positionX) {
	for (int j = 0;j < length;j++) {
		if (((*positionY + j) < sizeY && (*positionX) < sizeX))
			this->board[*positionY + j][*positionX] = empty;
		else break;
	}
}

void Game::resetUp(int** board, int length, int* positionY, int* positionX) {
	for (int j = 0;j < length;j++) {
		if ( (*positionY - j) < sizeY && (*positionX < sizeX) && (*positionY - j) >= 0 && (*positionX) >= 0)
			this->board[*positionY-j][*positionX]=empty;
		else break;
	}	
}

void Game::resetRight(int** board, int length, int* positionY, int* positionX) {
	for (int j = 0;j < length;j++) {
		if (((*positionY) < sizeY && (*positionX+j) < sizeX))
			this->board[*positionY][*positionX+j]=empty;
		else break;
	}
}
void Game::spy(int*, int*)
{
	cin >>index>> *positionY >> *positionX;
	if (*kolejka == playerA && (index < numberOfCarriers)) {
			pointer = &carriers[index];
			shotsTakenA[carrier][index] += 1;
		
	}
	else if (index < numberOfCarriersB && *kolejka == playerB) {
			pointer = &carriersB[index];
			shotsTakenB[carrier][index] += 1;
		
	}

	for (int i = (*positionY - 1);i <=(*positionY + 1);i++) {
		for (int j = (*positionX - 1);j <=(*positionX +1);j++) {
			if (*kolejka == playerA) {
				if(i<sizeY && j<sizeX && i>=0 && j>=0)
				isVisible[i][j] = true;
			}
			else if (*kolejka == playerB){
				if (i < sizeY && j < sizeX && i >= 0 && j >= 0) {
					isVisibleB[i][j] = true;
				}
			}
		}
	}

}

void Game::gameLoop(int *kolejka) {

	do {
		turn();
		if (endOfGame) {
			break;
		}
	} while (winA(parts)==false && winB(parts)==false );

	if (winA(parts) == true) cout << "a won" << endl;
	else if (winB(parts) == true) cout << "B won" << endl;
}
bool Game::winA(int* parts) {
	if (parts[playerB] == 0 && allShipsPlaced==true) {
		return true;
	}
	else return false;
}

bool Game::winB(int* parts) {
	if (parts[playerA] == 0 && allShipsPlaced == true) {
		return true;
	}
	else return false;
}

void Game::moveShip(Ship*pointer,char command[50]) {
	
	int movesAvailable = 3;
	int tempIndex = 0;
	cin >> index;
	cin >> shipClass;
	cin >> direction;
	

	if (strcmp(shipClass, "CAR") == 0) {
		if (*kolejka == playerA)
		{
			if (index >= numberOfCarriers) {
				allShipsPresent = true;
			}
			pointer = &carriers[index];
			movesMadeA[carrier][index] += 1;
		}
		else {
			pointer = &carriersB[index];
			movesMadeB[carrier][index] += 1;
			if (index >= numberOfCarriersB) {
				allShipsPresent = true;
			}
		}
		movesAvailable = 2;
		tempIndex = carrier;
	}

	else if (strcmp(shipClass, "BAT") == 0) {
		if (*kolejka == playerA) {
			pointer = &battleships[index];
			movesMadeA[battleship][index] += 1;
			if (index >= numberOfBattleships) {
				allShipsPresent = true;
			}
		}
		else {
			pointer = &battleshipsB[index];
			movesMadeB[battleship][index] += 1;
			if (index >= numberOfBattleshipsB) {
				allShipsPresent = true;
			}
		}
		tempIndex = battleship;
	}

	else if (strcmp(shipClass, "CRU") == 0) {
		if (*kolejka == playerA) {
			pointer = &cruisers[index];
			movesMadeA[cruiser][index] += 1;
			if (index >= numberOfCruisers) {
				allShipsPresent = true;
			}
		}
		else {
			pointer = &cruisersB[index];
			movesMadeB[cruiser][index] += 1;
			if (index >= numberOfCruisersB) {
				allShipsPresent = true;
			}
		}
		tempIndex = cruiser;
	}

	else if (strcmp(shipClass, "DES") == 0) {
		if (*kolejka == playerA) {
			pointer = &destroyers[index];
			movesMadeA[destroyer][index] += 1;
			if (index >= numberOfDestroyers) {
				allShipsPresent = true;
			}
		}
		else {
			pointer = &destroyersB[index];
			movesMadeB[destroyer][index] += 1;
			if (index >= numberOfDestroyersB) {
				allShipsPresent = true;
			}
		}
		tempIndex = destroyer;
	}
	if (pointer->getDirection() == north) {
		directionNumber = 0;
		oppositeDirectionNumber = 1;
	}
	else if (pointer->getDirection() == south) {
		directionNumber = 1;
		oppositeDirectionNumber = 0;
	}
	else if (pointer->getDirection() == west) {
		directionNumber = 2;
		oppositeDirectionNumber = 3;
	}
	else if (pointer->getDirection() == east) {
		directionNumber = 3;
		oppositeDirectionNumber = 2;
	}
	if (direction == forward) {
		takeNewPlaces(pointer, pointer->getShipLength());
	}
	else if (direction == moveLeft) {
		rotateLeft(pointer, pointer->getShipLength());
	}
	else if (direction == moveRight) {
		rotateRight(pointer, pointer->getShipLength());
	}
	if (outside) {
		cout<<"INVALID OPERATION \"MOVE "<<index<<" "<< shipClass<<" "<< direction << "\": SHIP WENT FROM BOARD" << endl;
		endOfGame = true;
	}
	if (shipToClose && outside==false) {
		cout << "INVALID OPERATION \"MOVE " << index << " " <<shipClass<< " " << direction << "\": PLACING SHIP TOO CLOSE TO OTHER SHIP" << endl;
		endOfGame = true;
	}
	if (movesMadeA[tempIndex][index] > movesAvailable || movesMadeB[tempIndex][index] > movesAvailable) {
		cout << "INVALID OPERATION \"MOVE " << index << " " << shipClass << " " << direction << "\": SHIP MOVED ALREADY" << endl;
		endOfGame = true;
	}

}

void Game::setShip(Ship* pointer, bool shipPlace)
{	bool wrongInput = false;
	bool shipPresent = false;
	
	if (shipPlace) {
		cin >> player;
		if (player == 'A') *kolejka = playerA;
		else *kolejka = playerB;
	}

	cin >> *positionY >> *positionX;
	cin >> direction;
	cin >> index;
	cin >> shipClass;
	if (direction == north) {
		directionNumber = 0;
		oppositeDirectionNumber =1;
	}
	else if (direction == south) {
		directionNumber = 1;
		oppositeDirectionNumber = 0;
	}
	else if (direction == west) {
		directionNumber = 2;
		oppositeDirectionNumber = 3;
	}
	else if (direction == east) {
		directionNumber = 3;
		oppositeDirectionNumber =2;
	}
	if (strcmp(shipClass, "CAR") == 0) {
		if (*kolejka == playerA)
		{
			if (index >= numberOfCarriers) {
				allShipsPresent = true;
			}
			pointer = &carriers[index];

		}
		else {
			pointer = &carriersB[index];
			if (index >= numberOfCarriersB) {
				allShipsPresent = true;
			}
		}
	}

	else if (strcmp(shipClass, "BAT") == 0) {
		if (*kolejka == playerA) {
			pointer = &battleships[index];
			if (index >= numberOfBattleships) {
				allShipsPresent = true;
			}
		}
		else {
			pointer = &battleshipsB[index];
			if (index >= numberOfBattleshipsB) {
				allShipsPresent = true;
			}
		}

	}

	else if (strcmp(shipClass, "CRU") == 0) {
		if (*kolejka == playerA) {
			pointer = &cruisers[index];
			if (index >= numberOfCruisers) {
				allShipsPresent = true;
			}
		}
		else {
			pointer = &cruisersB[index];
			if (index >= numberOfCruisersB) {
				allShipsPresent = true;
			}
		}
	}

	else if (strcmp(shipClass, "DES") == 0) {
		if (*kolejka == playerA) {
			pointer = &destroyers[index];
			if (index >= numberOfDestroyers) {
				allShipsPresent = true;
			}
		}
		else {
			pointer = &destroyersB[index];
			if (index >= numberOfDestroyersB) {
				allShipsPresent = true;
			}
		}

	}
		if (allShipsPresent) {
			cout << invalidOperation << " \"PLACE_SHIP " << *positionY << " " << *positionX << " " << direction << " " << index << " " << shipClass << "\": " << "ALL SHIPS OF THE CLASS ALREADY SET";
			endOfGame = true;
		}
		
		
		else {
			pointer->placeShip(positionY, positionX, direction, index);
			if (pointer->getExist() == exist && allShipsPresent == false) {
				cout << invalidOperation << " \"PLACE_SHIP " << *positionY << " " << *positionX << " " << direction << " " << index << " " << shipClass << "\": " << "SHIP ALREADY PRESENT";
				endOfGame = true;

			}
			pointer->setExist(exist);
			if(*positionX<sizeX && *positionY<sizeY)
			takePlaces(pointer, board, pointer->getShipLength(), pointer->getDirection(), pointer->getPositionY(), pointer->getPositionX());
			setEngine(pointer, positionY, positionX, pointer->getShipLength(), direction);
			if (*kolejka == playerA) {
				shipsPlacedA[pointer->getShipId()] += 1;
				parts[playerA] += pointer->getShipLength();
				totalShipsPlacedA += 1;
			}
			else {
				shipsPlacedB[pointer->getShipId()] += 1;
				parts[playerB] += pointer->getShipLength();
				totalShipsPlacedB += 1;
			}
			if (*positionY < sizeY && *positionX < sizeX) {
				this->board[*positionY][*positionX] = radar;
			}

			if (shipPlace) {
				setShip2(pointer);
			}
			out(pointer);
		}
			
		if (shipToClose && shipPlace==false) {
			cout << invalidOperation << " \"PLACE_SHIP " << *positionY << " " << *positionX << " " << direction << " " << index << " " << shipClass << "\": " << "PLACING SHIP TOO CLOSE TO OTHER SHIP";
			endOfGame = true;
		}
		if (shipToClose && shipPlace) {
			cout << invalidOperation << " \"SHIP "<<player<<" " << *positionY << " " << *positionX << " " << direction << " " << index << " " << shipClass << " " << tab << "\": " << "PLACING SHIP TOO CLOSE TO OTHER SHIP";
			endOfGame = true;
		}
		if (outside) {
		cout << invalidOperation << " \"PLACE_SHIP " << *positionY << " " << *positionX << " " << direction << " " << index << " " << shipClass << "\": " << "NOT IN STARTING POSITION";
		endOfGame = true;
		}
		
		if (totalShipsPlacedA == totalFleetA && totalShipsPlacedB == totalFleetB){
		allShipsPlaced = true;
	}
		if (onReef) {
			cout << invalidOperation << " \"PLACE_SHIP " << *positionY << " " << *positionX << " " << direction << " " << index << " " << shipClass << "\": " << "PLACING SHIP ON REEF";
			endOfGame = true;
		}
}

void Game::setShip2(Ship* pointer)
{
	int tempX = *pointer->getPositionX();
	int tempY = *pointer->getPositionY();
	cin >> tab;
	for (int i = 0;i < pointer->getShipLength();i++) {
		if (i != 0) {
			tempX += directionArray[directionNumber][1];
			tempY += directionArray[directionNumber][0];
		}
		if (tab[i] == '0') {
			this->board[tempY][tempX] = damaged;
			parts[*kolejka]--;
		}
	}
}

void Game::initPosition()
{
	cin >> player;
	if (player=='A') {
		*kolejka = playerA;
	}
	else {
		*kolejka = playerB;
	}
	cin >> boundYmin[*kolejka] >> boundXmin[*kolejka] >> boundYmax[*kolejka] >> boundXmax[*kolejka];
}

void Game::setReef()
{
	cin >> forbiddenY[numberOfReefs] >> forbiddenX[numberOfReefs];
	this->board[forbiddenY[numberOfReefs]][forbiddenX[numberOfReefs]] = reef;
	numberOfReefs++;
}
void Game::out(Ship*pointer)
{	int tempX= *pointer->getPositionX();
	int tempY = *pointer->getPositionY();
	if (tempX > boundXmax[*kolejka] || tempX<boundXmin[*kolejka] || tempY>boundYmax[*kolejka] || tempY < boundYmin[*kolejka]) {
		outside = true;
	}
	if (tempX < sizeX && tempY < sizeY) {
		for (int i = 0;i < (pointer->getShipLength() - 1);i++) {
			tempY += directionArray[directionNumber][0];
			tempX += directionArray[directionNumber][1];
			if (tempX > boundXmax[*kolejka] || tempX<boundXmin[*kolejka] || tempY>boundYmax[*kolejka] || tempY < boundYmin[*kolejka]) {
				outside = true;
			}
		}
	}
	else outside = true;
	
}
void Game::extendedShooting(Ship* pointer)
{
	int tempIndex=0;
	cin >> index >> shipClass;
	if (strcmp(shipClass, "CAR") == 0) {
		if (*kolejka == playerA)
		{
			if (index >= numberOfCarriers) {
				allShipsPresent = true;
			}
			pointer = &carriers[index];
			shotsTakenA[carrier][index] += 1;
		}
		else {
			pointer = &carriersB[index];
			shotsTakenB[carrier][index] += 1;
			if (index >= numberOfCarriersB) {
				allShipsPresent = true;
			}
		}
		tempIndex = carrier;
	}

	else if (strcmp(shipClass, "BAT") == 0) {
		if (*kolejka == playerA) {
			pointer = &battleships[index];
			shotsTakenA[battleship][index] += 1;
			if (index >= numberOfBattleships) {
				allShipsPresent = true;
			}
		}
		else {
			pointer = &battleshipsB[index];
			shotsTakenB[battleship][index] += 1;
			if (index >= numberOfBattleshipsB) {
				allShipsPresent = true;
			}
		}
		tempIndex = battleship;
	}

	else if (strcmp(shipClass, "CRU") == 0) {
		if (*kolejka == playerA) {
			pointer = &cruisers[index];
			shotsTakenA[cruiser][index] += 1;
			if (index >= numberOfCruisers) {
				allShipsPresent = true;
			}
		}
		else {
			pointer = &cruisersB[index];
			shotsTakenB[cruiser][index] += 1;
			if (index >= numberOfCruisersB) {
				allShipsPresent = true;
			}
		}
		int tempIndex = cruiser;
	}

	else if (strcmp(shipClass, "DES") == 0) {
		if (*kolejka == playerA) {
			pointer = &destroyers[index];
			shotsTakenA[destroyer][index] += 1;
			if (index >= numberOfDestroyers) {
				allShipsPresent = true;
			}
		}
		else {
			pointer = &destroyersB[index];
			shotsTakenB[destroyer][index] += 1;
			if (index >= numberOfDestroyersB) {
				allShipsPresent = true;
			}
		}
		tempIndex = destroyer;
	}
	
	shoot(positionY, positionX, board);
	if (board[pointer->getCannonPositionY()][pointer->getCannonPositionX()] == damaged) {
		cout << invalidOperation << " \"SHOOT " << index << " " << shipClass << " " << " " << *positionY << " " << *positionX << "\": SHIP CANNOT SHOOT" << endl;
		endOfGame = true;
	}
	range = pointer->getShipLength();
	if (range <= 4) {
		if (pointer->getShotDistance(pointer->getCannonPositionY(), pointer->getCannonPositionX(), *positionY, *positionX) <= range) {
	}
		else {
			cout << invalidOperation << " \"SHOOT " << index << " " << shipClass << " " << " " << *positionY << " " << *positionX << "\": SHOOTING TOO FAR" << endl;
			endOfGame = true;
		}
}
	if ((shotsTakenA[tempIndex][index]>pointer->getShipLength()) || (shotsTakenB[tempIndex][index] > pointer->getShipLength())) {
		cout << invalidOperation << " \"SHOOT " << index << " " << shipClass << " " << " " << *positionY << " " << *positionX << "\": TOO MANY SHOOTS" << endl;
		endOfGame = true;
	}
}
void Game::setTo0(int wyzeruj)
{
	wyzeruj = 0;
}

void Game::takeNewPlaces(Ship* pointer,int length)
{
	if (pointer->getDirection() == east) {
		resetLeft(board, length, pointer->getPositionY(), pointer->getPositionX());
		*pointer->getPositionX() += 1;
		if (*pointer->getPositionX() > sizeX) outside = true;
	}
	else if (pointer->getDirection() == west) {
		resetRight(board, length, pointer->getPositionY(), pointer->getPositionX());
		*pointer->getPositionX() -= 1;
		if (*pointer->getPositionX() < 0) outside = true;
	}
	else if (pointer->getDirection() == north) {
		resetDown(board, length, pointer->getPositionY(), pointer->getPositionX());
		*pointer->getPositionY() -= 1;
		if (*pointer->getPositionY() < 0) outside = true;
	}
	else if (pointer->getDirection() == south) {
		resetUp(board, length, pointer->getPositionY(), pointer->getPositionX());
		*pointer->getPositionY() += 1;
		if (*pointer->getPositionY() > sizeY) outside = true;
	}
if(outside==false)	takePlaces(pointer, board, length, pointer->getDirection(), pointer->getPositionY(), pointer->getPositionX());
}

void Game::rotateLeft(Ship* pointer, int length)
{
	takeNewPlaces(pointer, length);

		if (pointer->getDirection() == east) {
			resetLeft(board, length, pointer->getPositionY(), pointer->getPositionX());
			*pointer->getPositionY() -= (length - 1);
			pointer->setDirection(north);
			directionNumber = 0;
			oppositeDirectionNumber = 1;
		}
		else if (pointer->getDirection() == west) {
			resetRight(board, length, pointer->getPositionY(), pointer->getPositionX());
			*pointer->getPositionY() += (length - 1);
			pointer->setDirection(south);
			directionNumber = 1;
			oppositeDirectionNumber = 0;
		}
		else if (pointer->getDirection() == north) {
			resetDown(board, length, pointer->getPositionY(), pointer->getPositionX());
			*pointer->getPositionX() -= (length - 1);
			pointer->setDirection(west);
			directionNumber =2;
			oppositeDirectionNumber =3;
		}
		else if (pointer->getDirection() == south) {
			resetUp(board, length, pointer->getPositionY(), pointer->getPositionX());
			*pointer->getPositionX() += (length - 1);
			pointer->setDirection(east);
			directionNumber =3;
			oppositeDirectionNumber = 2;
		}
if(outside==false)	takePlaces(pointer, board, length, pointer->getDirection(), pointer->getPositionY(), pointer->getPositionX());
}

void Game::rotateRight(Ship* pointer, int length)
{
	takeNewPlaces(pointer, length);
	if (pointer->getDirection() ==east) {
		resetLeft(board, length, pointer->getPositionY(), pointer->getPositionX());
		*pointer->getPositionY()+= (length - 1);
		pointer->setDirection(south);
		directionNumber = 1;
		oppositeDirectionNumber = 0;
	}
	else if (pointer->getDirection() == west) {
		resetRight(board, length, pointer->getPositionY(), pointer->getPositionX());
		*pointer->getPositionY() -= (length - 1);	
		pointer->setDirection(north);
		directionNumber = 0;
		oppositeDirectionNumber = 1;
	}
	else if (pointer->getDirection() ==north) {
		resetDown(board, length, pointer->getPositionY(), pointer->getPositionX());
		*pointer->getPositionX()+= (length - 1);
		pointer->setDirection(east);
		directionNumber = 3;
		oppositeDirectionNumber = 2;
	}
	else if (pointer->getDirection() == south) {
		resetUp(board, length, pointer->getPositionY(), pointer->getPositionX());
		*pointer->getPositionX()-= (length - 1);
		pointer->setDirection(west);
		directionNumber = 2;
		oppositeDirectionNumber =3;

	}
	if(outside==false)takePlaces(pointer, board, length, pointer->getDirection(), pointer->getPositionY(), pointer->getPositionX());
}

void Game::setEngine(Ship* pointer, int* positionY, int* positionX, int length, char direction)
{
	int tempXC = *positionX;
	int tempYC = *positionY;
	int tempXE = *positionX;
	int tempYE = *positionY;
	if (direction == north) {
		tempYE += (length - 1);
		tempYC += 1;
	}
	else if (direction ==south) {
		tempYE -= (length - 1);
		tempYC -= 1;
	}
	else if (direction == west) {
		tempXE += (length - 1);
		tempXC +=1;
	
	}
	else if (direction == east) {
		tempXE -= (length - 1);
		tempXC -= 1;

	}
	pointer->setCannonPositionX(tempXC);
	pointer->setCannonPositionY(tempYC);
	pointer->setEnginePositionX(tempXE);
	pointer->setEnginePositionY(tempYE);
	if (pointer->getEnginePositionY() < sizeY && pointer->getEnginePositionX() < sizeX) {
		this->board[pointer->getCannonPositionY()][pointer->getCannonPositionX()] = cannon;
		this->board[pointer->getEnginePositionY()][pointer->getEnginePositionX()] = engine;
		
	}
}

void Game::setShooted(bool s)
{
	this->aShooted = s;
}