# Компилятор 
CC = gcc

# Пути до используемых папок
OBJ_DIR = obj
GCOV_OBJ_DIR = obj/gcov
TESTS_OBJ_DIR = obj/tests
TEST_DIR = TESTS
CORE_DIR = CORE
REPORT_DIR = report

#Цель и название исполняемого файла для тестов
TARGET = test

#Цель и название исполняемого файла для отчета о покрытии
REPORT = gcov_report

# Имя статичной библиотеки
STATIC_LIBRARY = s21_matrix.a

# Статическая библиотека, но с флагами для отчета покрытия
STATIC_LIBRARY_GCOV = s21_matrix_gcov.a

CFLAGS = -Wall -Werror -Wextra -c -std=c11 -pedantic

# Флаги для lcov
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

# Дополнительные библиотеки для линковки
ADDITIONAL_FLAGS =-lcheck -lsubunit -lm

# Дополнительные библиотеки для линковки c отчетом о покрытии
LIBS_GCOV = $(ADDITIONAL_FLAGS) -lgcov

# Заполняем переменные со списком директорий, исходных и исполняемых файлов
ALL_CORE_DIRS = $(shell find $(CORE_DIR) -type d)
ALL_CORE_C = $(notdir $(shell find $(ALL_CORE_DIRS) -maxdepth 1 -name "*.c"))
ALL_CORE_H = $(shell find $(ALL_CORE_DIRS) -maxdepth 1 -name "*.h")
MAIN_H = $(shell find . -maxdepth 1 -name "*.h")
ALL_H = $(ALL_CORE_H) $(MAIN_H)
ALL_CORE_O = $(ALL_CORE_C:%.c=%.o)

ALL_TESTS_DIRS = $(shell find $(TEST_DIR) -type d)
ALL_TESTS_C = $(notdir $(shell find $(ALL_TESTS_DIRS) -maxdepth 1 -name "*.c"))
ALL_TESTS_H = $(shell find $(ALL_TESTS_DIRS) -maxdepth 1 -name "*.h")
ALL_TESTS_O = $(addprefix $(TESTS_OBJ_DIR)/, $(notdir $(ALL_TESTS_C:%.c=%.o)))

ALL_GCOV_O = $(addprefix $(GCOV_OBJ_DIR)/, $(notdir $(ALL_CORE_C:.c=.o)))

# Набор всех файлов для cppcheck и clang-format
ALL_C_H_FILES = $(shell find . -type f | grep "\.(c|h)$$" -E)

# Указываем список каталогов, в которых make выполняет поиск
vpath %.c $(ALL_CORE_DIRS) : $(ALL_TESTS_DIRS)
vpath %.o $(OBJ_DIR)

# Далее идут все цели
all: $(TARGET) $(REPORT)

m:  $(STATIC_LIBRARY) $(ALL_TESTS_O)
	$(clean)
	$(CC) main.c $(STATIC_LIBRARY) $(ADDITIONAL_FLAGS)
	./a.out

$(TARGET): $(OBJ_DIR) $(TESTS_OBJ_DIR) $(STATIC_LIBRARY) $(ALL_TESTS_O)
	$(CC) $(ALL_TESTS_O) $(STATIC_LIBRARY) $(ADDITIONAL_FLAGS) -o $(TARGET)
	./$(TARGET)

$(REPORT): $(GCOV_OBJ_DIR) $(TESTS_OBJ_DIR) $(REPORT_DIR) $(STATIC_LIBRARY_GCOV) $(ALL_TESTS_O) $(ALL_H) $(ALL_TESTS_H)
	$(CC) $(ALL_TESTS_O) $(STATIC_LIBRARY_GCOV) $(LIBS_GCOV) -o ./$(REPORT)
	echo "\n-------------------------------------------------------------------------------------------------\n"
	./$(REPORT)
	gcov -o $(GCOV_OBJ_DIR) $(ALL_CORE_C)
	lcov -b ./ -d $(GCOV_OBJ_DIR) --gcov-tool /usr/bin/gcov -c -o output.info
	genhtml -o $(REPORT_DIR) output.info
	rm *.c.gcov output.info
	xdg-open $(REPORT_DIR)/index.html

$(STATIC_LIBRARY): $(OBJ_DIR) $(TESTS_OBJ_DIR) $(ALL_CORE_O) $(ALL_H)
	ar rc $(STATIC_LIBRARY) $(addprefix $(OBJ_DIR)/, $(ALL_CORE_O))
	ranlib $(STATIC_LIBRARY)

$(STATIC_LIBRARY_GCOV): $(GCOV_OBJ_DIR) $(TESTS_OBJ_DIR) $(ALL_GCOV_O) $(ALL_H)
	ar rc $(STATIC_LIBRARY_GCOV) $(ALL_GCOV_O)
	ranlib $(STATIC_LIBRARY_GCOV)

%.o: %.c $(ALL_H) $(ALL_TESTS_H)
	$(CC) $(CFLAGS) -o $(addprefix $(OBJ_DIR)/, $@) $<

$(GCOV_OBJ_DIR)/%.o : %.c $(ALL_H) $(ALL_TESTS_H)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -o $@ $<

$(TESTS_OBJ_DIR)/%.o : %.c $(ALL_H) $(ALL_TESTS_H)
	$(CC) $(CFLAGS) -o $@ $<

$(REPORT_DIR):
	mkdir -p $(REPORT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(GCOV_OBJ_DIR):
	mkdir -p $(GCOV_OBJ_DIR)

$(TESTS_OBJ_DIR):
	mkdir -p $(TESTS_OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(REPORT_DIR)
	rm -f *.a *.o
	rm -f *.c.gcov *.gcno *.gcov *.gcda output.info
	rm -f ./$(REPORT) ./$(TARGET)

rebuild: clean all

clang:
	clang-format -style=Google -n *.h $(ALL_C_H_FILES)

check:
	clang-format -style=Google -i *.h $(ALL_C_H_FILES)

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(ALL_C_H_FILES)

valgrind:
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./$(TARGET)

