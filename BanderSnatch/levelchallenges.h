/*Stores data for level One exam*/
struct examData{
  int question;
  int score;
};

/*Stores general data for level challenges*/
struct levelData{
  /*Data for Level Two*/
  int fire;
  int death;
  int ray;

  /*Data for level Three*/
  int burstOpen;
  int burstRead;
  int burstWrite;
  int correctTime;

  /*Data for level Four*/
  int location;
  int raySwitch;
  int power;
  int correctAlloc;

  /*Data for level Five and Six*/
  char ipBOS[255];
  char ipSBOS[255];
  int password;
  int corrupt;    //1 if corrupt, 0 if correct file
  int killPID;    //PID needed to kill in level six

  int statusID;  //value for stages within each level
};

//=================================================================================
//getAnswer()
//Description: Displays questions for level one exam and prompt player's answer to
//             questions. Input either "a", "b", or "c"
//Input: inputted player controls
//Output: fget function to prompt input from player
extern int getAnswer();
//=================================================================================
//challengeOne()
//Description: Switch to level gameplay and execute challenge for level one
//Input: NULL
//Output: Executed challenge for level one
extern void challengeOne();
//=================================================================================
//challengeTwo()
//Description: Switch to level gameplay and execute challenge for level two
//Input: NULL
//Output: Executed challenge for level two
extern void challengeTwo();
//=================================================================================
//challengeThree()
//Description: Switch to level gameplay and execute challenge for level three
//Input: NULL
//Output: Executed challenge for level three
extern void challengeThree();
//=================================================================================
//challengeFour()
//Description: Switch to level gameplay and execute challenge for level four
//Input: NULL
//Output: Executed challenge for level four
extern void challengeFour();
//=================================================================================
//challengeFive()
//Description: Switch to level gameplay and execute challenge for level five
//Input: NULL
//Output: Executed challenge for level Five
extern void challengeFive();
//=================================================================================
//challengeSix()
//Description: Switch to level gameplay and execute challenge for level six
//Input: NULL
//Output: Executed challenge for level six
extern void challengeSix();
//=================================================================================
//levelComplete()
//Description: Display Level complete notification for each level
//Input: NULL
//Output: Displayed Level complete notification for levels
extern void levelComplete();
