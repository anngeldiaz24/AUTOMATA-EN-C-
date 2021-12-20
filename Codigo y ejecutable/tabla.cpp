#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define ESTADOS 11
#define ENTRADAS 5

using namespace std;

void presentacion_1();
void EsconderCursor ()
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon, &cci);
}
void gotoxy (int x, int y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon, dwPos);
}

void delay(int number_of_seconds)
{
    int milli_seconds = 10 * number_of_seconds;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds);
}

//PRESENTACION
void presentacion()
{
    int xcol;

    // primera linea
    system("COLOR 03");
    gotoxy (1,2); printf("%c",201);
    gotoxy (1,3); printf("%c",186);
    gotoxy (1,4); printf("%c",200);

    for(xcol=2;xcol<=79;xcol++)
    {
        gotoxy(xcol,2); printf("%c",205);
        gotoxy(xcol,4); printf("%c",205);
        delay(4);
    }
    gotoxy(80,2); printf("%c",187);
    gotoxy(80,3); printf("%c",186);
    gotoxy(80,4); printf("%c",188);

    // segunda linea
    char titulo[]= " UN PERSONAJE EN APUROS ";
    int vlongitud;
    vlongitud=strlen(titulo);
    int centro=(((80-vlongitud)/2)+1);

    for(xcol=2;xcol<=centro;xcol++)
    {
        system("COLOR 03");
        gotoxy(xcol,3); printf(titulo);
        delay(7);
    }
    printf("\n\n\n");
    printf("\t\t\t");
    system("pause");
    system("CLS");
}


