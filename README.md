# 🌌 42_fract_ol

A graphical rendering project developed for the 42 School curriculum. This project focuses on rendering mathematically generated fractals—specifically the **Mandelbrot** and **Julia** sets—using standard C and the MiniLibX graphics library. 

## 📊 Repository Composition

The project is built entirely in C and utilizes a Makefile for efficient compilation. The repository is modularized into the following core components:

*   **`minilibx-linux`**: The standard 42 graphics library, securely integrated as a Git submodule.
*   **`.gitmodules`**: The configuration file that maps and tracks the MiniLibX submodule.
*   **Fractal Logic Files**: Core C files (such as `julia.c`, `julia_render.c`, `julia_event.c`, etc.) that handle initialization, mathematical rendering, and user input hooks for the fractals.
*   **`header.h`**: The central header file containing necessary struct definitions (e.g., fractal data, MiniLibX pointers) and function prototypes.
*   **`Makefile`**: The build script containing rules to compile the source code and link the MiniLibX library.

## 🚀 Getting Started

### Prerequisites
*   GCC compiler
*   Make
*   X11 development libraries (required by MiniLibX on Linux systems)

### Installation & Compilation

Because this repository uses a Git Submodule for MiniLibX, you must clone it recursively to pull all required files:

1. Clone the repository with submodules:
   ```bash
   git clone --recursive [https://github.com/Arkarchanmyae123/42_fract_ol.git](https://github.com/Arkarchanmyae123/42_fract_ol.git)
   cd 42_fract_ol
