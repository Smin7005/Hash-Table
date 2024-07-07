
---

# HashTable C++ Project

## Overview

This project implements a basic hash table in C++ that handles string keys. The hash table uses linear probing for collision resolution and includes basic operations such as insertion, deletion, and searching.

## Features

- **Hash Function**: A simple hash function based on the last character of the key.
- **Collision Handling**: Linear probing to handle collisions.
- **Operations**: Insert, delete, search, and print keys.

### Prerequisites

- C++ compiler (e.g., g++, clang)

### Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/Smin7005/A3-HashTable.git
    ```
2. Navigate to the project directory:
    ```bash
    cd A3-HashTable
    ```

### Usage

1. Compile the program:
    ```bash
    g++ -o hash_table A3-HashTable.cpp
    ```
2. Run the executable:
    ```bash
    ./hash_table
    ```

### Interacting with the Program

- **Add a key**: Enter `A key`
- **Delete a key**: Enter `D key`
- **Exit the program**: Follow the prompt after each operation

### Example

To add a key "example" and then delete it:
```plaintext
A example
D example
```

## Code Explanation

### Slot Structure

Defines a slot in the hash table with a key and status.

### HashTable Class

- **hash**: Computes hash value based on the last character of the key.
- **insert**: Adds a key to the hash table.
- **remove**: Deletes a key from the hash table.
- **search**: Searches for a key in the hash table.
- **print**: Prints all occupied slots in the hash table.

### Main Function

- Handles user input for adding and deleting keys.
- Continuously prompts the user for actions until they choose to exit.

## Contributing

(Shaun)Shangmin Chi

## License

This project is licensed under the MIT License. See the LICENSE file for details.

---
