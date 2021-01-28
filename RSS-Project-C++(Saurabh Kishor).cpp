           
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>

using namespace std;
class pn // passenger class name
{
public:
int pnr;  
}x;  
void star(); 
class train
{
public:
int tno,ac,sleeper,sc,time,dist,fac,fsleeper,fsc;
char from[100],to[100],name[100],Tname[25],Dto[40],Spoint[40];
public:                        

void modify(); 
void del(); 
void display(); 
void acp(); 
void check(); 
void update(int); // FUNCTION TO UPDATE NO. OF
// SEATS AFTER CANCELLATION
int ret() 
{
return tno;
}
char *f1() 
{
return from;
}
char *t1() 
{
return to;
}
}t; 
void add(); 
void disp();     

 class book // tickets  booking  Class name.
{
public:
int no,tickets,pnr;
char pto[100],pfrom[100],clas[20];
long int amt;
int retpnr() 
{
return pnr;
}
int rettic() 
{
return tickets;
}
int retamt() 
{
return amt;
}
void get(); 
int assign(); 
void show(); 
void cancel(); 
}b; 

class passenger
{
public:
int pnr,page;
char psex,pname[100];
void getp(); 
void showp(int); 
}p; 
void admin(); // ADMIN SECTION TO MANIPULATE TRAIN
// RECORDS
int main() // STARTING MAIN FUNCTION
{
int n;
while(1)
{
star();

cout<< endl <<" WELCOME TO INDIAN RAILWAYS"<<endl;
 cout<<" ENTER 1 TO CHECK AVAILABILITY "<<endl;
 cout<<" ENTER 2 TO BOOK TICKETS"<<endl;
 cout<<" ENTER 3 FOR CANCELLATION"<<endl;
 cout<<" ENTER 4 FOR ADMIN ACCESS"<<endl;
 cout<<" ENTER 5 TO EXIT"<<endl;
cout<<" ENTER YOUR CHOICE - "<<endl;
cin>>n;

switch (n)
{
case 1 : t.check();
getch();
break;
case 2 : b.get();
getch();
break;
case 3 : b.cancel();
getch();
break;
case 4 : admin();
break;
case 5 : exit(0);
default: 
star();
cout<<" WRONG CHOICE";
//getchar();
} // END OF SWITCH
} // END OF WHILE
return 0;
} // END OF MAIN

void add() // FUNCTION TO WRITE TRAIN RECORDS
{

star();
fstream rr;
rr.open("train.dat",ios::app|ios::in|ios::binary);
char ch;
do
{

star();
t.acp();
rr.write((char*)&t,sizeof t);
cout<<" ENTER MORE RECORDS ? (Y/N) - ";
cin>>ch;
}while(ch=='y'||ch=='Y');
rr.close();
} // END OF FUNCTION

