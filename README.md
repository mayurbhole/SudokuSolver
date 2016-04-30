# SudokuSolver
Sudoku Solver C Program
Problem Statement:
Sudoku is a puzzle game played on a grid that consists of n^2 × n^2
cells, each belonging to three groups: one of nine rows, one of
nine columns and one of nine boxes.
A Sudoku puzzle is a Sudoku grid that is partially filled, meaning that
a set of fixed cells, whose numerals are given (that cannot be
chosen/changed by the solver). The objective of the puzzle Solver is
to fill the Sudoku cells by assigning a numeral between 1 and n^2 to
each blank cell in such a way that each numeral is unique in each of
its three groups (row, column, box).
The objective of this assignment is to write a Sudoku Solver.
You can begin with implementing the following 2 rules.
Rule 1: If a cell can take only one number, assign that number to that
cell.
Rule 2: If there is a number which can go into only one cell, then
assign that number to that cell.

Data Structures & Functions Used:
1. Array: A 2D array of (n2 x n2) is used. Memory is allocated
dynamically using malloc.
2. can_place(): It checks whether the number can be placed at that
particular cell. Returns 1 if the number can be placed, else
returns 0.
3. filled_values(): It counts the number of filled cells in the
Sudoku and returns the count.
4. is_available(): It checks whether the cell is empty or filled. If it
is empty then returns 1, else returns 0.
5. rule1(): It checks for all the possible values which a cell can
have, if that particular cell can contain only one value then it
assigns that value to that cell.
6. rule2(): It checks if there is a number which can go into only
one cell, if true, then it assigns that number to that cell.
7. backtrack(): It recursively assigns the possible values to empty
cells until there is a situation when none of the values can go in
a particular cell.
8. print_sudoku(): It prints the Sudoku puzzle.


Approach:
1. Dynamically allocate a block of memory (n2 x n2) using a double
pointer.
2. Scan the input and store it into the dynamically allocated
memory.
3. Apply Rule 1 recursively until there is no cell which can have
only one possible value.
4. Rule 1: For each empty cell and for each value (1 to n2), call
can_place( ) function to check whether the value can go into that
particular cell. If the can_place( ) function returns 1, then
increment the counter and also store that value into a temporary
variable. If counter value is 1, then the cell can contain only one
value. This value is assigned to that particular cell using a
temporary variable.
5. Apply Rule 2 recursively on the output of Rule 1.
6. Rule 2: Choose a row and for each cell in that row, go through
each of the numbers that hasn’t already been placed. Call
can_place( ) function. If can_place( ) returns 1, then store the
location of column in a temporary variable and increment the
counter. After doing it for all cells in that row, check if the value
of counter is 1. If yes, then assign the value to that cell.
Similarly, do it for column and box.
7. If there are still empty cells even after applying the above rules,
then call Backtrack function.
8. backtrack( ): Call is_available( ), if it returns 0, then the Sudoku
is complete, else if it returns 1, then there are empty cells. Now
for every value, call can_place( ). If that value can be placed in
the cell, then assign it to that cell. Recursively make call to
backtrack( ). If at any point of time there is a cell which cannot
take any of the values, then roll back.
9. Finally print the Sudoku.



