#!/bin/bash

# Define the executable name
PROGRAM="./phonebook"

# Check if the executable exists before running
if [ ! -f "$PROGRAM" ]; then
    echo "Error: $PROGRAM not found. Please compile the project first using 'make'."
    exit 1
fi

echo "========================================="
echo "       Running My PhoneBook Tests        "
echo "========================================="

# Feed inputs into the program using a Here Document
$PROGRAM <<EOF
ADD
Arthur
Dent
Art
123456789
Forgot his towel
ADD
Ford
Prefect
Fordy
987654321
Is actually an alien
SEARCH
0
SEARCH
1
SEARCH
5
ADD
Three
Three
Three
333
333
ADD
Four
Four
Four
444
444
ADD
Five
Five
Five
555
555
ADD
Six
Six
Six
666
666
ADD
Seven
Seven
Seven
777
777
ADD
Eight
Eight
Eight
888
888
ADD
Nine (Should overwrite Arthur)
Nine
Nine
999
999
SEARCH
0
EXIT
EOF

echo "========================================="
echo "             Tests Complete              "
echo "========================================="