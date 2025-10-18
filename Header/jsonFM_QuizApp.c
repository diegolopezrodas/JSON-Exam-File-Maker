/******************************************************
   CREATED BY    : Diego Lopez-Rodas
   CREATION DATE : 09/28/2025
   UPDATE DATE   : 10/17/2025
   PURPOSE       : 
 ******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jsonFM_QuizApp.h"

// Access user exam file
FILE *accessUserFile(char *userFilenames[], int examID) {
    char userFile[56];
    printf("\nEnter your file's name (55 characters max):\n");
    scanf("%55s", userFile);
    
    // Allocating memory to store filename
    userFilenames[examID] = malloc(strlen(userFile) + 1);
    
    // Copying filename to memory
    strcpy(userFilenames[examID], userFile);

    FILE *filePtr = fopen(userFile, "w");
    return filePtr;
}

// Obtaining number of exams
int getNumberOfExams() {
   int numOfExams;
   int results;
   int flag = 0;

   do {
      if (flag > 0) {
        printf("\n[WARNING] : PLEASE ENTER A NUMBER");
      }

      printf("\nEnter the number of exams you want to make:\n");
      results = scanf("%d", &numOfExams);

      while(getchar() != '\n');
      flag++;
   } while(results != 1 || numOfExams < 0);

   return numOfExams;
}

// Formatting printing in terminal
void printGradeLevelOptions() {
    printf("\t+--------------------+\n");
    printf("\t| ELEMENTARY    -  0 |\n");
    printf("\t| MIDDLE SCHOOL -  1 |\n");
    printf("\t| HIGH SCHOOL   -  2 |\n");
    printf("\t| COLLEGE       -  3 |\n");
    printf("\t+--------------------+\n");
}

void printSubjectMatterOptions() {
    printf("\t+---------------------+\n");
    printf("\t| Social Science -  0 |\n");
    printf("\t| Science        -  1 |\n");
    printf("\t| Math           -  2 |\n");
    printf("\t| Literature     -  3 |\n");
    printf("\t| Language       -  4 |\n");
    printf("\t+---------------------+\n");
}

void printTypeOfQuestionOptions() {
    printf("\t+-------------------------------+\n");
    printf("\t| MULTIPLE CHOICE QUESTION -  0 |\n");
    printf("\t| TRUE OR FALSE            -  1 |\n");
    printf("\t| FILL-IN-BLANK            -  2 |\n");
    printf("\t| SHORT RESPONSE           -  3 |\n");
    printf("\t| MATCHING                 -  4 |\n");
    printf("\t| ESSAY RESPONSE           -  5 |\n");
    printf("\t+-------------------------------+\n");
}

void printSectionBorder() {
    printf("\n=======================================================\n");
}

void printFieldBorder() {
    printf("\n*******************************************************\n");
}

// Obtaining the name for associated enum value
char *getGradeLevelName(int gradeLevelValue){

   switch (gradeLevelValue) {
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

   switch (subjectMatterValue) {
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

char *getTypeOfQuestionName(int typeOfQuesValue) {

    switch (typeOfQuesValue) {
      case 0:
         return "MULTIPLE CHOICE QUESTION";
      case 1:
         return "TRUE OR FALSE";
      case 2:
         return "FILL-IN-THE-BLANK";
      case 3:
         return "SHORT RESPONSE";
      case 4:
         return "MATCHING";
      case 5:
         return "ESSAY RESPONSE";
    }
    return "NO VALUE FOUND";
}

// Collect user data to be called in setExamInfo()
int getNumberOfQuestions() {

    printFieldBorder();

    int numOfQues;
    int results;
    int flag = 0;

    do {
        if (flag > 0) {
            printf("\n[WARNING] : PLEASE ENTER NUMBER OF QUESTIONS AS POSITVE NUMBER\n");
        }
        
        printf("\nEnter the number of questions on this exam:\n");
        results = scanf("%d", &numOfQues);
        
        while (getchar() != '\n');
        flag++;
    } while(results != 1 || numOfQues < 0);
    
    return numOfQues;
}

int getTimeLimit() {
    printFieldBorder();

    int timeLimit;
    int results;
    int flag = 0;

    do {
        if(flag > 0) {
            printf("\n[WARNING] : PLEASE ENTER TIME AS POSITVE WHOLE NUMBER\n");
        }

        printf("\nEnter the time limit of the exam in minutes:\n");
        results = scanf("%d", &timeLimit);
        
        while (getchar() != '\n');
        flag++;
    } while(results != 1 || timeLimit < 0);
    
    return timeLimit;
}

enum gradeLevel getGradeLevel() {
    printFieldBorder();

    int grade;
    int results;
    int flag = 0;

    do {
        if(flag > 0) {
            printf("\n[WARNING] : PLEASE SELECT NUMBER FROM GIVEN OPTIONS\n");
        }

        printf("\nEnter the number corresponding to the grade level:\n");
        printGradeLevelOptions();
        results = scanf("%d", &grade);
        
        while(getchar() != '\n');
        flag++;
    } while(results != 1 || grade < 0 || grade > 3);

    return (enum gradeLevel) grade;
}

enum subjectMatter getSubjectMatter() {
    printFieldBorder();

    int subject;
    int results;
    int flag = 0;

    do {
        if(flag > 0) {
            printf("\n[WARNING] : PLEASE SELECT NUMBER FROM GIVEN OPTIONS\n");
        }
        
        printf("\nEnter the number corresponding to the subject matter:\n");
        printSubjectMatterOptions();
        results = scanf("%d", &subject);
        
        while (getchar() != '\n');
        flag++;
    } while(results != 1 || subject < 0 || subject > 4);

    return (enum subjectMatter) subject;
}

void getExamDescription(char* buffer, size_t size) {
    printFieldBorder();

    printf("\nEnter exam description (250 characters max):\n");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

// Collect user data to be called in setProfInfo()
int getProfessorID() {
    printFieldBorder();

    int profID;
    int result;
    int flag = 0;

    do {
        if(flag > 0) {
            printf("\n[WARNING] : PLEASE ENTER PROPER ID. PROFESSOR IDS ARE POSITIVE, NON-DECIMAL NUMBERS\n");
        }
        
        printf("\nEnter the professor ID:\n");
        result = scanf("%d", &profID);
        
        while (getchar() != '\n');
        flag++;
    } while(result != 1 || profID < 0);

    return profID;
}

void getProfessorEmail(char* buffer, size_t size) {
    printFieldBorder();

    printf("\nEnter the professor email (62 characters max):\n");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void getProfessorFirstName(char* buffer, size_t size) {
    printFieldBorder();

    printf("\nEnter the professor's first name (50 characters max):\n");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void getProfessorLastName(char* buffer, size_t size) {
    printFieldBorder();

    printf("\nEnter the professor's last name (50 characters max):\n");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

// Collect user data to be called in setQuestionInfo()
enum typeOfQuestion getTypeOfQuestion() {
    printFieldBorder();

    int questionType;
    int results;
    int flag = 0;

    do {
        if(flag > 0) {
            printf("\n[WARNING] : PLEASE SELECT NUMBER FROM GIVEN OPTIONS\n");
        }

        printf("\nEnter the number corresponding to the type of question:\n");
        printTypeOfQuestionOptions();
        results = scanf("%d", &questionType);
        
        while(getchar() != '\n');
        flag++;
    } while(results != 1 || questionType < 0 || questionType > 5);

    return (enum typeOfQuestion) questionType;
}

void getQuestionPrompt(char* buffer, size_t size) {
    printFieldBorder();

    printf("\nEnter the prompt of your question (250 characters max):\n");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int getNumOfOptions() {
    printFieldBorder();

    int options;
    int results;
    int flag = 0;

    do {
        if(flag > 0) {
            printf("\n[WARNING] : PLEASE ENTER A NUMBER THAT IS NOT NEGATIVE\n");
        }

        printf("\nEnter the number of options for the question:\n");
        results = scanf("%d", &options);
        
        while (getchar() != '\n');
        flag++;
    } while(results != 1 || options < 0);

    return options;
}

// Inserting user data into structs
void setExamInfo(struct examInfo *exam, int examId) {
    
    printSectionBorder();
    printf("Exam Information Section");

    exam->examID         = examId;
    exam->numOfQuestions = getNumberOfQuestions();
    exam->timeLimit      = getTimeLimit();
    exam->grade          = getGradeLevel();
    exam->subject        = getSubjectMatter();
    getExamDescription(exam->examDescrip, sizeof(exam->examDescrip));
}

void setProfInfo(struct professorInfo *professor) {

    printSectionBorder();
    printf("Professor Information Section");

    professor->professorID = getProfessorID();
    getProfessorEmail(professor->professorEmail, sizeof(professor->professorEmail));
    getProfessorFirstName(professor->professorFirstName, sizeof(professor->professorFirstName));
    getProfessorLastName(professor->professorLastName, sizeof(professor->professorLastName));
}

void setQuestionInfo(struct questionInfo *question, int questionid) {
    question->questionID   = questionid;
    question->questionType = getTypeOfQuestion();
    question->numOfOptions = getNumOfOptions();
    getQuestionPrompt(question->prompt, sizeof(question->prompt));
}

// Writing struct data into user file
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

void writeProfessorInfo(FILE *userFile, FILE *template, struct professorInfo *professor) {
    
    printSectionBorder();
    printf("Question Information Section");
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
          fprintf(userFile, "        \"ProfessorLastName\"    : \"%s\"\n", professor->professorLastName);
      }
      else if ( strstr(line, "    \"Questions\": [") ) {
          fputs(line, userFile);
          break;
      }
      else {
          fputs(line, userFile);
      }
   }
}

void writeQuestionInfo(FILE *userFile, FILE *questionTemplate, struct questionInfo *question, int commaFlag) {
    
    char line[301];

    while( fgets(line, sizeof(line), questionTemplate) ) {
        if( strstr(line, "<QUESTION_ID>") ) {
            fprintf(userFile, "            \"QuestionID\"     : %d,\n", question->questionID);
        }
        else if( strstr(line, "<TYPE_OF_QUESTION>") ) {
            char *typeOfQuesName = getTypeOfQuestionName(question->questionType);
            fprintf(userFile, "            \"TypeOfQuestion\" : \"%s\",\n", typeOfQuesName);
        }
        else if( strstr(line, "<PROMPT>") ) {
            fprintf(userFile, "                \"Prompt\" : \"%s\",\n", question->prompt);
        }
        else if( strstr(line, "<OPTION>") ) {
            fprintf(userFile, "                \"OPTION\" : \"%d\"\n", question->numOfOptions);
        }
        else if( strstr(line, "<INSERT_COMMA>") ) {
            if (commaFlag == 1) {
                fprintf(userFile, "        },\n");
            }
            else {
                fprintf(userFile, "        }\n");
            }
        }
        else {
            fputs(line, userFile);
        }
    }
}

void writeAllQuestionInfo(FILE *userFile, FILE *template, FILE *questionTemplate, int numOfQuestions) {
    
    printSectionBorder();
    char line[301];
    
    while( fgets(line, sizeof(line), template) ) {

        if( strstr(line, "<INSERT_QUESTION>")) {

            for(int questionID = 1; questionID <= numOfQuestions; questionID++) {

                struct questionInfo question;
                struct questionInfo *questionPtr = &question;

                setQuestionInfo(questionPtr, questionID);
                
                if(questionID < numOfQuestions) {
                    writeQuestionInfo(userFile, questionTemplate, questionPtr, 1);
                }
                else {
                    writeQuestionInfo(userFile, questionTemplate, questionPtr, 0);
                }
                
                rewind(questionTemplate);
            }
        }
        else {
            fputs(line, userFile);
        }
   }

}
