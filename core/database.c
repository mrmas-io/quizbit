//
// Created by mrmas on 12/12/23.
//
#include "../utils/utils.h"

static const Quiz_t Science[] = {
        {
                .question = "Which of the following is the smallest unit of matter?",
                .choices = {
                        "[A]. Atom",
                        "[B]. Molecule",
                        "[C]. Neutron",
                        "[D]. Proton"
                },
                .correct_answer = "[A]. Atom"
        },
        {
                .question = "What is the chemical symbol for the element gold?",
                .choices = {
                        "[A]. Ag",
                        "[B]. Fe",
                        "[C]. Au",
                        "[D]. Hg"
                },
                .correct_answer = "[C]. Au"
        },
        {
                .question = "Which gas is most abundant in the Earth's atmosphere?",
                .choices = {
                        "[A]. Oxygen",
                        "[B]. Carbon dioxide",
                        "[C]. Nitrogen",
                        "[D]. Hydrogen"
                },
                .correct_answer = "[C]. Nitrogen"
        },
        {
                .question = "What is the process by which plants make their own food using sunlight?",
                .choices = {
                        "[A]. Respiration",
                        "[B]. Photosynthesis",
                        "[C]. Fermentation",
                        "[D]. Combustion"
                },
                .correct_answer = "[B]. Photosynthesis"
        },
        {
                .question = "Which organelle is responsible for producing energy in a cell?",
                .choices = {
                        "[A]. Nucleus",
                        "[B]. Endoplasmic reticulum",
                        "[C]. Golgi apparatus",
                        "[D]. Mitochondria"
                },
                .correct_answer = "[D]. Mitochondria"
        },
        {
                .question = "What is the chemical formula for water?",
                .choices = {
                        "[A]. H2O",
                        "[B]. CO2",
                        "[C]. O2",
                        "[D]. NaCl"
                },
                .correct_answer = "[A]. H2O"
        },
        {
                .question = "Which planet is known as the 'Red Planet'?",
                .choices = {
                        "[A]. Venus",
                        "[B]. Earth",
                        "[C]. Mars",
                        "[D]. Jupiter"
                },
                .correct_answer = "[C]. Mars"
        },
        {
                .question = "What is the smallest bone in the human body?",
                .choices = {
                        "[A]. Femur",
                        "[B]. Tibia",
                        "[C]. Stapes",
                        "[D]. Radius"
                },
                .correct_answer = "[C]. Stapes"
        },
        {
                .question = "Which force keeps planets in orbit around the Sun?",
                .choices = {
                        "[A]. Gravitational force",
                        "[B]. Magnetic force",
                        "[C]. Electric force",
                        "[D]. Centrifugal force"
                },
                .correct_answer = "[A]. Gravitational force"
        },
        {
                .question = "What is the chemical symbol for helium?",
                .choices = {
                        "[A]. He",
                        "[B]. H",
                        "[C]. Ne",
                        "[D]. Li"
                },
                .correct_answer = "[A]. He"
        },
        {
                .question = "What is the process of a liquid turning into a gas at its boiling point?",
                .choices = {
                        "[A]. Condensation",
                        "[B]. Sublimation",
                        "[C]. Evaporation",
                        "[D]. Solidification"
                },
                .correct_answer = "[C]. Evaporation"
        },
        {
                .question = "What is the process by which plants make food using sunlight, water, and carbon dioxide?",
                .choices = {
                        "[A]. Photosynthesis",
                        "[B]. Cellular respiration",
                        "[C]. Transpiration",
                        "[D]. Fertilization"
                },
                .correct_answer = "[A]. Photosynthesis"
        },
        {
                .question = "What is the hardest naturally occurring substance on Earth?",
                .choices = {
                        "[A]. Quartz",
                        "[B]. Diamond",
                        "[C]. Topaz",
                        "[D]. Corundum"
                },
                .correct_answer = "[B]. Diamond"
        },
        {
                .question = "What is the name of the layer of the Earth's atmosphere that contains the ozone layer?",
                .choices = {
                        "[A]. Stratosphere",
                        "[B]. Mesosphere",
                        "[C]. Thermosphere",
                        "[D]. Exosphere"
                },
                .correct_answer = "[A]. Stratosphere"
        },
        {
                .question = "Which of the following is a fossil fuel?",
                .choices = {
                        "[A]. Coal",
                        "[B]. Natural gas",
                        "[C]. Oil",
                        "[D]. All of the above"
                },
                .correct_answer = "[D]. All of the above"
        },
        {
                .question = "What is the name of the branch of science that studies the human body?",
                .choices = {
                        "[A]. Anatomy",
                        "[B]. Physiology",
                        "[C]. Biochemistry",
                        "[D]. All of the above"
                },
                .correct_answer = "[D]. All of the above"
        },
        {
                .question = "Which of the following is a type of renewable energy?",
                .choices = {
                        "[A]. Solar energy",
                        "[B]. Wind energy",
                        "[C]. Hydropower",
                        "[D]. All of the above"
                },
                .correct_answer = "[D]. All of the above"
        },
        {
                .question = "What is the name of the process by which cells divide?",
                .choices = {
                        "[A]. Mitosis",
                        "[B]. Meiosis",
                        "[C]. Both A and B",
                        "[D]. None of the above"
                },
                .correct_answer = "[A]. Mitosis"
        },
        {
                .question = "Which of the following is a theory that explains the origin and evolution of the universe?",
                .choices = {
                        "[A]. The Big Bang theory",
                        "[B]. The Steady State theory",
                        "[C]. The Oscillating Universe theory",
                        "[D]. The Multiverse theory"
                },
                .correct_answer = "[A]. The Big Bang theory"
        },
        {
                .question = "What is the name of the scientist who discovered the theory of relativity?",
                .choices = {
                        "[A]. Albert Einstein",
                        "[B]. Isaac Newton",
                        "[C]. Galileo Galilei",
                        "[D]. Stephen Hawking"
                },
                .correct_answer = "[A]. Albert Einstein"
        }
};

