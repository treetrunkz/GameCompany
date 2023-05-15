#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class videogame      {
private:
        char *title, *publisher, *releasedate;
        float *price;
        int *availability;
public:
        videogame() {
            title= new char[25];
            publisher= new char [25];
            releasedate= new char [25];
            price= new float;
            availability= new int;
        }

        void add();
        void edit();
        void print();
        int search(char[],char[]);
        void purchase();

};

void videogame::add() {
    cin.ignore();
    cout<<"Publisher: "; cin.getline(publisher, 100);
    cout<<"Title: "; cin.getline(title, 100);
    cout<<"Release Date: "; cin.getline(releasedate, 100);
    cout<<"Price: "; cin>>*price;
    cout<<"Amount Available: "; cin>>*availability;
}

void videogame::edit() {
    cin.ignore();
    cout<<"Publisher: "; cin.getline(publisher, 100);
    cout<<"Title: "; cin.getline(title, 100);
    cout<<"Release Date: "; cin.getline(releasedate, 100);
    cout<<"Price: "; cin>>*price;
    cout<<"Amount Available: "; cin>>*availability;
}

void videogame::print() {
    cout<<"\nPublisher "<<publisher;
    cout<<"\nTitle "<<title;
    cout<<"\nReleased "<<releasedate;
    cout<<"\nPrice "<<price;
    cout<<"\nAvailable "<<availability;
}

int videogame::search(char titlebuy[20], char authorbuy[20]) {
    if(strcmp(titlebuy,title)==0 && strcmp(authorbuy,publisher)==0)
        return 1;
    else return 0;
}

void videogame::purchase() {
    int count;
    cout<<"How many would you like to purchase? ";
    cin>>count;
    if(count<=*availability)    {
        *availability=*availability-count;
        cout<<"Successful purchase. ";
        cout<<"You currently spent: "<<(*price)*count;

    }
}

int main()	{
    videogame *B[20];
    int i=0,r,t,choice;
    char titlebuy[20], authorbuy[20];
    while(1) {
        cout<<"\n\n\tMenu"
		<<"\n1. Enter New Game To Catalog"
		<<"\n2. Purchase"
		<<"\n3. Search"
		<<"\n4. Edit Details"
		<<"\n5. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>choice;        

		switch(choice)	{
			case 1:	B[i] = new videogame;
				B[i]->add();
				i++;	break;
				
			case 2: cin.ignore();
				cout<<"\nEnter Game Title: "; cin.getline(titlebuy,20);
				cout<<"Enter Publisher: ";  cin.getline(authorbuy,20);
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						B[t]->purchase();
						break;
					}
				}
				if(t==1)
				cout<<"\nThis Game is Not in Stock";
				break;
			case 3: cin.ignore();
				cout<<"\nEnter Title Of Game: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Game: ";  cin.getline(authorbuy,20);
				
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						cout<<"\nGame Found Successfully";
						B[t]->print();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Game is Not in Stock";
				break;
			
			case 4: cin.ignore();
				cout<<"\nEnter Title Of Game: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Game: ";  cin.getline(authorbuy,20);
				
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						cout<<"\nGame Found Successfully";
						B[t]->edit();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Game is Not in Stock";
				break;
			
			case 5: exit(0);
			default: cout<<"\nInvalid Choice Entered";
			
		}
	}

	

	
	
	return 0;
}