#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

// #define RANDSTRING(s) s[rand() % (sizeof(s)/sizeof(*(s)))]
#define STR_LEN 80
#define MAX_SEN 20


void logo_appear();
void main_scene(FILE*);
void begingame(FILE*);

void tip_generator(){
    typedef char sentence[STR_LEN];
    char *action[] = {"ping hit pong", "pong fell", "ping became cyber", "cyberpong now pong", "ping no pong"};
    const size_t n_articles = sizeof action /sizeof action[0];
    char *count[] = {"one", "two", "ten", "five thousand", "billion"};
    const size_t n_counts = sizeof count /sizeof count[0];
    char *timed[] = {"today", "yesterday", "never", "centuries ago", "in the future"};
    const size_t n_prepositions = sizeof timed /sizeof timed[0];

    sentence sentences[MAX_SEN];
    srand((unsigned) time(NULL));

    for (int i = 0; i < MAX_SEN; ++i) {
        int num = rand() % n_articles;
        strcpy(sentences[i], action[num]);

        num = rand() % n_counts;
        strcat(sentences[i], " ");
        strcat(sentences[i], count[num]);

        num = rand() % n_prepositions;
        strcat(sentences[i], " ");
        strcat(sentences[i], timed[num]);
        init_pair(10, COLOR_BLACK, COLOR_WHITE);
        attron(COLOR_PAIR(10));
        mvprintw(50, 75, "LAST GAME RESOLUTION: %s.\n", sentences[i]);
        attroff(COLOR_PAIR(10));
    }
}

void loading() {
    int i = 0; 
 	char load[10]; 
 	while(i < 9) 
 	{ 
 		system("clear"); 
 		load[i++] = '|';
 		load[i] = '\0'; 
		printf("\n\nLOADING CYBERPONG 2077... PLEASE WAIT... [%-10s]\n", load); 
 		usleep(199900); 
 	} 
 
 system("clear"); 
 printf("\n"); 
}


void logo_appear() {            
    clear();
    int usleep();
     FILE * fPtr;
    char ch;
    fPtr = fopen("load.txt", "r"); // extracting the logo
    do 
    {
        ch = fgetc(fPtr);
        putchar(ch);

    } while(ch != EOF);
    fclose(fPtr);
    sleep(2); // giving time for the player to see the logo
    clear();
}

void end() {
    clear(); refresh();
    int usleep();
    FILE * fPtr;
    char ch;
    fPtr = fopen("end.txt", "r"); // in case someone presses L
    do{
        ch = fgetc(fPtr);
        putchar(ch);
    } while (ch != EOF);
    fclose(fPtr);
    sleep(5); clear(); endwin(); exit(0); clear();
}

