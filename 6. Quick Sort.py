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

















'''

---

### **Objectives**
1. Understand the **divide-and-conquer** approach used in Quick Sort.
2. Learn to implement the Quick Sort algorithm for sorting an array of floating-point numbers.
3. Analyze the time complexity of Quick Sort in best, worst, and average cases.
4. Practice efficient data organization to handle large datasets.

---

### **Short Theory**

**Quick Sort Algorithm:**
Quick Sort is a recursive sorting algorithm based on the divide-and-conquer paradigm. It partitions the array into two subarrays relative to a pivot element, ensuring elements smaller than the pivot are on the left and larger elements are on the right.

**Steps in Quick Sort:**
1. Select a **pivot** element (commonly the last element of the array).
2. Partition the array into two halves:
   - Left subarray contains elements smaller than the pivot.
   - Right subarray contains elements larger than the pivot.
3. Recursively apply the same logic to the left and right subarrays.
4. Combine the sorted subarrays to form the final sorted array.

**Time Complexity:**
1. **Best Case**: O(n log n)
   - Occurs when the pivot divides the array into two equal halves.
2. **Worst Case**: O(n^2)  
   - Happens when the pivot is consistently the smallest or largest element, leading to unbalanced partitions.
3. **Average Case**: O(n log n)  
   - Most practical datasets result in this complexity due to random pivots.

**Space Complexity:**
- **Space Required**: Big Oh of (n Log n) for recursion stack in the best/average case.
- **Worst Case Space**: Big Oh of (n) if the recursion depth is unbalanced.

**Advantages of Quick Sort:**
- Fastest sorting algorithm for in-memory operations on large datasets.
- Highly efficient for practical use cases with good pivot selection strategies.

**Applications:**
- Sorting in databases.
- Optimized ranking systems.
- Preparing datasets for efficient searching algorithms.

**Python Tools Used:**
- Implement Quick Sort with recursion.
- Use functions for partitioning and sorting subarrays.

---

This assignment emphasizes learning an efficient, widely-used sorting algorithm, fostering an understanding of recursion, partitioning, and algorithmic optimization for real-world applications.'''
