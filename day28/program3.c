#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKETS 50
#define NAME_LEN 50

typedef struct {
    int ticketID;
    char name[NAME_LEN];
    int age;
    int isBooked; 
} Ticket;

Ticket tickets[MAX_TICKETS];

void initializeTickets() {
    for (int i = 0; i < MAX_TICKETS; i++) {
        tickets[i].ticketID = i + 1;
        tickets[i].isBooked = 0;
        strcpy(tickets[i].name, "");
        tickets[i].age = 0;
    }
}

void viewAvailableTickets() {
    printf("\n--- Available Tickets ---\n");
    int availableCount = 0;
    for (int i = 0; i < MAX_TICKETS; i++) {
        if (!tickets[i].isBooked) {
            printf("Ticket ID: %d\n", tickets[i].ticketID);
            availableCount++;
        }
    }
    if (availableCount == 0) {
        printf("No tickets available.\n");
    }
}

void bookTicket() {
    int id;
    printf("\nEnter Ticket ID to book (1-%d): ", MAX_TICKETS);
    if (scanf("%d", &id) != 1 || id < 1 || id > MAX_TICKETS) {
        printf("Invalid Ticket ID.\n");
        while (getchar() != '\n'); 
        return;
    }

    if (tickets[id - 1].isBooked) {
        printf("Ticket already booked.\n");
        return;
    }

    printf("Enter Name: ");
    while (getchar() != '\n'); // clear buffer
    fgets(tickets[id - 1].name, NAME_LEN, stdin);
    tickets[id - 1].name[strcspn(tickets[id - 1].name, "\n")] = '\0'; // remove newline

    printf("Enter Age: ");
    if (scanf("%d", &tickets[id - 1].age) != 1 || tickets[id - 1].age <= 0) {
        printf("Invalid age.\n");
        while (getchar() != '\n');
        return;
    }

    tickets[id - 1].isBooked = 1;
    printf("Ticket %d booked successfully for %s.\n", id, tickets[id - 1].name);
}

void cancelTicket() {
    int id;
    printf("\nEnter Ticket ID to cancel: ");
    if (scanf("%d", &id) != 1 || id < 1 || id > MAX_TICKETS) {
        printf("Invalid Ticket ID.\n");
        while (getchar() != '\n');
        return;
    }

    if (!tickets[id - 1].isBooked) {
        printf("Ticket is not booked.\n");
        return;
    }

    tickets[id - 1].isBooked = 0;
    strcpy(tickets[id - 1].name, "");
    tickets[id - 1].age = 0;
    printf("Ticket %d canceled successfully.\n", id);
}

void viewBookedTickets() {
    printf("\n--- Booked Tickets ---\n");
    int bookedCount = 0;
    for (int i = 0; i < MAX_TICKETS; i++) {
        if (tickets[i].isBooked) {
            printf("Ticket ID: %d | Name: %s | Age: %d\n",
                   tickets[i].ticketID, tickets[i].name, tickets[i].age);
            bookedCount++;
        }
    }
    if (bookedCount == 0) {
        printf("No tickets booked.\n");
    }
}

int main() {
    int choice;
    initializeTickets();

    while (1) {
        printf("\n===== Ticket Booking System =====\n");
        printf("1. View Available Tickets\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. View Booked Tickets\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1: viewAvailableTickets(); break;
            case 2: bookTicket(); break;
            case 3: cancelTicket(); break;
            case 4: viewBookedTickets(); break;
            case 5: printf("Exiting... Thank you!\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