void main_scene(FILE* fp) { // for seeing the menu, instructions and beginning of the game
    int decision;
    wbkgd(stdscr, COLOR_PAIR(6));
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    init_pair(8, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_RED);
    init_pair(4, COLOR_BLACK, COLOR_CYAN);
    init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(55, COLOR_WHITE, COLOR_BLACK);
    init_pair(6, COLOR_BLACK, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    init_pair(9, COLOR_BLACK, COLOR_WHITE);
    attron(COLOR_PAIR(7));
    mvprintw(1, 1, "~");
    mvprintw(2, 2, "~");
    mvprintw(3, 3, "~");
    mvprintw(4, 4, "~");
    mvprintw(5, 5, "~");
    mvprintw(6, 6, "~");
    mvprintw(7, 7, "~");
    mvprintw(8, 8, "~");
    mvprintw(9, 9, "~");
    mvprintw(10, 10, "~");
    mvprintw(11, 11, "~");
    mvprintw(12, 12, "~");
    mvprintw(13, 13, "~");
    mvprintw(14, 14, "~");
    mvprintw(15, 15, "~");
    mvprintw(16, 16, "~");
    mvprintw(17, 17, "~");
    mvprintw(17, 18, "~");
    mvprintw(17, 19, "~");
    mvprintw(17, 20, "~");
    mvprintw(17, 21, "~");
    mvprintw(17, 22, "~");
    mvprintw(17, 23, "~");
    mvprintw(17, 24, "~");
    mvprintw(17, 25, "~");
    mvprintw(17, 26, "~");
    mvprintw(17, 27, "~");
    mvprintw(17, 28, "~");
    mvprintw(17, 29, "~");
    mvprintw(17, 30, "~");
    mvprintw(17, 31, "~");
    mvprintw(17, 32, "~");
    mvprintw(17, 33, "~");
    mvprintw(17, 34, "~");
    mvprintw(17, 35, "~");
    mvprintw(17, 36, "~");
    mvprintw(17, 37, "~");
    mvprintw(17, 38, "~");
    mvprintw(17, 39, "~");
    mvprintw(17, 40, "~");
    mvprintw(17, 41, "~");
    mvprintw(17, 42, "~");
    mvprintw(17, 43, "~");
    mvprintw(16, 44, "~");
    mvprintw(15, 45, "~");
    mvprintw(14, 46, "~");
    mvprintw(13, 47, "~");
    mvprintw(12, 48, "~");
    mvprintw(11, 49, "~");
    mvprintw(10, 50, "~");
    mvprintw(9, 51, "~");
    mvprintw(8, 52, "~");
    mvprintw(7, 53, "~");
    mvprintw(6, 54, "~");
    mvprintw(5, 55, "~");
    mvprintw(4, 56, "~");
    mvprintw(3, 57, "~");
    mvprintw(2, 58, "~");
    mvprintw(1, 59, "~");
    attroff(COLOR_PAIR(7));
    attron(COLOR_PAIR(4));
    mvprintw(7, 20, " 1. Begin the simulation");
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(5));
    mvprintw(9, 20, " 2. Simulation Manual");
    attroff(COLOR_PAIR(5));
    attron(COLOR_PAIR(9));
    mvprintw(40, 20, "__________________________________________________________________________________________________________________");
    mvprintw(41, 20, "He who ping pong strikes ping pong in others is ping pong himself pong ping continually in ping pong ping the pong");
    mvprintw(42, 20, "________________________________________________________________________________________________Mykola Holovetskyi");
    attroff(COLOR_PAIR(9));
    attron(COLOR_PAIR(3));
    mvprintw(10, 100, "Warning!");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(9));
    mvprintw(10, 108, "The difficulty must be chosen in the game itself, not in the main menu.");
    attroff(COLOR_PAIR(9));
    attron(COLOR_PAIR(7));
    mvprintw(15, 100, " Choose the difficulty (if not chosen, will be kept standard): ");
    attroff(COLOR_PAIR(7));
    attron(COLOR_PAIR(1));
    mvprintw(19, 105, " 1. Child's Play (Ridiculously Easy)");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    mvprintw(21, 105, " 2. Average PingPong enjoyer (Medium)");
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(3));
    mvprintw(23, 105, " 3. Cyberpsychopath (Hardcore)");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(9));
    mvprintw(26, 105, " 4. Reset the difficulty (Standard)");
    attroff(COLOR_PAIR(9));
    tip_generator();
    refresh();
    do{
        scanw("%d", &decision);
        refresh();
    }while(decision < 1 || decision > 2);
    switch (decision) {
        case 1 : begingame(fp); break;
        case 2 : clear();
        attron(COLOR_PAIR(7));
        mvprintw(18, 75, "To control left player use 'W' and 'S'. ");
        mvprintw(20, 75, "To control right player use arrows. ");
        mvprintw(40, 75, "Press L when you want to stop playing.");
        mvprintw(24, 75, "The difficulty determines your and your opponent's gameplay.");
        mvprintw(34, 75, "Press the buttons during the gameplay to change the difficulty.");
        mvprintw(26, 75, "The ball will go faster, your platforms stay at the same speed.");
        mvprintw(28, 75, "Winning during Cyberpsychopath either depends on luck or how good you are.");
        mvprintw(30, 75, "Child's Play is restricted for PingPong enjoyers.");
        mvprintw(32, 75, "Press any key to return.");
        attroff(COLOR_PAIR(7));
        getch(); clear(); main_scene(fp);
    }
}
void begingame(FILE* fp) { // start game
    clear();
    init_pair(1,COLOR_BLACK, COLOR_RED); // giving game some colors
    init_pair(2,COLOR_BLACK, COLOR_YELLOW);
    init_pair(3,COLOR_BLACK, COLOR_BLACK);
    init_pair(4,COLOR_BLUE, COLOR_YELLOW);
    init_pair(6,COLOR_RED, COLOR_BLACK);
    int usleep();
    typedef struct {
        int x, y ;
    } wind; // structure of the game's window
    typedef struct {
        int x, y , count ;
    } ping; // structure hracov
    wind console; //initialization of the window
    getmaxyx(stdscr, console.y , console.x);
    ping player = {0, console.y/2, 0}; //setting the position of the player1
    ping player2 = {console.x-1, console.y/2, 0}; // setting the position of the player2
    ping ball = {console.x/2 , console.y/2 , 0}; // ball position
    bool finish = false; // boolean which controls if the game is finished
    int max_y = 0 , max_x = 0; 
    int next_y = 0, next_x = 0;
    int direction_y = 1, direction_x = 1;
    int timer = 70000;
    getmaxyx(stdscr, max_y, max_x);
    while(finish != true) { // for running the game
        nodelay(stdscr,1);
        attron(A_BOLD);
        mvprintw(ball.y,ball.x, "O"); // the ball display
        attroff(A_BOLD);
        refresh();
        next_x = ball.x + direction_x;
        next_y = ball.y + direction_y;
        if (next_x > max_x || next_x < 0) {
            direction_x *= -1;
        }
        if (next_y > max_y || next_y < 0) {
            direction_y *= -1;
        }
        if(timer > 10000) timer -= 10; // setting speed
        usleep(timer);
        ball.x += direction_x; // setting X of ball
        ball.y += direction_y; // setting Y of ball
        
        if(ball.x == max_x) { // if the ball hits for player1
            if(ball.y != player2.y && ball.y != player2.y+1 && ball.y != player2.y+2 && ball.y != player2.y+3 && ball.y != player2.y-1) {
                player.count++;
                ball.x = console.x/2;
                ball.y = console.y/2;
            } 
        } else if(ball.x == 0) { // if the ball hits for player2
            if(ball.y != player.y && ball.y != player.y+1 && ball.y != player.y+2 && ball.y != player.y+3 && ball.y != player.y-1) {
                player2.count++;
                ball.x = console.x/2;
                ball.y = console.y/2;
            } 
        }

        erase();
        mvprintw(2, 5, "%d ",player.count); // screen score
        mvprintw(2,console.x-5,"%d",player2.count); // screen score
        init_pair(999, COLOR_BLACK, COLOR_RED);
        attron(COLOR_PAIR(1));
        mvvline(0,console.x/2,'|',console.y); // visual line on the screen
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(4)); // some colors
        for(int i = -1 ; i < 2 ; i++) { // platform prints
            mvprintw(player.y+i,player.x,"-");
            mvprintw(player2.y+i,player2.x,"-");
        }
        attroff(COLOR_PAIR(4)); // turning off colors
            switch (getch()) { // controls
                case 'w': player.y--*2; break;
                case 's': player.y++*2; break;
                case KEY_UP: player2.y--*2; break;
                case KEY_DOWN: player2.y++*2; break;
                case 0x1B: finish = true; break;
                case 'l': end(); break;
                case '1': timer = 90000; break;
                case '2': timer = 50000; break;
                case '3': timer = 30000; break;
                case '4': timer = 70000; break; 
            }
            if(player.y <= 1) {
                player.y = console.y-2;
            }
            if(player.y >= console.y-1) {
                player.y = 2;
            }
            if(player2.y<=1) {
                player2.y=console.y-2;
            }
            if(player2.y>=console.y-1) {
                player2.y=2;
            } // moves players
            if(finish == true) {
                fprintf(fp,"Player 1 = %d\tPlayer 2 = %d ",player.count , player2.count);
            }
        }
} 
int main(int argc , char* argv[]) { // working with files
    srand(time(NULL));
    initscr();
    noecho();
    start_color();
    curs_set(0);
    keypad(stdscr, true);
    FILE* fp = fopen(argv[1],"w");
    loading();
    logo_appear();
    main_scene(fp);
    endwin();
    fclose(fp);
    return 0;
}