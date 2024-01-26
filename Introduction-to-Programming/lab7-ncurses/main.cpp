#include<ncurses.h> //biblioteka z ktorej bedziemy korzystac
#include<time.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
        /* uruchomienie ncurses */
        initscr(); //synchornizuj terminal
        raw(); //synchornizuj klawiature
        noecho(); //synchornizuj wypisywanie
        keypad(stdscr, TRUE); //dodaj obsluge klawiszy specjalnych
        
        srand(time(0));

        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_YELLOW, COLOR_BLACK);
        init_pair(3, COLOR_BLUE, COLOR_BLACK);
        init_pair(4, COLOR_GREEN, COLOR_BLACK);

        int znak;
        int x, y, kolor;
        int run = 300;  
        
        x = rand() %70;
        y = rand() % 23;
        move(y, x);
        refresh();
        printw("X");

        while(znak != 'q'){

        znak = getch();
        kolor = rand()%4 + 1;
        attron(COLOR_PAIR(kolor));
        if(znak=='a') --x;
        if(znak=='d') x++;
        if(znak=='w') y--;
        if(znak=='s') y++;

        move(y, x);
        printw("X");
        refresh();
        
        }       
        
        
        endwin(); //zamknij ncurses
        return 0;
}