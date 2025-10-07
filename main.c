/******************************************************
   CREATED BY    : Diego Lopez-Rodas
   CREATION DATE : 09/18/2025
   UPDATE DATE   : 10/07/2025
   PURPOSE       : 
 ******************************************************/

#include <stdio.h>
#include <string.h>

enum gradeLevel {
  ELEMENTARY,
  MIDDLE,
  HIGH,
  COLLEGE
};

enum subjectMatter {
  SOCIALSCI,
  SCIENCE,
  MATH,
  LITERATURE,
  LANGUAGE
};

struct professorInfo {
  int  professorID;
  char professorEmail[62];
  char professorFirstName[50];
  char professorLastName[50];
};

struct examInfo {
  int                examID; 
  int                numOfQuestions;
  int                timeLimit;
  char               examDescrip[250];
  enum gradeLevel    grade;
  enum subjectMatter subject;
};

char *getGradeLevelName(int gradeLevelValue){

   switch (gradeLevelValue){
      case 0:
         return "ELEMENTARY";
      case 1:
         return "MIDDLE SCHOOL";
      case 2:
         return "HIGH SCHOOL";
      case 3:
         return "COLLEGE";
   }

   return "NO VALUE FOUND";
}

char *getSubjectMatterName(int subjectMatterValue){

   switch (subjectMatterValue){
      case 0:
         return "SOCIAL SCIENCE";
      case 1:
         return "SCIENCE";
      case 2:
         return "MATHEMATICS";
      case 3:
         return "LITERATURE";
      case 4:
         return "LANGUAGE";
   }

   return "NO VALUE FOUND";
}

void writeProfessorInfo(FILE *userFile, FILE *template, struct professorInfo *professor) {
   char line[301];

   while( fgets(line, sizeof(line), template) ) {
      if( strstr(line, "<PROFESSOR_ID>") ) {
         fprintf(userFile, "        \"ProfessorID\"          : %d,\n", professor->professorID);
      }
      else if( strstr(line, "<PROFESSOR_EMAIL>") ) {
         fprintf(userFile, "        \"ProfessorEmail\"       : \"%s\",\n", professor->professorEmail);
      }
      else if( strstr(line, "<PROFESSOR_FIRST_NAME>") ) {
         fprintf(userFile, "        \"ProfessorFirstName\"   : \"%s\",\n", professor->professorFirstName);
      }
      else if( strstr(line, "<PROFESSOR_LAST_NAME>") ) {
         fprintf(userFile, "        \"ProfessorLastName\"    : \"%s\",\n", professor->professorLastName);
      }
      else {
         fputs(line, userFile);
      }
   }
}

void writeExamInfo(FILE *userFile, FILE *template, struct examInfo *exam) {
   char line[301];

   while( fgets(line, sizeof(line), template) ) {
      if( strstr(line, "<EXAM_ID>") ) {
         fprintf(userFile, "        \"ExamID\"          : %d,\n", exam->examID);
      }
      else if( strstr(line, "<NUM_OF_QUESTIONS>") ) {
         fprintf(userFile, "        \"NumOfQuestions\"  : %d,\n", exam->numOfQuestions);
      }
      else if( strstr(line, "<TIME_LIMIT>") ) {
         fprintf(userFile, "        \"TimeLimit\"       : %d,\n", exam->timeLimit);
      }
      else if( strstr(line, "<EXAM_DESCRIPTION>") ) {
         fprintf(userFile, "        \"ExamDescription\" : \"%s\",\n", exam->examDescrip);
      }
      else if( strstr(line, "<GRADE_LEVEL>") ) {
         char *gradeLevelName = getGradeLevelName(exam->grade);
         fprintf(userFile, "        \"GradeLevel\"      : \"%s\",\n", gradeLevelName);
      }
      else if( strstr(line, "<SUBJECT_MATTER>") ) {
         char *subjectMatterName = getSubjectMatterName(exam->subject);
         fprintf(userFile, "        \"SubjectMatter\"   : \"%s\"\n", subjectMatterName);
      }
      else if( strstr(line, "\"ProfessorInfo\":{") ) {
         fputs(line, userFile);
         break;
      }
      else {
         fputs(line, userFile);
      }
   }
}

FILE *accessUserFile(void) {
   char userFile[56];
   printf("Enter your file's name (55 characters max):\n");
   scanf("%55s", userFile);
   
   FILE *filePointer = fopen(userFile, "w");
   return filePointer;
}

int main(void) {

   struct professorInfo prof = {
      1,
      "example@prof.com",
      "Eddie",
      "Brock"
   };

   struct examInfo exam = {
      12,
      4,
      40,
      "This is my exam, yup.",
      HIGH,
      LANGUAGE
   };

   struct professorInfo *profPtr = &prof;
   struct examInfo *examPtr = &exam;

   FILE *defaultJFptr;
   defaultJFptr = fopen("defaultJF_QuizApp.json", "r");
   
   FILE *userFileptr = accessUserFile();

   char fileContent[100];

   writeExamInfo(userFileptr, defaultJFptr, examPtr);
   writeProfessorInfo(userFileptr, defaultJFptr, profPtr);

   fclose(defaultJFptr);
   fclose(userFileptr);

   return 0;
}