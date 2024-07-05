import subprocess
import json
import unittest

RED_STR = "\x1b[31;20m"
GREEN_STR = "\x1b[32;20m"
RESET_COLOR_STR= "\x1b[0m"

json_file = open("unittest.json")

data = json.load(json_file)
test_cases = data['problem']["unittest"]["test_cases"]
# Closing file
json_file.close()

problem_id = data["problem"]["id"]
test_case_len =data["problem"]["unittest"]["test_case_len"]

def testCase():
    
    print(f"\nYou entered problem id = {GREEN_STR} {problem_id} {RESET_COLOR_STR}\nYou are viewing {GREEN_STR}{data["problem"]["name"]}{RESET_COLOR_STR} problem\nDifficult Level: {GREEN_STR}EASY{RESET_COLOR_STR}")
    print(f"There are {GREEN_STR}{test_case_len}{RESET_COLOR_STR} test case in this unittest\n")
    for index, test_case in enumerate(test_cases):
        
        # Reading test case's input. 
        # test_case["input"] contains the file's path. All content of input is in a .txt file   
        with open(test_case["input"],'r') as f:
            input_data = f.read()

        with open(test_case["output"], 'r') as f:
            output_expect = f.read()
        # print(input_data)
        # Chạy chương trình C++ với input từ test case
        result = subprocess.run(['main', data["problem"]["id"]] , input=input_data, capture_output=True, text=True)
        # Kiểm tra output thực tế với output mong muốn

        print(f"\nTestcase {index+1}: ", end='')
        if result.stdout != output_expect:
            print(RED_STR+"FAIL\n"+RESET_COLOR_STR)
        else:
            print(GREEN_STR+"OK\n"+RESET_COLOR_STR)
        
        print(f"\tInput: [\n{input_data}\n]\n")
        print(f"\tOutput expectation: [\n{output_expect}\n]\n")
        print(f"\tYour output: [\n{result.stdout}\n]\n")

class TestMainProgram(unittest.TestCase):

    def setUp(self):
        print("Compiling main.exe...")
        process = subprocess.run(["mingw32-make", "main"], shell=True, check = True)
        
    def test_output(self):
        testCase()
        # MergeTwoListsTest.testCase()

if __name__ == '__main__':

    # problem_id = int(input("Enter problem ID: "))
    my_test = TestMainProgram()
    my_test.setUp()
    my_test.test_output()

    # with open("./test_cases/tc_1_output_expect.txt") as f:
    #     line = f.read()
    
    # print(line)