#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
// The project is about the resturant who wants to manage the ordering system of his/her resturant
/*
It uses the same concept of our university cafe order system 
*/
// this whole project is done by single link list and multidimentional single linklist


//creating  the Node of food for creating the list of foods 
struct food
{
    int id;
    float price;
    char name[100];
    char status[100];
    int quantity;
    int total;
    struct food *next;
};
//add new food in our menu
//it uses the same concept of inserting the new data in the linklist 
struct food *add_newFood(struct food *food, int id, float price, char name[], char status[])
{
    struct food *newFood = (struct food *)malloc(sizeof(struct food));
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
        struct food *food_ptr = food;
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
//it uses the same concept of inserting the new data in the linklist 
struct food *add_newFoodItem(struct food *food, int id, float price, char name[], int quantity)
{
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
        struct food *food_ptr = food;
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
    printf("\t\t---------------------------------------------------\n");
    printf("\t\tID\tPrice\t\tName\t\tStatus\t\t\n");
    printf("\t\t---------------------------------------------------\n");
    while (food_ptr != NULL)
    {
        printf("\t\t%d\t%.2f\t\t%s\t\t%s\t\n", food_ptr->id, food_ptr->price, food_ptr->name, food_ptr->status);
        food_ptr = food_ptr->next;
    }
    printf("\t\t---------------------------------------------------\n");
}
//deleting the food by selecting the food id
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
//deleting food by name
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
//Edit the food price
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
//Edit the food status 
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
struct Customer
{
    char name[100];
    int id;
    struct Customer *next;
    char status[100];
    struct food *foodItems;
    int totalBill;
};
//add the customer 
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
//display the list of the customer 
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
//edit the order status of the customer 
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
//display Customer order Invoice
void display_Customer_Invoice(struct Customer *customer)
{
    struct Customer *customer_ptr = customer;
    printf("  -----------------------------------------------------------\n");
    printf(" || Food ID ||  Food Price ||       Food Name     || Quantity || Total ||   \n");
    printf("  ------------------------------------------------------------\n");

    while (customer_ptr->foodItems != NULL)
    {
        printf("     %d            %.2f          %s\t    \t%d        %d \n", customer_ptr->foodItems->id, customer_ptr->foodItems->price, customer_ptr->foodItems->name, customer_ptr->foodItems->quantity, customer_ptr->foodItems->total);
         customer_ptr->totalBill=customer_ptr->foodItems->total+customer_ptr->totalBill;
        customer_ptr->foodItems = customer_ptr->foodItems->next;
    }
    printf("  ------------------------------------------------------------\n");
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
            printf("\tCustomer Name \t Customer ID\n");
            printf("\t  %s \t  %d ", customer_ptr->name, customer_ptr->id);
            printf("\n **************************************************************** \n");
            printf("\n ***************************Orders********************************\n");
            display_Customer_Invoice(customer_ptr);
           printf("\t\tTOTAL BILL : %d ",customer_ptr->totalBill);
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

    printf("\nPress -1 to exit \n");
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
    printf("\n===========================\n");
    printf("|| Customer Name || || Customer ID || || Total ||\n");
    while (customer_ptr != NULL)
    {
        printf("\t%s          \t%d       %d\n", customer_ptr->name, customer_ptr->id, customer_ptr->totalBill);
        totalSales = totalSales + customer_ptr->totalBill;
        customer_ptr = customer_ptr->next;
    }
    printf("\n==========================\n");
    printf("Total Sales : %d", totalSales);
    printf("\n==========================\n");
}
// payment of the foood by the customer 
void Payment_Method(struct Customer *customer)
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
        CompleteTheOrder(customer, customer->id);
    }
    if (payOpt == 2)
    {
        printf("Payment Successfull");
        CompleteTheOrder(customer, customer->id);
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
    while (1)
    {
        printf("\n\tWELCOME TO FOOD ORDERING SYSTEM\n");
        printf(" \n\t1-Admin \n\t 2-Customer \n\t -1 to exit ");
        int opt;
        printf("\nEnter : ");
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
            gets(name);
            gets(name);
            int id;
            printf("Enter your last 2 digit of your cnic id : ");
            scanf("%d", &id);
            //when user  Enters to the system this will store the data of the customer in the list 
            customer = addCustomer(customer, name, "Pending", id);
            printf("\n\t  *****Welcome %s to Food Ordering System****\n", name);
            while (1)
            {
                printf("\t    \n 1-Desi Food \n 2-Fast Food \n3-Special Discount Offers \n4- Display Invoice \n5-Payment \n-1 to exit\n");
                int foodOpt;
                printf("\n Enter the Option :  ");
                scanf("%d", &foodOpt);
                if (foodOpt == -1)
                {
                    break;
                }
                if (foodOpt == 4)
                {
                    displayCustomerDetails(customer, id);
                }
                if (foodOpt == 5)
                {
                    Payment_Method(customer);
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
                printf("Enter the password for admin module : ");
                gets(pass);

                if (strcmp(pass, "Arsalan123") == 0)
                {
                    break;
                }
                else
                {
                    printf("Wrong password ....... Enter your password again\n");
                }
            }
            printf("\n====== Welcome to the Admin Page ===========\n");
            while (1)
            {
                printf(" \n 1- Add the food \n  2- Remove the food \n 3- Edit the food \n 4- View the Customer Order Status \n5-Complete the Order\n6-View Sales Report\n -1 to Exit ");
                int adminOpt;
                printf("\n Enter the Option :  ");
                scanf("%d", &adminOpt);
                if (adminOpt == -1)
                {
                    break;
                }

                if (adminOpt == 1)
                {
                    while (1)
                    {
                        printf(" Select the category where you wanna add the food \n");
                        printf(" \n 1- Fast food \n  2- Desi food \n 3- Special Offer food \n -1 to go back ");
                        int category_opt;
                        printf("\n Enter the Option :  ");
                        scanf("%d", &category_opt);
                        // FAST FOOD
                        if (category_opt == -1)
                        {
                            break;
                        }

                        if (category_opt == 1)
                        {
                            display_Food(fastFood);
                            printf("\n---------------------- ADD FAST FOOD ------------------\n");
                            char name[100], status[100];
                            int id;
                            float price;
                            printf("Enter the name of fast food :   ");
                            gets(name);
                            gets(name);
                            printf("Enter the id of the %s", name);
                            scanf("%d", &id);
                            printf("Enter the price of %s", name);
                            scanf("%f", &price);
                            printf("Select the status\n");
                            printf("\n1-Availible\n2-Not Availible\n");
                            printf("\n Enter the Option :  ");
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
                            printf("Enter the name of desi food :   ");
                            gets(name);
                            gets(name);
                            printf("Enter the id of the %s", name);
                            scanf("%d", &id);
                            printf("Enter the price of %s", name);
                            scanf("%f", &price);
                            printf("Select the status\n");
                            printf("\n1-Availible\n2-Not Availible\n");
                            printf("\n Enter the Option :  ");
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
                            printf("Enter the name of  food :   ");
                            gets(name);
                            gets(name);
                            printf("Enter the id of the %s", name);
                            scanf("%d", &id);
                            printf("Enter the price of %s", name);
                            scanf("%f", &price);
                            printf("Select the status\n");
                            printf("\n1-Availible\n2-Not Availible\n");
                            int statusOpt;
                            printf("\n Enter the Option :  ");
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
                        printf("Select the category \n");
                        printf(" \n 1- Fast food \n  2- Desi food \n 3- Special Offer food \n -1 to go back ");
                        int category_opt;
                        printf("\n Enter the Option :  ");
                        scanf("%d", &category_opt);
                        if (category_opt == -1)
                        {
                            break;
                        }
                        if (category_opt == 1)
                        {
                            display_Food(fastFood);
                            printf("\n1-Delete the food by name \n2-Delete the food by id ");
                            int opt;
                            char name[100];
                            int id;
                            printf("\n Enter the Option :  ");
                            scanf("%d", &opt);
                            if (opt == 1)
                            {
                                printf("Enter the name of food :  ");
                                gets(name);
                                gets(name);
                                fastFood = delete_Food_byName(fastFood, name);
                                display_Food(fastFood);
                            }
                            if (opt == 2)
                            {
                                printf("Enter the ID of food :  ");
                                scanf("%d", &id);
                                fastFood = delete_Food_byID(fastFood, id);
                                display_Food(fastFood);
                            }
                        }

                        if (category_opt == 2)
                        {
                            display_Food(desi);
                            printf("\n1-Delete the food by name \n2-Delete the food by id ");
                            int opt;
                            char name[100];
                            printf("\n Enter the Option :  ");
                            scanf("%d", &opt);
                            int id;
                            if (opt == 1)
                            {
                                printf("Enter the name of food :  ");
                                gets(name);
                                gets(name);
                                desi = delete_Food_byName(desi, name);
                                display_Food(desi);
                            }
                            if (opt == 2)
                            {
                                printf("Enter the ID of food :  ");
                                scanf("%d", &id);
                                desi = delete_Food_byID(desi, id);
                                display_Food(desi);
                            }
                        }
                        if (category_opt == 3)
                        {
                            display_Food(special_discount);
                            printf("\n1-Delete the food by name \n2-Delete the food by id ");
                            int opt;
                            char name[100];
                            int id;
                            printf("\n Enter the Option :  ");
                            scanf("%d", &opt);
                            if (opt == 1)
                            {
                                printf("Enter the name of food :  ");
                                gets(name);
                                gets(name);
                                special_discount = delete_Food_byName(special_discount, name);
                                display_Food(special_discount);
                            }
                            if (opt == 2)
                            {
                                printf("Enter the ID of food :  ");
                                scanf("%d", &id);
                                special_discount = delete_Food_byID(special_discount, id);
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
                        printf("Enter the Food Category\n");
                        printf(" \n 1- Fast food \n  2- Desi food \n 3- Special Offer food \n -1 to go back ");
                        int category_opt;
                        printf("\n Enter the Option :  ");
                        scanf("%d", &category_opt);
                        if (category_opt == -1)
                        {
                            break;
                        }
                        if (category_opt == 1)
                        {
                            display_Food(fastFood);
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
                                fastFood = Edit_FoodPrice(fastFood, price, id);
                                display_Food(fastFood);
                            }
                            if (editOpt == 2)
                            {
                                char status[100];
                                int id, choice;
                                printf("Enter the id of the food : ");
                                scanf("%d", &id);
                                printf("Select the Status of food");
                                printf("\n1-Availible\n2-Not Availible");
                                scanf("%d", &choice);
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
                                printf("\n1-Availible\n2-Not Availible");
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
                                printf("\n1-Availible\n2-Not Availible");
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
                }
                if (adminOpt == 6)
                {
                    displaySalesReport(customer);
                }
            }
        }
    }
    return 0;
}