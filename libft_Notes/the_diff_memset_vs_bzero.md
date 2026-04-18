### 🔍 Why the prototypes are different

```c
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
```

👉 The key difference:

* **`ft_memset` returns a pointer**
* **`ft_bzero` returns nothing (`void`)**

---

### 💡 WHY?

👉 `memset` is designed to be **chainable / reusable in expressions**

Example:

```c
char *ptr = ft_memset(buffer, 'A', 10);
```

👉 You can immediately reuse the returned pointer.

---

👉 `bzero` is just a **simple utility**

* It only *does the action*
* No need to return anything

So:

* `memset` → flexible, general-purpose
* `bzero` → specific, minimal

---

### 🧠 Analogy

Think of memory like a **whiteboard**

---

### 🟢 `memset`

👉 Like a **marker you can reuse**

* You clean the board (or write on it)
* Then you **keep the marker in your hand** (returned pointer)

```c
ptr = memset(board, 'A', 10);
```

👉 “I did the job AND I give you the tool back”

---

### 🔵 `bzero`

👉 Like a **cleaning action only**

* You wipe the board
* You **don’t care about getting anything back**

```c
bzero(board, 10);
```

👉 “I did the job, that’s it”

---

### ⚠️ Important truth

👉 You **can still use the memory after `bzero`**
It’s not about that.

The difference is ONLY:

* `memset` → returns pointer (flexible)
* `bzero` → no return (simpler)

---

### 🧠 Why do we use a pointer here?

👉 Because we want to **modify memory outside the function**

If you pass a normal variable:

```c
int x = 5;
```

You pass `x` → you only get a **copy**

❌ You cannot change the original memory

---

### 🔥 But if you pass a pointer:

```c
int x = 5;
ft_bzero(&x, sizeof(x));
```

👉 Now you give:

* the **address of x**
* so the function can go **directly to memory**

---

### 💡 Key idea

👉 A pointer = **an address of memory**

👉 `void *s` means:

> “Give me the starting address of a memory block”

---

### 🧠 Why we CAST it

```c
(unsigned char *)s
```

👉 Because:

* `void *` → has **no type**, you cannot index it
* We need something we can do:

```c
ptr[i]
```

👉 So we convert it to:

* a type that represents **1 byte**
* → `unsigned char *`

---

### ⚡ Why pointer helps here

Because now we can do:

```c
ptr[0] = 0;
ptr[1] = 0;
ptr[2] = 0;
...
```

👉 We are literally walking through memory byte by byte

---

### 🧠 Simple mental model

* Pointer = GPS location
* `bzero` = go there and **wipe N bytes**

---

