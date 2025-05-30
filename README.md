# 🎬 Welcome to MediaTube!

**Experience a seamless, console-based media platform** — powered by modern C++ practices, robust design patterns, and playful ASCII-video magic!

---

## 🔧 Prerequisites & Toolchain

Before you begin, ensure you have:

* **C++17–compliant Compiler** (`g++ (v7.0+)` or `clang++`)

  * Leverage **structured bindings**, **`std::optional`**, **`if constexpr`**, and **template argument deduction**
* **GNU Make**: Automates builds and test runs via a concise Makefile
* **Valgrind** (optional): Memory profiling and leak detection
* **POSIX–compliant Shell** or Windows Command Prompt with proper path settings

---

## 🧩 In-Depth Technology Stack

### 1. C++17 Modern Features

* **Standard Library Extensions**: `std::filesystem` for file operations, `std::variant` & `std::any` for type-safe unions
* **Compile-time Enhancements**: `if constexpr` for branching templates, `inline` variables to reduce ODR issues
* **Memory Safety**: `std::unique_ptr` & `std::shared_ptr` for RAII-based resource management

### 2. Object-Oriented Architecture

* **Abstract Interfaces**

  * `Search` interface defines a pure virtual `execute()` method
  * `MediaPlayer` interface exposes `play()` for `AudioPlayer` and `VideoPlayer`
* **Polymorphism**

  * Runtime binding allows swapping players and search strategies without code changes
* **Encapsulation & Separation**

  * `View` handles I/O, `Control` delegates to `MediaTube`, and domain logic lives in `Media`, `Channel`, and `MediaFactory`

### 3. Creational & Behavioral Patterns

* **Factory Pattern**

  * `MediaFactory` centralizes instantiation of **Media**, **Channel**, and **Search** objects
  * Simplifies extending with new media types or strategies—just implement the Factory contract
* **Strategy Pattern**

  * Interchangeable search algorithms (`O_Search`, `C_Search`, `OorC_Search`)
  * Users select search type at runtime to filter media by **owner**, **category**, or **both**

### 4. Templates & Custom Containers

* **Array**

  * Templated dynamic array with `push_back()`, `size()`, and `operator[]`
  * Lightweight alternative to `std::vector` for clarity
* **Type Safety**

  * Compile-time checks catch misuse early—no unsafe casts

### 5. Multimedia Playback

* **AudioPlayer**

  * Plays `.wav` files via system calls (e.g., `aplay` on Linux)
  * Handles buffering and error recovery
* **VideoPlayer**

  * ASCII-frame playback from `.txt` files, synchronized with audio
  * Demonstrates multithreading basics for concurrent playback

### 6. Build Automation & Testing

* **Makefile Targets**

  * `make build` — Compiles sources with `-std=c++17 -Wall -Wextra`
  * `make test` — Builds and runs tests (`TestControl`), reporting pass/fail counts
  * `make clean` — Cleans binaries and temp files
* **Test Harness**

  * `TestControl` suite validates key classes/functions with sample scenarios

---

## 📂 Project Layout at a Glance

```plain
media_tube/
├── src/
│   ├── main.cc             # Bootstrap & command loop
│   ├── Media.h / .cpp      # Base & derived media types
│   ├── Channel.h / .cpp    # Container for Media objects
│   ├── Search.h            # Strategy interface
│   ├── O_Search.cpp        # Owner-based filter
│   ├── C_Search.cpp        # Category-based filter
│   ├── OorC_Search.cpp     # Combined filter logic
│   ├── Array.h             # Templated dynamic array
│   ├── MediaPlayer.h       # Playback interface
│   ├── AudioPlayer.cpp     # Audio implementation
│   ├── VideoPlayer.cpp     # ASCII-video + audio sync
│   ├── MediaFactory.cpp    # Factory logic
│   ├── MediaTube.cpp       # Core orchestration & storage
│   ├── View.cpp            # User interface
│   ├── Control.cpp         # Controller logic
│   └── TestControl.cpp     # Unit & integration tests
├── media/                  # Sample `.wav` & ASCII frames
├── Makefile                # Build/test/clean targets
└── README.md               # This guide!
```

---

## 🚀 Quickstart Guide

1. **Clone the repo**:

   ```bash
   git clone <repo_url>
   cd media_tube
   ```
2. **Build**:

   ```bash
   make build
   ```
3. **Run**:

   ```bash
   ./a4
   ```

   • Add channels, upload media, search, and play!
4. **Test**:

   ```bash
   make test
   ```
5. **Clean**:

   ```bash
   make clean
   ```

---

## 🤝 Tips & Tricks

* **Add New Media**: Copy your `.wav` & ASCII `.txt` into `media/`, update `mediaList.txt`, then restart.
* **Extend Searches**: Create a new class inheriting `Search` and register it in `MediaFactory`.
* **Adjust Playback**: Tweak sleep timings in `VideoPlayer` for custom frame rates.

---

**Immerse yourself in MediaTube’s modular design and rich console experience!**
