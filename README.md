# contact_manager
This C++ code implements a simple contact management system using a singly linked list for storing contact information. This system allows users to perform basic operations such as adding, searching, displaying, deleting, and updating contact details.

Description of C++ Contact Management System Code
Overview
The provided C++ code implements a simple contact management system using a singly linked list for storing contact information. This system allows users to perform basic operations such as adding, searching, displaying, deleting, and updating contact details. The code avoids using advanced features from the C++ Standard Library and instead relies on fundamental C++ constructs.

Key Components
Data Structure

Contact: A structure that represents an individual contact. It contains:

name: A char array to store the contact's name.
phone: A char array to store the contact's phone number.
email: A char array to store the contact's email address.
next: A pointer to the next Contact in the linked list.
head: A global pointer that points to the first contact in the linked list.

Functions

main(): The entry point of the program. It provides a menu-driven interface to the user for selecting different operations:

Add Contact
Search Contact
Display Contacts
Delete Contact
Update Contact
Exit
addContact(): Adds a new contact to the beginning of the linked list. It reads the contact’s name, phone number, and email from the user, validates the phone number, and handles dynamic memory allocation.

searchContact(): Searches for a contact by name. It prompts the user for a name, searches the linked list, and displays the contact details if found.

displayContacts(): Displays all contacts currently stored in the linked list. It iterates through the list and prints each contact’s details.

deleteContact(): Deletes a contact from the linked list based on the name provided by the user. It adjusts pointers to maintain the list’s integrity and handles memory deallocation.

updateContact(): Updates the phone number and email of an existing contact. It searches for the contact by name, validates the new phone number, and updates the details.

findContactByName(const char* name): Searches the linked list for a contact with a matching name and returns a pointer to the contact if found.

isValidPhoneNumber(const char* phone): Validates the phone number to ensure it meets specified criteria (contains only digits, spaces, or dashes and has a sufficient number of digits).

removeNewline(char* str): Removes newline characters from a string, which may be introduced by input functions.

compareStrings(const char* str1, const char* str2): Compares two strings character by character and returns the difference between them.

Usage
Adding Contacts: Users can add new contacts by entering their name, phone number, and email. Phone numbers are validated to ensure they are in the correct format.

Searching for Contacts: Users can search for a contact by name. The system displays the contact's details if found.

Displaying Contacts: Users can view all contacts stored in the system. This helps in reviewing all existing contacts.

Deleting Contacts: Users can delete a contact by name. The system ensures that the contact is removed from the list and adjusts pointers accordingly.

Updating Contacts: Users can update the phone number and email of an existing contact. The new phone number is validated before updating.

Memory Management
Dynamic Memory: The program uses new to allocate memory for new contacts and delete to free memory when contacts are removed. This ensures that the program manages memory efficiently and prevents memory leaks.
Conclusion
This C++ contact management system demonstrates fundamental programming concepts such as linked lists, manual string handling, and dynamic memory management. By avoiding advanced standard library features, the code provides a clear view of basic C++ operations and data structure manipulation.

