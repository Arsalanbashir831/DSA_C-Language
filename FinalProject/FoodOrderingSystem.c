#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
/*
Team Members :
1- Arsalan Bashir (FA20-BSE-013)
2- Hamza Shahid (FA20-BSE-048)
*/
// The project is about the resturant who wants to manage the ordering system of his/her resturant
/*
It uses the same concept of our university cafe order system or normal resturant system
*/
// this whole project is done by single link list , multidimentional single linklist, arrays and graph 
// creating  the Node of food for creating the list of foods
struct food
{
    int id;
    float price;
    char name[100];
    char status[100]; // | id | price | name | status | quantity | total | next | -> NULL
    int quantity;
    int total;
    struct food *next;
};

// add new food in our menu
// it uses the same concept of inserting the new data in the linklist
struct food *add_newFood(struct food *food, int id, float price, char name[], char status[])
{
    struct food *food_ptr;
    struct food *newFood = (struct food *)malloc(sizeof(struct food)); // creating memory space
    newFood->id = id;
    newFood->price = price;
    strcpy(newFood->name, name);
    strcpy(newFood->status, status);

    if (food == NULL)
    {
        newFood->next = food;
        food = newFood;
        return food;
    }
    else
    {
        food_ptr = food;
        while (food_ptr->next != NULL)
        {
            food_ptr = food_ptr->next;
        }
        food_ptr->next = newFood;
        newFood->next = NULL;
        return food;
    }
    return food;
}
// add food at the customer invoice
// it uses the same concept of inserting the new data in the linklist
struct food *add_newFoodItem(struct food *food, int id, float price, char name[], int quantity)
{
    struct food *food_ptr;
    struct food *newFood = (struct food *)malloc(sizeof(struct food));
    newFood->id = id;
    newFood->price = price;
    strcpy(newFood->name, name);
    newFood->quantity = quantity;
    newFood->total = newFood->quantity * newFood->price;

    if (food == NULL)
    {
        newFood->next = food;
        food = newFood;
        return food;
    }
    else
    {
        food_ptr = food;
        while (food_ptr->next != NULL)
        {
            food_ptr = food_ptr->next;
        }
        food_ptr->next = newFood;
        newFood->next = NULL;
        return food;
    }
    return food;
}
// display the food list
// it uses the same concept of traversing the linklist
void display_Food(struct food *food)
{
    struct food *food_ptr = food;
    printf("\n");
    printf("\t\t-----------------------------------------------------------------\n");
    printf("\t\tID\tPrice\t\tName\t\tStatus\t\t\n");
    printf("\t\t-----------------------------------------------------------------\n");
    printf("\n");

    while (food_ptr != NULL)
    {
        printf("\t\t%d\t%.2f\t\t%s\t\t%s\t\n", food_ptr->id, food_ptr->price, food_ptr->name, food_ptr->status);
        food_ptr = food_ptr->next;
    }
    printf("\t\t-----------------------------------------------------------------\n");
}
// deleting the food by selecting the food id
struct food *delete_Food_byID(struct food *food, int id)
{
    struct food *food_ptr = food;
    struct food *food_nptr = food->next;
    if (food->id == id)
    {
        food = food->next;
        return food;
    }
    else
    {
        while (food_nptr->id != id && food_nptr->next != NULL)
        {
            food_nptr = food_nptr->next;
            food_ptr = food_ptr->next;
        }
        if (food_nptr->id == id)
        {
            food_ptr->next = food_nptr->next;
            free(food_nptr);
        }
        else
        {
            printf("\n======  NO FOOD FOUND  =======\n");
        }
    }
    return food;
}
// deleting food by name
struct food *delete_Food_byName(struct food *food, char name[])
{
    struct food *food_ptr = food;
    struct food *food_nptr = food->next;
    if (strcmp(food->name, name) == 0)
    {
        food = food->next;
        return food;
    }
    else
    {
        while (strcmp(food_nptr->name, name) != 0 && food_nptr->next != NULL)
        {
            food_nptr = food_nptr->next;
            food_ptr = food_ptr->next;
        }
        if (strcmp(food_nptr->name, name) == 0)
        {
            food_ptr->next = food_nptr->next;
            free(food_nptr);
        }
        else
        {
            printf("\n======  NO FOOD FOUND  =======\n");
        }
    }
    return food;
}
// Edit the food price
struct food *Edit_FoodPrice(struct food *food, float price, int id)
{
    struct food *food_ptr = food;
    while (food_ptr != NULL)
    {
        if (food_ptr->id == id)
        {
            food_ptr->price = price;
        }
        food_ptr = food_ptr->next;
    }
    return food;
}
// Edit the food status
struct food *Edit_FoodStatus(struct food *food, char status[], int id)
{
    struct food *food_ptr = food;
    while (food_ptr != NULL)
    {
        if (food_ptr->id == id)
        {
            strcpy(food_ptr->status, status);
        }
        food_ptr = food_ptr->next;
    }
    return food;
}
// Count the number of food
int foodCounter(struct food *food)
{
    struct food *food_ptr = food;
    int counter = 0;
    while (food_ptr != NULL)
    {
        food_ptr = food_ptr->next;
        counter++;
    }
    return counter;
}
// generating the invoice
void display_Customer_Invoice(struct food *food)
{
    struct food *food_ptr = food;

    printf("  -----------------------------------------------------------------------------\n");
    printf(" || Food ID ||  Food Price ||       Food Name     || Quantity || Total ||   \n");
    printf("  -----------------------------------------------------------------------------\n");
    while (food_ptr != NULL)
    {
        printf("     %d            %.2f          \t%s    \t%d        %d \n", food_ptr->id, food_ptr->price, food_ptr->name, food_ptr->quantity, food_ptr->total);
        food_ptr = food_ptr->next;
    }
    printf("  -------------------------------------------------------------------------------\n");
}
struct Customer
{
    char name[100];
    int id;
    char status[100];
    int totalBill;
    char address[100];
    struct food *foodItems;
    struct Customer *next;
};

