#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
#include<limits.h>
#include<stdlib.h>
#include<iomanip.h>

class personal
{                  //CLASS FOR PERSONAL DETAILS
public:
char name[25];
char pass[20];
char add[40];
char pno[10];
long id;
long get_id()
{
return id;
}
char* get_pass()
{
return pass;
}
char* get_name()
{
return name;
}

};



class student:public personal
{                              //CLASS FOR STUDENT DETAILS
char ctr[10];
char fname[30];
char dob[13];
char str[10];
char cot[10];
public:
float fee;
float mark[6][3];
char sc;
char con[30];
float psub;
char sub[3][25];

student()
{
id=0;
}
void sl()
{
cout<<"Enter your Password:";
gets(pass);
clrscr();
si();
}

void si();
void so();
void testo();
void testi();
}st;


void student::so()            //MEMBER FUNCTIONS OF STUDENT
{
cout<<"\n-------------------------------------------------------------------------------";
cout<<"\nStudent ID:"<<id<<"\t\t\tName:"<<name<<"\t\tDOB:";
for(int i=0;i<8;i=i+2){cout<<dob[i]<<dob[i+1];if(!(i==6||i==4))cout<<"/";}
cout<<"\nFather's Name:"<<fname<<"\t\tAddress:"<<add;
cout<<"\nPhone Number:"<<pno<<"\t\tCourse Type:"<<cot<<"\t\tCentre:"<<ctr;
cout<<"\nCourse:"<<con<<"\t\tMonthly Fees:"<<int(fee/12);
cout<<"\n-------------------------------------------------------------------------------";
}


void student::si()
{
cout<<"\nComplete your registration........";
cout<<"\n-------------------------------------------------------------------------------";
cout<<"\nEnter the Name of Student:";
gets(name);
cout<<"Enter the Father's Name:";
gets(fname);
cout<<"Enter the Address:";
gets(add);
cout<<"Enter the Date of Birth(dd/mm/yyyy):";
gets(dob);
cout<<"Enter the Phone Number:";
gets(pno);

int ch,chs;
do
{
cout<<"\n1-> for Classroom Program Course";
cout<<"\n2-> for Distance Learning Course";
cout<<"\nEnter the Course you want to Avail.....";
cin>>ch;
       if(ch==1)
       {
       strcpy(cot,"CCP");
	    do
	    {
	    cout<<"\nAvailable Coaching Centres..";
	    cout<<"\n1->DELHI\n2->MUMBAI\n3->JAIPUR\n4->CHENNAI";
	    cout<<"\nEnter your choice:";
	    cin>>chs;
		 if(chs==1)
		 strcpy(ctr,"DELHI");
		 else if(chs==2)
		 strcpy(ctr,"MUMBAI");
		 else if(chs==3)
		 strcpy(ctr,"JAIPUR");
		 else if(chs==4)
		 strcpy(ctr,"CHENNAI");
		 else
		 cout<<"Invalid Option Selected...";
	    }while(ch<1||ch>4);
       }

       else if(ch==2)
       {
       strcpy(cot,"DLP");
       strcpy(ctr,"Nil");
       }

       else
       cout<<"\nInvalid Option Selected....";
}
while(ch<1||ch>2);

do
{
cout<<"\n\nCourses Offered.....";
cout<<"\n1-> JEE MAINS + ADVANCE    Rs.2,00,000";
cout<<"\n2-> JEE MAINS              Rs.1,40,000";
cout<<"\n3-> AIPMT/AIIMS            Rs.1,50,000";
cout<<"\n4-> KVPY/OLYMPIADS         Rs.50,000";
cout<<"\nEnter your choice:";
cin>>ch;
	 strcpy(sub[0],"Physics");
       strcpy(sub[1],"Chemistry");
       if(ch==1)
       {
       strcpy(con,"JEE MAINS + ADVANCE");
       fee=200000;
       strcpy(sub[2],"Mathematics");
       }
       else if(ch==2)
       {
       strcpy(con,"JEE MAINS");
       fee=140000;
       strcpy(sub[2],"Mathematics");
       }
       else if(ch==3)
       {
       strcpy(con,"AIPMT/AIIMS");
       fee=150000;
       strcpy(sub[2],"Biology");
       }
       else if(ch==4)
       {
       strcpy(con,"KVPY/OLYMPIADS");
       fee=50000;
       strcpy(sub[2],"Mathematics");
       }
       else
       {
       cout<<"\nInvalid Option Selected....";
       }
}while(ch<1||ch>4);
   cout<<"\nWanna to avail for Scholarship(Y/N):";
   cin>>sc;
   testi();
}

