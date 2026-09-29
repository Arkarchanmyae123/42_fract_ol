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

# Burmese 

# 🌌 42_fract_ol

42 School သင်ရိုးညွှန်းတမ်းအတွက် ရေးသားထားတဲ့ Graphical rendering ပရောဂျက်တစ်ခု ဖြစ်ပါတယ်။ ဒီပရောဂျက်က သင်္ချာနည်းအရ တွက်ချက်ဖန်တီးထားတဲ့ Fractals တွေ—အထူးသဖြင့် **Mandelbrot** နဲ့ **Julia** sets တွေကို—Standard C နဲ့ MiniLibX graphics library အသုံးပြုပြီး ပုံဖော်ပေးဖို့ အဓိကထားပါတယ်။

## 📊 Repository ဖွဲ့စည်းပုံ

ဒီပရောဂျက်ကို C language နဲ့ အပြည့်အဝ ရေးသားထားပြီး Compilation မြန်ဆန်စေဖို့ Makefile ကို အသုံးပြုထားပါတယ်။ Repository ကို အောက်ပါ အဓိက အစိတ်အပိုင်းတွေနဲ့ စနစ်တကျ ခွဲခြား (Modularized) ဖွဲ့စည်းထားပါတယ်-

*   **`minilibx-linux`**: Git submodule အနေနဲ့ လုံခြုံစွာ ထည့်သွင်းချိတ်ဆက်ထားတဲ့ 42 ရဲ့ စံသတ်မှတ်ချက်ဝင် Graphics library ဖြစ်ပါတယ်။
*   **`.gitmodules`**: MiniLibX submodule ကို ခြေရာခံပြီး ချိတ်ဆက်ပေးတဲ့ Configuration ဖိုင် ဖြစ်ပါတယ်။
*   **Fractal Logic Files**: Fractals တွေအတွက် ကနဦးသတ်မှတ်ခြင်း (Initialization)၊ သင်္ချာနည်းကျ ပုံဖော်ခြင်းနဲ့ အသုံးပြုသူရဲ့ Input တွေကို လက်ခံစီမံပေးတဲ့ အဓိက C ဖိုင်တွေ (`julia.c`, `julia_render.c`, `julia_event.c` စသည်) ဖြစ်ပါတယ်။
*   **`header.h`**: လိုအပ်တဲ့ Struct definitions တွေ (ဥပမာ- fractal data, MiniLibX pointers) နဲ့ Function prototypes တွေ ပါဝင်တဲ့ အဓိက Header ဖိုင် ဖြစ်ပါတယ်။
*   **`Makefile`**: Source code တွေကို Compile လုပ်ဖို့နဲ့ MiniLibX library ကို လင့်ခ်ချိတ်ပေးဖို့ စည်းမျဉ်းတွေ ပါဝင်တဲ့ Build script ဖြစ်ပါတယ်။

## 🚀 စတင်အသုံးပြုခြင်း

### လိုအပ်ချက်များ (Prerequisites)
*   GCC compiler
*   Make
*   X11 development libraries (Linux စနစ်များတွင် MiniLibX အတွက် လိုအပ်ပါသည်)

### ထည့်သွင်းခြင်းနှင့် Compile လုပ်ခြင်း (Installation & Compilation)

ဒီ Repository မှာ MiniLibX အတွက် Git Submodule ကို အသုံးပြုထားတဲ့အတွက် လိုအပ်တဲ့ ဖိုင်တွေ အားလုံးကို ရယူဖို့ `--recursive` ကိုသုံးပြီး Clone လုပ်ပေးရပါမယ်-

၁။ Submodules များနှင့်တကွ Repository ကို Clone လုပ်ရန်-
   ```bash
   git clone --recursive [https://github.com/Arkarchanmyae123/42_fract_ol.git](https://github.com/Arkarchanmyae123/42_fract_ol.git)
   cd 42_fract_ol