static const Quiz_t Sports[] = {
        {
                .question = "Who won the FIFA World Cup in 2018?",
                .choices = {
                        "[A]. Brazil",
                        "[B]. Germany",
                        "[C]. France",
                        "[D]. Argentina"
                },
                .correct_answer = "[C]. France"
        },
        {
                .question = "Which basketball player is often called 'The King'?",
                .choices = {
                        "[A]. Kobe Bryant",
                        "[B]. Michael Jordan",
                        "[C]. LeBron James",
                        "[D]. Shaquille O'Neal"
                },
                .correct_answer = "[C]. LeBron James"
        },
        {
                .question = "In martial arts, which discipline involves using throws and grappling techniques?",
                .choices = {
                        "[A]. Karate",
                        "[B]. Taekwondo",
                        "[C]. Judo",
                        "[D]. Muay Thai"
                },
                .correct_answer = "[C]. Judo"
        },
        {
                .question = "Which country is famous for its dominance in men's tennis with players like Rafael Nadal and Fernando Verdasco?",
                .choices = {
                        "[A]. United States",
                        "[B]. Spain",
                        "[C]. Switzerland",
                        "[D]. Serbia"
                },
                .correct_answer = "[B]. Spain"
        },
        {
                .question = "In soccer, what is the maximum number of players allowed on the field for one team during a match?",
                .choices = {
                        "[A]. 10",
                        "[B]. 11",
                        "[C]. 22",
                        "[D]. 9"
                },
                .correct_answer = "[B]. 11"
        },
        {
                .question = "Which basketball team is known for their 'Showtime' era during the 1980s, led by Magic Johnson?",
                .choices = {
                        "[A]. Boston Celtics",
                        "[B]. Los Angeles Lakers",
                        "[C]. Chicago Bulls",
                        "[D]. Miami Heat"
                },
                .correct_answer = "[B]. Los Angeles Lakers"
        },
        {
                .question = "What martial art features strikes using elbows and knees, and is sometimes called the 'Art of Eight Limbs'?",
                .choices = {
                        "[A]. Karate",
                        "[B]. Jiu-Jitsu",
                        "[C]. Muay Thai",
                        "[D]. Taekwondo"
                },
                .correct_answer = "[C]. Muay Thai"
        },
        {
                .question = "Which soccer player is often referred to as 'CR7'?",
                .choices = {
                        "[A]. Cristiano Ronaldo",
                        "[B]. Lionel Messi",
                        "[C]. Neymar",
                        "[D]. Gareth Bale"
                },
                .correct_answer = "[A]. Cristiano Ronaldo"
        },
        {
                .question = "In basketball, how many points is a three-point field goal worth?",
                .choices = {
                        "[A]. 1",
                        "[B]. 2",
                        "[C]. 3",
                        "[D]. 4"
                },
                .correct_answer = "[C]. 3"
        },
        {
                .question = "Which martial art originated in South Korea and emphasizes high, fast kicks and spinning kicks?",
                .choices = {
                        "[A]. Karate",
                        "[B]. Judo",
                        "[C]. Taekwondo",
                        "[D]. Kung Fu"
                },
                .correct_answer = "[C]. Taekwondo"
        },
        {
                .question = "Which team has won the most FIFA World Cups?",
                .choices = {
                        "[A]. Brazil",
                        "[B]. Germany",
                        "[C]. Italy",
                        "[D]. Argentina"
                },
                .correct_answer = "[A]. Brazil"
        },
        {
                .question = "What is the name of the highest-scoring player in NBA history?",
                .choices = {
                        "[A]. LeBron James",
                        "[B]. Kareem Abdul-Jabbar",
                        "[C]. Michael Jordan",
                        "[D]. Wilt Chamberlain"
                },
                .correct_answer = "[B]. Kareem Abdul-Jabbar"
        },
        {
                .question = "Who holds the record for the fastest 100m sprint in history?",
                .choices = {
                        "[A]. Justin Gatlin",
                        "[B]. Asafa Powell",
                        "[C]. Usain Bolt",
                        "[D]. Carl Lewis"
                },
                .correct_answer = "[C]. Usain Bolt"
        },
        {
                .question = "What is the name of the most famous soccer stadium in the world?",
                .choices = {
                        "[A]. Wembley Stadium",
                        "[B]. Camp Nou",
                        "[C]. Maracanã Stadium",
                        "[D]. Santiago Bernabéu Stadium"
                },
                .correct_answer = "[C]. Maracanã Stadium"
        },
        {
                .question = "What is the name of the basketball move where a player jumps up and dunks the ball with two hands?",
                .choices = {
                        "[A]. Slam dunk",
                        "[B]. Layup",
                        "[C]. Crossover",
                        "[D] Hook shot"
                },
                .correct_answer = "[A]. Slam dunk"
        },
        {
                .question = "What is the name of the martial art that is known for its use of grappling and submissions?",
                .choices = {
                        "[A] Karate",
                        "[B] Taekwondo",
                        "[C] Muay Thai",
                        "[D] Jiu-Jitsu"
                },
                .correct_answer = "[D] Jiu-Jitsu"
        },
        {
                .question = "As of 2023, which football (soccer) player has won the most Ballon d'Or awards?",
                .choices = {
                        "[A] Lionel Messi",
                        "[B] Cristiano Ronaldo",
                        "[C] Johan Cruyff",
                        "[D] Michel Platini"
                },
                .correct_answer = "[A] Lionel Messi"
        },
        {
                .question = "What is the name of the basketball team that has won the most NBA championships?",
                .choices = {
                        "[A] Boston Celtics",
                        "[B] Los Angeles Lakers",
                        "[C] Golden State Warriors",
                        "[D] Chicago Bulls"
                },
                .correct_answer = "[B] Los Angeles Lakers"
        },
        {
                .question = "What is the name of the martial art that is known for its use of weapons such as the katana and the nunchaku?",
                .choices = {
                        "[A] Karate",
                        "[B] Taekwondo",
                        "[C] Kendo",
                        "[D] Jiu-Jitsu"
                },
                .correct_answer = "[C] Kendo"
        },
        {
                .question = "What is the name of the soccer tournament that is held every four years and is contested by the best national teams in the world?",
                .choices = {
                        "[A] FIFA World Cup",
                        "[B] UEFA European Championship",
                        "[C] Copa América",
                        "[D] UEFA Champions League"
                },
                .correct_answer = "[A] FIFA World Cup"
        }
};

