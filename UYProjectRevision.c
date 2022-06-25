#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*
    Author: Usman Yousef
    Date: 05-04-2021
    Description: This program is made for a tool rental company to handle their customers, tools, and transactions
*/

//prototypes:
//menu functions
void DisplayMainMenu();
void DisplayCustomerMenu();
void DisplayToolMenu();
void DisplayTransactionMenu();
//tool functions:
void PopulateTools();
void AddTool();
void SearchTool();
void DisplayTool();
void CheckToolID();
void CheckToolType();
void CheckRentRate();
//customer functions:
void AddCustomer();
void SearchCustomer();
void CheckCustomerID();
bool CheckName();
bool CheckPhoneNum();
bool CheckEmail();
void DisplayCustomer();
//transaction functions:
void CheckRentPeriod();
void CalcRentFee();
void AddTransaction();
void SearchTransaction(); //searches by: customer ID (multiple hits possible), tool ID (one hit), OR BOTH
void DisplayTransaction();

//structures:
struct Tool
{//18 byte struct
    char toolID; //char = 1 byte
    char toolType;
    double fullRent; //double = 8 bytes
    double halfRent;
}typedef Tool; //typdef used to create new data type
//end of Tool
struct Customer
{//5 byte struct
    char customerID[6];
    char firstName;
    char lastName;
    char phoneNum;
    char email;
}typedef Customer;
//end of Customer
struct Transaction
{//11 byte struct
    char customerID;
    char toolID;
    char rentPeriod;
    double rentFee;
}typedef Transaction;
//end of Transaction
                        //is Tool* ptr_tool[3] equivalent to ptr_tool = malloc(3*sizeof(Tool))? If so, how is malloc dynamic?
