#ifndef BOARDFUNCTIONS_H
#define BOARDFUNCTIONS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void Board::appendSpace(int position, string name, bool ownable, bool owned, int owner, int cost, int rent, int mortgage)
{
    Space *newSpace = new Space;
    Space *nodePtr;

    newSpace -> spaceNumber = position;
    newSpace -> spaceName = name;
    newSpace -> isOwnable = ownable;
    newSpace -> isOwned = owned;
    newSpace -> spaceOwner = owner;
    newSpace -> spaceCost = cost;
    newSpace -> spaceRent = rent;
    newSpace -> spaceMortgage = mortgage;
    newSpace -> next = nullptr;

    if(!head)
    {
        head = newSpace;
    }
    else
    {
        nodePtr = head;
        
        while(nodePtr -> next)
        {
            nodePtr = nodePtr -> next;
        }
        
        nodePtr -> next = newSpace;
    }
}

string Board::getName(int position)
{
    string name;
    
    Space *temp = new Space;
    temp = head;
    
    while(temp -> spaceNumber != position)
    {
        temp = temp -> next;
    }
    name = temp -> spaceName;

    return name;
}

int Board::getCost(int position)
{
    int cost;
    
    Space *temp = new Space;
    temp = head;
    
    while(temp -> spaceNumber != position)
    {
        temp = temp -> next;
    }
    cost = temp -> spaceCost;

    return cost;
}

bool Board::getisOwnable(int position)
{
    bool result;
   
    Space *temp = new Space;
    temp = head;
    
    while(temp -> spaceNumber != position)
    {
        temp = temp -> next;
    }
    result = temp -> isOwnable;

    return result;
}

bool Board::getisOwned(int position)
{
    bool result;
   
    Space *temp = new Space;
    temp = head;
    
    while(temp -> spaceNumber != position)
    {
        temp = temp -> next;
    }
    result = temp -> isOwned;

    return result;
}

int Board::getOwner(int position)
{
    int owner;
    
    Space *temp = new Space;
    temp = head;
  
    while(temp -> spaceNumber != position)
    {
        temp = temp -> next;
    }
    owner = temp -> spaceOwner;

    return owner;
}

int Board::getRent(int position)
{
    int rent;
 
    Space *temp = new Space;
    temp = head;
    
    while(temp -> spaceNumber != position)
    {
        temp = temp -> next;
    }
    rent = temp -> spaceRent;

    return rent;
}

int Board::getMortgage(int position)
{
    int mortgage;
 
    Space *temp = new Space;
    temp = head;
    
    while(temp -> spaceNumber != position)
    {
        temp = temp -> next;
    }
    mortgage = temp -> spaceMortgage;

    return mortgage;
}

void Board::setisOwned(int position, bool owned)
{
    Space *temp = new Space;
    temp = head;

    while(temp -> spaceNumber != position)
    {
        temp = temp -> next;
    }
    if(temp -> spaceNumber == position)
    {
        temp -> isOwned = owned;
    }
}

void Board::setOwner(int position, int owner)
{
    Space *temp = new Space;
    temp = head;

    while(temp -> spaceNumber != position)
    {
        temp = temp -> next;
    }
    if(temp -> spaceNumber == position)
    {
        temp -> spaceOwner = owner;
    }
}

