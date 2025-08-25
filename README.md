**TinyDB**

> A tiny, file-backed in-memory database written in C++17 — built to learn how real systems work by building one.

TinyDB is a compact command-line database I built while learning C++ systems programming. It’s intentionally small and simple: it stores `name` + `age` records, assigns each a unique `id`, and persists everything to a text file so the data survives restarts. This is a learning project — the kind of thing I’d show to demonstrate core systems skills (file I/O, OOP, CLI parsing, and steady debugging).

** Features**
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

\*\*Compile\*\* (example with `g++`, adjust filenames if yours differ): g++ -std=c++17 -o tinydb main.cpp command.cpp storedata.cpp


<img width="599" height="372" alt="image" src="https://github.com/user-attachments/assets/002c35c3-a46b-4c67-bc96-83d7ac644e90" />

File format
•	Record.txt lives in the executable’s working directory.
•	Each line: <id> <name> <age> (space-separated).
•	id is a monotonically-increasing unique integer (never reused).
________________________________________
Design notes & trade-offs
•	Memory-first: Loads the file into an in-memory std::vector<Record> at startup. Queries operate against memory for speed and simplicity.
•	Delete-by-rewrite: Deletes rewrite the file from the in-memory vector for correctness.
•	IDs never reused: Keeps deletions safe and unambiguous.
•	Simplicity-first: No external libraries or complex indexing — intentionally minimal for learning.
________________________________________
What this demonstrates
•	Practical use of file I/O: ifstream, ofstream, append and truncate modes.
•	C++ class design, constructors, static members and lifetime considerations.
•	Defensive parsing and guard checks (avoid crashes on bad input).
•	Debugging real issues (off-by-one, object vs. temporary, ownership of file writes).
________________________________________
Next steps (ideas)
•	update <id> <name> <age> — modify a record.
•	delete range <from> <to> — delete multiple records by range.
•	Unit tests using a small framework (Catch2 recommended).
•	Add a CMakeLists.txt for easier builds.
•	Add support for quoted names (e.g. insert "Bob Jr" 30) and CSV/JSON export.
________________________________________
Tips for reviewers / maintainers
•	The best way to extend this is to split responsibilities clearly:
o	Record = data representation + instance file-write helper.
o	Database (or static in Record) = owns vector, implements read/write entire file and global operations.
o	CLI = parsing and dispatching to Database.
•	Add small unit tests for each operation (insert, read, delete) before changing file-format.
________________________________________
License
This is a learning project — use freely for education and experimentation. If you publish it publicly, a short licence (MIT) is recommended.





