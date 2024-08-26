#include <iostream>
#include "Property.h"
#include <chrono>

class QuickSort
{
    int size = 0;

public:
    // Function to sort properties by monthly rent and print the sorted list to std::cout
    void sortAndPrintLowToHighByRent(ListNode *head)
    {
        auto start = std::chrono::high_resolution_clock::now();
        ListNode *sortedListHead = quickSortHelper(head, true, "monthly_rent"); // Sort by monthly rent
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        printSortedProperties(sortedListHead, "Sorted by Monthly Rent", duration);
    }

    // Function to sort properties by property name alphabetically and print the sorted list to std::cout
    void sortAndPrintAToZByName(ListNode *head)
    {
        auto start = std::chrono::high_resolution_clock::now();
        ListNode *sortedListHead = quickSortHelper(head, true, "prop_name"); // Sort by property name
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        printSortedProperties(sortedListHead, "Sorted by Property Name A to Z", duration);
    }

private:
    // Helper function to perform quick sort based on a specified property field
    ListNode *quickSortHelper(ListNode *head, bool ascending, const std::string &sortBy)
    {
        if (!head || !head->next)
            return head; // Base case: If the list is empty or has one element, return head

        ListNode *pivot = head; // Choose the first node as the pivot
        ListNode *lessHead = nullptr;
        ListNode *lessTail = nullptr;
        ListNode *equalHead = nullptr;
        ListNode *equalTail = nullptr;
        ListNode *greaterHead = nullptr;
        ListNode *greaterTail = nullptr;

        ListNode *current = head;
        while (current)
        {
            ListNode *next = current->next;

            // Determine where to place the current node based on the specified property field
            if ((ascending && compareProperties(current->property, pivot->property, sortBy) < 0) ||
                (!ascending && compareProperties(current->property, pivot->property, sortBy) > 0))
            {
                // Node goes into the 'less' list
                appendToList(lessHead, lessTail, current);
            }
            else if (compareProperties(current->property, pivot->property, sortBy) == 0)
            {
                // Node goes into the 'equal' list
                appendToList(equalHead, equalTail, current);
            }
            else
            {
                // Node goes into the 'greater' list
                appendToList(greaterHead, greaterTail, current);
            }
            current = next; // Move to the next node in the original list
        }

        // Recursively sort the 'less' and 'greater' lists
        lessHead = quickSortHelper(lessHead, ascending, sortBy);
        greaterHead = quickSortHelper(greaterHead, ascending, sortBy);

        // Concatenate the sorted lists: 'less', 'equal', and 'greater'
        return concatenateLists(lessHead, equalHead, greaterHead);
    }

    // Function to compare properties based on the specified field
    int compareProperties(const Property &prop1, const Property &prop2, const std::string &sortBy)
    {
        if (sortBy == "monthly_rent")
        {
            return (prop1.monthly_rent - prop2.monthly_rent);
        }
        else if (sortBy == "prop_name")
        {
            return prop1.prop_name.compare(prop2.prop_name);
        }
        // Add more comparisons for other fields if needed
        return 0; // Default case
    }

    // Function to append a node to the end of a list
    void appendToList(ListNode *&head, ListNode *&tail, ListNode *node)
    {
        if (!head)
        {
            head = node;
        }
        else
        {
            tail->next = node;
        }
        tail = node;
        node->next = nullptr;
    }

    // Function to concatenate three lists: 'less', 'equal', and 'greater'
    ListNode *concatenateLists(ListNode *less, ListNode *equal, ListNode *greater)
    {
        ListNode *result = nullptr;
        ListNode *tail = nullptr;

        // Concatenate 'less' list
        result = concatenateListsHelper(result, tail, less);

        // Concatenate 'equal' list
        result = concatenateListsHelper(result, tail, equal);

        // Concatenate 'greater' list
        result = concatenateListsHelper(result, tail, greater);

        return result; // Return the concatenated sorted list
    }

    // Helper function to concatenate a list to the result list
    ListNode *concatenateListsHelper(ListNode *&result, ListNode *&tail, ListNode *list)
    {
        if (!result)
        {
            result = list;
        }
        else
        {
            tail->next = list;
        }
        if (list)
        {
            while (list->next)
            {
                list = list->next;
            }
            tail = list;
        }
        return result;
    }

    // Function to print sorted properties to std::cout
    void printSortedProperties(ListNode *sortedListHead, const std::string &title, std::chrono::milliseconds duration)
    {
        std::cout << title << ":" << std::endl;
        ListNode *current = sortedListHead;
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

        std::cout << "Time taken to sort properties: " << duration.count() << " milliseconds" << std::endl;
        std::cout << "Size Of LinkedList is = " << size << std::endl;

        // Clean up sorted list memory
        while (sortedListHead)
        {
            ListNode *temp = sortedListHead;
            sortedListHead = sortedListHead->next;
            delete temp;
        }
    }
};