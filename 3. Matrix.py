# Matrix operations without using built-in functions, packages, or classes

# Function to add two matrices
def add_matrices(matrix1, matrix2):
    rows, cols = len(matrix1), len(matrix1[0])
    result = [[0 for _ in range(cols)] for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            result[i][j] = matrix1[i][j] + matrix2[i][j]
    return result

# Function to subtract two matrices
def subtract_matrices(matrix1, matrix2):
    rows, cols = len(matrix1), len(matrix1[0])
    result = [[0 for _ in range(cols)] for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            result[i][j] = matrix1[i][j] - matrix2[i][j]
    return result

# Function to multiply two matrices
def multiply_matrices(matrix1, matrix2):
    rows1, cols1 = len(matrix1), len(matrix1[0])
    rows2, cols2 = len(matrix2), len(matrix2[0])
    result = [[0 for _ in range(cols2)] for _ in range(rows1)]
    for i in range(rows1):
        for j in range(cols2):
            for k in range(cols1):
                result[i][j] += matrix1[i][k] * matrix2[k][j]
    return result

# Function to transpose a matrix
def transpose_matrix(matrix):
    rows, cols = len(matrix), len(matrix[0])
    result = [[0 for _ in range(rows)] for _ in range(cols)]
    for i in range(rows):
        for j in range(cols):
            result[j][i] = matrix[i][j]
    return result

# Input matrices
print("Enter the dimensions of the matrices (rows and columns):")
rows, cols = int(input("Rows: ")), int(input("Columns: "))

print("\nEnter the elements of the first matrix row by row:")
matrix1 = []
for i in range(rows):
    row = list(map(int, input().split()))
    matrix1.append(row)

print("\nEnter the elements of the second matrix row by row:")
matrix2 = []
for i in range(rows):
    row = list(map(int, input().split()))
    matrix2.append(row)

# Perform computations
print("\nAddition of matrices:")
addition_result = add_matrices(matrix1, matrix2)
for row in addition_result:
    print(row)

print("\nSubtraction of matrices:")
subtraction_result = subtract_matrices(matrix1, matrix2)
for row in subtraction_result:
    print(row)

if len(matrix1[0]) == len(matrix2):
    print("\nMultiplication of matrices:")
    multiplication_result = multiply_matrices(matrix1, matrix2)
    for row in multiplication_result:
        print(row)
else:
    print("\nMultiplication is not possible due to dimension mismatch.")

print("\nTranspose of the first matrix:")
transpose_result = transpose_matrix(matrix1)
for row in transpose_result:
    print(row)


# Sample input to run the program:
# Enter the dimensions of the matrices (rows and columns):
# Rows: 2
# Columns: 2
# Enter the elements of the first matrix row by row:
# 1 2
# 3 4
# Enter the elements of the second matrix row by row:
# 5 6
# 7 8


















'''///OBJECTIVES///
Understand the representation and manipulation of two-dimensional arrays (matrices) in Python.
Learn to perform basic matrix operations, including:
Addition of two matrices.
Subtraction of two matrices.
Multiplication of two matrices.
Transposition of a matrix.
Develop problem-solving skills by implementing mathematical operations on matrices using Python’s data structures.


///THEORY///
Matrix Representation: A matrix is a collection of numbers arranged in rows and columns, forming a two-dimensional data structure. In Python, matrices can be represented using nested lists, where each sublist corresponds to a row of the matrix.

Key Characteristics of Matrices:

Dimensions: Defined by the number of rows and columns.
Indexing: Elements can be accessed using [row][column] indices.
Operations: Matrices support mathematical operations that adhere to specific rules, such as matching dimensions for addition or compatibility for multiplication.
Basic Matrix Operations:

Addition/Subtraction: Performed element-wise; matrices must have the same dimensions.
Multiplication: Follows the dot product rule, where the number of columns in the first matrix must match the number of rows in the second.
Transpose: Swaps the rows and columns of a matrix.
Applications: Matrix operations are fundamental in various domains, including:

Computer Graphics: For transformations and projections.
Data Science: As the foundation for linear algebra and machine learning.
Physics and Engineering: To model and solve systems of equations.
Python Tools: Matrix operations can be implemented using:

Nested Lists: Python’s built-in data structures for custom implementations.
Libraries like NumPy: To optimize and simplify operations with built-in functions.
'''






