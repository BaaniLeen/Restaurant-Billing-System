#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>


const int NoMenu=5;
const char VL=179,HL=196,TL=218,TR=191,BL=192,BR=217;
const char DVL=186,DHL=205,DTL=201,DTR=187,DBL=200,DBR=188;


void Color(int TC,int BC)//For Changing Text Color and Text Background
{
	textcolor(TC);
	textbackground(BC);
}

void ShowXY(int X,int Y,char CH)//Displays a character at X,Y position
{
	gotoxy(X,Y);
	cprintf("%c",CH);  //cout<<CH;
}

void ShowXY(int X,int Y,char CH[])//Displays a string at X,Y position
{
	gotoxy(X,Y);
	cprintf("%s",CH);  //cout<<CH;
}

void Vline(int X,int Y,int L)//To vertical line by joining vert. characters
{
	for (int i=Y;i<=Y+L;i++)
		ShowXY(X,i,VL);
}
void Hline(int X,int Y,int L)//To horizontal line by joining hor.characters
{
	for (int i=X;i<=X+L;i++)
		ShowXY(i,Y,HL);
}
void Recta(int C1,int R1,int C2,int R2)
{
	ShowXY(C1,R1,TL);             //
	ShowXY(C1,R2,BL);             //Placing corner characters
	ShowXY(C2,R1,TR);             //
	ShowXY(C2,R2,BR);             //
	Vline(C1,R1+1,R2-R1-2);       //
	Vline(C2,R1+1,R2-R1-2);       //Joining Corners by Vertical lines
	Hline(C1+1,R1,C2-C1-2);       //
	Hline(C1+1,R2,C2-C1-2);       //Joining Corners by Horizontal lines
}
				 //X,Y are coordinates for displaying menu
				 //Mnu all choices which required to be displayed as Menu Choices
				 //Noc no. of choices
int Vmenu(int X,int Y,char Mnu[][100],int Noc)
{
	Color(WHITE,CYAN);
	Recta(X,Y,X+strlen(Mnu[0])+1,Y+Noc+1);
	for (int i=0;i<Noc;i++)
		ShowXY(X+1,Y+i+1,Mnu[i]);

	int Sel=0,Exit=0;//Sel - Current Selected Option
									 //Exit- Control Variable for loop
	do
	{
		int Tsel=Sel;    //To store the current selection in Tsel
		Color(CYAN,WHITE);
		ShowXY(X+1,Y+Sel+1,Mnu[Sel]);
		Color(WHITE,CYAN);
		char Cho=getch();
		//71:Home  72:Up   73:Pup   75:Left   77:Right  79:End  80:Dn 81:PD
		switch(Cho)
		{
		 case 71:Sel=0;break;
		 case 79:Sel=Noc-1;break;
		 case 72:if (Sel==0)
				 Sel=Noc-1;
			 else
				 Sel--;
			 break;
		 case 80:if (Sel==Noc-1)
				 Sel=0;
			 else
				 Sel++;
			 break;
		 case 13:Exit=1; //Enter Key
			 break;
		 case 27:Sel=-1; //Escape
			 Exit=1;
			 break;
		}
		ShowXY(X+1,Y+Tsel+1,Mnu[Tsel]);
	}
	while (!Exit);
	return Sel;
}

int Hmenu(int X,int Y,char Mnu[][100],int Noc)
{
	Color(WHITE,CYAN);
	for (int i=0;i<Noc;i++)
		ShowXY(X+15*i+1,Y,Mnu[i]);
	int Sel=0,Exit=0;
	do
	{
		int Tsel=Sel;    //To store the current selection in Tsel
		Color(CYAN,WHITE);
		ShowXY(X+15*Sel+1,Y,Mnu[Sel]);
		Color(WHITE,CYAN);
		char Cho=getch();
		//71:Home  72:Up   73:Pup   75:Left   77:Right  79:End  80:Dn 81:PD
		switch(Cho)
		{
		 case 71:Sel=0;break;
		 case 79:Sel=Noc-1;break;
		 case 75:if (Sel==0)
				 Sel=Noc-1;
			 else
				 Sel--;
			 break;
		 case 77:if (Sel==Noc-1)
				 Sel=0;
			 else
				 Sel++;
			 break;
		 case 13:Exit=1;
			 break;
		 case 27:Sel=-1;
			 Exit=1;
			 break;
		}
		ShowXY(X+15*Tsel+1,Y,Mnu[Tsel]);
	}
	while (!Exit);
	return Sel;
}


