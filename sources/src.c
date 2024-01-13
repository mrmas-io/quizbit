//
// Created by mrmas on 01/01/24.
//
#include "src.h"
/**
 * @brief Clears the memory of an account_t structure.
 *
 * This function clears the memory of individual fields within the account_t structure,
 * ensuring sensitive information, such as passwords, is handled with security in mind.
 * The function uses memset to set each field to zero, providing a clean slate for sensitive data
 * and initializing numerical fields to zero.
 *
 * @param player A pointer to the account_t structure whose memory needs to be cleared.
 */
void struct_memset(account_t *player) {
    // Clear individual fields
    memset(player->pId, 0, sizeof(player->pId));
    memset(player->name, 0, sizeof(player->name));
    memset(player->surname, 0, sizeof(player->surname));
    memset(player->username, 0, sizeof(player->username));

    // Clear sensitive fields
#if defined(_MSC_VER) && (_MSC_VER >= 1400)
    // For MS Visual Studio
        memset_s(player->password, sizeof(player->password), 0, sizeof(player->password));
#else
    // For other compilers/platforms
    memset(player->password, 0, sizeof(player->password));
#endif

    memset(player->scores.date, 0, sizeof(player->scores.date));
    player->scores.score = 0;

    // Note: The entire structure is not cleared to allow for preserving other non-sensitive data.
    // If complete zeroing of the structure is needed, uncomment the following line.
    memset(player, 0, sizeof(account_t));
}

/**
 * @brief Reads user input from the specified stream and replaces the trailing newline character with a null character.
 *
 * @param prompt A prompt or message to display before reading input.
 * @param array A character array to store the user input.
 * @param size The size of the character array.
 * @param STREAM The file stream from which to read input (e.g., stdin for keyboard input).
 */
size_t input(const char *prompt, char *array, size_t size, FILE *STREAM) {
    if (prompt) {
        fputs(prompt, stdout); // Display the provided prompt.
        fflush(stdout);
    }
    if (size <= 1) { // Handle invalid buffer size
        return false; // Exit the program if the specified size is 0 (no input can be read).
    }
    size_t len = 0;
    // Read a line of text from 'STREAM' into 'array' with a maximum size of 'size'.
    memset(array, 0, size * sizeof(char));
    if (NULL != fgets(array, size, STREAM)) {
        len = strlen(array);
        if ((len > 1) && *(array + (len - 1)) == '\n') {
            *(array + (len - 1)) = '\0'; // Remove the trailing newline character, if present
            len -= 1;
        }
        else {
            return false;
        }
    }
    return len; // Return the length of the string read (excluding the newline character).
}

/**
 * @brief Displays the top five players with the highest scores from the database.
 *
 * @param player A pointer to the player's account structure.
 */
void displayScoreboard(account_t *player) {
    clr();
    short x = 8, y = 1;
    char query[MAXBUFF * 4];
    sqlite3_stmt *stmt;

    SetCursorPosition(x, y);
    print_banner(10, " QUIZBIT - SCOREBOARD ", 10);

    SetCursorPosition(x + 2, y += 2);
    printf("PLAYER : %s \t SCORE : %04u",
           player->username, player->scores.score);

    // SQL query to select the top 5 players based on their scores
    snprintf(query, sizeof(query),
             "SELECT username, score FROM player ORDER BY score DESC LIMIT 5;");

    sqlite3 *db;
    if (sqlite3_open("./core/database/game_database.db", &db) != SQLITE_OK) {
        print_error("Error Cannot open db : %s", sqlite3_errmsg(db));
        mainmenu(player);
    }
    // Prepare and execute the query
    if (sqlite3_prepare_v2(db, query, -1, &stmt, NULL) == SQLITE_OK) {
        // Execute the statement and print the results
        SetCursorPosition(x + 6, y += 2);
        printf("Top 5 Players on the scoreboard");

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const char *username = (const char *)sqlite3_column_text(stmt, 0);
            int score = sqlite3_column_int(stmt, 1);
            SetCursorPosition(x + 4, y += 2);
            printf("Username : %s  ", username);
            SetCursorPosition(x + 4, y += 1);
            printf("Score    : %04u", score);
        }
        // Finalize the statement
        sqlite3_finalize(stmt);
    } else {
        print_error("Error preparing SQL statement: %s", sqlite3_errmsg(db));
    }
    sqlite3_close(db);
    SetCursorPosition(x + 2, y + 2);
    printf("press any key to go back to the main menu!...");
    cgetch();
    mainmenu(player);
}

