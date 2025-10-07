/******************************************************
   CREATED BY    : Diego Lopez-Rodas
   CREATION DATE : 09/28/2025
   UPDATE DATE   : 10/07/2025
   PURPOSE       : 
 ******************************************************/

#include <stdio.h>
#include <string.h>
#include "jsonFM_QuizApp.h"

FILE *accessUserFile(void) {
   char userFile[56];
   printf("Enter your file's name (55 characters max):\n");
   scanf("%55s", userFile);
   
   FILE *filePointer = fopen(userFile, "w");
   return filePointer;
}


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

int getNumberOfQuestions() {
    int numOfQues;
    printf("Enter the number of questions on this exam:\n");
    scanf("%d", &numOfQues);
    return numOfQues;
}

int getTimeLimit() {
    int timeLimit;
    int flag = 0;

    do {
        if(flag > 0) {
            printf("PLEASE ENTER TIME AS POSITVE WHOLE NUMBER\n");
        }
        printf("Enter the time limit of the exam in minutes:\n");
        scanf("%d", &timeLimit);
        flag++;
    } while(timeLimit < 0);
    
    return timeLimit;
}

enum gradeLevel getGradeLevel() {
    int grade;
    int flag = 0;

    do {
        if(flag > 0) {
            printf("PLEASE SELECT NUMBER FROM GIVEN OPTIONS\n");
        }
        printf("Enter the number corresponding to the grade level:\n");
        printf("\tELEMENTARY - 0\n\tMIDDLE SCHOOL - 1\n\tHIGH SCHOOL- 2\n\tCOLLEGE - 3\n");
        scanf("%d", &grade);
        flag++;
    } while(grade < 0 || grade > 3);

    return (enum gradeLevel) grade;
}

enum subjectMatter getSubjectMatter() {
    int subject;
    int flag = 0;

    do {
        if(flag > 0) {
            printf("PLEASE SELECT NUMBER FROM GIVEN OPTIONS\n");
        }
        printf("Enter the number corresponding to the subject matter:\n");
        printf("\tSocial Science - 0\n\tScience - 1\n\tMath - 2\n\tLiterature - 3\n\tLanguage - 4\n");
        scanf("%d", &subject);
        flag++;
    } while(subject < 0 || subject > 4);

    return (enum subjectMatter) subject;
}

void getExamDescription(char* buffer, size_t size) {
    printf("Enter exam description (250 characters max):\n");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}


int getProfessorID() {
    int profID;
    int flag = 0;

    do {
        if(flag > 0) {
            printf("PLEASE ENTER PROPER ID. PROFESSOR IDS ARE POSITIVE, NON-DECIMAL NUMBERS\n");
        }
        printf("Enter the professor ID:\n");
        scanf("%d", &profID);
        flag++;
    } while(profID < 0);

    return profID;
}

void getProfessorEmail(char* buffer, size_t size) {
    printf("Enter the professor email (62 characters max):\n");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void getProfessorFirstName(char* buffer, size_t size) {
    printf("Enter the professor's first name (50 characters max):\n");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void getProfessorLastName(char* buffer, size_t size) {
    printf("Enter the professor's first name (50 characters max):\n");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}


enum typeOfQuestion getTypeOfQuestion() {
    int questionType;
    int flag = 0;

    do {
        if(flag > 0) {
            printf("PLEASE SELECT NUMBER FROM GIVEN OPTIONS\n");
        }
        printf("Enter the number corresponding to the type of question:\n");
        printf("\tMULTIPLE CHOICE QUESTION - 0\n\tTRUE OR FALSE - 1\n\tFILL-IN-BLANK - 2\n\tSHORT RESPONSE - 3\n\tMATCHING - 4\n\tESSAY RESPONSE - 5\n");
        scanf("%d", &questionType);
        flag++;
    } while(questionType < 0 || questionType > 5);

    return (enum typeOfQuestion) questionType;
}

void getQuestionPrompt(char* buffer, size_t size) {
    printf("Enter the prompt of your question (250 characters max):\n");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int getNumOfOptions() {
    int options;
    int flag = 0;

    do {
        if(flag > 0) {
            printf("PLEASE ENTER A NUMBER THAT IS NOT NEGATIVE");
        }
        printf("Enter the number of options for the question:\n");
        scanf("%d", &options);
        flag++;
    } while(options < 0);

    return options;
}


void setExamInfo(struct examInfo *exam, int examId) {
    exam->examID         = examId;
    exam->numOfQuestions = getNumberOfQuestions();
    exam->timeLimit      = getTimeLimit();
    exam->grade          = getGradeLevel();
    exam->subject        = getSubjectMatter();
    getExamDescription(exam->examDescrip, sizeof(exam->examDescrip));
}

void setProfInfo(struct professorInfo *professor) {
    professor->professorID = getProfessorID();
    getProfessorEmail(professor->professorEmail, sizeof(professor->professorEmail));
    getProfessorFirstName(professor->professorFirstName, sizeof(professor->professorFirstName));
    getProfessorLastName(professor->professorLastName, sizeof(professor->professorLastName));
}

void setQuestionInfo(struct questionInfo *question, int questionid) {
    question->questionID   = questionid;
    question->questionType = getTypeOfQuestion();
    question->numOfOptions = getNumberOfOptions();
    getQuestionPrompt(question->prompt, sizeof(question->prompt));
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
      else if ( strstr(line, "    \"Questions\": [") ) {
          fputs(line, userFile);
          break;
      }
      else {
          fputs(line, userFile);
      }
   }
}

void writeQuestionInfo(FILE *userFile, FILE *questionTemplate, struct questionInfo *question) {
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
        else {
            fputs(line, userFile);
        }
    }
}

