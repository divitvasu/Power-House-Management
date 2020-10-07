#include<stdio.h>
#include<conio.h>            //Header files
#include<string.h>
#include<stdlib.h>
#include<time.h>

void admin();
void ptech();                //Authentication
void dist();

void generation();
void powercap();
void capfactor();            //Functionalities of the console
void efficiency();
void loadcap();
void distribution();

char choice;
int choice1;			//Global variables
FILE *fptr;

int c;

int main()
{
char name[20],ch;
char password[10];
int i;
do{
clrscr();
printf("\n\n**************************Power House Management Console************************\n");
printf("\nEnter username: ");
scanf("%s",name);
printf("\nEnter password: ");

 for(i=0;i<5;i++)
 {
  ch = getch();
  password[i] = ch;                        //User and password verification
  ch = '*' ;
  printf("%c",ch);
 }
	password[i] = '\0';
if (strcmp(name, "admin") == 0 && strcmp(password, "admin") == 0)
 {
   admin();
  }

else if (strcmp(name, "ptechnician") == 0 && strcmp(password, "ptech") == 0)
  {
   ptech();
   }

else if (strcmp(name, "distmanager") == 0 && strcmp(password, "distm") == 0)
  {
    dist();
   }
else
  {
   printf("\nIncorrect Username or Password!!");
   printf("\nAccess Denied!");
  }
printf("\n\nWould you like to sign-in as another user??(enter 1 to proceed)");
scanf("%d",&choice1);
}
while(choice1==1);

getch();
return 0;
}

void admin()                        //User functions
 {
   int a;
   
    time_t t;				//Time for log files
    time(&t);
	clrscr();
   fptr = fopen("logtimeadmin.txt", "a+");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   fputs(ctime(&t), fptr);
   fclose(fptr);

   do{
   clrscr();
   printf("**************************Power House Management Console************************\n\n");
   printf("1). Check the Throughput of Last 4 months & material details.\n");
   printf("2). Power capability.\n");
   printf("3). Check Capacity factor.\n");
   printf("4). Check various parameters of efficiencies.\n");
   printf("5). Check handled loads by Substations.\n");
   printf("6). Distribution by Substations.\n");
   printf("7). View your last login.\n");
   printf("********************************************************************************");
   printf("\nEnter your choice...\n");
   scanf("%d",&a);
   getchar();
   clrscr();
   switch(a)
    {
      case 1 :  generation();
		break;
      case 2 :  powercap();
		break;
      case 3 :  capfactor();
		break;
      case 4 :  efficiency();
		break;
      case 5 :  loadcap();
		break;
      case 6 :  distribution();
		break;
	  case 7 : 	fptr = fopen("logtimeadmin.txt", "a+");
                if (fptr) 
				{
                 while ((c = getc(fptr)) != EOF)
                 putchar(c);
                 fclose(fptr);
				 }
		         break;	   
      default:  printf("\nWrong Choice!!");
		break;
     }
     printf("\nWould you like to browse more menu's(y/n)?\n");
     scanf("%c",&choice);
     }
     while(choice=='Y' || choice=='y');
}

void ptech()
 {
   int a;
   time_t t;				//Time for log files
   time(&t);
   clrscr();
   fptr = fopen("logtimeptech.txt", "a+");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   fputs(ctime(&t), fptr);
   fclose(fptr);
   
   do{
   clrscr();
   printf("**************************Power House Management Console************************\n\n");
   printf("1). Power capability.\n");
   printf("2). Check Capacity factor.\n");
   printf("3). Check various parameters of efficiencies.\n");
   printf("4). View your last login.\n");
   printf("********************************************************************************");
   printf("\nEnter your choice...\n");

   scanf("%d",&a);
   getchar();
   clrscr();
   switch(a)
    {
      case 1 :powercap();
	      break;
      case 2 :capfactor();
	      break;
      case 3 :efficiency();
	      break;
	  case 4 : fptr = fopen("logtimeptech.txt", "a+");
                if (fptr) 
				{
                 while ((c = getc(fptr)) != EOF)
                 putchar(c);
                 fclose(fptr);
				 }
		         break;	   
      default:printf("\nWrong Choice!!");
    }
     printf("\nWould you like to browse more menu's(y/n)?\n");
     scanf("%c",&choice);
    }while(choice=='Y' || choice=='y');
}

