#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }




// Complete the main function
    
int main() {
    char choice, filename;
    char record, date[11], time[6], steps[10]; 
    int intsteps, line_count=0, i;
    //int buffer_size = 256;    //creating the size of the buffer
    //char buffer[buffer_size];   //creating buffer and its size



        printf("Menu options:\n");
        printf("A: Specify the filename to be imported\n");                      
        printf("B: Display the total number of records in the file\n");                   
        printf("C: Find the date and time of the timeslot with the fewest steps \n");                    
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");                    
        printf("E: Find the mean step count of all the records in the file \n");       
        printf("F: Find the longest continuous period where the step count is above 500 steps \n");        
        printf("Q: Quit \n");

        printf("Enter choice: ");
        scanf("%c", &choice);
        


    switch (choice){
        case 'A':    //add misspell check
            input_filename();
            //FILE *file = fopen(filename,"r");
            //open_file(filename, "r");         
            break;

        case 'B':    
        printf("You have chosen choice B\n");
            break;

        case 'C':
            printf("You have chosen choice C\n");
            break;

        case 'D':  
            printf("You have chosen choice D\n");
            break;

        case 'E':   
            printf("You have chosen choice E\n");
            break;

        case 'F': 
            printf("You have chosen choice F");
            break;

        case 'Q': 
            printf("You have chosen choice Q\n");
            break;
            
        default: printf ("Invalid choice. Try again.\n");
    }
}
   










