#include <stdio.h>
#include <stdlib.h>

#define NUM_ROW 5
#define NUM_COL 5

int main()
{
     // create input file check if able to open
     FILE *inputMatchingDataFile;
     inputMatchingDataFile = fopen("matching-data.txt", "r");
     if (inputMatchingDataFile == NULL) {
          printf("ERROR: Failure to open input file named 'matching-data.txt'.\n");
          return 1;
     }

     // scan in input file into array
     char inputFileSize[255];
     int inputFileMatchingData[NUM_ROW * 2][NUM_COL];
     for(int i = 0; i < (NUM_ROW * 2) && EOF != fscanf(inputMatchingDataFile, "%[^\n]\n", inputFileSize); i++) {
          for (int j = 0; j < NUM_ROW; j++) {
               inputFileMatchingData[i][j] = (((int)(inputFileSize[j * 2])) - 48);
          }
     }
     fclose(inputMatchingDataFile);
     
     // create 2D arrays for the programmers prefernces and the departments prefernces
     int programmerPrefernces[NUM_ROW][NUM_COL] = {
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0}
     };
     int departmentPrefernces[NUM_ROW][NUM_COL] = {
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0}
     };
     
     // print out programmers data and allocate data to programmers prefernce 2D array
     printf("Programmers and their prefernces\nProgrammer #1  Programmer #2  Programmer #3  Programmer #4  Programmer #5  \n");
     for (int i = 5; i < (NUM_ROW * 2); i++) {
          for (int j = 0; j < NUM_COL; j++) {
               programmerPrefernces[i - NUM_ROW][j] = inputFileMatchingData[i][j];
               printf("       %d       ", programmerPrefernces[i - NUM_ROW][j]);
          }
          printf("\n");
     }

     // print out departments data and allocate data to departments prefernce 2D array
     printf("Departments and their prefernces\nDepartment #1  Department #2  Department #3  Department #4  Department #5  \n");
     for (int i = 0; i < NUM_ROW; i++) {
          for (int j = 0; j < NUM_COL; j++) {
               departmentPrefernces[i][j] = inputFileMatchingData[i][j];
               printf("       %d       ",departmentPrefernces[i][j]);  
          }
          printf("\n");
     }
     
     // check for conflicts between departments, and resolves conflict through programmers prefernce
     int conflictIndex = 0;
     int conflictArray[NUM_ROW * NUM_COL];
     for (int i = 1; i <= NUM_ROW; i++) {
          for (int j = 0; j < NUM_COL; j++) {
               int k = 0;
               while (k < NUM_ROW) {
                    if (i == programmerPrefernces[k][j]) {
                         conflictArray[conflictIndex] = k;
                         conflictIndex++;
                    }
                    k++;
               }
          }
     }
     
     // create 2D array to establish conflicts within departments
     conflictIndex = 0;
     int conflictArray2D[NUM_ROW][NUM_COL];
     for (int i = 0; i < NUM_ROW; i++) {
          for (int j = 0; j < NUM_COL; j++) {
               conflictArray2D[i][j] = conflictArray[j + conflictIndex];
          }
          conflictIndex += NUM_ROW;
     }
     
     // checks departments prefernces by checking smallest index
     int smallestIndex, assingedProgrammer;
     int i = 0;
     while (i < NUM_ROW) {
          smallestIndex = conflictArray2D[departmentPrefernces[i][0] - 1][0];
          // checks columns of smallest index
          int j = 0;
          while (j < NUM_COL) {
               if (conflictArray2D[i][j] < smallestIndex) { 
                    smallestIndex = conflictArray2D[i][j];
               }
               j++; 
          }

          // checks rows of smallest index
          int k = 0;
          while (k < NUM_ROW) {
               if (conflictArray2D[i][k] == smallestIndex) {
                    assingedProgrammer = k;
                    printf("Department #%d will get Programmer #%d\n", i + 1, k + 1);
                    break;
               }
               k++;
          }

          // claims whether programmer has been assigned to a department or not
          int l = 0;
          while (l < NUM_ROW) { 
               conflictArray2D[l][assingedProgrammer] = 100;
               l++;
          }
          i++;
     }
}
