# Part a
multiplication_dict = {i: (i-1)*i for i in range(1, 31)}
print(multiplication_dict)

# Part b
for key, value in multiplication_dict.items():
    print(key, ":", value)

# Part c
sum_of_values = 0
for value in multiplication_dict.values():
    sum_of_values += value
print("Sum of all values:", sum_of_values)

# Part d
user_number = input("Please enter a number that you want to remove from the dictionary: ")
if user_number.isdigit():
    user_number = int(user_number)
    if user_number in multiplication_dict:
        del multiplication_dict[user_number]
        print(f"Dictionary after removing key {user_number}: \n{multiplication_dict}")
    else:
        print(f"{user_number} is not a key in the dictionary.")
else:
    print("Invalid input! Please enter a number.")
