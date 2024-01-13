CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -lsqlite3 -lssl -lcrypto

SRCDIR = sources
COREDIR = core
SRCS = main.c $(SRCDIR)/src.c $(COREDIR)/access.c $(COREDIR)/auth.c $(COREDIR)/database/db.c #$(COREDIR)/database/questions.c

TARGET = main

ifeq ($(OS),Windows_NT)
	TARGET_EXTENSION = .exe
	RM = del /p
	RMF = del /Q
	APP = Drmemory
	APPFLAGS = -check_uninitialized -check_leaks
else
	TARGET_EXTENSION =
	RM = rm -f -i
	RMF = rm -rf
	APP = valgrind
	APPFLAGS = --leak-check=full --track-origins=yes --undef-value-errors=yes --show-leak-kinds=all
endif

$(TARGET)$(TARGET_EXTENSION): $(SRCS)
	@$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

run: $(TARGET)$(TARGET_EXTENSION)
	@./$(TARGET)$(TARGET_EXTENSION)
#setup:
memcheck: $(TARGET)$(TARGET_EXTENSION)
	@$(APP) $(APPFLAGS) ./$(TARGET)$(TARGET_EXTENSION)

clean:
	@$(RM) $(TARGET)$(TARGET_EXTENSION) $(COREDIR)/database/quiz.db $(COREDIR)/database/game_database.db
forceclean:
	@$(RMF) $(TARGET)$(TARGET_EXTENSION) $(COREDIR)/database/quiz.db $(COREDIR)/database/game_database.db