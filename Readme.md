*Authors

Shouvik Sarkar(2017A7PS0194H), Prakhar Gupta(2017A7PS1441H), Rahul Pillai(2017A7PS0099H)

Assumption: Standard logic symbols and mathematical reasoning to be used

Input Method:-

1)Implication Elimination- Line 1 contains the (left>right) line number and Line 2 contains the left line number.

2)And Introduction- For (a^b) line 1 contains 'a' line number and line 2 contains 'b' line number.

3)Modus Tollens - Line 1 contains (a>b), line 2 contains ~b.


*Compilation dependencies:-

1)Part1.cpp requires Part1functions.cpp -> precedence.cpp

2)Part2.cpp requires Part2functions.cpp -> Part1functions.cpp -> precedence.cpp

*Limitations:-

1)Our proof checker for part 2 shall work for only 10000 lines of code.

2)Since the program was coded in CodeBlocks, usermade cpp files were included instead of header files as CodeBlocks couldn't access the header files.

3)Our code shall compile on C++ standards supporting the Standard Template Library.
