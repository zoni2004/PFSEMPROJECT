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

int main() 
{
    struct Transportation transportDetails;

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

    generateBill(userName, driverName, finalPrice, userDestination, userVehicleType);

    return 0;
}

