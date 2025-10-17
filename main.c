/******************************************************
   CREATED BY    : Diego Lopez-Rodas
   CREATION DATE : 09/18/2025
   UPDATE DATE   : 10/17/2025
   PURPOSE       : 
 ******************************************************/

#include <stdio.h>
#include <time.h>
#include "Header/jsonFM_QuizApp.h"

void startProgramMessage();
void endProgramMessage(char *userFilenames[],int numOfExams);
void printTimeStamp();

int main(void) {

   startProgramMessage();
   
   // Intializing all structs
   struct examInfo exam;
   struct examInfo *examPtr = &exam;
   
   struct professorInfo prof;
   struct professorInfo *profPtr = &prof;
   
   struct questionInfo question;
   struct questionInfo *questionPtr = &question;
   
   // Intializing numOfExams to be used in for-loop
   int numOfExams = getNumberOfExams();
   
   // Intializing user filenames to be printed later
   char *userFilenames[numOfExams];

   // Intializing file pointers
   FILE *defaultTemplatePtr;
   FILE *questionTemplatePtr;
   FILE *userFilePtr;
   
   // Opening template files
   if ( (defaultTemplatePtr = fopen("Templates/defaultTemplateJF_QuizApp.json", "r")) == NULL ) {
      printf("\n[ERROR] : Issue occured opening 'defaultTemplateJF_QuizApp.json'\n");
      return 1; // Terminating program if problem opening file occurs
   }
   if ( (questionTemplatePtr = fopen("Templates/questionTemplateJF_QuizApp.json", "r")) == NULL ) {
      printf("\n[ERROR] : Issue occured opening 'questionTemplateJF_QuizApp.json'\n");
      return 1; // Terminating program if problem opening file occurs
   }

   for(int examID = 1; examID <= numOfExams; examID++) {

      // Opening user file
      if ( (userFilePtr = accessUserFile(userFilenames, examID)) == NULL ) {
         printf("\n[ERROR] : Issue occured opening your file\n");
      }

      // Obtaining user data for structs
      setExamInfo(examPtr, examID);
      setProfInfo(profPtr);

      int numOfQues = examPtr->numOfQuestions;

      // Writing user data into user's file
      writeExamInfo(userFilePtr, defaultTemplatePtr, examPtr);
      writeProfessorInfo(userFilePtr, defaultTemplatePtr, profPtr);
      writeAllQuestionInfo(userFilePtr, defaultTemplatePtr, questionTemplatePtr, numOfQues);

      // Rewinding both template files
      rewind(defaultTemplatePtr);
      rewind(questionTemplatePtr);
   }
   
   endProgramMessage(userFilenames, numOfExams);

   // Closing ALL file pointers
   fclose(defaultTemplatePtr);
   fclose(questionTemplatePtr);
   fclose(userFilePtr);

   return 0;
}

void startProgramMessage() {
   printf("\n+----------------------------------------------------------+");
   printf("\n|                   EXAM JSON FILE MAKER                   |");
   printf("\n+----------------------------------------------------------+");
   printTimeStamp();
   printf("\n+----------------------------------------------------------+");
   printf("\n|       This program will assist you in making .json       |");
   printf("\n|       file following a template, ensuring ALL files      |");
   printf("\n|       follow the same structure. This program will       |");
   printf("\n|       ask you to provide a file name, WARNING, if        |");
   printf("\n|       you use the name of an EXISTING file, then         |");
   printf("\n|       ALL its DATA will be OVERWRITTEN.                  |");
   printf("\n+----------------------------------------------------------+");
}

void endProgramMessage(char *userFilenames[], int numOfExams) {
   printf("\n+----------------------------------------------------------+");
   printf("\n|                      END OF PROGRAM                      |");
   printf("\n+----------------------------------------------------------+");
   printTimeStamp();
   printf("\n+----------------------------------------------------------+");
   for(int index = 1; index <= numOfExams; index++) {
      printf("\n+----------------------------------------------------------+");
      printf("\n  %d - %s  ", index, userFilenames[index]);
   }
   printf("\n+----------------------------------------------------------+");
}

void printTimeStamp() {
   
   time_t timeStamp = time(NULL);
   struct tm *tS    = localtime(&timeStamp);

   int month = tS->tm_mon  + 1;
   int day   = tS->tm_mday;
   int year  = tS->tm_year + 1900;
   int hour  = tS->tm_hour;
   int min   = tS->tm_min;
   int sec   = tS->tm_sec;
   
   printf("\n|  Date : %02d/%02d/%d                      Time : %02d:%02d:%02d  |", month, day, year, hour, min, sec);
}