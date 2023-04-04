divided = {'Tony': 41, 'Rhodey': 43, 'Nat': 35}
we_fall = {'Steve': 39, 'Clint': 35, 'Wanda': 28}

# Part a
united_we_stand = {**divided, **we_fall}

print("Name       Age")
for key, value in united_we_stand.items():
    print(f"{key:<10} {value}")

# Part b
del united_we_stand['Nat']
print("\nUpdated united_we_stand:")
print("Name       Age")
for key, value in united_we_stand.items():
    print(f"{key:<10} {value}")

# Part c
print("\nSorted united_we_stand:")
print("Name       Age")
for key in sorted(united_we_stand.keys()):
    print(f"{key:<10} {united_we_stand[key]}")

# Part d
max_age = max(united_we_stand.values())
min_age = min(united_we_stand.values())

print(f"\nMaximum value: {max_age}")
print(f"Minimum value: {min_age}")