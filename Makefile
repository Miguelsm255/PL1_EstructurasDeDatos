# Makefile básico para un proyecto C++

# Nombre del ejecutable
TARGET = prueba

# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++23

# Archivos fuente
SRCS = $(wildcard **.cpp)

# Regla por defecto
all: $(TARGET)

# Regla para compilar el ejecutable directamente desde los archivos fuente
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para limpiar archivos generados
clean:
	rm -f $(TARGET)

.PHONY: all clean
