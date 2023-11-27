/*
*
*
*
Programmers:
1. Zunaira Amjad (23k-0013)
2. Tanisha Kataria (23k-0067)
3. Rayyan Merchant (23k-0073)
Desc: Online cab service
*
*
*
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//asking user to set an email and password 
void user_login_setup(char set_email[20], char set_pass[8]){
    printf ("Enter the email you want to make an account with\n");
    scanf ("%s" , set_email);
    int b;
    //finding the index at which @ occurs to check for a valid email account
    for (int i=0; i<20; i++){
         if (strchr(set_email, "@") == set_email[i]){
            b = i;
         }
    }
    //checking for the correct email using comparison in strings
    for (int i=b; i<20; i++){
        if ((strcmp(set_email, "gmail.com")) != 0){
            printf ("Invalid Input. Make sure you only add a valid email account\n");
        }
    }
    printf ("Enter a unique 8 characters passowrd\n");
    scanf ("%s" , set_pass);
    int size = strlen(set_pass); //using string function to find the size of the input character
    //checking the size for the password for validity
    if (size != 8){
        printf ("Invalid password. Only allows 8 characters\n");
    }
}
/*PROBLEMS:
1. HOW TO ASK FOR THIS ONLY AT THE START AND THEN NEVER AGAIN
2. WOULD WE ALLOW DIFFERENT EMAIL AND GIVE OPTIONS TO SELECT FROM?
3. MAKE SPECIAL CHARACTERS AND STRONG PASSWORDS?
*/ 

//bool function to input and check email and password
bool user_login_input(char email[20], char pass[8]){
    printf ("Email:\t");
    scanf ("%s" , email[10]);
    //calling the set email and password function
    char s_m[20],s_p[8];
    user_login_setup(s_m[20], s_p[8]);
    //using string comparison function to match emails and passwords to login
    if ((strcmp(s_m[20], email[20])) == 0){
        if ((strcmp(s_p[20], pass[20])) == 0){
            printf ("WELCOME TO CALL-A-CAB\n");
            return true;
        }
        else {
            printf ("Invalid Input. Kindly make sure that your email and password is correct\n");
            return false;
        }
    }
}
/*PROBLEMS:
1. WILL WE ASK FOR EMAIL EVERY TIME THEY OPEN THE APP?
2. WILL THE CHECK INCLUDE MAIL CHECK TOO
*/ 

//taking the input of the type of vehicle form user
int vehicle_option(char vehicle[6][10]){
    vehicle[6][10] = {"Bike" , "Ride AC", "Ride", "Premium", "Ride Mini"};
    //asking the user to choose options with the help of numbers
    printf ("Please select your vehicle of choice\n");
    int c;
    printf ("1: Bike\t2: RideAC\t3: Ride\t4: Premium\t5: Ride Mini");
    scanf ("%d" ,&c);

return c;
}
/*PROBLEMS:
1. WILL WE PROVIDE BASE PRICE OF CARS OR ONLY CHARGE ACCORDING TO THE DISTANCE?
2. WILL THE CHOICE BE DONE USING NUMBERS OR ANOTHER WAY (AS CHRACTERS)?
*/

//storing credit and debit card info for payment use
struct credit_card_info {
    int c_card_no;
    int c_expiry_date;
    int c_cvv_no;
};

//will use this function if the user is using credit card for the first time
void credit_card_info_input (struct credit_card_info cci) {
    printf ("Enter the card number\n");
    scanf ("%d\n" , &cci.c_card_no);
    printf ("Enter the expiry date of the card\n");
    scanf ("%d\n" , &cci.c_expiry_date);
    printf ("Enter the CVV/CVS number\n");
    scanf ("%d\n" , &cci.c_cvv_no);
}

struct debit_card_info {
    int d_card_no;
    int d_expiry_date;
    int d_cvv_no;
};

//will use this function if the user is using debit card for the first time
void debit_card_info_input (struct debit_card_info dci){
    printf ("Enter the card number\n");
    scanf ("%d\n" , &dci.d_card_no);
    printf ("Enter the expiry date of the card\n");
    scanf ("%d\n" , &dci.d_expiry_date);
    printf ("Enter the CVV/CVS number\n");
    scanf ("%d\n" , &dci.d_cvv_no);
}

//will use this when the payment option is through stored credit
int stored_credit (int sc){
    int return_money;
    //initialize previous store credit in the main function
    printf ("Enter return money");
    scanf ("%d" ,&return_money);
    //if have to retrun money in case of wrong or canceled order
    sc += return_money;
return sc;
}
/*PROBLEMS:
1. WILL WE ADD THE OPTION OF CONVERTING CREDIT CARD OR CASH INTO STORED CREDIT IF ORDER CANCELED OR HAVE TO COMPENSATE?
2. HOW WILL STORE CREDIT WORK?
3. HOW TO STORE MONEY IN THE STORE CREDIT? USING DMA OR FILING?
*/

//choosing payment methods
int payment_method (int pm){
    printf ("Enter your preferred method");
    printf ("1.CASH, 2.DEBIT CARD, 3.CREDIT CARD, 4.EASYPAISA, 5.STORED CREDIT");
    scanf ("%d" ,pm);
return pm;
}

//finding the cost of the drive using predefined locations
int locat(int loc_p, int loc_d, int location_info[4][2]){
    printf ("Choose the pick-up location:\n");
    printf ("1.FAST-NU\t", "2.MILLENIUM MALL\t", "3.LUCKY ONE\t", "4.ASKARI PARK\t\n");
    scanf ("%d\n" ,&loc_p);
    printf ("Choose the drop-off location:\n");
    printf ("1.FAST-NU\t", "2.MILLENIUM MALL\t", "3.LUCKY ONE\t", "4.ASKARI PARK\t\n");
    scanf ("%d\n" ,&loc_d);
    int cost;
    location_info[4][2] = {{1,0}, {2,500}, {3,500}, {4,500}};
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (location_info[i][1] == loc_p){
                if (location_info[j][1] == loc_d){
                    cost = location_info[i][1] + location_info[j][1];
                }
             }        
         }
     }
return cost;
}
/*PROBLEMS:
1. HOW WILL WE FIND OR INTIALIZE THE DISTANCE?
2. HOW TO OUTPUT BOTH THE DROP OFF AND PICK UP LOCATION? SHOULD WE USE STRUCTS OR JUST MAKE TWO DIFF FUNCTIONS FOR IT (DONT LIKE THE OPTION TOO MUCH)?
3. DECIDE LOCATIONS
*/

int main (){

    return 0;
}
