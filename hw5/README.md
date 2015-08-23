+ To compile all programs, type "make" is terminal.

+ To run arraylist_test.cpp, type "./bin/hw5q4.exe" and program will run with no errors.

+ To run speed_test.cpp, type "./bin/hw5q5.exe" and program will run with no errors.

+ To read my explanation for the runtimes and the runtimes themselves, open hw5p5_times.txt.

+ To run hw5p7, type "./bin/hw5q7.exe expressions.txt variables.txt" (NOTE: unable to figure out an infinite loop issue.(Oddly, the program run in Visual Studio) Found the problem in gdb, which is for the first expression my "pos" variable is always less than "s.length()" so it never comes out of the while loop(pos < s.length()). The pos is 24 and s.length() is 25. I used gdb to "set variable pos = 25" and it was able to run the rest of the program no problem and produce the outputs. (WEIRD.....)  Also, I was unable to figure out where to put try catch blocks to catch the MALFORMATTED EXPRESSIONS. So program only runs with correct formatted boolean expressions, but and error is received when I expression has NOT'S (~) starting the expression (ie. ~~(14 & 0)) where the stack malfunctions and outputs that the "stack is empty" due to my throw in the stack.
