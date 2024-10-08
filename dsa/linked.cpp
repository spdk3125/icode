#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtFirst(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int data, int position) {
        if (position == 0) {
            insertAtFirst(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            std::cout << "Position out of range\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromFirst() {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int position) {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }
        if (position == 0) {
            deleteFromFirst();
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            std::cout << "Position out of range\n";
            return;
        }
        Node* nextPtr = temp->next->next;
        delete temp->next;
        temp->next = nextPtr;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    bool search(int x) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == x)
                return true;
            current = current->next;
        }
        return false;
    }

    int displayMenu() {
        int choice;
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert at beginning\n";
        std::cout << "2. Insert at end\n";
        std::cout << "3. Insert at specific position\n";
        std::cout << "4. Delete from beginning\n";
        std::cout << "5. Delete from end\n";
        std::cout << "6. Delete from specific position\n";
        std::cout << "7. Print the linked list\n";
        std::cout << "8. Search linked list\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        return choice;
    }
};

int main() {
    LinkedList list;
    int choice, data, position;

    while (true) {
        choice = list.displayMenu();
        switch (choice) {
            case 1:
                std::cout << "Enter data: ";
                std::cin >> data;
                list.insertAtFirst(data);
                break;
            case 2:
                std::cout << "Enter data: ";
                std::cin >> data;
                list.insertAtEnd(data);
                break;
            case 3:
                std::cout << "Enter data: ";
                std::cin >> data;
                std::cout << "Enter position: ";
                std::cin >> position;
                list.insertAtPosition(data, position);
                break;
            case 4:
                list.deleteFromFirst();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                std::cout << "Enter position: ";
                std::cin >> position;
                list.deleteAtPosition(position);
                break;
            case 7:
                list.print();
                break;
            case 8:
                std::cout << "Enter data to search: ";
                std::cin >> data;
                if (list.search(data))
                    std::cout << "Data found\n";
                else
                    std::cout << "Data not found\n";
                break;
            case 9:
                return 0;
            default:
                std::cout << "Invalid choice\n";
        }
    }
}