// add the customer
struct Customer *addCustomer(struct Customer *customer, char name[], char status[], int id)
{
    struct Customer *newCustomer = (struct Customer *)malloc(sizeof(struct Customer));
    newCustomer->id = id;
    strcpy(newCustomer->name, name);
    strcpy(newCustomer->status, status);

    if (customer == NULL)
    {
        newCustomer->next = customer;
        customer = newCustomer;
        return customer;
    }
    else
    {
        struct Customer *customer_ptr = customer;
        while (customer_ptr->next != NULL)
        {
            customer_ptr = customer_ptr->next;
        }
        customer_ptr->next = newCustomer;
        newCustomer->next = NULL;
        return customer;
    }
    return customer;
}

struct Customer *addDeliveryCustomer(struct Customer *customer, char name[], char status[], int id, char address[])
{
    struct Customer *newCustomer = (struct Customer *)malloc(sizeof(struct Customer));
    newCustomer->id = id;
    strcpy(newCustomer->name, name);
    strcpy(newCustomer->status, status);
    strcpy(newCustomer->address, address);

    if (customer == NULL)
    {
        newCustomer->next = customer;
        customer = newCustomer;
        return customer;
    }
    else
    {
        struct Customer *customer_ptr = customer;
        while (customer_ptr->next != NULL)
        {
            customer_ptr = customer_ptr->next;
        }
        customer_ptr->next = newCustomer;
        newCustomer->next = NULL;
        return customer;
    }
    return customer;
}

// display the list of the customer
void display_Customer(struct Customer *customer)
{
    struct Customer *customer_ptr = customer;
    int i = 1;
    printf("SR.no\t\tCustomer ID\t\tCustomer Name\t\tOrder Status\n");
    while (customer_ptr != NULL)
    {
        printf("%d\t\t   %d \t\t\t%s    \t\t%s \n", i, customer_ptr->id, customer_ptr->name, customer_ptr->status);
        customer_ptr = customer_ptr->next;
        i++;
    }
}
// display the those customers whose orders are to be delivered
void displayDeliveryCustomer(struct Customer *customer)
{
    struct Customer *customer_ptr = customer;
    int i = 1;
    printf("SR.no\t\tCustomer ID\t\tCustomer Name\t\tDestination\t\tOrder Status\n");
    while (customer_ptr != NULL)
    {
        printf("%d\t\t   %d \t\t\t%s    \t\t%s  \t\t%s \n", i, customer_ptr->id, customer_ptr->name, customer_ptr->address, customer_ptr->status);
        customer_ptr = customer_ptr->next;
        i++;
    }
}
// edit the order status of the customer
struct Customer *edit_OrderStatus(struct Customer *customer, char status[], int id)
{
    struct Customer *customer_ptr = customer;
    while (customer_ptr != NULL)
    {
        if (customer_ptr->id == id)
        {
            strcpy(customer_ptr->status, status);
        }
        customer_ptr = customer_ptr->next;
    }
    return customer;
}

