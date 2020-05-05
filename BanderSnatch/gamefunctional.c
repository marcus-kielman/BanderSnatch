#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "levelchallenges.h"
#include "levelsgeneral.h"
#include "gamefunctional.h"

struct levelData ld;
struct examData ed;

//=================================================================================
//getMessage()
//Description: Generates IP addresses for BOS and S-BOS, and boolean corrupt flag
//Input: NULL
//Output: Displayed IP Addresses for Incoming message from BOS
void getMessage();
//=================================================================================
//saveLeader()
//Description: Write player's name and health to leaderboard
//Input: NULL
//Output: player's name and health written to leaderLog.txt
//        1 on error, 0 on success
int saveLeader();
//=================================================================================
//displayLeader()
//Description: display leaderboard to terminal
//Input: NULL
//Output: displayed leaderboard
void displayLeader();
//=================================================================================
//clearLeader()
//Description: clears all names and health from leaderboard
//Input: NULL
//Output: cleared leaderLog.txt
//        1 on error, 0 on success
int clearLeader();
//=================================================================================
//displayInstant()
//Description: Instantly displays file contents to terminal
//Input: character pointer containing file name
//Output: displayed file contents
//        1 on error, 0 on success
int displayInstant(char *charFile);
//=================================================================================
//displayByline()
//Description: sleeps for certain time before displaying file contents to terminal
//Input: *charFile -->character pointer containing file name,
//       speed     --> amount of time to sleep before displaying next line
//Output: slow display of file contents line by line
//        1 on error, 0 on success
int displayByline(char *charFile, int speed);
//=================================================================================
//displaySpeed()
//Description: sleeps for certain time before displaying file contents to terminal
//Input: *charFile -->character pointer containing file name,
//       speed     --> amount of time to sleep before displaying next line
//Output: slow displaying every two lines of file contents
//        1 on error, 0 on success
int displaySpeed(char *charFile, int speed);
//=================================================================================
//getControls()
//Description: Displays prompts for each level and stores controls from player in
//             level gameplay
//             Input controls: "q", "c", "help", "status", "ps", "kill", "burst"
//                             "malloc", "ifconfig", "open", "ls", "cd", "sudo"
//Input: inputted player controls
//Output: fget function to prompt input from player
int getControls();
//=================================================================================
//parseAndExecute()
//Description: parse player input controls from terminal during level gameplay
//             User input controls:
//                 q        -- exits level gameplay
//                 c        -- continue gameplay during and between levels
//                 help     -- request control descriptions during
//                             gameplay and goal
//                 status   -- request current user status during
//                             gameplay
//                 ps       -- displays PIDs in level two
//                 kill     -- kill PIDs in level two and six
//                 burst    -- change burst times for threads in level
//                             three
//                 malloc   -- change amount of memory allocated for
//                             objects in level four
//                 ifconfig -- displays IP addresses for BOS and S-BOS
//                             in level five
//                 open     -- opens file in incoming message in level 5
//                 ls       -- list directories in level six
//                 cd       -- change to directories in level six
//                 sudo     -- access file in level six
//Input: NULL
//Output: Displayed responses and execution of player controls.
//        1 when gameplay in progress, 0 when gameplay completed
int parseControls();
//=================================================================================
//introduction()
//Description: display introduction to game
//Input: NULL
//Output: displayed introduction to game
void introduction();
//=================================================================================
//exitGame()
//Description: display EXIT GAME sequence
//Input: NULL
//Output: displayed EXIT GAME sequence
void exitGame();
//=================================================================================
//gameover()
//Description: display GAME OVER sequence, and prompt if player would like to restart
//Input: NULL
//Output: displayed GAME OVER sequence, 1 on restart, and 0 on exit game
int gameover();

