#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
    char choice;
    char record, date[11], time[6], steps[10]; 
    int intsteps, line_count=0, i;
    int fewest_steps, largest_steps;
    int fewest_steps_index, largest_steps_index;
    int total_steps;
    float mean_steps;

    char line[100];
    char filename[100];
    char buffer[buffer_size];

    FITNESS_DATA fitness_data[999];

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
        while (getchar() != '\n'); //gets rid of the new line character
}

//function for opening file, reading through creating array of structs
int open_file(char *filename , char *mode) {
    FILE *file= fopen(filename, mode);   //open file in read mode and check it isn't empty
      if (file ==NULL) {
        perror("Error: Could not find or open the file\n");  //if file does not exist
        return 1;
        //exit;
         }
        else 
            {printf("File successfully loaded.\n");
            
        }; //correct file opened

      //create struct array 

    while (fgets(buffer, buffer_size, file)!= NULL) {   //while the line is not empty

        tokeniseRecord(buffer, ",", date, time, steps);    //splitting the line into date, time, steps
        strcpy(fitness_data[i].date, date);                //assigning date, time and steps to data struct 
        strcpy(fitness_data[i].time, time);
        strcpy(fitness_data[i].steps, steps);
        i++;                                               //does this for every i; every line in the file
         }
    fclose(file);
return 0;
 
}

//function for line count
int total_records(char *filename , char *mode) {
    FILE *file= fopen(filename, mode);
    line_count=0;

    if (file ==NULL) {
         perror("Error: Could not find or open the file\n");
             return 1;
         }
      //open file in read mode and check it isn't empty
    while (fgets(buffer, buffer_size, file)!= NULL) {   //while the line is not empty
        line_count++;
    }
    printf("Total records: %d\n", line_count);}
// Complete the main function
    
//test function
void print_records() {
        for (int i =0; i <3; i++) {                            //prints out date, time and steps of first 3 records.
            printf("%s/%s/%d\n", fitness_data[i].date,
                         fitness_data[i].time,
                         atoi(fitness_data[i].steps));
                            }

}

void find_fewest_steps() {  //find fewest steps
    fewest_steps= atoi(fitness_data[0].steps);
    fewest_steps_index = 0;
    for( int i=0; i < line_count; i++) {
        if (atoi(fitness_data[i].steps) < fewest_steps) {
            fewest_steps = atoi(fitness_data[i].steps);
            fewest_steps_index = i;
        }
    }
    //printf("%d, %d\n", fewest_steps, fewest_steps_index);
    printf("Fewest steps: %s %s\n", fitness_data[fewest_steps_index].date,
                                    fitness_data[fewest_steps_index].time);
    // for (int i=0; i <line_count; i++) {
    //     printf("%d\n", atoi(fitness_data[i].steps));
    // }
}

void find_largest_steps() { //finds date and time of largest time
    largest_steps= atoi(fitness_data[0].steps);
    largest_steps_index = 0;
    for( int i=0; i < line_count; i++) {
        if (atoi(fitness_data[i].steps) > largest_steps) {
            largest_steps = atoi(fitness_data[i].steps);
            largest_steps_index = i;
        }
    }
    //printf("%d, %d\n", largest_steps, largest_steps_index);
    printf("Largest steps: %s %s\n", fitness_data[largest_steps_index].date,
                                    fitness_data[largest_steps_index].time);
    // for (int i=0; i <line_count; i++) {
    //     printf("%d\n", atoi(fitness_data[i].steps));
    // }
}

void find_mean_steps() {
    total_steps=0;
    for  (int i=0; i < line_count; i++){
        total_steps= total_steps+ atoi(fitness_data[i].steps);
    }
    //printf("%d\n", total_steps);
    mean_steps= total_steps/(float)line_count;
    //mean_steps= round(mean_steps);
    printf("Mean step count: %.0f\n", mean_steps);
}


int longest_period_count, period_count;
int start_index, end_index, j;

void longest_period() {
    period_count=0;
    longest_period_count =0;

    for (i=0; i< line_count; i++) {
        if (atoi(fitness_data[i].steps) >500) {
            period_count++;
            start_index=i;
        
        }
        else {
            //end_index=i;
            if (period_count> longest_period_count) {
                longest_period_count = period_count;
            }
            else {
                longest_period_count= longest_period_count;
            }
                period_count = 0;
            }
        
        }
    
    printf("%d, %d, %d\n", longest_period_count, start_index, end_index);
}

int main() {

while (2)
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
            //return open_file(filename, "r");
            break;

        case 'b':
        case 'B':
            //printf("You have chosen choice B\n");
            //open_file(filename, "r");
            total_records(filename, "r");
            break;

        case 'C':
        case 'c':
            //printf("You have chosen choice C\n");
            //print_records();
            find_fewest_steps();
            break;

        case 'D': 
        case 'd':
            //printf("You have chosen choice D\n");
            find_largest_steps();
            break;

        case 'E':   
        case 'e':
            //printf("You have chosen choice E\n");
            find_mean_steps();
            break;

        case 'F': 
        case 'f':
            printf("You have chosen choice F\n");
            longest_period();
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









