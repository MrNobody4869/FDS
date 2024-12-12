# Quick Sort function without using any built-in methods or classes
def quick_sort(arr, low, high):
    if low < high:
        # Partitioning index
        pi = partition(arr, low, high)
        
        # Recursively sort elements before and after partition
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

# Function to partition the array for Quick Sort
def partition(arr, low, high):
    pivot = arr[high]  # Taking the last element as the pivot
    i = low - 1  # Index of smaller element

    # Traverse through the array and rearrange elements
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            # Swap arr[i] and arr[j]
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp

    # Swap arr[i + 1] and arr[high] (pivot element)
    temp = arr[i + 1]
    arr[i + 1] = arr[high]
    arr[high] = temp
    
    return i + 1

# Main program to take user input, sort using quick sort and display top 5 scores
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

# Quick Sort the array
quick_sort(percentages, 0, n - 1)

# Display top 5 scores after sorting in ascending order
print("\n\nTop 5 scores after Quick Sort (ascending order):")
for i in range(min(5, n)):
    print(percentages[-(i + 1)], end=" ")
