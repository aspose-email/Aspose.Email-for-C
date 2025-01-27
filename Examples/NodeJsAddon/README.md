# Aspose.Email for C++ Node.js Addon Example with CMake.js

This README provides instructions for configuring, building, and testing a Aspose.Email for C++ Node.js Addon Example.

## Prerequisites

Ensure you have the following tools installed on your system:

1. **Node.js**: Install Node.js from [the official website](https://nodejs.org/).
2. **CMake**: Download and install CMake from [the official website](https://cmake.org/).
3. **C++ Compiler**: Ensure a compatible C++ compiler is installed (e.g., GCC, Clang, or MSVC).
4. **Python**: Python is required for building Node.js addons. Install Python 3.x.
5. **CMake.js**: Install CMake.js globally:
   ```bash
   npm install -g cmake-js
   ```
6. **Aspose.Email for C++**: Install the Aspose.Email for C++ library. Refer to [Aspose.Email documentation](https://products.aspose.com/email/cpp/) for installation instructions.
7. Set the environment variable `ASPOSE_ROOT` to the directory where the Aspose.Email library is installed. For example:
   ```bash
   export ASPOSE_ROOT=/path/to/aspose
   ```

## Configuring the Project

To configure the project, run the following command in the root directory of your addon:

```bash
cmake-js configure
```

This command generates the necessary build files based on your platform and configuration.

## Building the Project

After configuring the project, build it using the following command:

```bash
cmake-js build
```

The compiled addon will be output to the `build/Release/` directory.

## Running the Tests

To ensure the addon works correctly, run the tests provided in the project. The tests are typically executed using Node.js. Use the following command:

```bash
node test.js
```

## Clean Build (Optional)

If you need to clean the project and rebuild it from scratch, delete the `build` directory and re-run the configuration and build commands:

```bash
rm -rf build
cmake-js configure
cmake-js build
```

