void leftright(character players[])		//Controls Left and right movements of player 2
{
  
    if(get_key_state(KeyD) != 0)
     {
      players[1].x = players[1].x + 5; 
      players[1].theta_rate = 10;
      players[1].charwidth = 20;
      players[1].swordDirection = -1;
     }
    if(get_key_state(KeyA) != 0)
     {
      players[1].x = players[1].x - 5; 
      players[1].theta_rate = 10;
      players[1].charwidth = -20;
      players[1].swordDirection = 1;
     } 
  
  if(get_key_state(KeyRight) != 0)
     {
      players[0].x = players[0].x + 5; 
      players[0].theta_rate = 10;
      players[0].charwidth = 20;
      players[0].swordDirection = -1;
     }
    if(get_key_state(KeyLeft) != 0)
     {
      players[0].x = players[0].x - 5; 
      players[0].theta_rate = 10;
      players[0].charwidth = -20;
      players[0].swordDirection = 1;
     } 
  
  
  
  
  
  return;
}


void legsSwing(character players[])
{
  
  
  if(players[0].theta >= 50)					//Makes legs move in opposite direction once max angle is reached
    {
      players[0].direction = -1;
    }
    if(players[0].theta <= 0)					// Same thing here
    {
      players[0].direction = 1;
    }
    if( (get_key_state(KeyLeft) == 0) && (get_key_state(KeyRight) == 0))		//Stops legs from moving if no buttons are pressed
    {
     players[0].theta = 0;
     players[0].theta_rate = 0;
    }
    if( (get_key_state(KeyLeft) != 0) && (get_key_state(KeyRight) != 0))		//Stops legs from moving if both buttons are pressed at the same time
    {
     players[0].theta = 0;
     players[0].theta_rate = 0;
    }
  
  
    if( (get_key_state(KeyA) == 0) && (get_key_state(KeyD) == 0))
    {
     players[1].theta = 0;
     players[1].theta_rate = 0;
    }
    if( (get_key_state(KeyA) != 0) && (get_key_state(KeyD) != 0))
    {
     players[1].theta = 0;
     players[1].theta_rate = 0;
    }
    
    if(players[1].theta >= 50)
    {
      players[1].direction = -1;
    }
    if(players[1].theta <= 0)
    {
      players[1].direction = 1;
    }
  
  
  return;
}


void jumping(character players[])
{
  if( (get_key_state(KeyW) != 0) && (players[1].jumptracker == 0) )	//UP, also prevents players from double jumping by checking if they are still in a jump
    {
      players[1].jump_rate = 20;
      players[1].jumptracker = 1;
      players[1].boundary = 1;
    }
    
    if( players[1].jumptracker == 1 )
    {
     players[1].jump_rate = players[1].jump_rate - 1;
      
      if( players[1].jump_rate <= -19)
      {
       players[1].jump_rate = -19; 
      }
    }
  
  if( (get_key_state(KeyUp) != 0) && (players[0].jumptracker == 0) )	//UP, also prevents players from double jumping by checking if they are still in a jump
    {
      players[0].jump_rate = 20;
      players[0].boundary = 1;
      players[0].jumptracker = 1;
    }
    
    if( players[0].jumptracker == 1 )
    {
     players[0].jump_rate = players[0].jump_rate - 1;
      
      if( players[0].jump_rate <= -19)
      {
       players[0].jump_rate = -19; 
      }
    }
  
  
  
 return; 
}


void swordSwing(character players[])
{
  if(get_key_state(KeyShift) != 0)
    {
     players[1].swordtheta_rate = 20;
     players[1].attacktracker = 1;
    } 
    
    if(players[1].swordtheta >= 90)
    {
     players[1].swordtheta = 0; 
     players[1].swordtheta_rate = 0;
     players[1].attacktracker = 0;
    }
  
  if(get_key_state(KeyL) != 0)	//Moves sword to attack
   {
    players[0].swordtheta_rate = 20;
    players[0].attacktracker = 1;
   } 
    
    if(players[0].swordtheta >= 90)			//returns sword to original position
    {
     players[0].swordtheta = 0; 
     players[0].swordtheta_rate = 0;
     players[0].attacktracker = 0;
    }
  
  
  
 return; 
}

int damage = 5;

void checkdamage(character players[])
{
  if( (players[0].attacktracker) && (players[0].swordtipx >= players[1].x - 20) && (players[0].swordtipx <= players[1].x + 20) && (players[0].swordtipy >= players[1].y) &&  (players[0].swordtipy <= players[1].y + 140))
    {
     players[1].HP = players[1].HP - damage; 
    }
    
    if(players[1].HP <= 0)
    {
      players[1].x = 500;
      players[1].y = 20;
      players[1].HP = 100;
      players[1].lives = players[1].lives - 1;
    }
    
    if( (players[1].attacktracker) && (players[1].swordtipx >= players[0].x - 20) && (players[1].swordtipx <= players[0].x + 20) && (players[1].swordtipy >= players[0].y) &&  (players[1].swordtipy <= players[0].y + 140))
    {
     players[0].HP = players[0].HP - damage; 
    }
    
    if(players[0].HP <= 0)
    {
      players[0].x = 500;
      players[0].y = 20;
      players[0].HP = 100;
      players[0].lives = players[0].lives - 1;
    }
  return;
}

/*
void checklives(character players[])
{
  int i;
  for(i = 0; i < 2; i++)
  {
   if(players[i].lives <= 0)
   {
     
   }
    
  }
  
  return;
}

*/


