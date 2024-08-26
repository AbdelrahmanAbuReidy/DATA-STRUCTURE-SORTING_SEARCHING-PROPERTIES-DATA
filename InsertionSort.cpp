#include <iostream>
#include "Property.h"
#include <chrono>

class InsertionSort
{
    int size = 0;

public:
    // Function to perform insertion sort on properties based on monthly rent (ascending)
    void sortAndPrintLowToHigh(ListNode *&head)
    {
        if (!head || !head->next)
            return; // If the list is empty or has one element, no sorting needed
        auto start = std::chrono::high_resolution_clock::now();
        ListNode *sortedList = nullptr; // Sorted list
        ListNode *current = head;
        while (current != nullptr)
        {
            ListNode *next = current->next;

            // Insert current node into sorted list based on monthly rent (ascending)
            sortedList = sortedInsert(sortedList, current);
            current = next;
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        // Print sorted properties with all details
        printSortedProperties(sortedList);
        std::cout << "=============================" << std::endl;
        std::cout << "Time taken to sort properties: " << duration.count() << " milliseconds" << std::endl;
        std::cout << "Size Of LinkedList is = " << size << std::endl;

        // Clean up sorted list memory
        while (sortedList)
        {
            ListNode *temp = sortedList;
            sortedList = sortedList->next;
            delete temp;
        }

        // Update the head pointer to point to the sorted list
        head = sortedList;
    }

    // Function to perform insertion sort on properties based on property name (A to Z)
    void sortAndPrintAToZByName(ListNode *&head)
    {
        if (!head || !head->next)
            return; // If the list is empty or has one element, no sorting needed
        auto start = std::chrono::high_resolution_clock::now();
        ListNode *sortedList = nullptr; // Sorted list
        ListNode *current = head;
        while (current != nullptr)
        {
            ListNode *next = current->next;

            // Insert current node into sorted list based on property name (A to Z)
            sortedList = sortedInsertByName(sortedList, current);
            current = next;
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        // Print sorted properties with all details
        printSortedProperties(sortedList);
        std::cout << "=============================" << std::endl;
        std::cout << "Time taken to sort properties by name: " << duration.count() << " milliseconds" << std::endl;
        std::cout << "Size Of LinkedList is = " << size << std::endl;

        // Clean up sorted list memory
        while (sortedList)
        {
            ListNode *temp = sortedList;
            sortedList = sortedList->next;
            delete temp;
        }

        // Update the head pointer to point to the sorted list
        head = sortedList;
    }

private:
    // Helper function to insert a node into the sorted list based on monthly rent (ascending)
    ListNode *sortedInsert(ListNode *sortedHead, ListNode *newNode)
    {
        if (!sortedHead || sortedHead->property.monthly_rent >= newNode->property.monthly_rent)
        {
            newNode->next = sortedHead;
            return newNode;
        }

        ListNode *current = sortedHead;
        while (current->next != nullptr && current->next->property.monthly_rent < newNode->property.monthly_rent)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        return sortedHead;
    }

    // Helper function to insert a node into the sorted list based on property name (A to Z)
    ListNode *sortedInsertByName(ListNode *sortedHead, ListNode *newNode)
    {
        if (!sortedHead || sortedHead->property.prop_name >= newNode->property.prop_name)
        {
            newNode->next = sortedHead;
            return newNode;
        }

        ListNode *current = sortedHead;
        while (current->next != nullptr && current->next->property.prop_name < newNode->property.prop_name)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        return sortedHead;
    }

    // Function to print sorted properties with all details
    void printSortedProperties(ListNode *head)
    {
        ListNode *current = head;
        while (current)
        {
            std::cout << "Property Details:" << std::endl;
            std::cout << "  Ads ID: " << current->property.ads_id << std::endl;
            std::cout << "  Property Name: " << current->property.prop_name << std::endl;
            std::cout << "  Completion Year: " << current->property.completion_year << std::endl;
            std::cout << "  Monthly Rent: " << current->property.monthly_rent << std::endl;
            std::cout << "  Location: " << current->property.location << std::endl;
            std::cout << "  Property Type: " << current->property.property_type << std::endl;
            std::cout << "  Rooms: " << current->property.rooms << std::endl;
            std::cout << "  Parking: " << current->property.parking << std::endl;
            std::cout << "  Bathroom: " << current->property.bathroom << std::endl;
            std::cout << "  Size: " << current->property.size << std::endl;
            std::cout << "  Furnished: " << current->property.furnished << std::endl;
            std::cout << std::endl;
            size++;
            current = current->next;
        }
    }
};