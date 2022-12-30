# ex2_AP

Advanced Programming 1 by Niv Swisa & Guy Reuveni -

WHAT THE PROGRAM DOES :

This is a machine learning program. The program receives arguments from the command line. the arguments are an integer marked as 'k', a file name and a distance algorithm from one of the following - "MIN" - minkowski, "AUC" - euclidean, "MAN" - manhattan, "CAN" - canberra and "CHB" - chebyshev. After that the user inputs double values that will represent a vector, and check for it's validity. The program will scan the file from the argument line, and take all the rows from the file and represent each row as an object that will consist of a vector with double values, a string to represent the type of the vector (such as flower type), and a double variable that will represent the distance of the current vector from the input vector according to the distance algorithm from the command line. the program will then create a master vector that will contain all the objects created from each row in the given file. next, the program will take the user input vector and calculate it's distance from each and every vector that is in the objects of the master vector. now we will have many distance values, one for every comparison. according to the 'k' values we will take the k nearest vectors (meaning the k smallest distances) and determine according to the string that each of these vectors represent, what is most likely the type of vector of the user input, meaning what type of flower does the vector of the user represent for instance.

HOW TO RUN THE PROGRAM :

In order to run the program you need to clone it to your PC and :

1. Use the cd command to access the cloned directory

2. Use the command "cd ex2_AP" in order to access the c++ file containing all the headers and classes

3. Now you need to compile the files using the "make" command.

4. To run the project enter "./a.out" and the enter the arguments listed above (k, file name, distance algorithm) accordingly.

5. Now you can enter the vector and run the program.

NOTES :

1. If the vectors from the user input and the vectors from the read file are not of the same length the program will exit.

2. If the input consists of anything other than double values the program will exit, such as:
  - if the input is empty
  - if there is more than one decimal period in a single number.
  - if a decimal number starts with a decimal period instead of a number or a minus sign.
  - if the are doubleblank spaces in a row or other whitespaces like tab etc.
  - if the input starts with a blank space
  - if the input consists of anything else other than a decimal period or a digit such as letter, signs and so on.

3. if one of the values is greater than a double value the program will exit. 

4. The minkowski algorithm is the base to the manhattan and euclidean algorithms. In manhattan the p value is the constant 1 and in the euclidean the p value is the constant 2.

5. The p Value chosen for the minkowski algorithm is the constant 2.

6. In the canberra algorithm we covered the case where the division by zero could occur and made sure to avoid the calculation.

7. If the 'k' entered in the command line is greater than the amount of rows in the file or equal to or less than zero the program will exit.

8. If the sorting algorithm chosen in the command line is not written in the right format from one of the options, the program will exit.

9. If there are more or less than 4 arguments in the command line the program will exit.

10. The program will run in a endless loop until an invalid vector is entered or by an initiated stop.
