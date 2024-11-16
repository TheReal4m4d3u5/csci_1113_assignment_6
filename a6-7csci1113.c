
/* 
                                    Avery Jacobson
                                    csci 1113
                                    assignment 6 3.7
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
//void printFunction(FILE *fptr, int,int,int,int);
void calcFunction(FILE *fptr, char *argv[]);
void printFunction(FILE *fptr,int,int,int,int); 

int main(int argc, char *argv[ ])
{
   FILE *myfile; 
   myfile = fopen("TEMPER.OUT","w"); 
 
   fprintf(myfile,"Case P(atm)    V(1)     T(K)\n");  
   calcFunction(myfile,argv);

   fclose(myfile);  

 return 0;

}



void calcFunction(FILE *myfile, char *argv[ ])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    
    int   input1, input2, t1,t2,p1,p2,v1,v2, n;

    p1 = 5;
    v1 = 30;
    t1 = 273;
       
    for(n=0; fscanf(fp,"%i %i",&input1,&input2) == 2; n++)
    {  

             
		if(n == 0)
		{
			p2 = input1;
			v2 = input2;
        }


		if(n == 1)
		{
			p2 = input1;
			v2 = input2;
        }
		
        if(n == 2)
        {
			p2 = input1;
			v2 = input2;
        }
        
		if(n == 3)
		{
			p2 = input1;
			v2 = input2;
        }
	
		if(n == 4)
		{
			p2 = input1;
			v2 = input2;
        }

		t2 = (p2*v2*t1)/(p1*v1); 
   
   
   	    printFunction(myfile, n, p2,v2, t2); 
     }

    fclose(fp); 
   
}


void printFunction(FILE *fptr,int n,int p2,int v2,int t2)
{
    	fprintf(fptr,"%i       %i      %i       %i\n", n+1, p2, v2, t2); 

}


