#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define maxn 10005
#include<string.h>

typedef struct {
    int arr[maxn];
    int length;
} vector;

vector read_vector() {
/**
    Function to read a vector from the user.
    Input: nothing
    Output: the vector which was read
*/
    vector v;
    int i;
    printf("The number of numbers: ");
    scanf_s("%d", &v.length);
    printf("The numbers are: ");
    for(i = 0 ; i < v.length ; ++ i)
        scanf_s("%d", v.arr + i);

    return v;
}

void print_vector(vector v) {
/**
    Function to print a vector to the standard output.
    Input: v: vector
    Output: the content of the vector v on stdout
*/
    int i;
    for(i = 0 ; i < v.length ; ++ i)
        printf("%d ", v.arr[i]);
    printf("\n");
}

float int_part(int number){
/**
    Function which compute the integral part of square root of number.
    Compare the square of mid integer with the given number.
    If it is equal to the number, then we found our integral part, else look for the same in left or right side depending upon the scenario.
    Input :number
    Output: the integral part of square root of the given number
*/
    int start = 0, end = number, mid;
    double val = 0.0;
    while (start <= end)
    {
        mid = (start + end) / 2;

        if (mid * mid == number)
        {
            val = mid;
            break;
        }

        // incrementing start if integral part lies on right side of the mid
        if (mid * mid < number)
        {
            start = mid + 1;
            val = mid;
        }

            // decrementing end if integral part lies on the left side of the mid
        else
            end = mid - 1;

    }
    return (float) val;
}

double square_root(int number,int precision)
{
    /**
     Function to determine the approximated value of square root of a positive real number
     Initialize the increment variable by 0.1 and iteratively compute the fractional part upto p places.
     For each iteration, increment changes to 1/10th of it’s previous value.
     Input: the number and the precision
     Output: approximated value
     */
    //int start = 0, end = number, mid;
    double val = 0.0;

    // computing the fractional part of square root upto given precision
    double increment = 0.1;
    val = int_part(number);
    for (int i = 0; i < precision; i++)
    {
        while (val * val <= number)
            val += increment;

        // loop terminates when ans * ans > number
        val = val - increment;
        increment = increment / 10;
    }
    return (double) val;
}



int prime_number(int number)
/**
    Function that checks if a number is prime.
    First it handles the special cases(0,1 and 2), then the even numbers, which cannot be prime.
    After that, it goes through every possible odd divisor. If the remainder of the division is 0, then the number
    is not prime.

    Input :number: integer
    Output:
           returns 0: the number is not prime
           returns 1: the number is prime
 */
{
    if (number == 0 || number == 1)
        return 0;
    if (number == 2)
        return 1;
    if (number % 2 == 0)
        return 0;

    int div = 3;
    while (div * div <= number) {
        if (number % div == 0)
            return 0;
        div += 2;
    }

    return 1;
}

vector function_2(vector v) {
/**
    Function to solve the second task
    Input: v: vector
    Output: the longest contiguous subsequence such that the difference of any two consecutive elements is a prime number.
*/
    int i = 0, maxi = 1, limax = 0;
    while(i < v.length) {
        int ls = i;
        while(ls + 1 < v.length && prime_number(abs(v.arr[ls+1] - v.arr[ls]))== 1)
            ++ ls;
        if(maxi < ls - i + 1) {
            maxi = ls - i + 1;
            limax = i;
        }
        i = ls + 1;
    }
    vector ret;
    ret.length = 0;
    for(i = limax ; i < limax + maxi ; ++ i)
        ret.arr[ret.length ++ ] = v.arr[i];

    return ret;
}

int function_3(int n, int p)
{/**
   Print the exponent of a prime number p from the decomposition in prime factors of a given number n
   Input: number n and prime number p
   Output: exponent of  p from the decomposition in prime factors of number n
*/
    int exp = 0;

    while(n % p ==0)
    {
        exp++;
        n=n/p;}
    return exp;
}
void print_menu() {
/**
   Prints the console-based menu of the program.
   Input: none
   Output: none
*/

    printf(
            "1-Compute the approximated value of square root of a positive real number.\n");
    printf(
            "2-Find the longest contiguous subsequence such that the difference of any two consecutive elements is a prime number.\n");
    printf("3-Print the exponent of a prime number p from the decomposition in prime factors of a given number n");
    printf("0 - Exit\n");
    printf("Pick an option:\n");
}

int main() {
/**
    Main function.
    Input: none
    Output: none
*/

    int option;

    while (1) {
        print_menu();
        scanf_s("%d", &option);

        if (option == 1)
        {
            int n=0,dec= 0;
            printf("Give the number: ");
            scanf_s("%d", &n);
            printf("Give the precision: ");
            scanf_s("%d", &dec);

            // Function call
            char str1[20]="%.";
            char str2[20];
            sprintf(str2,"%d",dec);
            strcat(str1,str2);
            strcat(str1,"f");
            printf(str1, square_root(n,dec));
            //printf("%.9f ", square_root(n,dec));
            printf("\n");
        }

        else if (option == 2)
        {
            vector vect;
            vect = read_vector();
            vector ans;
            ans = function_2(vect);
            print_vector(ans);
        }
        else if (option == 3)
        {   int nr, p,exp;
            printf("Give the number: ");
            scanf_s("%d", &nr);
            printf("Give the prime number: ");
            scanf_s("%d", &p);
            exp = function_3(nr,p);
            printf("%d",exp);
            printf("\n");
        }

        else if (option == 0)
            break;
        else
            printf("Invalid option!\n");
    }

    return 0;
}

