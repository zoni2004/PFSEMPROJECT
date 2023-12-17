#include <stdio.h>
#include <stdbool.h>

// Structure to represent cab driver information
struct CabDriver {
    char cnic[15];
    char name[10];
    char phoneNumber[11];
    char email[20];
    char cabNumber[6];
};

// Function to input cab driver details
void inputDriverDetails(struct CabDriver *driver) {
    printf("Enter CNIC Number: ");
    scanf("%s", driver->cnic);
    
    printf("Enter Name: ");
    scanf("%s", driver->name);

    printf("Enter Phone Number: ");
    scanf("%s", driver->phoneNumber);

    printf("Enter Email: ");
    scanf("%s", driver->email);

    printf("Enter Cab Number: ");
    scanf("%s", driver->cabNumber);
}

// Function to display cab driver details
void displayDriverDetails(struct CabDriver driver) {
    printf("\nCab Driver Details:\n");
    printf("CNIC Number: %s\n", driver.cnic);
    printf("Name: %s\n", driver.name);
    printf("Phone Number: %s\n", driver.phoneNumber);
    printf("Email: %s\n", driver.email);

    printf("Cab Number: %s\n", driver.cabNumber);
}

int main() {
    // Declare a structure to store cab driver details
    struct CabDriver cabDriver;

    // Input cab driver details
    inputDriverDetails(&cabDriver);

    // Display cab driver details
    displayDriverDetails(cabDriver);
return 0;

}
#include <stdio.h>
#include <stdbool.h>

// Structure to represent information about a cab
struct Cab {
    char numberPlate[6];
    char ownerName[20];
    char registrationNumber[20];
    char vehicleType[20];
    char insuranceProof[30];
    char driversLicense[20];
    bool isRegistered;
    bool isAvailable;
    char currentLocation[50];
};

// Function to check registration status and availability
void checkRegistrationAndAvailability(struct Cab *cab) {
    printf("Have you already registered? (1 for Yes / 0 for No): ");
    scanf("%d", &cab->isRegistered);

    if (!cab->isRegistered) {
        printf("You haven't registered. Please register first.\n");

        // Registration process
        printf("Enter Number Plate: ");
        scanf("%s", cab->numberPlate);

        printf("Enter Owner's Name: ");
        scanf("%s", cab->ownerName);

        printf("Enter Registration Number: ");
        scanf("%s", cab->registrationNumber);

        printf("Enter Vehicle Type (e.g., rickshaw, auto, bicycle, car): ");
        scanf("%s", cab->vehicleType);

        printf("Enter Proof of Auto Insurance: ");
        scanf("%s", cab->insuranceProof);

        printf("Enter Driver's License: ");
        scanf("%s", cab->driversLicense);

        cab->isRegistered = true; // Mark as registered after inputting details
        printf("Registration successful! Moving on.\n");
    }

    printf("Are you available right now? (1 for Yes / 0 for No): ");
    scanf("%d", &cab->isAvailable);

    if (cab->isAvailable) {
        printf("You are available. Proceeding...\n");
        printf("Enter your current location: ");
        scanf("%s", cab->currentLocation);
        printf("Location set to: %s\n", cab->currentLocation);
    } else {
        printf("You are not available right now.\n");
    }
}

// Function to display cab details
void displayCabDetails(struct Cab cab) {
    printf("\nCab Details:\n");
    printf("Number Plate: %s\n", cab.numberPlate);
    printf("Owner's Name: %s\n", cab.ownerName);
    printf("Registration Number: %s\n", cab.registrationNumber);
    printf("Vehicle Type: %s\n", cab.vehicleType);
    printf("Proof of Auto Insurance: %s\n", cab.insuranceProof);
    printf("Driver's License: %s\n", cab.driversLicense);
    printf("Is Registered: %s\n", cab.isRegistered ? "Yes" : "No");
    printf("Is Available: %s\n", cab.isAvailable ? "Yes" : "No");
    printf("Current Location: %s\n", cab.currentLocation);
}

int main() {
    // Declare a structure to store cab details
    struct Cab cabDetails;

    // Check registration status and availability
    checkRegistrationAndAvailability(&cabDetails);

    // Display cab details
    displayCabDetails(cabDetails);

    return 0;
}
#include <stdio.h>
#include <time.h>

// Structure to represent transportation information
struct Transportation {
    char destination[50];
    char vehicleType[20];
    float basePrice;
    float peakFactor;
};

// Function to initialize predefined transportation details
void initializeTransportation(struct Transportation *transport) {
    // Predefined transportation details
    transport->basePrice = 300.0;
    transport->peakFactor = 1.0; // Default peak factor

    // Add more predefined details as needed
}

// Function to check if the current time corresponds to peak hours
int isPeakTime() {
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    int currentHour = tm_info->tm_hour;
    int currentMinute = tm_info->tm_min;

    // Check for peak hours based on current time
    if ((currentHour >= 7 && currentHour < 9) ||    // Morning peak (school time on)
        (currentHour >= 16 && currentHour < 18)) {  // Afternoon peak (school time off, office off time)
        return 1; // Peak time
    }

    return 0; // Not peak time
}

