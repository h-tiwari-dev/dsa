#!/usr/bin/env python

import argparse
import os
from urllib.parse import urlparse
from pathlib import Path


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
        problemName = parsed_url.path.split("/")[parsed_url.path.split("/").index("problems") + 1] 
        fileName = problemName + "/" + problemName + ".cpp" 
    except Exception as e:
        print(f"Cannot read file name from {problemURL}: {e}")
        return

    file_path = os.path.join(to_make_dir, fileName)
    print(f"File Path: {file_path}")

    try:
        output_file = Path(file_path, exist_ok=True)
        tempTestClass = """
        class Solution {
            public:
                void testFunction(int temp) {
                }
        };
        """
        if args.testClass:
            tempTestClass = args.testClass
            
        output_file.parent.mkdir(exist_ok=True, parents=True)
        print(f"Problem created successfully {fileName} at {to_make_dir} {file_path}")
        output_file.write_text(f"""
            #include<iostream>
            #include<vector>
            #include<string>

            using namespace std;
            
            {tempTestClass}
            
            int main() {{
                Solution * sol = new Solution();
                return 0;
            }}
            """)
    except FileExistsError:
        print(f"Directory '{fileName}' already exists '{to_make_dir}'")
    except Exception as e:
        print(f"Error occured: {e}")

        
if __name__ == "__main__":
    main()
