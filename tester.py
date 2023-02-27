import random
import subprocess
import statistics
import sys
import time


def main(argv):
    # Define the number of tests to run for each number of arguments
    if int(argv[1]) > 0:
        num_runs = int(argv[1])
    else:
        num_runs = 10

    # Define the number of arguments to test
    num_tests = [3, 5, 100, 500]

    # Define the range of unsigned integer values to use as arguments
    min_val = -2147483648
    max_val = 2147483647

    # Initialize empty lists to store the number of lines for each test
    num_lines_3 = []
    num_lines_5 = []
    num_lines_100 = []
    num_lines_500 = []
    # initialize empty list to store execution time
    time_lines_3 = []
    time_lines_5 = []
    time_lines_100 = []
    time_lines_500 = []
    # Initialize variables to store the number of errors
    chk_errors = 0
    mem_errors = 0

    # Loop through the different number of tests to run
    for num in num_tests:
        # Run multiple tests for each number of arguments
        for i in range(num_runs):
            # Generate a list of unique random unsigned integers within the specified range
            args = random.sample(range(min_val, max_val), num)
            # Convert the arguments list to a string with spaces between each value
            args_str = [str(arg) for arg in args]
            #measure time of execution
            start = time.perf_counter()
            # Call the push_swap executable with the generated arguments
            result = subprocess.run(["./push_swap"] + args_str, stdout=subprocess.PIPE)
            end = time.perf_counter()
            execution_time = (end - start) * 1000
            # Get the number of lines returned by push_swap
            num_lines = result.stdout.count(b'\n')
            #Use the output of result and pass it to the checker executable
            checker = subprocess.run(["./checker"] + args_str, input=result.stdout, stdout=subprocess.PIPE)
            if checker.stdout != b'OK\n':
                print("Error: " + " ".join(args_str))
                chk_errors += 1
            #run program with valgrind and check for memory leaks
            valgrind = subprocess.run(["valgrind", "--leak-check=full", "--quiet", "./push_swap"] + args_str, stdout=subprocess.PIPE)
            #Check if valgrind found any memory leaks
            if valgrind.stdout.find(b"definitely lost:") != -1:
                print(valgrind.stdout)
                mem_errors += 1
            # Append the number of lines to the appropriate list based on the number of arguments
            if num == 3:
                num_lines_3.append(num_lines)
                time_lines_3.append(execution_time)
            elif num == 5:
                num_lines_5.append(num_lines)
                time_lines_5.append(execution_time)
            elif num == 100:
                num_lines_100.append(num_lines)
                time_lines_100.append(execution_time)
            elif num == 500:
                num_lines_500.append(num_lines)
                time_lines_500.append(execution_time)

    # Calculate the average number of lines per argument for each number of arguments tested
    avg_num_lines_3 = statistics.mean(num_lines_3)
    avg_time_lines_3 = statistics.mean(time_lines_3)
    max_num_lines_3 = max(num_lines_3)
    max_time_lines_3 = max(time_lines_3)
    avg_num_lines_5 = statistics.mean(num_lines_5)
    avg_time_lines_5 = statistics.mean(time_lines_5)
    max_num_lines_5 = max(num_lines_5)
    max_time_lines_5 = max(time_lines_5)
    avg_num_lines_100 = statistics.mean(num_lines_100)
    avg_time_lines_100 = statistics.mean(time_lines_100)
    max_num_lines_100 = max(num_lines_100)
    max_time_lines_100 = max(time_lines_100)
    avg_num_lines_500 = statistics.mean(num_lines_500)
    avg_time_lines_500 = statistics.mean(time_lines_500)
    max_num_lines_500 = max(num_lines_500)
    max_time_lines_500 = max(time_lines_500)

    # Print the results
    print(f"Number of runs: {num_runs}")
    print(f"Checker errors: {chk_errors}")
    print(f"Memory leaks: {mem_errors}")
    print(f"Average for 3 arguments: {avg_num_lines_3} Maximum: {max_num_lines_3} Execution time: {avg_time_lines_3:.03f}ms Maximum: {max_time_lines_3:.03f}ms")
    print(f"Average for 5 arguments: {avg_num_lines_5} Maximum: {max_num_lines_5} Execution time: {avg_time_lines_5:.03f}ms Maximum: {max_time_lines_5:.03f}ms")
    print(f"Average for 100 arguments: {avg_num_lines_100} Maximum: {max_num_lines_100} Execution time: {avg_time_lines_100:.03f}ms Maximum: {max_time_lines_100:.03f}ms")
    print(f"Average for 500 arguments: {avg_num_lines_500} Maximum: {max_num_lines_500} Execution time: {avg_time_lines_500:.03f}ms Maximum: {max_time_lines_500:.03f}ms")

if __name__ == "__main__":
    main(sys.argv)