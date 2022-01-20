#include "Board.h"
#include "BoardFunctions.h"
#include "Players.h"
#include "PlayerFunctions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

int main()
{
    fstream file("MonopolyFile.txt", ios::out); //create outgoing file where game actions are recorded

    Board board; //initialize game board
    board.constructMonopolyBoard();
  
    int numberofPlayers = 0;
    string input = "";
    while(true)
    {
        cout << "\nEnter the number of players (minimum 2, maximum 8): ";
        getline(cin, input);
        bool check = true;
        
        for(int i = 0; i < input.length(); i++)
        {
            if(!isdigit(input[i]))
            {
                check = false;
            }
        }
        if(check)
        {
            numberofPlayers = stoi(input);
            if(numberofPlayers > 1 && numberofPlayers < 9)
            {
                break;
            }
        }
    }
    
    Players players[numberofPlayers + 1]; //initialize players plus bank account
    
    int bank = 0; //player[0] will represent the banker
    players[bank].setMoney(20580 - (1500 * numberofPlayers)); //sets bank account with max amount of money (excluding starting amount for each player)
    
    file << "The bank will begin the game with $" << players[bank].getMoney() << "." << endl;

    Board dice; //initialize dice
    unsigned seed = time(0);
    srand(seed);
    
    int winner;
    
    while(bankruptCounter < numberofPlayers - 1) //game loop
    {
        for(int i = 1; i < numberofPlayers + 1; i++)
        {
            if(players[i].getBankruptcy() == false)
            {
                file << "\nIt's Player's " << i << " turn.";

                int diceRoll = dice.rollDice();
                file << "\nPlayer " << i << " rolls " << diceRoll << ".";
                players[i].setSpace(players[i].getSpace() + diceRoll);

                if(players[i].getSpace() > 39) //wraps player around board
                {
                    players[i].setSpace(players[i].getSpace() - 40);
                    file << "\nPlayer " << i << " passed Go!";
                    board.boardPayment(file, players[bank], players[i], i, 200); //adds $200 for passing go
                }

                int space = players[i].getSpace(); //assigns players current space to variable

                if(board.getisOwnable(space) == true) //checks if space player landed on is ownable
                {
                    file << "\nPlayer " << i << " lands on " << board.getName(space) << ".";
                    
                    if(board.getisOwned(space) == true) //charges rent if it is owned
                    {
                        int owner = board.getOwner(space); //assigns owner of space to variable

                        if(owner != i && (space == 12 || space == 28)) // utilities rent
                        {
                            if(players[i].getMoney() >= (diceRoll * 4))
                            {
                                board.rentPayment(file, players[i], i, players[owner], owner, diceRoll * 4);
                            }
                            else // BANKRUPTCY CHECKER
                            {
                                file << "\nPlayer " << i << " cannot afford rent at " << board.getName(space) << ".";
                                int mortgage = board.bankruptcyChecker(file, i, space, diceRoll * 4, players[i], players[bank], board);
                                players[i].setMoney(players[i].getMoney() + mortgage);

                                if(players[i].getMoney() >= (diceRoll * 4))
                                {
                                    board.rentPayment(file, players[i], i, players[owner], owner, diceRoll * 4);
                                }
                                else //declares bankruptcy for player
                                {
                                    board.bankrupt(file, players[bank], players[i], i); //gives player's remaining cash back to the bank
                                }
                            }
                        }
                        else if(owner != i)
                        {
                            if(players[i].getMoney() >= board.getRent(space))
                            {
                                board.rentPayment(file, players[i], i, players[owner], owner, board.getRent(space));
                            }
                            else // BANKRUPTCY CHECKER
                            {
                                file << "\nPlayer " << i << " cannot afford rent at " << board.getName(space) << ".";
                                int mortgage = board.bankruptcyChecker(file, i, space, board.getRent(space), players[i], players[bank], board);
                                players[i].setMoney(players[i].getMoney() + mortgage);

                                if(players[i].getMoney() >= board.getRent(space))
                                {
                                    board.rentPayment(file, players[i], i, players[owner], owner, board.getRent(space));
                                }
                                else //declares bankruptcy for player
                                {
                                    board.bankrupt(file, players[bank], players[i], i); //gives player's remaining cash back to the bank
                                }
                            }
                        }
                        else
                        {
                            file << "\nPlayer " << i << " owns " << board.getName(space) << ".";
                        }
                    }
                    else
                    {
                        if(players[i].getMoney() >= board.getCost(space)) //attempts to buy space if it isnt owned
                        {
                            players[i].setMoney(players[i].getMoney() - board.getCost(space));
                            file << "\nPlayer " << i << " buys " << board.getName(space) << " for $" <<  board.getCost(space) << ".";
                            board.setisOwned(space, true); //sets location to owned
                            board.setOwner(space, i); //assigns property to player
                            players[bank].setMoney(players[bank].getMoney() + board.getCost(space)); //cost of property added to bank
                        }
                        else //player doesnt have enough money to purchase space
                        {
                            file << "\nPlayer " << i << " cannot afford " << board.getName(space) <<  ".";
                        }
                    }
                }
                else if(board.getisOwnable(space) == false) //the space is not ownable
                {
                    if(space == 0) //Go
                    {
                        file << "\nPlayer " << i << " lands on Go.";
                    }
                    else if(space == 2 || space == 17 || space == 33) //Community Chest
                    {
                        file << "\nPlayer " << i << " lands on Community Chest.";
                        int chest = (rand() % 5) + 1; //random community chest card
                        
                        board.communityChest(file, board, players[bank], players[i], i, chest, space); //takes action of community chest card
                    }
                    else if(space == 7 || space == 22 || space == 36) //Chance
                    {
                        file << "\nPlayer " << i << " lands on Chance.";
                        int chance = (rand() % 5) + 1; //random chance card
                        
                        board.chance(file, board, players[bank], players[i], i, chance, space); //takes action of chance card
                    }
                    else if(space == 4)
                    {
                        file << "\nPlayer " << i << " lands on Income Tax.";
                        int assets = board.calculateAssets(i, players[i].getMoney());
                        
                        file <<"\nPlayer " << i << " assets are $" << assets << ".";
                        
                        if(players[i].getMoney() >= 200 && assets >= 2000)
                        {
                            board.boardPayment(file, players[bank], players[i], i, -200); //subtracts $200
                        }
                        else if(players[i].getMoney() >= 10 && assets < 2000)
                        {
                            board.boardPayment(file, players[bank], players[i], i, (assets * -0.1)); //subtracts 10% of total assets
                        }
                        else // BANKRUPTCY CHECKER
                        {
                            file << "\nPlayer " << i << " cannot afford Income Tax.";
                            int mortgage = board.bankruptcyChecker(file, i, space, 200, players[i], players[bank], board);
                            players[i].setMoney(players[i].getMoney() + mortgage);

                            if(players[i].getMoney() >= 200 && assets > 2000)
                            {
                                board.boardPayment(file, players[bank], players[i], i, -200); //subtracts $200
                            }
                            else if(players[i].getMoney() >= 10 && assets < 2000)
                            {
                                board.boardPayment(file, players[bank], players[i], i, (assets * -0.1)); //subtracts 10% of total assets
                            }
                            else //declares bankruptcy for player
                            {
                                board.bankrupt(file, players[bank], players[i], i); //gives player's remaining cash back to the bank
                            }
                        }
                    }
                    else if(space == 10) //Jail
                    {
                        file << "\nPlayer " << i << " is just visiting Jail.";
                    }
                    else if(space == 20) //Free Parking
                    {
                        file << "\nPlayer " << i << " lands on Free Parking.";
                    }
                    else if(space == 30) //Go To Jail
                    {
                        file << "\nPlayer " << i << " lands on Go To Jail.";
                        players[i].setSpace(10);
                        file << "\nPlayer " << i << " is in Jail.";
                    }
                    else if(space == 38) //Luxury Tax
                    {
                        file << "\nPlayer " << i << " lands on Luxury Tax.";
                        if(players[i].getMoney() >= 75)
                        {
                            board.boardPayment(file, players[bank], players[i], i, -75); //subtracts $75
                        }
                        else // BANKRUPTCY CHECKER
                        {
                            file << "\nPlayer " << i << " cannot afford Luxury Tax.";

                            int mortgage = board.bankruptcyChecker(file, i, space, 75, players[i], players[bank], board);
                            players[i].setMoney(players[i].getMoney() + mortgage);

                            if(players[i].getMoney() >= 75)
                            {
                                board.boardPayment(file, players[bank], players[i], i, -75); //subtracts $75
                            }
                            else //declares bankruptcy for player
                            {
                                board.bankrupt(file, players[bank], players[i], i); //gives player's remaining cash back to the bank
                            }
                        }
                    }
                }
            }
            
            if(players[i].getBankruptcy() != true)
            {
                file << "\nPlayer " << i << " current money is $" << players[i].getMoney() << endl;
                file << "\nBank current money is $" << players[bank].getMoney() << endl;
            }
            if(bankruptCounter == numberofPlayers - 1)
            {
                file << "\nGAME OVER!";
                break;
            }

        } //end of player loop
    } //end of game loop
  
    //Winning messages
    for(int i = 1; i < numberofPlayers + 1; i++)
    {
        if(players[i].getBankruptcy() == false)
        {
            winner = i;
        }
    }
    file << "\n\n\nPlayer " << winner << " has won the game!!!";
    
    //debug
//    for(int i = 0; i < numberofPlayers + 1; i++)
//    {
//        if(i == 0)
//        {
//            file << "\n\n\nBank has $" << players[i].getMoney() << " money.";
//        }
//        else
//        {
//            file << "\nPlayer " << i << " has $" << players[i].getMoney() << " money.";
//        }
//    }
 
    //closes game file
    file.close();

    //end message
    cout << "\nThe game has concluded. Check MonopolyFile for the result of the game. Thank you for playing!";

    return 0;
}
