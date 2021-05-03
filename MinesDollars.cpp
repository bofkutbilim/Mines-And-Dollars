#include <iostream>
#include <conio.h>
#include <cmath>
#include <stdio.h>
#include <windows.h>
#include <ctime>
#include <string>

using namespace std;

char heart = 3;
int Polo = 0;
char resu = 4;
char U = 30, D = 31, L = 17, R = 16;
int no_mines = 0;
int no_wall = 0;

int mine = 0;
int h = 15, w = 30, y = 7, x = 15;
bool game[1000][1000];
int Dvig = 0;
int fx = rand()%30;
int fy = rand()%15;
int score = 0;
bool chit = false;
int
level = 1;

bool menu = false;

char resh = 219, resh2 = 223;
string levelFlag, exitFlag, mMenuFlag, menuFlag;
string levelStr[] = {"[level 1]", "[level 2]", "[level 3]", "[level 4]", "[level 5]", "[level 6]", "[level 7]", "[level 8]"};
string exitStr[] = {"[yes]", "[no]"};
string mMenuStr[] = {"[Continue]", "[New Game]", "[Level]", "[Instruction]", "[Exit]"};
string menuStr[] = {"[Continue]", "[Main Menu]"};

int speed[] = {70, 60, 50, 40, 30, 20, 10, 1};

void MainMenu();

void setcur(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

enum ConsoleColor{
	Black        =  0,
	Blue         =  1,
	Green        =  2,
	Cyan         =  3,
	Red          =  4,
	Magenta      =  5,
	Brown        =  6,
	LightGray    =  7,
	DarkGray     =  8,
	LightBlue    =  9,
	LightGreen   = 10,
	LightCyan    = 11,
	LightRed     = 12,
    LightMagenta = 13,
	Yellow       = 14,
	White        = 15
};

void Color(int Background, int Text) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD) ((Background << 4) | Text));
}

void Loading() {
	 system("cls");
	 Color(Black, LightCyan);
	 string str = "";
	 for(int i = 0; i <= 100;) {
			setcur(16, 2);
			cout << endl ;
			Color(Black, LightRed);
			cout << "                      _____________\n\n";
			Color(Black, LightRed);
			cout << "                      MINES\n";
			Color(Black, LightCyan);
			cout << "                          &\n";
			Color(Black, LightGreen);
			cout << "                          Dollar$\n";
			cout << "                          _____________";
			cout << endl;
			Color(Black, LightCyan);
			cout << "                      autor:\n                         Erjan Ulukbek\n\n";
		 Color(Black, White);
		 cout << "                          Loading..." << i << "%\n" << endl;
		 Color(Black, Green);
		 cout << "                 "<<str;
		 Color(Black, LightCyan);
		 if(i < 20) {
		 		if(!(i % 3)) {
					str += char(resh);
			  }
	   }else {
	 			if(!(i % 2)) {
				  str += char(resh);
			  }
		 }
		 if(i < 30) i+=4;
		 else if(i < 60) i+=3;
		 else if(i < 90) i+=2;
		 else if(i <= 100) i++;
		 Color(Black, LightGreen);
		 cout << char(resh);
		 Color(Black, White);
		 Sleep(100);
	}
	Sleep(1500);
}

