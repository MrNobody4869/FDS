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






'''///OBJECTIVES///

Understand the concept of searching algorithms, focusing on Ternary Search.
Practice maintaining and sorting a collection of data (e.g., roll numbers) in ascending order.
Implement Ternary Search to efficiently check for membership in the club.
Gain experience in using Python for data organization and efficient algorithm implementation.


///THEORY///
Searching Algorithms: Searching is the process of finding the location of a target element in a collection of data. Efficient search algorithms reduce the time complexity, especially for large datasets.

Ternary Search: Ternary Search is a divide-and-conquer algorithm that divides the search space into three parts, as opposed to two in Binary Search. It is used for searching in sorted data arrays.

Key Steps of Ternary Search:

Divide the array into three parts by two midpoints:
mid1 = left + (right - left) / 3
mid2 = right - (right - left) / 3
Compare the target value with elements at mid1 and mid2:
If the target matches, return the index.
If the target is less than mid1, search in the left part.
If the target is greater than mid2, search in the right part.
Otherwise, search in the middle segment.
Repeat until the target is found or the search space is exhausted.
Complexity:

Time Complexity: Big OH of (log3N)
Space Complexity: Big Oh of (1)

Applications:

Club Membership Management: Efficiently verify if a roll number exists.
Optimized Searching: Suitable for sorted arrays in scenarios where comparisons are computationally expensive.
Advantages of Ternary Search:

Faster convergence for large datasets.
Provides better division for certain unimodal functions or scenarios.
Python Tools Used:

Sorting of arrays using built-in methods (e.g., sort()).
Implementation of the Ternary Search algorithm using loops or recursion.
'''

