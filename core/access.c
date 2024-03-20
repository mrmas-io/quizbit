//
// Created by mrmas on 01/01/24.
//
#include "../utils/utils.h"

/**
 * @brief Displays and prompts options on the homepage.
 * Users can choose to login, signup, or exit the program.
 */
void homepage(void) {
    clr();
    short x = 8, y = 1, choice;
    enum options {
        LOGIN   = '1',
        SIGNUP  = '2',
        EXIT    = '3',
        QUIT    = CTRL_K('c')
    };

    SetCursorPosition(x, y);
    print_banner(10, " QUIZBIT - QUIZ GAME ", 10);
    SetCursorPosition(x + 4, y += 2);
    printf("[1]. LOGIN TO YOUR ACCOUNT");
    SetCursorPosition(x + 4, y += 2);
    printf("[2]. CREATE A NEW ACCOUNT");
    SetCursorPosition(x + 4, y += 2);
    printf("[3]. EXIT / QUIT");

    do {
        SetCursorPosition(x + 10, y + 1);
        switch (cgetch()) {
            case LOGIN :
                 login();
                 break;

            case SIGNUP :
                 signup();
                 break;

            case EXIT :
            case QUIT :
                 exit(EXIT_FAILURE);
            default:
                 choice = -1;
        }
    } while (-1 == choice);
}

/**
 * @brief Handles the signup process, allowing users to create a new account.
 */
void signup(void) {
    short x, y, check;
    account_t *Person;

    if (NULL == (Person = (account_t *)calloc(sizeof(account_t ), 2))) {
        print_error("Error: %s to the struct!", strerror(ENOMEM));
        exit(EXIT_FAILURE);
    }

    do {
        clr();
        x = 8, y = 1;  // Initialize cursor position.
        //* Set the cursor position & Display a banner.
        SetCursorPosition(x, y);
        print_banner(10, " CREATE A NEW ACCOUNT ", 10);

        SetCursorPosition(x + 2, y += 2);
        printf("\033[30;47m->> Username Requirements : Atleast 6 characters. \033[0m");
        SetCursorPosition(x + 2, y += 1);
        printf("\033[30;47m-> Can contain lowercase, digits or an Underscore.\033[0m");
        SetCursorPosition(x + 2, y += 2);
        printf("\033[30;47m->> Password Requirements : Atleast 8 characters. \033[0m");
        SetCursorPosition(x + 2, y += 1);
        printf("\033[30;47m-> Must contain Alphanumeric & Special characters.\033[0m");

        SetCursorPosition(x + 4, y += 2);
        input("Enter your name : ", Person->name, KEYSIZE, stdin);
        SetCursorPosition(x + 4, y += 2);
        input("Enter your surname : ", Person->surname, KEYSIZE, stdin);
        SetCursorPosition(x + 4, y += 2);
        input("Enter your username : ", Person->username, KEYSIZE, stdin);
        SetCursorPosition(x + 4, y + 2);
        input("Enter your password : ", Person->password, KEYSIZE, stdin);

        if (validateCredentials(Person->username, Person->password)) {
            if (check_duplicate(Person->username)) {
                print_error("Error : Username isn't available, try again");
                check = -1;
                cgetch();
            }
            else {
                assignPlayerId(Person->pId);
                Person->scores.score = 0;
                insertPlayerData(Person);
                check = 0;
            }
        } else {
            print_error("Error : Username/password must meet the requirements, try again");
            check = -1;
            cgetch();
        }
    } while (-1 == check);
    free(Person);
    print_success("Account Successfully Created!... Press any key to go to the login page : ");
    cgetch();
    login();
}

/**
 * @brief Handles the login process, prompting users to enter their credentials.
 */
