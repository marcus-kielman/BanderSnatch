#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "gamefunctional.h"
#include "levelchallenges.h"

//==============================================================================
//levelOne()
//Description: Prompts for player's name to store in playerName. Displays level
//             monologue from General Buckingham
//Input: NULL
//Output: Printed monologue and text art for level one
void levelOne();
//==============================================================================
//levelOneCongrats()
//Description: Displays congratulation monologue from General Buckingham
//Input: NULL
//Output: Printed monologue and text art for level one congratulation
void levelOneCongrats();
//==============================================================================
//levelTwo()
//Description: Displays level monologue from General Buckingham
//Input: NULL
//Output: Printed monologue and text art for level two
void levelTwo();
//==============================================================================
//levelThree()
//Description: Displays level monologue from General Buckingham
//Input: NULL
//Output: Printed monologue and text art for level three
void levelThree();
//==============================================================================
//levelFour()
//Description: Displays level monologue from General Buckingham
//Input: NULL
//Output: Printed monologue and text art for level four
void levelFour();
//==============================================================================
//levelfive()
//Description: Displays level monologue from General Buckingham
//Input: NULL
//Output: Printed monologue and text art for level five
void levelFive();
//==============================================================================
//levelSix()
//Description: Displays level monologue from General Buckingham
//Input: NULL
//Output: Printed monologue and text art for level Six
void levelSix();
//==============================================================================
//levelComplete()
//Description: Displays level monologue from General Buckingham
//Input: NULL
//Output: Printed monologue and text art for game completion
void gameComplete();

void levelOne(){
  /*Display Level*/
  sleep(2);
  displaySpeed("text_files/levelOne.txt", 1);
  sleep(2);
  printf("Incoming message from:\n");
  displayInstant("text_files/unitednations.txt");
  sleep(2);
  displayInstant("text_files/general.txt");

  /*Display General Name inquiry*/
  printf("Greetings sir. What is your name?\n");
  if (fgets(input, sizeof(input), stdin) == NULL){
    printf("no name found\n");
  }
  strncpy(pi.playerName, input, strlen(input) - 1);
  printf("\nExcellent. Welcome to the United Nations Transmission %s\n", pi.playerName);

  /*Display general monlogue and insert name*/
  sleep(1);
  displaySpeed("text_files/levelonegeneral.txt", 1);
  printf("BEST OF LUCK %s. The World is depending on it.\n", pi.playerName);
  printf("-General Buckingham\n");
  pi.gamestart = 0;
}
void levelOneCongrats(){
  printf("\nIncoming message from:\n");
  displayInstant("text_files/unitednations.txt");
  sleep(2);
  displayInstant("text_files/general.txt");
  printf("Greetings %s\n", pi.playerName);
  displaySpeed("text_files/congrats.txt", 1);
  levelComplete();
}
void levelTwo(){
  /*Display Level*/
  sleep(2);
  displaySpeed("text_files/levelTwo.txt", 1);
  sleep(2);

  /*Display general's monologue*/
  printf("Incoming message from:\n");
  displayInstant("text_files/unitednations.txt");
  sleep(2);
  displayInstant("text_files/general.txt");
  printf("Greetings Private %s\n", pi.playerName);
  displaySpeed("text_files/leveltwogeneral.txt", 1);
  printf("\nBEST OF LUCK Private %s. The World is depending on it.\n", pi.playerName);
  printf("-General Buckingham\n");
  pi.gamestart = 0;
}
void levelThree(){
  /*Display Level*/
  sleep(2);
  displaySpeed("text_files/levelThree.txt", 1);
  sleep(2);

  /*Display general's monologue*/
  printf("Incoming message from:\n");
  displayInstant("text_files/unitednations.txt");
  sleep(2);
  displayInstant("text_files/general.txt");
  printf("Greetings Private %s\n", pi.playerName);
  displaySpeed("text_files/levelthreegeneral.txt", 1);
  printf("Greetings Private %s\n", pi.playerName);
  printf("\nBEST OF LUCK Private %s. The World is depending on it.\n", pi.playerName);
  printf("-General Buckingham\n");
  pi.gamestart = 0;
}
void levelFour(){
  /*Display Level*/
  sleep(2);
  displaySpeed("text_files/levelFour.txt", 1);
  sleep(2);

  /*Display general's monologue*/
  printf("Incoming message from:\n");
  displayInstant("text_files/unitednations.txt");
  sleep(2);
  displayInstant("text_files/general.txt");
  printf("Greetings Private %s\n", pi.playerName);
  displaySpeed("text_files/levelfourgeneral.txt", 1);
  printf("\nBEST OF LUCK Private %s. The World is depending on it.\n", pi.playerName);
  printf("-General Buckingham\n");
  pi.gamestart = 0;
}
void levelFive(){
  /*Display Level*/
  sleep(2);
  displaySpeed("text_files/levelFive.txt", 1);
  sleep(2);

  /*Display general's monologue*/
  printf("Incoming message from:\n");
  displayInstant("text_files/unitednations.txt");
  sleep(2);
  displayInstant("text_files/general.txt");
  printf("Greetings Private %s\n", pi.playerName);
  displaySpeed("text_files/levelfivegeneral.txt", 1);
  printf("\nBEST OF LUCK Private %s. The World is depending on it.\n", pi.playerName);
  printf("-General Buckingham\n");
  pi.gamestart = 0;
}
void levelSix(){
  /*Display Level*/
  sleep(2);
  displaySpeed("text_files/levelSix.txt", 1);
  sleep(2);

  /*Display general's monologue*/
  printf("Incoming message from:\n");
  displayInstant("text_files/unitednations.txt");
  sleep(2);
  displayInstant("text_files/general.txt");
  printf("Greetings Private %s\n", pi.playerName);
  displaySpeed("text_files/levelsixgeneral.txt", 1); 
  printf("\nBEST OF LUCK Private %s. The World is depending on it.\n", pi.playerName);
  printf("-General Buckingham\n");
  pi.gamestart = 0;
}
void gameComplete(){
  /*Display complete game*/
  sleep(2);
  displaySpeed("text_files/gamecomplete.txt", 1);
  system("clear");

  /*Display General's monologue*/
  printf("Incoming message from:\n");
  displayInstant("text_files/unitednations.txt");
  sleep(2);
  displayInstant("text_files/general.txt");
  sleep(2);
  printf("Greetings %s\n", pi.playerName);
  displaySpeed("text_files/gamecompletegeneral.txt", 1);
  printf("-General Buckingham\n");
  printf("\nGame Completed. Congratulations\n");
  pi.badge = 0;
}