void Board::constructMonopolyBoard()
{
    appendSpace(0, "Go", false, false, -1, 0, 0 , 0);
    appendSpace(1, "Mediterranean Avenue", true, false, -1, 60, 2, 30);
    appendSpace(2, "Community Chest", false, false, -1, 0, 0, 0);
    appendSpace(3, "Baltic Avenue", true, false, -1, 60, 4, 30);
    appendSpace(4, "Income Tax", false, false, -1, 0, 0, 0);
    appendSpace(5, "Reading Railroad", true, false, -1, 200, 25, 100);
    appendSpace(6, "Oriental Avenue", true, false, -1, 100, 6, 50);
    appendSpace(7, "Chance", false, false, -1, 0, 0, 0);
    appendSpace(8, "Vermont Avenue", true, false, -1, 100, 6, 50);
    appendSpace(9, "Connecticut Avenue", true, false, -1, 120, 8, 60);
    appendSpace(10, "Jail / Just Visiting", false, false, -1, 0, 0, 0);
    appendSpace(11, "St. Charles Place", true, false, -1, 140, 10, 70);
    appendSpace(12, "Electric Company", true, false, -1, 150, 0, 75);
    appendSpace(13, "States Avenue", true, false, -1, 140, 10, 70);
    appendSpace(14, "Virginia Avenue", true, false, -1, 160, 12, 80);
    appendSpace(15, "Pennsylvania Railroad", true, false, -1, 200, 25, 100);
    appendSpace(16, "St. James Place", true, false, -1, 180, 14, 90);
    appendSpace(17, "Community Chest", false, false, -1, 0, 0, 0);
    appendSpace(18, "Tennessee Avenue", true, false, -1, 180, 14, 90);
    appendSpace(19, "New York Avenue", true, false, -1, 200, 16, 100);
    appendSpace(20, "Free Parking", false, false, -1, 0, 0, 0);
    appendSpace(21, "Kentucky Avenue", true, false, -1, 220, 18, 110);
    appendSpace(22, "Chance", false, false, -1, 0, 0, 0);
    appendSpace(23, "Indiana Avenue", true, false, -1, 220, 18, 110);
    appendSpace(24, "Illinois Avenue", true, false, -1, 240, 20, 120);
    appendSpace(25, "B. & O. Railroad", true, false, -1, 200, 25, 100);
    appendSpace(26, "Atlantic Avenue", true, false, -1, 260, 22, 130);
    appendSpace(27, "Ventnor Avenue", true, false, -1, 260, 22, 130);
    appendSpace(28, "Water Works", true, false, -1, 150, 0, 75);
    appendSpace(29, "Marvin Gardens", true, false, -1, 280, 24, 140);
    appendSpace(30, "Go To Jail", false, false, -1, 0, 0, 0);
    appendSpace(31, "Pacific Avenue", true, false, -1, 300, 26, 150);
    appendSpace(32, "North Carolina Avenue", true, false, -1, 300, 26, 150);
    appendSpace(33, "Community Chest", false, false, -1, 0, 0, 0);
    appendSpace(34, "Pennsylvania Avenue", true, false, -1, 320, 28, 160);
    appendSpace(35, "Short Line", true, false, -1, 200, 25, 100);
    appendSpace(36, "Chance", false, false, -1, 0, 0, 0);
    appendSpace(37, "Park Place", true, false, -1, 350, 35, 175);
    appendSpace(38, "Luxury Tax", false, false, -1, 0, 0, 0);
    appendSpace(39, "Boardwalk", true, false, -1, 400, 50, 200);
}

int Board::rollDice()
{
    int dice1 = (rand() % 6) + 1;
    int dice2 = (rand() % 6) + 1;

    return dice1 + dice2;
}

void Board::rentPayment(ostream& file, Players& p, int player, Players& o, int owner, int payment)
{
    p.setMoney(p.getMoney() - (payment));
    file << "\nPlayer " << player << " is charged $" << payment << " for rent.";
    o.setMoney(o.getMoney() + (payment));
    file << "\nPlayer " << owner << " receives $" << payment << " for rent.";
}

void Board::boardPayment(ostream& file, Players& b, Players& p, int player, int payment)
{
    if(payment > 0) //player is gaining money
    {
        if(b.getMoney() >= payment)
        {
            p.setMoney(p.getMoney() + payment);
            file << "\nPlayer " << player << " gains $" << payment << ".";
            b.setMoney(b.getMoney() - payment);
        }
        else
        {
            file << "\nThe bank does not have enough money to complete this transaction!";
        }
    }
    else //player is losing money
    {
        p.setMoney(p.getMoney() + payment);
        file << "\nPlayer " << player << " loses $" << -1 * payment << ".";
        b.setMoney(b.getMoney() - payment);
    }
}

void Board::chance(ostream& file, Board& board, Players& b, Players& p, int player, int chance, int space)
{
    if(chance == 1)
    {
        file << "\nThe Chance card reads \"Advance to Go (Collect $200)\".";
        space = 0;
        p.setSpace(space);
        board.boardPayment(file, b, p, player, 200); //adds $200
    }
    else if(chance == 2)
    {
        file << "\nThe Chance card reads \"Go To Jail. Go directly to jail, do not pass Go, do not collect $200\".";
        space = 10;
        p.setSpace(space);
        file << "\nPlayer " << player << " is in jail.";
    }
    else if(chance == 3)
    {
        file << "\nThe Chance card reads \"Speeding fine $15\".";
        if(p.getMoney() >= 15)
        {
            board.boardPayment(file, b, p, player, -15); //subtracts $15
        }
        else
        {
            file << "\nPlayer " << player << " cannot afford Speeding Fine.";
            int mortgage = board.bankruptcyChecker(file, player, space, 15, p, b, board);
            p.setMoney(p.getMoney() + mortgage);
            
            if(p.getMoney() >= 15)
            {
                board.boardPayment(file, b, p, player, -15); //subtracts $15
            }
            else //declares bankruptcy for player
            {
                board.bankrupt(file, b, p, player); //gives player's remaining cash back to the bank
            }
        }
    }
    else if(chance == 4)
    {
        file << "\nThe Chance card reads \"Bank pays you dividend of $50\".";
        board.boardPayment(file, b, p, player, 50); //adds $50
    }
    else if(chance == 5)
    {
        file << "\nThe Chance card reads \"Your building loan matures. Collect $150\".";
        board.boardPayment(file, b, p, player, 150); //adds $150
    }
}

