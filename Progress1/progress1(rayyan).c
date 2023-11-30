#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int isPeakTime() 
{
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    int currentHour = tm_info->tm_hour;
    int currentMinute = tm_info->tm_min;

    if ((currentHour >= 7 && currentHour < 9) ||    
        (currentHour >= 16 && currentHour < 18)) 
    {  
        return 1; // Peak time
    }

    return 0; // Not peak time
}

int calculatePrice(struct Transportation *transport, bool isPeakTime) 
{ 
    float finalPrice = transport->basePrice;

    if (isPeakTime) 
    {
        finalPrice *= transport->peakFactor;
    }

    return finalPrice;
}
/*
void generateBill(char userName[20], char driverName[20], float finalPrice, char pickupLocation[50], char dropoffLocation[50]) 
{
    printf("\n---------------------- Ride Hailing Bill -----------------------\n\n");
    printf("User Name: %s\n", userName);
    printf("Driver Name: %s\n", driverName);
    printf("Pickup Location: %s\n", pickupLocation);
    printf("Dropoff Location: %s\n", dropoffLocation);
    printf("Final Price: $%.2f\n", finalPrice);
    printf("\n----------------------------------------------------------------\n");
}
*/

void simulatePaymentProcessing(float finalPrice, int paymentMethod) 
{
    switch (paymentMethod) 
    {
        case 1:
            printf("Payment successful! You have paid with cash.\n");
            break;
        case 2:
            printf("Payment successful! You have paid with a debit card.\n");
            break;
        case 3:
            printf("Payment successful! You have paid with a credit card.\n");
            break;
        case 4:
            printf("Payment successful! You have paid with Easypaisa.\n");
            break;
        default:
            printf("Invalid payment method. Exiting...\n");
            exit(1);
    }
}


void rateDriver(struct CabDriver *driver) 
{
    int rating;
    printf("Rate your driver (1 to 5): ");
    scanf("%d", &rating);

    if (rating >= 1 && rating <= 5) 
    {
        driver->rating = (driver->rating + rating) / 2.0; // Calculate average rating
        printf("Thank you for your rating!\n");
    } else 
    {
        printf("Invalid rating. Please enter a number between 1 and 5.\n");
        rateDriver(driver); // Recursively ask for a valid rating
    }
}


// Enhanced function to generate the bill
void generateBill(struct User user, struct CabDriver driver, struct Transportation transport, float finalPrice) {
    printf("\n---------------------- Ride Hailing Bill -----------------------\n\n");
    
    printf("User Details:\n");
    printf("Name: %s\n", user.name);
    printf("Phone Number: %s\n", user.phoneNumber);
    printf("Contact Details: %s\n", user.contactDetails);

    printf("\nDriver Details:\n");
    printf("Name: %s\n", driver.name);
    printf("Phone Number: %s\n", driver.phoneNumber);
    printf("Email: %s\n", driver.email);
    printf("Cab Number: %s\n", driver.cabNumber);
    printf("Rating: %.2f\n", driver.rating);

    printf("\nRide Details:\n");
    printf("Destination: %s\n", transport.destination);
    printf("Vehicle Type: %s\n", transport.vehicleType);
    printf("Base Price: $%.2f\n", transport.basePrice);
    printf("Peak Factor: %.2f\n", transport.peakFactor);
    printf("Final Price: $%.2f\n", finalPrice);

    printf("\n----------------------------------------------------------------\n");
}


#include <stdio.h>

// Structure to represent feedback
struct DriverFeedback 
{
    int rating;
    char comments[100];
};

// Function to gather feedback from the driver
void provideDriverFeedback(struct CabDriver *driver) 
{
    struct DriverFeedback feedback;

    // Get rating from the driver
    printf("Rate your experience as a driver (1 to 5): ");
    scanf("%d", &feedback.rating);

    // Get comments from the driver
    printf("Provide comments (optional): ");
    scanf(" %[^\n]", feedback.comments);

    // Process or store the feedback as needed
    processDriverFeedback(driver, feedback);

    printf("Thank you for providing feedback!\n");
}



int main() 
{
    struct Transportation transportDetails; 
    struct cabDriver chosenDriver;

    initializeTransportation(&transportDetails);

    int isPeakTimeFlag = isPeakTime();

    char userDestination[50];
    char userVehicleType[20];

    printf("Enter your destination: ");
    scanf("%s", userDestination);

    printf("Choose your preferred vehicle (Bike, Car, Rickshaw): ");
    scanf("%s", userVehicleType);

    float finalPrice = calculatePrice(&transportDetails, isPeakTimeFlag);

    char userName[20];
    char driverName[20];

    printf("Enter your name: ");
    scanf("%s", userName);

    printf("Enter driver's name: ");
    scanf("%s", driverName);

    //generateBill(userName, driverName, finalPrice, userDestination, userVehicleType);
    generateBill(userDetails, chosenDriver, transportDetails, finalPrice);
    
    simulatePaymentProcessing(finalPrice, userDetails.paymentMethod);

    rateDriver(&chosenDriver);

     provideDriverFeedback(&chosenDriver);

    return 0;
}