void disp() // FUNCTION TO DISPLAY TRAIN RECORDS
{
fstream rr;
rr.open("train.dat",ios::in|ios::binary);
while(rr.read((char*)&t,sizeof t))
{

star();
t.display();
}
rr.close();
} // END OF FUNCTION
void train::display() // FUNCTION TO DISPLAY TRAIN
//RECORD
{
star();
cout<<" TRAIN NUMBER "<<tno;
cout<<" TRAIN NAME"<<name;
cout<<" STARTING POINT"<<from;
cout<<" DESTINATION "<<to;
cout<<" NUMBER OF AC TICKETS AVAILABLE"<<ac;
cout<<" PRICE OF EACH AC TICKET Rs. "<<fac;
cout<<" NUMBER OF SLEEPER TICKETS AVAILABLE "<<sleeper;
cout<<" PRICE OF EACH SLEEPER CLASSTICKET Rs. "<<fsleeper;

cout<<" NUMBER OF SECOND CLASS TICKETSAVAILABLE "<<sc;
cout<<" PRICE OF EACH SECOND CLASSTICKET Rs. "<<fsc;
cout<<" DURATION OF JOURNEY (hrs) "<<time;
cout<<" TOTAL DISTANCE (km) "<<dist;
getch();
}
void train::acp() // FUNCTION TO ACCEPT TRAIN
// RECORDS
{

star();
cout<<" ENTER TRAIN NUMBER";cin>>tno;
cout<<" ENTER TRAIN NAME";gets(name);
cin>>Tname;
cout<<" ENTER STARTING POINT(From)"<<endl;

cin>>Spoint;

cout<<" ENTER DESTINATION POINT(To)"<<endl;
cin>>Dto;
//gets(to);
cout<<" ENTER NUMBER OF AC TICKETS TO BE MADE AVAILABLE ";
cin>>ac;
cout<<" ENTER PRICE OF EACH AC TICKETRs. ";cin>>fac;
cout<<" ENTER NUMBER OF SLEEPER TICKETS TO BE MADE AVAILABLE";cin>>sleeper;
cout<<" ENTER PRICE OF EACH SLEEPERTICKET Rs. ";cin>>fsleeper;
cout<<" ENTER NUMBER OF SECOND CLASSTICKETS TO BE MADE AVAILABLE";cin>>sc;

cout<<" ENTER PRICE OF EACH SECOND CLASS TICKET Rs. ";cin>>fsc;
cout<<" ENTER DURATION OF JOURNEY (hrs) ";cin>>time;
cout<<" ENTER TOTAL DISTANCE (km) ";cin>>dist;
} // END OF FUNCTION
void train::modify() // FUNCTION TO MODIFY TRAIN
//RECORD
{

star();
fstream rr;
rr.open("train.dat",ios::in|ios::out|ios::binary);
int id,f=0,n=0,p;
cout<<" ENTER TRAIN NUMBER OF TRAIN TO BE MODIFIED - ";
cin>>id;
while(rr.read((char*)&t,sizeof t))
{
n++;
if(id==t.ret())
{
acp();
p=(n-1)*(sizeof t);
rr.seekp(p,ios::beg);
rr.write((char*)&t,sizeof t);
f=1;
}
}

if(f==0)

{
cout<<" SORRY RECORD NOT FOUND !!";
}
rr.close();
} //END OF FUNCTION
void train::del() // FUNCTION TO DELETE TRAIN RECORDS
{

star();
int id,f=0;
fstream rr;
rr.open("train.dat",ios::in|ios::binary);
fstream t1;
t1.open("temp.dat",ios::out|ios::binary);
cout<<" ENTER TRAIN NUMBER OF TRAIN TO BE DELETED - ";
cin>>id;
while(rr.read((char*)&t,sizeof t))
{ // 1
if(id==t.ret())
{ // 2
char ch;
f=1;
t.display();
cout<<" ARE YOU SURE ? (Y/N) - ";
cin>>ch;
if(ch=='y'||ch=='Y')
{
cout<<" RECORD DELETED";
}
else
{
t1.write((char*)&t,sizeof t);
}
} // 2
else
t1.write((char*)&t,sizeof t);
} // 1
if(f==0)
{
cout<<" SORRY TRAIN NOT FOUND!!";
}
rr.close();
t1.close();
remove("train.dat");
rename("temp.dat","train.dat" );
} // END OF FUNCTION
void train::check() // FUNCTION TO CHECK TICKET
// AVAILABILITY
{
star();
char T[100],f[100];

int flag=0;
cout<<" ENTER THE STARTING POINT - ";
cin>>f;
//gets(f);
cout<<" ENTER THE DESTINATION - ";
cin>>T;
//gets(T);
fstream rr;
rr.open("train.dat",ios::in|ios::binary);
while(rr.read((char*)&t,sizeof t))
{
if( strcmpi(f,t.f1())==0 && strcmpi(T,t.t1())==0 )
{

star();
flag=1;
t.display();
}
} // END OF WHILE
if(flag==0)
{
cout<<" SORRY NO AVAILABLE TRAINS FOUND ";
}
} //END OF FUNCTION
void train::update(int q) // FUNCTION TO UPDATE TICKETS
// AFTER CANCELLATION
{
fstream rr;
int n,tic;
rr.open("booking.dat",ios::in|ios::out|ios::binary);
while(rr.read((char*)&b,sizeof b))
{
if(b.pnr==q)
{
n=b.no;
tic=b.tickets;
rr.close();
rr.open("train.dat",ios::in|ios::out|ios::binary);
rr.seekg(0,ios::beg);
int f=0,p;
while(rr.read((char*)&t,sizeof t))
{
f++;
if(t.tno==n) //1
{
p=(f-1)*(sizeof (t));
rr.seekp(p,ios::beg);
if(strcmpi(b.clas,"ac")==0)
{
t.ac+=tic;
rr.write((char*)&t,sizeof t);
}
else if(strcmpi(b.clas,"sleeper")==0)

{
t.sleeper+=tic;
rr.write((char*)&t,sizeof t);
}
else
{
t.sc+=tic;
rr.write((char*)&t,sizeof t);
}
} 
} 
rr.close();
break;
} 
} 
} 
void book::get() 
{
int n=1;
while(n==1)
{ 


star();
cout<<" WELCOME TO BOOKING MENU";
cout<<" ENTER 1 TO BOOK TICKETS";
cout<<" ENTER 2 TO GO BACK";
cout<<" ENTER YOUR CHOICE - ";
cin>>n;
if(n==1)
{ 

star();
int flag=0;
cout<<" ENTER THE BOARDING POINT - ";
gets(pfrom);
cout<<" ENTER THE DESTINATION - ";
gets(pto);
fstream rr;
rr.open("train.dat",ios::in|ios::binary);
fstream pas;
pas.open("passenger.dat",ios::app|ios::binary);
rr.seekg(0,ios::beg);
while(rr.read((char*)&t,sizeof t))
{ 
if( strcmpi(pfrom,t.f1())==0 && strcmpi(pto,t.t1())==0 )
{

star();

flag=1;
t.display();
}
} 
rr.close();
if(flag==0)
{
cout<<" SORRY NO AVAILABLE TRAINS FOUND ";
getch();
}

if(flag==1)
{ 
int f1=0;

star();
cout<<" ENTER THE TRAIN NUMBER OF WHICH YOU WANT TO BOOK TICKETS - ";cin>>no;
rr.open("train.dat",ios::in|ios::binary);
rr.seekg(0,ios::beg);
while(rr.read((char*)&t,sizeof t) )
{ 
if(no==t.ret())
{ 
f1=1;

cout<<" ENTER THE NUMBER OF TICKETS YOU WANT TO BOOK (MAX. 6) - ";
cin>>tickets;
if(tickets>6)
{
cout<<" SORRY CANNOT BOOK MORE THAN 6 TICKETS";
getch();
break;
}
cout<<" ENTER THE CLASS ( AC / SLEEPER /SECOND CLASS (SC) ) - ";
gets(clas);
if(strcmpi(clas,"ac")!=0 && strcmpi(clas,"sleeper")!=0 &&
strcmpi(clas,"sc")!=0)
{
cout<<" SORRY YOU HAVE ENTERED INCORRECT CLASS";
getch();
break;
}
int z;
z=b.assign(); // CALLING THE FUNCTION TO ASSIGN
// BOOKING DETAILS
if(z==0)
{
cout<<" SORRY CANNOT BOOK "<<tickets<<" TICKETS";
getch();
break;
}

else
{
for(int i=1;i<=tickets;i++)
{

star();
cout<<" ENTER DETAILS OF PASSENGER "<<i;
p.getp();
p.pnr=b.pnr;
pas.write((char*)&p,sizeof p);
}
pas.close();
b.show();
p.showp(b.pnr);
getch();
}
} 
} 
if (f1==0)
{
cout<<" SORRY YOU HAVE ENTERED INCORRECT TRAIN NUMBER ";
getch();
}
} 

pas.close();
rr.close();
} 
} 
} 
int book::assign() 
{
int n=0,p;
fstream rr;
rr.open("train.dat",ios::in|ios::out|ios::binary);
rr.seekg(0,ios::beg);
while(rr.read((char*)&t,sizeof t))
{
n++;
if(no==t.ret())
{
if(strcmpi(clas,"ac")==0)
{
amt=tickets*t.fac;
p=(n-1)*sizeof (t);
rr.seekp(p,ios::beg);

t.ac=t.ac-tickets;
if(t.ac<0)
{
return 0;
}
else
rr.write((char*)&t,sizeof t);
}
else if(strcmpi(clas,"sleeper")==0)
{
amt=tickets*t.fsleeper;
p=(n-1)*sizeof (t);
rr.seekp(p,ios::beg);
t.sleeper=t.sleeper-tickets;
if(t.sleeper<0)
return 0;
else
rr.write((char*)&t,sizeof t);
}
else
{
amt=tickets*t.fsc;
p=(n-1)*sizeof (t);
rr.seekp(p,ios::beg);
t.sc=t.sc-tickets;
if(t.sc<0)
return 0;

else
rr.write((char*)&t,sizeof t);
}
break;
}
}
fstream b1;
b1.open("booking.dat",ios::app|ios::binary);
fstream rr2;
rr2.open("pnr.dat",ios::in|ios::binary);
if(!rr2)
{
rr2.close();
rr2.open("pnr.dat",ios::in|ios::app|ios::binary);
rr2.seekp(0,ios::beg);
x.pnr=1000;
rr2.write((char*)&x,sizeof x);
rr2.close();
}
else
{
int d;
rr2.seekg(0,ios::beg);
while(rr2.read((char*)&x,sizeof x))
{
d=x.pnr;

}
rr2.close();
fstream r2;
r2.open("pnr.dat",ios::app|ios::binary);
x.pnr=++d;
r2.write((char*)&x,sizeof x);
r2.close();
}
b.pnr=x.pnr;
b1.write((char*)&b,sizeof b);
b1.close();
return 1;
} 

