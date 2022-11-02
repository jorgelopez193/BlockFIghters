#include <stdio.h>
#include <kipr/graphics.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <strings.h>
#include "my_structs.h"
#include "draw.h"
#include "keyboardIn.h"
#include "boundaries.h"
#define ARR_MAX 1000





typedef struct scores_struct
{
  char initials[4];
  int numWins;
}scores;



void sorting(scores arr[ARR_MAX], int count)
{
  int i,j;
  int dummy;
  char dummyin[4];


  for(j = 0; j< count; j++)
  {
    for(i = 0; i < count; i++)
    {
      if(arr[i].numWins < arr[j].numWins)
      {
        //Rearranging score
        dummy = arr[j].numWins;
        arr[j].numWins = arr[i].numWins;
        arr[i].numWins = dummy;


        //Rearranging corresponding strings
        strcpy(dummyin, arr[j].initials);
        strcpy(arr[j].initials, arr[i].initials);
        strcpy(arr[i].initials, dummyin);

      }
    }
  }

}





int hit = 0;


/////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////MAIN FUNCTION/////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
  srand(time(0));


  graphics_open(1000, 650);
  graphics_fill(250, 40, 100);



  /////////////DRAWING AREA FOR ANIMATIONS////////////////

  //**Bottom of feet are 140 px below ref y**//





  scores input[2];	//takes the input from current game






  int winner[1];

  character players[2];



  players[0].r = 255;
  players[0].g = 255;
  players[0].b = 255;
  players[0].y = 400;
  players[0].x = 750;
  players[0].jumptracker = 0;
  players[0].jump_rate = 0;
  players[0].boundary = 1;
  players[0].theta = 0;
  players[0].charwidth = 20;
  players[0].direction = 0;
  players[0].swordtheta_rate = 0;
  players[0].swordDirection = -1;
  players[0].HP = 100;
  players[0].attacktracker = 0;
  players[0].lives = 3;
  players[0].color = 'A';
  players[0].swordtheta = 0;

  players[1].y = 400;
  players[1].x = 250;
  players[1].jumptracker = 0;
  players[1].jump_rate = 0;
  players[1].boundary = 1;
  players[1].charwidth = -20;
  players[1].theta = 0;
  players[1].direction = 0;
  players[1].swordtheta_rate = 0;
  players[1].swordDirection = 1;
  players[1].HP = 100;
  players[1].attacktracker = 0;
  players[1].lives = 3;
  players[1].color = 'A';
  players[1].r = 255;
  players[1].g = 255;
  players[1].b = 255;
  players[1].swordtheta = 0;

  char dummy[5];






  //max height from jump is at 210

  printf("Hello! Welcome to C-Combat!\n");
  printf("This is a two player game, inspired by a game called EggNog where you and your opponent will try to defeat eachother\n");
  printf("Player 1 will spawn on the right side of the screen and player 2 will be on the left side\n");
  printf("Similarly, each player's initials and number of lives will be displayed in their respective corners\n");
  printf("Player 1, please pick a color for your characater from the following options\n");
  printf("If you select an option that is not listed, the color will default to Green.\n");




  printf("R: Red\n");
  printf("Y: Yellow\n");
  printf("B: Blue\n");
  printf("O: Orange\n");
  printf("P: Pink\n");
  printf("&: Random\n");

  scanf("%c", &players[0].color);



  printf("\nPlayer 2, please pick a color for your characater from the following options\n");
  printf("R: Red\n");
  printf("Y: Yellow\n");
  printf("B: Blue\n");
  printf("O: Orange\n");
  printf("P: Pink\n");
  printf("&: Random\n");

  scanf("%c", &dummy[0]);
  scanf("%c", &players[1].color);

  srand(time(0));


  colorPlayers(players);

  printf("\nPlayer 1, please enter your initials (3 Characters).\n");
  fgets(dummy, 4, stdin);
  fgets(players[0].initials, 4, stdin);


  printf("\nPlayer 2, please enter your initials (3 Characters).\n");
  fgets(dummy, 4, stdin);
  fgets(players[1].initials, 4, stdin);

  strcpy(input[0].initials, players[0].initials);		//Putting players initials into array, will add winner's to file
  strcpy(input[1].initials, players[1].initials);



  printf("\nPlayer 1 Controls:\n\n");
  printf("Jump: Up Key\nLeft and Right: Left and Right Keys\nSword Attack: L\n");

  printf("\nPlayer 2 Controls:\n\n");
  printf("Jump: W\nLeft and Right: A and D\nSword Attack: Shift\n\n");

  printf("Now please close the console and open the graphics window.\n");
  printf("To access the leaderboard, press space on the winner screen.\n\n");
  
  printf("Sources used: ZyBooks, Google RGB Color Picker, Stackoverflow.com");
  

  double suntheta = 0;

  while((players[0].lives != 0) && (players[1].lives != 0) )
  {




    graphics_fill(135, 217, 255);

    //GROUND
    graphics_rectangle_fill(0, 540, 1000, 650, 31, 128, 58);


    //SUN

    sun(800, 60, 40, suntheta);
    suntheta = suntheta + .05;



    //TREE
    graphics_rectangle_fill(600, 340, 650, 540, 122, 73, 17);
    tree(625, 340, 40);


    //CLOUDS
    cloud(300, 150, 30);
    cloud(600, 90, 35);

    //PLATFORMS
    graphics_rectangle_fill(700, 375, 900, 350, 250, 250, 250);
    graphics_rectangle_fill(100, 375, 300, 350, 250, 250, 250);
    graphics_rectangle_fill(400, 375 - 190, 600, 350 - 190, 250, 250, 250);

    //Characters and swords
    //P1
    draw_character(players[0].x, players[0].y, players[0].theta, players[0].r, players[0].g, players[0].b);
    rotate_sword(players[0].x + players[0].charwidth, players[0].y + 70, players[0].swordtheta * players[0].swordDirection);
    players[0].swordtipx = swordtip[0]; //gets position of the sword tip, uses pointer from within rotate sword function
    players[0].swordtipy = swordtip[1];

    //P2
    draw_character(players[1].x, players[1].y, players[1].theta, players[1].r, players[1].g, players[1].b);
    rotate_sword(players[1].x + players[1].charwidth, players[1].y + 70, players[1].swordtheta * players[1].swordDirection); 
    players[1].swordtipx = swordtip[0]; //gets position of the sword tip
    players[1].swordtipy = swordtip[1]; 


    //FLOWERS
    flower(80, 500, .8);
    flower(300, 520, .9);


    //Health bars:

    //P1
    graphics_rectangle_fill(players[0].x - 55, players[0].y - 10, players[0].x + 55, players[0].y - 15, 250, 250, 250);
    graphics_rectangle_fill(players[0].x - players[0].HP/2, players[0].y - 12, players[0].x + players[0].HP/2, players[0].y - 13, players[0].r, players[0].g, players[0].b);

    //P2
    graphics_rectangle_fill(players[1].x - 55, players[1].y - 10, players[1].x + 55, players[1].y - 5, 250, 250, 250);
    graphics_rectangle_fill(players[1].x - players[1].HP/2, players[1].y - 7, players[1].x + players[1].HP/2, players[1].y - 8, players[1].r, players[1].g, players[1].b);

    //Number of Lives
    g_printInt(players[1].lives, 1, 100, 75, 250, 250, 250, 3.0);
    g_printInt(players[0].lives, 1, 900, 75, 250, 250, 250, 3.0);

    //Initials
    g_printString(players[0].initials, 900 - 14, 40, 250, 250, 250, 3.0);
    g_printString(players[1].initials, 100 - 14, 40, 250, 250, 250, 3.0);

    graphics_update();








    leftright(players);		//Checks if left/right keys are pressed, if so moves characters accordingly








    legsSwing(players);		// controls how legs swing when not moving or when both left and right are pressed

    checkboundaries(players);	//Function changes variable "collision" to 0, 1, or 2 depending on which boundary

    freefall(players);			//checks to see if character is going over a ledge, if so, it drops them back down to the ground    
    boundary(players);			//takes in collision variable and puts character at that boundary

    jumping(players);			// checks to see if player hit the jump buttons, then makes character jump
    leftrightboundaries(players);

    checkdamage(players);	//Checks if player is hit with sword, if so, deals damage

    swordSwing(players);	//Checks if attack button is pressed, if it is it swings the sword

    players[1].swordtheta = players[1].swordtheta + players[1].swordtheta_rate;
    players[1].theta = players[1].theta + players[1].theta_rate * players[1].direction;
    players[1].y = players[1].y - players[1].jump_rate* players[1].boundary;


    players[0].swordtheta = players[0].swordtheta + players[0].swordtheta_rate;
    players[0].theta = players[0].theta + players[0].theta_rate * players[0].direction;
    players[0].y = players[0].y - players[0].jump_rate * players[0].boundary; 






    if(players[0].lives <= 0)	//Determines who won, based on who lost all their lives first
    {
      winner[0] = 1; //used as a pointer
    }

    if(players[1].lives <= 0)
    {
      winner[0] = 0;
    }
  }



  int len3 = strlen("Thank you for playing!");	//getting string lengths to center
  int len4 = strlen("Winner: XXX");

  while(get_key_state(KeySpace) == 0)	//Winner screen
  {
    graphics_fill(0, 0, 0);

    g_printString("Winner:", 500 - 5*7*len4/2, 200, 250, 250, 250, 5.0);



    g_printString(players[winner[0]].initials, 500 + 70 , 200, 250, 250, 250, 5.0); 

    int len5 = strlen("Press space to continue");

    g_printString("Thank you for playing!", 500 - 7*len3*3/2, 300, 250, 250, 250, 3.0);
    g_printString("Press Space to continue", 500 - 7*3*len5/2, 400, 250, 250, 250, 3.0);



    graphics_update();





  }

  //FILE SECTION

  int i = 0;
  scores list[ARR_MAX];
  int fcounter = 0;
  FILE* fPointer;




  fPointer = fopen("player_wins.txt", "r");

  if(fPointer == NULL)	//Checks to see if file exists, if not, then it will assign first list member to winner's input, and sets counter to 1 so it can be printerd
  {
    strcpy(list[0].initials, input[winner[0]].initials);
    list[0].numWins = 1;
    fcounter = 1;
  }


  else{								//If file exists, it is read and fills list array to be sorted
    while(!feof(fPointer))
    {
      fscanf(fPointer, "%s %d", list[i].initials, &list[i].numWins);
      fcounter = fcounter + 1;
      i++;
    }
  }


  fclose(fPointer);


  int matchsum[1];	//Will be used to determine if a the same initials have been entered before

  matchsum[0] = 0;
  int m;

  if(fPointer != NULL)	//only compares the initials if file exists
  {
    for(i = 0; i < fcounter; i++)
    {
      m = 0;
      if(strcmp(list[i].initials, input[winner[0]].initials) == 0)		 //Checking for match in initials
      {
        list[i].numWins = list[i].numWins + 1;		//if match, it will increment numWins by 1
        m = 1;
      }
      matchsum[0] = matchsum[0] + m;
    }


    if(matchsum[0] == 0)		//if no match, it will append the array and set numWins to 1
    {
      strcpy(list[fcounter - 1].initials, input[winner[0]].initials);
      list[fcounter - 1].numWins = 1;
    }

  }


  sorting(list,fcounter);		//sorting the list array


  fPointer = fopen("player_wins.txt", "w");	//overwriting old file

  if(matchsum[0] == 0)	//if no match
  {
    for(i = 0; i < fcounter; i++)
    {
      fprintf(fPointer, "%s %d\n", list[i].initials, list[i].numWins); 
    }

  }
  else{		//if match
    for(i = 0; i < fcounter - 1; i++)
    {
      fprintf(fPointer, "%s %d\n", list[i].initials, list[i].numWins); 
    }
  }

  fclose(fPointer);






  //LEADERBOARD



  graphics_update();


  graphics_fill(0, 0, 0);
  g_printString("Wins Leaderboard:", 500 - 17*5*7/2, 50, 250, 250, 250, 5.0);

  if(matchsum[0] == 0)	//if no match
  {
    for(i = 0; i < fcounter; i++)
    {
      g_printString(list[i].initials, 500 - 3*2.5*7/2, 60 + 50*(i+1), 250, 250, 250, 2.5);	//initials
      g_printInt(list[i].numWins, 1, 500 + 60, 60 + 50 * (i+1), 250, 250, 250, 2.5);	        //numwins
      g_printInt((i+1), 1, 500 - 3*7/2 - 60, 60 + 50 * (i+1), 250, 250, 250, 2.5);		    //ranking
      if(i > 9)
      {
        break;
      }
    }
  }

  else{	//if match
    for(i = 0; i < fcounter - 1; i++)
    {
      g_printString(list[i].initials, 500 - 3*2.5*7/2, 60 + 50*(i+1), 250, 250, 250, 2.5);	//initials
      g_printInt(list[i].numWins, 1, 500 + 60, 60 + 50 * (i+1), 250, 250, 250, 2.5);		//numwins
      g_printInt((i+1), 1, 500 - 3*7/2 - 60, 60 + 50 * (i+1), 250, 250, 250, 2.5);					//ranking
      if(i > 9)		//set limit of 10 items being on the list, was crashing when more were printed
      {
        break;
      }
    }
  }


  graphics_rectangle_fill(400, 590, 600, 650, 0, 0, 0);

  graphics_update();




  


  graphics_close();




  return 0;
}





