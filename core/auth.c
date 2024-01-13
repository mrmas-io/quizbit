//
// Created by mrmas on 01/01/24.
//
#include "../sources/src.h"

/**
 * @brief Randomly generates a new player ID after a new signup.
 *
 * @param id A character array to store the generated player ID.
 */
void assignPlayerId(char *id) {
    srand((unsigned int)time(NULL));  // Seed the random number generator
    id[0] = 'p';
    id[1] = '1';
    for (int i = 2; i < (IDSIZE - 1); ++i) {
        id[i] = ('0' + rand() % 10);
    }
    id[IDSIZE - 1] = '\0';
}

/**
 * @brief Reads a password from the user without echoing the input and returns the length of the password.
 *
 * @param prompt A prompt or message to display before reading the password.
 * @param passwd A character array to store the entered password.
 *
 * @return The length of the entered password.
 */
size_t getPass(const char *prompt, char *passwd) {
    if (prompt) {
        fputs(prompt, stdout);
        fflush(stdout);
    }

    int pos = 0;
    memset(passwd, 0, KEYSIZE * sizeof(char));

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__MINGW64__)
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    DWORD count = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
    while (1) {
        ReadConsoleA(hStdin, &(*(passwd + pos)), 1, &count, NULL);
        if (*(passwd + pos) == '\r') {
            break;
        }
        pos++;
    }
    SetConsoleMode(hStdin, mode);
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    while (1) {
        char c = getchar();
        if (ENTER_KEY == c) {
            break;
        }
        *(passwd + pos++) = c;
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
    *(passwd + pos) = '\0';
    return pos;
}

/**
 * @brief Hashes a user password using SHA256.
 *
 * @param password The password to be hashed.
 *
 * @return A dynamically allocated string containing the hashed password.
 *         The caller is responsible for freeing the allocated memory.
 */
char *hashPass(const char *password) {
    // Allocate memory for the hash value (32 bytes + null terminator) & handle memory allocation error
    char *hash_str = malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    if (!hash_str) {
        return NULL;
    }
    // Create an SHA-256 context & handle context creation error
    EVP_MD_CTX *ctx = EVP_MD_CTX_create();
    if (!ctx) {
        free(hash_str);
        return NULL;
    }
    // Initialize the context with SHA-256 & handle initialization error
    if (EVP_DigestInit_ex(ctx, EVP_sha256(), NULL) != 1) {
        EVP_MD_CTX_destroy(ctx);
        free(hash_str);
        return NULL;
    }
    // Update the context with the password & handle update error
    if (EVP_DigestUpdate(ctx, password, strlen(password)) != 1) {
        EVP_MD_CTX_destroy(ctx);
        free(hash_str);
        return NULL;
    }

    // Finalize the hash and get the digest
    unsigned char digest[SHA256_DIGEST_LENGTH];
    EVP_DigestFinal_ex(ctx, digest, NULL);
    // Convert the digest to a hexadecimal string
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        sprintf(&hash_str[i * 2], "%02x", digest[i]);
    }
    hash_str[SHA256_DIGEST_LENGTH * 2] = '\0';
    // Clean up & return hashed value
    EVP_MD_CTX_destroy(ctx);
    return hash_str;
}


/**
 * @brief Checks if a password contains at least one uppercase letter.
 *
 * @param passwd The password to be checked.
 * @param len The length of the password.
 *
 * @return true if the password contains at least one uppercase letter, false otherwise.
 */
bool hasUpperCase(const char *passwd, size_t len) {
    //check if char *contains uppercase.
    for (size_t i = 0; i < len; i++) {
        if(isupper(passwd[i]))
            return true;
    }
    return false;
}

/**
 * @brief Checks if a password contains at least one lowercase letter.
 *
 * @param passwd The password to be checked.
 * @param len The length of the password.
 *
 * @return true if the password contains at least one lowercase letter, false otherwise.
 */
bool hasLowerCase(const char *passwd, size_t len) {
    //check if char *contains lowercase.
    for (size_t i = 0; i < len; i++) {
        if(islower(passwd[i]))
            return true;
    }
    return false;
}

/**
 * @brief Checks if a password contains at least one numeric digit.
 *
 * @param passwd The password to be checked.
 * @param len The length of the password.
 *
 * @return true if the password contains at least one numeric digit, false otherwise.
 */