void student::testi()
{
clrscr();
  char ch;
cout<<"\nSubmit your test results........";
cout<<"\n-------------------------------------------------------------------------------";
   for(int i=0;i<6;i++)
   {
	cout<<"\nPress T to submit Test "<<i+1<<" marks or Press N if not attented";
	cin>>ch;
	cout<<"\nTEST:"<<i+1;

	if(ch=='T'||ch=='t')
	{
	cout<<"\nEnter marks of-\n";
	  for(int j=0;j<3;j++)
	  {
	    cout<<j+1<<"."<<sub[j]<<":";
	    cin>>mark[i][j];
	  }
	}
	else
	   for(int k=0;k<3;k++)
	   mark[i][k]=0;
   }
      cout<<"Test results have been submitted..........";
      getch();

clrscr();
}
void student::testo()
{
 cout<<endl;
 float sum=0;
cout<<"TEST"<<setw(11)<<sub[0]<<setw(14)<<sub[1]<<setw(16)<<sub[2]<<endl;
cout<<"--------------------------------------------------\n";
	for(int i=0;i<6;i++)
	{
	   cout<<"TEST "<<i<<":\t";
	   for(int j=0;j<3;j++)
	   {
	   cout<<setw(4)<<mark[i][j];
	   cout<<setw(5)<<"|"<<"\t";
	   sum+=mark[i][j];
	   }
	   cout<<endl;
	}
	cout<<"\t\t_______________________________\n";
       cout<<"\t\t\tPERCENTAGE:- "<<(sum/18)<<'%';
}


 class admin:public personal       //CLASS FOR ADMINISTRATOR
{
char qu[15];
char cname[30];
public:
int s;
void al()
{
cout<<"\nEnter Name of the OWNER OF COACHING INSTITUTE:";
gets(name);
cout<<"Enter the Password:";
gets(pass);
ai();
}

void ai()                        //MEMBER FUNCTIONS OF ADMIN
{
cout<<"Name of COACHING INSTITUTE:";
gets(cname);
cout<<"Total Number of Seats in Coaching Institute:";
cin>>s;
cout<<"Qualification:";
gets(qu);
cout<<"Address of Coaching Institute:";
gets(add);
cout<<"Contact Number of Coaching:";
gets(pno);
}

}a;

char c;

int exist(long id)
{
int flag=0;
ifstream ifile;
	 ifile.open("srecord.dat");
	 while(ifile.read((char *)&st,sizeof(st)))
	 {
		if(id==st.get_id())
		{
		flag=1;break;
		}

	 }
	 return flag;

}

void captcha()
{
  char ran[5][20]={"inquiry","overlook","definite","obsolute","hyperbole"};
	  char en[20];
	  int r;
	  randomize();
	  do
	  {
	  clrscr();
	 r=random(5);
	 cout<<"\nEnter the CAPTCHA...";
	 cout<<"\n************************************";
	 cout<<"\n*        "<<ran[r]<<"              *";
	 cout<<"\n************************************";
	 cout<<"\nType the words given above..";
	 gets(en);
	 }while(strcmp(en,ran[r])!=0);
}