void login(void) {
    account_t *player;
    short x, y, check = 1;

    char __uname[KEYSIZE];
    char __passwd[KEYSIZE];

    if (NULL == (player = (account_t*)calloc(sizeof(account_t), 2))) {
        print_error("Error: %s to the struct!", strerror(ENOMEM));
        exit(EXIT_FAILURE);
    }

    do {
        clr();
        x = 8, y = 1;  // Initialize cursor position.
        //* Set the cursor position & Display a banner.
        SetCursorPosition(x, y);
        print_banner(10, " LOGIN TO YOUR ACCOUNT ", 10);

        SetCursorPosition(x + 4, y += 2);
        input("Enter your username : ", __uname, KEYSIZE, stdin);
        SetCursorPosition(x + 4, y + 2);
        getPass("Enter your password : ", __passwd);
        showLoader("Checking!...");

        char *hashedPassword;
        if ((hashedPassword = hashPass(__passwd)) == NULL) {
            print_error(" [!] - Error: [hPass] %s", strerror(ENOSYS));
            exit(EXIT_FAILURE);
        }
        if (verifyLogin(__uname, hashedPassword)) {
            check = 0;
        } else {
            print_error("Incorrect Username/password, Try Again : ");
            check += 1;
            cgetch();
        }
        free(hashedPassword);

    } while (check <= 3 && check > 0);

    if (check >= 3) {
        print_error("Error, Too many attempts : %s.", strerror(ECANCELED));
        cgetch();
    }
    else {
        print_success("Login Successful!... Press any key to go to the main menu : ");
        getPlayerData(__uname, player);
        cgetch();
        mainmenu(player);
    }
    free(player);
    homepage();
}

/**
 * @brief Logs out the current user session by clearing the user account structure and freeing memory.
 *
 * This function clears all members of the provided user account structure and then frees the memory
 * allocated for the structure itself. It effectively logs the user out of the current session.
 *
 * @param Session A pointer to the user account structure representing the current session.
 */

void logout(account_t *Session) {
    // Reset/Clear the fields of the struct and it's members
    struct_memset(Session);
    free(Session);
    homepage();
}

/**
 * @brief Displays the main menu options, including gameplay, help, settings, and logout.
 *
 * @param player A pointer to the user account structure representing the current player.
 */
void mainmenu(account_t *player) {
    clr();
    short x = 8, y = 1;
    enum options {
         GAMEPLAY   = '1',
         HELP       = '2',
         SETTINGS   = '3',
         LOGOUT     = '4'
    };

    SetCursorPosition(x, y);
    print_banner(10, " QUIZBIT - MAINMENU ", 10);

    SetCursorPosition(x + 15, y += 1);
    printf("Welcome to the Quiz Game");
    SetCursorPosition(x + 4, y += 2);
    printf("PLAYER : %s \tSCORE : %04u", player->username, player->scores.score);

    SetCursorPosition(x + 0, y += 2);
    printf("[1]. GAMEPLAY \t[2]. HELP \t[3]. SETTINGS \t[4]. LOGOUT");

    int choice;
    do {
        SetCursorPosition(x + 2, y + 1);
        switch (cgetch()) {
            case GAMEPLAY :
                 gameplay(player);
                 break;

            case HELP :
                 displayHelp(player);
                 break;

            case SETTINGS :
                 settings(player);
                 break;

            case LOGOUT :
                 logout(player);
                 break;
            default:
                choice = -1;
        }
    } while (-1 == choice);
}

/**
 * @brief Displays options for game and account management utilities.
 *
 * This function provides a menu for users to access game-related and account management options,
 * such as updating or deleting player data, changing settings, or navigating back to the main menu.
 *
 * @param player A pointer to the user account structure representing the current player.
 */