bool hasNumber(const char *passwd, size_t len) {
    //checs if char *cpntains digits.
    for (size_t i = 0; i < len; i++)
    {
        if(isdigit(passwd[i]))
            return true;
    }
    return false;
}

/**
 * @brief Checks if a password contains at least one special character from a specified set.
 *
 * @param passwd The password to be checked.
 * @param len The length of the password.
 * @param charSet The set of special characters to check for.
 *
 * @return true if the password contains at least one special character, false otherwise.
 */
bool hasSpecChars(const char *passwd, size_t len) {
    static const char *charSet = "@!#$%&+*=~^-.,;:?>_<[](){}|";
    for (size_t i = 0; i < len; i++) {
        if (strchr(charSet, passwd[i]) != NULL) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Validates a password based on specified criteria.
 *
 * @param passwd The password to be validated.
 * @param len The length of the password.
 *
 * @return true if the password meets the validation criteria, false otherwise.
 */
bool validatePassword(const char *passwd, size_t len) {
    return (len >= 8) && hasUpperCase(passwd, len) && hasLowerCase(passwd, len) && hasNumber(passwd, len) &&
            hasSpecChars(passwd, len);
}

/**
 * @brief Validates a username based on specified criteria.
 *
 * @param uname The username to be validated.
 * @param len The length of the username.
 *
 * @return true if the username meets the validation criteria, false otherwise.
 */
bool validateUsername(const char *uname, size_t len) {
    if (len < 6)
        return false;
    for (size_t i = 0; i < len; i++) {
        if (!islower(uname[i]) && !isdigit(uname[i]) && uname[i] != '_')
            return false;
    }
    return true;
}

/**
 * @brief Validates user credentials (username and password) based on specified criteria.
 *
 * @param uname The username to be validated.
 * @param passwd The password to be validated.
 *
 * @return true if both the username and password meet the validation criteria, false otherwise.
 */
bool validateCredentials(const char *uname, const char *passwd) {
    return validateUsername(uname, strlen(uname)) && validatePassword(passwd, strlen(passwd));
}

/**
 * @brief Checks the database for duplicate user accounts.
 *
 * This function queries the database to determine if there is an existing user account
 * with the specified username. It returns true if a duplicate is found and false otherwise.
 *
 * @param Uname The username to be checked for duplication.
 *
 * @return true if a duplicate user account is found, false otherwise.
 */
bool check_duplicate(const char *Uname) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    bool exists = false;

    // Open the database
    int rc = sqlite3_open("./core/database/game_database.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return false;
    }

    // Prepare SQL statement to check for the username in the signup table
    const char *sql = "SELECT username FROM users WHERE username = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, " [!] - Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return false;
    }

    // Bind the username parameter
    rc = sqlite3_bind_text(stmt, 1, Uname, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        fprintf(stderr, " [!] - Failed to bind parameter: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }

    // Execute the query
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        exists = true; // Username exists in the database
    } else if (rc != SQLITE_DONE) {
        fprintf(stderr, " [!] - Failed to execute query: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }

    sqlite3_finalize(stmt);  // Finalize the statement
    sqlite3_close(db);  // Close the database

    return exists;
}

// Function to check if username and password are valid
/**
 * @brief Checks and verifies login details against the database.
 *
 * This function validates login credentials by checking if the provided username and password
 * match an existing user account in the database. It returns true if the credentials are valid
 * and false otherwise.
 *
 * @param Uname The username to be verified.
 * @param Passwd The password to be verified.
 *
 * @return true if the login details are valid, false otherwise.
 */
bool verifyLogin(const char *Uname, const char *Passwd) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    bool isValid = false;

    // Open the database
    int rc = sqlite3_open("./core/database/game_database.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, " [!] - Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return false;
    }

    // Prepare SQL statement to check for username and password in the login table
    const char *sql = "SELECT player_id FROM users WHERE username = ? AND password = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, " [!] - Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return false;
    }

    // Bind the username and password parameters
    rc = sqlite3_bind_text(stmt, 1, Uname, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        fprintf(stderr, " [!] - Failed to bind username parameter: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }

    rc = sqlite3_bind_text(stmt, 2, Passwd, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        fprintf(stderr, " [!] - Failed to bind password parameter: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }

    // Execute the query
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        isValid = true; // Username and password are valid
    } else if (rc != SQLITE_DONE) {
        fprintf(stderr, " [!] - Failed to execute query: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }

    sqlite3_finalize(stmt);  // Finalize the statement
    sqlite3_close(db);  // Close the database
    return isValid;
}