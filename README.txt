# 🎬 Welcome to MediaTube!

**Experience a seamless, console-based media platform**—powered by modern C++ practices, robust design patterns, and playful ASCII-video magic!

---

## 🔧 Prerequisites & Toolchain

Before you begin, ensure you have:

* **C++17–compliant Compiler**: `g++ (v7.0+)` or `clang++`

  * Leverage **structured bindings**, **`std::optional`**, **`if constexpr`**, and **template argument deduction**
* **GNU Make**: Automates builds and test runs via a concise Makefile
* **Valgrind**: (Optional) Memory profiling and leak detection
* **POSIX–compliant Shell** or Windows Command Prompt with proper path settings

---

## 🧩 In-Depth Technology Stack

### 1. C++17 Modern Features

* **Standard Library Extensions**: `std::filesystem` for file operations, `std::variant` & `std::any` for type-safe unions
* **Compile-time Enhancements**: `if constexpr` for branching templates, `inline` variables to reduce ODR issues
* **Memory Safety**: `std::unique_ptr` & `std::shared_ptr` for RAII-based resource management

### 2. Object-Oriented Architecture

* **Abstract Interfaces**:

  * `Search` interface defines a pure virtual `execute()` method
  * `MediaPlayer` interface exposing `play()` for `AudioPlayer` and `VideoPlayer`
* **Polymorphism**:

  * Runtime binding allows swapping players and search strategies without code changes
* **Encapsulation & Separation**:

  * `View` handles I/O, `Control` delegates to `MediaTube`, and domain logic resides within `Media`, `Channel`, and `Factory` classes

### 3. Creational & Behavioral Patterns

* **Factory Pattern**:

  * `MediaFactory` centralizes instantiation of **Media**, **Channel**, and **Search** objects
  * Simplifies extending with new media types or strategies—adhere to `Factory` contract
* **Strategy Pattern**:

  * Define interchangeable search algorithms (`O_Search`, `C_Search`, `OorC_Search`)
  * Users dynamically select search type at runtime to filter media by **owner**, **category**, or a **combination**

### 4. Templates & Custom Containers

* **Array**:

  * Custom templated dynamic array with `push_back()`, `size()`, `operator[]`
  * Offers a lightweight alternative to `std::vector` for educational clarity
* **Type Safety**:

  * Compile-time checks ensure misuse is flagged early—no unsafe casts

### 5. Multimedia Playback

* **AudioPlayer**:

  * Plays `.wav` files via system calls (e.g., `aplay` on Linux)
  * Handles buffering and error recovery for broken streams
* **VideoPlayer**:

  * Incorporates ASCII-frame playback from `.txt` files, synchronized with audio
  * Demonstrates multithreading basics for concurrent playback

### 6. Build Automation & Testing

* **Makefile Targets**:

  * `make build` — Compiles all sources with `-std=c++17 -Wall -Wextra`
  * `make test` — Builds and runs `TestControl` suite, outputs pass/fail counts
  * `make clean` — Removes binaries and temporary files
* **Test Harness**:

  * `TestControl` validates key classes and functions with hardcoded scenarios
  * Ensures robust behavior before manual exploration

---

## 📂 Project Layout at a Glance

```
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
│   ├── AudioPlayer.cpp     # Audio via system calls
│   ├── VideoPlayer.cpp     # ASCII-video + audio sync
│   ├── MediaFactory.cpp    # Centralized creation logic
│   ├── MediaTube.cpp       # Core orchestration & data storage
│   ├── View.cpp            # User prompts & formatted output
│   ├── Control.cpp         # Coordinates View & MediaTube
│   └── TestControl.cpp     # Unit & integration tests
├── media/                  # Sample `.wav` & ASCII frames
├── Makefile                # Build/test/clean targets
└── README.md               # This in-depth guide!
```

---

## 🚀 Quickstart Guide

1. **Get the code**:

   ```bash
   git clone <repo_url> && cd media_tube
   ```
2. **Build**:

   ```bash
   make build
   ```
3. **Play**:

   ```bash
   ./a4
   ```

   • Add channels, upload media, search, and play!
4. **Verify**:

   ```bash
   make test
   ```
5. **Cleanup**:

   ```bash
   make clean
   ```

---

## 🤝 Tips & Tricks

* **Add New Media**: Place your `.wav` and ASCII `.txt` in `media/`, update `mediaList.txt`, and restart.
* **Extend Searches**: Implement a new class inheriting `Search`, register it in `MediaFactory`.
* **Parallel Playback**: Tweak sleep intervals in `VideoPlayer` for frame-rate control.

---

🔥 ***Immerse yourself in MediaTube’s modular design and rich console experience!***\* 🚀\*