void settings(account_t *player) {
    clr();
    short x = 8, y = 1, choice;
    enum options {
         SCOREBOARD     = '1',
         RESETSCORE     = '2',
         PROFILE        = '3',
         EDITACCOUNT    = '4',
         DELETEACCOUNT  = '5',
         MAINMENU       = '6'
    };

    SetCursorPosition(x, y);
    print_banner(10, " QUIZBIT - SETTINGS ", 10);

    SetCursorPosition(x + 2, y += 2);
    printf("PLAYER : %s \t SCORE : %04u",
           player->username, player->scores.score);

    SetCursorPosition(x + 1, y += 2);
    printf("[1]. SCORE BOARD \t[2]. RESET SCORE   \t[3]. PROFILE");
    SetCursorPosition(x + 1, y += 2);
    printf("[4]. EDIT ACCOUNT\t[5]. DELETE ACCOUNT\t[6]. MAINMENU");

    do {
        SetCursorPosition(x + 3, y + 1);
        switch (cgetch()) {
            case RESETSCORE :
                if (updateScore(player, 0)) {
                    char tmp[KEYSIZE]; strcpy(tmp, player->username);
                    getPlayerData(tmp, player);
                }
                mainmenu(player);
                break;
            case PROFILE :
                displayProfile(player);
                break;
            case SCOREBOARD :
                displayScoreboard(player);
                break;
            case EDITACCOUNT :
                print_error("This action is irreversible. Are you sure you want to edit your account? [Y/N] : ");
                do {
                    switch (toupper(cgetch())) {
                        case 'Y' :
                            editAccount(player);
                            break;
                        case 'N' :
                            mainmenu(player);
                            break;
                        default :
                            choice = -1;
                    }
                } while(-1 == choice);
                break;
            case DELETEACCOUNT :
                print_error("This action is irreversible. Are you sure you want to delete your account? [Y/N] : ");
                do {
                    switch (toupper(cgetch())) {
                        case 'Y' :
                            deleteAccount(player);
                            break;
                        case 'N' :
                            mainmenu(player);
                            break;
                        default :
                            choice = -1;
                    }
                } while(-1 == choice);
                break;
            case MAINMENU :
                mainmenu(player);
                break;
            default:
                choice = -1;
        }
    } while (-1 == choice);
}

/**
 * @brief Displays gameplay options, allowing the player to choose categories before starting the game.
 *
 * @param player A pointer to the user account structure representing the current player.
 */
void gameplay(account_t *player) {
    clr();
    short x = 8, y = 1, choice;
    enum options {
         SCIENCE            = '1',
         SPORTS             = '2',
         GENERALKNOWLEDGE   = '3',
         MAINMENU           = '4'
    };

    SetCursorPosition(x, y);
    print_banner(10, " QUIZBIT - GAMEPLAY", 10);

    SetCursorPosition(x + 2, y += 2);
    printf("PLAYER : %s \t SCORE : %04u",
           player->username, player->scores.score);

    SetCursorPosition(x + 1, y += 2);
    printf("Select the game category you want to play : ");
    SetCursorPosition(x + 1, y += 2);
    printf("[1]. SCIENCE \t[2]. SPORTS \t[3]. GENERAL KNOWLEDGE \t[4]. mainmenu");

    do {
        SetCursorPosition(x + 3, y + 1);
        switch (cgetch()) {
            case SCIENCE :
                 displayQuestions(player, "SCIENCE");
                 break;
            case SPORTS :
                 displayQuestions(player, "SPORTS");
                 break;
            case GENERALKNOWLEDGE :
                 displayQuestions(player, "GENERALKNOWLEDGE");
                 break;
            case MAINMENU :
                 mainmenu(player);
                 break;
            default:
                choice = -1;
        }
    } while (-1 == choice);
}

/**
 * @brief Updates the player's score in the database.
 *
 * @param player A pointer to the user account structure representing the current player.
 * @param score The new score to update in the database.
 *
 * @return true if the update is successful, false otherwise.
 */
