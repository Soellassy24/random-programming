#include <iostream>
#include <windows.h>
#include <conio.h>
#include <dos.h>
#include <unistd.h>
using namespace std;

/*void color(){
    system("Color 0A");
}*/
void Gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void pesawat(int x, int y){
    Gotoxy(x-6,y+0);cout << "000000000000000000000000000000000000";
    Gotoxy(x-6,y+1);cout << "000000000000000000000000000000000000";
    Gotoxy(x-6,y+2);cout << "                000";
    Gotoxy(x-6,y+3);cout << "                000";
    Gotoxy(x-6,y+4);cout << "                000";
}
void game(){
    int key = 0;
    int x1 = 0;
    int x2 = 0;
    int x3 = 7;
    int y3 = 20;
    while(1){
        if (_kbhit()){
            key =_getch();
            cout<<key<<endl;
            if (key == 27){
                system("cls");
                break;
            }
            if (key == 77){
                x3=x3+1;
            }
            if (key == 72){
                y3=y3-1;
            }
            if (key == 80){
                y3=y3+1;
            }
            if (key == 75){
                x3=x3-1;
            }
        }
        x1=x1+1;
        x2=x2+2;
        if (x1>100){
            x1=0;
        }
        if (x2>100){
            x2=0;
        }
        if (x3>100-6){
            x3=6;
        }
        pesawat(x3,y3);
        usleep(100000);
        system("cls");
    }
}
int main(){
    int pilihan;
    cout << "Selamat datang di game gabut!\n";
    cout << "Press 1 to start the game\n";
    cout << "Press 2 to exit the game\n";
    cin >> pilihan;
    switch (pilihan){
    case 1:
        system("cls");
        game();
        break;
    case 2:
        break;
    }
    return 0;
}