void Levels(){
	system("cls");
      setcur(16, 2);
	Color(Black, White);
	int levelH = 0, n = 8;
	while(true) {
		cout << "          {Levels}\n\n\n\n";
		for(int i = 0; i < n; i++){
			cout << "                         " << i + 1 << "|";
			if(i == levelH){
				Color(LightGreen, Black);
				cout << levelStr[i] << "\n\n";
				levelFlag = levelStr[i];
				Color(Black, White);
			}else{
				cout << levelStr[i] << "\n\n";
			}
		}
		_kbhit();
		char ch = _getch();
		if(ch == 72){
				levelH--;
		}else if(ch == 80){
				levelH++;
		}else if(ch == 13){
			  system("cls");
			  if(levelFlag == levelStr[0]) {
					level = 1;
					score = 0;
					no_mines = 0;
					no_wall = 0;
                              h = 15, w = 30;
                              mine = 0;
                              y = 7, x = 15;
                              int Polo = 0;
                              char resu = 4;
                              for(int i = 0; i < h; i++) {
                                          for(int j = 0; j < w; j++) game[i][j]=false;
                              }
					Dvig = 0;
                              fx = rand()%30;
                              fy = rand()%15;
				}else if(levelFlag == levelStr[1]){
					level = 2;
					score = 0;
					no_mines = 0;
					no_wall = 0;
                              h = 15, w = 30;
                              mine = 0;int Polo = 0;
                              char resu = 4;
                              for(int i = 0; i < h; i++) {
                                    for(int j = 0; j < w; j++) game[i][j]=false;
                              }
					Dvig = 0;
					y = 7, x = 15;
                              fx = rand()%30;
                              fy = rand()%15;
				}else if(levelFlag == levelStr[2]){
					level = 3;
					no_mines = 0;
					no_wall = 0;
					score = 0;int Polo = 0;
                              char resu = 4;
                              h = 15, w = 30;
                              mine = 0;
                              for(int i = 0; i < h; i++) {
                                    for(int j = 0; j < w; j++) game[i][j]=false;
                              }
                              y = 7, x = 15;
					Dvig = 0;
                              fx = rand()%30;
                              fy = rand()%15;
				}else if(levelFlag == levelStr[3]){
					level = 4;
					no_mines = 0;
					no_wall = 0;
					score = 0;int Polo = 0;
                              char resu = 4;
                              h = 15, w = 30;
                              mine = 0;
                              for(int i = 0; i < h; i++) {
                                    for(int j = 0; j < w; j++) game[i][j]=false;
                              }
					Dvig = 0;
					y = 7, x = 15;
                              fx = rand()%30;
                              fy = rand()%15;
				}else if(levelFlag == levelStr[4]){
					level = 5;
					no_mines = 0;
					no_wall = 0;
					score = 0;int Polo = 0;
                              char resu = 4;
                              h = 15, w = 30;
                              mine = 0;
                              y = 7, x = 15;
                              Dvig = 0;
                              fx = rand()%30;
                              fy = rand()%15;
                              for(int i = 0; i < h; i++) {
                                    for(int j = 0; j < w; j++) game[i][j]=false;
                              }
				}else if(levelFlag == levelStr[5]){
					level = 6;
					score = 0;
					no_mines = 0;
					no_wall = 0;
                              h = 15, w = 30;
                              mine = 0;int Polo = 0;
                              char resu = 4;
                              y = 7, x = 15;
                              Dvig = 0;
                              fx = rand()%30;
                              fy = rand()%15;
                              for(int i = 0; i < h; i++) {
                                    for(int j = 0; j < w; j++) game[i][j]=false;
                              }
				}else if(levelFlag == levelStr[6]){
					level = 7;
					score = 0;
					no_mines = 0;
					no_wall = 0;
					Dvig = 0;int Polo = 0;
                              char resu = 4;
                              fx = rand()%30;
                              fy = rand()%15;
                              h = 15, w = 30;
                              mine = 0;
                              y = 7, x = 15;
                              for(int i = 0; i < h; i++) {
                                    for(int j = 0; j < w; j++) game[i][j]=false;
                              }
				}else if(levelFlag == levelStr[7]){
					level = 8;
					score = 0;
					no_mines = 0;
					no_wall = 0;
                              h = 15, w = 30;
                              Dvig = 0;int Polo = 0;
                              char resu = 4;
                              fx = rand()%30;
                              fy = rand()%15;
                              mine = 0;
                              for(int i = 0; i < h; i++) {
                                    for(int j = 0; j < w; j++) game[i][j]=false;
                              }
                              y = 7, x = 15;
				}
				return;
		}else if(ch == 75){
			MainMenu();
			return;
		}
		if(levelH < 0)levelH = 0;
		else if(levelH > 7) levelH = 7;
		setcur(16, 2);
	}
}

