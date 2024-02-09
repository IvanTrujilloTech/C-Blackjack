#include <iostream>
#include <random>
#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <string>

#pragma comment(lib, "winmm.lib")


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
    PlaySound(TEXT("casino_music.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
void tutorial(); //forward declaration            


void menu(bool& startedGame) {
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
    // cout << selectedOption;
    switch (selectedOption) {
    case 1:
        startedGame = true;
        break;
    case 2:
        tutorial();
        break;
    case 3:
        exit(1);
    }
}
void tutorial() {
    cout << "\tEl croupier reparte una carta al jugador, y muestra el palo y el numero, si es un AS podras elegir entre el valor 1 u 11 y se anadiran los puntos al jugador\n";
    Sleep(1000);
    cout << "\tEl croupier volvera a repartirte otra carta por segunda vez, y se repite el proceso. Una vez ya tengas dos cartas el croupier se repartira una cara a si mismo, si sale un AS, le dara un valor de 11 por defecto\n";
    Sleep(1000);
    cout << "\tEl croupier de preguntara si quieres otra carta, si dices que si, se repite el proceso, si dices que no, el croupier se repartira una carta a si mismo\n";
    Sleep(1000);
    cout << "\tSi el croupier se pasa, ganas tu. Si el croupier tiene mas puntuaje que tu sin pasarse de 21 gana el. Si teneis el mismo puntuaje, ganas tu\n";
    Sleep(3500);
    cout << endl << endl << "Pulsa una tecla para volver al menu.";
    int keyboardInput = 0;
    switch ((keyboardInput = _getch())) {
        default:
            break;
        }
        system("CLS");
        //  menu();
}
string repartidos[30]; 
int repartidosIndex = 0;

void repartirCarta(string& hand, int& deck_value, int playerType) {
   
    int opcionA;
	string kind[] = { "Picas","Corazones","Treboles","Diamantes" };
	string deck[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
	int values[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 };
    string auxCard;
    int randomCard = rand() %13;
	int randomKind = rand() %4;
    
    
    string kindRepartido = kind[randomKind];
    string deckRepartido = deck[randomCard];

	auxCard = deckRepartido + " de " + kindRepartido;
    bool isRepartido = false;
    isRepartido = find(begin(repartidos), end(repartidos), auxCard) != end(repartidos);
    while (isRepartido)
    {
        // cout << "carta ya repartida";
		randomCard = rand() % (12 + 1);
		randomKind = rand() % (3 + 1);

		kindRepartido = kind[randomKind];
		deckRepartido = deck[randomCard];
		auxCard = deckRepartido + " de " + kindRepartido;
		isRepartido = find(begin(repartidos), end(repartidos), auxCard) != end(repartidos);
    }
    repartidos[repartidosIndex] = auxCard; repartidosIndex++;
    //cout << endl << "REPARTIDOS : " << repartidos[0] << " " << repartidos[1] <<  " " << repartidos[2] << " " << repartidos[3] << " " << repartidos[4] << " " << repartidos[5] << endl;
    if (playerType == 0) {
        cout << "La carta del croupier es el " << deckRepartido << " de " << kindRepartido << endl;
        Sleep(1000);
    }  
    else {
        cout << "Tu carta es el " << deckRepartido << " de " << kindRepartido << endl;
        Sleep(1000);
    }
    
	

    if (deckRepartido == "A" && playerType == 1) {
        cout << "¿Quieres que tu " << deckRepartido << " de " << kindRepartido << " valga 1 o valga 11? : ";
        int opcionA = NULL;
        while (opcionA != 1 and opcionA != 11) {
			cin >> opcionA;
            switch (opcionA) {
            case 1:
                deck_value += 1;
                break;
            case 11:
                deck_value += 11;
                break;
            default:
                cout << "Opcion no valida";
                break;
            }
        }
    }
    else if (deckRepartido == "A" && playerType == 0) {
        deck_value += 11;
    }
    else if (deckRepartido != "A") {
        deck_value += values[randomCard];
    }
}

bool checkWin(int player_score, int dealer_score, bool player_wants_hit) {
    cout << "~ Tienes " << player_score << " puntos ~\n";
    Sleep(1000);
    cout << "~ El croupier tiene " << dealer_score << " puntos ~\n";
    if (player_score == 21) {
        Sleep(1000);
        cout << "¡Enhorabuena, has ganado!"<<endl;
        return true;
    }
    else if (dealer_score == 21) {
        Sleep(1000);
        cout << "¡Has perdido!"<<endl;
        return true; 
    }
    else if (dealer_score>21 && player_score <=21) {
        Sleep(1000);
        cout << "¡Enhorabuena, has ganado!"<<endl;
        return true;
    }
    else if ((dealer_score > 21 && player_score > 21) || dealer_score == player_score) { //*/
        Sleep(1000);
        cout << "Empate tecnico"<<endl; return true;
    }

    else if (dealer_score < player_score && player_score < 21 && player_wants_hit) {
        Sleep(1000);
        cout << "¡Seguimos jugando!"<<endl; return false;
    }
    else if (dealer_score > player_score && dealer_score <= 21) {
        Sleep(1000);
        cout << "¡Has perdido!"<<endl; return true;
    }
    
    else if (dealer_score < player_score && player_score > 21) {
        Sleep(1000);
        cout << "¡Te has pasado de 21!"<<endl; return true;
    }
    /*else if (player_score > dealer_score && player_score < 21 && !(player_wants_hit)) {
        cout << "Has ganado!"; return true;
    }*/
}
bool startedGame = false;
int main() {
	srand(time(NULL));
    while(!startedGame) {menu(startedGame);}
    
    const int MAX_SCORE = 21;
    const int MAX_ACE = 4;
    //const int DEALER_MIN_SCORE = 17;
	
    string player_hand[10];
    string dealer_hand[10];
    string card_option = "0";
    int player_score = 0; 
    int dealer_score = 0;
    int turn = 1;
    int player_aces = 0;
    int dealer_aces = 0;
    bool player_wants_hit = true;
    bool reached21 = false;
    repartirCarta(*player_hand, player_score,1);
    repartirCarta(*player_hand, player_score,1);
	repartirCarta(*dealer_hand, dealer_score,0);

    cout << "~ Tienes " << player_score << " puntos ~\n";        
    Sleep(1000);
    cout << "~ El croupier tiene " << dealer_score << " puntos ~\n";
    Sleep(1000);
    cout << "¿Quieres otra carta? (S/N) : ";
    while (1) {
        cin >> card_option;
        if (card_option == "S" || card_option == "s" || card_option == "Si" || card_option == "si") {
                repartirCarta(*player_hand, player_score, 1);
                card_option == "0";
                break;
            }
        else if (card_option == "N" || card_option == "n" || card_option == "No" || card_option == "no") {
            repartirCarta(*dealer_hand, dealer_score, 0);
            card_option == "0";
            player_wants_hit = false;
            if (dealer_score < player_score || dealer_score != 21) {
                repartirCarta(*dealer_hand, dealer_score, 0);
            }
            break;
        }
    }

    reached21 = checkWin(player_score,dealer_score,player_wants_hit);

    while (!reached21) {
    //  reached21 = checkWin(player_score,dealer_score);
        if (!reached21 && player_wants_hit) {
            cout << "¿Quieres otra carta? (S/N)";
            player_wants_hit = true;
            while (player_wants_hit) {
                cin >> card_option;
                if (card_option == "S" || card_option == "s" || card_option == "Si" || card_option == "si") {
                    repartirCarta(*player_hand, player_score, 1);
                    card_option = "0";
                    reached21 = checkWin(player_score, dealer_score,player_wants_hit);
                    break;
                }
                else if (card_option == "N" || card_option == "n" || card_option == "no" || card_option == "No") {
                    reached21 = checkWin(player_score, dealer_score,player_wants_hit);
                    player_wants_hit = false;
                    break;
                }
            }
            /*EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA 😡👊 EJECUTA*/
        }
        else if (!reached21 && !player_wants_hit) {
            while(dealer_score<21) {
                repartirCarta(*dealer_hand, dealer_score, 0);
            }
            reached21 = checkWin(player_score, dealer_score, player_wants_hit);
        }
        // if (!player_wants_hit) {
        // checkWin(player_score, dealer_score, player_wants_hit);
        // break;
        // }
    }
    
}