static const Quiz_t GeneralKnowledge[] = {
        {
                .question = "What is the largest planet in our solar system?",
                .choices = {
                        "[A]. Venus",
                        "[B]. Earth",
                        "[C]. Jupiter",
                        "[D]. Mars"
                },
                .correct_answer = "[C]. Jupiter"
        },
        {
                .question = "Which river is the longest in the world?",
                .choices = {
                        "[A]. Amazon River",
                        "[B]. Nile River",
                        "[C]. Mississippi River",
                        "[D]. Yangtze River"
                },
                .correct_answer = "[B]. Nile River"
        },
        {
                .question = "Who is the author of 'To Kill a Mockingbird'?",
                .choices = {
                        "[A]. J.K. Rowling",
                        "[B]. Harper Lee",
                        "[C]. George Orwell",
                        "[D]. Charles Dickens"
                },
                .correct_answer = "[B]. Harper Lee"
        },
        {
                .question = "Which country is known as the Land of the Rising Sun?",
                .choices = {
                        "[A]. China",
                        "[B]. Japan",
                        "[C]. India",
                        "[D]. South Korea"
                },
                .correct_answer = "[B]. Japan"
        },
        {
                .question = "What is the largest ocean on Earth?",
                .choices = {
                        "[A]. Atlantic Ocean",
                        "[B]. Indian Ocean",
                        "[C]. Arctic Ocean",
                        "[D]. Pacific Ocean"
                },
                .correct_answer = "[D]. Pacific Ocean"
        },
        {
                .question = "Who painted the Mona Lisa?",
                .choices = {
                        "[A]. Vincent van Gogh",
                        "[B]. Pablo Picasso",
                        "[C]. Leonardo da Vinci",
                        "[D]. Michelangelo"
                },
                .correct_answer = "[C]. Leonardo da Vinci"
        },
        {
                .question = "What is the currency of Mexico?",
                .choices = {
                        "[A]. Peso",
                        "[B]. Euro",
                        "[C]. Dollar",
                        "[D]. Yen"
                },
                .correct_answer = "[A]. Peso"
        },
        {
                .question = "Which city is known as the City of Love and is famous for the Eiffel Tower?",
                .choices = {
                        "[A]. Rome",
                        "[B]. Paris",
                        "[C]. Barcelona",
                        "[D]. London"
                },
                .correct_answer = "[B]. Paris"
        },
        {
                .question = "In which year did the Titanic sink?",
                .choices = {
                        "[A]. 1907",
                        "[B]. 1912",
                        "[C]. 1920",
                        "[D]. 1931"
                },
                .correct_answer = "[B]. 1912"
        },
        {
                .question = "Who was the first woman to fly solo across the Atlantic Ocean?",
                .choices = {
                        "[A]. Amelia Earhart",
                        "[B]. Bessie Coleman",
                        "[C]. Charles Lindbergh",
                        "[D]. Howard Hughes"
                },
                .correct_answer = "[A]. Amelia Earhart"
        },
        {
                .question = "What is the capital of France?",
                .choices = {
                        "[A]. London",
                        "[B]. Berlin",
                        "[C]. Paris",
                        "[D]. Rome"
                },
                .correct_answer = "[C]. Paris"
        },
        {
                .question = "What is the largest ocean in the world?",
                .choices = {
                        "[A]. Atlantic Ocean",
                        "[B]. Pacific Ocean",
                        "[C]. Indian Ocean",
                        "[D]. Arctic Ocean"
                },
                .correct_answer = "[B]. Pacific Ocean"
        },
        {
                .question = "What is the most populous country in the world?",
                .choices = {
                        "[A]. China",
                        "[B]. India",
                        "[C]. United States",
                        "[D]. Indonesia"
                },
                .correct_answer = "[A]. China"
        },
        {
                .question = "What is the name of the world's tallest mountain?",
                .choices = {
                        "[A]. Mount Everest",
                        "[B]. K2",
                        "[C]. Kangchenjunga",
                        "[D]. Lhotse"
                },
                .correct_answer = "[A]. Mount Everest"
        },
        {
                .question = "What is the name of the largest desert in the world?",
                .choices = {
                        "[A]. Sahara Desert",
                        "[B]. Arabian Desert",
                        "[C]. Gobi Desert",
                        "[D]. Arctic Desert"
                },
                .correct_answer = "[A]. Sahara Desert"
        },
        {
                .question = "What is the name of the most famous painting in the world?",
                .choices = {
                        "[A]. Mona Lisa",
                        "[B]. Starry Night",
                        "[C]. The Scream",
                        "[D]. Guernica"
                },
                .correct_answer = "[A]. Mona Lisa"
        },
        {
                .question = "As of 1995, what is the name of the most famous book in the world?",
                .choices = {
                        "[A]. The Bible",
                        "[B]. Quran",
                        "[C]. The Lord of the Rings",
                        "[D]. Harry Potter"
                },
                .correct_answer = "[A]. The Bible"
        },
        {
                .question = "What is the name of the longest river in the world?",
                .choices = {
                        "[A]. Nile River",
                        "[B]. Amazon River",
                        "[C]. Yangtze River",
                        "[D]. Mississippi River"
                },
                .correct_answer = "[A]. Nile River"
        },
        {
                .question = "What is the name of the most popular social media platform in the world?",
                .choices = {
                        "[A]. Facebook",
                        "[B]. Instagram",
                        "[C]. Twitter",
                        "[D]. TikTok"
                },
                .correct_answer = "[A]. Facebook"
        },
        {
                .question = "What is the name of the largest city in the world?",
                .choices = {
                        "[A]. Tokyo",
                        "[B]. Shanghai",
                        "[C]. Delhi",
                        "[D]. São Paulo"
                },
                .correct_answer = "[A]. Tokyo"
        }
};

