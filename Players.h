#ifndef PLAYERS_H
#define PLAYERS_H

#include <iostream>

using namespace std;

class Players
{
	private:
    int playerMoney;
    int playerSpace;
    bool playerBankruptcy;
    
	public:
		Players()
		{
            playerMoney = 1500;
            playerSpace = 0;
            playerBankruptcy = false;
		}
		
        //functions
        void setMoney(int);
        void setSpace(int);
        void setBankruptcy(bool);
        int getMoney();
        int getSpace();
        bool getBankruptcy();
    
};

#endif
