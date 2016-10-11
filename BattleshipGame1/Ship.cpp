
#include "Ship.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int Ship::getX(int i) const
{
    if (i == 0)
        return x1;
    else if(i <= (size() - 1))
        return x2;
    else return 0;
}

int Ship::getY(int i) const
{
    if (i == 0)
        return y1;
    else if(i <= (size() - 1))
        return y2;
    else return 0;
}

void Ship::print(void) const
{
    cout<< name() <<" from ("<<getX(0)<<","<<getY(0)<<")";
    cout<< " to ("<<getX(size()-1) <<","<<getY(size()-1)<<")"<<endl;
}

bool Ship::includes(int x, int y)
{
    if(x == getX(0))
    {
        if ((y>= getY(0) && y<= getY(size()-1)) || (y>= getY(size()-1) && y<= getY(0)))
            return  true;
        else
            return false;
    }
    
    else if (y == getY(0))
    {
        if ((x>=getX(0) && x<=getX(size()-1)) || (x>= getX(size()-1) && x<=getX(0)))
        
            return true;
        else
            return false;
    }
   else return false;
}


int Ship::level(void) const
{
    return lev;
}

void Ship::decreaseLevel(void)
{
    if(lev >= 1)
        lev--;
    else
        lev =0;
}

Ship* Ship::makeShip(char ch, int x1, int y1, int x2, int y2)
{
    
    switch (ch) {
        case 'A':{
            AircraftCarrier* Aptr = new AircraftCarrier(x1, y1, x2, y2);
            return Aptr;
            break;
        }
        case 'B':{
            BattleShip* Bptr = new BattleShip(x1, y1, x2, y2);
            return Bptr;
            break;
        }
        case 'C':{
            Cruiser* Cptr = new Cruiser(x1, y1, x2, y2);
            return Cptr;
            break;
        }
        case 'D':{
            Destroyer* Dptr = new Destroyer(x1, y1, x2, y2);
            return Dptr;
            break;
        }
        default:{
            throw invalid_argument("invalid configuration");
            return 0;
            break;
        }
    }
}

void Ship::setPos(int a1, int b1, int a2, int b2)
{
    Ship::x1=a1;
    Ship::y1=b1;
    Ship::x2=a2;
    Ship::y2=b2;
    bool check = checkConfig(x1,y1,x2,y2);
    if (check == false)
        throw invalid_argument ("invalid configuration");
}

bool Ship::checkConfig(int x1, int y1, int x2, int y2)
{
    if (x1 == x2)
    {
        if (y1<y2 && size()-1 == y2 - y1)
            return true;
        
        else
        if (y1>y2 && size()-1 == y1 - y2)
            return true;
        
        else
            return false;
    }
    
    else if (y1 == y2)
    {
        if (x1 < x2 && size()-1 == x2 - x1)
            return true;
        
        else
        if (x1>x2 && size()-1 == x1 -x2)
            return true;
        
        else
            return false;
    }
    
    else
        return false;
}

//Aircraft
AircraftCarrier::AircraftCarrier(int x1, int y1, int x2, int y2)
{
    lev =size();
    setPos(x1, y1, x2, y2);
}

const char* AircraftCarrier::name() const
{
    return "AircraftCarrier";
}

int AircraftCarrier::size(void) const
{
    return 5;
}

//battleship
BattleShip::BattleShip(int x1, int y1, int x2, int y2)
{
    lev = size();
    setPos(x1, y1, x2, y2);
}

const char* BattleShip::name() const
{
    return "BattleShip";
}

int BattleShip::size(void) const
{
    return 4;
}

//Cruiser
Cruiser::Cruiser(int x1, int y1, int x2, int y2)
{
    lev = size();
    setPos(x1, y1, x2, y2);
}

const char* Cruiser::name() const
{
    return "Cruiser";
}

int Cruiser::size(void) const
{
    return 3;
}

//Destroyer
Destroyer::Destroyer(int x1, int y1, int x2, int y2)
{
    lev =size();
    setPos(x1, y1, x2, y2);
}

const char* Destroyer::name() const
{
    return "Destroyer";
}

int Destroyer::size(void) const
{
    return 2;
}