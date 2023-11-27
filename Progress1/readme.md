##Programmers:
1.	Zunaira Amjad (23k-0013)
2.	Tanisha Kataris (23k-0067)
3.	Rayyan Merchant (23k-0073)
Desc: Call a cab


A.	USER INPUT:
1.	Login and password:
●	Asking for a set email and password
●	Will ask the user for email and password 
●	Will verify the email and password 
●	If correct then will let the user book a ride else will print a message
●	CODING TECHNIQUES USED:
a.	Functions
b.	Strings
c.	Loops
d.	Conditional statements
e.	Booleans
●	Code:
//asking user to set an email and password
void user_login_setup(char set_email[20], char set_pass[8]){
    printf ("Enter the email you want to make an account with");
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
            printf ("Invalid Input. Make sure you only add a valid email account");
        }
    }
    printf ("Enter a unique 8 characters password");
    scanf ("%s" , set_pass);
    int size = strlen(set_pass); //using string function to find the size of the input character
    //checking the size for the password for validity
    if (size != 8){
        printf ("Invalid password. Only allows 8 characters");
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
    user_login_input(s_m[20], s_p[8]);
    if ((strcmp(s_m[20], email[20])) == 0){
        if ((strcmp(p_m[20], pass[20])) == 0){
            printf ("WELCOME TO CALL-A-CAB");
            return true;
        }
        else {
            printf ("Invalid Input. Kindly make sure that your email and password is correct");
            return false;
        }
    }
}
/*PROBLEMS:
1. WILL WE ASK FOR EMAIL EVERY TIME THEY OPEN THE APP?
2. WILL THE CHECK INCLUDE MAIL CHECK TOO
*/





2.	Car Options:
●	Give options for different types of vehicles
●	Providing options with the help of numbers provided in the print statement
●	CODING TECHNIQUES USED:
a.	Functions
b.	Arrays
●	Code:
//taking the input of the type of vehicle form user
int vehicle_option(char vehicle[6]){
    vehicle[6] = {"Bike" , "Ride AC", "Ride", "Premium", "Ride Mini"};
    //asking the user to choose options with the help of numbers
    printf ("Please select your vehicle of choice");
    int c;
    printf ("1: Bike\t2: RideAC\t3: Ride\t4: Premium\t5: Ride Mini");
    scanf ("%d" ,&c);

return c;
}
/*PROBLEMS:
1. WILL WE PROVIDE BASE PRICE OF CARS OR ONLY CHARGE ACCORDING TO THE DISTANCE?
2. WILL THE CHOICE BE DONE USING NUMBERS OR ANOTHER WAY (AS CHARACTERS)?
*/


3.	Location:
●	Will be predefined with set destinations for pickup and dropoff
●	Take input in the form of integer
●	CODING TECHNIQUES USED:
a.	Functions
b.	Arrays
c.	Structures (could be used) Structures (could be used)

●	Code
int location(char locat_pickup[2], char locat_dropoff[2]){
    locat_pickup[2] = {"1. FAST-NUCES \t", "2. MILLENIUM MALL"};
    locat_dropoff[2] = {"1. FAST-NUCES \t", "2. MILLENIUM MALL"};
    printf ("The locations available are as follows:\n");
    for (int i=0; i<2; i++){
        printf ("%s" , locat_pickup);
    }
    int pc,do;
    printf ("Enter the location number you want to be picked up from:");
    scanf ("%d" ,&pc);
    printf ("Enter the location number you want to be picked up from:");
    scanf ("%d" ,&do);

return pc; //ISSUE!
}
/*PROBLEMS:
1. HOW WILL WE FIND OR INITIALIZE THE DISTANCE?
2. HOW TO OUTPUT BOTH THE DROP OFF AND PICK UP LOCATION? SHOULD WE USE STRUCTS OR JUST MAKE TWO DIFF FUNCTIONS FOR IT (DON'T LIKE THE OPTION TOO MUCH)?
*/


4.	Prices:
•	Will be predefined with set destinations for prices and vehicle transportation.
•	Take input in the form of integer
•	CODING TECHNIQUES USED:
a)	Functions
b)	Arrays
c)	Structures (could be used)

•	CODE:
 


5. Peak Factor:
•	Will be predefined with set peak factor (average load and maximum load)
•	Take input in the form of integer
•	CODING TECHNIQUES USED:
a)	FUNCTIONS
b)	STRUCTURES (could be used)
c)	Arrays

 
 


