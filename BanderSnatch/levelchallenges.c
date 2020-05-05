#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "gamefunctional.h"
#include "levelchallenges.h"

struct examData ed;
struct levelData ld;

const char *key[] = {"b", "a", "a", "a", "b", "a", "c", "a", "c", "c", "b", "b"};

//=================================================================================
//getAnswer()
//Description: Displays questions for level one exam and prompt player's answer to
//             questions. Input either "a", "b", or "c"
//Input: inputted player controls
//Output: fget function to prompt input from player
int getAnswer();
//=================================================================================
//challengeOne()
//Description: Switch to level gameplay and execute challenge for level one
//Input: NULL
//Output: Executed challenge for level one
void challengeOne();
//=================================================================================
//challengeTwo()
//Description: Switch to level gameplay and execute challenge for level two
//Input: NULL
//Output: Executed challenge for level two
void challengeTwo();
//=================================================================================
//challengeThree()
//Description: Switch to level gameplay and execute challenge for level three
//Input: NULL
//Output: Executed challenge for level three
void challengeThree();
//=================================================================================
//challengeFour()
//Description: Switch to level gameplay and execute challenge for level four
//Input: NULL
//Output: Executed challenge for level four
void challengeFour();
//=================================================================================
//challengeFive()
//Description: Switch to level gameplay and execute challenge for level five
//Input: NULL
//Output: Executed challenge for level Five
void challengeFive();
//=================================================================================
//challengeSix()
//Description: Switch to level gameplay and execute challenge for level six
//Input: NULL
//Output: Executed challenge for level six
void challengeSix();
//=================================================================================
//levelComplete()
//Description: Display Level complete notification for each level
//Input: NULL
//Output: Displayed Level complete notification for levels
void levelComplete();
//=================================================================================
//parseQuestions()
//Description: Parse input responses from terminal during level 1.
//             User input controls: a, b, c -- anwers to questions
//                                  help    -- request help with level 1
//                                  status  -- request current status in level 1
//Input: NULL
//Output: Displayed responses to user inputs and changed values in level 1
//        struct along with player info
static int parseQuestions();
//============================================================================
//printQuestions()
//Description: Print questions for level 1 to terminal based on question ID
//
//
//
//Input: NULL
//Output: Displayed questions for exqm in level 1
static void printQuestions(int question);

