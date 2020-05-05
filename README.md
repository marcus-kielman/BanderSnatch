# BanderSnatch
Final Project for CMPSC 473. Teaches operating system concepts through Text Based Game.

BanderSnatch is a text based terminal game set in a futuristic world where you
must work with General Buckingham and the United Nations to combat an evil
operating system known as the BOS. To help them defeat the BOS, you must
complete their mandatory training and combat the S-BOS before combating the BOS.

There are six levels of BanderSnatch. Each level involves different ways of
combating the S-BOS and by association the BOS.

Level One
  Player is given a series of questions to answer, and must type "a", "b", or
  "c" to answer the questions as illustrated below. Any incorrect answer will
  result in a loss in health.

    Bandersnatch Assessment Test

    Please answer the following questions below to assess your abilities as a Private
    =================================================================================


    1. What is the linux command to change directories?
        a. mv         b. cd        c. ps

    --> a
    Incorrect Answer. Health -100

    2. What is the linux command to list directories?
        a. ls         b. kill      c. top

    --> b
    Incorrect Answer. Health -100

    3. In gdb, what commands complete the following tasks
      i. break on a line of code
        a. b/break   b. n/next     c. p

    --> b
    Incorrect Answer. Health -100

      ii. runs the next line of code
        a. n/next    b. b/break    c. p

    --> a
    Correct Answer. Health +100

      iii. print a variable
        a. n/next    b. p          c. b/break

Level Two
  Player is given three Process IDs from the S-BOS that must be killed in order
  to stop the S-BOS from firing a death ray. Use the "ps" command to display
  thest processes. Use the "kill" command as illustrated below to kill a process
  ID, and use the "c" command to confirm that the correct process IDs have been
  killed. Player must to guess the correct PIDs in order to complete the level.
  Any additional combination of PIDs killed will result in a loss in health.


    Stage 1

    Player$ ps
    PID    TTY
    1175    S-BOS
    1358    S-BOS
    1268    S-BOS

    Stage 1

    Player$ kill 1175

    Stage 1

    Player$ c
    Writing processes in file
    Death ray opening and reading file
    Death Ray Stopped. +100 points

Level Three
  Player is given three threads from the S-BOS that are scheduled to be executed
  to trigger the death ray to fire. Player must use the burst command to change
  the burst time of the correct thread that will cause a deadlock in this
  schedule, and use the "c" command to confirm that the correct threads' burst
  times were manipulated. Player must manipulate the correct threads' burst
  times as illustrated below to complete the level. Any additional manipulation
  of threads' burst times other than the necessary one will result in a loss of
  health.

    Stage 1
    Opening Files...
    Creating Threads ...
    Listing Threads ...
    Threads  Burst Time
    Open       3
    Read       4
    Write      7
    Manipulate Burst Times to 11

    Player$ burst open 11
    Burst Time for open changed to 11

    Stage 1
    Opening Files...
    Creating Threads ...
    Listing Threads ...
    Threads  Burst Time
    Open       11
    Read       4
    Write      7
    Manipulate Burst Times to 11

    Player$ c
    Opening file to read ...
    Switching to read contents ...
    File not found, waiting for inputted file
    Deadlock has occurred. Process Terminated. +100 points

Level Four
  Player is given three objects with corresponding bytes allocated in memory
  used to fire a death ray. Player must use the "malloc" command to manipulate
  the number of bytes necessary to cause a segmentation fault in the BOS' death
  ray program as illustrated below, and use the "c" command to confirm the
  necessary object was manipulated. Player must manipulate the correct objects'
  as illustrated below to complete the level. Any additional manipulation
  of allocated memory other than the necessary object's will result in a loss of
  health.

    Stage 1
    Loading objects...
    Gathering objects and allocation sizes..
    Objects     Allocation
    location     11
    switch       14
    power        12

    Player$ malloc location 3
    Allocation value for location changed to 3

    Stage 1
    Loading objects...
    Gathering objects and allocation sizes..
    Objects     Allocation
    location     3
    switch       14
    power        12

    Player$ c
    Error: Incorrect Allocation. Interference Detected
    Death Ray Fired. -100 points

Level Five
  Player is using a man-in-the-middle attack to access secret data communicated
  between the BOS and S-BOS, and receives a incoming message header from the
  BOS with falsified data. Player must use the "ifconfig" command to receive the
  correct IP addresses of the BOS and S-BOS, and use the "open" command to open
  a received message as illustrated below. Player must find the correct messages
  to open. Any corrupted messages opened will result in a loss of points.

      Stage 1
    Incoming Message
    IP Address Source: 127.24.0.0
    IP Address Destination: 127.32.0.1
    Details: Password

    Player$ c

      Stage 1
    Incoming Message
    IP Address Source: 255.0.255.0
    IP Address Destination: 127.24.0.0
    Details: Password

    Player$ open
    Error: Interference Detected. -100 points

Level Six
  Player has gained access to the BOS' filesystem, and has received a password,
  file, and PID to kill within the BOS. Player must use the "ls" command to list
  the contents of the current directory, "cd" command to change to a directory,
  and "sudo" command to access the file, prompting for a password, so the "kill"
  command can be used to kill the necessary PID in the BOS to shut it down as
  illustrated below. Player must access the correct directories to navigate
  through the filesystem, and reach the necessary file. Any wrong change of
  directory, or sudo will result in a loss of health.

      Stage 1

    Player$ ls
    /bin
    /bash
    /etc

      Stage 1

    Player$ cd bin
    Entering /bin +100 points

    Player$ ls
    mastershutdown

    Player$ sudo mastershutdown
    Enter Password 114253

    Player$ kill 1534
    Player$ c

    Level 6 Completed. Badge #6 Earned


Controls:
  Main Gameplay Controls:
    q           -- exits main gameplay (i.e. overall game)
    c           -- continue main gameplay between levels
    help        -- request control description during gameplay
    status      -- request current user status during gameplay
    saveleader  -- save player info to leaderboard
    leaderboard -- display leaderboard
    leaderclear -- clear info on leaderboard

  Level Gameplay Controls:
    q        -- exits level gameplay
    c        -- continue gameplay during and between levels
    help     -- request control descriptions during gameplay and goal
    status   -- request current user status during gameplay
    ps       -- displays PIDs in level two
    kill     -- kill PIDs in level two and six
    burst    -- change burst times for threads in level three
    malloc   -- change amount of memory allocated for objects in level four
    ifconfig -- displays IP addresses for BOS and S-BOS in level five
    open     -- opens file in incoming message in level 5
    ls       -- list directories in level six
    cd       -- change to directories in level six
    sudo     -- access file in level six

To compile and run the game, type ./run.sh in terminal
To run the game, type ./BanderSnatch.exe in terminal
