#include <stdio.h>
#include <cs50.h>
#include <math.h>

// IDENTIFYING CREDIT CARDS

int main(void)
{   // IDENTIFY NUMBER POSITIONS: EVEN  > digit1, digit2..
    long long cnum = get_long_long("Number?\n");
    printf("Number: %lli\n", cnum); // Credit Card Number
    int d1 = (cnum / 10) % 10 * 2;
    int d2 = (cnum / 1000) % 10 * 2;
    int d3 = (cnum / 100000) % 10 * 2;
    int d4 = (cnum / 10000000) % 10 * 2;
    int d5 = (cnum / 1000000000) % 10 * 2;
    int d6 = (cnum / 100000000000) % 10 * 2;
    int d7 = (cnum / 10000000000000) % 10 * 2;
    int d8 = (cnum / 1000000000000000) % 10 * 2;

    // TRUE NUMBERS
    int d1true = d1 / 2;
    int d2true = d2 / 2;
    int d3true = d3 / 2;
    int d4true = d4 / 2;
    int d5true = d5 / 2;
    int d6true = d6 / 2;
    int d7true = d7 / 2;
    int d8true = d8 / 2;

    // COUNTING DIGITS
    long long countn = cnum;
    int count = 0;
    while (countn > 1)
    {
        countn = countn / 10;
        count++;
    }

    // OVER 9? DROP YOUR 10 AND GET +1 INSTEAD!
    if (d1 > 9)
    {        d1 = (d1 % 10) + 1;    }
    if (d2 > 9)
    {        d2 = (d2 % 10) + 1;    }
    if (d3 > 9)
    {        d3 = (d3 % 10) + 1;    }
    if (d4 > 9)
    {        d4 = (d4 % 10) + 1;    }
    if (d5 > 9)
    {        d5 = (d5 % 10) + 1;    }
    if (d6 > 9)
    {        d6 = (d6 % 10) + 1;    }
    if (d7 > 9)
    {        d7 = (d7 % 10) + 1;    }
    if (d8 > 9)
    {        d8 = (d8 % 10) + 1;    }

    // ADD UP EVEN NUMBERS AFTER 'OVER 9' EXAMINATION
    int even = d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8;

    // IDENTIFY NUMBERS POSITIONS: ODD
    int d1o = (cnum / 1) % 10;                  // 1
    int d2o = (cnum / 100) % 10;                // 3
    int d3o = (cnum / 10000) % 10;              // 5
    int d4o = (cnum / 1000000) % 10;            // 7
    int d5o = (cnum / 100000000) % 10;          // 9
    int d6o = (cnum / 10000000000) % 10;        // 11
    int d7o = (cnum / 1000000000000) % 10;      // 13
    int d8o = (cnum / 100000000000000) % 10;    // 15

    // CHECK SUM
    int total = d1o + d2o + d3o + d4o + d5o + d6o + d7o + d8o + even;
    printf("Total: %i\n", total);

    // INVALID; CHECK SUM NOT DIVISIBLE BY 10
    if (total % 10 != 0)
    {
        printf("INVALID\n");
    }

    // VISA 16
    else if (count == 16 && d8true == 4)
    {
        printf("VISA\n");
    }

    // VISA 13
    else if (count == 13 && d7o == 4)
    {
        printf("VISA\n");
    }

    // AMERICAN EXPRESS
    else if (count == 15 && d8o == 3 && (d7true == 4 || d7true == 7))
    {
        printf("AMEX\n");
    }

    // MASTERCARD
    else if (count == 16 && d8true == 5 && (d8o == 1 || d8o == 2 || d8o == 3 || d8o == 4 || d8o == 5))
    {
        printf("MASTERCARD\n");
    }

    else
    {
        printf("INVALID\n");
    }
}
