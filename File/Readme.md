# C++ File Read and Write Tutorial

In this tutorial, we will cover the basics of reading from and writing to files in C++. We will use file streams provided by the `<fstream>` library to perform these operations. This tutorial includes examples and exercises to help you practice file handling in C++.

## Introduction to File Handling

File handling in C++ is done using the `<fstream>` library, which provides the `ifstream` class for reading from files and the `ofstream` class for writing to files. The `fstream` class can be used for both reading and writing.

### Including the Library
To use file streams, you need to include the `<fstream>` library.
```cpp
#include <fstream>
```

## Writing to a File

### Writing to a File using `ofstream`
The `ofstream` class is used to create files and write information to them.

#### Example: Writing to a File
```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outFile("example.txt");
    if (outFile.is_open()) {
        outFile << "Hello, World!" << std::endl;
        outFile << "Writing to a file in C++." << std::endl;
        outFile.close();
        std::cout << "File written successfully." << std::endl;
    } else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
    return 0;
}
```

## Reading from a File

### Reading from a File using `ifstream`
The `ifstream` class is used to read information from files.

#### Example: Reading from a File
```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile("example.txt");
    std::string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cout << "Unable to open file for reading." << std::endl;
    }
    return 0;
}
```

## Reading and Writing to a File

### Using `fstream` for Both Reading and Writing
The `fstream` class can be used for both reading from and writing to files.

#### Example: Reading and Writing to a File
```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::fstream file("example.txt", std::ios::in | std::ios::out | std::ios::app);
    if (file.is_open()) {
        file << "Appending a new line to the file." << std::endl;
        
        file.seekg(0);  // Move the cursor to the beginning of the file
        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
    return 0;
}
```

## Checking if a File Exists

### Using `ifstream` to Check if a File Exists
You can use `ifstream` to check if a file exists by trying to open it.

#### Example: Checking if a File Exists
```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ifstream inFile("example.txt");
    if (inFile) {
        std::cout << "File exists." << std::endl;
    } else {
        std::cout << "File does not exist." << std::endl;
    }
    return 0;
}
```

## Exercises

### Exercise 1: Writing to a File
Create a program that writes your name, age, and favorite hobby to a file named `info.txt`.

#### Solution
```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outFile("info.txt");
    if (outFile.is_open()) {
        outFile << "Name: John Doe" << std::endl;
        outFile << "Age: 30" << std::endl;
        outFile << "Hobby: Reading" << std::endl;
        outFile.close();
        std::cout << "File written successfully." << std::endl;
    } else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
    return 0;
}
```

### Exercise 2: Reading from a File
Create a program that reads and prints the contents of `info.txt`.

#### Solution
```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile("info.txt");
    std::string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cout << "Unable to open file for reading." << std::endl;
    }
    return 0;
}
```

### Exercise 3: Reading and Writing to a File
Create a program that appends a new hobby to `info.txt` and then reads and prints the entire file.

#### Solution
```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::fstream file("info.txt", std::ios::in | std::ios::out | std::ios::app);
    if (file.is_open()) {
        file << "New Hobby: Coding" << std::endl;
        
        file.seekg(0);  // Move the cursor to the beginning of the file
        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
    return 0;
}
```

### Exercise 4: Checking if a File Exists
Create a program that checks if `info.txt` exists and prints an appropriate message.

#### Solution
```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ifstream inFile("info.txt");
    if (inFile) {
        std::cout << "File exists." << std::endl;
    } else {
        std::cout << "File does not exist." << std::endl;
    }
    return 0;
}
```

By understanding these basic file operations and working through the exercises, you will be able to handle files effectively in your C++ programs.
