#!/bin/bash

# Define the linked list as an array
linked_list=()

# Function to insert a new element at the beginning of the linked list
insert_at_first() {
    linked_list=("$1" "${linked_list[@]}")
}

# Function to insert a new element at the end of the linked list
insert_at_end() {
    linked_list+=("$1")
}

# Function to insert a new element at a specific position in the linked list
insert_at_position() {
    local position=$2
    linked_list=("${linked_list[@]:0:$position}" "$1" "${linked_list[@]:$position}")
}

# Function to delete the first element of the linked list
delete_from_first() {
    linked_list=("${linked_list[@]:1}")
}

# Function to delete the last element of the linked list
delete_from_end() {
    unset linked_list[-1]
}

# Function to delete an element at a specific position in the linked list
delete_at_position() {
    local position=$1
    linked_list=("${linked_list[@]:0:$position}" "${linked_list[@]:$((position + 1))}")
}

# Function to print the linked list
print_list() {
    for element in "${linked_list[@]}"; do
        echo -n "$element -> "
    done
    echo "NULL"
}

# Function to search for an element in the linked list
search_list() {
    local element=$1
    for item in "${linked_list[@]}"; do
        if [ "$item" -eq "$element" ]; then
            echo "Element found"
            return
        fi
    done
    echo "Element not found"
}

# Display menu and handle user input
while true; do
    echo "Menu:"
    echo "1. Insert at beginning"
    echo "2. Insert at end"
    echo "3. Insert at specific position"
    echo "4. Delete from beginning"
    echo "5. Delete from end"
    echo "6. Delete from specific position"
    echo "7. Print the linked list"
    echo "8. Search linked list"
    echo "9. Exit"
    read -p "Enter your choice: " choice

    case $choice in
        1) read -p "Enter data: " data
           insert_at_first "$data"
           ;;
        2) read -p "Enter data: " data
           insert_at_end "$data"
           ;;
        3) read -p "Enter data: " data
           read -p "Enter position: " position
           insert_at_position "$data" "$position"
           ;;
        4) delete_from_first
           ;;
        5) delete_from_end
           ;;
        6) read -p "Enter position: " position
           delete_at_position "$position"
           ;;
        7) print_list
           ;;
        8) read -p "Enter element to search: " element
           search_list "$element"
           ;;
        9) exit 0
           ;;
        *) echo "Invalid choice"
           ;;
    esac
done