/**
 * @brief Displays help/guide information on playing the game.
 *
 * @param player A pointer to the player's account structure.
 */
void displayHelp(account_t *player) {
    clr();
    short x = 8, y = 1;
    SetCursorPosition(x, y);
    print_banner(10, " QUIZBIT - GAMEPLAY HELP ", 10);

    SetCursorPosition(x + 2, y += 2);
    printf("PLAYER : %s \t SCORE : %04u",
           player->username, player->scores.score);

    SetCursorPosition(x + 0, y += 2);
    printf("\033[1;37;0m Welcome to QUIZBIT Quiz Challenge! This is a fun and educational game.");
    SetCursorPosition(x + 0, y += 1);
    printf("\033[1;37;0m The game consists of 3 categories: science, sports, and general knowledge.");
    SetCursorPosition(x + 0, y += 1);
    printf("\033[1;37;0m The system will randomly select questions from the chosen category.");
    SetCursorPosition(x + 0, y += 2);
    printf("\033[1;37;0m You can reset scores, edit & delete your account from the settings page.");
    SetCursorPosition(x + 0, y += 1);
    printf("\033[1;37;0m TIPS: Try to answer as quickly as possible to get more bonus points.");
    SetCursorPosition(x + 2, y + 2);
    printf("\033[1;37;0m Press any key to go back to the main menu : ");
    cgetch();
    mainmenu(player);
}

/**
 * @brief Displays the player's profile data including name, surname, username, score,
 * and the recently played date & time.
 *
 * @param person A pointer to the player's account structure.
 */
void displayProfile(account_t *Person) {
    clr();
    short x = 8, y = 1;
    enum options {SCOREBOARD = '1', RESETSCORE = '2', PROFILE = '3', EDITACCOUNT = '4', DELETEACCOUNT = '5', MAINMENU = '6'};

    SetCursorPosition(x, y);
    print_banner(10, " QUIZBIT - PLAYER PROFILE ", 10);

    SetCursorPosition(x + 2, y += 2);
    printf("FIRSTNAME      : \t%s", Person->name);
    SetCursorPosition(x + 2, y += 2);
    printf("LASTNAME       : \t%s", Person->surname);
    SetCursorPosition(x + 2, y += 2);
    printf("USERNAME       : \t%s", Person->username);
    SetCursorPosition(x + 2, y += 2);
    printf("CURRENT SCORE  : \t%04u", Person->scores.score);
    SetCursorPosition(x + 2, y + 2);
    printf("LAST PLAYED    : \t%s", Person->scores.date);
    print_success("Press any key to go  back to the main menu : ");
    cgetch();
    mainmenu(Person);
}
/**
 * @brief Calls the readRand function, writes the 10 randomly generated questions to the struct,
 * and displays the questions.
 *
 * @param player A pointer to the player's account structure.
 * @param category The category of questions to display.
 */
