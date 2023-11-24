#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
    char choice;
    char record, date[11], time[6], steps[10]; 
    int intsteps, line_count=0, i;

    char line[100];
    char filename[100];
    char buffer[buffer_size];

    FITNESS_DATA fitness_data[9999];

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



//function to enter filename
void input_filename() {
        printf("Input filename: ");
        //fgets(line, buffer_size, stdin);
        //sscanf(line, " %s ", filename);
        scanf(" %s", filename);
        while (getchar() != '\n');

    
}

//function for opening file, reading through 
//creating array of structs
FILE *open_file(char *filename , char *mode) {
    FILE *file= fopen(filename, mode);   //open file in read mode and check it isn't empty
      if (file ==NULL) {
         perror("Error opening file\n");
             return 1;
         }
        else 
            (printf("File successfully loaded.\n"));

      //create struct array 

    while (fgets(buffer, buffer_size, file)!= NULL) {   //while the line is not empty

        // tokeniseRecord(buffer, ",", date, time, steps);    //splitting the line into date, time, steps
        // strcpy(fitness_data[i].date, date);                //assigning date, time and steps to data struct 
        // strcpy(fitness_data[i].time, time);
        // strcpy(fitness_data[i].steps, steps);
        // i++;                                               //does this for every i; every line in the file
         }

    //return 0;
}

//function for line count
FILE *total_records(char *filename , char *mode) {
    FILE *file= fopen(filename, mode);
    line_count=0;

    if (file ==NULL) {
         perror("Error: could not open file\n");
             return 0;
         }
      //open file in read mode and check it isn't empty
    while (fgets(buffer, buffer_size, file)!= NULL) {   //while the line is not empty
        line_count++;
    }
    printf("Total records: %d\n", line_count);
}
// Complete the main function
    




int main() {

while (1)
{       
        printf("\n");
        printf("Menu options:\n");
        printf("A: Specify the filename to be imported\n");                      
        printf("B: Display the total number of records in the file\n");                   
        printf("C: Find the date and time of the timeslot with the fewest steps \n");                    
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");                    
        printf("E: Find the mean step count of all the records in the file \n");       
        printf("F: Find the longest continuous period where the step count is above 500 steps \n");        
        printf("Q: Quit \n");
        printf("Enter choice: ");
        //scanf("%s", &choice);
        choice = getchar(); //prevents from printing again unnecessarily
        while (getchar() != '\n');

    switch (choice){
        case 'a':
        case 'A':    //add misspell check
            input_filename();
            open_file(filename, "r");   //program isnt exiting when wrong filename isnt entered
    
            break;

        case 'b':
        case 'B':
            //printf("You have chosen choice B\n");
            //open_file(filename, "r");
            total_records(filename, "r");
            break;

        case 'C':
        case 'c':
            printf("You have chosen choice C\n");

            break;

        case 'D': 
        case 'd':
            printf("You have chosen choice D\n");
            break;

        case 'E':   
        case 'e':
            printf("You have chosen choice E\n");
            break;

        case 'F': 
        case 'f':
            printf("You have chosen choice F\n");
            break;

        case 'Q':
        case 'q':
            printf("You have chosen choice Q. Exiting program\n");
            return 0;
            break;
            
        default:
            printf("Invalid choice. Try again.\n");
            break;
    }
}
}









