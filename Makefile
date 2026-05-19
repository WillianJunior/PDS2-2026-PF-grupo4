CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude --coverage

ARQUIVOS_SRC = $(wildcard src/*.cpp)
ARQUIVOS_TESTE = $(wildcard tests/*.cpp)

TODOS_ARQUIVOS = $(ARQUIVOS_SRC) $(ARQUIVOS_TESTE)

test: $(TODOS_ARQUIVOS)
	$(CXX) $(CXXFLAGS) $(TODOS_ARQUIVOS) -o test_runner
	./test_runner
	gcovr

clean:
	@rm -f test_runner *.gcda *.gcno
