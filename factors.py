#!/usr/bin/pyton3


# factors.py
import sys

def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def factorize_number(n):
    for i in range(2, n):
        if n % i == 0:
            return i, n // i

def process_file(file_path):
    try:
        with open(file_path, 'r') as file:
            for line in file:
                line = line.strip()
                if line:
                    n = int(line)
                    factors = factorize_number(n)
                    print(f"{n}={factors[0]}*{factors[1]}")
    except FileNotFoundError:
        print(f"Error: File '{file_path}' not found.")
    except ValueError:
        print("Error: Invalid data in the file. Ensure all lines contain valid natural numbers greater than 1.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python factors.py <file>")
        sys.exit(1)

    file_path = sys.argv[1]
    process_file(file_path)