int main() {
    // Declare a structure to store transportation details
    struct Transportation transportDetails;

    // Initialize transportation details
    initializeTransportation(&transportDetails);

    // Check if it's peak time
    if (isPeakTime()) {
        printf("It's peak time! Prices are increased.\n");
        transportDetails.peakFactor = 1.5; // Increase the peak factor as an example
    } else {
        printf("It's not peak time. Prices are normal.\n");
    }

    // User input for preferred destination and vehicle
    char userDestination[50];
    char userVehicleType[20];

    printf("Enter your destination: ");
    scanf("%s", userDestination);

    printf("Choose your preferred vehicle (Bike, Car, Rickshaw): ");
    scanf("%s", userVehicleType);

    // Calculate and display the final price
    float finalPrice = transportDetails.basePrice * transportDetails.peakFactor;
    printf("\nThe final price for Destination '%s' with Vehicle Type '%s' is $%.2f\n", userDestination, userVehicleType, finalPrice);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>

// Function to check if the user is already registered
bool isRegistered() {
    char response;

    printf("Are you already registered for transportation? (y/n): ");
    scanf(" %c", &response);

    // Check the user's response
    if (response == 'y' || response == 'Y') {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Call the function
    if (isRegistered()) {
        printf("You are already registered for transportation.\n");
    } else {
        printf("You are not registered for transportation yet.\n");
        // Add code here to handle the registration process if needed
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// Define a structure for driver information
struct Driver {
    int driverID;
    char name[50];
    char phoneNumber[15];
    char email[50];
    char cabNumber[20];
};

// Function to write driver information to a file
void writeToFile(const char *filename, struct Driver *driverArray, int numDrivers) {
    FILE *file = fopen(filename, "wb");
    
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fwrite(driverArray, sizeof(struct Driver), numDrivers, file);

    fclose(file);
}

// Function to read driver information from a file
struct Driver* readFromFile(const char *filename, int *numDrivers) {
    FILE *file = fopen(filename, "rb");
    
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    *numDrivers = fileSize / sizeof(struct Driver);
    
    struct Driver *driverArray = (struct Driver*)malloc(fileSize);
    if (driverArray == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    fread(driverArray, sizeof(struct Driver), *numDrivers, file);

    fclose(file);

    return driverArray;
}

int main() {
    // Example data
    struct Driver drivers[] = {
        {1, "John Doe", "123-456-7890", "john.doe@example.com", "ABC123"},
        {2, "Jane Smith", "987-654-3210", "jane.smith@example.com", "XYZ789"}
        // Add more drivers as needed
    };
    int numDrivers = sizeof(drivers) / sizeof(struct Driver);

    // Write data to file
    writeToFile("driver_data.dat", drivers, numDrivers);

    // Read data from file
    struct Driver *readDrivers;
    int readNumDrivers;
    readDrivers = readFromFile("driver_data.dat", &readNumDrivers);

    // Display read data
    for (int i = 0; i < readNumDrivers; i++) {
        printf("Driver ID: %d\n", readDrivers[i].driverID);
        printf("Name: %s\n", readDrivers[i].name);
        printf("Phone Number: %s\n", readDrivers[i].phoneNumber);
        printf("Email: %s\n", readDrivers[i].email);
        printf("Cab Number: %s\n\n", readDrivers[i].cabNumber);
    }

    // Free allocated memory
    free(readDrivers);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Driver {
    char numberPlate[10];
    char ownerName[20];
    char registrationNumber[20];
    char vehicleType[20];
    char insuranceProof[30];
    char driversLicense[20];
    bool isRegistered;
    bool isAvailable;
    char currentLocation[50];
};

// Function to write driver information to a file
void writeToFile(const char *filename, struct Driver *driverArray, int numDrivers) {
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fwrite(driverArray, sizeof(struct Driver), numDrivers, file);

    fclose(file);
}

// Function to read driver information from a file
struct Driver* readFromFile(const char *filename, int *numDrivers) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    *numDrivers = fileSize / sizeof(struct Driver);

    struct Driver *driverArray = (struct Driver*)malloc(fileSize);
    if (driverArray == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    fread(driverArray, sizeof(struct Driver), *numDrivers, file);

    fclose(file);

    return driverArray;
}

int main() {
    // Example data
    struct Driver drivers[] = {
        {"ABC123", "John Doe", "RN12345", "Sedan", "InsuranceProof1", "License123", true, true, "CurrentLocation1"},
        {"XYZ789", "Jane Smith", "RN67890", "SUV", "InsuranceProof2", "License456", true, false, "CurrentLocation2"}
        // Add more drivers as needed
    };
    int numDrivers = sizeof(drivers) / sizeof(struct Driver);

    // Write data to file
    writeToFile("driver_data.dat", drivers, numDrivers);

    // Read data from file
    struct Driver *readDrivers;
    int readNumDrivers;
    readDrivers = readFromFile("driver_data.dat", &readNumDrivers);

    // Display read data
    for (int i = 0; i < readNumDrivers; i++) {
        printf("Number Plate: %s\n", readDrivers[i].numberPlate);
        printf("Owner Name: %s\n", readDrivers[i].ownerName);
        printf("Registration Number: %s\n", readDrivers[i].registrationNumber);
        printf("Vehicle Type: %s\n", readDrivers[i].vehicleType);
        printf("Insurance Proof: %s\n", readDrivers[i].insuranceProof);
        printf("Driver's License: %s\n", readDrivers[i].driversLicense);
        printf("Is Registered: %s\n", readDrivers[i].isRegistered ? "Yes" : "No");
        printf("Is Available: %s\n", readDrivers[i].isAvailable ? "Yes" : "No");
        printf("Current Location: %s\n\n", readDrivers[i].currentLocation);
    }

    // Free allocated memory
    free(readDrivers);

    return 0;
}
