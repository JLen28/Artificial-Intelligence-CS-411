// created by Joseph Lenaghan 2/11/22 during the spring semester at UIC for CS 411 || UIN:676805596 netId: jlenag2
#include <iostream>
#include <vector>
#include <string>
#include<stdio.h>
#include<stdlib.h>
#include <typeinfo>
#include <fstream>
using namespace std;
//**for the sake of ease I have represented the free spaces on the sudoku board as zero**
// this function handles consistency check, first we check the number of rows, then the number of columns.
// next we must check all the sub grids based on the given location to assure a placement is valid...
int conCheck(int board[9][9], int row,int col,int val){
    for(int j = 0; j < 9; j++){
      if(board[j][col] == val){return 0;} // duplicate value found, placement invalid, return 0...
    }
    for(int i = 0; i < 9; i++){
      if(board[row][i] == val){return 0;} // duplicate value found, placement invalid, return 0...
    }
    // the following if block is used for checking the 3x3 subgrids of the puzzle, the check is complete and accounts for
    // 
    if(col == 0 || col == 3 || col == 6){ // columns 0, 3, and 6 can be checked the same way...
      if(row == 0 || row == 3 || row == 6){ // rows 0,3, and 6 can be checked the same way...
        if(board[row][col] == val){return 0;} // check original location...
        if(board[row][col+1] == val){return 0;} // check column next to location...
        if(board[row][col+2] == val){return 0;} // check two columns over from location...
        if(board[row+1][col] == val){return 0;} // check row below original location...
        if(board[row+1][col+1] == val){return 0;} // check column next to location but one row down...
        if(board[row+1][col+2] == val){return 0;} // check two columns over from location but one row down...
        if(board[row+2][col] == val){return 0;} // check two rows below original location...
        if(board[row+2][col+1] == val){return 0;} // check column next to location but two rows down...
        if(board[row+2][col+2] == val){return 0;} //  check two columns over from location but two rows down...
        else{return 1;} // checks conclude and no issues found, placement is valid, return 1...
      }
      if(row == 1 || row == 4 || row == 7){ // rows 1,4, and 7 can be checked the same way...
        if(board[row][col] == val){return 0;} // check original location...
        if(board[row][col+1] == val){return 0;} // check column over from original location...
        if(board[row][col+2] == val){return 0;} // check two columns over from original location...
        if(board[row-1][col] == val){return 0;} // check the row above original location...
        if(board[row-1][col+1] == val){return 0;} // check the column over from original location but one row above...
        if(board[row-1][col+2] == val){return 0;} // check two columns over from original location but one row above...
        if(board[row+1][col] == val){return 0;} // check row below original location...
        if(board[row+1][col+1] == val){return 0;} // check one column over from original location but one row below...
        if(board[row+1][col+2] == val){return 0;} // check two columns over from original location but one row below...
        else{return 1;} // checks conclude and no issues found, placement is valid, return 1...
        
      }
      if(row == 2 || row == 5 || row == 8){ // rows 2,5, and 8 can be checked the same way...
        if(board[row][col] == val){return 0;} // check original location...
        if(board[row][col+1] == val){return 0;} // check one column over from original location...
        if(board[row][col+2] == val){return 0;} // check two columns over from original location
        if(board[row-1][col] == val){return 0;} // check row above original location...
        if(board[row-1][col+1] == val){return 0;} // check one column over from original location but one row above...
        if(board[row-1][col+2] == val){return 0;} // check two columns over from original locations but one row above...
        if(board[row-2][col] == val){return 0;} // check two rows above original location..
        if(board[row-2][col+1] == val){return 0;} // check one column over from original location but two rows above...
        if(board[row-2][col+2] == val){return 0;} // check two columns over from original location but two rows above...
        else{return 1;} // checks conclude and no issues found, placement is valid, return 1...
        
      }
    }
    if(col == 1 || col == 4 || col == 7){ // columns 1, 4, and 7 can be checked the same way...
      if(row == 0 || row == 3 || row == 6){ // rows 0,3, and 6 can be checked the same way...
        if(board[row][col] == val){return 0;} // check original location...
        if(board[row][col-1] == val){return 0;} // check the column behind the original location...
        if(board[row][col+1] == val){return 0;} // check the next column from the original location...
        if(board[row+1][col] == val){return 0;} // check the row above original location...
        if(board[row+1][col-1] == val){return 0;} // check the column behind the original location but one row below...
        if(board[row+1][col+1] == val){return 0;} // check the column over from original location but one row below...
        if(board[row+2][col] == val){return 0;} // check two rows below original location...
        if(board[row+2][col-1] == val){return 0;} // check column behind original location but two rows below...
        if(board[row+2][col+1] == val){return 0;} // check next column over from original location but two rows below...
        else{return 1;} // checks conclude and no issues found, placement is valid, return 1...
        
      }
      if(row == 1 || row == 4 || row ==7){ // rows 1,4, and 7 can be checked the same way...
        if(board[row][col] == val){return 0;} // check the original location..
        if(board[row][col-1] == val){return 0;} // check the column behind original location..
        if(board[row][col+1] == val){return 0;} // check the next column over from original location...
        if(board[row+1][col] == val){return 0;} // check the row below original location..
        if(board[row-1][col-1] == val){return 0;}// check the column behind original location but one row above...
        if(board[row-1][col+1] == val){return 0;} // check the next column over from original location but one row above..
        if(board[row+1][col] == val){return 0;} // check the row below original location...
        if(board[row+1][col-1] == val){return 0;} // check the column behind original location but one row below...
        if(board[row+1][col+1] == val){return 0;} // check the next column over from original location but one row below...
        else{return 1;} // checks conclude and no issues found, placement is valid, return 1...
        
      }
      if(row == 2 || row == 5 || row == 8){ // rows 2,5,8 can be checked the same way...
        if(board[row][col] == val){return 0;} // check the original location...
        if(board[row][col-1] == val){return 0;} // check the column behind the original location...
        if(board[row][col+1] == val){return 0;} // check the next column over from the original location...
        if(board[row-1][col] == val){return 0;} // check the row above the original location...
        if(board[row-1][col-1] == val){return 0;} // check the column behind original location but one row above..
        if(board[row-1][col+1] == val){return 0;} // check the next column over from original location but one row above...
        if(board[row-2][col] == val){return 0;} // check two rows above original location...
        if(board[row-2][col-1] == val){return 0;} // check column behind original location but two rows above...
        if(board[row-2][col+1] == val){return 0;} // check next column over from original location but two rows above...
        else{return 1;} // checks conclude and no issues found, placement is valid, return 1...
        
      }
      
    }
    if(col == 2 || col == 5 || col == 8){ // columns 2, 5, and 8 can be checked the same way...
      if(row == 0 || row == 3 || row == 6){ // rows 0,3, and 6 can be checked the same way...
        if(board[row][col] == val){return 0;} // check the original location...
        if(board[row][col-1] == val){return 0;} // check the column behind original location...
        if(board[row][col-2] == val){return 0;} // check two columns behind original location...
        if(board[row+1][col] == val){return 0;} // check one row below original location...
        if(board[row+1][col-1] == val){return 0;} // check one column behind original location but one row below...
        if(board[row+1][col-2] == val){return 0;} // check two columns behind original location but one row below...
        if(board[row+2][col] == val){return 0;} // check two rows below original location...
        if(board[row+2][col-1] == val){return 0;} // check one column behind original location but two rows below...
        if(board[row+2][col-2] == val){return 0;} // check two columns behind original location but two rows below...
        else{return 1;} // checks conclude and no issues found, placement is valid, return 1...
        
      }
      if(row == 1 || row == 4 || row ==7){ // rows 1,4, and 7 can be checked the same way...
        if(board[row][col] == val){return 0;} // check the original location...
        if(board[row][col-1] == val){return 0;} // check the column behind original location...
        if(board[row][col-2] == val){return 0;} // check two columns behind original location...
        if(board[row-1][col] == val){return 0;} // check the row above original location...
        if(board[row-1][col-1] == val){return 0;} // check the column behind the original location but one row above...
        if(board[row-1][col-2] == val){return 0;} // check two columns behind original location but one row above...
        if(board[row+1][col] == val){return 0;} // check one row below original location...
        if(board[row+1][col-1] == val){return 0;} // check one column behind original location but one row below...
        if(board[row+1][col-2] == val){return 0;} // check two columns behind original location but one row below...
        else{return 1;} // checks conclude and no issues found, placement is valid, return 1...
        
      }
      if(row == 2 || row == 5 || row == 8){ // rows 2,5,8 can be checked the same way...
        if(board[row][col] == val){return 0;} // check the original location...
        if(board[row][col-1] == val){return 0;} // check the column behind original location...
        if(board[row][col-2] == val){return 0;} // check two columns behind original location...
        if(board[row-1][col] == val){return 0;} // check row above original location..
        if(board[row-1][col-1] == val){return 0;} // check the column behind the original location but one row above...
        if(board[row-1][col-2] == val){return 0;} // check two columns behind the original location but one row above...
        if(board[row-2][col] == val){return 0;} // check two rows above original location...
        if(board[row-2][col-1] == val){return 0;} // check one column behind original location but two rows above...
        if(board[row-2][col-2] == val){return 0;} // check two columns behind original location but two rows above...
        else{return 1;} // checks conclude and no issues found, placement is valid, return 1...
        
      }
      
    }
 
 } // end of conCheck...