void ClearArea(int C1,int R1,int C2,int R2)
{
	window(C1,R1,C2,R2);
	clrscr();
	window(1,1,80,25);
}

class Food

{
 int Fno;
 int Fcno;
 float FPrice;
 char FName[31];

 public:
  void Input()            {cout<<"Food No:\t";cin>>Fno; cout<<"\nFood Name:\t"; gets(FName); cout<<"\nFood Price:\t"; cin>>FPrice;cout<<endl;}
  void Output()           {cout<<Fno<<"\t"<<FName<<"\t"<<FPrice<<"\n";}
  void Disp_Price()       { cout<<"Rs."<<FPrice; }
  void Disp_Name()        { puts(FName); }
  float Ret_Price()       { return FPrice; }
  char* Ret_Name()        { return FName; }
  int Ret_FNo()           { return Fno; }
  void EditPrice_n()      { cout<<"\nEnter Modified Price:\t"; cin>>FPrice;}

};

class Bill
{
  int Bno;
  int Fno;
  int Qty;
  float Amount;
public:
  void Assign(int N, int F, int Q, float A)
  {
    Bno = N;
    Fno = F;
    Qty = Q;
    Amount = A;
  }
  void showdetails()
  {
    cout<<Bno<<" "<<Fno<<" " <<Qty<<" "<<Amount<<endl;
  }
  int Rbno() {return Bno;}
  float RAmount() {return Amount;}
  int RFno() {return Fno;}
};


void EditPrice();     //To Change the Price of a Food Item
void design();        //Restaurant Logo
void Create_Menu();   //Create Menu
void Display_Menu();  //Display Menu
void Order();         //Order Items
void Add_Menu();      //Add Food Items to the Menu
void Delete_Menu();    //Delete Food Items to the Menu
void Admin();          //Admin control
void Admin_c();        //Admin Control if the password is correct
void Cancel_Order();   //Delete particular items from the menu
void Enter();
void Show_Bill();
void PB();
void COM();
void SUG();
void REV();
void CS();
void User();
void Exit();
void Show_bill();




//*********************************************************************


void main()
{
	clrscr();
	design();
	getch();
	clrscr();
	char MainMenu[][100] = {	"ADMIN",
					"USER ",
					"EXIT"
			       };

	int Ch;

	do
	{
		Color(WHITE,CYAN);
		clrscr();

		Ch = Vmenu(35,8,MainMenu,3);

		switch(Ch)
		{
			case 0:	Admin(); break;
			case 1:	User (); break;
			case 2: Exit();
		}
	}while(Ch!=2);
}

//********************************************************************


//**************LOGO DESIGN*******************************************

void design()
{

  Color(WHITE,CYAN);
  clrscr();
  gotoxy(20,2);
  cout<<"THE FOOD YOUR TASTEBUDS CAN'T RESIST...!!";
  gotoxy(33,5);
  cout<<"WELCOME TO";

  // For J

  gotoxy(11,12);
  for(int i=1;i<9;i++)
   cout<<(char)175;
  gotoxy(15,12);
  for(i=1;i<9;i++)
  {
   gotoxy(15,12+i);
   cout<<(char)175;
  }
  for(i=1;i<5;i++)
  {
   gotoxy(15-i,20-i);
   cout<<(char)175;
  }

  //For O

  gotoxy(20,12);
  for(i=1;i<9;i++)
  cout<<(char)175;
  for(i=1;i<9;i++)
  {
   gotoxy(28,12+i);
   cout<<(char)175;
  }
  for(i=1;i<9;i++)
  {
   gotoxy(28-i,20);
   cout<<(char)175;
  }
  for(i=1;i<9;i++)
  {
   gotoxy(20,20-i);
   cout<<(char)175;
  }

  //For L

  for(i=1;i<10;i++)
  {
   gotoxy(35,11+i);
   cout<<(char)175;
   }
  for(i=1;i<6;i++)
   cout<<(char)175;

   //For L

  for(i=1;i<10;i++)
  {
   gotoxy(42,11+i);
   cout<<(char)175;
  }
  for(i=1;i<6;i++)
   cout<<(char)175;

  //For Y

  for(i=1;i<6;i++)
  {
   gotoxy(52+i,11+i);
   cout<<(char)175;
   }
  for(i=1;i<10;i++)
  {
   gotoxy(62-i,11+i);
   cout<<(char)175;
   }

   //For '

   gotoxy(63,11);
   cout<<(char)219;
   gotoxy(63,12);
   cout<<(char)222;

   //For S

   for(i=1;i<6;i++)
   {
    gotoxy(65+i,12);
    cout<<(char)175;
   }
   for(i=1;i<6;i++)
   {
    gotoxy(65+i,16);
    cout<<(char)175;
   }
   for(i=1;i<6;i++)
   {
    gotoxy(64+i,20);
    cout<<(char)175;
    }
   for(i=1;i<6;i++)
   {
    gotoxy(70,15+i);
    cout<<(char)175;
   }
   for(i=1;i<6;i++)
   {
    gotoxy(65,11+i);
    cout<<(char)175;
   }

 }