int getAnswer(){
   printQuestions(ed.question);
   printf("\n--> ");
   return fgets(input, sizeof(input), stdin) != NULL;
}
void challengeOne(){
  system("clear");
  printf("Bandersnatch Assessment Test\n\n");
  printf("Please answer the following questions below to assess your abilities as a Private\n");
  printf("=================================================================================\n\n");
  pi.playerHealth = 500;
  while(getAnswer() && parseQuestions());     //Display questions, and parse input for score

  pi.gamestart = 1;  //start main gameplay
  pi.badge += 1;
  sleep(3);
  system("clear");
}
void challengeTwo(){
  /*generate random values for level*/
  ld.fire = (rand() % (2000 - 1000 + 1)) + 1000;
  ld.death = (rand() % (2000 - 1000 + 1)) + 1000;
  ld.ray = (rand() % (2000 - 1000 + 1)) + 1000;
  ld.statusID = 0;

  system("clear");
  displayInstant("text_files/SBOS.txt");
  printf("\nPrepare for demolition Human!\n");
  while(getControls(), parseControls());

  pi.gamestart = 1; //start main gameplay
  sleep(3);
  if(pi.playerStatus == 0){
    return;
  }
  levelComplete();
}
void challengeThree(){
  ld.statusID = 0;
  ld.correctTime = (rand() % (15 - 10 + 1)) + 10;
  ld.burstOpen = (rand() % (8 - 3 + 1)) + 3;
  ld.burstRead = (rand() % (8 - 3 + 1)) + 3;
  ld.burstWrite = (rand() % (8 - 3 + 1)) + 3;

  system("clear");
  displayInstant("text_files/SBOS.txt");
  printf("\nPrepare for demolition Human!\n");
  while(getControls(), parseControls());

  pi.gamestart = 1;
  sleep(3);
  if(pi.playerStatus == 0){
    return;
  }
  levelComplete();
}
void challengeFour(){
  ld.statusID = 0;
  ld.correctAlloc = (rand() % (3 - 1 + 1)) + 1;
  ld.location = (rand() % (16 - 8 + 1)) + 8;
  ld.raySwitch = (rand() % (16 - 8 + 1)) + 8;
  ld.power = (rand() % (16 - 8 + 1)) + 8;

  system("clear");
  displayInstant("text_files/BOS.txt");
  printf("\nPrepare for demolition Human!\n");
  while(getControls(), parseControls());

  pi.gamestart = 1;
  sleep(3);
  if(pi.playerStatus == 0){
    return;
  }
  levelComplete();
}
void challengeFive(){
  ld.statusID = 0;
  ld.killPID = (rand() % (2000 - 1000 + 1)) + 1000;
  ld.password = (rand() % (200000 - 100000 + 1)) + 100000;

  strcpy(ld.ipBOS, "127.24.0.0");
  strcpy(ld.ipSBOS, "127.32.0.1");

  system("clear");
  displayInstant("text_files/SBOS_BOS.txt");
  printf("\nEngaging transmission\n");
  while(getControls(), parseControls());

  pi.gamestart = 1;
  sleep(3);
  if(pi.playerStatus == 0){
    return;
  }
  levelComplete();
}
void challengeSix(){
  ld.statusID = 0;
  system("clear");
  displayInstant("text_files/BOS.txt");
  printf("\nWelcome to the BOS mainframe\n");
  while(getControls(), parseControls());

  pi.gamestart = 1;
  sleep(3);
  if(pi.playerStatus == 0){
    return;
  }
  levelComplete();
}
void levelComplete(){
  printf("\nLevel %d Completed. Badge #%d earned\n", pi.badge, pi.badge);
  pi.badge += 1;
  sleep(1);
  system("clear");
}
static int parseQuestions(){
  char *answer = strtok(input, " \n");
  if (answer != NULL){
    /*Check if player answer matches answer key*/
    if(strncmp(answer, key[ed.question], 1) == 0){
      printf("Correct Answer. Health +100\n");
      pi.playerHealth += 100;
      ed.question += 1;
      ed.score += 1;
    }
    /*execute help command for level 1*/
    else if (strncmp(answer, "help", 4) == 0){
      displayInstant("text_files/general.txt");
      printf("Help Command Actions: a, b, c\n");
      printf("The exam is multiple choice. Type one of the letters to complete the exam.\n");
    }
    /*execute status command for level 1*/
    else if (strncmp(answer, "status", 4) == 0){
      displayInstant("text_files/general.txt");
      printf("Greetings %sThe information below shows your current health, and the latest badge received.\n", pi.playerName);
      printf("You must achieve badge %d to get to the next level\n", pi.badge + 1);
      printf("Health = %d\n", pi.playerHealth);
      printf("Badge = %d\n", pi.badge);
    }
    else{
      printf("Incorrect Answer. Health -100\n");
      ed.question += 1;
      pi.playerHealth -= 100;
      /*Check if playerHealth <= 0 to run game over sequence for stage 1*/
      if (pi.playerHealth <= 0){
        if(gameover() == 1){
          ed.question = 0;
          pi.playerHealth = 500;
          return 1;
        }
        pi.playerStatus = 0;
        return 0;
      }
    }
  }
  if (ed.question >= 12){
    printf("\nExam Completed: Score %d/12\n", ed.score);
    ed.question = 0;
    return 0;
  }
  return 1;
}
static void printQuestions(int question){
  switch(question){
    case 0:
      printf("\n1. What is the linux command to change directories?\n");
      printf("    a. mv         b. cd        c. ps\n");
      break;
    case 1:
      printf("\n2. What is the linux command to list directories?\n");
      printf("    a. ls         b. kill      c. top\n");
      break;
    case 2:
      printf("\n3. In gdb, what commands complete the following tasks\n");
      printf("  i. break on a line of code\n");
      printf("    a. b/break   b. n/next     c. p\n");
      break;

    case 3:
      printf("\n  ii. runs the next line of code\n");
      printf("    a. n/next    b. b/break    c. p\n");
      break;
    case 4:
      printf("\n  iii. print a variable\n");
      printf("    a. n/next    b. p          c. b/break\n");
      break;
    case 5:
      printf("\n4. Concurrency, Memory management, and Persistence make up the main concepts of an OS.\n");
      printf("    a. True      b. False\n");
      break;
    case 6:
      printf("\n5. Which of the following is not an Operating System goal?\n");
      printf("    a. Execute user program and make solving user problems easier\n");
      printf("    b. Use computer hardware and resources in an efficient matter\n");
      printf("    c. Use the heat from a CPU to toast bread\n");
      break;
    case 7:
      printf("\n6. In the file type with the flag wxr-xr-x. Who has writing permissions in the file?\n");
      printf("    a. Owner     b. Group      c. Other\n");
      break;
    case 8:
      printf("\n7. In the file above, who has executable permisisons in file?\n");
      printf("    a. Owner     b. Group      c. Everyone\n");
      break;
    case 9:
      printf("\n8. In the file above, who doesn't have read permissions to the file?\n");
      printf("    a. Owner     b. Group      c. Other\n");
      break;
    case 10:
      printf("\n9. A process cannot be killed, unless it is completed.\n");
      printf("    a. True      b. False\n");
      break;
    case 11:
      printf("\n10. What function is used to create a child process?\n");
      printf("    a. dup()     b. Fork()     c. strcpy()\n");
      break;
    default:
      return;
  }
}
