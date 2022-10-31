# Word-Chains
More information about the project can be found [here](https://www.ida.liu.se/~TDDI16/2021/labs/lab3.pdf).

## run (on linux)

Compile the follwing code to run the make file

$ g++ wordchain.cpp

$ time cat folder_of_words/your_word_file.txt folder_of_tests/your_test_file.txt | ./a.out

example 

$ time cat words/full.txt tests/full1.txt | ./a.out

$ time cat words/full.txt tests/full1.txt | valgrind ./a.out

valgrind is used to check the programs memory
## run (on windows)

Compiler the follwing code to run the vcxproj file

$ msbuild wordchain.vcxproj

$ wordchain.exe < your_word_and_test_file.txt
