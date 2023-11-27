// Structure to represent transportation information
struct Transportation {
    char destination[50];
    char vehicleType[20];
    float price;
};

// Function to input transportation details
void inputTransportation(struct Transportation transport[], int n) {
    printf("\nEnter Transportation Details:\n");
    for (int i = 0; i < n; ++i) {
        printf("\nTransportation %d:\n", i + 1);
        printf("Enter Destination: ");
        scanf("%s", transport[i].destination);
        printf("Enter Vehicle Type: ");
        scanf("%s", transport[i].vehicleType);
        printf("Enter Price: ");
        scanf("%f", &transport[i].price);
    }
}

// Function to display transportation details
void displayTransportation(struct Transportation transport[], int n) {
    printf("\nTransportation Details:\n");
    printf("%-20s%-20s%-10s\n", "Destination", "Vehicle Type", "Price");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < n; ++i) {
        printf("%-20s%-20s%-10.2f\n", transport[i].destination, transport[i].vehicleType, transport[i].price);
    }
}

int main() {
    // Define the maximum number of transportation details
    const int MAX_TRANSPORTATIONS = 5;

    // Declare an array of structures to store transportation details
    struct Transportation transportationDetails[MAX_TRANSPORTATIONS];

    // Input transportation details
    inputTransportation(transportationDetails, MAX_TRANSPORTATIONS);

    // Display transportation details
    displayTransportation(transportationDetails, MAX_TRANSPORTATIONS);

    return 0;
}
#include <stdio.h>
#include <string.h>

// Structure to represent a cab
struct Cab {
    int cabID;
    char driverName[50];
    float basePrice;
};

// Function to calculate the peak pricing multiplier based on demand
float calculatePeakMultiplier(int hour) {
    // Simple peak pricing logic (you can customize based on your needs)
    if ((hour >= 9 && hour <= 10) || (hour >= 18 && hour <= 19)) {
        return 1.5; // Peak demand hours, increase the price
    } else {
        return 1.0; // Non-peak hours, normal price
    }
}

// Function to book a cab
void bookCab(struct Cab cabs[], int numCabs, int hour) {
    int cabID;
    printf("Enter the cab ID you want to book: ");
    scanf("%d", &cabID);

    if (cabID < 1 || cabID > numCabs) {
        printf("Invalid cab ID. Please enter a valid cab ID.\n");
        return;
    }

    float peakMultiplier = calculatePeakMultiplier(hour);
    float totalPrice = cabs[cabID - 1].basePrice * peakMultiplier;

    printf("\nBooking Details:\n");
    printf("Cab ID: %d\n", cabs[cabID - 1].cabID);
    printf("Driver Name: %s\n", cabs[cabID - 1].driverName);
    printf("Total Price: $%.2f\n", totalPrice);

    // Ask the user if they agree to pay the peak pricing
    char choice[10];
    printf("Do you agree to pay the peak pricing? (Type 'yes' or 'no'): ");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0) {
        printf("Thank you for accepting the peak pricing. Your ride is booked!\n");
    } else {
        printf("You chose not to accept the peak pricing. You can try again later or select a different category.\n");
    }
}

int main() {
    // Define an array of cabs
    struct Cab cabs[] = {
        {1, "John Doe", 10.0},
        {2, "Jane Smith", 12.0},
        {3, "Bob Johnson", 15.0},
        // Add more cabs as needed
    };

    int numCabs = sizeof(cabs) / sizeof(cabs[0]);

    // Get the current hour from the user
    int currentHour;
    printf("Enter the current hour (0-23): ");
    scanf("%d", &currentHour);

    // Display available cabs
    printf("\nAvailable Cabs:\n");
    printf("CabID\tDriver Name\tBase Price\n");
    for (int i = 0; i < numCabs; i++) {
        printf("%d\t%s\t\t$%.2f\n", cabs[i].cabID, cabs[i].driverName, cabs[i].basePrice);
    }

    // Book a cab
    bookCab(cabs, numCabs, currentHour);

    return 0;
}
