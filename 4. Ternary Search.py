# Function to sort the roll numbers in ascending order (bubble sort)
def sort_roll_numbers(roll_numbers):
    n = len(roll_numbers)
    for i in range(n):
        for j in range(0, n - i - 1):
            if roll_numbers[j] > roll_numbers[j + 1]:
                # Swap the elements
                roll_numbers[j], roll_numbers[j + 1] = roll_numbers[j + 1], roll_numbers[j]

# Ternary search function
def ternary_search(array, left, right, key):
    if right >= left:
        # Divide array into three parts
        mid1 = left + (right - left) // 3
        mid2 = right - (right - left) // 3

        # Check if key is at any mid
        if array[mid1] == key:
            return True
        if array[mid2] == key:
            return True

        # Narrow down to the relevant segment
        if key < array[mid1]:
            return ternary_search(array, left, mid1 - 1, key)
        elif key > array[mid2]:
            return ternary_search(array, mid2 + 1, right, key)
        else:
            return ternary_search(array, mid1 + 1, mid2 - 1, key)
    
    return False

# Main program
print("Enter the number of club members:")
n = int(input())
roll_numbers = []

print("Enter the roll numbers of club members:")
for i in range(n):
    roll_number = int(input())
    roll_numbers.append(roll_number)

# Sort the roll numbers
sort_roll_numbers(roll_numbers)

print("\nSorted Roll Numbers:")
for roll in roll_numbers:
    print(roll, end=" ")

# Search for a student
print("\n\nEnter the roll number to search:")
key = int(input())
is_member = ternary_search(roll_numbers, 0, len(roll_numbers) - 1, key)

if is_member:
    print(f"Roll number {key} is a member of the club.")
else:
    print(f"Roll number {key} is NOT a member of the club.")


# Enter the number of club members:
# 5
# Enter the roll numbers of club members:
# 34
# 12
# 7
# 56
# 23

# Sorted Roll Numbers:
# 7 12 23 34 56 

# Enter the roll number to search:
# 23