int main(int argc, char const *argv[])
{
    string nombre;
    int input;
    char opc;
    int estado = 0;
    int tabla[ESTADOS][ENTRADAS]={{3, 2, 4, 1, 5},
                                  {3, 2, 4, 1, 5},
                                  {3, 2, 4, 1, 5},
                                  {3, 7, 0, 6, 5},
                                  {0, 8, 4, 9, 5},
                                  {5, 5, 5, 5, 5},
                                  {3, 7, 0, 6, 5},
                                  {0,10, 0, 6, 5},
                                  {0, 8, 4, 9, 5},
                                  {0, 8, 4,10, 5},
                                  {10,10,10,10,10}};

    /* for (size_t i = 0; i < ESTADOS ; i++)
    {
        for (size_t j = 0; j < ENTRADAS; j++)
        {
            cout << tabla[i][j]<< " ";
        }
        cout<<endl;
    }
 */
    EsconderCursor();
    presentacion_1();
    presentacion();
    cout <<"\tBotones: "<<endl;
    cout << " w -> volar"<<endl;
    cout << " s -> agachar"<<endl;
    cout << " a -> retroceder"<<endl;
    cout << " d -> avanzar"<<endl;
    cout << " e -> parar"<<endl;
    cout << " x -> terminar juego"<<endl;
    

    cout << "*****************************************"<<endl;
    cout << "\tNombra a tu personaje: ";
    getline(cin, nombre);
    
    cout << endl <<endl;
    cout << "*****************************************"<<endl;
    cout <<"\t"<< nombre << " esta en movimmiento"<<endl;
    cout <<"\t"<<"Se encuentra en el estado q"<<estado << endl << endl;
    cout << "*****************************************"<<endl;
    do
    {
        cout << "Ingresa una tecla: ";
        cin >> opc;
        switch (opc)
        {
        case 'w':
            input = 0;
            break;
        case 'a':
            input = 1;
            break;
        case 's':
            input = 2;
            break;
        case 'd':
            input = 3;
            break;
        case 'e':
            input = 4;
            break;
        case 'x':
            cout << "El juego a terminado"<<endl;
            return 0;
            break;
        default:
            cout << "Opcion no valida"<<endl;
            break;
        }
        estado = tabla[estado][input];
    
            if(estado==0)
            {
                cout << "*****************************************"<<endl;
                cout <<"\t"<< nombre <<" esta en movimiento"<<endl;
                cout <<"\t"<<"Se encuentra en el estado q"<<estado << endl << endl;
                cout << "*****************************************"<<endl;
                
            }
            else if (estado==1)
            {
                cout << "*****************************************"<<endl;
                cout <<"\t"<< nombre <<" avanza"<<endl;
                cout <<"\t"<<"Se encuentra en el estado q"<<estado << endl << endl;
                cout << "*****************************************"<<endl;
                
            }
            else if (estado==2)
            {
                cout << "*****************************************"<<endl;
                cout <<"\t"<< nombre <<" retrocede"<<endl;
                cout <<"\t"<<"Se encuentra en el estado q"<<estado << endl << endl;
                cout << "*****************************************"<<endl;
                
            }
            else if (estado==3)
            {
                cout << "*****************************************"<<endl;
                cout <<"\t"<<nombre <<" vuela"<<endl;
                cout <<"\t"<<"Se encuentra en el estado q"<<estado << endl << endl;
                cout << "*****************************************"<<endl;
                
            }
            else if (estado==4)
            {
                cout << "*****************************************"<<endl;
                cout <<"\t"<< nombre <<" esta agachado"<<endl;
                cout <<"\t"<<"Se encuentra en el estado q"<<estado << endl << endl;
                cout << "*****************************************"<<endl;
            } 
            else if (estado==6)
            {
                cout << "*****************************************"<<endl;
                cout <<"\t"<< nombre <<" avanza volando"<<endl;
                cout <<"\t"<<"Se encuentra en el estado q"<<estado << endl << endl;
                cout << "*****************************************"<<endl;   
            } 
            else if (estado==7)
            {
                cout << "*****************************************"<<endl;
                cout <<"\t"<< nombre <<" retrocede volando"<<endl;
                cout <<"\t"<<"Se encuentra en el estado q"<<estado << endl << endl;
                cout << "*****************************************"<<endl;
                
            } 
            else if (estado==8)
            {
                cout << "*****************************************"<<endl;
                cout <<"\t"<< nombre <<" retrocede agachado"<<endl;
                cout <<"\t"<<"Se encuentra en el estado q"<<estado << endl << endl;
                cout << "*****************************************"<<endl;
                
            } 
            else if (estado==9)
            {
                cout << "*****************************************"<<endl;
                cout <<"\t"<< nombre <<" avanza agachado"<<endl;
                cout <<"\t"<<"Se encuentra en el estado q"<<estado << endl << endl;
                cout << "*****************************************"<<endl;
                
            } 
            else if (estado==10)
            {
                cout << "*****************************************"<<endl;
                cout <<"\t"<< nombre <<" ha caido en una trampa"<<endl;
                cout <<"\t"<<"Cayo en el estado q"<<estado << endl;
                cout <<"\t"<< "GAME OVER"<<endl << endl;
                cout << "*****************************************"<<endl;
                
            } 
            else if (estado ==5)
            {
                cout << "*****************************************"<<endl;
                cout <<"\t"<< nombre <<" se quedo parado " <<endl
                        <<"\t"<<"y murio a causa de una trampa"<<endl;
                cout <<"\t"<<"Cayo en el estado q"<<estado << endl;
                cout <<"\t"<< "\t"<<"GAME OVER"<<endl << endl;
                cout << "*****************************************"<<endl;
            
            }
        getchar();
    }while (opc != 'x' && estado!=5 && estado!=10 );
    return 0;
} 



