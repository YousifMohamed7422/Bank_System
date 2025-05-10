#pragma once
#include"LoginManger.h"
#include <iostream>
#include <windows.h> 
#include <thread>     
using namespace std;



class Screens
{
protected:
	static void displayWelcomeMessage() {


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);


		cout << " W   W   EEEEE   L       CCCC   OOO    M   M   EEEEE   " << endl;
		cout << " W   W   E       L      C      O   O   MM MM   E        " << endl;
		cout << " W W W   EEEE    L      C      O   O   M M M   EEEE     " << endl;
		cout << " WW WW   E       L      C      O   O   M   M   E        " << endl;
		cout << " W   W   EEEEE   LLLLL   CCCC   OOO    M   M   EEEEE    " << endl;
		cout << endl;
		cout << " TTTTT   OOO       OOO    U   U   RRRR       BBBBB    AAAAA   N   N    K   K  " << endl;
		cout << "   T    O   O     O   O   U   U   R   R      B   B   A     A  NN  N    K  K   " << endl;
		cout << "   T    O   O     O   O   U   U   RRRR       BBBBB   AAAAAAA  N N N    KKK    " << endl;
		cout << "   T    O   O     O   O   U   U   R  R       B   B   A     A  N  NN    K  K   " << endl;
		cout << "   T     OOO       OOO     UUU    R   R      BBBBB   A     A  N   N    K   K  " << endl;

		this_thread::sleep_for(chrono::seconds(5));

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}


	static void displayMessage() {
		cout << "We have an excellent team ready to assist you at any time!!." << endl;
		cout << "We provide 24/7 and hope our service meets your satisfaction and approval." << endl;
		cout << endl;
	}
public:
	static void RunApp() {
		cout << "555448888";
		
		//FileManager::getAllData();
		//LoginManger::login();
	}
};

 

