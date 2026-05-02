#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
//--------------------Global Variables--------------------
int opt = 0;
int boxX = 13;
int boxY = 3;
int boxW = 100;
void reg();
void del();
void view();
void printCentered(string , int);
//-------------------------Classes-------------------------
class parking_lot {
    public:
        bool isFull = false;
        virtual void clear() {
            isFull = false;
            
        }
        virtual void full() {
            isFull = true;
            
        }
};

class lot1 : public parking_lot {
    public:
        void clear() override{
        	if(isFull == false){
        		printCentered("Lot 1 is already Cleared. Please select another lot",8);
			} else {
				isFull = false;
            	printCentered("Parking Lot 1 is Clear",8);
			}
        }
        void full() override{
            if(isFull == true){
        		printCentered("Lot 1 is already Full. Please select another lot",8);
			} else {
				isFull = true;
            	printCentered("Parking Lot 1 is Booked",8);
			}
            
        }
};

class lot2 : public parking_lot {
    public:
        void clear() override{
            if(isFull == false){
        		printCentered("Lot 2 is already Cleared. Please select another lot",10);
			} else {
				isFull = false;
            	printCentered("Parking Lot 2 is Clear",10);
			}
            
        }
        void full() override{
            if(isFull == true){
        		printCentered("Lot 2 is already Full. Please select another lot",9);
			} else {
				isFull = true;
            	printCentered("Parking Lot 2 is Booked",9);
			}
            
        }
};
class lot3 : public parking_lot {
    public:
        void clear() override{
            if(isFull == false){
        		printCentered("Lot 3 is already Cleared. Please select another lot",12);
			} else {
				isFull = false;
            	printCentered("Parking Lot 3 is Clear",12);
			}
            
        }
        void full() override{
            if(isFull == true){
        		printCentered("Lot 3 is already Full. Please select another lot",10);
			} else {
				isFull = true;
            	printCentered("Parking Lot 3 is Booked",10);
			}
            
        }
};

lot1 l1;
lot2 l2;
lot3 l3;

// -----------------------Functions-----------------------
void gotoxy(int x, int y) {
    COORD coord = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void printCentered(string text, int y) {
    int x = boxX + (boxW - text.length()) / 2;
    gotoxy(x, y);
    cout << text;
}
void drawBox(int x, int y, int width, int height) {
    // Top-left corner
    setColor(3);
    gotoxy(x, y);
    cout << char(201);

    // Top border
    for (int i = 1; i < width - 1; i++)
        cout << char(205);

    // Top-right corner
    cout << char(187);

    // Sides
    for (int i = 1; i < height - 1; i++) {
        gotoxy(x, y + i);
        cout << char(186);           // Left wall
        gotoxy(x + width - 1, y + i);
        cout << char(186);           // Right wall
    }

    // Bottom-left corner
    gotoxy(x, y + height - 1);
    cout << char(200);

    // Bottom border
    for (int i = 1; i < width - 1; i++)
        cout << char(205);

    // Bottom-right corner
    cout << char(187 - 187 + 188);  // 188 = ╝
}

void reg() {
    int x = boxX + boxW - 29 - 4;
    int ya = boxY + 25 - 2;
    string line1 = "1. Lot 1  " + string(l1.isFull ? "Full" : "Available");
    string line2 = "2. Lot 2  " + string(l2.isFull ? "Full" : "Available");
    string line3 = "3. Lot 3  " + string(l3.isFull ? "Full" : "Available");
    string line4 = "Enter Your Choice :";
    system("cls");
    drawBox(13,3,100,25);
    setColor( (1 * 16) + 15 ); 
    gotoxy(51,5);
    cout<<"Parking Lot Manager V2";
    setColor(10);
    // Vertical placement (you can adjust these)
    int y = boxY + 5;

    gotoxy(boxX + (boxW - line1.length()) / 2, y++);
    cout << line1;

    gotoxy(boxX + (boxW - line2.length()) / 2, y++ );
    cout << line2;

    gotoxy(boxX + (boxW - line3.length()) / 2, y++ );
    cout << line3;

    y++; // space

    gotoxy(boxX + (boxW - line4.length()) / 2, y+2);
    cout << line4;
    char ch = getch();
    opt = ch - '0';
    Beep(750, 300);
    switch (opt) {
        case 1: l1.full();break;
        case 2: l2.full();break;
        case 3: l3.full();break;
    }
    gotoxy(x,ya);
    system("pause");
}
void del(){
    int x = boxX + boxW - 29 - 4;
    int ya = boxY + 25 - 2;
    string line1 = "1. Lot 1  " + string(l1.isFull ? "Full" : "Available");
    string line2 = "2. Lot 2  " + string(l2.isFull ? "Full" : "Available");
    string line3 = "3. Lot 3  " + string(l3.isFull ? "Full" : "Available");
    string line4 = "Enter Your Choice :";
    system("cls");
    drawBox(13,3,100,25);
    setColor( (1 * 16) + 15 ); 
    printCentered("Parking Lot Freeing System", 5);
    setColor(10);
    printCentered(line1, 8);
    printCentered(line2,10);
    printCentered(line3,12);
    printCentered(line4,15);
    char ch = getch();
    opt = ch - '0';
    Beep(750, 300);
    switch (opt) {
        case 1: l1.clear();break;
        case 2: l2.clear();break;
        case 3: l3.clear();break;
    }
    gotoxy(x,ya);
    system("pause");
}
void view(){
    int x = boxX + boxW - 29 - 4;
    int ya = boxY + 25 - 2;
    system("cls");
    drawBox(13,3,100,25);
    string line1 = "1. Lot 1  " + string(l1.isFull ? "Full" : "Available");
    string line2 = "2. Lot 2  " + string(l2.isFull ? "Full" : "Available");
    string line3 = "3. Lot 3  " + string(l3.isFull ? "Full" : "Available");
    setColor( (1 * 16) + 15 ); 
    printCentered("Lot Viewing System",5);
    setColor(10);
    printCentered(line1, 8);
    printCentered(line2,10);
    printCentered(line3,12);
    gotoxy(x,ya);
    system("pause");
    
}

//-----------------------Mains-----------------------
int main() {
    bool isRunning = true;
    SetConsoleOutputCP(437); 
    while(isRunning){
        system("cls");
        drawBox(13,3,100,25);
        setColor( (1 * 16) + 15 ); 
        printCentered("Parking Lot Manager",5);
        setColor(2);
        printCentered("1. Register Parking lots",8);
        setColor(4);
        printCentered("2. Free Parking Lots", 10);
        setColor(6);
        printCentered("3. View Parking Lots",12);
        setColor(4);
        printCentered("4. Exit",14);
        setColor(7);
        printCentered("Enter your Option [1,2,3,4]: ", 17);
        char ch = getch();
        opt = ch - '0';
        Beep(750, 300);
        switch (opt) {
            case 1: reg();break;
            case 2: del();break;
            case 3: view();break;
            case 4: isRunning=false;break;
        }
    }
    return 0;
}