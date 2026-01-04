#include <stdio.h>

#define GST_RATE 0.18

void showMenu(char items[][20], float price[], int n);
void printBill(char items[][20], float price[], int qty[], int n);

int main() {
    char items[8][20] = {
        "Burger",
        "Pizza",
        "Pasta",
        "Sandwich",
        "French Fries",
        "Cold Drink",
        "Coffee",
        "Ice Cream"
    };

    float price[8] = {120, 250, 180, 100, 80, 50, 90, 70};
    int qty[8] = {0};

    int choice, quantity;
    char more;

    printf("\n=====================================\n");
    printf("        WELCOME TO FOOD HUB            \n");
    printf("=====================================\n");

    do {
        showMenu(items, price, 8);

        printf("\nEnter item number: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 8) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            qty[choice - 1] += quantity;
        } else {
            printf("Invalid choice!\n");
        }

        printf("Add more items? (y/n): ");
        scanf(" %c", &more);

    } while (more == 'y' || more == 'Y');

    printBill(items, price, qty, 8);

    return 0;
}

// Display Menu
void showMenu(char items[][20], float price[], int n) {
    int i;
    printf("\n-------------- MENU ----------------\n");
    for (i = 0; i < n; i++) {
        printf("%d. %-15s Rs %.2f\n", i + 1, items[i], price[i]);
    }
}

// Print Restaurant Bill with GST
void printBill(char items[][20], float price[], int qty[], int n) {
    int i;
    float subtotal = 0, gst, grandTotal;

    printf("\n=====================================\n");
    printf("              FOOD HUB                \n");
    printf("            TAX INVOICE           \n");
    printf("=====================================\n");
    printf("%-15s %5s %10s\n", "Item", "Qty", "Amount");
    printf("-------------------------------------\n");

    for (i = 0; i < n; i++) {
        if (qty[i] > 0) {
            float amt = qty[i] * price[i];
            subtotal += amt;
            printf("%-15s %5d %10.2f\n", items[i], qty[i], amt);
        }
    }

    gst = subtotal * GST_RATE;
    grandTotal = subtotal + gst;

    printf("-------------------------------------\n");
    printf("%-21s %10.2f\n", "Sub Total", subtotal);
    printf("%-21s %10.2f\n", "GST (18%)", gst);
    printf("%-21s %10.2f\n", "Grand Total", grandTotal);
    printf("=====================================\n");
    printf("   Thank You! Visit Again\n");
    printf("=====================================\n");
}
