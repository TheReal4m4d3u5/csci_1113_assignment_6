/* 
                                    Avery Jacobson
                                    csci 1113
                                    assignment 6 3.6
                                    James Polzin

Assignment 6:                Given: 02/26/14     Due: 03/06/14
------------                                  Points: 10
Purpose: - Functions and command-line arguments

  Description:
  -----------
  Modify your assignment #5 program so that you write and use two 
  functions in addition to main( ). One function will do your 
  computations the other will do the printing.
  
  Also, the file you are to process will be passed as a command-
  line argument to your program. This allows your program to 
  process any file containing data that fits the pattern described
  in the textbook, regardless of the actual name of the file.

Notes:
-----
  - Do both #3.6 and #3.7
  - All assignment #5 features and requirements still apply
  - With the functions, main( ) should become simpler/cleaner
    since the print and computation code will be moved out of 
    main into separate functions.
   
  - Make incremental changes:
  
    Add the functions:
    - Add them one at a time
    - Start with the simplest and then move to ones that
      are more complicated
      
    Add the command-line argument for the file name:
    - Get everything else working in your program,
      then try to change the file name to the first (and
      only) command-line argument
    
  - Submit 3.6 as #6-6 and 3.7 as #6-7; since they are for 
    Assignment #6.  You DO NEED to do both!

*/

#include <stdio.h>

void printFunction(FILE *myfile, int, int, int, int, float);
void calcFunction(FILE *myfile, char *argv[ ]);

int main(int argc, char *argv[ ])
{

    FILE *myfile; 
    myfile = fopen("DISTANCE.OUT","w"); 
    
     
    fprintf(myfile,"Car under constant accleceration\n\nInital\nvelocity   time    acceleration     distance\n_________  _____   _____________    ________\n");  
    
    calcFunction(myfile, argv);      // go over passing a pointer variable to a function
  
    fclose(myfile);  

 return 0;

}


void calcFunction(FILE *myfile, char *argv[ ])
{
    FILE *fp;  
    fp = fopen(argv[1], "r");
    
    double dist;
    int   input, velocity, time, accel, n;
         
    for(n=0; (fscanf(fp,"%i",&input) == 1); n++)
    {  
       switch(n)
       {
        case 0:
             velocity = input;
             break;
        case 1:
             time = input;
             break;
        case 7:
             velocity = input;
             break;
        case 8:
             time = input;
             break;
        case 9:
             fprintf(myfile,"\n"); 
             break;   
        }

	    if( ((n >=2) && (n<7)) || ((n >=9) && (n <14)) )         
		    accel = input;
        
	dist =  ((double)velocity*(double)time) +  (.5 * (double)accel * pow((double)time,2));
        printFunction(myfile, n, velocity, time, accel, dist);                                                            
    }
    
    fclose(fp); 
}

void printFunction(FILE *myfile, int n, int velocity, int time, int accel, float dist)
{
     if((n ==2) || (n ==9))                                
       fprintf(myfile,"\n%5i m/s %4i s %9i m/s^2 %9.2lf m\n", velocity, time, accel, dist);
       
       	
     if( ((n > 2) && (n < 7)) || ((n>9) && (n <14)) )                                
       fprintf(myfile,"\n %25i m/s^2 %9.2lf m\n", accel, dist);   
}