void printInstructions() {
	/*
	       { Instruction }

  Contol the [Menu] with w=UP
 s=DOWN,(in all free Exit a=B
ACK) and o=CHOICE.
  Control the [Player] with w
=UP, s=DOWN, a=LEFT, d=RIGHT
and space=Menu.
  You must take points in the
game and must not die, I made
8 levels, 8 speeds and 7 maps
            FOR YOU.
	*/
	system("cls");
	cout << "                        { Instruction }" << endl << endl << endl;

	cout << "                   Contol the [Menu] with w=UP" << endl << endl;
	cout << "                 s=DOWN,(in all free Exit a=B" << endl << endl;
	cout << "                 ACK) and o=CHOICE." << endl << endl;
	cout << "                   Control the [Player] with w" << endl << endl;
	cout << "                 =UP, s=DOWN, a=LEFT, d=RIGHT" << endl << endl;
	cout << "                 and space=Menu." << endl << endl;
	cout <<  "                  You must take points in the" << endl << endl;
	cout << "                 game and must not die, I made" << endl << endl;
	cout << "                 8 speeds and 1 map" << endl << endl;
	cout << "                           FOR YOU." << endl << endl;
	Color(Black, LightCyan);
	cout <<"                       author: ''Good Luck!!''.";
	Color(Black, White);
}

void Instructions() {
	while(true) {
		setcur(0, 0);
		printInstructions();
		_kbhit();
		int ch = (_getch());
		if(ch == 75) {
			MainMenu();
			return;
		}
		setcur(0, 0);
	}
}
void Exit(){
	system("cls");
	Color(Black, LightRed);
	int exitH = 0, n = 2;
	while(true) {
		setcur(24, 6);
		cout << "{ Exit the Game? }\n\n    ";
		setcur(24, 8);
		for(int i = 0; i < n; i++){
			if(i == exitH) {
				Color(LightCyan, Black);
				cout << exitStr[i];
				exitFlag = exitStr[i];
				Color(Black, LightRed);
				cout << "         ";
			}else{
				cout << exitStr[i] << "         ";
			}
		}
		_kbhit();
		int ch = int(_getch());
		if(ch == 77){
			exitH++;
		}else if(ch == 75){
			exitH--;
		}else if(ch == 13){
			if(exitFlag == exitStr[0]){
				system("cls");
				system("pause");
				exit(0);
			}else if(exitFlag == exitStr[1]){
				MainMenu();
			}
			return;
		}
		if(exitH <= -1)exitH = 0;
		else if(exitH >= 2)exitH = 1;
	}
}

void MainMenu() {
	system("cls");
	setcur(17, 2);
	Color(Black, White);
	int mMenuH = 0, n = 5;
	while(true) {
		cout << "        {Main Menu}\n\n\n\n";
		for(int i = 0; i < n; i++) {
			cout <<"                         " << i + 1 << "|";
			if(i == mMenuH) {
				Color(LightGreen, Black);
				cout << mMenuStr[i] << endl << endl << endl;
				mMenuFlag = mMenuStr[i];
				Color(Black, White);
			}else{
				cout << mMenuStr[i] << endl << endl << endl;
			}
		}
		_kbhit();
		char ch = _getch();
		if(ch == 72) {
			mMenuH--;
		}else if(ch == 80) {
			mMenuH++;
		}else if(ch == 13) {
			if(mMenuFlag == mMenuStr[1]){
				no_mines = 0;
				no_wall = 0;
				score = 0;
				h = 15, w = 30;
				mine = 0;
				system("cls");
				for(int i = 0; i < h; i++) {
                              for(int j = 0; j < w; j++) game[i][j]=false;
                        }
                        y = 7, x = 15;
                        Dvig = 0;int Polo = 0;
                        char resu = 4;
                        fx = rand()%30;
                        fy = rand()%15;
				level = 1;
			}else if(mMenuFlag == mMenuStr[0]){
				system("cls");
			}else if(mMenuFlag == mMenuStr[2]){
				Levels();
			}else if(mMenuFlag == mMenuStr[3]){
				Instructions();
			}else if(mMenuFlag == mMenuStr[4]){
				Exit();
			}
			return;
		}
		if(mMenuH > 4)mMenuH = 4;
		else if(mMenuH < 0) mMenuH = 0;
		setcur(17, 2);
	}
	system("cls");
}

