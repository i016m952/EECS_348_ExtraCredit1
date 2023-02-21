#include <stdio.h>
#include <stdlib.h>

int main()
{
     FILE *inputMatchingDataFile;
     inputMatchingDataFile = fopen("matching-data.txt", "r");
     if (inputMatchingDataFile == NULL) {
          printf("ERROR: Failure to open input file named 'matching-data.txt'.\n");
          return 1;
     }

     char inputFileSize[255];
     int inputFileMatchingData[10][5];
     for(int i = 0; i < 10 && EOF != fscanf(inputMatchingDataFile, "%[^\n]\n", inputFileSize); i++) {
          for (int j = 0; j < 5; j++) {
               inputFileMatchingData[i][j] = (((int)(inputFileSize[j * 2])) - 48);
          }
     }
     fclose(inputMatchingDataFile);


     int programmer[5][5] = {
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0}
     };

     int department[5][5] = {
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0}
     };

     printf("Programmers and their prefernces\n");
     for (i = 5; i < 10; i++) {
          for (j = 0; j < 5; j++) {
               programmer[i - 5][j] = inputFileMatchingData[i][j];
               if (i < 1) {
                    printf("Programmer #%d   ", j+1);
               } else {
                    printf("       %d       ", programmer[i-1][j]);
               }
          }
          printf("\n");
     }

     printf("Departments and their prefernces\n");
     for (int i = 0; i < 5; i++) {
          for (j = 0; j < 5; j++) {
               department[i][j] = inputFileMatchingData[i][j];
               if (i < 1) {
                    printf("Department #%d   ", j+1);
               } else {
                    printf("       %d       ", department[i-1][j]);
               }
          }
          printf("\n");
     }

     int conflictingIndex = 0;
     int conflictingArrayIndex = 0;
     int conflictIndex[25];
     int conflictIndexArray[5][5];
     for (int i = 1; i <= 5; i++) {
          for (int j = 0; j < 5; j++) {
               for (int k = 0; k < 5; k++) {
                    if (k == programmer[j][i]) { 
                         val_index[index] = j;
                         conflictingIndex++;
                    }
                    
               }
               conflictIndexArray[i][j] = conflictIndexArray[j + conflictingArrayIndex];          
          }
     }
  

}