void getMessage(){
  int details = (rand() % (2 - 0 + 1)) + 0;
  ld.corrupt = (rand() % (1 - 0 + 1)) + 0;

  printf("Incoming Message\n");
  if(ld.corrupt == 0){
    printf("IP Address Source: %s\n", ld.ipBOS);
    printf("IP Address Destination: %s\n", ld.ipSBOS);
  }
  else{
    switch(details){
      case 0:
        printf("IP Address Source: 123.255.255.0\n");
        printf("IP Address Destination: %s\n", ld.ipSBOS);
        break;
      case 1:
        printf("IP Address Source: 255.0.255.0\n");
        printf("IP Address Destination: %s\n", ld.ipBOS);
        break;
      case 2:
        printf("IP Address Source: 123.255.255.0\n");
        printf("IP Address Destination: 255.0.255.0\n");
        break;
      default:
        break;
    }
  }
  switch(details){
    case 0:
      printf("Details: Battle Plans\n");
      break;
    case 1:
      printf("Details: Password\n");
      break;
    case 2:
      printf("Details: File Location\n");
      break;
    default:
    return;
  }
}
int saveLeader(){
  FILE *file;
  char c[] = "";
  char contents[255];

  if((file = fopen("text_files/leaderLog.txt","a")) == NULL){
      fprintf(stderr,"error opening text_files/leaderLog.txt\n");
      return 1;
  }
  fprintf(file, "%-12s %10d\n", pi.playerName, pi.playerHealth);
  fclose(file);
  return 0;
}
int clearLeader(){
  FILE *file;
  char c[] = "";
  char contents[255];

  if((file = fopen("text_files/leaderLog.txt","w+")) == NULL){
      fprintf(stderr,"error opening text_files/leaderLog.txt\n");
      return 1;
  }
  fprintf(file, "Name               Health\n");
  fclose(file);
  return 0;
}
void displayLeader(){
  displayInstant("text_files/leaderboards.txt");
  displayInstant("text_files/leaderLog.txt");
  return;
}
int displayInstant(char *charFile){
  FILE *file;
  char c[] = "";
  char contents[255];


  if((file = fopen(charFile,"r")) == NULL){
    fprintf(stderr,"error opening %s\n", charFile);
    return 1;
  }
  while (fgets(contents, 255, (FILE*)file) != NULL){
    printf("%s", contents);
  }
  fclose(file);
  return 0;
}
int displaySpeed(char *charFile, int speed){
  FILE *file;
  char c[] = "";
  char contents[255];
  int count = 0;


  if((file = fopen(charFile,"r")) == NULL){
    fprintf(stderr,"error opening %s\n", charFile);
    return 1;
  }
  while (fgets(contents, 255, (FILE*)file) != NULL){
    if (count < 2){
      printf("%s", contents);
      count += 1;
    }
    else{
      count = 0;
      sleep(speed);
      printf("%s", contents);
    }
  }
  fclose(file);
  return 0;
}
int displayByline(char *charFile, int speed){
  FILE *file;
  char c[] = "";
  char contents[255];
  int count = 0;


  if((file = fopen(charFile,"r")) == NULL){
    fprintf(stderr,"error opening %s\n", charFile);
    return 1;
  }
  while (fgets(contents, 255, (FILE*)file) != NULL){
    printf("%s", contents);
    sleep(speed);
  }
  fclose(file);
  return 0;
}
int getControls(){
  /*Prompt input*/
  printf("\nStage %d\n", ld.statusID + 1);
  /*display prompt for levels based on current pi.badge*/
  if(pi.badge == 3){
    printf("Opening Files...\n");
    printf("Creating Threads ...\n");
    sleep(1);
    printf("Listing Threads ...\n");
    printf("Threads  Burst Time\n");
    printf("  Open       %d\n", ld.burstOpen);
    printf("  Read       %d\n", ld.burstRead);
    printf("  Write      %d\n", ld.burstWrite);
    printf("Manipulate Burst Times to %d\n", ld.correctTime);
  }
  if(pi.badge == 4){
    printf("Loading objects...\n");
    printf("Gathering objects and allocation sizes..\n");
    printf("Objects     Allocation\n");
    printf("  location     %d\n", ld.location);
    printf("  switch       %d\n", ld.raySwitch);
    printf("  power        %d\n", ld.power);
  }
  if(pi.badge == 5){
    getMessage();
  }
  printf("\n%s$ ", pi.playerName);
  return fgets(input, sizeof(input), stdin) != NULL;
}
int parseControls(){
  char *verb = strtok(input, " \n");
  char *noun = strtok(NULL, " \n");

  if (verb != NULL){
    /*execute q command in level gameplay*/
    if(strncmp(verb, "q", 1) == 0){
      if(gameover() == 1){
        pi.playerHealth = 500;
        ld.statusID = 0;
        return 1;
      }
      pi.playerStatus = 0;
      return 0;
    }
    /*execute help command in level gameplay based on current pi.badge*/
    else if (strncmp(verb, "help", 4) == 0){
      printf("Help Command Actions: q, status\n");
      printf("c --> continues gameplay (allow PIDs to be written in file to death ray), q --> exit game, status --> current health and status in game\n");
      if(pi.badge == 2){
        printf("ps --> displays PIDS of different processes, kill --> kills specific process at a given PID (e.g. kill 1935)\n");
      }
      if(pi.badge == 3){
        printf("burst --> manipulates burst time of a given thread (e.g. burst open 11 changes burst time of open thread to 11\n)");
        printf("Goal: manipulate the burst time of the correct file");
      }
      else if (pi.badge == 4){
        printf("malloc --> manipulates the size of allocated space for objects (e.g. malloc location 1 changes memory allocated for location to 1 byte.\n");
        printf("Goal: manipulate the allocation size of the correct objects to the right sizes\n");
        printf("Hint: correct allocation size is a number between [1-3]\n");
      }
      else if (pi.badge == 5){
        printf("ifconfig --> shows the ip addresses for the S-BOS and BOS\n");
        printf("open -->opens incoming message from BOS\n");
        printf("Goal: verify incoming messages to receive necessary information to shut down the BOS\n");
      }
      else if (pi.badge == 6){
        printf("kill --> kills specific process at a given PID (e.g. kill 1935)\n");
        printf("ls -->lists files in directory, cd --> changes to certain directory\n");
        printf("sudo --> gives access to unauthorized files and directory (e.g. sudo file_name)\n");
        printf("Goal: Find the correct directory to kill PID %d. Given Password is %d\n", ld.killPID, ld.password);
      }
    }
    /*execute status command in level gameplay*/
    else if (strncmp(verb, "status", 4) == 0){
      displayInstant("text_files/general.txt");
      printf("Greetings %sThe information below shows your current health, and the latest badge received.\n", pi.playerName);
      printf("You must achieve badge %d to get to the next level\n", pi.badge + 1);
      printf("Health = %d\n", pi.playerHealth);
      printf("Badge = %d\n", pi.badge);
    }
    /*execute c command in level gameplay*/
    else if (strcmp(verb, "c") == 0){
      /*execute c command in level 2*/
      if(pi.badge == 2){
        switch(ld.statusID){
          case 0:
            if (ld.fire == 0){
              printf("Writing processes in file\n");
              sleep(1);
              printf("Death ray opening and reading file\n");
              sleep(1);
              printf("Death Ray Stopped. +100 points\n");
              pi.playerHealth += 100;
              ld.statusID += 1;
            }
            if(ld.death == 0){
              printf("Wrong PID Killed. -100 points\n");
              pi.playerHealth -= 100;
              ld.statusID = 0;
            }
            if(ld.ray == 0){
              printf("Wrong PID Killed. -100 points\n");
              pi.playerHealth -= 100;
              ld.statusID = 0;
            }
            if (ld.fire != 0){
              printf("Death Ray Fired. -100 points\n");
              pi.playerHealth -= 100;
              ld.statusID = 0;
            }
            /*Check if playerHealth <= 0 to run game over sequence for stage 1*/
            if (pi.playerHealth <= 0){
              if(gameover() == 1){
                pi.playerHealth = 500;
                ld.statusID = 0;
                ld.fire = (rand() % (2000 - 1000 + 1)) + 1000;
                ld.death = (rand() % (2000 - 1000 + 1)) + 1000;
                ld.ray = (rand() % (2000 - 1000 + 1)) + 1000;
                return 1;
              }
              pi.playerStatus = 0;
              return 0;
            }
            break;
          case 1:
            if (ld.fire == 0 && ld.death == 0){
              printf("Writing processes in file\n");
              sleep(1);
              printf("Death ray opening and reading file\n");
              sleep(1);
              printf("Death Ray Stopped. +100 points\n");
              pi.playerHealth += 100;
              ld.statusID += 1;
            }
            if(ld.death == 0 && ld.fire != 0){
              printf("Wrong PID Killed. -100 points\n");
              pi.playerHealth -= 100;
              ld.statusID = 1;
            }
            if(ld.ray == 0){
              printf("Wrong PID Killed. -100 points\n");
              pi.playerHealth -= 100;
              ld.statusID = 1;
            }
            if (ld.fire != 0 && ld.death != 0){
              printf("Death Ray Fired. -100 points\n");
              pi.playerHealth -= 100;
              ld.statusID = 1;
            }
            /*Check if playerHealth <= 0 to run game over sequence for stage 2*/
            if (pi.playerHealth <= 0){
              if(gameover() == 1){
                pi.playerHealth = 500;
                ld.statusID = 0;
                ld.fire = (rand() % (2000 - 1000 + 1)) + 1000;
                ld.death = (rand() % (2000 - 1000 + 1)) + 1000;
                ld.ray = (rand() % (2000 - 1000 + 1)) + 1000;
                return 1;
              }
              pi.playerStatus = 0;
              return 0;
            }
            break;
          case 2:
            if (ld.fire == 0 && ld.death == 0 && ld.ray == 0){
              printf("Writing processes in file\n");
              sleep(1);
              printf("Death ray opening and reading file\n");
              sleep(1);
              printf("Death Ray Stopped. +100 points\n");
              pi.playerHealth += 100;
              ld.statusID += 1;
              return 0;
            }
            if(ld.death == 0 && ld.fire != 0 && ld.ray != 0){
              printf("Wrong PID Killed. -100 points\n");
              pi.playerHealth -= 100;
              ld.statusID = 2;
            }
            if(ld.ray == 0 && ld.death != 0 && ld.fire != 0){
              printf("Wrong PID Killed. -100 points\n");
              pi.playerHealth -= 100;
              ld.statusID = 2;
            }
            if (ld.fire != 0 && ld.death != 0 && ld.ray != 0){
              printf("Death Ray Fired. -100 points\n");
              pi.playerHealth -= 100;
              ld.statusID = 2;
            }
            /*Check if playerHealth <= 0 to run game over sequence for stage 3*/
            if (pi.playerHealth <= 0){
              if(gameover() == 1){
                pi.playerHealth = 500;
                ld.statusID = 0;
                ld.fire = (rand() % (2000 - 1000 + 1)) + 1000;
                ld.death = (rand() % (2000 - 1000 + 1)) + 1000;
                ld.ray = (rand() % (2000 - 1000 + 1)) + 1000;
                return 1;
              }
              pi.playerStatus = 0;
              return 0;
            }
            break;
          default:
          return 0;
        }
        ld.fire = (rand() % (2000 - 1000 + 1)) + 1000;
        ld.death = (rand() % (2000 - 1000 + 1)) + 1000;
        ld.ray = (rand() % (2000 - 1000 + 1)) + 1000;
      }
      /*execute c command in level 3*/
      else if(pi.badge == 3){
        switch(ld.statusID){
          case 0:
            if (ld.burstOpen == ld.correctTime){
              printf("Opening file to read ...\n");
              sleep(1);
              printf("Switching to read contents ...\n");
              sleep(1);
              printf("File not found, waiting for inputted file\n");
              sleep(1);
              printf("Deadlock has occurred. Process Terminated. +100 points\n");
              sleep(1);
              pi.playerHealth += 100;
              ld.statusID += 1;
              ld.correctTime = (rand() % (15 - 10 + 1)) + 10;
            }
            else{
              printf("Incorrect burst time or file modified\n");
              printf("Death Ray Fired. -100 points\n");
              pi.playerHealth -= 100;
            }
            /*Check if playerHealth <= 0 to run game over sequence for stage 1*/
            if (pi.playerHealth <= 0){
              if(gameover() == 1){
                pi.playerHealth = 500;
                ld.statusID = 0;
                ld.burstOpen = (rand() % (8 - 3 + 1)) + 3;
                ld.burstRead = (rand() % (8 - 3 + 1)) + 3;
                ld.burstWrite = (rand() % (8 - 3 + 1)) + 3;
                return 1;
              }
              pi.playerStatus = 0;
              return 0;
            }
            break;
          case 1:
            if (ld.burstOpen == ld.correctTime && ld.burstRead == ld.correctTime){
              printf("Opening file to read ...\n");
              sleep(1);
              printf("Reading contents in file...\n");
              sleep(1);
              printf("Switching to write confim message in file\n");
              printf("File not read. Waiting for file to complete reading\n");
              sleep(1);
              printf("Deadlock has occurred. Process Terminated. +100 points\n");
              sleep(1);
              pi.playerHealth += 100;
              ld.statusID += 1;
              ld.correctTime = (rand() % (15 - 10 + 1)) + 10;
            }
            else{
              printf("Incorrect burst time or file modified\n");
              printf("Death Ray Fired. -100 points\n");
              pi.playerHealth -= 100;
            }
            /*Check if playerHealth <= 0 to run game over sequence for stage 2*/
            if (pi.playerHealth <= 0){
              if(gameover() == 1){
                pi.playerHealth = 500;
                ld.statusID = 0;
                ld.burstOpen = (rand() % (8 - 3 + 1)) + 3;
                ld.burstRead = (rand() % (8 - 3 + 1)) + 3;
                ld.burstWrite = (rand() % (8 - 3 + 1)) + 3;
                return 1;
              }
              pi.playerStatus = 0;
              return 0;
            }
            break;
          case 2:
            if (ld.burstOpen == ld.correctTime && ld.burstWrite == ld.correctTime){
              printf("Opening file to write into ...\n");
              sleep(1);
              printf("Reading contents in file ...\n");
              sleep(1);
              printf("Writing confirmation message in file\n");
              sleep(1);
              printf("Switching to read file\n");
              sleep(1);
              printf("File overwritten, waiting for message to finish writing\n");
              printf("Process Deadlocked. +100 points\n");
              sleep(1);
              pi.playerHealth += 100;
              return 0;
            }
            else{
              printf("Incorrect burst time or file modified\n");
              printf("Death Ray Fired. -100 points\n");
              pi.playerHealth -= 100;
            }
            /*Check if playerHealth <= 0 to run game over sequence for stage 3*/
            if (pi.playerHealth <= 0){
              if(gameover() == 1){
                pi.playerHealth = 500;
                ld.statusID = 0;
                ld.burstOpen = (rand() % (8 - 3 + 1)) + 3;
                ld.burstRead = (rand() % (8 - 3 + 1)) + 3;
                ld.burstWrite = (rand() % (8 - 3 + 1)) + 3;
                return 1;
              }
              pi.playerStatus = 0;
              return 0;
            }
            break;
          default:
            return 0;
        }
        ld.burstOpen = (rand() % (8 - 3 + 1)) + 3;
        ld.burstRead = (rand() % (8 - 3 + 1)) + 3;
        ld.burstWrite = (rand() % (8 - 3 + 1)) + 3;
      }
      /*execute c command in level 4*/
      else if(pi.badge == 4){
        switch(ld.statusID){
          case 0:
            if(ld.location == ld.correctAlloc){
              printf("Attempting to store location to fire\n");
              sleep(1);
              printf("Segmentation Fault. %d bytes allocated. +100 points\n", ld.correctAlloc);
              pi.playerHealth += 100;
              ld.statusID += 1;
              ld.correctAlloc = (rand() % (3 - 1 + 1)) + 1;
            }
            else{
              printf("Error: Incorrect Allocation. Interference Detected\n");
              printf("Death Ray Fired. -100 points\n");
              pi.playerHealth -= 100;
            }
            /*Check if playerHealth <= 0 to run game over sequence for stage 1*/
            if (pi.playerHealth <= 0){
              if(gameover() == 1){
                pi.playerHealth = 500;
                ld.statusID = 0;
                ld.location = (rand() % (16 - 8 + 1)) + 8;
                ld.raySwitch = (rand() % (16 - 8 + 1)) + 8;
                ld.power = (rand() % (16 - 8 + 1)) + 8;
                return 1;
              }
              pi.playerStatus = 0;
              return 0;
            }
            break;
          case 1:
            if(ld.raySwitch == ld.correctAlloc){
              printf("Attempting to store location to fire\n");
              sleep(1);
              printf("Segmentation Fault. %d bytes allocated. +100 points\n", ld.correctAlloc);
              pi.playerHealth += 100;
              ld.statusID += 1;
              ld.correctAlloc = (rand() % (3 - 1 + 1)) + 1;
            }
            else{
              printf("Error: Incorrect Allocation. Interference Detected\n");
              printf("Death Ray Fired. -100 points\n");
              pi.playerHealth -= 100;
            }
            /*Check if playerHealth <= 0 to run game over sequence for stage 2*/
            if (pi.playerHealth <= 0){
              if(gameover() == 1){
                pi.playerHealth = 500;
                ld.statusID = 0;
                ld.location = (rand() % (16 - 8 + 1)) + 8;
                ld.raySwitch = (rand() % (16 - 8 + 1)) + 8;
                ld.power = (rand() % (16 - 8 + 1)) + 8;
                return 1;
              }
              pi.playerStatus = 0;
              return 0;
            }
            break;
          case 2:
            if(ld.power == ld.correctAlloc){
              printf("Attempting to store location to fire\n");
              sleep(1);
              printf("Segmentation Fault. %d bytes allocated. +100 points\n", ld.correctAlloc);
              pi.playerHealth += 100;
              return 0;
            }
            else{
              printf("Error: Incorrect Allocation. Interference Detected\n");
              printf("Death Ray Fired. -100 points\n");
              pi.playerHealth -= 100;
            }
            /*Check if playerHealth <= 0 to run game over sequence for stage 3*/
            if (pi.playerHealth <= 0){
              if(gameover() == 1){
                pi.playerHealth = 500;
                ld.statusID = 0;
                ld.location = (rand() % (16 - 8 + 1)) + 8;
                ld.raySwitch = (rand() % (16 - 8 + 1)) + 8;
                ld.power = (rand() % (16 - 8 + 1)) + 8;
                return 1;
              }
              pi.playerStatus = 0;
              return 0;
            }
            break;
          default:
            return 0;
        }
        ld.location = (rand() % (16 - 8 + 1)) + 8;
        ld.raySwitch = (rand() % (16 - 8 + 1)) + 8;
        ld.power = (rand() % (16 - 8 + 1)) + 8;
      }
      /*execute c command in level 6*/
      else if(pi.badge == 6){
        if(ld.killPID == 0){
          printf("BOS SHUTDOWN SEQUENCE ACTIVATED. +100 points\n");
          return 0;
        }
        else{
          printf("Error: Access Denied. Interference Detected. -100 points\n");
          pi.playerHealth -= 100;
          /*Check if playerHealth <= 0 to run game over sequence for kill command*/
          if (pi.playerHealth <= 0){
            if(gameover() == 1){
              pi.playerHealth = 500;
              ld.statusID = 0;
              return 1;
            }
            pi.playerStatus = 0;
            return 0;
          }
        }
      }
    }
    /*execute ps command*/
    else if (strncmp(verb, "ps", 2) == 0){
      printf(" PID    TTY\n");
      printf("%d    S-BOS\n", ld.fire);
      printf("%d    S-BOS\n", ld.death);
      printf("%d    S-BOS\n", ld.ray);
    }
    /*parse PID and execute kill command*/
    else if (strncmp(verb, "kill", 4) == 0){
      int pid = atoi(noun);

      if(pid == ld.fire){
        ld.fire = 0;
      }
      else if(pid == ld.death){
        ld.death = 0;
      }
      else if (pid == ld.ray){
        ld.ray = 0;
      }
      else if (pid == ld.killPID){
        ld.killPID = 0;
      }
      else{
        printf("Invalid PID\n");
      }
    }
    /*parse thread to change burst time to and execute burst command*/
    else if (strncmp(verb, "burst", 5) == 0){
      char *number;
      if((number = strtok(NULL, " \n")) == NULL){
        printf("Please input a valid burst time\n");
        return 1;
      }
      int burstTime = atoi(number);

      if(strncmp(noun, "open", 4) == 0){
        ld.burstOpen = burstTime;
        printf("Burst Time for open changed to %d\n", ld.burstOpen);
      }
      else if(strncmp(noun, "read", 4) == 0){
        ld.burstRead = burstTime;
        printf("Burst Time for read changed to %d\n", ld.burstRead);
      }
      else if(strncmp(noun, "write", 5) == 0){
        ld.burstWrite = burstTime;
        printf("Burst Time for write changed to %d\n", ld.burstWrite);
      }
      else{
        printf("Unknown change\n");
      }
    }
    /*parse object and execute malloc*/
    else if (strncmp(verb, "malloc", 6) == 0){
      char *number;
      if((number = strtok(NULL, " \n")) == NULL){
        printf("Please input a valid burst time\n");
        return 1;
      }
      int allocValue = atoi(number);

      if(strncmp(noun, "location", 8) == 0){
        ld.location = allocValue;
        printf("Allocation value for location changed to %d\n", ld.location);
      }
      else if(strncmp(noun, "switch", 6) == 0){
        ld.raySwitch = allocValue;
        printf("Allocation value for switch changed to %d\n", ld.raySwitch);
      }
      else if(strncmp(noun, "power", 5) == 0){
        ld.power = allocValue;
        printf("Allocation value for power changed to %d\n", ld.power);
      }
      else{
        printf("Unknown change\n");
      }
    }
    /*execute ifconfig command*/
    else if (strncmp(verb, "ifconfig", 8) == 0){
      printf("BOS: %s\n", ld.ipBOS);
      printf("S-BOS: %s\n", ld.ipSBOS);
    }
    /*execute open command based on stage player is on*/
    else if (strncmp(verb, "open", 4) == 0){
      if (pi.badge == 5){
        switch(ld.statusID){
          case 0:
            if (ld.corrupt == 1){
              printf("Error: Interference Detected. -100 points\n");
              pi.playerHealth -= 100;
            }
            else{
              printf("kill PID %d. +100 points\n", ld.killPID);
              pi.playerHealth += 100;
              ld.statusID += 1;
            }
            /*Check if playerHealth <= 0 to run game over sequence for stage 1*/
            if (pi.playerHealth <= 0){
              if(gameover() == 1){
                pi.playerHealth = 500;
                ld.statusID = 0;
                return 1;
              }
              pi.playerStatus = 0;
              return 0;
            }
            break;
          case 1:
            /*Check if displayed file is corrupted*/
            if (ld.corrupt == 1){
              printf("Error: Interference Detected. -100 points\n");
              pi.playerHealth -= 100;
            }
            else{
              printf("Filename: file_shutdown +100 points\n");
              pi.playerHealth += 100;
              ld.statusID += 1;
            }
            /*Check if playerHealth <= 0 to run game over sequence for stage 2*/
            if (pi.playerHealth <= 0){
              if(gameover() == 1){
                pi.playerHealth = 500;
                ld.statusID = 0;
                return 1;
              }
              pi.playerStatus = 0;
              return 0;
            }
            break;
          case 2:
            /*Check if displayed file is corrupted*/
            if (ld.corrupt == 1){
              printf("Error: Interference Detected. -100 points\n");
              pi.playerHealth -= 100;
            }
            else{
              printf("file password %d. +100 points\n", ld.password);
              pi.playerHealth += 100;
              ld.statusID += 1;
              return 0;
            }
            /*Check if playerHealth <= 0 to run game over sequence for third stage*/
            if (pi.playerHealth <= 0){
              if(gameover() == 1){
                pi.playerHealth = 500;
                ld.statusID = 0;
                return 1;
              }
              pi.playerStatus = 0;
              return 0;
            }
            break;
          default:
            return 0;
        }
      }
      else{
        printf("Must receive badge #4 to unlock\n");
      }
    }
    /*Execute ls command based on current stage player is on*/
    else if (strncmp(verb, "ls", 2) == 0){
      if(pi.badge == 6){
        switch(ld.statusID){
          case 0:
          printf("/bin\n");
          printf("/bash\n");
          printf("/etc\n");
          break;
          case 1:
          printf("/Battlezone\n");
          printf("/Shutdown\n");
          printf("/Network_directory\n");
          break;
          case 2:
          printf("file_shutdown\n");
          break;
          default:
          break;
        }
      }
      else{
        printf("Must receive Badge #5 to unlock\n");
      }
    }
    /*Parse what to cd, and execute*/
    else if (strcmp(verb, "cd") == 0){
      if (pi.badge == 6){
        /*Determine execution based on what stage player is on*/
        switch(ld.statusID){
          case 0:
          if (strcmp(noun, "etc") == 0){
            printf("Entering /etc +100 points\n");
            pi.playerHealth += 100;
            ld.statusID += 1;
          }
          else{
            printf("Error: Access Denied. Interference Detected. -100 points\n");
            pi.playerHealth -= 100;
          }
          /*Check if playerHealth <= 0 to run game over sequence for stage 1*/
          if (pi.playerHealth <= 0){
            if(gameover() == 1){
              pi.playerHealth = 500;
              ld.statusID = 0;
              return 1;
            }
            pi.playerStatus = 0;
            return 0;
          }
          break;
          case 1:
          if (strcmp(noun, "Network_directory") == 0){
            printf("Entering Network_directory. +100 points\n");
            pi.playerHealth += 100;
            ld.statusID += 1;
          }
          else{
            printf("Error: Access Denied. Interference Detected. -100 points\n");
            pi.playerHealth -= 100;
          }
          /*Check if playerHealth <= 0 to run game over sequence for stage 2*/
          if (pi.playerHealth <= 0){
            if(gameover() == 1){
              pi.playerHealth = 500;
              ld.statusID = 0;
              return 1;
            }
            pi.playerStatus = 0;
            return 0;
          }
          break;
          default:
          break;
        }
      }
      else{
        printf("Must receive Badge #5 to unlock\n");
      }
    }
    /*Execute sudo command and parse file_name*/
    else if (strcmp(verb, "sudo") == 0){
      if (pi.badge == 6){
        if(strcmp(noun, "file_shutdown") == 0){
          printf("Enter Password ");
          if(fgets(input, sizeof(input), stdin) == NULL){
          }
          int password = atoi(input);

          if(password == ld.password){
            printf("Insert command to BOS\n");
          }
          else{
            printf("Error: Access Denied. Interference Detected. -100 points\n");
            pi.playerHealth -= 100;

            /*Check if playerHealth <= 0 to run game over sequence for stage 3*/
            if (pi.playerHealth <= 0){
              if(gameover() == 1){
                pi.playerHealth = 500;
                ld.statusID = 0;
                return 1;
              }
              pi.playerStatus = 0;
              return 0;
            }
          }
        }
        else{
          printf("Error: Access Denied. Interference Detected. -100 points\n");
          pi.playerHealth -= 100;

          /*Check if playerHealth <= 0 to run game over sequence for stage 3*/
          if (pi.playerHealth <= 0){
            if(gameover() == 1){
              pi.playerHealth = 500;
              ld.statusID = 0;
              return 1;
            }
            pi.playerStatus = 0;
            return 0;
          }
        }
      }
      else{
        printf("Must receive Badge #5 to unlock\n");
      }
    }
  }
  return 1;
}
void introduction(){
  pi.gamestart = 1;     //Start main gameplay
  displayInstant("text_files/bandersnatch.txt");
  printf("Welcome to the Bandersnatch Project.\n");
  printf("Standby for transmission.\n");

  displayByline("text_files/introduction.txt", 1);
  displaySpeed("text_files/begintrans.txt", 1);
  sleep(3);
  system("clear");
}
void exitGame(){
  displaySpeed("text_files/endtrans.txt", 1);
  displayInstant("text_files/MXK.txt");
}
int gameover(){
  displaySpeed("text_files/gameover.txt", 1);
  printf("Would you like to restart? (Y/N) ");

  /*Get input response to continue the game or not*/
  if(fgets(input, sizeof(input), stdin) == NULL){
    return 0;
  }

  if (strncmp(input, "Y", 1) == 0){
    printf("%s\n", input);
    printf("Resarting Level\n");
    return 1;
  }
  else if (strncmp(input, "N", 1) == 0){
    printf("Ending Game\n");
    return 0;
  }
  printf("UNKNOWN Statement\n");
  return 0;

}
