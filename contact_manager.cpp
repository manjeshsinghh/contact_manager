#include <iostream>

using namespace std;

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50
#define PHONE_LENGTH 10  // Define the valid length for phone numbers

// Define the contact structure
struct Contact {
	char name[MAX_NAME_LENGTH];
	char phone[MAX_PHONE_LENGTH];
	char email[MAX_EMAIL_LENGTH];
	Contact* next; // Pointer to the next contact
};

// Declare the head of the linked list
Contact* head = nullptr;

// Function prototypes
void addContact();
void searchContact();
void displayContacts();
void deleteContact();
void updateContact();
Contact* findContactByName(const char* name);
bool isValidPhoneNumber(const char* phone);
void removeNewline(char* str);
int compareStrings(const char* str1, const char* str2);

int main() {
	int choice;

	while (true) {
		cout << "\nContact Manager\n";
		cout << "1. Add Contact\n";
		cout << "2. Search Contact\n";
		cout << "3. Display Contacts\n";
		cout << "4. Delete Contact\n";
		cout << "5. Update Contact\n";
		cout << "6. Exit\n";

		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();  // Consume newline character left by cin

		switch (choice) {
		case 1:
			addContact();
			break;
		case 2:
			searchContact();
			break;
		case 3:
			displayContacts();
			break;
		case 4:
			deleteContact();
			break;
		case 5:
			updateContact();
			break;
		case 6:
			cout << "Exiting the program.\n";
			// Free memory before exiting
			while (head != nullptr) {
				Contact* temp = head;
				head = head->next;
				delete temp;
			}
			return 0;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	}

	return 0;
}

// Function to remove newline characters from a string
void removeNewline(char* str) {
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] == '\n') {
			str[i] = '\0'; // Replace newline with null terminator
			return;
		}
		i++;
	}
}

// Function to validate a phone number
bool isValidPhoneNumber(const char* phone) {
	int i = 0;
	int digitCount = 0;

	// Check each character in the phone number
	while (phone[i] != '\0') {
		if (phone[i] >= '0' && phone[i] <= '9') {
			digitCount++;
		} else if (phone[i] != ' ' && phone[i] != '-') {
			return false; // Invalid character found
		}
		i++;
	}

	// Check if the number of digits matches PHONE_LENGTH
	return (digitCount >= PHONE_LENGTH);
}

// Function to add a new contact
void addContact() {
	Contact* newContact = new Contact;
	if (newContact == nullptr) {
		cout << "Memory allocation failed.\n";
		return;
	}

	cout << "Enter name: ";
	cin.getline(newContact->name, MAX_NAME_LENGTH);
	removeNewline(newContact->name); // Remove newline character

	cout << "Enter phone: ";
	cin.getline(newContact->phone, MAX_PHONE_LENGTH);
	removeNewline(newContact->phone); // Remove newline character

	if (!isValidPhoneNumber(newContact->phone)) {
		cout << "Invalid phone number format. Please enter a valid phone number.\n";
		delete newContact;
		return;
	}

	cout << "Enter email: ";
	cin.getline(newContact->email, MAX_EMAIL_LENGTH);
	removeNewline(newContact->email); // Remove newline character

	newContact->next = head;
	head = newContact;

	cout << "Contact added successfully.\n";
}

// Function to search for a contact by name
void searchContact() {
	char name[MAX_NAME_LENGTH];
	cout << "Enter name to search: ";
	cin.getline(name, MAX_NAME_LENGTH);
	removeNewline(name); // Remove newline character

	Contact* contact = findContactByName(name);
	if (contact != nullptr) {
		cout << "Contact found: " << contact->name << ", " << contact->phone << ", " << contact->email << "\n";
	} else {
		cout << "Contact with name " << name << " not found.\n";
	}
}

// Function to find a contact by name
Contact* findContactByName(const char* name) {
	Contact* current = head;
	while (current != nullptr) {
		if (compareStrings(current->name, name) == 0) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

// Function to display all contacts
void displayContacts() {
	if (head == nullptr) {
		cout << "No contacts to display.\n";
		return;
	}

	Contact* current = head;
	while (current != nullptr) {
		cout << "Name: " << current->name << ", Phone: " << current->phone << ", Email: " << current->email << "\n";
		current = current->next;
	}
}

// Function to delete a contact by name
void deleteContact() {
	char name[MAX_NAME_LENGTH];
	cout << "Enter name to delete: ";
	cin.getline(name, MAX_NAME_LENGTH);
	removeNewline(name); // Remove newline character

	Contact* current = head;
	Contact* previous = nullptr;

	while (current != nullptr && compareStrings(current->name, name) != 0) {
		previous = current;
		current = current->next;
	}

	if (current == nullptr) {
		cout << "Contact with name " << name << " not found.\n";
		return;
	}

	if (previous == nullptr) {
		head = current->next;
	} else {
		previous->next = current->next;
	}

	delete current;
	cout << "Contact " << name << " deleted successfully.\n";
}

// Function to update a contact's details
void updateContact() {
	char name[MAX_NAME_LENGTH];
	cout << "Enter name of the contact to update: ";
	cin.getline(name, MAX_NAME_LENGTH);
	removeNewline(name); // Remove newline character

	Contact* contact = findContactByName(name);
	if (contact != nullptr) {
		cout << "Updating contact " << contact->name << "\n";

		cout << "Enter new phone: ";
		cin.getline(contact->phone, MAX_PHONE_LENGTH);
		removeNewline(contact->phone); // Remove newline character

		if (!isValidPhoneNumber(contact->phone)) {
			cout << "Invalid phone number format. Please enter a valid phone number.\n";
			return;
		}

		cout << "Enter new email: ";
		cin.getline(contact->email, MAX_EMAIL_LENGTH);
		removeNewline(contact->email); // Remove newline character

		cout << "Contact updated successfully.\n";
	} else {
		cout << "Contact with name " << name << " not found.\n";
	}
}

// Function to compare two strings manually
int compareStrings(const char* str1, const char* str2) {
	while (*str1 && (*str1 == *str2)) {
		str1++;
		str2++;
	}
	return *(unsigned char*)str1 - *(unsigned char*)str2;
}
