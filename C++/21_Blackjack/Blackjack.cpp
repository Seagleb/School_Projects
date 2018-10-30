/***********************************************************
    Author:         William Seagle
    Project:        Lab 4A
    Date:           3/2/18
    Description:    Lets user play a game of Blackjack
************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

int RollDice();
int GetWager(int money);
void PlayerTurn(int money,
                int &wager,
                bool &bust,
                int &total,
                int &houseroll);
void HouseTurn(int houseroll,bool &bust,int &total);
void DrawBoard(int money,int house_total,int player_total,int wager);

int main()
{
    srand(time(NULL));
    int die;
    int wager;
    bool bust = false;
    bool quit = false;
    int houseroll;
    int money = 100;
    int total = 0;
    int player_total;
    int house_total;
    char play_again;
    while (money > 0 && quit == false)
    {
        PlayerTurn(money, wager, bust, total, houseroll);
        player_total = total;
        if (bust == true)
        {
            money = money-wager;
            DrawBoard(money,houseroll,total,wager);
            cout << "Player Busted! House wins this round. Better luck next time." << endl;
        }
        else
        {
            HouseTurn(houseroll,bust,total);
            house_total = total;
            if (bust == true)
            {
                money = money + wager;
                DrawBoard(money,house_total,player_total,wager);
                cout << "House Busted! You won, Congratulations!" << endl;
            }
            else if (house_total > player_total && bust == false)
            {
                money = money-wager;
                DrawBoard(money,house_total,player_total,wager);
                cout << "House wins this round. Better luck next time" << endl;
            }
            else if (house_total < player_total && bust == false)
            {
                money = money + wager;
                DrawBoard(money,house_total,player_total,wager);
                cout << "You won! Congratulations!" << endl;
            }
            else if (house_total == player_total && bust == false)
            {
                DrawBoard(money,house_total,player_total,wager);
                cout << "Split pot, even hands.";
            }
        }




        cout << "Would you like to play again? y/n: ";
        cin >> play_again;
        if(play_again == 'y' || play_again == 'Y')
        {
            cout << "lets do it!" << endl;
            if (money <=0)
            {
                cout << "I'm sorry, You don't have the funds to continue playing.";
            }
        }
        else
        {
            cout << "Okay lets not." << endl;
            quit = true;
        }


    }

}

int RollDice()
{
    int convert = rand()%13+1;
        if (convert >= 1 && convert < 10)
        {
            convert = convert + 1;
            return convert;
        }
        else if(convert >= 10 && convert < 13)
        {
            convert = 10;
            return convert;
        }
        else if(convert == 13)
        {
            convert = 11;
            return convert;
        }
        else
        {
            cout << "DICE ERROR";
        }
}

int  GetWager(int money)
{

    int wager;
    bool valid_wager = false;
    while (valid_wager == false)
    {
        cout << "What is your wager: ";
        cin >> wager;
        if (wager <= money && wager > 0)
        {
            cout << "Your Wager is " << wager << endl;
            valid_wager=true;
            return wager;
        }
        else
        {
            cout <<"Invalid Wager, try again." << endl;
        }
    }

}

void PlayerTurn(int money,int &wager,bool &bust,int &total,int &houseroll)
{
    bool stay = false;
    int stay_input;
    bust = false;
    int player_card;
    total = 0;
    cout << "It is now your turn" << endl;
    wager = GetWager(money);
    total = total + RollDice();
    houseroll = RollDice();
    DrawBoard(money,houseroll,total,wager);


    while (bust == false && stay == false)
    {
        total = total + RollDice();
        player_card = RollDice();
        DrawBoard(money,houseroll,total,wager);
        if (total > 21)
        {
            bust = true;
            cout << "Player Busted!" << endl;
            break;
        }
        cout << "1.Stay or 2.Hit: ";
        cin >> stay_input;
        if (stay_input == 1)
        {
            stay = true;
        }
    }
    cout << "Your turn is finished" << endl;
}

void HouseTurn(int houseroll,bool &bust,int &total)
{
    cout << "It is now the House's turn." << endl;
    total = houseroll;
    while(total < 17)
    {
        total = total + RollDice();
        if (total > 21)
        {
            bust = true;
            break;
        }
    }
    cout << "House's turn has ended." << endl;
}

void DrawBoard(int money,int house_total,int player_total,int wager)
{
    system("cls");
    cout << "\t-------------------------------" << endl;
    cout << "\t-------William's Casino--------"<< endl;
    cout << "\t-------------------------------"<< endl;
    cout << "\t\tHouse Total:" << house_total << endl<< endl << endl;
    cout << "Dollars: " << money << "\tPlayer Total: " << player_total << "\tPlayer Wager: " << wager << endl<< endl << endl;

}

