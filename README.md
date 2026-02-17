# Gestión Biblioteca 

## Descripción
Proyecto en C++ para la gestión de préstamos de libros en una biblioteca.  
El sistema permite:

- Registrar libros con ISBN, título, número de ejemplares y número de ejemplares prestados.  
- Gestionar préstamos de libros por usuarios identificados por DNI.  
- Devolver libros y actualizar los préstamos.  
- Consultar la biblioteca completa y los préstamos activos. 
- Índice hash para búsquedas rápidas por ISBN.
- Ranking de libros más prestados.  
- Persistencia en archivo `biblioteca.txt` para mantener datos entre ejecuciones.  

El proyecto está optimizado para prácticas de programación orientada a objetos y estructuras de datos.

## Estructura del proyecto
Gestión Biblioteca/
├─ main.cpp
├─ biblioteca.cpp
├─ prestamos.cpp
├─ biblioteca.h
├─ prestamos.h
├─ biblioteca.txt
├─ README.md
├─ Gestión Biblioteca.sln
├─ Gestión Biblioteca.vcxproj

- `biblioteca.h/cpp` → Definición de clases `tLibro` y `tBiblioteca`, funciones de carga, guardado, ranking y búsqueda rápida.  
- `prestamos.h/cpp` → Definición de clases `tPrestamo` y `tPrestamos`, gestión de array dinámico, inserción, eliminación y visualización de préstamos.  
- `main.cpp` → Menú interactivo para la gestión de la biblioteca.  
- `biblioteca.txt` → Datos persistentes de la biblioteca.  

## Funcionalidades

- **Prestar libro**: controla que el usuario no tenga ya el mismo libro prestado y que haya ejemplares disponibles  
- **Devolver libro**: elimina el préstamo y actualiza la biblioteca  
- **Mostrar biblioteca**: lista todos los libros con ejemplares totales y prestados  
- **Mostrar préstamos**: lista todos los préstamos actuales  
- **Ranking**: muestra los libros más prestados  

## Cómo usar

1. Abrir el proyecto en Visual Studio 2022.  
2. Ejecutar el programa.
3. Usar el menú para:
   - Prestar libros
   - Devolver libros
   - Mostrar biblioteca
   - Mostrar préstamos
   - Consultar ranking de libros más prestados
   - Salir del programa
4. Los cambios se guardan automáticamente en `biblioteca.txt`.  

## Mejoras implementadas

- Búsqueda rápida de libros por ISBN: Se creó un índice hash (unordered_map) que permite localizar cualquier libro de la biblioteca en tiempo casi constante,
  mejorando la eficiencia frente a una búsqueda lineal.
- Ranking de libros más prestados: Se agregó una función que genera un ranking de popularidad de los libros según el número de préstamos, lo que permite identificar
  rápidamente los libros más solicitados.
- Gestión dinámica de préstamos: La lista de préstamos utiliza memoria dinámica que se redimensiona automáticamente, permitiendo manejar cualquier número de préstamos sin desperdiciar memoria.
- Persistencia de datos: Todos los cambios realizados en los libros y préstamos se guardan automáticamente en el archivo biblioteca.txt, manteniendo la información entre ejecuciones del programa.

## Habilidades demostradas
- Estructuras de datos: arrays estáticos y dinámicos  
- Manejo de punteros y memoria dinámica  
- Modularización y separación de headers/código  
- Persistencia de datos en archivos  

## Autor: Olivia Mendez Blanco
