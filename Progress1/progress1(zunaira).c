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
#include <time.h>

//asking if logging in as driver or customer
char identification (char identity) {
    printf ("Press \"d\" if driver and \"c\" if user:");
    scanf ("%c" ,&identity);

return identity;
}
//WILL ADD IF STATEMENT IN MAIN FOR USER AND DRIVER AND MOVE ON FROM THERE

/*
*
*
DEALING WITH THE USER
*
*
*/
//asking user to set an username and password
void user_login_setup(int phone_number, char set_pass[8]){
    printf ("Enter the phone number\n");
    scanf ("%s" , phone_number);
    //validating the phone number (making sure it is 11 digits)
    int rem;
    int quotient;
    int count=0;
    //if the number isnt less than 10 in 8 attempts to make it a single integer than it is not equal to 11 digits
    do{
        rem = phone_number%10;
        quotient = phone_number/10;
        phone_number = quotient;
        count++;
    }while (phone_number>10);

    if (count != 8){
        printf ("Invalid Input. Make sure you enter the right number");
    }
    //if the number is verified than we ask for password
    else if (count == 8){
         printf ("Enter a unique 8 characters passowrd\n");
         scanf ("%s" , set_pass);
         int size = strlen(set_pass); //using string function to find the size of the input character
         //checking the size for the password for validity
         if (size != 8){
         printf ("Invalid password. Only allows 8 characters\n");
         }
    }
}
/*PROBLEMS:
1.STORE DATA IN FILING 
*/

//bool function to input and check phone number and password
bool user_login_input(char number, char pass[8]){
    printf ("Phone number:\t");
    scanf ("%d" , number);
    //calling the set email and password function
    char s_m[20],s_p[8];
    //validating the phone number (making sure it is 11 digits)
    int check_rem;
    int check_quotient;
    int check_count=0;
    //if the number isnt less than 10 in 8 attempts to make it a single integer than it is not equal to 11 digits
    do{
        check_rem = number%10;
        check_quotient = number/10;
        number = check_quotient;
        check_count++;
    }while (number>10);
    user_login_setup(s_m[20], s_p[8]);
    if (check_count == 8){
        if ((strcmp(s_p[20], pass[20])) == 0){
            printf ("WELCOME TO CALL-A-CAB\n");
            return true;
        }
        else {
            printf ("Invalid Input. Kindly make sure that your phone number and password is correct\n");
            return false;
        }
    }
}
/*PROBLEMS:
1. WILL STORE THE PREVIOUS DATA IN FILING AND THEN CHECK
*/ 

//asking user if already signed up or not
void signing_up(int su){
    printf ("If you already have an account press 1 and if not then press 0\n");
    scanf ("%d" ,&su);
    char pn,sp[20],n,p[20];
    if (su == 0){
        user_login_setup(pn,sp[20]);
    }
    else if (su == 1){
        user_login_input(n,p[20]);
    }
}

//taking the input of the type of vehicle form user
int vehicle_option(int c){
    //asking the user to choose options with the help of numbers
    printf ("Please select your vehicle of choice\n");
    printf ("1: Bike\t2: RideAC\t3: Ride\t4: Premium\t5: Ride Mini");
    scanf ("%d" ,&c);

return c;
}

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


//choosing payment methods
int payment_method (int pm){
    printf ("Enter your preferred method");
    printf ("1.CASH, 2.DEBIT CARD, 3.CREDIT CARD, 4.EASYPAISA");
    scanf ("%d" ,pm);
return pm;
}

struct locat {
    int location_pickup;
    int location_dropoff;
};
//finding the cost of the drive using predefined locations
int locat(struct locat locations, int location_info[4][2]){
    printf ("Choose the pick-up location:\n");
    printf ("1.FAST-NU\t", "2.MILLENIUM MALL\t", "3.LUCKY ONE\t", "4.ASKARI PARK\t\n");
    scanf ("%d\n" ,&locations.location_pickup);
    printf ("Choose the drop-off location:\n");
    printf ("1.FAST-NU\t", "2.MILLENIUM MALL\t", "3.LUCKY ONE\t", "4.ASKARI PARK\t\n");
    scanf ("%d\n" ,&locations.location_dropoff);
    int cost;
    location_info[4][2] = {{1,0}, {2,500}, {3,500}, {4,500}};
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (location_info[i][1] == locations.location_pickup){
                if (location_info[j][1] == locations.location_dropoff){
                    cost = location_info[i][1] + location_info[j][1];
                }
             }        
         }
     }
return cost;
}
/*PROBLEMS:
1. HOW WILL WE FIND OR INTIALIZE THE DISTANCE?
3. DECIDE LOCATIONS
*/

int main (){

    return 0;
}
