#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Function declarations
void addTask(const std::string& filename);
void viewTasks(const std::string& filename);
void deleteTask(const std::string& filename);

int main() {
    const std::string filename = "todo.txt";
    int choice;

    do {
        std::cout << "To-Do List Program\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline character left in buffer

        switch (choice) {
            case 1:
                addTask(filename);
                break;
            case 2:
                viewTasks(filename);
                break;
            case 3:
                deleteTask(filename);
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

void addTask(const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    std::string task;
    std::cout << "Enter the task: ";
    std::getline(std::cin, task);
    file << task << std::endl;

    std::cout << "Task added successfully.\n";
    file.close();
}

void viewTasks(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    std::string task;
    std::cout << "To-Do List:\n";
    int taskNumber = 1;
    while (std::getline(file, task)) {
        std::cout << taskNumber++ << ". " << task << std::endl;
    }

    file.close();
}

void deleteTask(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    std::vector<std::string> tasks;
    std::string task;
    while (std::getline(file, task)) {
        tasks.push_back(task);
    }
    file.close();

    int taskNumber;
    std::cout << "Enter the task number to delete: ";
    std::cin >> taskNumber;
    std::cin.ignore(); // Ignore newline character left in buffer

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        std::cerr << "Invalid task number." << std::endl;
        return;
    }

    tasks.erase(tasks.begin() + taskNumber - 1);

    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    for (const auto& t : tasks) {
        outFile << t << std::endl;
    }

    std::cout << "Task deleted successfully.\n";
    outFile.close();
}