/**
 * @brief Creates a new SQLite database for the game and initializes necessary tables.
 *
 * The function creates 5 tables: 'users' to store user details after signing up, 'players' to keep user play records,
 * and three additional tables to store questions from three different categories, along with their answers.
 */
bool createDatabase(void) {
    sqlite3 *db;
    char *errMsg = 0;

    if (SQLITE_OK != sqlite3_open(FILE_PATH, &db)) {
        fprintf(stderr, " [!] - Error : %s.\n", sqlite3_errmsg(db));
        return false;
    }

    char *createTableQueries[] = {
            "CREATE TABLE IF NOT EXISTS users ("
                        "player_id TEXT NOT NULL UNIQUE PRIMARY KEY,"
                        "name TEXT NOT NULL,"
                        "surname TEXT NOT NULL,"
                        "username TEXT NOT NULL UNIQUE,"
                        "password TEXT NOT NULL,"
                        "registration_date TEXT NOT NULL);",

            "CREATE TABLE IF NOT EXISTS player ("
                        "player_id TEXT NOT NULL UNIQUE PRIMARY KEY,"
                        "name TEXT NOT NULL, surname TEXT NOT NULL,"
                        "username TEXT NOT NULL UNIQUE,"
                        "score INTEGER,"
                        "last_played TEXT NOT NULL);",

            "CREATE TABLE IF NOT EXISTS Science ("
                        "question_id INTEGER UNIQUE PRIMARY KEY,"
                        "question TEXT NOT NULL,"
                        "choice_a TEXT NOT NULL,"
                        "choice_b TEXT NOT NULL,"
                        "choice_c TEXT NOT NULL,"
                        "choice_d TEXT NOT NULL,"
                        "correct_choice TEXT NOT NULL);",

            "CREATE TABLE IF NOT EXISTS Sports ("
                        "question_id INTEGER UNIQUE PRIMARY KEY,"
                        "question TEXT NOT NULL,"
                        "choice_a TEXT NOT NULL,"
                        "choice_b TEXT NOT NULL,"
                        "choice_c TEXT NOT NULL,"
                        "choice_d TEXT NOT NULL,"
                        "correct_choice TEXT NOT NULL);",

            "CREATE TABLE IF NOT EXISTS GeneralKnowledge ("
                        "question_id INTEGER UNIQUE PRIMARY KEY,"
                        "question TEXT NOT NULL,"
                        "choice_a TEXT NOT NULL,"
                        "choice_b TEXT NOT NULL,"
                        "choice_c TEXT NOT NULL,"
                        "choice_d TEXT NOT NULL,"
                        "correct_choice TEXT NOT NULL);"
    };
    // Execute the SQL commands
    size_t i = 0, size = sizeof(createTableQueries) / sizeof(char*);
    for (; i < size; i++) {
        if (SQLITE_OK != sqlite3_exec(db, *(createTableQueries + i), 0, 0, &errMsg)) {
            fprintf(stderr, " [!] - SQL error: %s.\n", errMsg);
            sqlite3_free(errMsg);
            sqlite3_close(db);
            return false;
        }
    }
    sqlite3_close(db);
    return true;
}

