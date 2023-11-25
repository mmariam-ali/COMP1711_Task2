
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define buffer_size 256

//Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	char steps[10];
} FITNESS_DATA;

//Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);




/**
* @brief Opens the file in the correct mode
*
* @param filename the name of the file to open
* @param mode the mode (r/w/a/r+/w+/a+)
* @return FILE* The file object to store the opened file in.
*/  


//setting filename


//char *input_filename() {
        
        //scanf(" %s ", &filename);
        //printf("%s", filename);

        // fgets(line, buffer_size, stdin);
        // sscanf(line, " %s ", filename);
        
        //printf("helloooo");
        //printf("%s", filename);

    //openfile(filename, "r");


//opening file

//int line_count=0;

// FILE *open_file(char *filename [], char *mode[]) {
//     FILE *file= fopen(filename, mode);   //open file in read mode and check it isn't empty
//       if (file ==NULL) {
//          perror("Error opening file: file is empty. \n");
//              return 1;
//          }
//     return file; 
// }
/**
 * @brief Reads the data from the input file into an array of structs
 *
 * @param inputFile the open file object
 * @param dataArray the array of readings
 * @return int Returns the number of readings from the file
 */

//  void *read_file(FILE *inputFile, FITNESS_DATA, char *mode) {
//     char line_count=0;
//     int buffer_size = 256;
//     char buffer[buffer_size]=
//      FITNESS_DATA fitness_data[9999];   //create struct array 

//          while (fgets(buffer, buffer_size, file)!= NULL) {   //while the line is not empty
//              line_count++;   //counting the number of lines in the file

//              tokeniseRecord(buffer, ",", date, time, steps);    //splitting the line into date, time, steps
//              strcpy(fitness_data[i].date, date);                //assigning date, time and steps to data struct 
//              strcpy(fitness_data[i].time, time);
//              strcpy(fitness_data[i].steps, steps);
//              i++;                                               //does this for every i; every line in the file
//          }
//  }

#endif // FITNESS_DATA_STRUCT_H
