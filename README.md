# KNN C-Classifier

This C program implements the k-nearest neighbor (KNN) algorithm to classify test data points based on their proximity to the training data set. The program reads input data from two files, "dataset.csv" and "dataset_test.csv", and writes the output to a file named "result.csv".

## Requirements
- C compiler (e.g. GCC)
- Input data files ("dataset.csv" and "dataset_test.csv")

## Usage
1. Compile the program using a C compiler (e.g. GCC) :
```
$ gcc knn.c -o knn
```
2. Place the input data files ("dataset.csv" and "dataset_test.csv") in the same directory as the compiled program.
3. Run the program from the command line :
```
$ ./knn
```
4. The program will output the classification results to the file "result.csv".
