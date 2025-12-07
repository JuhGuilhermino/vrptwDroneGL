# Compilador C++
CXX = g++

# Opções de compilação
CXXFLAGS = -Wall -std=c++17

# Nome do executável
TARGET = main

# Fontes do projeto
SOURCES = src/main.cpp src/Experiment.cpp src/Instance.cpp src/FileUtilities.cpp

# Objetos gerados a partir dos fontes
OBJECTS = $(SOURCES:.cpp=.o)

# Regra de compilação
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar cada arquivo fonte em um objeto
main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

experiment.o: src/Experiment.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

instance.o: src/Instance.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

file.o: src/FileUtilities.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar os objetos e o executável
clean:
	rm -f $(OBJECTS) $(TARGET)

# Regra padrão
all: $(TARGET)

.PHONY: clean all