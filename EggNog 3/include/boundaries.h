void checkboundaries(character players[])		//Returns 0 if not at boundary, returns 1 if at boundary
{
  /*
  int collision[2];
  collision[0] = 0;
  collision[1] = 0;
  */
  int i;
  
 for(i = 0; i<2; i++)
 {
  if(players[i].y >= 400) //Checks if on ground
  {
   players[i].collision = 1; 
  }
  
  		//checks far right platform
  else if( (players[i].y>= 210) && (players[i].y <= 217) && (players[i].x>= 700) && (players[i].x <= 900) )
  {
   players[i].collision = 2; 
  }
   		//checks left platform
  else if( (players[i].y>= 210) && (players[i].y <= 217) && (players[i].x>= 100) && (players[i].x <= 300) )
  {
   players[i].collision = 2; 
  } 
   	//checks top platform
  else if( (players[i].y>= 210 - 190) && (players[i].y <= 215 - 190) && (players[i].x>= 400) && (players[i].x <= 600) )
  {
   players[i].collision = 3; 
  } 
  
   
  else{ players[i].collision = 0;} 
   
 }
  
  return;
}



void boundary(character player[])
{
  
 int i;
for(i = 0; i<2; i++)
 {
 
 if(player[i].collision != 0)		
    {
     player[i].jumptracker = 0;
     player[i].jump_rate = 0;
     player[i].boundary = 0;
      if(player[i].collision == 1)
      {
       player[i].y = 400; 
      }
   
	  if(player[i].collision == 2)
      {
       player[i].y = 210; 
      }
      
      if(player[i].collision == 3)
      {
       player[i].y = 20; 
      }
   
    } 
 }
 
 return;
}

void freefall(character players[])
{
  int i;
  
 for( i = 0; i < 2; i++)
 {
  if( (players[i].collision == 0) && (players[i].jumptracker == 0))	
    {
     players[i].jump_rate = players[i].jump_rate -1; 
     players[i].boundary = 1;
     //players[i].jumptracker = 1;
    }
   if(players[i].jump_rate <= -19)	//establishes a maximum fall velocity of -19 px/loop
   {
    players[i].jump_rate = -19; 
   }
   
   
 }
  
 return; 
}

void leftrightboundaries(character players[])
{
  int i;
 for( i = 0; i < 2; i++)
 {
  if(players[i].x <= 0)
  {
   players[i].x = 0; 
  }
   
  if(players[i].x >= 1000)
  {
   players[i].x = 1000; 
  }
   
 }
   
   return;
  
  
  
}



	/*
    if(players[0].y >= y1OG)						//Checks if the character is back at original position
    {
     players[0].jump_rate = 0; 
     players[0].y = y1OG; 
     players[0].boundary = 0;
     players[0].jumptracker = 0;
    }
    */