/**
 * @brief Inserts player data into the 'players' table of the game database.
 *
 * @param user A pointer to the user account structure containing player details.
 */
bool insertPlayerData(account_t *user) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *hashedPassword = NULL;

    if (SQLITE_OK != sqlite3_open(FILE_PATH, &db)) {
        fprintf(stderr, " [!] - Can't open database: %s\n", sqlite3_errstr(SQLITE_ERROR));
        return false;
    }
    /* Open the database
    if (SQLITE_OK != sqlite3_open(FILE_PATH, &db)) {
        fprintf(stderr, " [!] - Can't open database: %s\n", sqlite3_errmsg(db));
        return false;
    }*/

    if (NULL == (hashedPassword = hashPass(user->password))) {
        fprintf(stderr, " [!] - Error: [hPass] %s\n", strerror(ENOSYS));
        return false;
    }

    char *registeredDatetime = getFormattedDatetime();
    if (registeredDatetime == NULL) {
        fprintf(stderr, " [!] - Error: %s to struct time_t member!\n", strerror(ENOMEM));
        free(hashedPassword);
        return false;
    }
    strcpy(user->scores.date, registeredDatetime);
    free(registeredDatetime);

    // Insert data into the "users" table using prepared statements
    char *insertTableQueries[] = {
            "INSERT INTO users (player_id, name, surname, username, password, registration_date) VALUES (?, ?, ?, ?, ?, ?);",
            "INSERT INTO player (player_id, name, surname, username, score, last_played) VALUES (?, ?, ?, ?, ?, ?);"
    };

    size_t i = 0, size = sizeof(insertTableQueries) / sizeof(char *);
    for (; i < size; i++) {
        if (SQLITE_OK == sqlite3_prepare_v2(db, *(insertTableQueries + i), -1, &stmt, 0)) {
            sqlite3_bind_text(stmt, 1, user->pId, -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, user->name, -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 3, user->surname, -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 4, user->username, -1, SQLITE_STATIC);

            if (1 == i) {
                sqlite3_bind_int(stmt, 5, user->scores.score);
                sqlite3_bind_text(stmt, 6, user->scores.date, -1, SQLITE_STATIC);
            } else {
                sqlite3_bind_text(stmt, 5, hashedPassword, -1, SQLITE_STATIC);
                sqlite3_bind_text(stmt, 6, user->scores.date, -1, SQLITE_STATIC);
            }

            if (SQLITE_DONE != sqlite3_step(stmt)) {
                fprintf(stderr, " [!] - Error inserting data into 'users' table: %s\n", sqlite3_errmsg(db));
                free(hashedPassword);
                sqlite3_close(db);
                return false;
            }
            sqlite3_reset(stmt);
            sqlite3_finalize(stmt);

        } else {
            fprintf(stderr, " [!] - Error preparing SQL statement for 'player' table: %s\n", sqlite3_errmsg(db));
            free(hashedPassword);
            sqlite3_close(db);
            return false;
        }
    }
    free(hashedPassword);
    sqlite3_close(db);
    return true;
}

