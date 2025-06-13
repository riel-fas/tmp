#!/bin/bash

echo "Testing minishell functionality..."

# Test 1: Simple command
echo -e "echo hello\nexit" | ./minishell > test1.out 2>&1
echo "Test 1 (echo hello):"
cat test1.out
echo "---"

# Test 2: ls command  
echo -e "ls\nexit" | ./minishell > test2.out 2>&1
echo "Test 2 (ls):"
cat test2.out
echo "---"

# Test 3: pwd command
echo -e "pwd\nexit" | ./minishell > test3.out 2>&1
echo "Test 3 (pwd):"
cat test3.out
echo "---"

# Test 4: env command
echo -e "env\nexit" | ./minishell > test4.out 2>&1
echo "Test 4 (env):"
head -5 test4.out
echo "---"

# Test 5: export command
echo -e "export TEST=123\necho \$TEST\nexit" | ./minishell > test5.out 2>&1
echo "Test 5 (export and variable):"
cat test5.out
echo "---"

# Clean up
rm -f test*.out

echo "Testing complete."