void CalculateTotalBIll(struct food *food, struct Customer *customer)
{
    struct food *food_ptr;
    int temp = 0;
    while (food != NULL)
    {
        temp = temp + food->total;
        food = food->next;
    }
    customer->totalBill = temp;
    printf("\t\tTOTAL BILL : %d ", temp);
    temp = 0;
}

// display customer detail with invoice details
void displayCustomerDetails(struct Customer *customer, int id)
{
    struct Customer *customer_ptr = customer;
    while (customer_ptr != NULL)
    {
        if (id == customer_ptr->id)
        {
            printf("\n **********************Customer Details*************************\n");
            printf("\t\tCustomer Name  \tCustomer ID\n");
            printf("\t\t%s    \t\t%d ", customer_ptr->name, customer_ptr->id);
            printf("\n ***************************Orders********************************\n");
            display_Customer_Invoice(customer_ptr->foodItems);
            CalculateTotalBIll(customer_ptr->foodItems, customer_ptr);
            printf("\n  *****************************************************************\n");
        }
        customer_ptr = customer_ptr->next;
    }
}
// purchase the order by the customer from the given list
void Purchase(struct Customer *customer, struct food *food)
{
    struct food *food_ptr = food;
    struct Customer *customer_ptr = customer;
    int id, quantity, flag = 0;

    printf("Enter the id of food you want to purchase : ");
    scanf("%d", &id);

    while (food_ptr != NULL)
    {
        if (food_ptr->id == id && strcmp(food_ptr->status, "Not Availible") != 0)
        {
            flag = 1;
            printf("Enter the quantity : ");
            scanf("%d", &quantity);
            while (customer_ptr != NULL)
            {
                customer_ptr->foodItems = add_newFoodItem(customer_ptr->foodItems, food_ptr->id, food_ptr->price, food_ptr->name, quantity);
                customer_ptr = customer_ptr->next;
            }
            break;
        }
        food_ptr = food_ptr->next;
    }
    if (flag == 0)
    {
        printf("\nSorry you cant purchase this food\n");
        printf("\n maybe you enter the wrong id of the food or select not avalible food \n ");
    }
}
// completion order list of the customer
void CompleteTheOrder(struct Customer *customer, int id)
{
    struct Customer *customer_ptr = customer;
    int flag = 0;
    while (customer_ptr != NULL)
    {
        if (id == customer_ptr->id)
        {
            flag = 1;
            customer_ptr = edit_OrderStatus(customer_ptr, "Completed", id);
        }
        customer_ptr = customer_ptr->next;
    }
    if (flag == 0)
    {
        printf("\nNo ID found \n");
    }
}
// display the sales report to the admin
void displaySalesReport(struct Customer *customer)
{
    struct Customer *customer_ptr = customer;
    int totalSales = 0;
    printf("\n----------------------------------------------------------\n");
    printf("\t|| Customer Name || || Customer ID || || Total ||\n");
    while (customer_ptr != NULL)
    {
        printf("\t%s          \t%d       \t%d\n", customer_ptr->name, customer_ptr->id, customer_ptr->totalBill);
        totalSales = totalSales + customer_ptr->totalBill;
        customer_ptr = customer_ptr->next;
    }
    printf("\n----------------------------------------------------------\n");
    printf("Total Sales : %d", totalSales);
    printf("\n----------------------------------------------------------\n");
}
// payment of the foood by the customer
void Payment_Method(struct Customer *customer, int id)
{
    printf("\n Choose the Payment Method :  ");
    int payOpt;
    printf("1-Cash \t 2-Card ");
    scanf("%d", &payOpt);
    if (payOpt == 2)
    {
        printf("Enter your Card Number : ");
        int cardNum;
        scanf("%d", &cardNum);
        printf("Payment Successfull");
        CompleteTheOrder(customer, id);
    }
    int cash;
    if (payOpt == 1)
    {
    enterAmountAgain:

        printf("Enter the amount : ");
        scanf("%d", &cash);
        if (cash < customer->totalBill)
        {
            printf("\nnot enough amount \n");
            printf("\nEnter again \n");
            goto enterAmountAgain;
        }
        if (cash > customer->totalBill)
        {
            int returnAmount;
            returnAmount = cash - customer->totalBill;
            printf("\n You recieve %d amount in return ", returnAmount);
            printf("\nPayment Successfull");
            CompleteTheOrder(customer, id);
        }
        if (cash == customer->totalBill)
        {
            printf("Payment Successfull");
            CompleteTheOrder(customer, id);
        }
    }
}
void cancelOrder(struct food *food, struct Customer *customer, int id)
{
    struct food *food_ptr=food;
    while (customer != NULL)
    {
        if (customer->id == id)
        {
            while (food_ptr->next!=NULL)
            {
                food_ptr=food_ptr->next;
            }
            food->next = food_ptr->next;
        }
        customer = customer->next;
    }
}
int randomGeneration(int lower, int higher)
{

    int num = (rand() %
               (higher - lower + 1)) +
              lower;
    return num;
}

