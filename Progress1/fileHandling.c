#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void saveRideInformation(struct User user, struct CabDriver driver, struct Transportation transport, float finalPrice) {
    FILE *file = fopen("ride_information.txt", "a"); // Open the file in append mode

    if (file == NULL) {
        printf("Error opening file for saving ride information.\n");
        return;
    }

    fprintf(file, "\n---------------------- Ride Information -----------------------\n\n");
    
    fprintf(file, "User Details:\n");
    fprintf(file, "Name: %s\n", user.name);
    fprintf(file, "Phone Number: %s\n", user.phoneNumber);
    fprintf(file, "Contact Details: %s\n", user.contactDetails);

    fprintf(file, "\nDriver Details:\n");
    fprintf(file, "Name: %s\n", driver.name);
    fprintf(file, "Phone Number: %s\n", driver.phoneNumber);
    fprintf(file, "Email: %s\n", driver.email);
    fprintf(file, "Cab Number: %s\n", driver.cabNumber);
    fprintf(file, "Rating: %.2f\n", driver.rating);

    fprintf(file, "\nRide Details:\n");
    fprintf(file, "Destination: %s\n", transport.destination);
    fprintf(file, "Vehicle Type: %s\n", transport.vehicleType);
    fprintf(file, "Base Price: $%.2f\n", transport.basePrice);
    fprintf(file, "Peak Factor: %.2f\n", transport.peakFactor);
    fprintf(file, "Final Price: $%.2f\n", finalPrice);

    fprintf(file, "\n----------------------------------------------------------------\n");

    fclose(file); // Close the file
}

void saveCreditCardInfo(struct User user) {
    FILE *file = fopen("credit_card_info.txt", "a"); // Open the file in append mode

    if (file == NULL) {
        printf("Error opening file for saving credit card information.\n");
        return;
    }

    fprintf(file, "\n---------------------- Credit Card Information -----------------------\n\n");
    
    fprintf(file, "User Details:\n");
    fprintf(file, "Name: %s\n", user.name);
    fprintf(file, "Phone Number: %s\n", user.phoneNumber);
    fprintf(file, "Credit Card Number: %s\n", user.creditCardNumber);

    fprintf(file, "\n------------------------------------------------------------------------\n");

    fclose(file); // Close the file
}


void saveUserFeedback(struct User user, struct DriverFeedback feedback) {
    FILE *file = fopen("user_feedback.txt", "a");

    if (file == NULL) {
        printf("Error opening file for saving user feedback.\n");
        return;
    }

    fprintf(file, "\n---------------------- User Feedback -----------------------\n\n");
    fprintf(file, "User Details:\n");
    fprintf(file, "Name: %s\n", user.name);
    fprintf(file, "Phone Number: %s\n", user.phoneNumber);

    fprintf(file, "\nFeedback:\n");
    fprintf(file, "Rating: %d\n", feedback.rating);
    fprintf(file, "Comments: %s\n", feedback.comments);

    fprintf(file, "\n----------------------------------------------------------------\n");

    fclose(file);
}



void savePaymentDetails(struct User user, int paymentMethod, float finalPrice) {
    FILE *file = fopen("payment_details.txt", "a");

    if (file == NULL) {
        printf("Error opening file for saving payment details.\n");
        return;
    }

    fprintf(file, "\n---------------------- Payment Details -----------------------\n\n");
    fprintf(file, "User Details:\n");
    fprintf(file, "Name: %s\n", user.name);
    fprintf(file, "Phone Number: %s\n", user.phoneNumber);

    fprintf(file, "\nPayment Details:\n");
    fprintf(file, "Payment Method: %d\n", paymentMethod);
    fprintf(file, "Final Price: $%.2f\n", finalPrice);

    fprintf(file, "\n----------------------------------------------------------------\n");

    fclose(file);
}



void saveLog(const char *logMessage) {
    FILE *file = fopen("program_log.txt", "a");

    if (file == NULL) {
        printf("Error opening file for saving program log.\n");
        return;
    }

    time_t currentTime;
    time(&currentTime);
    struct tm *tm_info = localtime(&currentTime);

    fprintf(file, "[%04d-%02d-%02d %02d:%02d:%02d] %s\n",
            tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday,
            tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec, logMessage);

    fclose(file);
}



