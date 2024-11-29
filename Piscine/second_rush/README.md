## Second Rush - Skyscraper Puzzle

### Edge Constraint Rule:
For a N x N board:
- If clue = 1, adjacent cell will be N
- If clue = N, adjacent cells will be filled 1 → N in ascending order.

### Explanation of code:
#### `main.c`
- Function display_solution prints the puzzle solution
  - While loops iterates over each row `[i]`, column by column `[j]`
  - `temp` holds `ASCII` characters converted from the corresponding integer from the board
- `free_puzzle` frees dynamically allocated memory in the puzzle structure, each row of the board as well as the board and target arrays
- The arguments `ac` and `av` are passed into `input_validation` to check that they are valid inputs.
- `puzzle.board` allocates memory for an array of pointers to integer arrays (each row of the board).
- Loop iterates from `0` to `puzzle.n - 1`, allocating memory for each row of the board. Each row is an array of integers of size `puzzle.n`
- `puzzle.target` allocates an array of integers to store target constraints. The size is `puzzle.n * 4` because there are four constraints per puzzle (top, bottom, left, right)
- `fill_target(&puzzle, av[1])` uses the input string to set the target constraints in the puzzle board
- Then `solve_puzzle` is called, to try and solve the puzzle and display the solution if possible
- Finally `free_puzzle` is called to free all dynamically allocated memory and prevent memory leaks

#### `check_av.c`
- Function `is_doubles` checks that there are no repeated numbers for the current `i` in columns or rows
- `pos` converted to rows and columns using division and modulo
  - For example, if `puzzle->n` is 4 and `pos` is 9:
    -  `9 / 4 = 2` . Then `pos = 9` is in the 2nd row.
    - `9 % 4 = 1`. This means that `pos = 9` is in the 1st column within its row.
- Function `check_up_col` checks if placing `i` at `pos` will fulfil the top visibility constraints
  - If the row index is less than `puzzle->n - 1` (`pos` not in the last row), then there is no need to check the constraint for visibility from the top, because there aren’t enough rows above to validate the constraint
  - Place `i` in the board
  - Initialise `v_tower` to start counting visible towers from the top with the initial number `i` as the first visible tower.
  - Initialise `tallest` with the value in the top cell of the column where `pos` is located. This keeps track of the tallest tower as it checks down the column.
    - The loop iterates over each row (`j`) in the column where `pos` is located.
    - For each cell in this column, if the value is greater than `tallest`, it means this tower is visible from the top.
    - Update `tallest` to the current value if it is greater, and increment `v_tower`.
  - Then check if the number of visible towers matches the expected number from the target constraints
    - `puzzle->target[pos % puzzle->n]` provides the expected number of visible towers from the top for the column corresponding to pos.
    - If `v_tower` does not match, then i at pos is invalid and the board resets.  
- Other functions check down the column (if `pos` is in the last row, no need to check), left side of rows (ignore if `pos` is in the last column), right side of rows (ignore if `pos` is in the first column)

#### `puzzle.h`
- Begins with preprocessor directives
  - `#ifndef PUZZLE_H` checks if `PUZZLE_H` has not been defined.
  - `#define PUZZLE_H` defines `PUZZLE_H` if it hasn’t been defined yet.
- At the end of the file, `#endif` closes the conditional inclusion
- Struct used to define a set of variables of mixed type that are stored in a block of memory. Allows the different values to be accessed by a single pointer. 
  - `t_puzzle` used to wrap common variables to reduce number of arguments
  - `n` determines size of the board. Initialised as `n = 0`.
  - `int **board` is a pointer to a pointer
    - Represents a 2D array where each int value indicates a cell in the puzzle board, used to store the current state of the puzzle
    - `int *target` stores target constraints

#### `solve_puzzle.c`
- `is_valid` checks if placing the number `i` at position `pos` in the puzzle board is valid according to the puzzle's constraints
  - Calls functions from c`heck_col_row` 
- `solve_puzzle` tries to use backtracking method to solve the puzzle
  - If `pos = t * t` (`t` is board dimension), all positions are filled correctly and puzzle is solved
  - Iterates over all possible values (`1 to t`) to try placing in the current position pos.
    - For each value `i`, checks if placing `i` at `pos` is valid using `is_valid`.
    - If valid, sets `puzzle->board[pos / puzzle->n][pos % puzzle->n]` to `i` and recursively tries to solve the puzzle for the next position (`pos + 1`).
    - If the recursive call succeeds (`solve_puzzle(puzzle, pos + 1)`), it means the puzzle can be solved with this configuration
    - If placing `i` gives an unsolvable configuration, it resets the position to `0` and tries the next value.
   
#### `target.c`
- `target_isvalid` checks that puzzle constraints are valid
  - If `puzzle->target[i] == n`, the constraint for that particular direction (top, bottom, left, or right) is set to the maximum value `n`, so there are n visible towers.
  - The opposite constraint is determined based on the position `i`:
    - For `i < n` (top view constraints), opposite constraints are `i + n` (bottom view)
    - For `n to 2n` (bottom view constraints), opposite constraints are `i - n` (top view)
    - For `2n to 3n` (left view constraints), opposite constraints are `i + n` (right view)
    - For `3n to 4n` (right view constraints), opposite constraints are `i - n` (left view)
- `fill_target` fills target array in `t_puzzle` struct with values from input string
  - Only characters at even indices (`i % 2 == 0`) are processed to extract numbers (to ignore spaces).
  - `input[i] - '0'` converts the character digit to its integer value.
  - The integer value is stored in the target array at position `ctr`, then incremented to fill the next position in the target array


