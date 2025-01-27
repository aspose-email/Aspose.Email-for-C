# Unified Project

This project demonstrates how to build a Rust application that interacts with a shared library (`DLL`) written in C++. The Rust application loads the shared library at runtime and invokes its exported functions.

## Project Structure

```
RustExample/
├── CMakeLists.txt        # Build system for both C++ library and Rust app
├── Cargo.toml            # Rust project configuration
├── src_cpp/              # Aspose mail convertion library sources
└── src/                  # Rust source directory (automatically created by Cargo)
```

## Requirements

To build and run this project, ensure the following tools are installed:

1. **Rust**: Install via [rustup](https://rustup.rs/).
2. **CMake**: Version 3.15 or later is recommended. Download from [cmake.org](https://cmake.org/).
3. **Microsoft C++ Build Tools** (for Windows):
   - Install via the Visual Studio Installer by selecting the **Desktop development with C++** workload.

## Configuration and Build Instructions


###  Build the Project with CMake

1. **Generate the build system:**

   Open a terminal in the project directory and run:

   ```bash
   cmake -B build
   ```

   This command generates the build configuration in the `build/` directory.

2. **Compile the project:**

   Run the following command to build both the C++ library and the Rust application:

   ```bash
   cmake --build build
   ```

3. **Output:**

   The compiled C++ library (`CppLibrary.dll`) and the Rust application (`unified_project.exe`) will be located in the `build/output` directory.

---

### 3. Run the Rust Application

To run the Rust application, use the following command:

```bash
./build/Release/rust_example.exe 
```

If everything is configured correctly, you’ll see the program output similar to the following:

```
HTML Result: HTML content for: example.msg
```