void displayQuestions(account_t *player, const char *category) {
    sqlite3 *db;
    short x = 8, y = 1, qid = 0;
    int rc = sqlite3_open("./core/database/quiz.db", &db); // Use your actual database connection

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s", sqlite3_errmsg(db));
        cgetch();
        mainmenu(player);
    }
    char title[BUFSIZE];
    sprintf(title, "QUIZBIT CHALLENGE - %s", category);
    Quiz_t questions[11];
    // Read 10 random questions from the 'science' table
    rc = readRand(db, questions, category);

    if (rc != true) {
        fprintf(stderr, "Error: Failed to read random questions. Code: %d", rc);
        sqlite3_close(db);
        cgetch();
        mainmenu(player);
    }
    clr();
    /* Set the cursor position, Display banner, & Load game */
    SetCursorPosition(x, y);
    print_banner(10, title, 10);
    SetCursorPosition(x + 2, y += 2);
    printf("Gameplay Loading... please wait!...");
    gamePlayLoader(x + 3, y + 2);
    SetCursorPosition(x + 2, y + 3);
    printf("Press any key to start : ");
    cgetch();

    //! Start game timer
    clock_t start_time = clock();
    player->scores.score = 0;
    do {

        clr();
        x = 8, y = 1;
        SetCursorPosition(x, y);
        print_banner(10, title, 10);
        SetCursorPosition(x + 2, y += 2);
        printf("PLAYER : %s \tSCORE : %u", player->username, player->scores.score);

        //Display quiz questions
        SetCursorPosition(x + 2, y += 2);
        printf("%hi.) %s", qid + 1, questions[qid].question);
        for (int i = 0; i < 4; ++i) {
            SetCursorPosition(x + 3, y += 2);
            printf("%s", questions[qid].choices[i]);
        }
        do {
            SetCursorPosition(x + 4, y + 1);
            switch (toupper(cgetch())) {
                case 'A' :
                    questions[qid].selected_choice = 0;
                    break;
                case 'B' :
                    questions[qid].selected_choice = 1;
                    break;
                case 'C' :
                    questions[qid].selected_choice = 2;
                    break;
                case 'D' :
                    questions[qid].selected_choice = 3;
                    break;
                default:
                    questions[qid].selected_choice = 9;
            }
        } while(questions[qid].selected_choice == 9);
        if (questions[qid].selected_choice == questions[qid].correct_answer) {
            player->scores.score += 100;
        }
        qid += 1;
    } while (qid < 10);
    clock_t end_time = clock();

    // Calculate the elapsed time in seconds
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Allocate bonus score to players
    if (player->scores.score > 0) {
        uint32_t bonus_score = player->scores.score / 10;
        if (elapsed_time > 180) {
            player->scores.score += bonus_score + 100;
        } else if (elapsed_time <= 120) {
            player->scores.score += bonus_score + 500;
        } else {
            player->scores.score += bonus_score + 300;
        }
    }
    SetCursorPosition(x + 2, y += 2);
    print_success("You scored : %04u", player->scores.score);
    //Update players score to database.
    if (updateScore(player, player->scores.score)) {
        //char tmp[KEYSIZE]; strcpy(tmp, player->username);
        //struct_memset(player);
        getPlayerData(player->username, player);
    }
    sqlite3_close(db);

    SetCursorPosition(x + 2, y += 2);
    printf("Do you want to view your answers [Y/N] ?");
    int ch = cgetch();
    if (toupper(ch) == 'Y') {
        displayAnswrs(player, questions);
        //cgetch();
    }
    SetCursorPosition(x + 2, y + 2);
    printf("Press any key to go back to the main menu : ");
    cgetch();
    mainmenu(player);
    // Close the database connection
}

/**
* @brief Keeps records of the answers the user entered while playing and displays them.
*
* @param player A pointer to the player's account structure.
* @param quest A pointer to the Quiz_t structure containing questions and correct answers.
*/
void displayAnswrs(account_t *player, Quiz_t *quest) {
    short x, y, qid = 0, check = 0;

    for (int i = 0; i < 2; ++i) {
        x = 8, y = 1;
        clr();
        SetCursorPosition(x, y);
        print_banner(10, "QUIZBIT - Preview Answers", 10);
        SetCursorPosition(x + 2, y += 2);
        printf("PLAYER : %s \tSCORE : %u", player->username, player->scores.score);
        while (check < 10) {
            SetCursorPosition(x + 1, y += 2);
            printf("%hi.) %s", qid + 1, quest[qid].question);
            SetCursorPosition(x + 3, y += 1);
            printf("Your Choice    : %s", quest[qid].choices[quest[qid].selected_choice]);
            SetCursorPosition(x + 2, y += 1);
            printf("\033[1;37;42mCorrect Answer : %s \033[0m", quest[qid].choices[quest[qid].correct_answer]);
            qid += 1;
            check += 1;
            if (check == 5) {
                break;
            }
        }
        if (check <= 9) {
            SetCursorPosition(x + 2, y + 2);
            printf("Press the [SPACE-BAR] key to view the rest : ");
            cgetch();
        } else {
            break;
        }
    }
}

/**
 * @brief Displays a banner containing a title text with characters on both sides.
 *
 * @param left The number of characters on the left side of the title text.
 * @param text The title text to be displayed in the banner.
 * @param right The number of characters on the right side of the title text.
 */
void print_banner(size_t left, const char *text, size_t right) {
    do {
        for (size_t i = 0; i < left; i++) {
            if (i % 2 == 1)
                printf("\033[1;31;41m  ");
            else
                printf("\033[1;37;47m  ");
        }

        if (NULL != text) {
            printf("\033[0m%s", text);
        }
        for (size_t i = 0; i < right; i++) {
            if (i % 2 == 1) {
                printf("\033[1;37;47m  ");
            }
            else {
                printf("\033[1;31;41m  ");
            }
        }
        printf("\033[0m"); fflush(stdout);
    } while(EXIT_SUCCESS);
}

/**
 * @brief Prints colored text on the screen when the code/functions encounter errors.
 *
 * @param error The error message to be printed.
 * @param ... Additional parameters to support variable argument list formatting.
 */
