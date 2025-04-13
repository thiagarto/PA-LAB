# Nombre del ejecutable
TARGET = programa

# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -Wall -std=c++17

# Archivos fuente y objetos
SRC = main.cpp Informacion.cpp Estudiante.cpp Libro.cpp PaginaWeb.cpp chatGPT.cpp DTFecha.cpp DTInfoEstudiante.cpp
OBJ = $(SRC:.cpp=.o)

# Regla principal
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Regla para compilar cada archivo fuente a objeto
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJ) $(TARGET)