/**
 * @brief Inserts quiz data (questions, choices, and correct choice) into the specified quiz table.
 *
 * @param db The SQLite database connection.
 * @param quizArray An array of Quiz_t structures containing quiz question & answer data.
 * @param arraySize The size of the quizArray.
 * @param tableName The name of the quiz table to insert data into.
 */
bool insertQuizData(sqlite3 *db, const Quiz_t *quizArray, size_t arraySize, const char *tableName) {
    char sql[MAXBUFF * 2];
    sprintf(sql, "INSERT INTO %s (question_id, question, choice_a, choice_b, choice_c, choice_d, correct_choice) VALUES (NULL, ?, ?, ?, ?, ?, ?)", tableName);

    sqlite3_stmt *stmt;
    // Prepare the SQL statement
    if (SQLITE_OK != sqlite3_prepare_v2(db, sql, -1, &stmt, NULL)) {
        fprintf(stderr, " [!] - Error: Failed to prepare SQL statement: %s.\n", sqlite3_errmsg(db));
        return false;
    }

    // Bind values and execute the statement for each quiz entry
    for (size_t i = 0; i < arraySize; i++) {
        if (SQLITE_OK != sqlite3_bind_text(stmt, 1, quizArray[i].question, -1, SQLITE_STATIC) ||
            SQLITE_OK != sqlite3_bind_text(stmt, 2, quizArray[i].choices[0], -1, SQLITE_STATIC) ||
            SQLITE_OK != sqlite3_bind_text(stmt, 3, quizArray[i].choices[1], -1, SQLITE_STATIC) ||
            SQLITE_OK != sqlite3_bind_text(stmt, 4, quizArray[i].choices[2], -1, SQLITE_STATIC) ||
            SQLITE_OK != sqlite3_bind_text(stmt, 5, quizArray[i].choices[3], -1, SQLITE_STATIC) ||
            SQLITE_OK != sqlite3_bind_text(stmt, 6, quizArray[i].correct_answer, -1, SQLITE_STATIC)) {
            fprintf(stderr, " [!] - Error: Failed to bind values: %s.\n", sqlite3_errmsg(db));
            sqlite3_finalize(stmt);
            return false;
        }

        // Execute the statement
        if (SQLITE_DONE != sqlite3_step(stmt)) {
            fprintf(stderr, " [!] - Error: Failed to execute SQL statement: %s\n", sqlite3_errmsg(db));
            sqlite3_finalize(stmt);
            return false;
        }
        // Reset the statement for the next iteration
        sqlite3_reset(stmt);
        sqlite3_clear_bindings(stmt);
    }

    // Finalize the statement
    sqlite3_finalize(stmt);

    fprintf(stdout, " [$] - Data inserted into table %s successfully.\n", tableName);
    return true;
}

