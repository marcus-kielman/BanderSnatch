#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "levelsgeneral.h"
#include "gamefunctional.h"
#include "levelchallenges.h"

//=================================================================================
//getInput()
//Description: Gets player input controls from terminal during main gameplay
//             User input controls: q    -- exits main gameplay (i.e. overall game)
//                                  c    -- continue main gameplay between levels
//                                  help -- request control description during
//                                          gameplay
//                                status -- request current user status during
//                                          gameplay
//                            saveleader  -- save player info to leaderboard
//                            leaderboard -- display leaderboard
//                            leaderclear -- clear info on leaderboard
//Input: inputted player controls
//Output: NULL
int getInput();
//=================================================================================
//parseAndExecute()
//Description: parse player input controls from terminal during main gameplay
//             User input controls: q    -- exits main gameplay (i.e. overall game)
//                                  c    -- continue main gameplay between levels
//                                  help -- request control description during
//                                          gameplay
//                                status -- request current user status during
//                                          gameplay
//                            saveleader  -- save player info to leaderboard
//                            leaderboard -- display leaderboard
//                            leaderclear -- clear info on leaderboard
//Input: NULL
//Output: Displayed responses to player controls
//        fget function to prompt input from player
static int parseAndExecute();


int getInput(){
  /*Check if user quit after game over*/
  if (pi.playerStatus == 0){
    exitGame();
    return 0;
  }

  /*Prompt input*/
  printf("\n--> ");
  return fgets(input, sizeof(input), stdin) != NULL;
}
static int parseAndExecute(){
  char *verb = strtok(input, " \n");

  if (verb != NULL){
    /*Execute q command*/
    if(strncmp(verb, "q", 1) == 0){
      exitGame();
      return 0;
    }
    /*Execute c command*/
    else if(strncmp(verb, "c", 1) == 0){
      /*Decide which level to run based on pi.badge*/
      switch(pi.badge){
        case 0:
          /*Check if game switched from main gameplay to level gameplay*/
          if(pi.gamestart == 0){
            challengeOne();
          }
          else{
            levelOne();
          }
          break;
        case 1:
          levelOneCongrats();
          break;
        case 2:
          if(pi.gamestart == 0){
            challengeTwo();
          }
          else{
            levelTwo();
          }
          break;
        case 3:
          if(pi.gamestart == 0){
            challengeThree();
          }
          else{
            levelThree();
          }
          break;
        case 4:
          if(pi.gamestart == 0){
            challengeFour();
          }
          else{
            levelFour();
          }
          break;
        case 5:
          if(pi.gamestart == 0){
            challengeFive();
          }
          else{
            levelFive();
          }
          break;
        case 6:
          if(pi.gamestart == 0){
            challengeSix();
          }
          else{
            levelSix();
          }
          break;
        case 7:
          gameComplete();
          break;
        default:
          printf("UNKNOWN BADGE ID\n");
      }
    }
    /*Execute help command*/
    else if (strncmp(verb, "help", 4) == 0){
      printf("Help Command Actions: q, c, status\n");
      printf("c --> continues gameplay, q --> exit game, status --> current health and status in game\n");
      printf("saveleader --> saves player Name and Health in leaderboard\n");
      printf("leaderboard --> displays leaderboard, leaderclear --> clears leaderboard\n");
    }
    /*Execute status command*/
    else if (strncmp(verb, "status", 4) == 0){
      displayInstant("text_files/general.txt");
      printf("Greetings %sThe information below shows your current health, and the latest badge received.\n", pi.playerName);
      printf("You must achieve badge %d to get to the next level\n", pi.badge + 1);
      printf("Health = %d\n", pi.playerHealth);
      printf("Badge = %d\n", pi.badge);
    }
    /*Execute saveleader command*/
    else if(strncmp(verb, "saveleader", 10) == 0){
      printf("Player Info Saved to Leaderboard\n");
      saveLeader();
    }
    /*Execute leaderboard command*/
    else if(strncmp(verb, "leaderboard", 11) == 0){
      displayLeader();
    }
    /*Execute leaderclear command*/
    else if (strncmp(verb, "leaderclear", 11) == 0){
      printf("Leaderboard cleared\n");
      clearLeader();
    }
    else{
      printf("Please input valid command\n");
    }
  }
  return 1;
}
int main(){
  srand(time(0));
  pi.badge = 0;
  pi.playerStatus = 1;
  introduction();
  while(getInput() && parseAndExecute());
  return 0;
}
