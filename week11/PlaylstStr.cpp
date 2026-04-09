#include <iostream>
#include <string>
#include "Playlist.h"

void displayMenu() {
    std::cout << "\n Playlist Manager Menu \n";
    std::cout << "1. Add Song\n";
    std::cout << "2. Remove Song\n";
    std::cout << "3. Skip Forward\n";
    std::cout << "4. Skip Backward\n";
    std::cout << "5. Display Current Song\n";
    std::cout << "6. Clear Playlist\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Playlist myPlaylist;
    int choice = 0;
    std::string title, artist;
    double duration;
    int steps;

    while (choice != 7) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::cout << "Enter song title: ";
            std::getline(std::cin, title);
            std::cout << "Enter artist name: ";
            std::getline(std::cin, artist);
            std::cout << "Enter duration (minutes): ";
            std::cin >> duration;
            myPlaylist.addSong(title, artist, duration);
        }
        else if (choice == 2) {
            std::cout << "Enter title of song to remove: ";
            std::getline(std::cin >> std::ws, title);
            myPlaylist.removeSong(title);
        }
        else if (choice == 3) {
            std::cout << "Skip forward by how many songs? ";
            std::cin >> steps;
            myPlaylist.skipForward(steps);
        }
        else if (choice == 4) {
            std::cout << "Skip backward by how many songs? ";
            std::cin >> steps;
            myPlaylist.skipBackward(steps);
        }
        else if (choice == 5) {
            myPlaylist.displayCurrent();
        }
        else if (choice == 6) {
            myPlaylist.clear();
            std::cout << "Playlist cleared.\n";
        }
        else if (choice == 7) {
            std::cout << "Exiting Playlist Manager. Goodbye!\n";
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}