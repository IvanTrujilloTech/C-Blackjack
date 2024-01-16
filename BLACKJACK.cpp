#include <iostream>
#include <random>
#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <ctime>

bool firstRead = true;
int selectedOption;

HANDLE  hConsole;


//Calling libraries
using namespace std;
bool play = true;
void esperar(int ms) {
    if (firstRead) {
        Sleep(ms);
    }
}
void title() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 2);
	cout << "\t\t .S_SSSs    S.       .S_SSSs      sSSs   .S    S.       .S   .S_SSSs      sSSs   .S    S.   \n";esperar(250);
	cout << "\t\t.SS~SSSSS   SS.     .SS~SSSSS    d%%SP  .SS    SS.     .SS  .SS~SSSSS    d%%SP  .SS    SS.  \n";esperar(250);
	cout << "\t\tS%S   SSSS  S%S     S%S   SSSS  d%S'    S%S    S&S     S%S  S%S   SSSS  d%S'    S%S    S&S  \n";esperar(250);
	cout << "\t\tS%S    S%S  S%S     S%S    S%S  S%S     S%S    d*S     S%S  S%S    S%S  S%S     S%S    d*S  \n";esperar(250);
	cout << "\t\tS%S SSSS%P  S&S     S%S SSSS%S  S&S     S&S   .S*S     S&S  S%S SSSS%S  S&S     S&S   .S*S  \n";esperar(250);
	cout << "\t\tS&S  SSSY   S&S     S&S  SSS%S  S&S     S&S_sdSSS      S&S  S&S  SSS%S  S&S     S&S_sdSSS   \n";esperar(250);
	cout << "\t\tS&S    S&S  S&S     S&S    S&S  S&S     S&S~YSSY%b     S&S  S&S    S&S  S&S     S&S~YSSY%b  \n";esperar(250);
	cout << "\t\tS&S    S&S  S&S     S&S    S&S  S&S     S&S    `S%     S&S  S&S    S&S  S&S     S&S    `S%  \n";esperar(250);
	cout << "\t\tS*S    S&S  S*b     S*S    S&S  S*b     S*S     S%     d*S  S*S    S&S  S*b     S*S     S%  \n";esperar(250);
	cout << "\t\tS*S SSSSP    SSSbs  S*S    S*S   SSSbs  S*S     S&  sdSSS   S*S    S*S   SSSbs  S*S     S&  \n";esperar(250);
	cout << "\t\tS*S  SSY      YSSP  SSS    S*S    YSSP  S*S     SS  YSSY    SSS    S*S    YSSP  S*S     SS  \n";esperar(250);
	cout << "\t\tSP                         SP           SP                         SP           SP          \n";esperar(250);
	cout << "\t\tY                          Y            Y                          Y            Y           \n";esperar(250);
	cout << "\n";
	SetConsoleTextAttribute(hConsole, 14);
    
}
void opciones(int option) {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //cout << "funcion: " << option;
	esperar(1500);
    if (option == 1) {  SetConsoleTextAttribute(hConsole, 15*16); }
	cout << "\t\t[JUGAR]\t\t\t"; SetConsoleTextAttribute(hConsole, 14);
	esperar(1500);
    if (option == 2) {
         SetConsoleTextAttribute(hConsole, 15 * 16); }
	cout << "\t\t[TUTORIAL]\t\t\t";SetConsoleTextAttribute(hConsole, 14);
	esperar(1500);
    if (option == 3) {  SetConsoleTextAttribute(hConsole, 15 * 16); }
	cout << "\t[SALIR]\t"; SetConsoleTextAttribute(hConsole, 14);
	esperar(1500);
	firstRead = false;
}
void tutorial() {
    cout << "\tEl croupier reparte una carta al jugador, y muestra el palo y el numero, si es un AS podras elegir entre el valor 1 u 11 y se anadiran los puntos al jugador\n";
    cout << "\tEl croupier volvera a repartirte otra carta por segunda vez, y se repite el proceso. Una vez ya tengas dos cartas el croupier se repartira una cara a si mismo, si sale un AS, le dara un valor de 11 por defecto\n";
    cout << "\tEl croupier de preguntara si quieres otra carta, si dices que si, se repite el proceso, si dices que no, el croupier se repartira una carta a si mismo\n";
    cout << "\tSi el croupier se pasa, ganas tu. Si el croupier tiene mas puntuaje que tu sin pasarse de 21 gana el. Si teneis el mismo puntuaje, ganas tu\n";
}

void menu() {
    int selectedOption = 1;
    int keyboardInput = 0;
    bool isSelected = false;
    #define KEY_LEFT 75
    #define KEY_RIGHT 77
    #define SPACE 32
    
    
    while (!isSelected) {

        title();
		opciones(selectedOption);
        switch ((keyboardInput = _getch())) {
        case KEY_LEFT:
            if (selectedOption > 1) selectedOption -= 1;
            //cout << selectedOption;
            break;
        case KEY_RIGHT:
			if (selectedOption < 3) selectedOption += 1;
            //cout << selectedOption;
            break;
        case SPACE:
            isSelected = true;
        }
        
        
        system("CLS");
    }
    //cout << selectedOption;
	switch (selectedOption) {
	case 2:
		tutorial();
	}
}

int main() {
    menu();
    
    const int MAX_SCORE = 21;
    const int MAX_ACE = 4;
    //const int DEALER_MIN_SCORE = 17;

    string deck[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    int values[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 };
    string kind[] = { "Picas","Corazones","Treboles","Diamantes" };
    string player_hand[10]; string dealer_hand[10];
    int player_score; int dealer_score;
    int player_aces = 0;
    int dealer_aces = 0;
    bool player_wants_hit = true;

    cout << "Tus cartas son: " << player_hand[0] << " y " << player_hand[1];
    cout << "Las cartas del croupier son: " << dealer_hand[0] << " y " << dealer_hand[1];
    string CARDS = ['''
        ------ -
        | K      |
        |       |
        |       |
        |       |
        |      K |
        ------ - ''', '''
        ------ -
        | Q      |
        |       |
        |       |
        |       |
        |      Q |
        ------ - ''', '''
        ------ -
        | J      |
        |       |
        |       |
        |       |
        |      J |
        ------ - ''', '''
        ------ -
        | 10     |
        |       |
        |       |
        |       |
        |     10 |
        ------ - ''', '''
        ------ -
        | 9      |
        |       |
        |       |
        |       |
        |      9 |
        ------ - ''', '''
        ------ -
        | 8      |
        |       |
        |       |
        |       |
        |      8 |
        ------ - ''', '''
        ------ -
        | 7      |
        |       |
        |       |
        |       |
        |      7 |
        ------ - ''', '''
        ------ -
        | 6      |
        |       |
        |       |
        |       |
        |      6 |
        ------ - ''', '''
        ------ -
        | 5      |
        |       |
        |       |
        |       |
        |      5 |
        ------ - ''', '''
        ------ -
        | 6      |
        |       |
        |       |
        |       |
        |      6 |
        ------ - ''', '''
        ------ -
        | 5      |
        |       |
        |       |
        |       |
        |      5 |
        ------ - ''', '''
        ------ -
        | 4      |
        |       |
        |       |
        |       |
        |      4 |
        ------ - ''', '''
        ------ -
        | 3      |
        |       |
        |       |
        |       |
        |      3 |
        ------ - ''', '''
        ------ -
        | 2      |
        |       |
        |       |
        |       |
        |      2 |
        ------ - ''', '''
        ------ -
        | A      |
        |       |
        |       |
        |       |
        |      A |
        ------ - '''
    ]
    cout << CARDS[5];

}