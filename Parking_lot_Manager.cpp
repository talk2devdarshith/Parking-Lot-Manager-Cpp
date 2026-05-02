#include<iostream>
#include<cstdlib>
#include<windows.h>
using namespace std;

int opt;

class parking_lot {
    public:
        bool isFull;
        virtual void clear() {
            isFull = false;
            cout<<"Lot is Clear\n";
            
        }
        virtual void full() {
            isFull = true;
            cout<<"Lot is Full\n";
            
        }
};

class lot1 : public parking_lot {
    public:
        void clear() override{
        	if(isFull == false){
        		cout<<"Lot 1 is already Cleared. Please select another lot\n";
			} else {
				isFull = false;
            	cout<<"Parking Lot 1 is Clear\n";
			}
        }
        void full() override{
            if(isFull == true){
        		cout<<"Lot 1 is already Full. Please select another lot\n";
			} else {
				isFull = true;
            	cout<<"Parking Lot 1 is Booked\n";
			}
            
        }
};
class lot2 : public parking_lot {
    public:
        void clear() override{
            if(isFull == false){
        		cout<<"Lot 2 is already Cleared. Please select another lot\n";
			} else {
				isFull = false;
            	cout<<"Parking Lot 2 is Clear\n";
			}
            
        }
        void full() override{
            if(isFull == true){
        		cout<<"Lot 2 is already Full. Please select another lot\n";
			} else {
				isFull = true;
            	cout<<"Parking Lot 2 is Booked\n";
			}
            
        }
};
class lot3 : public parking_lot {
    public:
        void clear() override{
            if(isFull == false){
        		cout<<"Lot 3 is already Cleared. Please select another lot\n";
			} else {
				isFull = false;
            	cout<<"Parking Lot 3 is Clear\n";
			}
            
        }
        void full() override{
            if(isFull == true){
        		cout<<"Lot 3 is already Full. Please select another lot\n";
			} else {
				isFull = true;
            	cout<<"Parking Lot 3 is Booked\n";
			}
            
        }
};
lot1 l1;
lot2 l2;
lot3 l3;

void reg() {
	system("cls");
    cout<<"\n\n\tParking Registeration\n";
    cout<<"-------------------------------------\n";
    cout<<"\t1.Lot 1  "<<(l1.isFull ? "Full" : "Available")<<"\n\t2.Lot 2  "<<(l2.isFull ? "Full" : "Available")<<"\n\t3.Lot 3  "<<(l3.isFull ? "Full" : "Available")<<"\n";
    cout<<"\n\tEnter Your Choice :";
    cin>>opt;
    Beep(750, 300);
    switch (opt) {
        case 1: l1.full();break;
        case 2: l2.full();break;
        case 3: l3.full();break;
    }
    system("pause");
    Beep(750, 300);
    system("cls");
}
void del(){
	system("cls");
    cout<<"\n\n\t\tParking Lot Freeing System\n";
    cout<<"-------------------------------------------\n";
    cout<<"\t1.Lot 1  "<<(l1.isFull ? "Full" : "Available")<<"\n\t2.Lot 2  "<<(l2.isFull ? "Full" : "Available")<<"\n\t3.Lot 3  "<<(l3.isFull ? "Full" : "Available")<<"\n";
    cout<<"\n\tEnter Your Choice :";
    cin>>opt;
    Beep(750, 300);
    switch (opt) {
        case 1: l1.clear();break;
        case 2: l2.clear();break;
        case 3: l3.clear();break;
    }
    system("pause");
    Beep(750, 300);
	system("cls");
}
void view(){
	system("cls");
    cout << "\n\n\tParking Lot Status\n";
    cout << "-------------------------------------\n";
    cout << "Lot 1: " << (l1.isFull ? "Full" : "Available") << endl;
    cout << "Lot 2: " << (l2.isFull ? "Full" : "Available") << endl;
    cout << "Lot 3: " << (l3.isFull ? "Full" : "Available") << endl;
    system("pause");
    Beep(750, 300);
    system("cls");
}

int main() {
	system("color 02");
    parking_lot* pl;
    
    int i = 1;
    while(i != 0){
    	system("cls");
        cout<<"\n\n\t\tParking Lot Manager\n";
        cout<<"------------------------------------------------\n";
        cout<<"\t1.Register Parking Lot\n\t2.Free Parking Lot\n\t3.View Parking lots\n\t4.Exit\n";
        cout<<"\n\tEnter Your Option :";
        cin>>opt;
        Beep(750, 300);
        switch(opt){
            case 1: reg();break;
            case 2: del();break;
            case 3: view();break;
            case 4: cout<<"\nExiting ... ";i=0;
        }
    }
    return 0;
}
