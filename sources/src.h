//
// Created by mrmas on 01/01/24.
//
#ifndef QUIZBIT_SRC_H
#define QUIZBIT_SRC_H
#include <time.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <sqlite3.h>
#include <stdbool.h>
#include <openssl/evp.h>

#define IDSIZE 13
#define KEYSIZE 32
#define BUFSIZE 64
//#define MINBUFF 128
#define MAXBUFF 256

#define clr() printf("\033c")
#define CTRL_K(key) ((key) & 0x1f)
#define SHA256_DIGEST_LENGTH EVP_MAX_BLOCK_LENGTH

typedef struct Quiz{
    char question[MAXBUFF];
    char choices[5][BUFSIZE];
    uint32_t correct_answer;
    uint32_t selected_choice;
} Quiz_t;

typedef struct Point{
    uint32_t score;
    char date[KEYSIZE];
} Point_t;
typedef struct Account{
    char pId[IDSIZE];
    char name[KEYSIZE];
    char surname[KEYSIZE];
    char username[KEYSIZE];
    char password[KEYSIZE];
    Point_t scores;
} account_t;

/**
 ** @brief Functions for managing user authentication, gameplay, and account management utilities.
 **/
void login(void);
void signup(void);
void homepage(void);
void logout(account_t*);
void mainmenu(account_t*);
void gameplay(account_t*);
void settings(account_t*);
void assignPlayerId(char *);
void displayHelp(account_t*);
void editAccount(account_t *);
void deleteAccount(account_t *);
void struct_memset(account_t *);
void displayProfile(account_t *);
void displayScoreboard(account_t *);
bool updateScore(account_t *, uint32_t);

/**
 ** @brief Function declarations for database utilities
 **/
void setup(void);
bool createGameDatabase(void);
bool createQuizDatabase(void);
bool insertPlayerData(account_t *);
bool readRand(sqlite3 *, Quiz_t *, const char *);
bool deletePlayerData(sqlite3 *, account_t *, const char *);
bool insertQuizData(sqlite3 *, const Quiz_t *, size_t, const char *);
bool updatePlayerData(sqlite3 *, const char *, const char *, const char *, const char *);

/**
 ** @brief Function declarations
 **/
void showLoader(const char *);
void print_error(const char *,...);
void print_success(const char *,...);
void SetCursorPosition(short, short);
void print_banner(size_t, const char *, size_t);

size_t getPass(const char *, char *);
size_t input(const char *, char *, size_t, FILE *);

int cgetch(void);
void delay(uint32_t);
char *getFormattedDatetime();
char *hashPass(const char *);
void gamePlayLoader(short, short);
void displayAnswrs(account_t *, Quiz_t *);
void displayQuestions(account_t *, const char *);
void progressBar(uint32_t, uint32_t, short, short);

/**
 * @brief Function declarations for user/player validation/authentication
 **/
bool check_duplicate(const char *);
bool hasNumber(const char *, size_t);
bool hasUpperCase(const char *, size_t);
bool hasLowerCase(const char *, size_t);
bool hasSpecChars(const char *, size_t);
bool validatePassword(const char *, size_t);
bool validateUsername(const char *, size_t);
bool verifyLogin(const char *, const char *);
bool getPlayerData(const char *, account_t *);
bool validateCredentials(const char *, const char *);

/**
 * @brief Function declarations for Platform-specific includes for Windows and Unix-like systems
 **/
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__MINGW64__)
#include <io.h>
#include <conio.h>
#include <windows.h>
#define ENTER_KEY 0x0D
#define BACKSPACE_KEY 0x08
#else
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#define ENTER_KEY 0x0A
#define BACKSPACE_KEY 0x7F
#endif
#endif //QUIZBIT_SRC_H
