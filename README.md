# ECE 370 Closed Hash Table
The original code was created by me for my ECE 370 course. I plan to reveiw the code and make adjustments/improvements.
Assignment details are shown below:
----------------
Closed hash table
 
Assume that in the file a4.txt, there are no more than 50 state names are stored. Each entry is less than 15 chars. The data format is as follows:
 
NewYork
Connecticut
Michigan
Ohio
NEWJersey
 
Closed Hash: You are to construct a closed hash table of total capacity 60 (Bucket Table Size = 60).
Using linear rehash (one step increment) with the following hash function to insert each string inString from the input in a4.txtinto the hash table:
 
h(inString) = ((inString[0]*3)%50 + (inString[1]*5)%50 + (inString[2]*7)%50 ) % 60
 
The index last is for the last char of inString.
 
Record the cumulative number of steps (i.e., the number of hash table slots examined for available slot) for every string being entered into the table; this number must be printed immediately following each state name in the table. Print the resulted hash table on the screen: 4 states each line; if the bucket entry is NULL, print a number of spaces that are assigned for each state. Enumerate each line with the first entry of the four. Each entry should be printed as 15 chars. For a name less than 15 chars, use spaces to make up. Therefore, each state name will have 15 chars plus 2 positions (chars) for the number of rehash and one space for separation between names. The first two chars of each line are for the table entry starting 0 and incrementing 4 each of next lines.
 
You must use a4.txt as the input file name.
