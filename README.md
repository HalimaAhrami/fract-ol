# fract-ol
---

# **Fract’ol – Computer Graphics Fractals**
**Language:** C
**Libraries:** MiniLibX, libft (optional), math library

---

## **Table of Contents**

1. [Foreword](#foreword)
2. [Introduction](#introduction)
3. [Objectives](#objectives)
4. [Common Instructions](#common-instructions)
5. [AI Instructions](#ai-instructions)
6. [Mandatory Part](#mandatory-part)

   * [Rendering](#rendering)
   * [Graphic Management](#graphic-management)
7. [Bonus Part](#bonus-part)
8. [Submission & Peer-Evaluation](#submission--peer-evaluation)

---

## **Foreword**

**Fract’ol** is a computer graphics project that allows users to generate and explore fractals.

> ⚠ Note: This project has **no relation to hydraulic fracturing**.

Fractals are mathematical objects whose patterns remain consistent at every scale. Examples in nature include the Romanesco cabbage.

Your goal: create beautiful fractals and explore them interactively.

---

## **Introduction**

* Fractals were first studied by **Benoit Mandelbrot** in 1974.
* The word “fractal” comes from Latin *fractus*, meaning “broken” or “fractured”.
* A fractal can be a curve, surface, or shape that repeats its pattern infinitely.
* This project helps you learn:

  * MiniLibX library for graphics
  * Complex numbers in mathematics
  * Event handling (keyboard/mouse)
  * Graphics optimization

---

## **Objectives**

* Build a **small computer graphics program** in C.
* Render **Mandelbrot** and **Julia** fractals.
* Implement **zoom and color depth** effects.
* Practice **programming standards** and proper memory management.
* Learn to handle **mouse and keyboard events** for interactive exploration.

---

## **Common Instructions**

* **Language:** C, following the **Norm** coding standard.
* Handle memory correctly (**no leaks, no crashes**).
* Use a **Makefile** with rules: `all`, `clean`, `fclean`, `re`, and `$(NAME)`.
* Include `libft` if used; compile it from its Makefile.
* Test your program before submission.
* Only submit **required files** in the Git repository.

---

## **AI Instructions**

* AI can **assist** but you must understand and verify all results.
* ✅ Good practice: use AI for ideas, testing, and code snippets.
* Always do **peer review** and check your work critically.

---

## **Mandatory Part**

### **Program Name**

`fractol`

### **Files to Submit**

* `Makefile`
* `*.c` and `*.h` files

### **Functionality**

* Display **Mandelbrot** and **Julia** sets.
* Zoom in/out using **mouse wheel**.
* Accept command-line arguments for fractal type and rendering options.
* Use multiple colors to highlight **depth** and **pattern**.
* Window management:

  * Smooth switching/minimizing
  * Press `ESC` or close window to exit
* Use **MiniLibX images** for rendering.
* **No global variables** allowed.

---

### **Rendering**

* Julia sets can vary depending on **parameters passed via command line**.
* If **invalid or missing parameters**, program displays help and exits.
* Zoom is nearly **infinite**, limited only by computer resolution.
* Colors reveal fractal depth; **psychedelic color effects** are encouraged.

---

### **Graphic Management**

* Program displays the fractal in a **window**.
* Window must remain **responsive** at all times.
* Closing the window or pressing **ESC** exits cleanly.
* Use **MiniLibX image functions** to render pixels.

---

## **Bonus Part**

* Add **extra fractal types**.
* Zoom follows **actual mouse position**.
* Allow **moving view** using arrow keys.
* Shift **color ranges dynamically**.

> Bonus evaluated **only if mandatory part is perfect**.

---

## **Submission & Peer-Evaluation**

* Submit via **Git repository** only.
* Ensure all mandatory files are **correctly named**.
* Minor modifications may be requested during evaluation, such as:

  * Adjusting a display
  * Modifying a function
  * Updating data structures

---