//***************************************************************


//*********** ADMIN CONTROL******************************************
void Admin()
{
	textcolor(WHITE);
        char u[25],p[25];
	clrscr();
	cout<<"USERNAME:\t";
	gets(u);
	cout<<"\nPASSWORD:\t";
	gets(p);
	 if(strcmpi(u,"abc")==0 && strcmpi(p,"123")==0)
	    Admin_c();
	 else
	    cout<<"\nInvalid username or password....\n";
}

void Admin_c()
{
	char Admin_cMenu[][100]= {  "CREATE MENU",
                                    "ADD MENU",
				    "DELETE MENU",
				    "EDIT PRICE",
				    "EXIT"
				  };
	int Ch;
	do
	{
		Color(WHITE,CYAN);
		clrscr();
		Ch =Hmenu(1,1,Admin_cMenu,5);
		switch(Ch)
		{
			case 0: Create_Menu(); break;
			case 1:	Add_Menu();    break;
			case 2:	Delete_Menu(); break;
			case 3: EditPrice();   break;
			case 4: Exit();
		}

	}while(Ch!=4);

}


void Create_Menu()  //Allows the restaurant owner to design his own menu
{
   clrscr();
   int c;
   char FName[25];
   cout<<"Choose the Desired Cuisine:\n";
   cout<<"1.Chinese\t2.Italian\t3.Indian\n";
   cin>>c;
    
     if(c==1)  strcpy(FName,"Menu_Chi.dat");
      else if (c==2) strcpy(FName,"Menu_Ita.dat");
      else if (c==3) strcpy(FName,"Menu_Ind.dat");
      else cout<<"Enter a valid cuisine....\n";

   fstream file1;
   Food F;
   file1.open(FName,ios::binary|ios::out);
   char ch;
   clrscr();
   do
   {
    F.Input();
    file1.write((char*)&F,sizeof(F));
    cout<<"More(Y/N)?";
    cin>>ch;
    cout<<"\n";
   }
   while(ch=='y');
   file1.close();
}


void Add_Menu()  //To Add Items to the Existing Menu
{
   int c;  char FName[25];
   clrscr();
   cout<<"Choose the Desired Cuisine:\n";
   cout<<"1.Chinese\t2.Italian\t3.Indian\n";
   cin>>c;
    if(c==1)  strcpy(FName,"Menu_Chi.dat");
    else if (c==2) strcpy(FName,"Menu_Ita.dat");
    else if (c==3) strcpy(FName,"Menu_Ind.dat");
    else cout<<"Enter a valid cuisine....\n";
   fstream file;
   Food F;
   file.open(FName,ios::binary|ios::app);
   char ch;
   clrscr();
   do
  {
    F.Input();
    file.write((char*)&F,sizeof(F));
    cout<<"\nMore(Y/N)?";
    cin>>ch;

  }while(ch=='y'||ch=='Y');

  file.close();
}