void Board::communityChest(ostream& file, Board& board, Players& b, Players& p, int player, int chest, int space)
{
    if(chest == 1)
    {
        file << "\nThe Community Chest card reads \"Advance to Go (Collect $200)\".";
        space = 0;
        p.setSpace(space);
        board.boardPayment(file, b, p, player, 200); //adds $200
    }
    else if(chest == 2)
    {
        file << "\nThe Community Chest card reads \"Go To Jail. Go directly to jail, do not pass Go, do not collect $200\".";
        space = 10;
        p.setSpace(space);
        file << "\nPlayer " << player << " is in jail.";
    }
    else if(chest == 3)
    {
        file << "\nThe Community Chest card reads \"Life insurance matures. Collect $100\".";
        board.boardPayment(file, b, p, player, 100); //adds $100
    }
    else if(chest == 4)
    {
        file << "\nThe Community Chest card reads \"Doctor’s fee. Pay $50\".";

        if(p.getMoney() >= 50)
        {
            board.boardPayment(file, b, p, player, -50); //subtracts $50
        }
        else // BANKRUPTCY CHECKER
        {
            file << "\nPlayer " << player << " cannot afford Doctor's Fee.";

            int mortgage = board.bankruptcyChecker(file, player, space, 50, p, b, board);
            p.setMoney(p.getMoney() + mortgage);

            if(p.getMoney() >= 50)
            {
                board.boardPayment(file, b, p, player, -50); //subtracts $50
            }
            else //declares bankruptcy for player
            {
                board.bankrupt(file, b, p, player); //gives player's remaining cash back to the bank
            }
        }
    }
    else if(chest == 5)
    {
        file << "\nThe Community Chest card reads \"Pay school fees of $50\".";
        if(p.getMoney() >= 50)
        {
            board.boardPayment(file, b, p, player, -50); //subtracts $50
        }
        else // BANKRUPTCY CHECKER ****
        {
            file << "\nPlayer " << player << " cannot afford school fees.";

            int mortgage = board.bankruptcyChecker(file, player, space, 50, p, b, board);
            p.setMoney(p.getMoney() + mortgage);

            if(p.getMoney() >= 50)
            {
                board.boardPayment(file, b, p, player, -50); //subtracts $50
            }
            else //declares bankruptcy for player
            {
                board.bankrupt(file, b, p, player); //gives player's remaining cash back to the bank
            }
        }
    }
}

int Board::calculateAssets(int player, int money)
{
    int totalAssets = 0;

    Space *temp = new Space;
    temp = head;

    while(temp -> spaceOwner == player)
    {
        totalAssets += temp -> spaceCost;
        temp = temp -> next;
    }
    totalAssets += money;
  
    return totalAssets;
}

int Board::bankruptcyChecker(ostream& file, int player, int location, int moneyOwed, Players& p, Players& b, Board& board)
{
    file << "\nPlayer " << player << " has $" << p.getMoney() << " and needs $" << moneyOwed << " .";
    file << "\nPlayer " << player << " must begin mortgaging properties.";

    int mortgage = 0;

    Space *temp = new Space;
    temp = head;
  
    while(moneyOwed > mortgage + p.getMoney() && temp != nullptr)
    {
        if(temp -> spaceOwner == player)
        {
            mortgage += temp -> spaceMortgage;
            file << "\nPlayer " << player << " mortgaged " << temp -> spaceName << " for $" << temp -> spaceMortgage;
            b.setMoney(b.getMoney() - temp -> spaceMortgage); // takes mortgage value from bank
            board.setisOwned(temp -> spaceNumber, false);
            board.setOwner(temp -> spaceNumber, -1);
        }
        temp = temp -> next;
    }
    
    if(mortgage == 0)
    {
        file << "\nPlayer " << player << " has no properties available to mortgage.";
    }
    
    return mortgage;
}

void Board::bankrupt(ostream& file, Players& b, Players& p, int player)
{
    file << "\nPlayer " << player << " does not have enough money.";
    b.setMoney(b.getMoney() + p.getMoney());
    p.setMoney(0);
    p.setBankruptcy(true);
    file << "\n\nPlayer " << player << " is bankrupt!!!" << endl;
    bankruptCounter++;
}

#endif
