#include <iostream>
#include <chrono> // For timing measurements
#include "Property.h"
#include "InsertionSort.cpp"      // Include the InsertionSort implementation file
#include "PropertyDataReader.cpp" // Include the PropertyDataReader implementation file
#include "QuickSort.cpp"

using namespace std;

void freeList(ListNode *head)
{
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    int propertyCount = 0;
    PropertyDataReader reader;
    ListNode *properties = reader.readData("C:\\Users\\Abood\\Desktop\\DS\\mudah-apartment-kl-selangor (1).csv", propertyCount);

    if (properties == nullptr)
    {
        std::cerr << "Failed to read properties." << std::endl;
        return 1;
    }

    cout << "Welcome to Asia Pacific Home (APH)" << endl;
    int choice;
    do
    {
        std::cout << "=============================" << std::endl;
        std::cout << "1. Quick Sort Property Rent (Low to High)" << std::endl;
        std::cout << "2. Quick Sort by Property Name (A to Z)" << std::endl;
        std::cout << "3. Insertion Sort Propert Rent (Low to High )" << std::endl;
        std::cout << "4. Insertion Sort by Property Name (A to Z)" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "=============================" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Perform Quick Sort by monthly rent and print sorted properties
            QuickSort quickSort;
            quickSort.sortAndPrintLowToHighByRent(properties);
            break;
        }
        case 2:
        {
            // Perform Quick Sort by property name (A to Z) and print sorted properties
            QuickSort quickSort;
            quickSort.sortAndPrintAToZByName(properties);
            break;
        }
        case 3:
        {
            // Perform Insertion Sort by monthly rent and print sorted properties
            InsertionSort insertionSort;
            insertionSort.sortAndPrintLowToHigh(properties);
            break;
        }
        case 4:
        {
            // Perform Insertion Sort by property name (A to Z) and print sorted properties
            InsertionSort insertionSort;
            insertionSort.sortAndPrintAToZByName(properties);
            break;
        }
        case 5:
        {
            std::cout << "Exiting the program." << std::endl;
            break;
        }
        default:
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        }

    } while (choice != 5);

    freeList(properties); //

    return 0;
}