# Function to compute the average score of the class
def compute_average(marks):
    total_marks = sum(marks)
    num_students = len(marks)
    return total_marks / num_students if num_students > 0 else 0

# Function to find the highest and lowest score in the class
def find_highest_lowest(marks):
    return max(marks), min(marks)

# Function to count the number of students absent for the test
def count_absentees(marks):
    return marks.count(-1)

# Function to find the mark with the highest frequency
def mark_with_highest_frequency(marks):
    frequency = {}
    for mark in marks:
        if mark != -1:  # Exclude absentees
            frequency[mark] = frequency.get(mark, 0) + 1
    
    max_freq = max(frequency.values(), default=0)
    highest_freq_marks = [mark for mark, freq in frequency.items() if freq == max_freq]

    return highest_freq_marks, max_freq

# Input the number of students
n = int(input("Enter the number of students: "))

# Input marks for each student (-1 for absent)
marks = []
print("Enter the marks for each student (-1 for absent):")
for i in range(n):
    mark = int(input(f"Student {i + 1}: "))
    marks.append(mark)

# Exclude absentees for calculations
valid_marks = [mark for mark in marks if mark != -1]

# a) Compute the average score of the class
average_score = compute_average(valid_marks)
print(f"\nThe average score of the class is: {average_score:.2f}")

# b) Find the highest and lowest score of the class
if valid_marks:
    highest_score, lowest_score = find_highest_lowest(valid_marks)
    print(f"The highest score in the class is: {highest_score}")
    print(f"The lowest score in the class is: {lowest_score}")
else:
    print("No valid marks to determine highest and lowest scores.")

# c) Count the number of students absent for the test
absent_count = count_absentees(marks)
print(f"The number of students absent for the test is: {absent_count}")

# d) Display the mark with the highest frequency
if valid_marks:
    highest_freq_marks, max_freq = mark_with_highest_frequency(marks)
    print(f"The marks with the highest frequency ({max_freq} times): {highest_freq_marks}")
else:
    print("No valid marks to determine frequency.")




















'''///Objectives///
Understand the concept and implementation of arrays as a linear data structure.
Practice manipulating array elements using Python programming.
Learn how to:
Calculate the average score of a class.
Identify the highest and lowest marks in the class.
Count absent students (represented by -1 in the array).
Determine the marks with the highest frequency.
Gain familiarity with object-oriented programming concepts, such as creating and using classes and functions in Python.


///Short Theory///
Array Data Structure: An array is a collection of data items stored at contiguous memory locations. In programming, it allows storing multiple values in a single variable, where each value can be accessed using an index. Python implements arrays as lists, which are dynamic and can hold elements of varying data types.

Key Characteristics of Python Lists:

Ordered collection of elements.
Mutable (modifiable) data structure.
Supports a wide range of methods for traversal, insertion, deletion, and other manipulations.
Basic Array Operations:

Traverse: Access each element sequentially.
Insertion: Add elements at specific indices.
Deletion: Remove elements at specific indices.
Search: Find elements by index or value.
Update: Modify elements at specific positions.
The use of arrays in this problem facilitates efficient computation of average scores, identification of extremes (min and max), and counts of absent or common marks.'''
