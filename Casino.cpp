#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std;
using namespace std::chrono;

#ifndef CARD_H
#define CARD_H
class Card{
    private:
        string face;
        string suit;
        
    public:
        Card();
        Card(string, string);
        string print();
};
#endif

Card::Card(){
    face = "";
    suit = "";
}

Card::Card(string cardFace, string cardSuit){
    face = cardFace;
    suit = cardSuit;
}

string Card::print(){
    return (face + " of " + suit);
}

const int cardsPerDeck = 52;

#ifndef CARDDECK_H
#define CARDDECK_H
class cardDeck{
    private:
        Card *deck;
        int currentCard;
    public:
        cardDeck();
        void shuffle();
        Card dealCard();
        void printDeck();
};
#endif

cardDeck::cardDeck(){
    string faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    string suits[] = {"Hearts", "Spades", "Diamonds", "Clubs"};
    deck = new Card[cardsPerDeck];
    currentCard = 0;
    for(int i = 0; i < cardsPerDeck; i++){
        deck[i] = Card(faces[i%13], suits[i/13]);
    }
}

void cardDeck::printDeck(){
    cout << left;
    for(int i = 0; i < cardsPerDeck; i++){
        cout << setw(19) << deck[i].print();
        if((i+1)%4 == 0){
            cout << endl;
        }
    }
}

void cardDeck::shuffle(){
    currentCard = 0;
    for(int i = 0; i < cardsPerDeck; i++){
        int hold = (rand() + time(0))%cardsPerDeck;
        Card temp = deck[i];
        deck[i] = deck[hold];
        deck[hold] = temp;
    }
}

Card cardDeck::dealCard(){
    if(currentCard > cardsPerDeck){
        shuffle();
    }
    if(currentCard < cardsPerDeck){
        return deck[currentCard++];
    }
    return deck[0];
}

int bal = 100;

void clearScreen(){
    cout << string(10, '\n');
}

void numberGuess(int &bal){
    int option;
    int num;
    int bet;
    unsigned seed = system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> ranNum1(1, 2);
    uniform_int_distribution<int> ranNum2(1, 5);
    uniform_int_distribution<int> ranNum3(1, 10);
    uniform_int_distribution<int> ranNum4(1, 50);
    uniform_int_distribution<int> ranNum5(1, 100);
    while(option != 6){
        if(bal == 0){
            break;
        }
        bool workNum = false;
        bool workBet = false;
        cout << "Which option would you like?" << endl;
        cout << "1. Guess a number between 1-2" << endl;
        cout << "2. Guess a number between 1-5" << endl;
        cout << "3. Guess a number between 1-10" << endl;
        cout << "4. Guess a number between 1-50" << endl;
        cout << "5. Guess a number between 1-100" << endl;
        cout << "6. Go back to the main lobby of the casino" << endl;
        cin >> option;
        switch(option){
            case 1: {
                int chance1 = ranNum1(generator);
                cout << "Choose a number between 1-2" << endl;
                cin >> num;
                while(workNum == false){
                    if(num < 1 || num > 2){
                        cout << "Choose a number between 1-2" << endl;
                        cin >> num;
                    }
                    else{
                        workNum = true;
                    }
                }
                cout << "How much would you like to bet?" << endl;
                cin >> bet;
                while(workBet == false){
                    if(bet > bal){
                        cout << "You do not have that much money." << endl;
                        cout << "How much would you like to bet?" << endl;
                        cin >> bet;
                    }
                    else if(bet == 0){
                        cout << "You need to bet something" << endl;
                        cout << "How much would you like to bet?" << endl;
                        cin >> bet;
                    }
                    else{
                        workBet = true;
                    }
                }
                if(num == chance1){
                    cout << "CORRECT" << endl;
                    bal += bet;
                    cout << "New balance is: $" << bal << endl;
                }
                else{
                    cout << "INCORRECT" << endl;
                    cout << "The correct number was " << chance1 << endl;
                    bal -= bet;
                    cout << "New balance is: $" << bal << endl;
                }
                break;
            }
            case 2: {
                int chance2 = ranNum2(generator);
                cout << "Choose a number between 1-5" << endl;
                cin >> num;
                while(workNum == false){
                    if(num < 1 || num > 5){
                        cout << "Choose a number between 1-5" << endl;
                        cin >> num;
                    }
                    else{
                        workNum = true;
                    }
                }
                cout << "How much would you like to bet?" << endl;
                cin >> bet;
                while(workBet == false){
                    if(bet > bal){
                        cout << "You do not have that much money." << endl;
                        cout << "How much would you like to bet?" << endl;
                        cin >> bet;
                    }
                    else if(bet == 0){
                        cout << "You need to bet something" << endl;
                        cout << "How much would you like to bet?" << endl;
                        cin >> bet;
                    }
                    else{
                        workBet = true;
                    }
                }
                if(num == chance2){
                    cout << "CORRECT" << endl;
                    bal += bet * 4;
                    cout << "New balance is: $" << bal << endl;
                }
                else{
                    cout << "INCORRECT" << endl;
                    cout << "The correct number was " << chance2 << endl;
                    bal -= bet;
                    cout << "New balance is: $" << bal << endl;
                }
                break;
            }
            case 3: {
                int chance3 = ranNum3(generator);
                cout << "Choose a number between 1-10" << endl;
                cin >> num;
                while(workNum == false){
                    if(num < 1 || num > 10){
                        cout << "Choose a number between 1-10" << endl;
                        cin >> num;
                    }
                    else{
                        workNum = true;
                    }
                }
                cout << "How much would you like to bet?" << endl;
                cin >> bet;
                while(workBet == false){
                    if(bet > bal){
                        cout << "You do not have that much money." << endl;
                        cout << "How much would you like to bet?" << endl;
                        cin >> bet;
                    }
                    else if(bet == 0){
                        cout << "You need to bet something" << endl;
                        cout << "How much would you like to bet?" << endl;
                        cin >> bet;
                    }
                    else{
                        workBet = true;
                    }
                }
                if(num == chance3){
                    cout << "CORRECT" << endl;
                    bal += bet * 9;
                    cout << "New balance is: $" << bal << endl;
                }
                else{
                    cout << "INCORRECT" << endl;
                    cout << "The correct number was " << chance3 << endl;
                    bal -= bet;
                    cout << "New balance is: $" << bal << endl;
                }
                break;
            }
            case 4: {
                int chance4 = ranNum4(generator);
                cout << "Choose a number between 1-50" << endl;
                cin >> num;
                while(workNum == false){
                    if(num < 1 || num > 50){
                        cout << "Choose a number between 1-50" << endl;
                        cin >> num;
                    }
                    else{
                        workNum = true;
                    }
                }
                cout << "How much would you like to bet?" << endl;
                cin >> bet;
                if(bet > bal){
                    cout << "You do not have that much money." << endl;
                }
                while(workBet == false){
                    if(bet > bal){
                        cout << "You do not have that much money." << endl;
                        cout << "How much would you like to bet?" << endl;
                        cin >> bet;
                    }
                    else if(bet == 0){
                        cout << "You need to bet something" << endl;
                        cout << "How much would you like to bet?" << endl;
                        cin >> bet;
                    }
                    else{
                        workBet = true;
                    }
                }
                if(num == chance4){
                    cout << "CORRECT" << endl;
                    bal += bet * 49;
                    cout << "New balance is: $" << bal << endl;
                }
                else{
                    cout << "INCORRECT" << endl;
                    cout << "The correct number was " << chance4 << endl;
                    bal -= bet;
                    cout << "New balance is: $" << bal << endl;
                }
                break;
            }
            case 5: {
                int chance5 = ranNum5(generator);
                cout << "Choose a number between 1-100" << endl;
                cin >> num;
                while(workNum == false){
                    if(num < 1 || num > 100){
                        cout << "Choose a number between 1-100" << endl;
                        cin >> num;
                    }
                    else{
                        workNum = true;
                    }
                }
                cout << "How much would you like to bet?" << endl;
                cin >> bet;
                if(bet > bal){
                    cout << "You do not have that much money." << endl;
                }
                while(workBet == false){
                    if(bet > bal){
                        cout << "You do not have that much money." << endl;
                        cout << "How much would you like to bet?" << endl;
                        cin >> bet;
                    }
                    else if(bet == 0){
                        cout << "You need to bet something" << endl;
                        cout << "How much would you like to bet?" << endl;
                        cin >> bet;
                    }
                    else{
                        workBet = true;
                    }
                }
                if(num == chance5){
                    cout << "CORRECT" << endl;
                    bal += bet * 99;
                    cout << "New balance is: $" << bal << endl;
                }
                else{
                    cout << "INCORRECT" << endl;
                    cout << "The correct number was " << chance5 << endl;
                    bal -= bet;
                    cout << "New balance is: $" << bal << endl;
                }
                break;
            }
            case 6: {
                break;
            }
            default: {
                cout << "Choose an option between 1-6" << endl;
            }
        }
        cout << endl;
    }
}