/**
 * @brief Updates a specific column on the specified table in the game database.
 *
 * @param db The SQLite database connection.
 * @param col The name of the column to be updated.
 * @param oldV The old value in the specified column to be replaced.
 * @param newV The new value to replace the old value.
 * @param tableName The name of the table to update.
 */
bool updatePlayerData(sqlite3 *db, const char *col, const char *oldV, const char *newV, const char *tableName) {

    // Check for valid database connection or table, & column name values
    if (NULL == db || NULL == tableName || NULL == col || NULL == oldV || NULL == newV) {
        print_error("Error : Database connection is NULL or Invalid input parameters..");
        return false;
    }
    // Construct the SQL statement using placeholders to prevent SQL injection
    const char *sqlTemplate = "UPDATE %s SET %s = ? WHERE %s = ?;";
    size_t sqlSize = strlen(sqlTemplate) + strlen(tableName) + strlen(col) * 2 + 1;
    char sql[sqlSize];

    // Create & Prepare SQL statement
    snprintf(sql, sqlSize, sqlTemplate, tableName, col, col);
    sqlite3_stmt *stmt;
    if (SQLITE_OK != sqlite3_prepare_v2(db, sql, -1, &stmt, NULL)) {
        print_error("Error : Failed to prepare SQL statement.\n");
        return false;
    }

    // Bind values to the prepared statement
    if (SQLITE_OK != sqlite3_bind_text(stmt, 1, newV, -1, SQLITE_STATIC) ||
        SQLITE_OK != sqlite3_bind_text(stmt, 2, oldV, -1, SQLITE_STATIC)) {
        print_error("Error: Failed to bind values to the SQL statement.");
        sqlite3_finalize(stmt);
        return false;
    }
    // Execute the SQL statement & Check for successful execution
    int result = sqlite3_step(stmt);
    if (SQLITE_DONE != result) {
        print_error("Error: Failed to execute the SQL statement. Code -> %d", result);
        sqlite3_finalize(stmt);
        return false;
    }
    // Finalize the prepared statement
    sqlite3_finalize(stmt);
    return true;
}
/**
 * @brief Deletes a line that matches the user's information in the specified table of the game database.
 *
 * @param db The SQLite database connection.
 * @param user A pointer to the user account structure.
 * @param tableName The name of the table to delete data from.
 */
