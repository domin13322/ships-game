#pragma once
#include<iostream>
#include"game.h"
using namespace std;
int main(){
    int sizeY = 21, sizeX = 10;
    int tur = 0;
    int** board{};
    int* parts{};
    Game gra(board,sizeX,sizeY,parts);
    gra.setParts(parts);
    gra.setBoard(board);   
    int* kolejka =&tur;
    gra.gameLoop(kolejka);
    
    return 0;
}