bool updateScore(account_t *player, uint32_t score) {
    bool status = true;
    char query[MAXBUFF];
    sqlite3_stmt *stmt;

    // SQL query to update the score of the specified player
    snprintf(query, sizeof(query),
             "UPDATE player SET score = ?, last_played = ? WHERE username = ?;");

    sqlite3 *db;
    int rc = sqlite3_open(FILE_PATH, &db);
    if (rc != SQLITE_OK) {
        print_error("Cannot open database: %s", sqlite3_errmsg(db));
        return false;
    }

    char *registeredDatetime = getFormattedDatetime();
    if (registeredDatetime != NULL) {
        strcpy(player->scores.date, registeredDatetime);
        free(registeredDatetime);
    } else {
        fprintf(stderr, " [!] - Error: %s to struct time_t member!\n", strerror(ENOMEM));
        return false;
    }
    // Prepare and execute the query
    if (sqlite3_prepare_v2(db, query, -1, &stmt, NULL) == SQLITE_OK) {
        if (sqlite3_bind_int(stmt, 1, score) == SQLITE_OK &&
            sqlite3_bind_text(stmt, 2, player->scores.date, -1, SQLITE_STATIC) == SQLITE_OK &&
            sqlite3_bind_text(stmt, 3, player->username, -1, SQLITE_STATIC) == SQLITE_OK) {
            if (sqlite3_step(stmt) != SQLITE_DONE) {
                fprintf(stderr, "Error updating score: %s\n", sqlite3_errmsg(db));
                sqlite3_finalize(stmt);
                sqlite3_close(db);
                return false;
            }
        } else {
            fprintf(stderr, "Error binding parameters: %s\n", sqlite3_errmsg(db));
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return false;
        }
        sqlite3_finalize(stmt);
    } else {
        fprintf(stderr, "Error preparing SQL statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return false;
    }
    sqlite3_close(db);
    return status;
}

/**
 * @brief Modifies player account details.
 *
 * This function allows the player to edit and update their account information,
 * such as name, surname, username, or password.
 *
 * @param player A pointer to the user account structure representing the current player.
 */
void editAccount(account_t *player) {
    sqlite3 *db;
    account_t *Person;
    short x, y, check;

    if (sqlite3_open(FILE_PATH, &db) != SQLITE_OK) {
        print_error("Cannot open database: %s", sqlite3_errmsg(db));
        cgetch();
        mainmenu(player);
    }
    do {
        clr();
        x = 8, y = 1;
        //* Set the cursor position & Display a banner.
        SetCursorPosition(x, y);
        print_banner(10, " EDIT YOUR ACCOUNT ", 10);
        SetCursorPosition(x + 2, y += 2);
        printf("\033[30;47m->> Username Requirements : Atleast 6 characters. \033[0m");
        SetCursorPosition(x + 2, y += 1);
        printf("\033[30;47m-> Can contain lowercase, digits or an Underscore.\033[0m");
        SetCursorPosition(x + 2, y += 2);
        printf("\033[30;47m->> Password Requirements : Atleast 8 characters. \033[0m");
        SetCursorPosition(x + 2, y += 1);
        printf("\033[30;47m-> Must contain Alphanumeric & Special characters.\033[0m");

        if ((Person = (account_t *)calloc(sizeof(account_t), 2)) == NULL) {
            print_error("Error %s to struct.", strerror(ENOMEM));
            sqlite3_close(db);
            cgetch();
            mainmenu(player);
        }

        SetCursorPosition(x + 4, y += 2);
        input("Enter your name : ", Person->name, KEYSIZE, stdin);
        SetCursorPosition(x + 4, y += 2);
        input("Enter your surname : ", Person->surname, KEYSIZE, stdin);
        SetCursorPosition(x + 4, y += 2);
        input("Enter your username : ", Person->username, KEYSIZE, stdin);
        SetCursorPosition(x + 4, y + 2);
        input("Enter your password : ", Person->password, KEYSIZE, stdin);

        if (validateCredentials(Person->username, Person->password)) {
            if (check_duplicate(Person->username)) {
                print_error("Error : Username isn't available, try again");
                free(Person);
                check = -1;
                cgetch();
            }
            else {
                check = 0;
            }
        } else {
            print_error("Error : Username/password must meet the requirements, try again");
            free(Person);
            check = -1;
            cgetch();
        }
    } while(-1 == check);

    if (updatePlayerData(db, "name", player->name, Person->name, "users") &&
            updatePlayerData(db, "surname", player->surname, Person->surname, "users") &&
            updatePlayerData(db, "username", player->username, Person->username, "users") &&
            updatePlayerData(db, "password", player->password, Person->password, "users") &&
            updatePlayerData(db, "name", player->name, Person->name, "player") &&
            updatePlayerData(db, "surname", player->surname, Person->surname, "player") &&
            updatePlayerData(db, "username", player->username, Person->username, "player")) {
        print_success("Account details successfully updated!... Press any key to go back to the main menu...");
    } else {
        print_error("Error : Failed to update data.");
    }
    // Close the database connection
    sqlite3_close(db);
    cgetch();
    getPlayerData(Person->username, player);
    free(Person);
    mainmenu(player);
}

/**
 * @brief Deletes player account details.
 *
 * This function allows the player to delete their account, removing all associated data from the database.
 *
 * @param player A pointer to the user account structure representing the current player.
 */
void deleteAccount(account_t *player) {
    sqlite3 *db;
    short x = 8, y = 1;

    int rc = sqlite3_open(FILE_PATH, &db); // Use your actual database connection
    if (rc != SQLITE_OK) {
        print_error("Cannot open database : %s", sqlite3_errmsg(db));
        cgetch();
        mainmenu(player);
    }

    clr();
    //* Set the cursor position & Display a banner.
    SetCursorPosition(x, y);
    print_banner(10, " DELETE YOUR ACCOUNT ", 10);
    SetCursorPosition(x + 2, y + 2);
    printf("\033[30;47m->> Press any key to finalize account deletion process : \033[0m");
    cgetch();

    if (deletePlayerData(db, player, "users") && deletePlayerData(db, player, "player")) {
        print_success("Account deleted successfully!... Press any key to go to the login/signup page : ");
    }
    else {
        print_error("Error : Failed to delete account. You need to log in again...", rc);
    }
    // Close the database connection
    sqlite3_close(db);
    cgetch();
    logout(player);
}

/**
 * @brief Gets player information from the database after player details get updated.
 *
 * This function retrieves updated player information from the database based on the provided username
 * and updates the player account structure accordingly.
 *
 * @param username The username of the player whose information needs to be retrieved.
 * @param playerData A pointer to the user account structure to store the retrieved player information.
 *
 * @return true if the retrieval is successful, false otherwise.
 */
bool getPlayerData(const char *username, account_t *playerData) {
    char query[MAXBUFF * 2];
    sqlite3_stmt *stmt;

    // SQL query to select player data by username
    snprintf(query, sizeof(query),
             "SELECT player_id, name, surname, username, score, last_played FROM player WHERE username = ?;");

    sqlite3 *db;
    int rc = sqlite3_open(FILE_PATH, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return false;
    }

    // Prepare and execute the query
    if (sqlite3_prepare_v2(db, query, -1, &stmt, NULL) == SQLITE_OK) {
        // Bind the username parameter
        if (sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC) == SQLITE_OK) {
            // Execute the statement
            if (sqlite3_step(stmt) == SQLITE_ROW) {
                // Retrieve data from the result set and store it in the account_t struct
                strcpy(playerData->pId, (const char *)sqlite3_column_text(stmt, 0));
                strcpy(playerData->name, (const char *)sqlite3_column_text(stmt, 1));
                strcpy(playerData->surname, (const char *)sqlite3_column_text(stmt, 2));
                strcpy(playerData->username, (const char *)sqlite3_column_text(stmt, 3));
                playerData->scores.score = sqlite3_column_int(stmt, 4);
                strcpy(playerData->scores.date, (const char *)sqlite3_column_text(stmt, 5));

                // Finalize the statement
                sqlite3_finalize(stmt);
                // Close the database connection
                sqlite3_close(db);
                return true;  // Success
            } else {
                fprintf(stderr, "No data found for username: %s\n", username);
            }
        } else {
            fprintf(stderr, "Error binding parameter: %s\n", sqlite3_errmsg(db));
        }
        // Finalize the statement
        sqlite3_finalize(stmt);
    } else {
        fprintf(stderr, "Error preparing SQL statement: %s\n", sqlite3_errmsg(db));
    }
    // Close the database connection
    sqlite3_close(db);
    return false;  // Failure
}
