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







'''
///OBJECTIVES///

Understand the concept of sorting algorithms and their role in organizing data.
Learn and implement:
Selection Sort: A simple comparison-based sorting technique.
Bubble Sort: A basic sorting algorithm that repeatedly swaps adjacent elements.
Gain insights into the performance of sorting algorithms and their time complexity.
Display the top five scores after sorting the array.
Short Theory
Sorting Algorithms: Sorting is the process of arranging elements of a list in a specific order (e.g., ascending or descending). It is a fundamental operation used to organize data for efficient searching and analysis.

Selection Sort:
Concept: Finds the smallest (or largest) element in the unsorted portion and swaps it with the first unsorted element.
Steps:
1.Start with the first element.
2.Find the minimum element in the unsorted section.
3.Swap it with the first unsorted element.
4.Repeat for the remaining unsorted section.

Complexity:
Time Complexity: Big Oh of (N square) for all cases
Space Complexity: Big Oh of (1)

Bubble Sort:
Concept: Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
Steps:
Traverse the array from the start.
Compare adjacent elements and swap them if needed.
Repeat until no more swaps are required.

Complexity:
Time Complexity: Best is (N), avg/worst is (N square)
Space Complexity: Big Oh of (1)

Comparison of Sorting Algorithms:

Selection Sort is preferred when the number of swaps must be minimized.
Bubble Sort is easier to implement but less efficient due to its higher number of swaps.
Applications: Sorting is critical in:

Preparing datasets for binary or ternary searches.
Ranking systems (e.g., top scores).
Real-world use cases like leaderboards, scheduling, and analytics.
Python Tools Used:

Implementation of sorting using loops and conditions.
Comparison of outputs for efficiency evaluation.
'''
