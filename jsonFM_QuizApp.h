/******************************************************
   CREATED BY    : Diego Lopez-Rodas
   CREATION DATE : 09/18/2025
   UPDATE DATE   : 10/07/2025
   PURPOSE       : 
 ******************************************************/

#ifndef JSONFM_QUIZAPP
#define JSONFM_QUIZAPP

#include <stdio.h>
#include <string.h>

// ENUMs
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

enum typeOfQuestion {
  MCQ,
  TF,
  FILLBLANK,
  SHORT,
  MATCH,
  ESSAY
};

// STRUCTs
struct examInfo {
  int                examID; 
  int                numOfQuestions;
  int                timeLimit;
  char               examDescrip[250];
  enum gradeLevel    grade;
  enum subjectMatter subject;
};

struct professorInfo {
  int  professorID;
  char professorEmail[62];
  char professorFirstName[50];
  char professorLastName[50];
};

struct questionInfo {
  int                 questionID;
  enum typeOfQuestion questionType;
  char                prompt[250];
  int                 numOfOptions;
};

// METHODS

// Access user exam file
FILE *accessUserFile(void);

// Obtaining the name for associated enum value
char *getGradeLevelName(int gradeLevelValue);
char *getSubjectMatterName(int subjectMatterValue);
char *getTypeOfQuestionName(int typeOfQuesValue);


// Collect user data to be called in setExamInfo()
int getNumberOfQuestions();
int getTimeLimit();
enum gradeLevel getGradeLevel();
enum subjectMatter getSubjectMatter();
void getExamDescription(char* buffer, size_t size);

// Collect user data to be called in setProfInfo()
int getProfessorID();
void getProfessorEmail(char* buffer, size_t size);
void getProfessorFirstName(char* buffer, size_t size);
void getProfessorLastName(char* buffer, size_t size);

// Collect user data to be called in setQuestionInfo()
enum typeOfQuestion getTypeOfQuestion();
void getQuestionPrompt(char* buffer, size_t size);
int getNumOfOptions();

// Inserting user data into structs
void setExamInfo(struct examInfo *exam, int examId);
void setProfInfo(struct professorInfo *professor);
void setQuestionInfo(struct questionInfo *question, int questionId);

// Writing struct data into user file
void writeExamInfo(FILE *userFile, FILE *template, struct examInfo *exam);
void writeProfessorInfo(FILE *userFile, FILE *template, struct professorInfo *professor);
void writeQuestionInfo(FILE *userFile, FILE *questionTemplate, struct questionInfo *question);
void writeAllQuestionInfo(FILE *userFile, FILE *template, int numOfQuestions);

#endif