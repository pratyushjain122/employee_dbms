// EMPLOYEE DATABASE MANAGEMENT SYSTEM

#include <stdio.h> 		//for input output functions like printf, scanf
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 	//for windows related functions (not important)
#include <string.h>  	//string operations
//#include<graphics.h>

/* List of Global Variable */

COORD coord = {0,0}; 	// top-left corner of window

/*
    function : gotoxy
    @param input: x and y coordinates
    @param output: moves the cursor in specified position of console
*/

void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void add(void);
void display(void);
void modify(void);
void deletee(void);
void menu(void);

int admin()
{	
	system("COLOR 4e");
	printf("\t====================================================================================================\n");
	printf("\t|||                                                                                              |||\n");
	printf("\t|||                                                                                              |||\n");
	printf("\t|||                                                                                              |||\n");
	printf("\t|||                                                                                              |||\n");
	printf("\t|||                    **********************************************                            |||\n");
	printf("\t|||                                                                                              |||\n");
	printf("\t|||                        EMPLOYEE DATATBASE MANAGEMENT SYSTEM                                  |||\n");
	printf("\t|||                                                                                              |||\n");
	printf("\t|||                    **********************************************                            |||\n");
	printf("\t|||                                                                                              |||\n");
	printf("\t|||                                                                                              |||\n");
	printf("\t|||                                                                                              |||\n");
	printf("\t|||                                                                                              |||\n");
	printf("\t====================================================================================================\n");
	
	printf("\n\n\n\t\t\t\t1.ADMIN\n\n\t\t\t\t2.EXIT\n\n\n\n");
	printf("\t\t\tEnter your choice : ");

	char ch2=0;
	ch2=fgetc(stdin);

	if (ch2==49)
	{
        gotoxy(0,0);
    	system("cls");
        return 0;
	}
	else if(ch2==50)
	{
        printf("\n\n\nEXITING.........");
        printf("\nPress any key to continue...\n");
        getch();
        exit(1);
	}
	else
	{
        gotoxy(0,0);
    	system("cls");
    	main();
        return 1;
	}


}


int login()
{			
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    printf("\n\nComplete the password setup to enter the management system\n");
    do
    {
    printf("\n\n\t\t  ::::::::::::::::::::::::::  LOGIN FORM  ::::::::::::::::::::::::::  \n");
    printf(" \n\t\t                       ENTER USERNAME:- ");
	scanf("%s", &uname);
	printf(" \n\t\t                       ENTER PASSWORD:- ");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;

	if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	    printf("\n ACCESS GRANTED... \n");
        printf("  \n\n       WELCOME TO EMPLOYEE RECORD MANAGEMENT SYSTEM !!!! LOGIN IS SUCCESSFUL");
	    printf("\n\n\n LOADING PLEASE WAIT...");
        for(i=0; i<5; i++)
        {
            printf(".");
            Sleep(500);
        }
	    printf("\n\n\n\t\t\t\tPress any key to continue...");
	    getch();
	    return 0;
	    break;
	}
	else
	{
		printf("\n\nSORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		getch();        //holds the screen
	}
}while(a<=2);

	if (a>2)
	{
		printf("\n\nSorry you have entered the wrong username and password for three times!!!");
		printf("\nPress any key to continue...");
		getch();
        return 1;
	}
		system("cls");
}


char ch2=0;
FILE *fp, *ft;       				// file pointers
struct emp e;       		 		// structure variable creation
long int recsize;    				// size of each record of employee
char empname[40],empid[10];     	// string to store name of the employee


struct emp					 		// structure that represent a employee
    {
        char name[40],id[10];       // name of employee
        int age; 					// age of employee
        char address[20];    		// address of employee
        float bs; 			 		// basic salary of employee

    };