void Delete_Menu()
{
  int c;  char FName[25];
  clrscr();
  cout<<"Choose the Desired Cuisine:\n";
  cout<<"1.Chinese\t2.Italian\t3.Indian\n";
  cin>>c;
   if(c==1)  strcpy(FName,"Menu_Chi.dat");
   else if (c==2) strcpy(FName,"Menu_Ita.dat");
   else if (c==3) strcpy(FName,"Menu_Ind.dat");
   else cout<<"Enter a valid cuisine....\n";
  
  clrscr();
  fstream file1,file2;
  Food F;
  int FNoD;//Food Number to be deleted
  file1.open(FName,ios::binary|ios::in);
  file2.open("New.dat",ios::binary|ios::out);
  cout<<"\nEnter food no. to be deleted..";
  cin>>FNoD;
  int del=0;

  while(file1.read((char*)&F,sizeof(F)))
 {
     if(F.Ret_FNo()!=FNoD)
	file2.write((char*)&F,sizeof(F));
      else
	del++;
 }
    if(!del)
       cout<<"Record match not found...."<<endl;
    else
       cout<<"Record deleted..."<<endl;
     file1.close();
     file2.close();

    file1.open(FName,ios::binary|ios::out);
    file2.open("New.dat",ios::binary|ios::in);

    while(file2.read((char*)&F,sizeof(F)))
     file1.write((char*)&F,sizeof(F));
    file1.close();
    file2.close();

}


void EditPrice()
{
  int c;char FName[25];
  clrscr();
  cout<<"Choose the Desired Cuisine:\n";
  cout<<"1.Chinese\t2.Italian\t3.Indian\n";
  cin>>c;
  if(c==1)  strcpy(FName,"Menu_Chin.dat");
  else if (c==2) strcpy(FName,"Menu_Ita.dat");
  else if (c==3) strcpy(FName,"Menu_Ind.dat");
  else cout<<"Enter a valid cuisine....\n";

  clrscr(); 
  int FPrice,SFNo;
  cout<<"\nEnter the food number whose price is to be modified....\t";
  cin>>SFNo; 
  
  fstream file;
  file.open(FName,ios::binary|ios::in|ios::out);
  Food F;
  int found =0;

  //Search for a record matching with Fno whose price is to be changed

  while(!found && file.read((char*)&F,sizeof(F)))
     if(F.Ret_FNo()==SFNo) found++;

  if(found)
  {
    F.EditPrice_n();
    int n=file.tellg()-sizeof(F);//Finds the searched record's position
    file.seekp(n);		 //Moves file pointer for re-writing edited record
    file.write((char*)&F,sizeof(F));
  }
  else
   cout<<"No record matching for editing..."<<endl;
   file.close();
}


void Exit()
{
  clrscr();
  ShowXY(20,10,"THANKS FOR COMING.\nPLEASE VISIT US AGAIN!...");
  getch();
}




//*************************************************************************************





//************ USER CONTROL ***********************************************************

void User()
{

   char UserMenu[5][100] = {   "VIEW MENU ",
			       "CANCEL ORDER",
			       "PAY BILL   ",
			       "HOW WAS IT?",
			       "EXIT       "
				 };
  int Ch=0;
  do
  {
   Color(WHITE,CYAN);
   clrscr();
   Ch = Hmenu(1,1,UserMenu,5);
   switch(Ch)
   {
     case 0:  Display_Menu(); break;
     case 1:  Cancel_Order(); break;
     case 2:  PB();break;
     case 3:  CS();break;
     case 4:  Exit();
   }
  }while(Ch!=4);
}

int getlastbill()
{
  Bill B;
  int Bn=0;
  fstream file;
  file.open("User_Bill.dat",ios::binary|ios::in);
  while(file.read((char*)&B,sizeof(B)))
      Bn = B.Rbno();
  file.close();
  return Bn;
}



