def common_elements(list1, list2):

    common_set = set(list1) & set(list2)

    return list(common_set)

list1 = [1, 2, 3, 4, 5]
list2 = [5, 6, 7, 8, 9, 10]

result = common_elements(list1, list2)

print(result)