struct PlayerInfo pi;   //reference to player Info struct
static char input[100]; //Player input during gameplay

/*Player Struct*/
struct PlayerInfo{
  char playerName[255];
  int playerHealth;
  int badge;
  int gamestart;    //1 for continuing, 0 for stop
  int playerStatus; //1 for playing, 0 for game over
};

//=================================================================================
//saveLeader()
//Description: Write player's name and health to leaderboard
//Input: NULL
//Output: player's name and health written to leaderLog.txtextern int saveLeader();
//        1 on error, 0 on success
extern int saveLeader();
//=================================================================================
//displayLeader()
//Description: display leaderboard to terminal
//Input: NULL
//Output: displayed leaderboard
extern void displayLeader();
//=================================================================================
//clearLeader()
//Description: clears all names and health from leaderboard
//Input: NULL
//Output: cleared leaderLog.txt
//        1 on error, 0 on success
extern int clearLeader();
//=================================================================================
//displayInstant()
//Description: Instantly displays file contents to terminal
//Input: character pointer containing file name
//Output: displayed file contents
//        1 on error, 0 on success
extern int displayInstant(char *charFile);
//=================================================================================
//displayByline()
//Description: sleeps for certain time before displaying file contents to terminal
//Input: *charFile -->character pointer containing file name,
//       speed     --> amount of time to sleep before displaying next line
//Output: slow display of file contents line by line
//        1 on error, 0 on success
extern int displayByline(char *charFile, int speed);
//=================================================================================
//displaySpeed()
//Description: sleeps for certain time before displaying file contents to terminal
//Input: *charFile -->character pointer containing file name,
//       speed     --> amount of time to sleep before displaying next line
//Output: slow displaying every two lines of file contents
//        1 on error, 0 on success
extern int displaySpeed(char *charFile, int speed);
//=================================================================================
//getControls()
//Description: Displays prompts for each level and stores controls from player in
//             level gameplay
//             Input controls: "q", "c", "help", "status", "ps", "kill", "burst"
//                             "malloc", "ifconfig", "open", "ls", "cd", "sudo"
//Input: inputted player controls
//Output: fget function to prompt input from player
extern int getControls();
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
//Output: Displayed responses and execution of player controls
//        1 when gameplay in progress, 0 when gameplay completed
extern int parseControls();
//=================================================================================
//introduction()
//Description: display introduction to game
//Input: NULL
//Output: displayed introduction to game
extern void introduction();
//=================================================================================
//exitGame()
//Description: display EXIT GAME sequence
//Input: NULL
//Output: displayed EXIT GAME sequence
extern void exitGame();
//=================================================================================
//gameover()
//Description: display GAME OVER sequence, and prompt if player would like to restart
//Input: NULL
//Output: displayed GAME OVER sequence, 1 on restart, and 0 on exit game
extern int gameover();