void Console(){
      string str;
      setcur(2, 2);
      for(int i = 0; i < 10; i++) {
            setcur(2, i+2);
            for(int j = 0; j < 36; j++) {
                  cout << ' ';
            }
            cout <<"|"<<endl;
      }
      int s = 9;
      setcur(16, 12);
      for(int i = 0; i < 22; i++) cout << '_';cout << "|";
      setcur(16, 2);
      string R = "Your command, please!!";
    cout << R;
    for(int i = 0; i < s; i++){
          cout << "\n";
    }setcur(16, 11);
    char c;
    scanf("%c", &c);
    if(c == '\n')return;
    else cin >> str;
    if (c == 'n' && str == "o_mines") {
    	no_mines ^= 1;
    } else if (c == 'n' && str == "o_wall") {
    	no_wall ^= 1;
    } else {
    	cout << "                Sorry!!";
    	Sleep(1000);
    }
}

void Menu() {
	Color(Black, White);
	int menuH = 0, n = 2;
	while(true) {
		setcur(25, 6);
		cout << "   {Pause}   ";
		setcur(25, 7);
		cout << "             ";
		for(int i = 0; i < n; i++) {
			if(i == 0) {
				setcur(25, 8);
			}else{
				setcur(25, 9);
			}
			cout << i + 1 << "|";
			if(i == menuH) {
				Color(LightGreen, Black);
				cout << menuStr[i];
				menuFlag = menuStr[i];
				Color(Black, White);
			}else{
				cout << menuStr[i];
			}
			if(i == 0)cout<<" ";
			cout << endl;
		}
		setcur(25, 10);
		cout << "             ";
		_kbhit();
		int ch = int(_getch());
		if(ch == 72) {
			menuH--;
		}else if(ch == 80) {
			menuH++;
		}else if(ch == 13) {
			if(menuFlag == menuStr[0]){
                        menu = false;
			}else if(menuFlag == menuStr[1]){
				MainMenu();
			}
			return;
		}
		if(menuH < 0) menuH = 0;
		else if(menuH > 1) menuH = 1;
 	}
}

