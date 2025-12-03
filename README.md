# 42 C++ Mini Projects — BigInt, vect2, PolySet

This file gives a short and clear explanation of each project (BigInt, vect2, and PolySet), what they are meant to train, and how to compile and run them.

---

## 📌 BigInt

**Goal:** Implement a class that can store and manipulate integers much larger than what built‑in types (`int`, `long long`) can handle.

### What it covers

* Handling numbers as strings or dynamic arrays
* Operator overloading (`+`, `-`, `*`, comparison operators…)
* Managing sign, carry, and borrowing manually
* Clean class design

### Typical features you implement

* Constructors from `int` or `string`
* Arithmetic operators
* Comparison operators
* Output using `operator<<`

### How to compile

Make sure all `.cpp` and `.hpp` files are in the project folder.

```bash
g++ -Wall -Wextra -Werror *.cpp -o bigint
./bigint
```

---

## 📌 vect2

**Goal:** Build a simple 2D vector class to practice constructors, copying, assignment, and operator overloading.

### What it covers

* Basic class structure
* Canonical form (constructor, copy constructor, assignment operator, destructor)
* Operator overloads (`+`, `-`, `==`)
* Encapsulation and simple math operations

### Typical features

* `x` and `y` integer coordinates
* Addition and subtraction of vectors
* Comparison
* Getter/setter usage

### How to compile

```bash
g++ -Wall -Wextra -Werror *.cpp -o vect2
./vect2
```

---

## 📌 PolySet

This assignment isn’t about geometry or shapes. Instead, it focuses on containers and how to extend them. You’re given a small ecosystem of classes representing “bags” — collections that can hold elements, possibly with duplicates. Some bags store data in arrays, others in binary search trees.

Your job is to add search capabilities to these bags and then use one of them to build a proper mathematical set.

### What you build

#### **searchable_array_bag**

Extends the array‑based bag so it can look for a specific element. The searching logic is simple: walk through the stored items and check if one matches. It still behaves like a bag, but now it knows how to check for membership.

#### **searchable_tree_bag**

Extends the tree‑based bag, using the usual binary‑search‑tree walk to find an element efficiently. This version generally performs better because of the BST structure.

#### **set**

A lightweight wrapper around any searchable bag. It relies on the search function to ensure uniqueness: an element is inserted only if it's not already present. Everything else is delegated to the underlying bag.

### What this project is really testing

* Using inheritance from multiple abstract classes
* Adding search logic in two very different data structures
* Respecting canonical form
* Implementing a class that relies on composition rather than inheritance (`set`)
* Producing code that works with the provided `main.cpp`

### How to compile

Place all `.cpp` files in the same directory, including the provided main:

```bash
g++ -Wall -Wextra -Werror *.cpp -o polyset
./polyset [ARGs]
```