void Display_Menu()
{
   int c;
   clrscr();
   char FName[25];
   cout<<"Choose the Desired Cuisine:\n";
   cout<<"1.Chinese\t2.Italian\t3.Indian\n";
   cin>>c;
   if(c==1) strcpy(FName,"Menu_Chi.dat");
    else if (c==2) strcpy(FName,"Menu_Ita.dat");
    else if (c==3) strcpy(FName,"Menu_Ind.dat");
    else cout<<"Enter a valid cuisine....\n";

   fstream file;
   Food F;
   file.open(FName,ios::binary|ios::in);
   clrscr();
   cout<<"Fno\tFName\tFPrice\n";
   while (file.read((char*)&F,sizeof(F)))
   {
	F.Output();
	cout<<endl;
   }
  file.close();

  char ch;
  int i;
  int FSel,Fquant;
  Bill B;
  fstream file1,file2;

  int Bn= getlastbill()+1;
  file2.open("User_Bill.dat",ios::binary|ios::app);
  do
 {

  cout<<"\n\nEnter the Food Item Number to be ordered....\t";
  cin>>FSel;
  cout<<"\nEnter the quantity...\t";
  cin>>Fquant;
/*  file1.seekg(0);
  cout<<"At"<<file1.tellg(); getch();*/
  file1.open(FName,ios::binary|ios::in);
  while(file1.read((char*)&F, sizeof(F)))
  {
    if(F.Ret_FNo()==FSel)
    {
      cout<<"Matched...";getch();
      float A = Fquant * F.Ret_Price();
      B.Assign(Bn, FSel, Fquant, A);
      file2.write((char*)&B,sizeof(B));
    }
   }
  cout<<"\nMore?(Y/N)";
  cin>>ch;
   file1.close();
 }while(ch=='y'||ch=='Y');


  file2.close();
}


void Cancel_Order()
{
 clrscr();
 ShowXY(1,3,"The Following Items Have Been Ordered By You:");
 Show_bill();
 Bill B;
 int N1,N2;
 int Dele=0;
 ShowXY(1,18,"Enter Bill no. to edit  ");
 cin>>N1;
 ShowXY(1,18,"Enter food no. to cancel  ");
 cin>>N2;
 ifstream fil1;
 ofstream fil2;
 fil1.open("User_Bill.dat",ios::binary);
 fil2.open("Billnew.dat",ios::binary);

 while(fil1.read((char*)&B,sizeof(B)))
 {
   if(B.Rbno()!=N1 && B.RFno() !=N2 &&!Dele)
   {
    fil2.write((char*)&B,sizeof(B));
    Dele++;
   }
 }

 gotoxy(1,20);

 if(!Dele)
  cout<<"Food Item not found"<<endl;
 else
  cout<<"Food Item removed"<<endl;

 fil1.close();
 fil2.close();

 fil1.open("Billnew.dat",ios::binary);

 fil2.open("User_Bill.dat",ios::binary);

 while(fil1.read((char*)&B,sizeof(B)))
  fil2.write((char*)&B,sizeof(B));

 ShowXY(1,22,"To select another food item please return to VIEW MENU");

 getch();

}


void Show_bill()
{
 Bill B;
 ifstream fil;
 fil.open("User_Bill.dat",ios::binary);
 gotoxy(1,5);
 while(fil.read((char*)&B,sizeof(B)))
 {
  B.showdetails();
  getch();
 }
 fil.close();
}


void PB()
{
 Bill B;
 int N;
 float Sum=0;
 ifstream file;
 file.open("User_Bill.dat",ios::binary);

 gotoxy(1,10);
 cout<<"Enter Bill No. to make payment...";
 cin>>N;
 while(file.read((char*)&B,sizeof(B)))
 {
  if(N==B.Rbno())
  {
    B.showdetails();
    Sum+=B.RAmount();
    getch();
  }
 }
 file.close();
 cout<<"Your Net Amount is: Rs."<<Sum;
 getch();
}


void CS()
{
 char SMenu[3][100] = {	"COMPLAINT   " ,
			"SUGGESTION  " ,
			"REVIEW      "
			};
 int Ch;
 Ch = Vmenu(47,5,SMenu,3);
 switch(Ch)
 {
  case 0:	ClearArea(47,5,60,15);COM(); break;
  case 1:	ClearArea(47,5,60,15);SUG();break;
  case 2:	ClearArea(47,5,60,15);REV();
  }
}


void COM()
{
  char C[100];
  ShowXY(20,7, "WE ARE SORRY FOR THE INCONVENIENCE.");
  gotoxy(20,10);
  cout<<"Your Complaint?";
  gets(C);
  ShowXY(20,20,"YOUR COMPLAINT HAS BEEN REGISTERED");
  getch();
}


void SUG()
{
  char S[100];
  ShowXY(20,7, "HELP US SERVE YOU BETTER!");
  gotoxy(20,10);
  cout<<"Your Suggestion?";
  gets(S);
  gotoxy(20,20);
  cout<<"THANKS FOR THE SUGGESTION!";
  getch();
}

void REV()
{
  char R[100];
  ShowXY(20,7, "HOW SATISFIED WERE YOU?");
  gets(R);
}
