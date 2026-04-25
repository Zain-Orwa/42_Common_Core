# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    04_the_substr_function.md                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/25 17:43:51 by zorwa             #+#    #+#              #
#    Updated: 2026/04/25 17:44:08 by zorwa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 📌 `ft_substr` — Questions & Insights

## 🧠 What does the function do?

> Extracts a substring from a string.

* `start` → index to begin from
* `len` → number of characters to take

👉 Not “from–to” → it is **start + length**

---

## ❓ Q1: Can `start` be a character like `'o'`?

❌ No

* `'o'` = ASCII value (≈111)
* `start` must be an **index**

✔ Correct:

```c
start = 4; // position of 'o'
```

---

## ❓ Q2: If `start >= strlen(s)` what should we return?

❌ Not `NULL`
✅ Return an **empty string `""`**

👉 Because:

* Nothing failed
* You just asked for something outside the string

✔ Must still:

```c
malloc(1);
str[0] = '\0';
```

---

## ❓ Q3: What if `start == strlen(s)`?

👉 Same result as above

* You are pointing at `'\0'`
* Nothing to copy

✔ Return:

```c
""
```

---

## ❓ Q4: What if `len` is too big?

Example:

```c
ft_substr("Hello", 2, 100)
```

👉 You **don’t go out of bounds**

✔ You take only what’s available:

```c
"llo"
```

---

## ❓ Q5: What is `min(len, remaining)`?

👉 Take the **smaller value**

```c
actual_len = (len < remaining) ? len : remaining;
```

C has **no built-in `min`**, you implement it yourself.

---

## ❓ Q6: Why not do `remain - len`?

❌ Wrong logic

Example:

```c
remain = 8
len = 5
```

```c
remain - len = 3 ❌
```

✔ Correct:

```c
actual_len = 5
```

👉 You want how much to copy, not what’s left after copying.

---

## ❓ Q7: `<` vs `<=` — does it matter?

```c
(len < remain) ? len : remain;
(len <= remain) ? len : remain;
```

👉 No difference when `len == remain`

✔ Both give same result

---

## ❓ Q8: If `len == 0`?

👉 Return empty string

✔ Still:

```c
malloc(1);
str[0] = '\0';
```

---

## ❓ Q9: What size should we `malloc`?

❌ Not always `len`

✔ Correct:

```c
sub_len = min(len, strlen(s) - start);
malloc(sub_len + 1);
```

👉 `+1` for `'\0'`

---

## ❓ Q10: Why `sub[j] = '\0'` and not `sub[start + j]`?

👉 Because `sub` starts at index `0`

❌ Wrong:

```c
sub[start + j] = '\0';
```

✔ Correct:

```c
sub[j] = '\0';
```

---

## ❓ Q11: Can we use ternary `?:` in 42?

✅ Yes

✔ Good:

```c
sub_len = (len > sub_len) ? sub_len : len;
```

❌ Avoid overly complex nested ternaries

---

## ❓ Q12: Do we need to handle `NULL` input?

👉 Optional but good practice

```c
if (!s)
	return (NULL);
```

---

## ❓ Q13: Why use `ft_memcpy` instead of loop?

👉 Cleaner and faster

```c
ft_memcpy(sub, s + start, sub_len);
```

---

## 🔑 Final Mental Model

1. If `start >= strlen(s)` → return `""`
2. Else:

   * compute remaining: `strlen(s) - start`
   * take min(`len`, remaining)
3. Allocate `+1`
4. Copy
5. Null terminate

---

## ✅ Final Clean Version

```c
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	sub_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	sub_len = s_len - start;
	sub_len = (len > sub_len) ? sub_len : len;
	sub = malloc(sub_len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, sub_len);
	sub[sub_len] = '\0';
	return (sub);
}
```