void print_error(const char *error, ...) {
    va_list args;
    va_start(args, error);

    // Print white text on red background
    fprintf(stderr, "\033[1;37;41m\n\t [!] - ");
    // Call vprintf to handle variable arguments
    vprintf(error, args);
    // Reset text attributes to default
    printf("\033[0m");

    va_end(args);
}

/**
 * @brief Prints colored text on the screen for successful operations.
 *
 * @param error The success message to be printed.
 * @param ... Additional parameters to support variable argument list formatting.
 */
void print_success(const char *success,...) {
    va_list args;
    va_start(args, success);

    // Print white text on green background
    fprintf(stdout, "\033[1;37;42m\n\t [$] - ");
    // Call vprintf to handle variable arguments
    vprintf(success, args);
    // Reset text attributes to default
    printf("\033[0m");

    va_end(args);
}

/**
 * @brief Custom sleep function that delays program execution for the specified number of milliseconds.
 *
 * @param milliseconds The duration to sleep in milliseconds.
 */
void delay(uint32_t milliseconds) {
    struct timespec req = {0};
    req.tv_sec = milliseconds / 1000;
    req.tv_nsec = (milliseconds % 1000) * 1000000;

    while (nanosleep(&req, &req) != 0) {
        if (errno != EINTR) {
            perror("nanosleep");
            break;
        }
    }
}

/**
 * @brief Displays a progress bar at the specified position on the screen.
 *
 * @param progress The current progress value.
 * @param length The length of the progress bar.
 * @param x The x-coordinate position on the screen.
 * @param y The y-coordinate position on the screen.
 */
void progressBar(uint32_t progress, uint32_t length, short x, short y) {
    SetCursorPosition(x, y);
    for (uint32_t i = 0; i < length; ++i) {
        if (i < progress) {
            printf("\033[48;5;15m \033[0m"); // White color for the progress bar
        } else {
            printf(" ");
        }
    }
    printf(" %d%%", progress * 2);
    fflush(stdout);
}

/**
 * @brief Displays a progress bar at the specified position on the screen for a pre-gameplay loader.
 *
 * @param x The x-coordinate position on the screen.
 * @param y The y-coordinate position on the screen.
 */
void gamePlayLoader(short x, short y) {
    const uint32_t DELAY_MS = 100, BAR_LENGTH = 50;
    for (uint32_t i = 0; i <= BAR_LENGTH; ++i) {
        printf("\t\t");
        progressBar(i, BAR_LENGTH, x, y);
        delay(DELAY_MS);
    }
    return;
}

/**
 * @brief Displays a loader while user credentials authenticate.
 *
 * @param session The session or stage for which the loader is displayed.
 */
void showLoader(const char *session) {
    const char charSet[] = {'|', '/', '-', '\\'};
    const size_t charSize = sizeof(charSet) / sizeof(charSet[0]);
    const size_t numFrames = 50;

    printf("%s", session);
    fflush(stdout);

    for (size_t i = 0; i < numFrames; ++i) {
        printf("%c ", charSet[i % charSize]);
        fflush(stdout);
        delay(50);  // Sleep for 50 milliseconds (0.05 seconds)
        printf("\b\b");
    }
    printf("\n");
}

/**
 * @brief Gets the current date and time in a formatted string.
 *
 * @return A string containing the current formatted date and time.
 */
char* getFormattedDatetime() {
    time_t t;
    time(&t);
    char *formattedDatetime = malloc(KEYSIZE * sizeof(char));
    if (formattedDatetime != NULL) {
        strftime(formattedDatetime, KEYSIZE, "%d-%b-%Y %I:%M%p", localtime(&t));
    }
    return formattedDatetime;
}

/**
 * @brief Sets the cursor position on the screen.
 *
 * @param x The x-coordinate position on the screen.
 * @param y The y-coordinate position on the screen.
 */
void SetCursorPosition(short x, short y) {
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__MINGW64__)
    COORD coordinates = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
#else
    printf("\033[%d;%dH", y + 1, x + 1); //* On non-Windows systems, use ANSI escape codes to set cursor position.
#endif
}

/**
 * @brief Custom cross-platform getch() function for reading a single character from the console.
 *
 * @return The character read from the console.
 */
int cgetch(void) {
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__MINGW64__)
    //* On Windows, use the 'getch' function to get a character.
    return getch();
#else
    //* On non-Windows systems, set the terminal to non-canonical mode to get a character.
    struct termios old_tio, new_tio;
    int c;

    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    c = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    return c;
#endif
}