void dist()
 {
   int a;
   time_t t;				//Time for log files
   time(&t);
   clrscr();
   fptr = fopen("logtimedist.txt", "a+");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   fputs(ctime(&t), fptr);
   fclose(fptr);
   
   do{
   clrscr();
   printf("**************************Power House Management Console************************\n\n");
   printf("1). Check handled loads by Substations.\n");
   printf("2). Distribution by Substations.\n");
   printf("3). View your last login.\n");
   printf("********************************************************************************\n");
   printf("\nEnter your choice...\n");

   scanf("%d",&a);
   getchar();
   clrscr();
   switch(a)
    {
      case 1 :  loadcap();
		break;
      case 2 :  distribution();
		break;
	  case 3 :  fptr = fopen("logtimedist.txt", "a+");
                if (fptr) 
				{
                 while ((c = getc(fptr)) != EOF)
                 putchar(c);
                 fclose(fptr);
				 }
		         break;	   
      default:  printf("\nWrong Choice!!");
		break;
    }
     printf("\nWould you like to browse more menu's(y/n)?\n");
     scanf("%c",&choice);
    } while(choice=='Y' || choice=='y');
}

void generation()                         //Functionality definations
{ long int throughp;
  throughp=(100*1*24*30);
  printf("********************************************************************************\n");
  printf("\nMonth (2016):      January:  February:  March:   April:\n\n");
  printf("Throughput(MWh):     40,000    46,660     55,000   62,300\n");
  printf("Coal Used(Ktons):    25.2      27.8       29.5     32\n");
  printf("Water Used(Klitres): 1,425     1,600      1,878    2,225\n");
  printf("Running cost:        101cr     112cr      130.2cr  143cr\n");
  printf("\n\nIt can be seen that the running cost and throughput have been less in the winter months, gradually increasing as summer approaches....");
  printf("\nAlso the max throughput of the plant= %ld\n",throughp);
  printf("********************************************************************************\n");
}

void powercap()
{ int x;
  printf("********************************************************************************\n");
  printf("\nNumber of Stacks=6\n");
  printf("Individual Capacities:\n");
  printf("Stack 1= 150 MW\nStack 2= 100 MW\nStack 3= 100 MW\nStack 4= 50 MW\nStack 5= 65 MW\nStack 6= 35MW\n");
  x=150+100+100+50+65+35;
  printf("\nNameplate capacity: %d MW from 6 Stacks.\n",x);
  printf("********************************************************************************\n");
}

void capfactor()
{ float avg,cf;
  avg=(70+74+79+88)/4;
  printf("********************************************************************************\n");
  printf("\nThe average output of the plant in 4 months: %f",avg);
  cf=avg/100;
  printf("\nThe capacity factor is: %f\n",cf);
  printf("********************************************************************************\n");
}

void efficiency()
{ float therm;
  printf("********************************************************************************\n");
  printf("\nHeat rate of the Coal used=10,700 BTU/KWh\n");
  printf("BTU content of a KWh of electricity generated=3,412 BTU\n");
  therm=(3412.0/10700.0);
  printf("Thermodynamic efficiency of the plant= %f\n",therm*100);
  printf("The Turbine efficiency is about 40%\n");
  printf("The Boiler efficiency is about 70%\n");
  printf("The Economic efficiency is about 50%\n");
  printf("Transmission losses are about 25%\n");
  printf("********************************************************************************\n");
}

void loadcap()
{  float conv1;
   conv1=(86.5*1000);  					 //For Converting to KWh
   printf("********************************************************************************\n");
   printf("Details Shown are for the current month!!\n");
   printf("\n\nEnergy generated in one hour= 86.5 MWh\n");
   printf("\nEnergy generated in KWh= %f",conv1);
   printf("\nPower in KW= %f\n",conv1);
   printf("\nThe above Power was consumed by the city an hour in this month...\n");
   printf("********************************************************************************\n");
}

void distribution()
{  float conv2;
   conv2=(86.5/100)*75;        //75% Power availaible due to losses in transmission
   printf("********************************************************************************\n");
   printf("Details Shown are for the current month!!\n\n");
   printf("The Power availaible for distribution= %f MW\n\n",conv2);
   printf("Substation:		Substation 1:	Substation 2:	  Substation3:\n\n");
   printf("Power Supplied(MW):      27.0MW          18.6MW            19.275MW\n");
   printf("Industries 3-phase:      18MW	   \t 13.6MW	           10.275MW\n");
   printf("Households 3-phase:      3MW		 2.5MW             1MW\n");
   printf("Households 1-phase:      6MW             2.5MW             8MW\n");
   printf("********************************************************************************\n");
}