int main() {
      int Time = 120, timer = 0;
      srand(time(NULL));
      //Loading();
      while(true){
            MainMenu();
            system("Cls");
            mine = 0;
            h = 15, w = 30, y = 7, x = 15;
            game[h][w];
            Dvig = 0;
            Polo = 0;
            resu = 4;
            fx = rand()%30;
            fy = rand()%15;
            score = 0;


            for(int i = 0; i < h; i++) {
                  for(int j = 0; j < w; j++) {
                        game[i][j] = false;
                  }
            }



            while(true) {

                  //Game
                  Color(Black, LightCyan);
                  cout << "                    author: Erjan Ulukbekov\n";
                  Color(Black, White);
                  cout << "                ";
                  Color(LightMagenta, LightMagenta);
                  for(int  i = 0; i < w+2; i++) cout << char(219);
                  Color(Black, White);
                  cout << endl;
                  for(int  i = 0; i < h; i++) {
                        cout << "                ";
                        Color(LightMagenta, LightMagenta);
                        cout <<char(219);
                        Color(Black, White);
                        for(int j = 0; j < w; j++) {
                              if(game[i][j] == true){
                                          Color(Black, LightRed);
                                          cout << char(253);
                                          Color(Black, White);
                              }
                              else if(i == fy and j == fx){
                                          Color(Black, LightGreen);
                                          cout << "$";
                                          Color(Black, White);
                              }
                              else if(i == y and j == x) {
                                    Color(Black, LightBlue);
                                    cout << char(resu);
                                    Color(Black, White);
                              }else {
                                    cout << ' ';
                              }
                        }
                        Color(LightMagenta, LightMagenta);
                        cout << char(219);
                       Color(Black, White);
                        cout << endl;
                  }
                  cout << "                ";
                  Color(LightMagenta, LightMagenta);
                  for(int  i = 0; i < w+2; i++) cout << char(219);
                  Color(Black, White);
                  cout << endl;
                  cout << endl;
                  Color(Black, LightGreen);
                  cout << "                money: " <<score/1000<<score/100%10<<score/10%10<<score%10<<"                ";
                  Color(Black, LightRed);
                  cout << heart << " " << heart << " " << heart << "\n";
                  Color(Black, LightRed);
                  cout << "                mines: " <<mine/1000<<mine/100%10<<mine/10%10<<mine%10<< endl;
                  Color(Black, White);
                  //Dvizhenie
                  const char up = char(72),down = char(80),left = char(75),right = char(77);
                  if(_kbhit()) {
                        switch (_getch()){
                        case char(27):
                              Console();
                              break;
                        case ' ':
                              menu = true;
                              break;
                        case 'w':
                              Dvig = 1, Polo = 1;
                              break;
                        case 'a':
                              Dvig = 2, Polo = 2;
                              break;
                        case 'd':
                              Dvig = 3, Polo = 3;
                              break;
                        case 's':
                              Dvig = 4, Polo = 4;
                              break;
                        }
                  }
                  if(menu) {
                        Menu();
                  }
                  switch(Polo) {
                        case 1:
                              resu=U;
                              break;
                        case 2:
                              resu=L;
                              break;
                        case 3:
                              resu=R;
                              break;
                        case 4:
                              resu=D;
                              break;
                  }
                  switch(Dvig) {
                        case 1:
                              y--;
                              break;
                        case 2:
                              x--;
                              break;
                        case 3:
                              x++;
                              break;
                        case 4:
                              y++;
                              break;
                  }

                  //you lose
                  //game[y][x] == true
                  if(y < 0 or x < 0 or y >= h or x >= w) {
                	 if (no_wall) {
                	 	if (y < 0) y = h-1;
                	 	if (x < 0) x = w-1;
                	 	if (y >= h) y = 0;
                	 	if (x >= w) x = 0;
                	 } else {
						bool rd = true;
                        setcur(0, 0);
                        Color(Black, LightRed);
                        cout << "                    author: Erjan Ulukbekov\n";
                        Color(Black, White);
                        cout << "                ";
                        if(rd) Color(Red, Red);
                        else Color(LightMagenta, LightMagenta);
                        for(int  i = 0; i < w+2; i++) cout << char(219);
                        Color(Black, White);
                        cout << endl;
                        for(int  i = 0; i < h; i++) {
                              cout << "                ";
                              if(rd) Color(Red, Red);
                              else Color(LightMagenta, LightMagenta);
                              cout <<char(219);
                              Color(Black, White);
                              for(int j = 0; j < w; j++) {
                                    if(i == y and j == x) {
                                          Color(Black, Red);
                                          cout << "x";
                                          Color(Black, White);
                                    }
                                    else if(game[i][j] == true){
                                                Color(Black, Red);
                                                cout << char(253);
                                                Color(Black, White);
                                    }
                                    else if(i == fy and j == fx){
                                                Color(Black, Green);
                                                cout << "$";
                                                Color(Black, White);
                                    }
                                    else {
                                          cout << ' ';
                                    }
                              }
                              if(rd) Color(Red, Red);
                              else Color(LightMagenta, LightMagenta);
                              cout << char(219);
                              Color(Black, White);
                              cout << endl;
                        }
                        cout << "                ";
                        if(rd) Color(Red, Red);
                        else Color(LightMagenta, LightMagenta);
                        for(int  i = 0; i < w+2; i++) cout << char(219);
                        Color(Black, White);
                        cout << endl;
                        cout << endl;
                        Color(Black, LightGreen);
                        cout << "                money: " <<score/1000<<score/100%10<<score/10%10<<score%10<<"                ";
                        Color(Black, LightRed);
                        cout << heart << " " << heart << " " << heart << "\n";
                        Color(Black, LightRed);
                        cout << "                mines: " <<mine/1000<<mine/100%10<<mine/10%10<<mine%10<< endl;
                        cout << endl << "                           YOU LOSE!!!\n";
                        Color(Black, White);
                        Beep(800, 500);
                        Sleep(2000);
                        break;
                    }
                  }
                  if(game[y][x] == true) {
                	 if (no_mines) {
                	 } else {
						bool rd = false;
                        rd = true;
						setcur(0, 0);
                        Color(Black, LightRed);
                        cout << "                    author: Erjan Ulukbekov\n";
                        Color(Black, White);
                        cout << "                ";
                        if(rd) Color(Red, Red);
                        else Color(LightMagenta, LightMagenta);
                        for(int  i = 0; i < w+2; i++) cout << char(219);
                        Color(Black, White);
                        cout << endl;
                        for(int  i = 0; i < h; i++) {
                              cout << "                ";
                              if(rd) Color(Red, Red);
                              else Color(LightMagenta, LightMagenta);
                              cout <<char(219);
                              Color(Black, White);
                              for(int j = 0; j < w; j++) {
                                    if(i == y and j == x) {
                                          Color(Black, Red);
                                          cout << "x";
                                          Color(Black, White);
                                    }
                                    else if(game[i][j] == true){
                                                Color(Black, Red);
                                                cout << char(253);
                                                Color(Black, White);
                                    }
                                    else if(i == fy and j == fx){
                                                Color(Black, Green);
                                                cout << "$";
                                                Color(Black, White);
                                    }
                                    else {
                                          cout << ' ';
                                    }
                              }
                              if(rd) Color(Red, Red);
                              else Color(LightMagenta, LightMagenta);
                              cout << char(219);
                              Color(Black, White);
                              cout << endl;
                        }
                        cout << "                ";
                        if(rd) Color(Red, Red);
                        else Color(LightMagenta, LightMagenta);
                        for(int  i = 0; i < w+2; i++) cout << char(219);
                        Color(Black, White);
                        cout << endl;
                        cout << endl;
                        Color(Black, LightGreen);
                        cout << "                money: " <<score/1000<<score/100%10<<score/10%10<<score%10<<"                ";
                        Color(Black, LightRed);
                        cout << heart << " " << heart << " " << heart << "\n";
                        Color(Black, LightRed);
                        cout << "                mines: " <<mine/1000<<mine/100%10<<mine/10%10<<mine%10<< endl;
                        cout << endl << "                           YOU LOSE!!!\n";
                        Color(Black, White);
                        Beep(800, 500);
                        Sleep(2000);
                        break;
                    }
                 }

                  //fruit[Y][X]
                  if(x == fx and y == fy) {
						game[y][x] = true;
                        mine++;
                        score += level;
                        Beep(700, 30);
                        fx = rand()%30;
                        fy = rand()%15;
                        while(game[fy][fx] == true) {
                              fx = rand()%30;
                              fy = rand()%15;
                        }
                  }
                  Sleep(speed[level-1]);
                  setcur(0, 0);
                  timer+=speed[level-1]+100;
                  if(timer >= 1000)Time--, timer = 0;
            }
            system("cls");
      }
      return 0;
}
