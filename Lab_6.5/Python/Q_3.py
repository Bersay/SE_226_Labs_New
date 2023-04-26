def sieve_of_eratosthenes(numbers):
    if len(numbers) < 2:
        return []

    max_number = max(numbers)
    is_prime = [True] * (max_number + 1)
    is_prime[0] = False
    is_prime[1] = False

    for num in range(2, int(max_number ** 0.5) + 1):
        if is_prime[num]:
            for multiple in range(num * num, max_number + 1, num):
                is_prime[multiple] = False

    primes = [num for num in numbers if is_prime[num]]
    return primes

integer_list = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]

result = sieve_of_eratosthenes(integer_list)
print(result)