This program was created during the spring 2022 semester at UIC for my Artificial Intelligence course (CS 411).
--------------------------------------------------------------------------------
Inputs must follow the form of that shown in input.txt, it will look like this.

|5|||4||6|||1|
||4|||1||||2|
||6|||||4|9|5|
||||||8||||
|||2||5|||||
|||||4||1|7|9|
||||||||3|4|
|||9||6|4||1|8|
|||4||8|2|||7|

Values must be placed between the bars with no spaces in between and must be given in the form of a ".txt" file for the program to function properly.

For example, a fully completed puzzle will look like this. The solution will be written to a text file of its own and save itself as "output.txt"

|5|9|7|4|2|6|3|8|1|
|3|4|8|5|1|9|7|6|2|
|2|6|1|8|3|7|4|9|5|
|4|1|3|7|9|8|5|2|6|
|9|7|2|6|5|1|8|4|3|
|6|8|5|2|4|3|1|7|9|
|8|2|6|1|7|5|9|3|4|
|7|5|9|3|6|4|2|1|8|
|1|3|4|9|8|2|6|5|7|



*** On line 203 in main is the line of code that decides which file to read from, by default, it is set to input.txt which is provided for example purposes ***

within this program there exists a total of 3 functions not including main. 
--------------------------------------------------------------------------------
First is the function conCheck, this function is responsible for doing a consistency check each time a value is trying to be placed in the backtrack search. It will start by searching all the relevant rows and columns that could violate the conistency check, after that it will check the relevant 3x3 sub-grid depending on the position we're trying to place a value in. Returning 0 to indicate to the backtrack search that some backtracking must be done, or that no solution can be found depending on when the check fails. Or, returning 1 if each check passes. This is the only function that is used for consistency checking and is called by the backtrack search function each time a value can potentially be placed in the sudoku board.
--------------------------------------------------------------------------------
Next is the function backTracker, this function is responsible for filling up the sudoku board with numbers and calling conCheck before each value is placed. First the function starts by looking for free spaces, should no free spaces be found (i.e no more 0's are left on the board) then this will mean we can conclude iteration for that call to backTracker and will begin recursive rewinding or simply exit if it is the last call to backTracker. After this aforementioned check for free spaces, a for loop will begin passing values starting from 1, to conCheck, where its potential placement will be checked. Should concheck return a 1, the value will be accepted and placed on the relevant board position. Immediately after another recursive call to backTracker is made with an if condition that should it also have an acceptable board placement (return 1), then the call that made the recursive call should also return 1. If this is not the case and the if condition that called backTracker recursively fails(return 0), that means an error has been made in the placement before that recursive call was made that resulted in the fail. So we need to erase the value that we thought was a valid placement (set the space back to zero), and continue recursive iteration to remedy the error with a new value.
--------------------------------------------------------------------------------
the final function used in this program is the printBoard() function. this function's sole purpose is to print the solution of the sudoku board to a text file called "output.txt". The function recieves the board at a given state before opening the output file and reading values off the completed board and placing a "|" between each board space to maintain the necessary format.
--------------------------------------------------------------------------------
main is where the board is declared as well as where the input file is parsed and placed into the 2d array board we declared. After this step is completed and the 2d array board is filled with the initial state from the input file, it will give the first call to backTracker, from which the solving will happen recursively. Should a solution be found and the last call to backTracker return 1, this means we have a solution to the problem and can call printBoard() to write the solution to a text file called "output.txt".
