#include "Property.h"
#include <fstream>
#include <sstream>
#include <iostream>

class PropertyDataReader
{
public:
    // Function to read property data from a CSV file and store it in a linked list
    static ListNode *readData(const std::string &filename, int &propertyCount)
    {
        std::ifstream file(filename); // Open the file for reading
        if (!file.is_open())
        { // Check if file opening failed
            std::cerr << "Failed to open the file: " << filename << std::endl;
            return nullptr;
        }

        std::string line;
        std::getline(file, line); // Read and skip the header line

        propertyCount = 0;        // Initialize property count
        ListNode *head = nullptr; // Initialize head of the linked list
        ListNode *tail = nullptr; // Initialize tail of the linked list

        while (std::getline(file, line))
        {                               // Read each line from the file
            std::stringstream ss(line); // Use stringstream to parse the line
            Property property;
            try
            {
                // Read each property attribute from the stringstream
                std::getline(ss, property.ads_id, ',');
                std::getline(ss, property.prop_name, ',');
                std::getline(ss, property.completion_year, ',');
                std::string monthly_rent_str;
                std::getline(ss, monthly_rent_str, ',');
                property.monthly_rent = std::stoi(monthly_rent_str);
                std::getline(ss, property.location, ',');
                std::getline(ss, property.property_type, ',');
                std::getline(ss, property.rooms, ',');
                std::getline(ss, property.parking, ',');
                std::getline(ss, property.bathroom, ',');
                std::getline(ss, property.size, ',');
                std::getline(ss, property.furnished, ',');

                // Create a new ListNode and add it to the linked list
                ListNode *newNode = new ListNode(property);
                if (!head)
                { // If head is null, set head and tail to the new node
                    head = newNode;
                    tail = newNode;
                }
                else
                { // Otherwise, append the new node to the end of the list
                    tail->next = newNode;
                    tail = newNode;
                }
                propertyCount++; // Increment property count
            }
            catch (const std::exception &e)
            {
                // If an exception occurs while parsing, skip the current line
                // Uncomment the following lines for debugging purposes:
                // std::cerr << "Error reading data at line " << propertyCount + 2 << ": " << e.what() << std::endl;
                // std::cerr << "Skipping this line." << std::endl;
                continue;
            }
        }

        file.close();                                                         // Close the file
        std::cout << "Total properties read: " << propertyCount << std::endl; // Output total properties read

        // Uncomment the following section for debugging: Print all properties in the linked list
        /*
        ListNode* current = head;
        while (current) {
            std::cout << "Property: " << current->property.ads_id << ", "
                      << current->property.prop_name << ", "
                      << current->property.monthly_rent << std::endl;
            current = current->next;
        }
        */

        return head; // Return the head of the linked list
    }
};