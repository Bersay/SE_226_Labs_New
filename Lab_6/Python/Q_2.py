global result

def sum_calculator(n):
    
    """
    My sum_calculator function uses recursion to calculate the sum of a series dependent on the input number n,
    but it does not return any value.
    Instead, it updates the global variable result to store the final result of the calculation.
    """

    global result

    if n == 1:
        result = 1
    else:
        sum_calculator(n - 1)
        result += ((-1) ** (n + 1)) / n
        
n = int(input("Enter the value for n: "))

sum_calculator(n)

print("The result is:", result)