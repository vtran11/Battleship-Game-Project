
#include "Board.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;


Board::Board(void)
{
    
    for (int i =0; i< 10; i++) {
        for(int j=0; j<10; j++){
            score[i][j]=' ';
        }
    }
    //score[10][10] = {' '};
}


void Board::addShip(char type, int x1, int y1, int x2, int y2)
{
    if (shipList.size() <= 10)
        shipList.push_back(Ship::makeShip(type,x1,y1,x2,y2));
}


void Board::print(void)
{
    cout <<"   a b c d e f g h i j" << endl;
    cout <<"  +-------------------+" << endl;
    for (int i=0; i < 10; i++){
        cout <<" "<<i<<"|";
        for(int j=0;j<10; j++){
            if(j<9)
            cout << score[i][j] <<" ";
           else if(j==9)
               cout << score[i][j];
        }
        cout << "|" << endl;
    }
    cout <<"  +-------------------+" <<endl;}


void Board::hit(char c, int i)
{
    if (c<'a' || c >'j')
        throw invalid_argument("invalid input");
    if (i< 0 || i> 9)
        throw invalid_argument("invalid input");
    if (score[i][c-'a'] == ' ') {
        Ship* sTemp = shipAt(c-'a', i);
        if (sTemp){
            score[i][c-'a'] = '*';
            sTemp->decreaseLevel();
            if (sTemp->level()==0){
                cout  << sTemp->name() << " sunk" << endl;
            }
        }
        else
            score[i][c-'a'] = 'x';
    }

}

Ship* Board::shipAt(int x, int y)
{
    Ship* sTemp;
    vector<Ship *>::iterator iter;
    vector<Ship *>::iterator end = shipList.end();
    for (iter = shipList.begin(); iter!=end; iter++) {
        if((*iter)->includes(x,y)==true){
            sTemp = *iter;
            return sTemp;
        }
    }
    return NULL;
    
}
int Board::level(void)
{
    int sumLev=0;
    std::vector<Ship *>::iterator iter;
    std::vector<Ship *>:: iterator end = shipList.end();
    for (iter = shipList.begin(); iter != end; iter++)
    {
        sumLev+=(*iter)->level();
    }
    
    return sumLev;
}

