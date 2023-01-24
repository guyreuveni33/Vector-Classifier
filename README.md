# ex4_AP

Advanced Programming 1 by Niv Swisa & Guy Reuveni -

WHAT THE PROGRAM DOES :

This is a machine learning program. This program is divided into two sides, client and server.
Client side: the client receives two arguments from the command line, the first argument is the ip number and the second argument is the port number.
Server side: the server receives two arguments from the command line, the first argument is the file route and the second argument is the port number.

In order to operate the program, we will first need to turn on the server so that it will be able to connect to a client using the port number. after that the client will connect to the server, and now the server will wait for a message from the client. the server and client will communicate through a socket called dio, both of them will create a dio and then send it to a CLI class, which will hold a vector to all the commands. the menu will then open up to the client and the user will choose an option from the menu, according to the option chosen by the user, the class of the chosen option from the menu will execute and start communicating with the server. the communication will happen through the class socketIO that both the client and the server hold. when the client writes the server reads and when the server writes the client reads. they will go back and forth until the option chosen has been fully executed.
the options from the menu are:
1. upload a classified and unclassified csv file accordingly :
  the user will choose 1, then the client will ask the user to enter a filepath for a classified csv file. when the path is entered, the user will   open the file and send its content to the server and the server will store the content in a mastervector call train.
  after that the client will ask for the user to enter a path for an unclassified csv file. when the path is entered, the user will open the file   and send its content to the server and the server will store the content in a mastervector call tesr. after entering two valid filepaths, the     server will send the menu to the client and the client will print for the menu again.
  
2. set a k value and a distance metric for future calculations:
  the user will press 2 and the current K and distance metric will be presented on the screen. the user will have the option to change the k and     distance metric, he will have to enter the k and the distance metric accordingly and they will have to be valid. once the user enters the new K   and distance metric the menu will pop up again and the new values will be updated. the default settings in the beginning of the program are k=5   and distance metris - 'AUC'.

3. classify the unclassified file with the k and distance metric that is set in option 2 and according to the classified file:
  the user will press 3, and wait for the servers update that the file has been classified. the server will take the unclassified file from option   1 and classify it with the KNN algorithm using the k and distance metric from option 2. for every row in the unclassified file it will calculate   the distance of the row from all the rows in the classified file and take the K nearest distances and that way it will classify the row from the   unclassified file. after the server is finished with the entire unclassified file it will update the client and the user will be notified that     the classification has been done.
  
4. print all the classification and the row number of the classification to the client on the screen:
  the user will press 4, the server will open the file that was classified in option 3 and for every row in the file it will send the row number     and the classification string of the vector in that row to the client, the client will receive and print all of the rows and their classifications to the user   on the screen.
  
5. perform the exact same thing as option 4 but instead of printing it on the screen create a new file and print it in the file locally on the computer:
  the user will press 5, the server will open the file that was classified in option 3 and for every row in the file it will send the row number     and the classification string of the vector in that row to the client

In order to operate the program, we will first need to turn on the server so that it will be able to connect to a client using the port number. after that the client will connect to the server, and now the server will wait for a message from the client. after performing these opreations the client will input a string that should consist of three things : a number of double values that will represent a vector, a distance algorithm from one of the following - "MIN" - minkowski, "AUC" - euclidean, "MAN" - manhattan, "CAN" - canberra and "CHB" - chebyshev, and finally an integer that will be marked as 'K'.
after receiving the input, the client will make an initial check for the validity of the string, meaning checking if it contains all of the above values as listed. if the input is valid, the input will be sent to the server, otherwise the program will print an 'invalid input' message and wait for a new input from the user. the server will now receive the user input and split the string to three parts, a vector, distance algorithm and the 'k' value. 

The server will scan the file from the argument line, and take all the rows from the file and represent each row as an object that will consist of a vector with double values, a string to represent the type of the vector (such as flower type), and a double variable that will represent the distance of the current vector from the input vector according to the distance algorithm from the command line. the server will then create a master vector that will contain all the objects created from each row in the given file. next, the server will take the user input vector and calculate it's distance from each and every vector that is in the objects of the master vector. now we will have many distance values, one for every comparison. according to the 'k' values we will take the k nearest vectors (meaning the k smallest distances) and determine according to the string that each of these vectors represent, what is most likely the type of vector of the user input, meaning what type of flower does the vector of the user represent for instance. 

During the calculation the server will check for the validity of the values that were passed on from the client like - if the vector is in the right size, if a valid distance algorithm was chosen and if the k value is in a valid range.

after that the server will take the calssification determined from the calculation and sent it to the client, and the client will print it. the program runs in an endless loop meaning that after every classification it will always wait for a new user input and start the entire process between the server and the client all over again. in order for the client to disconnect from the server the user will need to input '-1' in this exact format.


HOW TO RUN THE PROGRAM :

In order to run the program you need to clone it to your PC and :

1. Use the cd command to access the cloned directory

2. Use the command "cd ex3_AP" in order to access the c++ file containing all the headers and classes

3. Now you need to compile the files using the "make" command.

4. To run the project enter "./server.out" and the enter the arguments listed above (file, port) accordingly.

5. enter "./client.out" and the enter the arguments listed above (ip, port) accordingly.

6. Now you can enter the input and run the program.

NOTES :

1. If the vectors from the user input and the vectors from the read file are not of the same length the program will print invalid input.

2. If the input consists of anything other than the vector values, distance algo and k value the program will print invalid input, such as:
  - if the input is empty
  - if there is more than one decimal period in a single number.
  - if the numbers in the vector part of the input consist of anything other than a decimal period or a digit such as letter, signs and so on.
  - if the distance algo in the input is not in one of the following formats : "MIN",  "AUC", "MAN", "CAN", "CHB"
  - if the k is not in a valid range meaning if it is a negative sign or larger than the master vector.
  - if the k is not an integer.
  - if the input is correct but is not in the right order.
  - if the amount of double values in the vector is different from the amount of values in each line in the read file.
  - if one of the vector values is greater than a double value.

3. The minkowski algorithm is the base to the manhattan and euclidean algorithms. In manhattan the p value is the constant 1 and in the euclidean the p value is the constant 2.

4. The p Value chosen for the minkowski algorithm is the constant 2.

5. In the canberra algorithm we covered the case where the division by zero could occur and made sure to avoid the calculation.

6. if the input of the server command line is invalid, the program will exit, such as :
  - if there are more or less that 3 arguments including the ./a.out
  - if the port number is not between 1025 and 65535
  - if the file route is incorrect(in that case it will also print "could not open file" before exiting)

7. if the input of the client command line is invalid, the program will exit, such as :
  - if there are more or less that 3 arguments including the ./a.out
  - if the port number is not between 1025 and 65535
  - if the ip number is not in the right range and format

8. The program will run in a endless loop until the user enters '-1' or by an initiated stop.