int main()
{
    //declarations:
    //menu selections
    int startSelect = 0;
    int mMenuSelect = 0;
    int cMenuSelection = 0;
    int tMenuSelection = 0;
    //pointers to structs - declare struct in main and point if size known (I.E: struct name; ptr_name = &name;) or use malloc for dynamic
    Customer* ptr_customer = malloc(100*sizeof(Customer));
    Tool* ptr_tool = malloc(100*sizeof(Tool));
    Transaction* ptr_transaction = malloc(100*sizeof(Transaction));
    //total counts:
    int totalCustomers = 0;
    int totalTools = 4;
    int totalTransactions = 0;

    do{ //loop to restart the program
        printf("Would you like to start the program?\n"
               "1- Yes \n"
               "0- No \n");
        scanf("%d", startSelect);
        while (startSelect != 1 && startSelect != 0) //validation loop for program start selection
        {
            printf("Incorrect input! Please enter:\n"
                   "1- Yes \n"
                   "0- No \n
            scanf("%d", startSelect);
        }//end while
        if (startSelect == 0)
        {
            printf("Thank you for using ToolX. Goodbye! \n");
        }//end if
        else
        {
            DisplayMainMenu();
            scanf("%d", mMenuSelect);
            while(mMenuSelect < 0 || mMenuSelect > 4) //validation loop for menu selection
            {
                system("cls");
                printf("Incorrect input!\n");
                DisplayMainMenu;
                scanf("%d", mMenuSelect);
            }//end while
            switch(mMenuSelect)
            {
            case 1:
                DisplayCustomerMenu();
                scanf("%d", cMenuSelection);
                while (cMenuSelection < 0 || cMenuSelection > 3) //validation loop for customer menu select
                {
                    system("cls");
                    printf("Incorrect input!\n");
                    DisplayCustomerMenu;
                    scanf("%d", cMenuSelect);
                }//end while
                switch(cMenuSelection)
                {
                case 1:
                    AddCustomer(ptr_customer, totalCustomers);
                    totalCustomers++;
                    break;
                case 2:
                    SearchCustomer(ptr_customer, totalCustomers);
                    break;
                case 3:
                    printf("Returning to main menu...\n"); //figure out how to return to main menu
                    break;
                }//end switch on cMenuSelection
                break;
            case 2:
                DisplayToolMenu();
                scanf("%d", tMenuSelection);
                while (tMenuSelection < 1 || tMenuSelection > 3)
                {
                    printf("Invalid input!\n"
                           "Please enter a menu selection between 1 and 3: \n");
                    scanf("%d", tMenuSelection);
                }//end while
                switch(tMenuSelection)
                {
                case 1:
                    AddTool(ptr_tool, totalTools)
                    break;
                case 2:
                    break;
                case 3:
                    printf("Returning to main menu...\n"); //figure out how to return to main menu
                    break;
                }//end switch
                break;
            case 3:
                DisplayTransactionMenu();
                break;
            case 4:
                printf("Thank you for using ToolX. Goodbye! \n");
                break;
            }//end switch
        }//end else
    }//end do-while
    return 0;
}//end main

//================================================================================================================================================

void DisplayMainMenu()
{
    printf("==========MAIN MENU========== \n"
           "1- Customer Menu\n"
           "2- Tool Menu\n"
           "3- Transaction Menu\n"
           "4- Quit"
           "Enter your selection: \n");
}//end MainMenu
//================================================================================================================================================
void DisplayCustomerMenu()
{
    printf("==========CUSTOMER MENU========== \n"
           "1- Add a Customer\n"
           "2- Search for a Customer\n"
           "3- Go Back to Main Menu\n"
           "Enter your selection: \n");
}//end of DisplayCustomerMenu
//================================================================================================================================================
void DisplayToolMenu()
{
    printf("==========TOOL MENU========== \n"
           "1- Add a Tool\n"
           "2- Search for a Tool\n"
           "3- Go Back to Main Menu\n"
           "Enter your selection: \n");
}//end of DisplayToolMenu
//================================================================================================================================================
void DisplayTransactionMenu()
{
    printf("==========TRANSACTION MENU========== \n"
           "1- Start a Transaction\n"
           "2- Search for a Transaction\n"
           "3- Display all Transactions\n"
           "4- Go Back to Main Menu\n"
           "Enter your selection: \n");
}//end of DisplayTransactionMenu
//================================================================================================================================================
void AddCustomer(Customer* ptr_customer, int totalCustomers)
{
    //declarations:
        //input variables
    char input = {' '};
    char* ptr_input = &input;
        //validation variables
    bool validName = 1;
    bool validPhoneNum = 1;
    bool validEmail = 1;
        //rand range
    int randMax = 99999999999;
    int randMin = 10000000000;
    int randNum = 1;
    char idFirstLetter = *ptr_customer[0][0];

    fflush(stdin); //clearing buffer of any garbage
    //customer ID generated through rand num between randMax and randMin
    randNum = rand() %(randMax - randMin) + randMin;
    //convert randNum to string

    printf("Automated Customer ID: %d \n",
           (ptr_customer + totalCustomers)->customerID;

    //customer first name:
    printf("Enter the customer's first name: \n);e
    ptr_input = fgets(input, buffer, stdin); //retrieve string of input
    ptr_input = strtok(ptr_input, "\n")
    validName = CheckName(ptr_input);
    while (validName == 0)
    {
        printf("Invalid input!\n"
               "Enter the customer's first name without digits or spaces: \n");
        ptr_input = fgets(input, buffer, stdin); //retrieve string of input
        ptr_input = strtok(ptr_input, "\n")
        validName = CheckName(ptr_input);
    }//end while
    strcpy((ptr_customer + totalCustomers)->firstName, ptr_input);

    //customer last name:
    printf("Enter the customer's last name: \n);
    ptr_input = fgets(input, buffer, stdin); //retrieve string of input
    ptr_input = strtok(ptr_input, "\n")
    validName = CheckName(ptr_input);
    while (validName == 0)
    {
        printf("Invalid input!\n"
               "Enter the customer's last name without digits or spaces: \n");
        ptr_input = fgets(input, buffer, stdin); //retrieve string of input
        ptr_input = strtok(ptr_input, "\n")
        validName = CheckName(ptr_input);
    }//end while
    strcpy((ptr_customer + totalCustomers)->lastName, ptr_input);

    //customer phone number:
    printf("Enter the customer's phone number: \n");
    ptr_input = fgets(input, buffer, stdin);
    validPhoneNum = CheckPhoneNum(ptr_input);
    while (validPhoneNum == 0)
    {
        printf("Invalid input!\n"
               "Enter the customer's phone number without letters or spaces: \n");
        ptr_input = fgets(input, buffer, stdin); //retrieve string of input
        ptr_input = strtok(ptr_input, "\n")
        validPhoneNum = CheckPhoneNum(ptr_input);
    }//end while
    strcpy((ptr_customer + totalCustomers)->phoneNum, ptr_input);

    //customer email:
    printf("Enter the customer's email?\n");
    ptr_input = fgets(input, buffer, stdin);
    strtok(ptr_input, "\n");
    validEmail = CheckEmail(ptr_input);
    while (validEmail == 0)
    {
        printf("Invalid input!\n"
               "Please enter a valid email: \n");
        ptr_input = fgets(input, buffer, stdin);
        strtok(ptr_input, "\n");
        validEmail = CheckEmail(ptr_input);
    }//end while
    strcpy((ptr_customer + totalCustomers)->email, ptr_input);
}//end AddCustomer
//================================================================================================================================================
bool CheckName(char* ptr_input)
{
    //declarations:
    int invalidChar = 0;

    //loop to ensure characters are NOT digits/spaces
    for(int i = 0; i < strlen(ptr_input), i++)
    {
       if (isdigit(ptr_input + i) == 1 || isspace (ptr_input + i) == 1) //1 for TRUE and 0 for FALSE
       {
            invalidChar++;
       }//end if
    }//end for
    if (invalidChar == 0)
    {
        return 1;
    }//end if
    else
    {
        return 0;
    }//end else
}//end CheckName
//================================================================================================================================================
bool CheckPhoneNum(char* ptr_input)
{
    //declarations
    int invalidCount = 0;

    //loop to ensure no spaces/letters
    for(i = 0; i < strlen(ptr_input); i++;)
    {
        if(isspace(ptr_input + i) == 1 || isalpha(ptr_input + i) == 1)
        {
            invalidCount++;
        }//end if
    }//end for
    if (invalidCount == 0)
    {
        return 1;
    }//end if
    else
    {
        return 0;
    }//end else
}//end CheckPhoneNum
//================================================================================================================================================
bool CheckEmail(char* ptr_input)
{
    //what do I need to confirm a valid email?
    //I need to confirm: use of a @ character and ONLY one @ char
        //How?
        // if ... == @ foundAt = i
    //declarations
    int foundAt = -1;

    //loop to search for @
    for (int i = 0; i < strlen(ptr_input); i++)
    {
        if (*(ptr_input + i) == "@")
        {
            foundAt++;
        }//end if
    }//end for
    if(foundAt == 0 && foundAt !> 0)
    {
        return 1;
    }//end if
    else
    {
        return 0;
    }//end else
}//end CheckEmail
//================================================================================================================================================
bool CheckCustomerID(char* ptr_input) //check if id contains anything other than digits AND if ID is shorter/longer than 6 digits
{
    //declarations:
    int invalidCount = 0;

    //test if ID is > || < 6
    if(strlen(ptr_input) != 6)
    {
        invalidCount++;
    }//end if

    //loop to test for anything other than digit
    for(int i = 0; i < strlen(ptr_input); i++;)
    {
        if(!isdigit(ptr_input + i) == 1)
        {
            invalidCount++;
        }//end if
    }//end for
    if(invalidCount > 0)
    {
        return 0;
    }//end if
    else
    {
        return 1;
    }//end else
}//end CheckCustomerID
//================================================================================================================================================
void SearchCustomer(Customer* ptr_customer, int totalCustomers) //enter customer to be search for, search for customer, if not found ask if customer would like to be added or not
{
    //declarations:
        //input retrieval
    char input = {' '};
    char* ptr_input = NULL;
        //validation
    bool validID = 0;
        //matching
    int matchID = 0;
        //found OR not found at variable
    int customerFoundAt = 0;
    int notFoundSelection = 0;

    //retrieve customer id
    fflush(stdin);
    printf("Enter the customer you would like to search for: \n");
    ptr_input = fgets(input, buffer, stdin);
    validID = CheckCustomerID(ptr_input);

    //validation loop
    while(validID == 0)
    {
        printf("Invalid customer ID! \n"
               "Please enter a valid customer ID consisting of no more or less than 6 digits only: \n");
        ptr_input = fgets(input, buffer, stdin);
        validID = CheckCustomerID(ptr_input);
    }//end while

    //loop to search for matching customer ID
    for(int = 0; i < totalCustomers; i++;)
    {
        mactchID = strcmp(ptr_input, (ptr_customer + i)->customerID);
        if(matchID == 1)
        {
            customerFoundAt = i;
        }//end if
    }//end for
    if (matchID == 0)
    {
        printf("Customer not found!\n")
               /*"Would you like to register a new customer, search again, or return to main menu?\n"
               "1- Register a New Customer\n"
               "2- Search Again\n"
               "3- Return to Main Menu\n");
               scanf("%d", notFoundSelection);
               switch(notFoundSelection)
               {
               case 1:
                    AddCustomer();
                    break;
               }//end switch                ...coming soon*/
    }//end if
    else
    {
        DisplayCustomer(ptr_customer, customerFoundAt);
    }//end else
}//end SearchCustomer
//================================================================================================================================================
void DisplayCustomer(Customer* ptr_customer, int customerFoundAt)
{
    printf("Customer ID: %s \n"
           "First Name: %s \n"
           "Last Name: %s \n"
           "Phone Number: %s \n"
           "Email: %s \n",
           (ptr_customer + customerFoundAt)->customerID, (ptr_customer + customerFoundAt)-> firstName, (ptr_customer + customerFoundAt)-> lastName, (ptr_customer + customerFoundAt)-> phoneNum, (ptr_customer + customerFoundAt)-> email);
}//end DisplayCustomer
//================================================================================================================================================
void AddTool()
{
    //declarations:
        //input variables
    char input = {' '};
    char ptr_input = &input;
        //validation variables
    bool validToolType = 0;

    fflush(stdin);
    printf("Enter tool type: \n");
    ptr_input = fgets(input, buffer, stdin);
    validToolType = CheckToolType(ptr_input);
    while (validToolType != 1)
    {
        printf("Invalid input!\n"
               "Enter the tool type without the use of digits: \n");
        ptr_input = fgets(input, buffer, stdin);
        validToolType = CheckToolType(ptr_input);
    }//end while
    CheckToolID(ptr_input);
    strcpy((ptr_tool + totalTools)-> toolType, ptr_input);

}//end AddTool
//================================================================================================================================================

//================================================================================================================================================
bool CheckToolType(char* ptr_input)
{
    //declarations:
        //validation variables
    int invalidCount = 0;

    for(i = 0; i < strlen(ptr_input); i++)
    {
        if(isdigit(ptr_input + i) == 1)
        {
            invalidCount ++;
        }//end if
    }//end for

    if(invalidCount > 0)
    {
        return 0;
    }//end if
    else
    {
        return 1;
    }//end else
}//end CheckToolType
//================================================================================================================================================
void CheckToolID(char* ptr_input)
{
    //declarations:
        //find space
    int spaceFoundAt = 0;
        //store initial letters
    char firstLetter = {' '};
    char ptr_input = NULL;
    char secondLetter = {' '};
        //rand range
    int lower1 =


    for(int i = 0; i < strlen(ptr_input); i++;)
    {
        if (*(ptr_input + i) == {' '})
            {
                spaceFoundAt = i;
            }//end if
    }//end for
    if(spaceFoundAt > 0)
    {
        firstLetter = *(ptr_input + 0);
        secondLetter = *(ptr_input + spaceFoundAt + 1);

    }//end if
}//end CheckToolID
//================================================================================================================================================

//================================================================================================================================================

//================================================================================================================================================

//================================================================================================================================================

//================================================================================================================================================

//================================================================================================================================================

//================================================================================================================================================

//================================================================================================================================================

//================================================================================================================================================
