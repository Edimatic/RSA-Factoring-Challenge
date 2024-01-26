#include <stdio.h>
#include <stdlib.h>

/**
 * gcd - Compute the greatest common divisor of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The greatest common divisor of a and b.
 */
long long gcd(long long a, long long b)
{
    while (b)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return (a);
}

/**
 * square_and_add_one - Compute the square of a number and add one.
 * @x: The number.
 *
 * Return: The result of squaring x and adding one.
 */

long long square_and_add_one(long long x)
{
    return (x * x + 1);
}


/**
 * pollards_rho - Pollard's rho algorithm to find a non-trivial factor of a number.
 * @n: The number to factorize.
 *
 * Return: A non-trivial factor of n.
 */

long long pollards_rho(long long n)
{
    if (n % 2 == 0)
    {
        return (2);
    }

    long long x = 2, y = 2, d = 1;
    long long (*f)(long long) = &square_and_add_one;

    while (d == 1)
    {
        x = f(x) % n;
        y = f(f(y)) % n;
        d = gcd(llabs(x - y), n);
    }

    return (d);
}


/**
 * find_prime_factors - Find the prime factors of a number and print them.
 * @n: The number to factorize.
 */
void find_prime_factors(long long n)
{
    while (n > 1)
    {
        long long factor = pollards_rho(n);
        while (n % factor == 0)
	{
            n /= factor;
            printf("%lld", factor);
            if (n > 1)
	    {
                printf("*");
            }
        }
    }
}

/**
 * process_file - Process a file containing numbers and print 
	their prime factorization.
 *
 * @file_path: The path to the input file.
 */

void process_file(char *file_path)
{
    FILE *file = fopen(file_path, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        long long n = atoll(line);
        printf("%lld=", n);
        find_prime_factors(n);
        printf("\n");
    }

    fclose(file);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: 0 on success, 1 on failure.
 */

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    char *file_path = argv[1];
    process_file(file_path);

    return (0);
}

