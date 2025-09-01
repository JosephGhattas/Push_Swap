# Push_swap 🌀

A C program that sorts integers using two stacks and a limited set of operations, optimized for minimal moves.

#📖 Overview

Push_swap is an algorithmic challenge from the 42 curriculum, where the objective is to sort a stack of integers using only two stacks (a and b) and a limited set of operations (push, swap, rotate, reverse).

The twist? You’re not just asked to sort—you must find the most efficient sequence of operations.

This project is a deep dive into algorithm design, complexity analysis, and optimization under strict constraints.

# ⚙️ How It Works

My implementation is based on a custom approach I call the Turk Algorithm, designed specifically for Push_swap.

### 1. Small Sets (≤ 3–5 numbers)

Special-case hardcoded strategies (sort_three.c, etc.)

Minimal moves to guarantee sorted output

### 2. Large Sets

Turk Algorithm: a hybrid approach using:

Median detection → checks if a number belongs to the lower or upper half of the current set

Selective pushing → pushes elements from a to b depending on their relation to the median

Reintegration → elements are moved back from b to a in sorted order

Rotations and reverse-rotations are balanced to minimize unnecessary moves

### 3. Improvements Over Naive Chunk Sorting

Added a median-based adjustment to decide whether to rotate upwards or downwards before pushing

Optimized rotations to avoid “over-rotating” stacks

Clean handling of edge cases (duplicates, invalid input, empty args, etc.)

# 📊 Benchmarks
Input Size	Moves (avg)	Notes
3–5 numbers	1–9 moves	Optimal or near-optimal
100 numbers	543 – 636 moves	Well below 700 threshold
500 numbers	5233 – 5509 moves	Below 5500 threshold
1000 numbers	~14,700 moves	Efficient scaling
5000 numbers	~149,685 moves	Demonstrates scalability
# 🚀 Usage
### Clone the repo
git clone https://github.com/<your-username>/Push_Swap.git
cd Push_Swap

### Compile
make

### Run push_swap
./push_swap <list_of_integers>

### Example
./push_swap 3 2 1
### Output
sa
rra


The output is the sequence of operations that will sort the stack.
You can verify the correctness with the included checker:

ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
# Output: OK

# 🧠 Key Learnings

This project was more than just sorting—it was about designing efficient solutions under constraints:

Implemented and optimized custom algorithms in C

Explored algorithmic complexity and trade-offs between approaches

Strengthened memory management (no leaks, Norm-compliant code)

Improved debugging skills with custom test cases and automated checkers

Learned how small tweaks (like median-based decisions) can greatly reduce operation counts

#📂 Project Structure

srcs/ → Core sorting logic (init_a_to_b.c, init_b_to_a.c, sort.c, etc.)

ft_printf/ → Custom printf implementation used for formatted output

push_swap.h → Headers & shared structures

Makefile → Build rules (all, clean, fclean, re)

# 🏁 Conclusion

Push_swap was a great exercise in balancing algorithm design, optimization, and strict coding standards. The Turk Algorithm, with its median-based adjustments, consistently produces efficient results across small and large datasets, meeting the performance thresholds required for top evaluation scores.