void book::show() // FUNCTION TO DISPLAY BOOKING
//DETAILS
{

star(); 
cout<<" TICKET";
 cout<<" PNR NUMBER - "<<pnr;
 cout<<" TRAIN NUMBER - "<<no;
 cout<<" TOTAL PASSENGERS - "<<tickets;
 cout<<" TOTAL AMOUNT - "<<amt;
 cout<<" BOARDING POINT - "<<pfrom;
 cout<<" DESTINATION - "<<pto;

cout<<" YOUR TICKET HAS BEEN RESERVED";
} 
void book::cancel() 
{
star();
train tr;
fstream b1;
b1.open("booking.dat",ios::in|ios::binary);
fstream rr;
rr.open("passenger.dat",ios::in|ios::binary);
fstream t;
t.open("temp",ios::out|ios::binary);
fstream tmp;
tmp.open("t2",ios::out|ios::binary);
int id;
int flag=0,f=0;
char ch;
cout<<" ENTER YOUR PNR NUMBER - ";
cin>>id;
while(b1.read((char*)&b,sizeof b))
{
if(id==b.retpnr())
{

star();
flag=1;

f=1;
cout<<" PNR NUMBER - "<<b.retpnr();
cout<<" TOTAL TICKETS - "<<b.rettic();
cout<<" TOTAL AMOUNT - "<<b.retamt();
 cout<<" TOTAL AMOUNT - "<<amt;
 cout<<" BOARDING POINT - "<<pfrom;
 cout<<" DESTINATION - "<<pto;
p.showp(id);
cout<<" ARE YOU SURE ? (Y/N) - ";
cin>>ch;
if(ch=='y'||ch=='Y')
{
cout<<" YOUR BOOKING HAS BEEN CANCELLED";
tr.update(id);
}
else
{
flag=0;
t.write((char*)&b,sizeof b);
}
}
else
{
t.write((char*)&b,sizeof b);
}
}
remove("booking.dat");

rename("temp","booking.dat");
if(flag==1)
{
rr.seekg(0,ios::beg);
while(rr.read((char*)&p,sizeof p))
{
if(id!=b.retpnr())
tmp.write((char*)&p,sizeof p);
}
remove("passenger.dat");
rename("t2","passenger.dat");
}
if(f==0)
{
cout<<" SORRY INVALID PNR ";
}
rr.close();
tmp.close();
b1.close();
t.close();

} // END OF FUNCTION
void passenger::getp()
{
star();
cout<<" ENTER NAME - ";gets(pname);
cout<<" ENTER AGE - ";cin>>page;
cout<<" ENTER SEX (M/F) - ";cin>>psex;
} // END OF FUNCTION
void passenger::showp(int q) // FUNCTION TO SHOW
// PASSENGER DETAILS
{
int i=14;
fstream rr;
rr.open("passenger.dat",ios::in|ios::binary);
cout<<" PASSENGER LIST";
cout<<" PASSENGER NAME - PASSENGER AGE - PASSENGER SEX ";
while(rr.read((char*)&p,sizeof p))
{
if(p.pnr==q)
{
cout<<pname;
cout<<page;
cout<<psex;
}
}
rr.close();
} // END OF FUNCTION
void admin() // FUNCTION TO MANIPULATE TRAIN
// RECORDS
{
star();
int m;
char p[20];
cout<<" ENTER THE PASSWORD - ";
for(int i=0;i<20;i++)
{
p[i]=getch();
if(p[i]==13)
{
p[i]='\0';
break;
}
else
cout<<"*";
}

if(strcmp(p,"sk123")==0)
{
do
{

star();
cout<<" ADMIN SECTION";
 cout<<endl<<" ENTER 1 TO CREATE NEW FILE"<<endl;
 cout<<" ENTER 2 TO ENTER NEW RECORD "<<endl;
 cout<<" ENTER 3 TO MODIFY A TRAIN RECORD"<<endl;
 cout<<" ENTER 4 TO DELETE A TRAIN RECORD"<<endl;
 cout<<" ENTER 5 TO DISPLAY ALL THE CURRENT RECORDS"<<endl;
 cout<<" ENTER 6 TO GO BACK"<<endl;
 cout<<" ENTER YOUR CHOICE - "<<endl;
cin>>m;
switch (m)
{
case 1: remove("train.dat");
add();
getch();
break;
case 2: add();
getch();
break;
case 3: t.modify();
getch();
break;
case 4: t.del();

getch();
break;
case 5: disp();
getch();
break;
}
}while(m>=1&&m<=5);
} // END OF IF
else
{

star();
cout<<" WRONG PASSWORD";
cout<<" ACCESS DENIED";
getch();
}
} // END OF FUNCTION
void star() // FUNCTION TO PRINT STARS ON SCREEN
{
	int i;
	for(i=1;i<81;i++)
	{
		cout<<"-";

	}
	for(i=1;i<25;i++)
	{
		cout<<"-";

	}
	cout<<endl;
}