// This is the backtracking function responsible for traversing the board and assigning values to the board after the consistency check passes...
int backTracker(int board[9][9])
{
  int row = 20; // setting an impossible arbitrary value to serve as a flag for both column and row
  int col = 20; // should these values remain 20, this is indicative of no more free spaces (zeros) and means we're finished iterating
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      if(board[i][j] == 0){ // we've found an empty space, update row and column to the empty space and move on to value placement...
          row = i;  // storing the location of the free space...
          col = j;
          
      }
    }
  }
  if(row == 20 || col == 20){return 1;} // if we satisfy this if statement, it means there are no more free spaces available, conclude iteration...

  for (int val = 1; val < 10; val++) // time to start selecting values for placement on the board...
  {
         
      if (conCheck(board, row, col, val) == 1) // start the consistency check...
      {
          board[row][col] = val;
        if (backTracker(board) == 1){ // recursively call again to continue filling board spaces...
            return 1;
        }
          board[row][col] = 0; // if we get here, it means an incorrect value was addded to the board
      }                        // flip it back to zero so it will be picked up again by backTracker...
  }
  return 0; // got here, means something is placed incorrectly or no solution can be found, need to backtrack...
} // end of backTracker...

  // tiny function responsible for printing the board...
 void printBoard(int board[9][9]){
   ofstream myFile ("solution2.txt"); // opening a file to be written too....
  if(myFile.is_open()){ 
   for(int i = 0; i <9; i++){ // begin traversing the completed board...
   for(int j =0; j<9; j++){
      myFile << "|" << board[i][j]; // adding lines to match the desired output format...
      if(j == 8){myFile << "|";} // this line of code gives us the last bracket on the end of each row...
   }
     if(i < 8){ // this piece of code prevents an extra whitespace from being written at the bottom of output.txt...
         myFile << endl;
     }
  }
  }
   myFile.close(); // close the output file...
 }// end of printBoard...

