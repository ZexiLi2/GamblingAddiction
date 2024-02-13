// GamblingAddiction.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <ctime>
using namespace std; 

int dice(int d1, int d2);   //funcio tira daus 
//void calculator(int W10, int W5, int W3, int L1);

int main()
{
    srand(NULL);
    cout << R"(
     ____              __                    __                _____ _                 __      __  _           
    / __ )____ _____  / /_________  ______  / /________  __   / ___/(_)___ ___  __  __/ /___ _/ /_(_)___  ____ 
   / __  / __ `/ __ \/ //_/ ___/ / / / __ \/ __/ ___/ / / /   \__ \/ / __ `__ \/ / / / / __ `/ __/ / __ \/ __ \
  / /_/ / /_/ / / / / ,< / /  / /_/ / /_/ / /_/ /__/ /_/ /   ___/ / / / / / / / /_/ / / /_/ / /_/ / /_/ / / / /
 /_____/\__,_/_/ /_/_/|_/_/   \__,_/ .___/\__/\___/\__, /   /____/_/_/ /_/ /_/\__,_/_/\__,_/\__/_/\____/_/ /_/ 
                                  /_/             /____/                                                       

	)" << "\n";	//ascii title
    cout << "Welcome to [Bankruptcy Simulation]!\n";
    int playOpt, bet, d1=0, d2=0, suma=0;
    int* pMoney = 0;
    int money = 100;    //player starts with this amount of money
    pMoney = &money;
    int W10=0, W5=0, W3=0, L1=0;
    cout << "Money available: " << money << endl;
    do {
cout << "Select an option: [1 (Throw away your life savings)], [2 (Exit)]|\n";
    cin >> playOpt;
    if (playOpt == 1)
    {
        do {
            cout << "Insert the amount of money you want to bet\n";
            cin >> bet;
            if (bet > money)
            {
                cout << "You are too poor!\n";
            }
            
        } while (bet > money);
        cout << "You are betting " << bet << " !\n";
        money = money - bet;
        cout << "Money left in your wallet: " << money<<endl;
        cout << "I'm going to throw 2 D50 dices, guess the result (2 - 100) :D\n";
        
        suma=dice(d1, d2);
        cout << "Correct answer is "<<suma << " (normalment hauria d'estar ocult, em facilita fer proves)\n";   //per fer experiments
        //calculator(W10, W5, W3,L1);
        int guesSuma;
            cin >> guesSuma;
            if (guesSuma == suma)
            {
                int W10 = bet * 10;
                cout << "Congratulations, you won " << W10 << "! (" << bet << "*10)\n";
                //cout << "Your wallet: " << money << "+" << W10 << endl;
                money = money + W10;
                cout << "Money available: " << money << endl;
            }
            else if (guesSuma ==suma+1 || guesSuma == suma -1 )
            {
                int W5 = bet * 5;
                cout << "Congratulations, you won " << W5 << "! ("<<bet<<"*5)\n";
                //cout << "Your wallet: " << money << "+" << W5 << endl;
                money = money + W5;
                cout << "Money available: " << money << endl;
            }
            else if (guesSuma == suma +2|| guesSuma == suma -2)
            {
                int W3 = bet * 3;
                cout << "Congratulations, you won " << W3 << "! (" << bet << "*3)\n";
                //cout << "Your wallet: " << money << "+" << W3 << endl;
                money = money + W3;
                cout << "Money available: " << money << endl;
            }
            else
            {
                int L1 = -bet;
                cout << "Congratulations, you lost " << L1 << "!\n";
                //cout << "Your wallet: " << money << "-" << L1 << endl;
                cout << "Money available: " << money << endl;
            }
    }
    else 
    {
        cout << "ok bye >:C";
    }
    } while (money > 0 && playOpt != 2);
    if (money == 0)
    {
    cout << "Thanks for the donations!\n";
    }
}

int dice(int d1, int d2) {
    int sumaTemp;
    d1 = rand() % 50 + 1;
    d2 = rand() % 50 + 1;
    sumaTemp = d1 + d2;
    return sumaTemp;
}
//void calculator (int W10, int W5, int W3, int L1) { ////funcio no funciona
// int guesSuma;
//  cin >> guesSuma;
//  
//    int suma, bet, money;
//    if (guesSuma == suma)
//    {
//        int W10 = bet * 10;
//        cout << "Congratulations, you won " << W10 << "! (" << bet << "*10)\n";
//        //cout << "Your wallet: " << money << "+" << W10 << endl;
//        money = money + W10;
//        cout << "Money available: " << money << endl;
//    }
//    else if (guesSuma == suma + 1 || guesSuma == suma - 1)
//    {
//        int W5 = bet * 5;
//        cout << "Congratulations, you won " << W5 << "! (" << bet << "*5)\n";
//        //cout << "Your wallet: " << money << "+" << W5 << endl;
//        money = money + W5;
//        cout << "Money available: " << money << endl;
//    }
//    else if (guesSuma == suma + 2 || guesSuma == suma - 2)
//    {
//        int W3 = bet * 3;
//        cout << "Congratulations, you won " << W3 << "! (" << bet << "*3)\n";
//        //cout << "Your wallet: " << money << "+" << W3 << endl;
//        money = money + W3;
//        cout << "Money available: " << money << endl;
//    }
//    else
//    {
//        int L1 = -bet;
//        cout << "Congratulations, you lost " << L1 << "!\n";
//        //cout << "Your wallet: " << money << "+" << L1 << endl;
//        cout << "Money available: " << money << endl;
//    }
//}