# Makefile básico para un proyecto C++

# Nombre del ejecutable
TARGET = main

# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++23 -g

# Archivos fuente y ejecutable
SRCS = $(wildcard src/*.cpp) $(wildcard include/**/*.cpp)

# Regla por defecto
all: $(TARGET)

# Regla para construir el ejecutable
$(TARGET): $(SRCS)
	@echo "Compiling and linking $(TARGET)..."
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

# Regla para limpiar archivos generados
clean:
	rm -f $(TARGET)

.PHONY: all clean
