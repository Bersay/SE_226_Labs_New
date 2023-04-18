n = int(input("Enter the value for parameter n: "))
x = int(input("Enter the value for parameter x: "))

factorial = lambda x: 1 if x == 0 else x * factorial(x - 1)

terms = [(n ** i) / factorial(i) for i in range(x + 1)]

result = sum(terms)

print("The result is: ", result)