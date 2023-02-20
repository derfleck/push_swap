import random
import subprocess
import statistics

# Define the number of tests to run for each number of arguments
num_runs = 100

# Define the number of arguments to test
num_tests = [3, 5, 100, 500]

# Define the range of unsigned integer values to use as arguments
min_val = 0
max_val = 1000000

# Initialize empty lists to store the number of lines for each test
num_lines_3 = []
num_lines_5 = []
num_lines_100 = []
num_lines_500 = []

# Loop through the different number of tests to run
for num in num_tests:
    # Run multiple tests for each number of arguments
    for i in range(num_runs):
        # Generate a list of unique random unsigned integers within the specified range
        args = random.sample(range(min_val, max_val), num)

        # Convert the arguments list to a string with spaces between each value
        args_str = [str(arg) for arg in args]
        # Call the push_swap executable with the generated arguments
        result = subprocess.run(["./push_swap"] + args_str, stdout=subprocess.PIPE)
        # Get the number of lines returned by push_swap
        num_lines = result.stdout.count(b'\n')
        # Append the number of lines to the appropriate list based on the number of arguments
        if num == 3:
            num_lines_3.append(num_lines)
        elif num == 5:
            num_lines_5.append(num_lines)
        elif num == 100:
            num_lines_100.append(num_lines)
        elif num == 500:
            num_lines_500.append(num_lines)

# Calculate the average number of lines per argument for each number of arguments tested
avg_num_lines_3 = statistics.mean(num_lines_3)
max_num_lines_3 = max(num_lines_3)
avg_num_lines_5 = statistics.mean(num_lines_5)
max_num_lines_5 = max(num_lines_5)
avg_num_lines_100 = statistics.mean(num_lines_100)
max_num_lines_100 = max(num_lines_100)
avg_num_lines_500 = statistics.mean(num_lines_500)
max_num_lines_500 = max(num_lines_500)

# Print the results
print(f"Average for 3 arguments: {avg_num_lines_3} Maximum: {max_num_lines_3}")
print(f"Average for 5 arguments: {avg_num_lines_5} Maximum: {max_num_lines_5}")
print(f"Average for 100 arguments: {avg_num_lines_100} Maximum: {max_num_lines_100}")
print(f"Average for 500 arguments: {avg_num_lines_500} Maximum: {max_num_lines_500}")
