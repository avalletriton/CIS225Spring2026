#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stack>
using namespace std;

const int MAX = 10;

// ---------------------------------------------------------
// Structure Definition
// ---------------------------------------------------------
struct Book {
    string title;
    string author;
    int year;
};

// ---------------------------------------------------------
// Function Prototypes
// ---------------------------------------------------------
void loadData(ifstream& inFile, Book catalog[], int& count);
void display(const Book catalog[], int count);

void quickSortIterative(Book catalog[], int count);
int partition(Book catalog[], int low, int high);

// ---------------------------------------------------------
// Main Function
// ---------------------------------------------------------
int main() {
    Book catalog[MAX];
    int count = 0;

    ifstream inFile("booksMS.txt");
    if (!inFile) {
        cout << "Error: Could not open input file." << endl;
        return 1;
    }

    loadData(inFile, catalog, count);
    inFile.close();

    cout << "UNSORTED BOOK CATALOG\n";
    cout << "----------------------------------------\n";
    display(catalog, count);

    quickSortIterative(catalog, count);

    cout << "\nSORTED BOOK CATALOG (BY TITLE)\n";
    cout << "----------------------------------------\n";
    display(catalog, count);

    return 0;
}

// ---------------------------------------------------------
// Load data from file into the array of structures
// ---------------------------------------------------------
void loadData(ifstream& inFile, Book catalog[], int& count) {
    string title, author, yearStr;

    while (getline(inFile, title, ',')) {
        if (title.size() > 0 && title[0] == ' ')
            title.erase(0, 1);

        getline(inFile, author, ',');
        if (author.size() > 0 && author[0] == ' ')
            author.erase(0, 1);

        getline(inFile, yearStr);
        if (yearStr.size() > 0 && yearStr[0] == ' ')
            yearStr.erase(0, 1);

        catalog[count].title = title;
        catalog[count].author = author;
        catalog[count].year = stoi(yearStr);

        count++;
    }
}

// ---------------------------------------------------------
// Display all books in a formatted table
// ---------------------------------------------------------
void display(const Book catalog[], int count) {
    cout << left << setw(30) << "Title"
        << setw(25) << "Author"
        << setw(6) << "Year" << endl;

    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < count; i++) {
        cout << left << setw(30) << catalog[i].title
            << setw(25) << catalog[i].author
            << setw(6) << catalog[i].year << endl;
    }
}

// ---------------------------------------------------------
// Partition function for Quick Sort
// ---------------------------------------------------------
int partition(Book catalog[], int low, int high) {
    string pivot = catalog[high].title;
    int i = low - 1;

    // Complete code here ......
    for (int j = low; j < high; j++)
    {
        if (catalog[j].title <= pivot)
        {
            i++;
            swap(catalog[i], catalog[j]);
        }
    }

     // End of Code Updates

    swap(catalog[i + 1], catalog[high]);
    return i + 1;
}

// ---------------------------------------------------------
// Iterative (Non-Recursive) Quick Sort
// ---------------------------------------------------------
void quickSortIterative(Book catalog[], int count) {
    stack<int> s;

    // Push initial range
    s.push(0);
    s.push(count - 1);

    // Complete code here ........
    while (!s.empty())
    {
        int h = s.top(); s.pop();
        int l = s.top(); s.pop();
        int pi = partition(catalog, l, h);

        if (pi - 1 > l)
        {
            s.push(l);
            s.push(pi - 1);
        }
        if (pi + 1 < h)
        {
            s.push(pi + 1);
            s.push(h);
        }
    }


   // End of code updates
}