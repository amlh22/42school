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


