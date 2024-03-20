cmake_minimum_required(VERSION 3.27)
project(QuizBit C)

set(CMAKE_C_STANDARD 23)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra -pedantic")

find_package(SQLite3 REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(main main.c
        utils/utils.c
        core/access.c
        core/auth.c
        core/database.c)

target_link_libraries(main PUBLIC sqlite3 crypto ssl)