int generateUserId(struct Customer *customer, char name[])
{
    int num = randomGeneration(randomGeneration(1, 9), randomGeneration(100, 500));
    struct Customer *customer_ptr = customer;
    while (customer_ptr != NULL)
    {
        if (strcmp(customer->name, name) == 0)
        {
            return num;
        }
        customer_ptr = customer_ptr->next;
    }

    return num;
}
// implementation of graph data structure
struct Node
{
    int data;
    char string[20];
    struct Node *next;  // | data | location | next ->|
};
struct AdjList
{
    struct Node *head;
};
struct AdjList *arrAdjList[7] = {0};
void addNode(int source, char string1[], int destination, char string2[])
{
    struct Node *dest, *temp, *src;
    if (arrAdjList[source]->head == NULL)
    {
        src = (struct Node *)malloc(sizeof(struct Node));
        src->data = source;
        strcpy(src->string, string1);
        src->next = NULL;
        arrAdjList[source]->head = src;
    }

    dest = (struct Node *)malloc(sizeof(struct Node));
    dest->data = destination;
    strcpy(dest->string, string2);
    dest->next = NULL;
    temp = arrAdjList[source]->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = dest;
}
// printing the route from source to destination
void PrintList(char destination[])
{
    int i = 0;
    struct Node *p = arrAdjList[i]->head;
    while (p)
    {
        if (strcmp(p->string, destination) == 0)
        {
            printf("  [%d](KM)  %s  |->|\t", p->data, p->string);
            break;
        }
        printf(" [%d](KM)  %s  |->|\t", p->data, p->string);
        p = p->next;
    }
    printf("Customer Destinition");
}
//creation of nodes in graph
void CreateNode(int size)
{
    for (int i = 0; i < size; i++)
    {
        arrAdjList[i] = (struct AdjList *)malloc(sizeof(struct AdjList));
        arrAdjList[i]->head = NULL;
    }
}
// this function enable us to view the route of customer destination
void viewCustomerDest(struct Customer *customer)
{
    struct Customer *customer_ptr = customer;
    int id;
    printf("Enter the Customer Id for delivery of order : ");
    scanf("%d", &id);
    // int flag = 0;
    while (customer_ptr != NULL)
    {
        if (id == customer_ptr->id)
        {
            // flag == 1;
            break;
        }
        customer_ptr = customer_ptr->next;
    }

    printf("\n Do you want to view the map for customer destination : (1-Yes || 2-No)");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        PrintList(customer_ptr->address);
    }
    else
    {
        printf("\nReady for Delivery\n");
    }
}
int main(int argc, char const *argv[])
{
    /*
        list of thr fast fast food ,desi and special discount list of food
    */
    struct food *fastFood = NULL;
    struct food *desi = NULL;
    struct food *special_discount = NULL;
    // create the list of the customer
    struct Customer *customer = NULL;
    struct Customer *deliveryCustomer = NULL;
    // by default list of the food or we also call this menu
    fastFood = add_newFood(fastFood, 89, 234, "Pasta", "Availible");
    fastFood = add_newFood(fastFood, 67, 30, "Roll", "Availible");
    fastFood = add_newFood(fastFood, 19, 934, "Pizza(M)", "Availible");
    fastFood = add_newFood(fastFood, 59, 1234, "Pizza(L)", "Not Availible");

    desi = add_newFood(desi, 9, 2000, "Chicken Karahi", "Availible");
    desi = add_newFood(desi, 67, 300, "Chicken Biryani", "Availible");
    desi = add_newFood(desi, 19, 934, "Chicken Quorma", "Not Availible");

    special_discount = add_newFood(special_discount, 29, 423, "Pizza(M)", "Availible");
    special_discount = add_newFood(special_discount, 267, 150, "Chicken Biryani", "Availible");

    char location[7][100] = {"Model Town", "Iqbal Town", "Canal Road", "Bahria Town", "Sabzazar", "Ali Town", "EME"};
    CreateNode(7);
    for (int i = 0; i < 7; i++)
    {
        addNode(0, "SHOP", i + 1, location[i]);
    }

    while (1)
    {
        printf("\n==========================WELCOME TO FOOD ORDERING SYSTEM========================\n");
        printf(" \n\t1 - Admin \n\t2 - Customer \n\t3-Delivery Boy\n\tEnter -1 to exit ");
        int opt;
        printf("\n\tEnter : ");
        scanf("%d", &opt);
        if (opt == -1)
        {
            break;
        }
        // For customer
        if (opt == 2)
        {
            char name[100];
            printf("Enter your name : ");
            fflush(stdin);
            gets(name);
            srand(time(0));
            int id = generateUserId(customer, name);
            // when user  Enters to the system this will store the data of the customer in the list
            customer = addCustomer(customer, name, "Pending", id);
            printf("\nyour ID is : %d\n", id);
            printf("\n\t  *****Welcome %s to Food Ordering System****\n", name);
            while (1)
            {
            customerMenu:
                printf("\t\n1-Desi Food \n2-Fast Food \n3-Special Discount Offers \n4- Display Invoice \n5-Payment\n6-Delivery \n-1 to exit\n");
                int foodOpt;
                printf("\n Enter the Option :  ");
                scanf("%d", &foodOpt);
                if (foodOpt == -1)
                {
                    break;
                }
                if (foodOpt == 6)
                {
                askAddress:
                    printf("Enter your address : ");
                    fflush(stdin);
                    char address[100];
                    fflush(stdin);
                    gets(address);
                    int time = 20;
                    int flag = 0;
                    for (int i = 0; i < 7; i++)
                    {
                        if (strcmp(address, location[i]) == 0)
                        {
                            flag = 1;
                            deliveryCustomer = addDeliveryCustomer(deliveryCustomer, name, "Pending", id, address);
                            printf("\n----Your order will recieve in %d minutes----", time);
                        }
                        time += 20;
                    }
                    if (flag == 0)
                    {
                        printf("\n--Sorry!--\n---Location out of reach---\n");
                        printf("\nWe deliver the food at the location \n");
                        for (int i = 0; i < 7; i++)
                        {
                            printf(" %s  \n", location[i]);
                        }

                        printf("\nWant to go back to menu : (1-Yes || 2- No)\n");
                        int choice;
                        scanf("%d", &choice);
                        if (choice == 2)
                        {
                            goto askAddress;
                        }
                        if (choice == 1)
                        {
                            goto customerMenu;
                        }
                    }
                }
                if (foodOpt == 4)
                {
                    displayCustomerDetails(customer, id);
                }
                if (foodOpt == 5)
                {
                    Payment_Method(customer, id);
                }

               
                if (foodOpt == 1)
                {
                    display_Food(desi);
                    while (1)
                    {
                        Purchase(customer, desi);
                        printf("Do you want to Add more ?");
                        printf("\n1-Yes\n2-No");
                        printf("\n Enter the Option :  ");
                        int buy;
                        scanf("%d", &buy);
                        if (buy == 1)
                        {
                            continue;
                        }
                        if (buy == 2)
                        {
                            break;
                        }
                    }
                }
                if (foodOpt == 2)
                {
                    display_Food(fastFood);
                    while (1)
                    {
                        Purchase(customer, fastFood);
                        printf("Do you want to Add more ?");
                        printf("\n1-Yes\n2-No");
                        int buy;
                        printf("\n Enter the Option :  ");
                        scanf("%d", &buy);
                        if (buy == 1)
                        {
                            continue;
                        }
                        if (buy == 2)
                        {
                            break;
                        }
                    }
                }
                if (foodOpt == 3)
                {
                    while (1)
                    {
                        printf("Enter the discount code : ");
                        int code;
                        scanf("%d", &code);

                        if (code == 1234)
                        {
                            display_Food(special_discount);
                            while (1)
                            {
                                Purchase(customer, special_discount);
                                printf("Do you want to Add more ?");
                                printf("\n1-Yes\n2-No");
                                int buy;
                                printf("\n Enter the Option :  ");
                                scanf("%d", &buy);
                                if (buy == 1)
                                {
                                    continue;
                                }
                                if (buy == 2)
                                {
                                    break;
                                }
                            }
                            break;
                        }
                        else
                        {
                            printf("\nWrong code\n");
                            continue;
                        }
                    }
                }
            }
        }
        // <<<Admin Module>>>
        if (opt == 1)
        {
            while (1)
            {

                char pass[100];
                gets(pass);
                printf("\n\tEnter the password for admin module : ");
                gets(pass);

                if (strcmp(pass, "12345") == 0)
                {
                    break;
                }
                else
                {
                    printf("\n\n\t'**Wrong password ....... Enter your password again**'\n");
                    printf("\n\t'**Press Enter to continue**'\n");
                }
            }
            printf("\n========================= WELCOME TO ADMIN PANEL ============================\n");
            while (1)
            {
                printf(" \n\t1- Add the food \n\t2- Remove the food \n\t3- Edit the food \n\t4- View the Customer Order Status \n\t5- Complete the Order\n\t6- View Sales Report\n\tEnter -1 to Exit ");
                int adminOpt;
                printf("\n\tEnter the Option :  ");
                scanf("%d", &adminOpt);
                if (adminOpt == -1)
                {
                    break;
                }

                if (adminOpt == 1)
                {
                    while (1)
                    {
                        printf(" \n\tSelect the category where you wanna add the food \n");
                        printf(" \n\t1- Fast food \n\t2- Desi food \n\t3- Special Offer food \n\tEnter -1 to go back ");
                        int category_opt;
                        printf("\n\tEnter the Option :  ");
                        scanf("%d", &category_opt);
                        // FAST FOOD
                        if (category_opt == -1)
                        {
                            break;
                        }

                        if (category_opt == 1)
                        {
                            display_Food(fastFood);
                            printf("\n\t---------------------- ADD FAST FOOD ------------------\n");
                            char name[100], status[100];
                            int id;
                            float price;
                            printf("\n\tEnter the name of fast food : ");
                            fflush(stdin);
                            gets(name);
                            printf("\n");
                            printf("\tEnter the id of the %s : ", name);
                            scanf("%d", &id);
                            printf("\n");
                            printf("\tEnter the price of %s : ", name);
                            scanf("%f", &price);
                            printf("\n");
                            printf("\tSelect the status\n");
                            printf("\n-----------------1-Availible\n-----------------2-Not Availible\n");
                            printf("\n");
                            printf("\n\tEnter the Option : ");
                            int statusOpt;
                            scanf("%d", &statusOpt);
                            if (statusOpt == 1)
                            {
                                strcpy(status, "Availible");
                            }
                            else
                            {
                                strcpy(status, "Not Availible");
                            }
                            fastFood = add_newFood(fastFood, id, price, name, status);
                            display_Food(fastFood);
                        }
                        // DESI FOOD

                        if (category_opt == 2)
                        {
                            display_Food(desi);
                            printf("\n---------------------- ADD DESI FOOD ------------------\n");
                            char name[100], status[100];
                            int id;
                            float price;
                            printf("\n");
                            printf("\tEnter the name of Desi food : ");
                            fflush(stdin);
                            gets(name);
                            printf("\n");
                            printf("\tEnter the id of the %s : ", name);
                            scanf("%d", &id);
                            printf("\n");
                            printf("\tEnter the price of %s : ", name);
                            scanf("%f", &price);
                            printf("\n");
                            printf("\tSelect the status\n");
                            printf("\n-----------------1-Availible\n-----------------2-Not Availible\n");
                            printf("\t\nEnter the Option :  ");
                            int statusOpt;
                            scanf("%d", &statusOpt);
                            if (statusOpt == 1)
                            {
                                strcpy(status, "Availible");
                            }
                            else
                            {
                                strcpy(status, "Not Availible");
                            }
                            desi = add_newFood(desi, id, price, name, status);
                            display_Food(desi);
                        }

                        // Special offer Food
                        if (category_opt == 3)
                        {
                            display_Food(special_discount);
                            printf("\n---------------------- ADD SPECIAL DISCOUNT FOOD ------------------\n");
                            char name[100], status[100];
                            int id;
                            float price;
                            printf("\n");
                            printf("\tEnter the name of food : ");
                            gets(name);
                            gets(name);
                            printf("\n");
                            printf("\tEnter the id of the %s : ", name);
                            scanf("%d", &id);
                            printf("\n");
                            printf("\tEnter the price of %s : ", name);
                            scanf("%f", &price);
                            printf("\n");
                            printf("\tSelect the status\n");
                            printf("\n-----------------1-Availible\n-----------------2-Not Availible\n");
                            int statusOpt;
                            printf("\n\tEnter the Option :  ");
                            scanf("%d", &statusOpt);
                            if (statusOpt == 1)
                            {
                                strcpy(status, "Availible");
                            }
                            else
                            {
                                strcpy(status, "Not Availible");
                            }
                            special_discount = add_newFood(special_discount, id, price, name, status);
                            display_Food(special_discount);
                        }
                    }
                }
                // Remove the food
                if (adminOpt == 2)
                {
                    while (1)
                    {
                        printf("\n\tDeletion category \n");
                        printf(" \n\t1 - Fast food \n\t2 - Desi food \n\t3 - Special Offer food \n\tEnter -1 to go back ");
                        int category_opt;
                        printf("\n\tEnter the Option :  ");
                        scanf("%d", &category_opt);
                        if (category_opt == -1)
                        {
                            break;
                        }
                        if (category_opt == 1)
                        {
                            display_Food(fastFood);
                            printf("\n\t1 - Delete the food by name \n\t2 - Delete the food by id ");
                            int opt;
                            char name[100];
                            int id;
                            printf("\n\tEnter the Option : ");
                            scanf("%d", &opt);
                            if (opt == 1)
                            {
                                printf("\t\nEnter the name of food : ");
                                gets(name);
                                gets(name);
                                fastFood = delete_Food_byName(fastFood, name);
                                printf("\t\t------------Food Item deleted from list successfully------------");
                                display_Food(fastFood);
                            }
                            if (opt == 2)
                            {
                                printf("\n");
                                printf("\tEnter the ID of food : ");
                                scanf("%d", &id);
                                fastFood = delete_Food_byID(fastFood, id);
                                printf("\t\t-----------Food Item deleted from list successfully------------");
                                display_Food(fastFood);
                            }
                        }

                        if (category_opt == 2)
                        {
                            display_Food(desi);
                            printf("\n\t1 - Delete the food by name \n\t2 - Delete the food by id ");
                            int opt;
                            char name[100];
                            printf("\n\tEnter the Option : ");
                            scanf("%d", &opt);
                            int id;
                            if (opt == 1)
                            {
                                printf("\t\nEnter the name of food : ");
                                gets(name);
                                gets(name);
                                desi = delete_Food_byName(desi, name);
                                display_Food(desi);
                            }
                            if (opt == 2)
                            {
                                printf("\n");
                                printf("\tEnter the ID of food :  ");
                                scanf("%d", &id);
                                desi = delete_Food_byID(desi, id);
                                display_Food(desi);
                            }
                        }
                        if (category_opt == 3)
                        {
                            display_Food(special_discount);
                            printf("\n\t1 - Delete the food by name \n\t2 - Delete the food by id ");
                            int opt;
                            char name[100];
                            int id;
                            printf("\n\tEnter the Option : ");
                            scanf("%d", &opt);
                            if (opt == 1)
                            {
                                printf("\n\tEnter the name of food : ");
                                gets(name);
                                gets(name);
                                special_discount = delete_Food_byName(special_discount, name);
                                printf("\t\t-------------Food Item deleted from list successfully------------");
                                display_Food(special_discount);
                            }
                            if (opt == 2)
                            {
                                printf("\n");
                                printf("\tEnter the ID of food : ");
                                scanf("%d", &id);
                                special_discount = delete_Food_byID(special_discount, id);
                                printf("\t\t--------Food Item deleted from list successfully------------");
                                display_Food(special_discount);
                            }
                        }
                    }
                }
                if (adminOpt == 3)
                {
                    printf("\n===========Edit the Food===========\n");
                    while (1)
                    {
                        printf("\t\nEnter the Food Category\n");
                        printf(" \n\t1- Fast food \n\t2- Desi food \n\t3- Special Offer food \n\tEnter -1 to go back ");
                        int category_opt;
                        printf("\n\tEnter the Option :  ");
                        scanf("%d", &category_opt);
                        if (category_opt == -1)
                        {
                            break;
                        }
                        if (category_opt == 1)
                        {
                            display_Food(fastFood);
                            printf("\t\nWhat do you want to edit ?");
                            printf("\n\t1 - Price \n\t2 - Status");
                            printf("\n");
                            int editOpt;
                            printf("\n\tEnter the Option : ");
                            scanf("%d", &editOpt);
                            printf("\n");
                            if (editOpt == 1)
                            {
                                float price;
                                int id;
                                printf("\t\nEnter the id of the food : ");
                                scanf("%d", &id);
                                printf("\n");
                                printf("Enter the edited price of food : ");
                                scanf("%f", &price);
                                printf("\n");
                                fastFood = Edit_FoodPrice(fastFood, price, id);
                                display_Food(fastFood);
                            }
                            if (editOpt == 2)
                            {
                                char status[100];
                                int id, choice;
                                printf("\t\nEnter the id of the food : ");
                                scanf("%d", &id);
                                printf("\n");
                                printf("Select the Status of food");
                                printf("\n\t1-Availible\n\t2-Not Availible\n");
                                scanf("%d", &choice);
                                printf("\n");
                                if (choice == 1)
                                {
                                    strcpy(status, "Availible");
                                }
                                else
                                {
                                    strcpy(status, "Not Availible");
                                }
                                fastFood = Edit_FoodStatus(fastFood, status, id);
                                display_Food(fastFood);
                            }
                        }
                        if (category_opt == 2)
                        {
                            display_Food(desi);
                            printf("\n\tWhat do you want to edit ?");
                            printf("\n\t1 - Price \n\t2 - Status");
                            printf("\n");
                            int editOpt;
                            printf("\n Enter the Option :  ");
                            scanf("%d", &editOpt);
                            printf("\n");
                            if (editOpt == 1)
                            {
                                float price;
                                int id;
                                printf("\tEnter the id of the food : ");
                                scanf("%d", &id);
                                printf("\n");
                                printf("\tEnter the edited price of food : ");
                                scanf("%f", &price);
                                desi = Edit_FoodPrice(desi, price, id);
                                display_Food(desi);
                            }
                            if (editOpt == 2)
                            {
                                char status[100];
                                int id, choice;
                                printf("Enter the id of the food : ");
                                scanf("%d", &id);
                                printf("Select the Status of food");
                                printf("\n-----------------1-Availible\n-----------------2-Not Availible\n");
                                scanf("%d", &choice);
                                if (choice == 1)
                                {
                                    strcpy(status, "Availible");
                                }
                                else
                                {
                                    strcpy(status, "Not Availible");
                                }
                                desi = Edit_FoodStatus(desi, status, id);
                                display_Food(desi);
                            }
                        }
                        if (category_opt == 3)
                        {
                            display_Food(special_discount);
                            printf("What do you want to edit ?");
                            printf("\n1-Price \n 2-Status");
                            int editOpt;
                            printf("\n Enter the Option :  ");
                            scanf("%d", &editOpt);
                            if (editOpt == 1)
                            {
                                float price;
                                int id;
                                printf("Enter the id of the food : ");
                                scanf("%d", &id);
                                printf("Enter the edited price of food");
                                scanf("%f", &price);
                                special_discount = Edit_FoodPrice(special_discount, price, id);
                                display_Food(special_discount);
                            }
                            if (editOpt == 2)
                            {
                                char status[100];
                                int id, choice;
                                printf("Enter the id of the food : ");
                                scanf("%d", &id);
                                printf("Select the Status of food");
                                printf("\n-----------------1-Availible\n-----------------2-Not Availible\n");
                                scanf("%d", &choice);
                                if (choice == 1)
                                {
                                    strcpy(status, "Availible");
                                }
                                else
                                {
                                    strcpy(status, "Not Availible");
                                }
                                special_discount = Edit_FoodStatus(special_discount, status, id);
                                display_Food(special_discount);
                            }
                        }
                    }
                }

                if (adminOpt == 4)
                {
                    printf("\n***** Customer Order Status *****\n");
                    display_Customer(customer);
                }
                if (adminOpt == 5)
                {
                    printf("\n***** Customer Order Status *****\n");
                    display_Customer(customer);
                    printf("Enter the id of the customer who completed the order : ");
                    int id;
                    scanf("%d", &id);
                    CompleteTheOrder(customer, id);
                    display_Customer(customer);
                }
                if (adminOpt == 6)
                {
                    displaySalesReport(customer);
                }
            }
        }
        if (opt == 3)
        {
            printf("\n========================= WELCOME TO DELIVERY PANEL ============================\n");
        deliveryBoyMenu:
            printf(" \n 1-Select the customer for delivery \n 2- Update the Order Status \n -1 to Exit\n Enter :  ");
            int choice;
            scanf("%d", &choice);
            if (choice == -1)
            {
            }
            if (choice == 1)
            {
                displayDeliveryCustomer(deliveryCustomer);
                viewCustomerDest(deliveryCustomer);
                goto deliveryBoyMenu;
            }
            if (choice == 2)
            {

                displayDeliveryCustomer(deliveryCustomer);
                printf("Enter the id of the customer : ");
                int id;
                scanf("%d", &id);
                deliveryCustomer = edit_OrderStatus(deliveryCustomer, "Completed", id);
                 displayDeliveryCustomer(deliveryCustomer);
                goto deliveryBoyMenu;
            }
        }
    }
    return 0;
}
