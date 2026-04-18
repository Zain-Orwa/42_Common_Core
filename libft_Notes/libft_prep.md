# 🚀 42 Libft: Ultimate Preparation & Survival Guide

*Your roadmap from “it works” → “it passes everything (Norm + Moulinette + Humans)”*

---

## 📅 Introduction: What Libft REALLY is

**Libft is not just a project.**
It is your **foundation layer** for everything at 42.

You are building:

* A **static library** → `libft.a`
* A **toolbox of reusable functions** used in:

  * `ft_printf`
  * `get_next_line`
  * `push_swap`
  * `minishell`
  * and more...

👉 Think like this:

> “Every bug I leave here will follow me for months.”

---

## 🧠 The Mindset Shift

Before Libft:

* “If it works, it's fine.”

After Libft:

* Memory-safe
* Norm-compliant
* Same behavior as libc
* No leaks
* All edge cases handled

👉 You are writing **production-level C**, not exercises.

---

## 🏗 How Libft Works (Conceptually)

Your project is built like this:

```
Your Program
     ↓
#include "libft.h"
     ↓
libft.a
     ↓
Your Functions
```

👉 Your `libft.h` is the **interface**
👉 Your `.c` files are the **implementation**

---

## ⚠️ The Real Pitfalls (Where Students Fail)

---

### 💀 1. `ft_split` = Memory Leak Machine

#### The Problem

`ft_split` allocates:

* an array of pointers
* each word separately

If one allocation fails → **everything before leaks**

#### Correct Pattern

```c
char **free_all(char **arr, int i)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (NULL);
}
```

👉 Always clean everything before returning `NULL`

---

### ⚠️ 2. `ft_memcpy` vs `ft_memmove`

#### `ft_memcpy`

* ❌ Undefined behavior if memory overlaps

#### `ft_memmove`

* ✅ Must handle overlap safely

#### Core Logic

```c
if (dst > src)
	copy backwards;
else
	copy forwards;
```

👉 This is a **classic failure point**

---

### ⚠️ 3. `unsigned char` Trap

#### Problem

```c
char c = 200; // may become negative
```

#### Fix

```c
(unsigned char *)ptr
```

👉 Always cast when working with raw memory

Used in:

* `ft_memcpy`
* `ft_memset`
* `ft_memcmp`
* `ft_memchr`

---

### ⚠️ 4. `ft_atoi` Edge Cases

You must handle:

* spaces (`' '`, `\t`, `\n`, etc.)
* multiple signs (`+` / `-`)
* stopping at first invalid character

#### Example

```c
"--123" → incorrect / must be handled properly
```

---

### ⚠️ 5. `ft_strlcpy` / `ft_strlcat`

👉 Most misunderstood functions

Rule:

* Return = **length of source (or intended total length)**
* Even if truncation happens

---

### ⚠️ 6. NULL Safety

Always protect your functions:

```c
if (!ptr)
	return (NULL);
```

Important for:

* `ft_substr`
* `ft_strjoin`
* `ft_split`

---

## 🛠 Strategic Roadmap

---

### 🟢 Phase 1 — Libc Functions (FOUNDATION)

Goal: **Exact behavior replication**

Functions:

```
ft_isalpha
ft_isdigit
ft_isalnum
ft_isascii
ft_isprint
ft_strlen
ft_memset
ft_bzero
ft_memcpy
ft_memmove
ft_strlcpy
ft_strlcat
ft_toupper
ft_tolower
ft_strchr
ft_strrchr
ft_strncmp
ft_memchr
ft_memcmp
ft_strnstr
ft_atoi
```

👉 Strategy:

* Compare output with real libc

---

### 🟡 Phase 2 — Core Logic + Memory

Goal: **Safe malloc + clean logic**

Functions:

```
ft_calloc
ft_strdup
ft_substr
ft_strjoin
ft_strtrim
ft_split
ft_itoa
ft_strmapi
ft_striteri
ft_putchar_fd
ft_putstr_fd
ft_putendl_fd
ft_putnbr_fd
```

👉 Focus:

* Memory allocation
* Clean structure
* Helper functions

---

### 🔵 Phase 3 — Bonus (Linked Lists)

Structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

Functions:

```
ft_lstnew
ft_lstadd_front
ft_lstsize
ft_lstlast
ft_lstadd_back
ft_lstdelone
ft_lstclear
ft_lstiter
ft_lstmap
```

---

### 💣 Critical Trap: `ft_lstclear`

Correct logic:

```c
del(node->content);
free(node);
```

👉 Never forget to free the **content**, not just the node

---

## 🔍 Testing Strategy

---

### 1. Compare with libc

```c
printf("%d\n", ft_strlen("abc"));
printf("%d\n", strlen("abc"));
```

---

### 2. Edge Cases Checklist

Always test:

* `NULL`
* empty string `""`
* single character
* long strings
* overlapping memory

---

### 3. Memory Check

Tools:

* `valgrind`
* `leaks` (Mac)

Goal:

```
0 leaks, 0 errors
```

---

## 🧠 Mental Model

Think like this:

```
Input → Your Function → Output
        ↓
   Must match libc EXACTLY
```

---

## 💡 Top Pro Tips

---

### 1. Norm First, Not Last

Run constantly:

```bash
norminette
```

👉 Fix errors immediately

---

### 2. Small Functions Win

* Easier debugging
* Easier norm compliance
* Better reuse

---

### 3. Never Trust `malloc`

```c
if (!ptr)
	return (NULL);
```

---

### 4. Write Helpers Early

Examples:

* word counter
* string duplicator
* memory cleaner

👉 Saves time later

---

### 5. Think Before Coding

Ask:

* What if input is `NULL`?
* What if size = 0?
* What if `malloc` fails?

---

## 🧭 Final Advice

Libft is NOT about:

* speed
* tricks

👉 It IS about:

* correctness
* discipline
* clean thinking

---

