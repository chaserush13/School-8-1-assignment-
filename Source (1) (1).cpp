#include <iostream>
#include <fstream>
#include <map>
#include <string>

class ItemTracker {
private:
    std::map<std::string, int> items; // This helps to Map to store items and their frequencies

public:
    // with our Function to read and process the input file
    void readInputFile(const std::string& fileName) {
        std::ifstream file(fileName);
        if (!file.is_open()) {
            std::cerr << "Error opening input file." << std::endl;
            return;
        }

        std::string item;

        while (std::getline(file, item)) {
            //this helps with Incrementing the count for each item
            items[item]++;
        }

        file.close();
    }

    // Function to find and return the frequency of a specific item
    int findFrequency(const std::string& item) {
        return items[item];
    }

    // Function to print the list of items and their frequencies
    void printList() {
        for (const auto& pair : items) {
            std::cout << pair.first << " " << pair.second << std::endl;
        }
    }

    // Function to print a histogram of items
    void printHistogram() {
        for (const auto& pair : items) {
            std::cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }

    // Function to save data to a backup file
    void saveDataToFile(const std::string& fileName) {
        std::ofstream outFile(fileName);
        for (const auto& pair : items) {
            outFile << pair.first << " " << pair.second << std::endl;
        }
        outFile.close();
    }
};

int main() {
    ItemTracker tracker;
    tracker.readInputFile("CS210_Project_Three_Input_File.txt"); // Replace with your input file name

    int choice = 0; // Initialize choice to a value that doesn't trigger the loop initially

    while (choice != 4) { // Exit loop when choice is 4
        std::cout << "Menu Options:\n";
        std::cout << "1. Find the frequency of an item\n";
        std::cout << "2. Print the list of items and their frequencies\n";
        std::cout << "3. Print a histogram\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            std::string item;
            std::cout << "Enter the item: ";
            std::cin.ignore(); // Consume the newline character
            std::getline(std::cin, item);
            int frequency = tracker.findFrequency(item);
            std::cout << "Frequency of " << item << ": " << frequency << std::endl;
            break;
        }
        case 2: {
            std::cout << "Printing the list of items and their frequencies:" << std::endl;
            tracker.printList();
            break;
        }
        case 3: {
            std::cout << "Printing the histogram:" << std::endl;
            tracker.printHistogram();
            break;
        }
        case 4: {
            tracker.saveDataToFile("frequency.dat");
            break; // Exit the loop after saving data
        }
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}