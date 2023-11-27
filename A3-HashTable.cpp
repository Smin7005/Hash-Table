// A3-HashTable.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include <iostream>
#include <vector>
#include <string>

const int TABLE_SIZE = 26;
enum SlotStatus { NEVER_USED, TOMBSTONE, OCCUPIED };

struct Slot {
    std::string key;
    SlotStatus status;
    Slot() : status(NEVER_USED) {}
};

class HashTable {
private:
    std::vector<Slot> table;

    int hash(const std::string& key) const {
        return key.back() - 'a';
    }

public:
    HashTable() : table(TABLE_SIZE) {}

    bool search(const std::string& key) const {
        int index = hash(key);
        while (table[index].status != NEVER_USED) {
            if (table[index].status == OCCUPIED && table[index].key == key)
                return true;
            index = (index + 1) % TABLE_SIZE;
        }
        return false;
    }

    void insert(const std::string& key) {
        if (search(key))
            return;

        int index = hash(key);
        while (table[index].status == OCCUPIED)
            index = (index + 1) % TABLE_SIZE;

        table[index].key = key;
        table[index].status = OCCUPIED;
    }

    void remove(const std::string& key) {
        int index = hash(key);
        while (table[index].status != NEVER_USED) {
            if (table[index].status == OCCUPIED && table[index].key == key) {
                table[index].status = TOMBSTONE;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        }
    }

    void print() const {
        for (const Slot& slot : table) {
            if (slot.status == OCCUPIED)
                std::cout << slot.key << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::cout << "Program started now: " << std::endl;
    HashTable ht;
    char c = 'n';
    do {
        std::string input;
        getline(std::cin, input);
        size_t start = 0;
        while (start < input.size()) {
            char action = input[start];
            size_t nextSpace = input.find(' ', start);

            // If there's no next space, take the rest of the string as the key
            std::string key = (nextSpace != std::string::npos) ?
                input.substr(start + 1, nextSpace - start - 1) :
                input.substr(start + 1);

            if (action == 'A') ht.insert(key);
            else if (action == 'D') ht.remove(key);

            // If there's no next space, break out of the loop
            if (nextSpace == std::string::npos) {
                break;
            }
            else {
                start = nextSpace + 1;
            }
        }
        ht.print();

        std::cout << "\nContinuing input or not? (y/n)";
        std::cin >> c;
        // Clear the newline character left in the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (c == 'y' || c == 'Y');

    return 0;
}
