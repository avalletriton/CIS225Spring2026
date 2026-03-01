#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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
void mergeSortIterative(Book catalog[], int count);
void merge(Book catalog[], int left, int mid, int right);

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

    mergeSortIterative(catalog, count);

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
        // Remove leading space after comma
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
// Iterative (Bottom?Up) Merge Sort
// ---------------------------------------------------------
void mergeSortIterative(Book catalog[], int count) {
    // size = current size of subarrays to merge
    // Complete code here ......
    for (int size = 1; size < count; size = size*2)
    {
        for (int left = 0; left < count - 1; left = left + (2*size))
        {
            int mid = min(left + size - 1, count - 1);
            int right = min(left + 2 * size - 1, count - 1);
            merge(catalog, left, mid, right);
        }
    }





    // End of code updates
}

// ---------------------------------------------------------
// Merge two sorted halves of the array
// ---------------------------------------------------------
void merge(Book catalog[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    Book* L = new Book[n1];
    Book* R = new Book[n2];

    // Copy data into temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = catalog[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = catalog[mid + 1 + j];

    // Merge temp arrays back into catalog[]
    int i = 0, j = 0, k = left;

    // Complete code here ..........
    while (i < n1 && j < n2)
    {
        if (L[i].title < R[j].title)
        {
            catalog[k] = L[i];
            k++; i++;
        }
        else
        {
            catalog[k] = R[j];
            k++; j++;
        }
    }




    // End of code updates

    // Copy remaining elements
    while (i < n1) {
        catalog[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        catalog[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}