bool deletePlayerData(sqlite3 *db, account_t *user, const char *tableName) {
    // Construct the SQL statement using placeholders to prevent SQL injection
    const char *sqlTemplate = "DELETE FROM %s WHERE username = ?;";
    char sql[MAXBUFF]; // Adjust the size based on your needs

    // Check for valid database connection, table name, and user information
    if (NULL == db) {
        print_error("Error : Database connection is NULL.");
        return false;
    }
    if (NULL == tableName || NULL == user) {
        print_error("Error : Invalid input parameters.");
        return false;
    }

    // Create, Prepare, & Bind values to the prepared SQL statement
    snprintf(sql, sizeof(sql), sqlTemplate, tableName);
    sqlite3_stmt *stmt;
    if (SQLITE_OK != sqlite3_prepare_v2(db, sql, -1, &stmt, NULL)) {
        print_error("Error : Failed to prepare SQL statement.");
        return false;
    }
    if (SQLITE_OK != sqlite3_bind_text(stmt, 1, user->username, -1, SQLITE_STATIC)) {
        print_error("Error : Failed to bind values to the SQL statement.");
        sqlite3_finalize(stmt);
        return false;
    }

    // Execute & Check for successful execution of the SQL statement
    int result = sqlite3_step(stmt);
    if (SQLITE_DONE != result) {
        print_error("Error: Failed to execute the SQL statement. Code: %d", result);
        sqlite3_finalize(stmt);
        return false;
    }
    // Finalize the prepared statement
    sqlite3_finalize(stmt);
    return true;
}

/**
 * @brief Cross-platform function to checks for file existence in the directory
 * @param filePath A const pointer variable of type "const char*" (Path & Name of file to check for).
 **/
bool __fileExists(const char *filePath) {
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__MINGW64__)
    // Windows-specific code
    return ( 0 == _access(filePath, 0));
#else
    // Unix-like (including Linux, macOS) code
    return (0 == access(filePath, F_OK));
#endif
}

/**
 * @brief Sets up the initial state of the program by checking and creating necessary databases.
 *
 * The function checks if the 'game_db' and 'quiz_db' files already exist. If not, it creates
 * and populates the 'quiz_db' file with quiz questions, choices, and correct choices.
 * It also creates the 'game_db' with a default 'john_doe' player.
 *
 * The 'game_db' contains two tables: 'users' for storing user details after signing up,
 * and 'players' to keep user play records.
 *
 * The 'quiz_db' contains three tables for questions from three different categories
 * along with their answers.
 */
bool setup(void) {
    if (__fileExists(FILE_PATH)) {
        fprintf(stdout, " [$] - Database already exists.\n");
        return true;
    }
    //delay(2000); //Not needed
    if (!createDatabase()) {
        fprintf(stderr, " [!] - Error: Failed to create database!...\n");
        return false;
    }

    sqlite3 *db;
    if (SQLITE_OK != sqlite3_open(FILE_PATH, &db)) {
        fprintf(stderr, " [!] - Error: Failed to open database!...\n");
        return false;
    }
    fprintf(stdout, " [$] - Database created successfully.\n");

    if (!insertQuizData(db, Science, sizeof(Science) / sizeof(*Science), "Science") ||
        !insertQuizData(db, Sports, sizeof(Sports) / sizeof(*Sports), "Sports") ||
        !insertQuizData(db, GeneralKnowledge, sizeof(GeneralKnowledge) / sizeof(*GeneralKnowledge), "GeneralKnowledge")) {
        fprintf(stderr, " [!] - Error: Failed to insert data to database!...\n");
        sqlite3_close(db);
        return false;
    }
    sqlite3_close(db);

    account_t *defaultPlayer = (account_t *)calloc(sizeof(account_t), 2);
    if (NULL == defaultPlayer) {
        fprintf(stderr, " [!] - Error: Memory allocation failed!...\n");
        return false;
    }

    strcpy(defaultPlayer->name, "John Alvin");
    strcpy(defaultPlayer->surname, "Doe");
    strcpy(defaultPlayer->username, "Johndoe_11");
    strcpy(defaultPlayer->password, "avjohn1234");
    strcpy(defaultPlayer->pId, "p11111111111");
    defaultPlayer->scores.score = 980;
    if (!insertPlayerData(defaultPlayer)) {
        fprintf(stderr, "[!] - Error populating to game db.\n");
        return false;
    }
    free(defaultPlayer);
    return true;
}