void menu()				// Main function started
{
	char choice;
	int i=0;

	while(1)
    {

        system("cls"); 								// clear the console window

        printf(" \n  ::::::::::::::::::::::::::  |EMPLOYEES RECORD MANAGEMENT|  :::::::::::::::::::::::::: \n");

        gotoxy(30,05);								// move the cursor to postion 30, 10 from top-left corner
		printf("1> Add Employee's Records"); 		// option for add record
        gotoxy(30,07);
        printf("2> List Employee's Records"); 		// option for showing existing record
        gotoxy(30,9);
        printf("3> Modify Employee's Records"); 	// option for editing record
        gotoxy(30,11);
        printf("4> Delete Employee's Records"); 	// option for deleting record
        gotoxy(30,13);
        printf("5> Return to the main menu");		// exit from the program     
	    gotoxy(30,15);
        printf("Your Choice: ");					// enter the choice 1, 2, 3, 4, 5
        fflush(stdin); 								// flush the input buffer
        choice  = getche(); 						// get the input from keyboard

		switch(choice)

        {
        case '1': 		 	// if user press 1 then add funtion is called
            add();
            break;
        case '2':			// if user press 2 then display funtion is called
            display();
            break;
        case '3':  			// if user press 3 then modify funtion is called
            modify();
            break;
        case '4':			// if user press 4 then delete funtion is called
            deletee();
            break;
        case '5':
            printf("\n\n\n RETURNING TO MAIN MENU...");
        	for(i=0; i<5; i++)
        	{
            	printf(".");
            	Sleep(500);
        	}
        	printf("\n\n\n\t\t\t\tPress any key to continue...");
        	getch();
			fclose(fp); 	// close the file
			system("cls");
			admin();
        }
    }
}

int main()
{
	int i=0;
	if (admin()==0)
	{

    /*
	 open the file in binary read and write mode
     if the file EMP.DAT already exists then it open that file in read write mode
     if the file doesn't exit it simply create a new copy
    */
		if (login()==0)
		{

    		fp = fopen("EMP.DAT","rb+");
   			if(fp == NULL)
    		{
       			fp = fopen("EMP.DAT","wb+");
        		if(fp == NULL)
        		{
            		printf("Connot open file");
            		exit(1);
        		}
    		}
    		
   			recsize = sizeof(e);		 // sizeo of each record i.e. size of structure variable e
			menu();
		}
		else 
		{
            gotoxy(0,0);
    		system("cls");
			admin();					// Calling the menu function
		}
	}
		
}

void add()								// This function is used to add the details of the employee
{
    system("cls");
    fseek(fp,0,SEEK_END); 				// search the file and move cursor to end of the file
           							    // here 0 indicates moving 0 distance from the end of the file
	char another = 'y';
    while(another == 'y')  				// if user want to add another record
    {	
    	system("cls");
    	printf("\n\n\t\t\t\t\t*****************************************");
    	printf("\n");
    	printf("\n\t\t\t\t\t\tADDING EMPOLYEE'S DETAILS");
    	printf("\n");
    	printf("\n\t\t\t\t\t*****************************************");
        printf("\n\n\nEnter unique id: ");
        scanf("%s",e.id);
        printf("\nEnter name: ");
        scanf("%s",e.name);
        printf("\nEnter age: ");
        scanf("%d", &e.age);
        printf("\nEnter Address:");
        scanf("%s",e.address);
        printf("\nEnter basic salary: ");
        scanf("%f", &e.bs);
		fwrite(&e,recsize,1,fp); 					// write the record in the file
		printf("\n\n\nRecord added successfully\n");				
        printf("Add another record?? (y/n) ");
        printf("\nEnter your input: ");
        fflush(stdin);
        another = getche();
        printf("\n\n\n\t\t\t\tPress any key to continue...");
	    getch();
    }
}


