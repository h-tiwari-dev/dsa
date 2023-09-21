#!/usr/bin/env python

import argparse
import os
from urllib.parse import urlparse


def main():
    parser = argparse.ArgumentParser(description="LeetCode Problem creator")
    parser.add_argument("problemURL", help="URL of the problem you are solving")
    parser.add_argument("--directory", help="Optional Argument. Which directory do you want to create the file")
    parser.add_argument("--testClass", help="Optional Argument. Problem class structure, copied from leetcode.")

    args = parser.parse_args()
    print(f"{args.problemURL}, {args.directory}")
    
    to_make_dir = args.directory
    
    if not to_make_dir:
        to_make_dir = os.getcwd()
        print(f"Current Directory:", to_make_dir)
    
    problemURL = args.problemURL
    parsed_url = urlparse(problemURL)
    fileName   = "SomeName"
    
    try:
        fileName = parsed_url.path.split("/")[parsed_url.path.split("/").index("problems") + 1]
    except Exception as e:
        print(f"Cannot read file name from {problemURL}: {e}")
        return

    file_path = os.path.join(to_make_dir, fileName)
    
    try:
        os.makedirs(file_path, exists_ok=True)
        print(f"Problem created successfully {fileName} at {to_make_dir}")
        tempTestClass = """
        class Solution {
            public:
                void testFunction(int temp) {
                }
        };
        """
        if args.testClass:
            tempTestClass = args.testClass
            
        with open(file_path, 'w') as file:
            file.write(f"""
            #include<iostream>
            #include<vector>
            #include<string>

            using namespace std;
            
            {tempTestClass}
            
            int main() \{
                Solution * sol = new Solution();
                return 0;
            \}
            """)
    except FileExistsError:
        print(f"Directory '{fileName}' already exists '{to_make_dir}'")
    except Exception as e:
        print(f"Error occured: {e}")

        
if __name__ == "__main__":
    main()