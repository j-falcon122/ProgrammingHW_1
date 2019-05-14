# ProgrammingHW_1
Homework for CMP 426 (Operating Systems)

 # Programming Assignment 1
 This is your last programming assignment for the course. As we have done with all programming assignment, this is a group work. The due date is May 14th by 11:59 pm. No late work will be accepted.How to submit.
 
 Share your GitHub repo link to your solution

 # Question 1.
 Write a program that implements the following disk-scheduling algorithms:
 1. FCFS
 2. SSTF
 3. SCAN
 4. C-SCAN
 5. LOOK
 6. C-LOOK

 Your program will service a disk with 5,000 cylinders numbered 0 to 4,999. The program will generate a random series of 1,000 cylinder requests and service them according to each of the algorithms listed above. The program will be passed the initial position of the disk head (as a parameter on the command line) and report the total amount of head movement required by each algorithm.

 # Question2.
 The Sleeping Teaching Assistant
 A university computer science department has a teaching assistant (TA) who helps undergraduate students with their programming assignments during regular office hours. The TA’s office is rather small and has room for only one desk with a chair and computer. There are three chairs in the hallway outside the office where students can sit and wait if the TA is currently helping another student. When there are no students who need help during office hours, theTA sits at the desk and takes a nap. If a student arrives during office hours and finds the TA sleeping, the student must awaken the TA to ask for help. If a student arrives and finds the TA currently helping another student, the student sits on one of the chairs in the hallway and waits. If no chairs are available, the student will come back at a later time.

 Implement a solution that coordinates the activities of the TA and the students. Details for this assignment are provided below.

Students and the TA
Using threads, begin by creating n students. Each will run as a separate thread. The TA will run as a separate thread as well. Student threads will alternate between programming for a period of time and seeking help from the TA. If the TA is available, they will obtain help. Otherwise, they will either sit in a chair in the hallway or, if no chairs are available, will resume programming and will seek help at a later time. If a student arrives and notices that the TA is sleeping, the student must notify the TA using a semaphore. When the TA finishes helping a student, the TA 
must check to see if there are students waiting for help in the hallway. If so, the TA must help each of these students in turn. If no students are present, the TA may return to napping.

Perhaps the best option for simulating students programming—as well as the TA providing help to a student—is to have the appropriate threads sleep for a random period of time.