void signup(char ch)
{
clrscr();
cout<<"\n       CREATING NEW USER......";
cout<<"\n   -----------------------------\n\n";


   char dot[15]=".............";
      if(ch=='a'||ch=='A')
      {
      a.al();
       //	  captcha();

	   ofstream ofile("arecord.dat");
	   ofile.write((char *)&a,sizeof(a));
	   ofile.close();
	   cout<<"\n\nPlease Wait....Signing Up";
	   for(int i=0;i<10;i++){delay(i+100);cout<<dot[i];};
	   cout<<"\n\n\nNow login to your Server.....";
	   cout<<"\nPress any key to continue..";
	   getch();
	   clrscr();
      }

      else
      {
      es:
      long x;
      cout<<"\nEnter your Student ID:";
      cin>>x;
      int f=exist(x);

	   if(f==0)
	   {   st.id=x;
	   st.sl();
	 //  captcha();
	   cout<<"\n-------------------------------------------------------------------------------";
	   cout<<"\nYou are succesfully registered with Coaching Institute....";
	   ofstream ofile("srecord.dat",ios::app);
	   ofile.write((char *)&st,sizeof(st));
	   ofile.close();
	   cout<<"\n\nPlease Wait....Signing Up";
	   for(int i=0;i<10;i++){delay(i+100);cout<<dot[i];};
	   cout<<"\n\n\nNow login to your newly created Account.....";
	   cout<<"\nPress any key to continue..";
	   getch();
	   clrscr();
	   }
	   else
	   {
	   clrscr();
	   cout<<"\n!!!!!!!!!!!!!!!!!!!";
	   cout<<"\nUser ID already exists!!!";
	   cout<<"\nTry another one if you are lucky enough!!";
	   goto  es;
	   }
      }

}


long login(char ch)
{
  long id;
  char name[25];
  char dot[15]=".............";
  char c;
  int o=2;
  char pass[20],y[20];
  delay(200);
   e:
   clrscr();

    if(ch=='a'||ch=='A')
    {
	cout<<"#############################################";
	cout<<"\n     ##........Logging In........##\n\n";
	int f=0;
	do
	{
	 cout<<"\nEnter Administrator Name:";
	 gets(name);
	 ifstream ifile("arecord.dat");

	  while(ifile.read((char *)&a,sizeof(a)))
	  {
		 if(strcmp(a.get_name(),name)==0)
		  {
		  f=1;
		   pt:
		   cout<<"Enter your password:";
			for(int i=0;;i++)
			{
			 pass[i]=getch();
			 cout<<pass[i];
			 delay(380);
			 cout<<char(8);
			     if(pass[i]==13)
			     {
			       pass[i]='\0';
			       break;
			     }
			 cout<<"*";
			}

		       if(strcmp(pass,a.get_pass())==0)
			{
			cout<<"\n\n.......Please wait.........Logging into your account";
			for(i=0;i<10;i++){delay(i+100);cout<<dot[i];}
			cout<<"\nPress any key to continue..";
			getch();
			clrscr();

			cout<<"\n##############.....!!....Welcome ADMINISTRATOR....!!......#################";
			cout<<"\n                    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ";
			cout<<"\n\n                             INSTITUTE OWNER :"<<a.name;

			return a.get_id();

			}
			else
			{
			      if(o==0)
			      {
			       cout<<"\n\nYour ID is temporarily blocked";
			       exit(0);
			      }
			cout<<"\n\n      !!!!..Incorrect Password..!!!!!!!!";
			cout<<"\n      Try again..( "<<o<<" attempts left..)\n";
			o--;
			  goto pt;

			}

		  }

	  }
	  ifile.close();

	  cout<<"\nUser ID does not exist...";
	}while(f==0);
    }

    else
    {
	cout<<"         ##........Login to your Account........##";
	cout<<"\n         .........................................\n\n";
	int f=0;
	do
	{
	 cout<<"\nEnter your User ID:";
	 cin>>id;
	 ifstream ifile("srecord.dat");

	  while(ifile.read((char *)&st,sizeof(st)))
	  {
		 if(st.get_id()==id)
		  {
		  f=1;
		   ps:
		   cout<<"Enter your password:";
			for(int i=0;;i++)
			{
			 pass[i]=getch();
			 cout<<pass[i];
			 delay(380);
			 cout<<char(8);
			     if(pass[i]==13)
			     {
			       pass[i]='\0';
			       break;
			     }
			 cout<<"*";
			}

		       if(strcmp(pass,st.get_pass())==0)
			{
			cout<<"\n\n.......Please wait.........Logging into your account";
			for(i=0;i<10;i++){delay(i+100);cout<<dot[i];}
			cout<<"\nPress any key to continue..";
			getch();
			clrscr();
			cout<<"\n##############.....!!....Welcome to your account....!!......#################";
			cout<<"\n                    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ";
			cout<<"\n                                                 USER ID:"<<st.get_id();

			return st.get_id();

			}
			else
			{
			      if(o==0)
			      {
			       cout<<"\n\nYour ID is temporarily blocked";
			       exit(0);
			      }
			cout<<"\n\n      !!!!..Incorrect Password..!!!!!!!!";
			cout<<"\n      Try again..( "<<o<<" attempts left..)\n";
			o--;
			  goto ps;

			}

		  }

	  }
	  ifile.close();

	  cout<<"\nUser ID does not exist...";
	}while(f==0);
    }

return 0;
}


