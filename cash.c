#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float dollars;
    int cents;
    int coins = 0;
    // prompt the user for a positive amount
    do
    {
        dollars = get_float("change owed: ");
        // if the user enters an integer >= 1, treat it as cents
        if (dollars >= 1 && floor(dollars) == dollars)
        {
            dollars = dollars / 100;
        }
    }
    while (dollars <= 0);
    // convert dollars to cents and round
    cents = round(dollars * 100);
    // count quarters
    coins += cents / 25;
    cents %= 25;
    // count dimes
    coins += cents / 10;
    cents %= 10;
    // count nickels
    coins += cents / 5;
    cents %= 5;
    // count pennies
    coins += cents;
    // print the total number of coins
    printf("%i\n", coins);
}
