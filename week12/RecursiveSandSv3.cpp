#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Game {
    string name;
    int score;
};

// Quick Sort by score (descending)
int partitionByScore(Game arr[], int low, int high) {
    // add code here
    int piv, i, j;

    piv = arr[high].score;
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if (arr[j].score > piv)
        {
            i++;
            swap(arr[i], arr[j]); //when the condition is true, this moves the boundary
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortByScore(Game arr[], int low, int high) {
    if (low < high) {
        int pi = partitionByScore(arr, low, high);
        quickSortByScore(arr, low, pi - 1);
        quickSortByScore(arr, pi + 1, high);
    }
}

// Quick Sort by name (ascending)
int partitionByName(Game arr[], int low, int high) {
    // Add code here
    int i, j;
    string piv;

    piv = arr[high].name;
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if (arr[j].name < piv) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortByName(Game arr[], int low, int high) {
    // added code here
    if (low < high)
    {
        int pi = partitionByName(arr, low, high);
        quickSortByName(arr, low, pi - 1);
        quickSortByName(arr, pi + 1, high);
    }
}

// Binary Search by name
int binarySearchByName(Game arr[], int low, int high, string target) {
    // add code here
    if (low > high) //this lines checks if there are elements left to search. 
    {
        return -1; //when there arent any, this prevents the function from calling itself infinitely
    }

    int mid;
    mid = (low + high) / 2;

    if (arr[mid].name == target)
    {
        return mid;
    }
    else if (target < arr[mid].name)
    {
        return binarySearchByName(arr, low, mid - 1, target);
    }
    else
    {
        return binarySearchByName(arr, mid + 1, high, target);
    }
}

// Display games
void displayGames(Game arr[], int n) {
    cout << "\nGame List:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << arr[i].name << " - Score: " << arr[i].score << endl;
    }
}

// Read games from file
bool readFromFile(Game arr[], int& n, const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cout << "Error opening file: " << filename << endl;
        return false;
    }

    n = 0;
    while (n < 10 && infile >> arr[n].name >> arr[n].score) {
        n++;
    }

    infile.close();
    return n == 10;
}

// Main menu
int main() {
    Game games[10];
    int n = 0, choice;
    bool isSortedByScore = false;
    bool isSortedByName = false;

    cout << "Reading game data from 'gamed.txt'...\n";
    if (!readFromFile(games, n, "gamed.txt")) {
        cout << "Failed to read 10 games. Exiting.\n";
        return 1;
    }

    while (true) {
        cout << "\n--- Indie Game Ranking Menu ---\n";
        cout << "1. Sort games by score (recursive quick sort)\n";
        cout << "2. Sort games by name (recursive quick sort)\n";
        cout << "3. Search for a game by name (binary search)\n";
        cout << "4. Display games\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            quickSortByScore(games, 0, n - 1);
            isSortedByScore = true;
            isSortedByName = false;
            cout << "Games sorted by score.\n";
        }
        else if (choice == 2) {
            quickSortByName(games, 0, n - 1);
            isSortedByName = true;
            isSortedByScore = false;
            cout << "Games sorted by name.\n";
        }
        else if (choice == 3) {
            if (!isSortedByName) {
                cout << "Please sort the games by name first.\n";
            }
            else {
                string target;
                cout << "Enter game name to search: ";
                cin >> target;
                int index = binarySearchByName(games, 0, n - 1, target);
                if (index != -1)
                    cout << "Found: " << games[index].name << " with score " << games[index].score << endl;
                else
                    cout << "Game not found.\n";
            }
        }
        else if (choice == 4) {
            displayGames(games, n);
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}