#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 50

struct Ticket {
    int seatNumber;
    char passengerName[50];
    int isBooked;
};

struct Ticket systemSeats[MAX_SEATS];

void initializeSystem() {
    for (int i = 0; i < MAX_SEATS; i++) {
        systemSeats[i].seatNumber = i + 1;
        systemSeats[i].passengerName[0] = '\0';
        systemSeats[i].isBooked = 0;
    }
}

void displaySeats() {
    printf("\n--- Seat Status ---\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (systemSeats[i].isBooked) {
            printf("[%02d: B]  ", systemSeats[i].seatNumber);
        } else {
            printf("[%02d: A]  ", systemSeats[i].seatNumber);
        }
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
}

void bookTicket() {
    int seatNum;
    displaySeats();
    printf("\nEnter seat number to book (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNum);

    if (seatNum < 1 || seatNum > MAX_SEATS) {
        printf("Error: Invalid seat number.\n");
        return;
    }

    if (systemSeats[seatNum - 1].isBooked) {
        printf("Error: Seat %d is already booked.\n", seatNum);
        return;
    }

    printf("Enter passenger name: ");
    while (getchar() != '\n'); 
    fgets(systemSeats[seatNum - 1].passengerName, 50, stdin);
    systemSeats[seatNum - 1].passengerName[strcspn(systemSeats[seatNum - 1].passengerName, "\n")] = '\0';

    systemSeats[seatNum - 1].isBooked = 1;
    printf("Success: Seat %d booked successfully for %s.\n", seatNum, systemSeats[seatNum - 1].passengerName);
}

void cancelTicket() {
    int seatNum;
    printf("\nEnter seat number to cancel (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNum);

    if (seatNum < 1 || seatNum > MAX_SEATS) {
        printf("Error: Invalid seat number.\n");
        return;
    }

    if (!systemSeats[seatNum - 1].isBooked) {
        printf("Error: Seat %d is not currently booked.\n", seatNum);
        return;
    }

    printf("Success: Booking for %s at seat %d has been canceled.\n", systemSeats[seatNum - 1].passengerName, seatNum);
    systemSeats[seatNum - 1].passengerName[0] = '\0';
    systemSeats[seatNum - 1].isBooked = 0;
}

void searchTicket() {
    char name[50];
    int found = 0;
    printf("\nEnter passenger name to search: ");
    while (getchar() != '\n');
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("\n--- Search Results ---\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (systemSeats[i].isBooked && strcmp(systemSeats[i].passengerName, name) == 0) {
            printf("Passenger: %s | Seat Number: %d\n", systemSeats[i].passengerName, systemSeats[i].seatNumber);
            found = 1;
        }
    }

    if (!found) {
        printf("No records found for passenger: %s\n", name);
    }
}

int main() {
    int choice;
    initializeSystem();

    while (1) {
        printf("\n=================================");
        printf("\n     TICKET BOOKING SYSTEM       ");
        printf("\n=================================");
        printf("\n1. View Seat Map");
        printf("\n2. Book a Ticket");
        printf("\n3. Cancel a Ticket");
        printf("\n4. Search Passenger Ticket");
        printf("\n5. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                searchTicket();
                break;
            case 5:
                printf("\nThank you for using the ticket system.\n");
                exit(0);
            default:
                printf("Error: Invalid choice. Try again.\n");
        }
    }
    return 0;
}
