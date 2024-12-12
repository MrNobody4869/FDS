# Main program that takes user input and sorts the percentages without using functions or built-in methods
n = int(input("Enter the number of students: "))  # Number of students

percentages = []
print("Enter the percentages of students:")
for i in range(n):
    percentage = float(input(f"Percentage of student {i + 1}: "))
    percentages.append(percentage)

# Display the original list
print("\nOriginal percentages:")
for percentage in percentages:
    print(percentage, end=" ")

# Selection Sort (Without using functions)
selection_sorted = percentages.copy()

# Perform selection sort on the array
for i in range(n):
    # Find the index of the smallest element in the unsorted part
    min_idx = i
    for j in range(i + 1, n):
        if selection_sorted[j] < selection_sorted[min_idx]:
            min_idx = j
    # Swap the found minimum element with the first element
    temp = selection_sorted[i]
    selection_sorted[i] = selection_sorted[min_idx]
    selection_sorted[min_idx] = temp

# Display top 5 scores after Selection Sort
print("\n\nTop 5 scores after Selection Sort:")
for i in range(min(5, n)):
    print(selection_sorted[-(i + 1)], end=" ")

# Bubble Sort (Without using functions)
bubble_sorted = percentages.copy()

# Perform bubble sort on the array
for i in range(n):
    for j in range(0, n - i - 1):
        if bubble_sorted[j] > bubble_sorted[j + 1]:
            # Swap the elements if they are in the wrong order
            temp = bubble_sorted[j]
            bubble_sorted[j] = bubble_sorted[j + 1]
            bubble_sorted[j + 1] = temp

# Display top 5 scores after Bubble Sort
print("\n\nTop 5 scores after Bubble Sort:")
for i in range(min(5, n)):
    print(bubble_sorted[-(i + 1)], end=" ")



# Enter the number of students: 6
# Enter the percentages of students:
# Percentage of student 1: 75.5
# Percentage of student 2: 82.3
# Percentage of student 3: 68.9
# Percentage of student 4: 91.2
# Percentage of student 5: 80.5
# Percentage of student 6: 55.7

# Original percentages:
# 75.5 82.3 68.9 91.2 80.5 55.7 

# Top 5 scores after Selection Sort:
# 91.2 82.3 80.5 75.5 68.9 

# Top 5 scores after Bubble Sort:
# 91.2 82.3 80.5 75.5 68.9