void display()																			// This function is used to display all the details of the employee
{
    system("cls");
    printf("\n\n\t\t\t\t\t********************************************");
    printf("\n");
    printf("\n\t\t\t\t\t\tDISPLAYING EMPOLYEE'S DETAILS");
    printf("\n");
    printf("\n\t\t\t\t\t********************************************");
    rewind(fp); 																		// this moves file cursor to start of the file
    while(fread(&e,recsize,1,fp)==1) 									 				// read the file and fetch the record one record per fetch
    {
		printf("\n\n\n\nID          : %s",e.id);
		printf("\nNAME        : %s",e.name);
		printf("\nAGE         : %d",e.age);
		printf("\nADDRESS     : %s",e.address);
		printf("\nBASIC SALARY: %.2f",e.bs);
    }
    printf("\n\n\n\t\t\t\tPress any key to continue...");
    getch();
}

void modify()																// This function is used to modify the details of the employee
{
    system("cls");
    printf("\n\n\t\t\t\t\t********************************************");
    printf("\n");
    printf("\n\t\t\t\t\t\tMODIFYING EMPOLYEE'S DETAILS");
    printf("\n");
    printf("\n\t\t\t\t\t********************************************");
    char another = 'y';
    while(another == 'y')
    {
        printf("\n\nEnter the employee id to modify: ");
        scanf("%s", empid);
        rewind(fp);
        int flag=0;
        while(fread(&e,recsize,1,fp)==1)  									// fetch all record from file
        {
            if(strcmp(e.id,empid) == 0)  								    // if entered name matches with that in file
            {	
            	flag=1;
            	printf("\n\nRECORD FOUND\n");
                printf("\nEnter new name,age,address and basic salary: \n\n");
                scanf("%s%d%s%f",e.name,&e.age,&e.address,&e.bs);
                fseek(fp,-recsize,SEEK_CUR); 								// move the cursor 1 step back from current position
                fwrite(&e,recsize,1,fp);
				printf("\n\nRECORD MODIFIED SUCCESSFULLY\n");				// override the record
                break;
            }
            
        }
        if(flag==0)
        {
            printf("\n\nRECORD NOT FOUND");
		}
        printf("\n\nModify another record?? (y/n) ");
        printf("\nEnter your input: ");
        fflush(stdin);
        another = getche();
        printf("\n\n\n\t\t\t\tPress any key to continue...");
	    getch();
    }
}

void deletee()									//This function is used to delete the details of the employee
{
    system("cls");
    printf("\n\n\t\t\t\t\t********************************************");
    printf("\n");
    printf("\n\t\t\t\t\t\tDELETING EMPOLYEE'S DETAILS");
    printf("\n");
    printf("\n\t\t\t\t\t********************************************");
    char another = 'y';
    int flag=0;
    while(another == 'y')
    {	
    	system("cls");
        printf("\n\nEnter id of employee to delete: ");
        scanf("%s",empid);
       
        ft = fopen("Temp.dat","wb");  			// create a intermediate file for temporary storage
        rewind(fp); 							// move record to starting of file
        while(fread(&e,recsize,1,fp) == 1)      // read all records from file
        {
            if(strcmp(e.id,empid) != 0)         // if the entered record match
            {
				fwrite(&e,recsize,1,ft); 		// move all records except the one that is to be deleted to temp file
            }
            else
            {
            	flag=1;
			}
            
        }
        fclose(fp);
        fclose(ft);
        remove("EMP.DAT"); 						// remove the orginal file
        rename("Temp.dat","EMP.DAT"); 			// rename the temp file to original file name
        fp = fopen("EMP.DAT", "rb+");
        if(flag==1)
        {
			printf("\n\nRECORD FOUND");
			printf("\nRECORD DELETED SUCCESSFULLY\n");
		}
		else
		{
			printf("\n\nRECORD NOT FOUND\n");
		}
        printf("\n\nDelete another record?? (y/n) ");
        printf("\nEnter your input: ");
        fflush(stdin);
        another = getche();
        printf("\n\n\n\t\t\t\tPress any key to continue...");
	    getch();
    }
}