int chk_file()
{
  int ps;
  ifstream ifile;
  ifile.open("srecord.dat");
  ifile.seekg(0,ios::end);
  ps=ifile.tellg();
  ifile.close();
  return ps;
}

void view(long iid=0)
{
       ifstream ifiles("srecord.dat");
       while(ifiles.read((char *)&st,sizeof(st)))
	      {
	      if(iid==0)
	      st.so();
	      else
	     if(iid==st.get_id())
	     {
	     st.so();
	     }

	       }
	       ifiles.close();
}

void modify(long iid)
{
    ifstream ifile1("srecord.dat");
       while(ifile1.read((char *)&st,sizeof(st)))
       {
	       if(iid==st.get_id())
	       {
	       st.si();
	       st.id=iid;
	       }

	       ofstream ofile("srecordn.dat");
	       ofile.write((char *)&st,sizeof(st));
	       ofile.close();
       }
      ifile1.close();
      remove("srecord.dat");
      rename("srecordn.dat","srecord.dat");

    cout<<"\n     The Account has been Updated Successfully.........";
}

void economy()
{
int count=0,t;
float fee=0;
 ifstream ifiles("srecord.dat");
       while(ifiles.read((char *)&st,sizeof(st)))
	      {
		count++;
		fee+=st.fee;
	       }
	       ifiles.close();
   ifstream ifile("arecord.dat");
   while(ifile.read((char *)&a,sizeof(a)))
   {
     t=a.s;
   }
   ifile.close();

 cout<<"\n                                         TOTAL   SEATS :"<<t;
 cout<<"\n                                       AVAILABLE SEATS :"<<(t-count);
 cout<<"\n                                       EARNING(/year)Rs."<<fee<<"\n";
}
void test(long iid)
{
 ifstream ifiles("srecord.dat");
       while(ifiles.read((char *)&st,sizeof(st)))
	      {
	     if(iid==st.get_id())
		    {
			  st.testo();

		    }

	       }
	       ifiles.close();
}

void deletee(long iid)
{
	 ifstream ifile("srecord.dat");
	 ofstream ofile("snrecord.dat",ios::app);
	 while(ifile.read((char *)&st,sizeof(st)))
	     {
			if(!(iid==st.get_id()))
			{
			ofile.write((char *)&st,sizeof(st));
			}

	     }
	 ifile.close();
	 ofile.close();
	 remove("srecord.dat");
	 rename("snrecord.dat","srecord.dat");
}


void sort()
{
int ps;
      remove("ssrecord.dat");
      do
      {
	long id=LONG_MAX;
       ifstream ifile1("srecord.dat");
       while(ifile1.read((char *)&st,sizeof(st)))
	     {
		   if(st.get_id()<id)
		   {
		    id=st.get_id();
		   }
	     }
	    ifile1.close();
       ifstream ifile2("srecord.dat");
       ofstream ofile("ssrecord.dat",ios::app);

       while(ifile2.read((char *)&st,sizeof(st)))
	    {
		    if(st.get_id()==id)
		    {
		ofile.write((char *)&st,sizeof(st));
		deletee(id);
		   }
	    }
       ifile2.close();
       ofile.close();
	  ps=chk_file();

      }while(ps!=0);
       remove("srecord.dat");
       rename("ssrecord.dat","srecord.dat");
    cout<<"The Records have been Sorted Successfully...................\n";
}

void list(char o)
{
long id;
	ifstream ifile("srecord.dat");
cout<<"____________________________________________________________________________";
cout<<"\n|       ID      |     NAME         |        COURSE     |        FEE        |";
cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
   while(ifile.read((char *)&st,sizeof(st)))
   {

   cout<<"\n        "<<st.id<<setw(23)<<st.name<<setw(22)<<st.con<<setw(18)<<st.fee;

  }
 ifile.close();


if(o=='v')
{
cout<<"\n\nEnter the ID of The Student To View His Record or Press 0 to View All Records:";

cin>>id;
if(id==0)
view();
else
view(id);
}

else
{
cout<<"\nEnter the ID of The Student To Delete His Record:";
cin>>id;
deletee(id);
cout<<"\nID "<<id<<" Has Been Successfully Deleted.....";
}
}

