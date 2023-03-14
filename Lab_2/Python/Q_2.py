try:
    num = int(input("Please enter a number between 3 and 9: "))

    if num < 3 or num > 9:
        raise ValueError("Number should be between 3 and 9.")

    for i in range(1, num+1):
        print('*' * i)

    for i in range(num-1, 0, -1):
        print('*' * i)

except ValueError as ve:
    print(f"Error: {ve}")
except Exception as e:
    print(f"Error: {e}")