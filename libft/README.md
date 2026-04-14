```c
/* ************************************************/
/*                                                */
/*   File:    README.md                           */
/*   Author:  Zain Orwa                           */
/*   Created: 2026/04/14 13:48:40                 */
/*   Updated: 2026/04/14 13:48:40                 */
/*                                                */
/* ************************************************/

# 42 Libft: Ultimate Preparation & Survival Guide
*Compiled as a roadmap for the 42 Common Core Journey (Version 16.7).*

---

## 📅 Introduction: Starting the Common Core
Starting with **Libft** is a transition from "coding that works" to "coding for production." You are building a static library (`libft.a`)—a collection of your own tools that you will use for almost every future project at 42 (like *ft_printf*, *get_next_line*, and *minishell*).

### The Version Check
As of 2026, **Version 16.7** is the latest and current standard for the 42 Network. It is optimized for **Norminette v3+** and follows the standard curriculum split:
* **Part 1:** Re-coding standard Libc functions.
* **Part 2:** Additional utility functions (strings, memory, numbers).
* **Bonus:** Linked list manipulation.

---

## 🏗 The Build Process: From .c to .a
To build your library, you aren't just compiling a program; you are creating an **archive**.

1.  **Compilation:** Each function (`ft_strlen.c`, `ft_memset.c`, etc.) is compiled into an object file (`.o`).
    * Example: `cc -Wall -Wextra -Werror -c ft_strlen.c -o ft_strlen.o`
2.  **Archiving:** The `ar` command bundles all those `.o` files into one library file.
    * Example: `ar rcs libft.a *.o`
3.  **The Header:** Your `libft.h` acts as the interface. Any program using your library just needs to `#include "libft.h"` to "see" your functions.



---

## ⚠️ The Hidden Pitfalls (Why Most Students Fail)

Through a "deep search" of common evaluation failures, these are the "silent killers" you must avoid:

### 1. The `ft_split` Memory Leak
This is the #1 reason for a 0 on Libft. `ft_split` performs "nested" allocations (an array of pointers, then a string for each pointer).
* **The Trap:** If you successfully allocate 10 words, but the 11th `malloc` fails, simply returning `NULL` leaves the first 10 words floating in the Heap.
* **The Fix:** You **must** create a cleanup helper to `free` every previously allocated string before finally freeing the main array pointer and returning `NULL`.



### 2. `ft_memmove` vs. `ft_memcpy`
* **The Difference:** `ft_memcpy` assumes the source and destination do not overlap. `ft_memmove` **must** handle overlaps safely.
* **The Logic:** If the destination starts *inside* the source string, you must copy from **end-to-beginning** (backwards) to avoid overwriting data you haven't moved yet.



### 3. The "Relink" Rule (Makefile)
* **The Failure:** If you run `make` and then immediately run `make` again, the terminal should say *"Nothing to be done"*. 
* **The Trap:** If your Makefile recompiles the files or recreates the `.a` archive a second time, it is a **Relink**. This is an automatic failure in many 42 evaluations.

### 4. Signed vs. Unsigned (The `unsigned char` Trap)
* **The Logic:** Functions like `ft_memset`, `ft_memchr`, and `ft_memcmp` treat memory as raw bytes.
* **The Fix:** In C, a `char` can be signed. To handle values above 127 correctly, you **must** cast your pointers to `unsigned char *` before performing operations.

---

## 🛠 Strategic Roadmap

### Phase 1: The Basics (Libc)
Start here to build momentum. Keep a terminal open with `man <function>` to ensure your behavior matches the original perfectly.
* `ft_isalpha`, `ft_isdigit`, `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_strlcpy`, `ft_strlcat`, `ft_toupper`, `ft_tolower`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_memchr`, `ft_memcmp`, `ft_strnstr`, `ft_atoi`.

### Phase 2: Additional Functions
These require custom logic and careful `malloc` protection.
* `ft_calloc`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`.

### Phase 3: The Bonus (Linked Lists)
Essential for future projects.
* You will define a `t_list` struct in your header.
* **Pitfall:** In `ft_lstclear`, you must use the provided `del` function to free the *content* of the node before freeing the node itself.

---

## 💡 Top 3 Pro-Tips for Tomorrow
1.  **The Header Guard:** Wrap your `libft.h` in `#ifndef LIBFT_H`, `#define LIBFT_H`, and `#endif` immediately so you don't forget.
2.  **Protect Every Malloc:** If `malloc` returns `NULL`, your function should return `NULL` (or handle it) immediately. Never assume memory was granted.
3.  **The "Norm" is Law:** Use the Norminette tool constantly. A single space in the wrong place or a function over 25 lines is an automatic failure.

```
---
