NAME:    RAHUL VARMA
ROLL No: S20200010212

Every input should be taken from termianl:
for easy convinient the input is given at the end of the file.

Description of the implementation idea and running steps:

Time Tabling Problem using Graph Coloring (GC) in C program.

My Assumption for the Assignments are as follows:

1) Number of Courses N = 12
2) Time slots T = 36 
	12 * 3
	
3) Set of Room's R = 6
	Room : 101. 102. 103, 104, 105, 106

4) Set of room features (F):

	Room capacity = 60 
	Tables for lab
	AC
	Fan's
	Charging Port's
	Board
	Wifi
	Speakers (Audio)
	Marker's
	Projector
	Mic

5) Number of Students (M) = 180.
	

Bipartite Graph Edge Coloring Approach to Course Timetabling is used for the implementation.

Three Year Students:
UG1
UG2
UG3

Four Subjects for Each UG.

Hard and soft Constraints:

SOFT:
Number of Faculty (input) ie.. 12
Number of Courses (input) ie.. 12
Number of Students (input) ie.. 180
Class Rooms (input) ie.. 6
Batches
Minimum number of Classes per Course for week is credits: (input) ie.. 4.

Courses for UG2: ADSA, OOPS, OS, DBMS.
Courses for UG3: CC, DC, GTA, ML.
Courses for UG4: VAR, DIP, BI, DSD.

HARD:
IF FACULTY IS LESS THAN REQUIRED GIVES ERROR MESSAGE
IF CLASSES ARE LESS GIVES ERROR MESSAGE
FOR UG2 --> 101, 102.
FOR UG3 --> 103, 104.
FOR UG4 --> 105, 106.
Faculty Availability.
Less classes are preferable on last period of the class.


Hard:
	Room Capacity
	Tables for lab
	Charging ports
	Projector
	Speaker's
	Mic
	Marker's

Soft:
	AC's
	Fans
	Board
	Marker
	Wifi


These are my assumptions.

The given functions in hints section are implemented in the code.









SAMPLE INPUT:

5
5
3
12
6

101
102
103
104
105
106

Rahul
Varma
Sai
Ashok
Saketh
Darshak
Kasyap
Vinay
Sriram
Prabhash
odelusir
ragavendrasir

ug2

4
ADSA
4
0
OOP
4
1
OS
4
2
DBMS
4
3
101

ug3

4
CC
4
4
DC
4
5
GTA
4
6
ML
4
7
103

ug4

4
VAR
4
8
DIP
4
9
BI
4
10
DSD
4
11
105







	