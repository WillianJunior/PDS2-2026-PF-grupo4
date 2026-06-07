CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

COVERAGE_FLAGS = --coverage

SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

ARQUIVOS_SRC = $(wildcard $(SRC_DIR)/*.cpp)
ARQUIVOS_TESTE = $(wildcard $(TEST_DIR)/*.cpp)


#remove o main.cpp do jogo para evitar conflito com o main_tests.cpp
SRC_SEM_MAIN = $(filter-out $(SRC_DIR)/main.cpp, $(ARQUIVOS_SRC))

#compilar apenas com make
all: game

# Regra para criar o diretório build automaticamente se não houver 
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

game: $(ARQUIVOS_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(ARQUIVOS_SRC) -o rpg_game

run: game
	./rpg_game

test: $(SRC_SEM_MAIN) $(ARQUIVOS_TESTE) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(COVERAGE_FLAGS) $(SRC_SEM_MAIN) $(ARQUIVOS_TESTE) -o $(BUILD_DIR)/test_runner
	-./$(BUILD_DIR)/test_runner
	gcovr -e "$(TEST_DIR)/.*"

#a regra foi alterada para find que garante que os arquivos na raiz do projeto não vao ser apagados
clean:
	@rm -f $(BUILD_DIR)
	@find . -type f -name '*.gcda' -delete
	@find . -type f -name '*.gcno' -delete