int main() {
 // declaring relevant variables like the board, inputstream,string to store the input, and counters for storing the board in the 2d array...
 int board[9][9] ={{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}}; // board used for storing the sudoku puzzle...
 ifstream inputFile; // file stream to gather input's contents...
 string myStr = ""; // string that will serve to gather the input...
 int row = 0; // counter one for adding to the board...
 int col = 0; // counter two for adding to the board...
 inputFile.open("medium2.txt"); // ***CHANGE this to the relevant name of the text file...***
 while(!inputFile.eof()){ // reading from the input file...
  getline(inputFile,myStr);// gathering the input line by line...
    // here we take the input and organize it into a 2d array making DFS(backtrack search) more feasible...
   for(int i = 0; i < myStr.length() -1; i++){ // operate on the length of input
     if(col == 9){ // if we hit a column value of 9, that means its time for a new row, so reset column and update to the next row...
       col = 0;
       row++;
     }
     if(myStr[i] == '|'){ // this brack either preceeds an empty space or a value on the input, need to check for this first...
       if(myStr[i + 1] != '|'){ // if the value next to the bar isn't another bar its a value that needs to be captured,.
         int x = (int)myStr[i+1] - 48; // converting char to int...
         board[row][col] = x; // set the captured value to the relevant board position...
         col++; // increment to the next column...
       }
       else if(myStr[i + 1] == '|'){ // if there is another bracket immediately after a bracket, there is an empty space to be added..
         board[row][col] = 0; // updating the relevant board position to be an empty space...
         col++; // increment to the next column...
       }
       else{continue;} // niche case where we get a bracket at the end of a line, for example "|2", this assures there is no uncaptured behavior...
     }
   }
 }
  if (backTracker(board) == 1){ // once we get to the last recursive call of the search, should it evaluate to one, we have sucessfully solved the puzzle and can output the results to "output.txt"...
    printBoard(board); // call the output function to write "output.txt"
  }
  else{cout << "no solution can be found, exiting..." << endl; // if we got here, no solution can be resolved by the algorithm, exiting...
       return 1;
    }
}// end of main...
