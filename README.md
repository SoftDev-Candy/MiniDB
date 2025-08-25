\# TinyDB



> A tiny, file-backed in-memory database written in C++17 — built to learn how real systems work by building one.



TinyDB is a compact command-line database I built while learning C++ systems programming. It’s intentionally small and simple: it stores `name` + `age` records, assigns each a unique `id`, and persists everything to a text file so the data survives restarts. This is a learning project — the kind of thing I’d show to demonstrate core systems skills (file I/O, OOP, CLI parsing, and steady debugging).



---



\## Features

\- `insert <name> <age>` — add a new row (auto-assigned unique `id`).

\- `select all` — print every record.

\- `select <name>` — print all records with a matching name.

\- `delete <id>` — delete a single record by id (rewrites file).

\- Data persisted to `Record.txt` (format: `id name age`).

\- Minimal, no external dependencies — uses only the C++ standard library.



---



\## Why I built this

I built TinyDB to practice and demonstrate:

\- Clean C++ structure (classes, static members, constructors).

\- CLI REPL design and robust input parsing.

\- File persistence (append + full-rewrite patterns).

\- Basic CRUD semantics (insert / select / delete).

\- Debugging and incremental design — learning by doing.



---



\## Quick start (build \& run)



\*\*Compile\*\* (example with `g++`, adjust filenames if yours differ):



```bash

g++ -std=c++17 -o tinydb main.cpp command.cpp storedata.cpp



