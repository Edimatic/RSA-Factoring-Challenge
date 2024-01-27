#include <stdio.h>
#include <stdlib.h>

/**
 * is_prime - Check if a given number is prime.
 * @num: The number to check for primality.
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */

int is_prime(long long num)
{
	long long i;

		if (num < 2)
	{
		return (0);
	}
	for (i = 2; i * i <= num; i++)
	{
	if (num % i == 0)
	{
		return (0);
		}
	}
		return (1);
}

/**
 * factorize_number - Factorize a number into two prime factors.
 * @n: The number to factorize.
 * @factor1: Pointer to store the first prime factor.
 * @factor2: Pointer to store the second prime factor.
 *
 * Return: 1 if successful, 0 if no proper factors found.
 */

int factorize_number(long long n, long long *factor1, long long *factor2)
{
		long long i;

	if (n < 2)
	{
		return (0);  /* Numbers less than 2 cannot be factorized */
	}

	for (i = 2; i * i <= n; i++)
	{
	if (n % i == 0)
	{
	*factor1 = i;
	*factor2 = n / i;
		return (1);
		}
	}
		return (0);  /* No proper factors found */
}

/**
 * process_file - Process a file containing numbers and print
 * their prime factorization.
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
		long long factor1, factor2;

	if (factorize_number(n, &factor1, &factor2))
	{
		printf("%lld=%lld*%lld\n", n, factor1, factor2);
	}
	else
	{
	printf("%lld=No factors found\n", n);
		}
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
		char *file_path;

if (argc != 2)
	{
	fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(1);
}
	file_path = argv[1];
	process_file(file_path);

		return (0);
}

