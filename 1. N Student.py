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
