import os

files = os.listdir(".")

# CHECK 1: Putting the username in a file
if "identity.txt" in files:
    with open("identity.txt") as identity:
        lines = identity.readlines()
        if len(lines) == 1:
            print(f'[PASS] Check 1. Username is {lines[0].strip()}.')
        else:
            print("[FAIL] Check 1, whoami command output")
else:
    print("[FAIL] Check 1, identity.txt not found")

# CHECK 2: Removing the "trash" file
if "trash" in files:
    print("[FAIL] Check 2, removing the trash file")
else:
    print("[PASS] Check 2")

# CHECK 3: Diffing the writeups
if "diff.log" in files:
    # we'll just compare the size of their diff file to ours, which should be sufficient
    if os.path.getsize("diff.log") == 4662306:
        print("[PASS] Check 3")
    else:
        print("[FAIL] Check 3, correct contents of diff.log")
else:
    print("[FAIL] Check 3, diff.log not found!")

# CHECK 4: Creating the `writeup` directory
# CHECK 5: Creating a file "differences.txt"
# CHECK 6: Writing a quick sentence in that file
if "writeup" in files:
    print("[PASS] Check 4")
    subfiles = os.listdir("./writeup")
    if "differences.txt" in subfiles:
        print("[PASS] Check 5")
        with open("writeup/differences.txt") as differences:
            if "teh" in differences.readline():
                print("[PASS] Check 6")
            else:
                print("[FAIL] Check 6, describing the differences between the two files")
    else:
        print("[FAIL] Check 5, differences.txt not found!")
        print("[FAIL] Check 6, this requires check 5!")
else:
    print("[FAIL] Check 4, writeup directory not found!")
    print("[FAIL] Check 5, this requires check 4!")
    print("[FAIL] Check 6, this requires check 5!")

# Check 7: gitlog file with a commit with message "Removed trash, identified differences"
if "gitlog" in files:
    with open("gitlog") as log:
        for line in log:
            if "Removed trash, identified differences" in line:
                print("[PASS] Check 7")
                break
        else:
            print("[FAIL] Check 7, correct commit message not found!")
else:
    print("[FAIL] Check 7, gitlog file not found!")
