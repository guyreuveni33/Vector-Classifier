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
  the user will press 4, the server will open the file that was classified in option 3 and for every row in the file it will send the row number     and the classification string of the vector in that row to the client, the client will receive and print all of the rows and their                 classifications to the user on the screen.
  
5. perform the exact same thing as option 4 but instead of printing it on the screen create a new file and print it in the file locally on the       computer:
  the user will press 5,the user will enter a filepath for a new file to be created locally, the client will check if the path is a valid path and if it is the client will create a new thread and perform the next oprations using the thread and not the main program. the server will open the file that was classified in option 3 and for every row in the file it will send the row number and the classification string of the vector in that row to the thread, the thread will then create an new file in the path that was given from the user and write all the rows and classifications in the file.

if the user enters 8 the client will end his side of the program and the server will continue running and wait for a new client interaction.
everytime a new client connects to the server the server will create a new thread and interact with the client using the new thread so that many clients can talk to the same server all at once.

HOW TO RUN THE PROGRAM :

In order to run the program you need to clone it to your PC and :

1. Use the cd command to access the cloned directory

2. Use the command "cd ex4_AP" in order to access the c++ file containing all the headers and classes

3. Now you need to compile the files using the "make" command.

4. To run the project enter "./server.out" and the enter the arguments listed above (file, port) accordingly.

5. enter "./client.out" and the enter the arguments listed above (ip, port) accordingly.

6. Now you can enter choose an option from the file and run the program.

NOTES :

in option 1:
  -if the path of the classified or unclassified file is invalid the client will print "invalid input" and print the menu again.

in option 2:
  - if the user presses 'enter' button then there will be no changes to the settings and the menu will pop up again.
  - if the user enters an invalid K, meaning not an integer value then the client will print invalid K and the menu will pop up again with no changes to the algo settings.
  - if the user enters an invalid distance metric, meaning not one of "MIN",  "AUC", "MAN", "CAN", "CHB" then the client will print invalid distance metric and the menu will pop up again with no changes to the algo settings.
  -  if both the K and distance metric are invalid the client will print an invalid error for both of them with no changes to the algo settings and the menu will pop up.

in option 3:
  - if the both files or one of the files were not uploaded in option 1 then the client will ask the user to upload files and return to the menu.
  - if the k is invalid meaning if it is a negative sign or larger than the master vector the program will tell the user the k is invalid and the menu will pop up again.

in option 4:
  - if the both files or one of the files were not uploaded in option 1 then the client will ask the user to upload files and return to the menu.
  - if the file was not classified in option 3 the client will ask the user to classify the data and open the menu.
  - after the printing ends the client will print done and wait for the user to press 'enter' and then return to the menu. the enter can come after any string input and the program will still return to the menu, for example 'fdswfs\n' is ok because it ended with '\n'.

in option 5:
  - if the both files or one of the files were not uploaded in option 1 then the client will ask the user to upload files and return to the menu.
  - if the file was not classified in option 3 the client will ask the user to classify the data and open the menu.

in the menu:
  - if the user enters an invalid option like a number other than 1-5 and 8 the client will print invalid input and will return to the menu.
  - if the user enters any string that is not one of the valid numbers in the menu the client will print invalid input and return to the menu.



1. If the vectors from the calssified file and the vectors from the unclassified are not of the same length the program will print invalid input.

2. if the vectors in the files consist of anything like the following the program will print invalid input:
  - if the vector is empty
  - if there is more than one decimal period in a single number.
  - if the numbers in the vector consist of anything other than a decimal period or a digit such as letter, signs and so on.
  - if the amount of double values in the unclassified file vector is different from the amount of values in each line in the classified file.
  - if one of the vector values is greater than a double value.

3. The minkowski algorithm is the base to the manhattan and euclidean algorithms. In manhattan the p value is the constant 1 and in the euclidean the p value is the constant 2.

4. The p Value chosen for the minkowski algorithm is the constant 2.

5. In the canberra algorithm we covered the case where the division by zero could occur and made sure to avoid the calculation.

6. if the input of the server command line is invalid, the program will exit, such as :
  - if there are more or less that 2 arguments including the ./a.out
  - if the port number is not between 1025 and 65535

7. if the input of the client command line is invalid, the program will exit, such as :
  - if there are more or less that 3 arguments including the ./a.out
  - if the port number is not between 1025 and 65535
  - if the ip number is not in the right range and format

8. The program will run in a endless loop until the user enters '-1' or by an initiated stop.