void blackjackSetup(){
    cardDeck deck;
    Card currentCard;
    deck.shuffle();
    deck.printDeck();
}

void blackjack(int &bal){
    int option, num, bet;
    while(option != 2){
        if(bal == 0){
            break;
        }
        cout << "Which option would you like?" << endl;
        cout << "1. Play BlackJack" << endl;
        cout << "2. Go back to the main lobby of the casino" << endl;
        cin >> option;
        if(option == 1){
            blackjackSetup();
        }
        else if(option == 2){
            break;
        }
        else{
            cout << "Enter a viable option" << endl;
        }
    }
}

void getBal(){
    cout << bal << endl;
}

int main()
{
    clearScreen();
    int game;

    cout<<"\n=====================================================================" << endl;
    cout<<"   CCCCC      A        SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     " << endl;
    cout<<" CC          A  A      SS             III     NN N   NN   OO      OO    " << endl;
    cout<<"CC          A    A     SSSSSSSSS      III     NN  N  NN   OO      OO    " << endl;
    cout<<" CC        AAAAAAAA           SS      III     NN   N NN   OO      OO    " << endl;
    cout<<"   CCCCC  A        A   SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     " << endl;
    cout<<"=====================================================================" << endl;

    cout << "\n* You come to a casino with $" << bal << " *" << endl;
    while(game != 3){
        if(bal == 0){
            cout << "\nWe don't like broke people staying around. Get Out!" << endl;
            cout << "* You are forcibly thrown out of the casino *" << endl;
            cout << "Looking up in despair at the two burly men who threw you out, a tear falls down your cheek" << endl;
            cout << "Now void of all worldy possessions, you turn back and wander off into the empty abyss that is your future \n" << endl;
            break;
        }
        cout << "\nWhat game would you like to play?" << endl;
        cout << "1. Number guessing game" << endl;
        cout << "2. BlackJack" << endl;
        cout << "3. exit" << endl;
        cin >> game;
        if(game == 1){
            numberGuess(bal);
        }
        else if(game == 2){
            blackjack(bal);
        }
        else if(game == 3){
            cout << "You leave the casino with $" << bal << endl;
            break;
        }
    }
}