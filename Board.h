#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Players.h"

using namespace std;

class Board
{
    private:
        struct Space
		{
            //node function variables
			Space *next;

            //gameboard variables
            int spaceNumber;
            string spaceName;
            bool isOwnable;
            bool isOwned;
            int spaceCost;
            int spaceRent;
            int spaceMortgage;
            int spaceOwner;
		};

        Space *head;
    
	public:
		// constructor
		Board()
		{
			head = nullptr;
		}
    
        //destructor
        ~Board()
        {
            Space *nodePtr;
            Space *nextNode;
            nodePtr = head;
    
            while(nodePtr != nullptr)
            {
                nextNode = nodePtr -> next;
                delete nodePtr;
                nodePtr = nextNode;
            }
        }

        //getters
        string getName(int);
        bool getisOwnable(int);
        bool getisOwned(int);
        int getOwner(int);
        int getCost(int);
        int getRent(int);
        int getMortgage(int);

        //setters
        void setisOwned(int, bool);
        void setOwner(int, int);
  
		//functions 
        void constructMonopolyBoard();
        void appendSpace(int, string, bool, bool, int, int, int, int);
        int rollDice();
        void rentPayment(ostream&, Players&, int, Players&, int, int);
        void boardPayment(ostream&, Players&, Players&, int, int);
        void chance(ostream&, Board&, Players&, Players&, int, int, int);
        void communityChest(ostream&, Board&, Players&, Players&, int, int, int);
        int calculateAssets(int, int);
        int bankruptcyChecker(ostream&, int, int, int, Players&, Players&, Board&);
        void bankrupt(ostream&, Players&, Players&, int);
};

//global variable
int bankruptCounter = 0;

#endif
