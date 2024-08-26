#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

// Property structure
struct Property
{
    std::string ads_id;
    std::string prop_name;
    std::string completion_year;
    int monthly_rent;
    std::string location;
    std::string property_type;
    std::string rooms;
    std::string parking;
    std::string bathroom;
    std::string size;
    std::string furnished;
};

// Linked list node structure
struct ListNode
{
    Property property;
    ListNode *next;
    ListNode(const Property &prop) : property(prop), next(nullptr) {}
};

#endif // PROPERTY_H