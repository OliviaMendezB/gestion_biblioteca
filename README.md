# Gestión Biblioteca 

## Descripción

Este proyecto universitario implementa un sistema de gestión de una biblioteca en C++17:

- Control de libros y préstamos
- Array estático para libros (máx. 50)
- Array dinámico redimensionable para préstamos
- Búsqueda rápida por ISBN mediante hash map
- Guardado persistente en archivo `data/biblioteca.txt`
- Ranking de libros más prestados
- Modularizado en `biblioteca` y `prestamos`

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

## Funcionalidades

- **Prestar libro**: controla que el usuario no tenga ya el mismo libro prestado y que haya ejemplares disponibles  
- **Devolver libro**: elimina el préstamo y actualiza la biblioteca  
- **Mostrar biblioteca**: lista todos los libros con ejemplares totales y prestados  
- **Mostrar préstamos**: lista todos los préstamos actuales  
- **Ranking**: muestra los libros más prestados  

## Cómo usar

1. Abrir proyecto en **Visual Studio 2022**  
2. Compilar y ejecutar  
3. Usar el menú para interactuar con el sistema:  
   - 1. Prestar  
   - 2. Devolver  
   - 3. Mostrar biblioteca  
   - 4. Mostrar préstamos  
   - 5. Ranking  
   - 6. Salir  

Todos los cambios se guardan automáticamente en `data/biblioteca.txt`.

## Habilidades demostradas
 Programación en **C++17**  
- Estructuras de datos: arrays estáticos y dinámicos  
- Manejo de punteros y memoria dinámica  
- Modularización y separación de headers/código  
- Persistencia de datos en archivos  

## Autor: Olivia Mendez Blanco