void presentacion_1(){

    system("cls");
    system("color 0b");


    Sleep(300);
    gotoxy(28,7); printf("U");Sleep (80);
    gotoxy(33,7); printf("U");Sleep (80);
    gotoxy(35,7); printf("D");Sleep (80);
    gotoxy(36,7); printf("D");Sleep (80);
    gotoxy(37,7); printf("D");Sleep (80);
    gotoxy(41,7); printf("G");Sleep (80);
    gotoxy(42,7); printf("G");Sleep (80);
    gotoxy(43,7); printf("G");Sleep (80);
    gotoxy(44,7); printf("G");Sleep (80);
    gotoxy(45,7); printf("G");Sleep (80);

    Sleep(200);
    gotoxy(28,8); printf("U");Sleep (80);
    gotoxy(33,8); printf("U");Sleep (80);
    gotoxy(35,8); printf("D");Sleep (80);
    gotoxy(38,8); printf("D");Sleep (80);
    gotoxy(41,8); printf("G");Sleep (80);

    Sleep(300);
    gotoxy(28,9); printf("U");Sleep (80);
    gotoxy(33,9); printf("U");Sleep (80);
    gotoxy(35,9); printf("D");Sleep (80);
    gotoxy(39,9); printf("D");Sleep (80);
    gotoxy(41,9); printf("G");Sleep (80);
    gotoxy(42,9); printf("G");Sleep (80);
    gotoxy(43,9); printf("G");Sleep (80);
    gotoxy(44,9); printf("G");Sleep (80);
    gotoxy(45,9); printf("G");Sleep (80);


    Sleep(300);
    gotoxy(28,10); printf("U");Sleep (80);
    gotoxy(33,10); printf("U");Sleep (80);
    gotoxy(35,10); printf("D");Sleep (80);
    gotoxy(39,10); printf("D");Sleep (80);
    gotoxy(41,10); printf("G");Sleep (80);
    gotoxy(45,10); printf("G");Sleep (80);

    Sleep(300);
    gotoxy(28,11); printf("U");Sleep (80);
    gotoxy(33,11); printf("U");Sleep (80);
    gotoxy(35,11); printf("D");Sleep (80);
    gotoxy(38,11); printf("D");Sleep (80);
    gotoxy(41,11); printf("G");Sleep (80);
    gotoxy(45,11); printf("G");Sleep (80);

    Sleep(300);
    gotoxy(28,11); printf("U");Sleep (80);
    gotoxy(29,11); printf("U");Sleep (80);
    gotoxy(30,11); printf("U");Sleep (80);
    gotoxy(31,11); printf("U");Sleep (80);
    gotoxy(32,11); printf("U");Sleep (80);
    gotoxy(33,11); printf("U");Sleep (80);
    gotoxy(35,11); printf("D");Sleep (80);
    gotoxy(36,11); printf("D");Sleep (80);
    gotoxy(37,11); printf("D");Sleep (80);
    gotoxy(38,11); printf("D");Sleep (80);
    gotoxy(41,11); printf("G");Sleep (80);
    gotoxy(42,11); printf("G");Sleep (80);
    gotoxy(43,11); printf("G");Sleep (80);
    gotoxy(44,11); printf("G");Sleep (80);
    gotoxy(45,11); printf("G");Sleep (80);

    Sleep(800);
    gotoxy(9,14);  printf("C");Sleep (80);
    gotoxy(10,14); printf("E");Sleep (80);
    gotoxy(11,14); printf("N");Sleep (80);
    gotoxy(12,14); printf("T");Sleep (80);
    gotoxy(13,14); printf("R");Sleep (80);
    gotoxy(14,14); printf("O");Sleep (80);
    gotoxy(16,14); printf("U");Sleep (80);
    gotoxy(17,14); printf("N");Sleep (80);
    gotoxy(18,14); printf("I");Sleep (80);
    gotoxy(19,14); printf("V");Sleep (80);
    gotoxy(20,14); printf("E");Sleep (80);
    gotoxy(21,14); printf("R");Sleep (80);
    gotoxy(22,14); printf("S");Sleep (80);
    gotoxy(23,14); printf("I");Sleep (80);
    gotoxy(24,14); printf("T");Sleep (80);
    gotoxy(25,14); printf("A");Sleep (80);
    gotoxy(26,14); printf("R");Sleep (80);
    gotoxy(27,14); printf("I");Sleep (80);
    gotoxy(28,14); printf("O");Sleep (80);
    gotoxy(29,14); printf(" ");Sleep (80);
    gotoxy(30,14); printf("D");Sleep (80);
    gotoxy(31,14); printf("E");Sleep (80);
    gotoxy(32,14); printf(" ");Sleep (80);
    gotoxy(33,14); printf("C");Sleep (80);
    gotoxy(34,14); printf("I");Sleep (80);
    gotoxy(35,14); printf("E");Sleep (80);
    gotoxy(36,14); printf("N");Sleep (80);
    gotoxy(37,14); printf("C");Sleep (80);
    gotoxy(38,14); printf("I");Sleep (80);
    gotoxy(39,14); printf("A");Sleep (80);
    gotoxy(40,14); printf("S");Sleep (80);
    gotoxy(41,14); printf(" ");Sleep (80);
    gotoxy(42,14); printf("E");Sleep (80);
    gotoxy(43,14); printf("X");Sleep (80);
    gotoxy(44,14); printf("A");Sleep (80);
    gotoxy(45,14); printf("C");Sleep (80);
    gotoxy(46,14); printf("T");Sleep (80);
    gotoxy(47,14); printf("A");Sleep (80);
    gotoxy(48,14); printf("S");Sleep (80);
    gotoxy(49,14); printf(" ");Sleep (80);
    gotoxy(50,14); printf("E");Sleep (80);
    gotoxy(51,14); printf(" ");Sleep (80);
    gotoxy(52,14); printf("I");Sleep (80);
    gotoxy(53,14); printf("N");Sleep (80);
    gotoxy(54,14); printf("G");Sleep (80);
    gotoxy(55,14); printf("E");Sleep (80);
    gotoxy(56,14); printf("N");Sleep (80);
    gotoxy(57,14); printf("I");Sleep (80);
    gotoxy(58,14); printf("E");Sleep (80);
    gotoxy(59,14); printf("R");Sleep (80);
    gotoxy(60,14); printf("I");Sleep (80);
    gotoxy(61,14); printf("A");Sleep (80);
    gotoxy(62,14); printf("S");Sleep (80);

    Sleep(800);
    gotoxy(25,16); printf("T");Sleep (80);
    gotoxy(26,16); printf("E");Sleep (80);
    gotoxy(27,16); printf("O");Sleep (80);
    gotoxy(28,16); printf("R");Sleep (80);
    gotoxy(29,16); printf("I");Sleep (80);
    gotoxy(30,16); printf("A");Sleep (80);
    gotoxy(31,16); printf(" ");Sleep (80);
    gotoxy(32,16); printf("D");Sleep (80);
    gotoxy(33,16); printf("E");Sleep (80);
    gotoxy(34,16); printf(" ");Sleep (80);
    gotoxy(35,16); printf("L");Sleep (80);
    gotoxy(36,16); printf("A");Sleep (80);
    gotoxy(37,16); printf(" ");Sleep (80);
    gotoxy(38,16); printf("C");Sleep (80);
    gotoxy(39,16); printf("O");Sleep (80);
    gotoxy(40,16); printf("M");Sleep (80);
    gotoxy(41,16); printf("P");Sleep (80);
    gotoxy(42,16); printf("U");Sleep (80);
    gotoxy(43,16); printf("T");Sleep (80);
    gotoxy(44,16); printf("A");Sleep (80);
    gotoxy(45,16); printf("C");Sleep (80);
    gotoxy(46,16); printf("I");Sleep (80);
    gotoxy(47,16); printf("O");Sleep (80);
    gotoxy(48,16); printf("N");Sleep (80);

    Sleep(800);
    gotoxy(31,18); printf("P");Sleep (60);
    gotoxy(32,18); printf("R");Sleep (60);
    gotoxy(33,18); printf("O");Sleep (60);
    gotoxy(34,18); printf("Y");Sleep (60);
    gotoxy(35,18); printf("E");Sleep (60);
    gotoxy(36,18); printf("C");Sleep (60);
    gotoxy(37,18); printf("T");Sleep (60);
    gotoxy(38,18); printf("O");Sleep (60);
    gotoxy(39,18); printf(" ");Sleep (60);
    gotoxy(40,18); printf("F");Sleep (60);
    gotoxy(41,18); printf("I");Sleep (60);
    gotoxy(42,18); printf("N");Sleep (60);
    gotoxy(43,18); printf("A");Sleep (60);
    gotoxy(44,18); printf("L");Sleep (60);


    Sleep(800);
    gotoxy(21,20); printf("M");Sleep (60);
    gotoxy(22,20); printf("T");Sleep (60);
    gotoxy(23,20); printf("R");Sleep (60);
    gotoxy(24,20); printf("O");Sleep (60);
    gotoxy(25,20); printf(".");Sleep (60);
    gotoxy(26,20); printf(" ");Sleep (60);
    gotoxy(27,20); printf("A");Sleep (60);
    gotoxy(28,20); printf("B");Sleep (60);
    gotoxy(29,20); printf("E");Sleep (60);
    gotoxy(30,20); printf("L");Sleep (60);
    gotoxy(31,20); printf("A");Sleep (60);
    gotoxy(32,20); printf("R");Sleep (60);
    gotoxy(33,20); printf("D");Sleep (60);
    gotoxy(34,20); printf("O");Sleep (60);
    gotoxy(35,20); printf(" ");Sleep (60);
    gotoxy(36,20); printf("G");Sleep (60);
    gotoxy(37,20); printf("O");Sleep (60);
    gotoxy(38,20); printf("M");Sleep (60);
    gotoxy(39,20); printf("E");Sleep (60);
    gotoxy(40,20); printf("Z");Sleep (60);
    gotoxy(41,20); printf(" ");Sleep (60);
    gotoxy(42,20); printf("A");Sleep (60);
    gotoxy(43,20); printf("N");Sleep (60);
    gotoxy(44,20); printf("D");Sleep (60);
    gotoxy(45,20); printf("R");Sleep (60);
    gotoxy(46,20); printf("A");Sleep (60);
    gotoxy(47,20); printf("D");Sleep (60);
    gotoxy(48,20); printf("E");Sleep (60);

    Sleep(800);
    gotoxy(31,22); printf("C");Sleep (80);
    gotoxy(32,22); printf("A");Sleep (80);
    gotoxy(33,22); printf("R");Sleep (80);
    gotoxy(34,22); printf("G");Sleep (80);
    gotoxy(35,22); printf("A");Sleep (80);
    gotoxy(36,22); printf("N");Sleep (80);
    gotoxy(37,22); printf("D");Sleep (80);
    gotoxy(38,22); printf("O");Sleep (80);
    gotoxy(39,22); printf(".");Sleep (500);
    gotoxy(40,22); printf(".");Sleep (500);
    gotoxy(41,22); printf(".");Sleep (500);

    gotoxy(41,22); printf("   ");Sleep (500);
    gotoxy(41,22); printf(".");Sleep (500);
    gotoxy(42,22); printf(".");Sleep (500);
    gotoxy(43,22); printf(".");Sleep (500);

    gotoxy(41,22); printf("   ");Sleep (500);
    gotoxy(41,22); printf(".");Sleep (500);
    gotoxy(42,22); printf(".");Sleep (500);
    gotoxy(43,22); printf(".");Sleep (500);

    gotoxy(31,22); printf("    LISTO    ");Sleep (80);

    system("color 0e");Beep(400,500);
    system("color 0f");Beep(400,500);
    system("color 0a");Beep(400,500);
    Beep(1100,500);
    system("color 0a");



    Beep(725,500);
    Sleep(2000);

    system("CLS");
}