void schol()
{

 randomize();
 long r[3];
 int f,z,x;
 long B[3],A[100];
 int i=0;
 ifstream ifile("srecord.dat",ios::in|ios::binary);
   while(ifile.read((char *)&st,sizeof(st)))
   {
       if(st.sc=='Y'||st.sc=='y')
	{
	 A[i]=st.id;
	 i++;
	}
   }
	 ifile.close();


      for(int k=0;k<3;k++)
      {
	  m:
	  f=0;
	  x=0;
	  rand();
	  r[k]=random(10)+1;
	      for(int j=0;j<i;j++)
	      {
		 if(r[k]==A[j])
		 {
		    x=1;
		    B[k]=r[k];
		       z=k;
		       while(z!=0)
		       {
			 if(B[k]==B[z-1])
			 {
			 f=1;break;
			 }
			z--;
		       }
		     if(f==1)
		     goto m;
		     if((f==0)&&(x==1))
		     break;
		 }
	      }
	      if(x==0)
	      goto m;

      }

cout<<"\n  ................. THREE RANDOMLY SELECTED STUDENTS ARE.................  \n\n";
cout<<"____________________________________________________________________________";
cout<<"\n|       ID      |     NAME         |        COURSE     |    SCHOLARSHIP    |";
cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";

   float v=2500,y=4000,n=3;
  for(int j=0;j<3;j++)
  {
     ifstream ifile("srecord.dat");
   while(ifile.read((char *)&st,sizeof(st)))
   {
       if(st.get_id()==B[j])
       {
   cout<<"\n        "<<st.id<<setw(23)<<st.name<<setw(22)<<st.con<<setw(15)<<v+((n-j)*y);
       }
  }
 }
  ifile.close();


}

