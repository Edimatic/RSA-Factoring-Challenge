#!/usr/bin.python3

import sys


def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def pollards_rho(n):
    if n % 2 == 0:
        return 2
    
    x, y, d = 2, 2, 1
    f = lambda x: (x**2 + 1) % n

    while d == 1:
        x = f(x)
        y = f(f(y))
        d = gcd(abs(x - y), n)

    return d

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def find_prime_factors(n):
    factors = []
    
    while n > 1:
        factor = pollards_rho(n)
        while n % factor == 0:
            n //= factor
            factors.append(factor)

    return factors

def process_file(file_path):
    try:
        with open(file_path, 'r') as file:
            for line in file:
                n = int(line.strip())
                factors = find_prime_factors(n)
                print(f"{n}={'*'.join(map(str, factors))}")
    except FileNotFoundError:
        print(f"Error: File '{file_path}' not found.")
    except ValueError:
        print("Error: Invalid data in the file. Ensure all lines contain valid natural numbers.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python rsa_prime_factors.py <file>")
        sys.exit(1)

    file_path = sys.argv[1]
    process_file(file_path)