void credits()
{
clrscr();
char t[]="THANKS";
char e[]="EVERYONE";
  cout<<"\n                     __________________________________         ";
  cout<<"\n                    |          *   CREDITS   *         |        ";
  cout<<"\n...............................***************..................................";
  cout<<"__----------------------------_________________-------------------------------__";
  cout<<"\n                    |            ARJUN DIXIT            |      ";
  cout<<"\n                    |           ARIHANT MISHRA          |     ";
  cout<<"\n                    |          ASHUTOSH VARSHNEY        |    ";
  cout<<"\n                    |            ARPIT PANDEY           |  ";
  cout<<"\n                    |          YASHVENDRA SINGH         | ";
  cout<<"\n                     ___________________________________ \n\n";
  cout<<"\n                   ***************************************\n";
  cout<<"                   * SPECIAL THANKS TO OUR COMPUTER SIR  *";
  cout<<"\n                   *******    MR. RAHUL JOHARY    ********    ";
  cout<<"\n                         *         FOR HIS        *         ";
  cout<<"\n                         *    HELP AND SUPPORT    * ";
  cout<<"\n                         **************************      \n\n  ";
  cout<<"            ";
  for(int i=0;t[i];i++)
    {
      delay(150);
      cout<<"      "<<t[i];
    }
  for(int f=1;f<=45;f++)
  cout<<char(8);
  for(i=0;e[i];i++)
    {
      delay(150);
      cout<<"     "<<e[i];
    }
    getch();
    exit(0);
}
void display()
{
clrscr();
cout<<"           ***********************************************************";
cout<<"\n           *******NARAYAN COACHING INSTITUTE, THE PRIDE OF KOTA*******";
cout<<"\n           ***********************************************************";
}
void main()
{
  clrscr();
  char ch,c;
  char s[300]="\t********WELCOME TO NARAYAN COACHING INSTITUTE**********";


    for(int i=0;i<12;i++)
    {
       delay(40);
       cout<<"\n#                                                                             #";
    }
     gotoxy(15,12);
  cout<<"     ................................................\n\n\n\n";

  gotoxy(15,12);

   for(i=0;s[i];i++)
    {
      delay(20);
      cout<<s[i];
    }
  gotoxy(15,13);
  cout<<"     ................................................\n\n";


l:
cout<<"\n\n                 -> A for Administrator";
cout<<"\n                 -> S for Student";
cout<<"\n                 -> E to Exit the Program";
cout<<"\n                 -> D to Delete";
cout<<"\n\n                  Enter your choice:";
cin>>ch;
if(ch=='d'||ch=='D')     {
  remove("srecord.dat");
  remove("snrecord.dat");
  remove("arecord.dat");
  exit(0);}
if(ch=='e'||ch=='E')
{
credits();
}
 clrscr();
 display();
 cout<<"\n\n";
 cout<<"\n1-> SignUp for A New ACCOUNT";
 cout<<"\n2-> Login into An Existing ACCOUNT";
 cout<<"\n\nChoose one option:";
 cin>>c;
 if(c=='1')
  signup(ch);
 long iid=login(ch);

  if(ch=='a'||ch=='A')
  {
  char c;

	do
	{
	cout<<endl;
	economy();
  cout<<"\n1-> TO VIEW LIST OF ALL STUDENTS";
  cout<<"\n2-> TO DELETE A STUDENT RECORD";
  cout<<"\n3-> TO SORT THE RECORDS";
  cout<<"\n4-> TO SELECT STUDENTS RANDOMLY FOR SCHOLARSHIP";
  cout<<"\n5-> TO DELETE THE EXISTING DATABASE";
  cout<<"\n6-> TO LOG OUT";
  cout<<"\n\n\n.....Enter your Choice.....";

  cin>>c;
    if(chk_file()==0||chk_file()==-1)
    {
	cout<<"\n\n      Sorry!!! NO STUDENT EXISTS YET....";
	cout<<"\n\n            Logging Out...........";
	cout<<"\n             Press any key:";
	getch();
	display();
	goto l;
    }

    else
    {
	if(c=='1')
	list('v');
	else if(c=='2')
	list('d');
	else if(c=='3')
	sort();
	else if(c=='4')
	schol();
	else if(c=='5')
	{
	remove("srecord.dat");
	remove("arecord.dat");
	cout<<"\n   DATABASE DELETED SUCCESSFULLY...";
	cout<<"\n    EXITING THE PROGRAM..";
	delay(1000);
	credits();
	}

       else
       {
	display();
	goto l;
       }
    }
       cout<<"\n\nPress L to Log Out or any other key to Go To Menu:";
       cin>>c;
       clrscr();
       if(!(c=='l'||c=='L'))
       {
       cout<<"\n##############.....!!....Welcome ADMINISTRATOR....!!......#################";
       cout<<"\n                    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ";
       cout<<"\n\n                             INSTITUTE OWNER :"<<a.name;
       }
       else
       {
       display();
       goto l;
       }

      }while(!(ch=='l'||ch=='L'));


  }

  else
  {
  char ch;
   do
   {
     cout<<"\n1-> VIEW YOUR RECORD";
     cout<<"\n2-> CHANGE YOUR PERSONAL DETAILS";
     cout<<"\n3-> DELETE YOUR ACCOUNT";
     cout<<"\n4-> DISPLAY TEST RESULTS";
     cout<<"\n5-> LOG OUT OF YOUR ACCOUNT";
     cout<<"\n\n      ....Enter your Choice:";
     cin>>ch;


    if(ch=='1')
    view(iid);
    else if(ch=='2')
    modify(iid);
    else if(ch=='3')
    {
    deletee(iid);
     cout<<"\n       Account Deleted Successfully.........";
     delay(200);
     display();
    goto l;
    }
    else if(ch=='4')
    test(iid);
    else if(ch=='5')
    {
    display();
    goto l;
    }
    else
    cout<<"\nInvalid Option Selected....";

    cout<<"\n\nPress L to Log Out or any other key to Go To Menu:";
    cin>>ch;
    clrscr();
    if(!(ch=='l'||ch=='L'))
    {
    cout<<"\n##############.....!!....Welcome to your account....!!......#################";
    cout<<"\n                    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ";
    cout<<"\n                                                 USER ID:"<<iid;
    }
    else
    {
    display();
    goto l;
    }


   }while(!(ch=='l'||ch=='L'));
  }
   credits();
getch();
}

