double xR(double x0, double y0, double theta)		//X rotation function
{
  return (x0*cos(theta) + y0*sin(theta));
}

double yR(double x0, double y0, double theta)		//Rotation function
{
  return (y0*cos(theta) - x0*sin(theta));
}


 int swordtip[2];
  

void draw_sword(int x, int y)
{
  int blade_width = 5;
  int blade_height = 40;
  
  int hilt_width = 10;
  double handle_width = 2.4;
  int hilt_height = 5;
  int handle_height = 10;
  
  //X/Y is at middle of handle
  
  //BLADE
  graphics_rectangle_fill(x - blade_width, y - blade_height, x + blade_width, y, 250, 250, 250); 
  graphics_triangle_fill(x - blade_width, y - blade_height,
                         x + blade_width, y - blade_height,
                         x, y - blade_height - 10, 
                         250, 250, 250);
  
  
  ///SWORD HILT
  graphics_rectangle_fill(x - hilt_width, y, x + hilt_width, y + hilt_height, 135, 88, 0);	//part across blade
  graphics_rectangle_fill(x - handle_width, y + hilt_height, x + handle_width, y + hilt_height + handle_height, 135, 88, 0);	//handle part
  
  
  
  
 return; 
}


void rotate_sword(int x, int y, double theta)
{
  
  double deg = theta * 3.14/180;
  
  int blade_width = 5;
  int blade_height = 40;
  
  int hilt_width = 10;
  double handle_width = 2.4;
  int hilt_height = 5;
  int handle_height = 10;
  
  
  
  int xBlade1, xBlade2, yBlade1, yBlade2;		//RECTANGULAR PORTION OF BLADE
  xBlade1 = x - blade_width;
  yBlade1 = y - blade_height;
  xBlade2 = x + blade_width;
  yBlade2 = y;
  
  int xBlade3,xBlade4, yBlade3, yBlade4;
  xBlade3 = xBlade2;
  yBlade3 = yBlade1;
  xBlade4 = xBlade1;
  yBlade4 = yBlade2;
  
  												//NEW RECTANGULAR PORTION OF BLADE
  int xBlade1_new, xBlade2_new, yBlade1_new, yBlade2_new, xBlade3_new,xBlade4_new, yBlade3_new, yBlade4_new;
  xBlade1_new = x + xR(xBlade1 - x, yBlade1 - y, deg);
  yBlade1_new = y + yR(xBlade1 - x, yBlade1 - y, deg);
  xBlade2_new = x + xR(xBlade2 - x, yBlade2 - y, deg);
  yBlade2_new = y + yR(xBlade2 - x, yBlade2 - y, deg);
  xBlade3_new = x + xR(xBlade3 - x, yBlade3 - y, deg);
  yBlade3_new = y + yR(xBlade3 - x, yBlade3 - y, deg);
  xBlade4_new = x + xR(xBlade4 - x, yBlade4 - y, deg);
  yBlade4_new = y + yR(xBlade4 - x, yBlade4 - y, deg);
  
  graphics_triangle_fill(xBlade1_new, yBlade1_new, 
                         xBlade3_new, yBlade3_new, 
                         xBlade2_new, yBlade2_new, 
                         181, 186, 189);
  graphics_triangle_fill(xBlade1_new, yBlade1_new, 
                         xBlade4_new, yBlade4_new, 
                         xBlade2_new, yBlade2_new, 
                         181, 186, 189);
  
  
 //graphics_rectangle_fill(xBlade1_new, yBlade1_new, xBlade2_new, yBlade2_new, 250, 250, 250); //drawing new rectangle
  
  											 	//TRIANGLE TIP OF BLADE
  int xT1, yT1, xT2, yT2, xT3, yT3;
  
  xT1 = x - blade_width;
  yT1 = y - blade_height;
  xT2 = x + blade_width;
  yT2 = y - blade_height;
  xT3 = x;
  yT3 = y - blade_height - 10;
  
  																//NEW TRIANGLE TIP	
  int xT1_new, xT2_new, xT3_new, yT1_new, yT2_new, yT3_new;	
  xT1_new = x + xR(xT1 - x, yT1 - y, deg);
  yT1_new = y + yR(xT1 - x, yT1 - y, deg);
  xT2_new = x + xR(xT2 - x, yT2 - y, deg);
  yT2_new = y + yR(xT2 - x, yT2 - y, deg);
  xT3_new = x + xR(xT3 - x, yT3 - y, deg);
  yT3_new = y + yR(xT3 - x, yT3 - y, deg);
  
  
  swordtip[0] = xT3_new;
  swordtip[1] = yT3_new;
  															//DRAWING NEW TRIANGLE TIP
  graphics_triangle_fill(xT1_new, yT1_new,		
                         xT2_new, yT2_new,
                         xT3_new, yT3_new, 
                         181, 186, 189);
  
  
  
  												//SWORD HILT
  int xHilt1, xHilt2, yHilt1, yHilt2, xHilt3, yHilt3, xHilt4, yHilt4;
  xHilt1 = x - hilt_width;
  yHilt1 = y;
  xHilt2 = x + hilt_width;
  yHilt2 = y + hilt_height;
  xHilt3 = xHilt2;
  yHilt3 = yHilt1;
  xHilt4 = xHilt1;
  yHilt4 = yHilt2;
  
  
  												//NEW SWORD HILT
  int xHilt1_new, xHilt2_new, yHilt1_new, yHilt2_new, xHilt3_new, yHilt3_new, xHilt4_new, yHilt4_new;
  
  xHilt1_new = x + xR(xHilt1 - x, yHilt1 - y, deg);
  yHilt1_new = y + yR(xHilt1 - x, yHilt1 - y, deg);
  xHilt2_new = x + xR(xHilt2 - x, yHilt2 - y, deg);
  yHilt2_new = y + yR(xHilt2 - x, yHilt2 - y, deg);
  xHilt3_new = x + xR(xHilt3 - x, yHilt3 - y, deg);
  yHilt3_new = y + yR(xHilt3 - x, yHilt3 - y, deg);
  xHilt4_new = x + xR(xHilt4 - x, yHilt4 - y, deg);
  yHilt4_new = y + yR(xHilt4 - x, yHilt4 - y, deg);
  																						//DRAWING NEW HILT
  
  graphics_triangle_fill(xHilt1_new, yHilt1_new, 
                         xHilt3_new, yHilt3_new, 
                         xHilt2_new, yHilt2_new, 
                         134, 88, 0);
  graphics_triangle_fill(xHilt1_new, yHilt1_new, 
                         xHilt4_new, yHilt4_new, 
                         xHilt2_new, yHilt2_new, 
                         134, 88, 0);
  
  //graphics_rectangle_fill(xHilt1_new, yHilt1_new, xHilt2_new, yHilt2_new, 135, 88, 0);	//part across blade
  
  
  												//SWORD HANDLE
  int xHandle1, xHandle2, yHandle1, yHandle2, xHandle3, yHandle3, xHandle4, yHandle4;
  xHandle1 = x - handle_width;
  yHandle1 = y + hilt_height;
  xHandle2 = x + handle_width;
  yHandle2 = y + hilt_height + handle_height;
  xHandle3 = xHandle2;
  yHandle3 = yHandle1;
  xHandle4 = xHandle1;
  yHandle4 = yHandle2;
  
  												//NEW SWORD HANDLE
  int xHandle1_new, xHandle2_new, yHandle1_new, yHandle2_new, xHandle3_new, yHandle3_new, xHandle4_new, yHandle4_new;
  
  xHandle1_new = x + xR(xHandle1 - x, yHandle1 - y, deg);
  yHandle1_new = y + yR(xHandle1 - x, yHandle1 - y, deg);
  xHandle2_new = x + xR(xHandle2 - x, yHandle2 - y, deg);
  yHandle2_new = y + yR(xHandle2 - x, yHandle2 - y, deg);
  xHandle3_new = x + xR(xHandle3 - x, yHandle3 - y, deg);
  yHandle3_new = y + yR(xHandle3 - x, yHandle3 - y, deg);
  xHandle4_new = x + xR(xHandle4 - x, yHandle4 - y, deg);
  yHandle4_new = y + yR(xHandle4 - x, yHandle4 - y, deg);
  
  
  
  																//DRAWING NEW HANDLE
  graphics_triangle_fill(xHandle1_new, yHandle1_new,
                         xHandle3_new, yHandle3_new, 
                         xHandle2_new, yHandle2_new, 
                         134, 88, 0);
  
  graphics_triangle_fill(xHandle1_new, yHandle1_new, 
                         xHandle4_new, yHandle4_new,
                         xHandle2_new, yHandle2_new, 
                         134, 88, 0);
  
  //graphics_rectangle_fill(xHandle1_new, yHandle1_new, xHandle2_new, yHandle1_new, 135, 88, 0);	//handle part
  
  
  
  
 return; 
}



void draw_character(int x, int y, double theta, int r, int g, int b)
{
  double deg = theta * 3.14/180;
  double deg2 = -1*deg;
  int head_width = 30;
  int head_height = head_width;
  int torso_height = 60;
  int torso_width = 50;
  int yTorsoStart = y + head_height;
  int yLegStart = yTorsoStart + torso_height;
  int leg_height = 50;
  int leg_width = 30;
  //double leg_space = 2.5;
  
  //HEAD
  graphics_triangle_fill(x - head_width/2, y,
                         x + head_width/2, y,
                         x + head_width/2, y + head_height,
                         r, g, b);
  graphics_triangle_fill(x - head_width/2, y,
                         x - head_width/2, y + head_height,
                         x + head_width/2, y + head_height,
                         r, g, b);
  
  
  //TORSO
  graphics_triangle_fill(x - torso_width/2, yTorsoStart,
                         x + torso_width/2, yTorsoStart,
                         x + torso_width/2, yTorsoStart + torso_height,
                         r, g, b);
  graphics_triangle_fill(x - torso_width/2, yTorsoStart,
                         x - torso_width/2, yTorsoStart + torso_height,
                         x + torso_width/2, yTorsoStart + torso_height,
                         r, g, b);
  
  
  //LEGS
  /*
  graphics_triangle_fill(x - leg_width/2, yLegStart,		//left leg
                         x + leg_width/2, yLegStart,
                         x + leg_width/2, yLegStart + leg_height,
                         0, 150, 100);
  graphics_triangle_fill(x - leg_width/2, yLegStart,		//left leg
                         x - leg_width/2, yLegStart + leg_height,
                         x + leg_width/2, yLegStart + leg_height,
                         0, 150, 100);
  */
  
  /*
  graphics_triangle_fill(x - leg_width/2, yLegStart,		//left leg
                         x + leg_width/2, yLegStart,
                         x + leg_width/2, yLegStart + leg_height,
                         0, 0, 250);
  graphics_triangle_fill(x - leg_width/2, yLegStart,		//left leg
                         x - leg_width/2, yLegStart + leg_height,
                         x + leg_width/2, yLegStart + leg_height,
                         0, 0, 250);
  */
  
  int xLL1, yLL1, xLL2, yLL2, xLL3, yLL3, xLL4, yLL4;
  xLL1 = x - leg_width/2;
  yLL1 = yLegStart;
  xLL2 = x + leg_width/2;
  yLL2 = yLegStart;
  xLL3 = x + leg_width/2;
  yLL3 = yLegStart + leg_height;
  xLL4 = x - leg_width/2;
  yLL4 = yLegStart + leg_height;
  
  
  int xLL1_new, yLL1_new, xLL2_new, yLL2_new, xLL3_new, yLL3_new, xLL4_new, yLL4_new;
  
  xLL1_new = x + xR(xLL1 - x, yLL1 - yLegStart, deg);
  yLL1_new = yLegStart + yR(xLL1 - x, yLL1 - yLegStart, deg);
  xLL2_new = x + xR(xLL2 - x, yLL2 - yLegStart, deg);
  yLL2_new = yLegStart + yR(xLL2 - x, yLL2 - yLegStart, deg);
  xLL3_new = x + xR(xLL3 - x, yLL3 - yLegStart, deg);
  yLL3_new = yLegStart + yR(xLL3 - x, yLL3 - yLegStart, deg);
  xLL4_new = x + xR(xLL4 - x, yLL4 - yLegStart, deg);
  yLL4_new = yLegStart + yR(xLL4 - x, yLL4 - yLegStart, deg);
  
  
  graphics_triangle_fill(xLL1_new, yLL1_new,		//left leg
                         xLL2_new, yLL2_new,
                         xLL3_new, yLL3_new,
                         r, g, b);
  graphics_triangle_fill(xLL1_new, yLL1_new,
                         xLL4_new, yLL4_new,
                         xLL3_new, yLL3_new,
                         r, g, b);
  
  
  
  int xLL1_new1, yLL1_new1, xLL2_new1, yLL2_new1, xLL3_new1, yLL3_new1, xLL4_new1, yLL4_new1;
  
  xLL1_new1 = x + xR(xLL1 - x, yLL1 - yLegStart, deg2);
  yLL1_new1 = yLegStart + yR(xLL1 - x, yLL1 - yLegStart, deg2);
  xLL2_new1 = x + xR(xLL2 - x, yLL2 - yLegStart, deg2);
  yLL2_new1 = yLegStart + yR(xLL2 - x, yLL2 - yLegStart, deg2);
  xLL3_new1 = x + xR(xLL3 - x, yLL3 - yLegStart, deg2);
  yLL3_new1 = yLegStart + yR(xLL3 - x, yLL3 - yLegStart, deg2);
  xLL4_new1 = x + xR(xLL4 - x, yLL4 - yLegStart, deg2);
  yLL4_new1 = yLegStart + yR(xLL4 - x, yLL4 - yLegStart, deg2);
  
  
  graphics_triangle_fill(xLL1_new1, yLL1_new1,		//left leg
                         xLL2_new1, yLL2_new1,
                         xLL3_new1, yLL3_new1,
                         r, g, b);
  graphics_triangle_fill(xLL1_new1, yLL1_new1,
                         xLL4_new1, yLL4_new1,
                         xLL3_new1, yLL3_new1,
                         r, g, b);
  
  
  
  
  /*
  //LEGS
  
  graphics_triangle_fill(x - leg_width, yLegStart,		//left leg
                         x - leg_space, yLegStart,
                         x - leg_space, yLegStart + leg_height,
                         0, 150, 100);
  graphics_triangle_fill(x - leg_width, yLegStart,
                         x - leg_width, yLegStart + leg_height,
                         x - leg_space, yLegStart + leg_height,
                         0, 150, 100);
  
  graphics_triangle_fill(x + leg_width, yLegStart,		//right leg
                         x, yLegStart,
                         x, yLegStart + leg_height,
                         0, 150, 100);
  graphics_triangle_fill(x + leg_width, yLegStart,
                         x + leg_width, yLegStart + leg_height,
                         x, yLegStart + leg_height,
                         0, 150, 100);
  
  
  
  
  
  // moving leg
  int xLL1, yLL1, xLL2, yLL2, xLL3, yLL3, xLL4, yLL4;
  xLL1 = x - leg_width;
  yLL1 = yLegStart;
  xLL2 = x - leg_space;
  yLL2 = yLegStart;
  xLL3 = x - leg_space;
  yLL3 = yLegStart + leg_height;
  xLL4 = x - leg_width;
  yLL4 = yLegStart + leg_height;
  
  
  int xLL1_new, yLL1_new, xLL2_new, yLL2_new, xLL3_new, yLL3_new, xLL4_new, yLL4_new;
  
  xLL1_new = x + xR(xLL1 - x, yLL1 - yLegStart, deg);
  yLL1_new = yLegStart + yR(xLL1 - x, yLL1 - yLegStart, deg);
  xLL2_new = x + xR(xLL2 - x, yLL2 - yLegStart, deg);
  yLL2_new = yLegStart + yR(xLL2 - x, yLL2 - yLegStart, deg);
  xLL3_new = x + xR(xLL3 - x, yLL3 - yLegStart, deg);
  yLL3_new = yLegStart + yR(xLL3 - x, yLL3 - yLegStart, deg);
  xLL4_new = x + xR(xLL4 - x, yLL4 - yLegStart, deg);
  yLL4_new = yLegStart + yR(xLL4 - x, yLL4 - yLegStart, deg);
  
  
  graphics_triangle_fill(xLL1_new, yLL1_new,		//left leg
                         xLL2_new, yLL2_new,
                         xLL3_new, yLL3_new,
                         0, 150, 100);
  graphics_triangle_fill(xLL1_new, yLL1_new,
                         xLL4_new, yLL4_new,
                         xLL3_new, yLL3_new,
                         0, 150, 100);
  */
  return;
}



void colorPlayers(character players[])
{
  switch(players[0].color){
     case 'R': 
       players[0].r = 250;
       players[0].g = 0;
       players[0].b = 0;
       break;
    case 'Y':
      players[0].r = 244;
      players[0].g = 221;
      players[0].b = 0;
      break;
    case 'G':
      players[0].r = 111; 
      players[0].g = 242;
      players[0].b = 68;
      break;
    case 'O':
      players[0].r = 255;
      players[0].g = 130;
      players[0].b = 5;
      break;
    case 'B': 
      players[0].r = 38;
      players[0].g = 31;
      players[0].b = 240;
      break;
    case 'P':
      players[0].r = 255;
      players[0].g = 31;
      players[0].b = 154;
      break;
    case '&':
      players[0].r = rand() % 256;
      players[0].g = rand() % 256;
      players[0].b = rand() % 256;
      break;
    default:
      players[0].r = 0;
      players[0].g = 255;
      players[0].b = 0;
	  break;
   }
  
  
  
  
  switch(players[1].color){
     case 'R': 
       players[1].r = 250;
       players[1].g = 0;
       players[1].b = 0;
       break;
    case 'Y':
      players[1].r = 244;
      players[1].g = 221;
      players[1].b = 0;
      break;
    case 'G':
      players[1].r = 111; 
      players[1].g = 242;
      players[1].b = 68;
      break;
    case 'O':
      players[1].r = 255;
      players[1].g = 130;
      players[1].b = 5;
      break;
    case 'B': 
      players[1].r = 38;
      players[1].g = 31;
      players[1].b = 240;
      break;
    case 'P':
      players[1].r = 255;
      players[1].g = 31;
      players[1].b = 154;
      break;
    case '&':
      players[1].r = rand() % 256;
      players[1].g = rand() % 256;
      players[1].b = rand() % 256;
      break;
    default:
      players[1].r = 0;
      players[1].g = 255;
      players[1].b = 0;
	  break;
  }
  
  
  return;
}


void cloud(int x, int y, int r)
{
  
  graphics_circle_fill(x, y, r, 250, 250, 250);
  
  graphics_circle_fill(x + 30, y - 10, r, 250, 250, 250);
  graphics_circle_fill(x, y - 20, r, 250, 250, 250);
  graphics_circle_fill(x - 30, y -15, r, 250, 250, 250);
  
  
 return; 
}



  void sun(int x, int y, int r, double theta)
{
  int x1,x2,x3,y1,y2,y3;
  x1 = x -r;
  y1 = y;
  x2 = x + r;
  y2 = y;
  x3 = x;
  y3 = y+1.5*r;
  
  double x1n, x2n, x3n, y1n, y2n, y3n;	//New coordinates for triangles
  x1n = x + xR(x1 - x, y1 -y, theta);
  y1n = y + yR(x1 - x, y1 -y, theta);
  x2n = x + xR(x2 - x, y2 -y, theta);
  y2n = y + yR(x2 - x, y2 -y, theta);
  x3n = x + xR(x3 - x, y3 -y, theta);
  y3n = y + yR(x3 - x, y3 -y, theta);
  
  
  
  int t2x1,t2x2,t2x3,t2y1,t2y2,t2y3;
  t2x1 = x -r;
  t2y1 = y;
  t2x2 = x + r;
  t2y2 = y;
  t2x3 = x;
  t2y3 = y-1.5*r;
  
  double t2x1n, t2x2n, t2x3n, t2y1n, t2y2n, t2y3n; ////New coordinates for triangles
  t2x1n = x + xR(t2x1 - x, t2y1 -y, theta);
  t2y1n = y + yR(t2x1 - x, t2y1 -y, theta);
  t2x2n = x + xR(t2x2 - x, t2y2 -y, theta);
  t2y2n = y + yR(t2x2 - x, t2y2 -y, theta);
  t2x3n = x + xR(t2x3 - x, t2y3 -y, theta);
  t2y3n = y + yR(t2x3 - x, t2y3 -y, theta);
  
  int t3x1,t3x2,t3x3,t3y1,t3y2,t3y3;
  t3x1 = x;
  t3y1 = y+r;
  t3x2 = x;
  t3y2 = y-r;
  t3x3 = x-1.5*r;
  t3y3 = y;
  
  
  double t3x1n, t3x2n, t3x3n, t3y1n, t3y2n, t3y3n;	//New coordinates for triangles
  t3x1n = x + xR(t3x1 - x, t3y1 -y, theta);
  t3y1n = y + yR(t3x1 - x, t3y1 -y, theta);
  t3x2n = x + xR(t3x2 - x, t3y2 -y, theta);
  t3y2n = y + yR(t3x2 - x, t3y2 -y, theta);
  t3x3n = x + xR(t3x3 - x, t3y3 -y, theta);
  t3y3n = y + yR(t3x3 - x, t3y3 -y, theta);
  
  
  int t4x1,t4x2,t4x3,t4y1,t4y2,t4y3;
  t4x1 = x;
  t4y1 = y+r;
  t4x2 = x;
  t4y2 = y-r;
  t4x3 = x+1.5*r;
  t4y3 = y;
  
  double t4x1n, t4x2n, t4x3n, t4y1n, t4y2n, t4y3n;		//New coordinates for triangles
  t4x1n = x + xR(t4x1 - x, t4y1 -y, theta);
  t4y1n = y + yR(t4x1 - x, t4y1 -y, theta);
  t4x2n = x + xR(t4x2 - x, t4y2 -y, theta);
  t4y2n = y + yR(t4x2 - x, t4y2 -y, theta);
  t4x3n = x + xR(t4x3 - x, t4y3 -y, theta);
  t4y3n = y + yR(t4x3 - x, t4y3 -y, theta);
  
  graphics_circle_fill(x, y, r, 255, 248,31);
  graphics_triangle_fill(x1n, y1n, x2n, y2n, x3n, y3n, 255, 248,31);
  graphics_triangle_fill(t2x1n, t2y1n, t2x2n, t2y2n, t2x3n, t2y3n, 255, 248,31);
  graphics_triangle_fill(t3x1n, t3y1n, t3x2n, t3y2n, t3x3n, t3y3n, 255, 248,31);
  graphics_triangle_fill(t4x1n, t4y1n, t4x2n, t4y2n, t4x3n, t4y3n, 255, 248,31);
  
  
  return;
}
  


void flower( int x, int y, double s)				//Function for Flower
{
  int rad = 25;			// circle radius
  
  
  int width, height;							// Rectangle for flower stem
  width = 7.5 * s;
  height = 65 * s;
  graphics_rectangle_fill(x-width/2, y, x+width/2, y+height, 0, 170, 0); 
  
  
  
  
  int x1, x2, x3, y1, y2, y3;					// points for leaf 
  x1 = x - width/2;
  y1 = y + height/2;
  
  x2 = x1;
  y2 = y1 + height/4;
  				
  x3 = x1 - width;
  y3 = y2;
  
  graphics_triangle_fill(x1, y1, x2, y2, x3, y3, 0, 170, 0); 		//Leaf
  
  
  graphics_circle_fill(x-(rad/1.3 * s), y, rad/1.8*s, 255, 242, 0);				// Petals			
  graphics_circle_fill(x, y - (rad*s/ 1.3), rad/1.8*s, 255, 242, 0);
  graphics_circle_fill(x+(rad * s/ 1.3), y, rad/1.8*s, 255, 242, 0);
  graphics_circle_fill(x, y + (rad*s / 1.3), rad/1.8*s, 255, 242, 0);
  
  
  
  graphics_circle_fill(x, y, rad* .5 * s, 84, 42, 0); 							//Center of flower
  graphics_circle_fill(x, y, rad* .3 * s, 51, 26, 0);
  
  return;
}


void tree(int x, int y, int r)
{
  
  graphics_circle_fill(x, y, r, 50, 200, 80);
  
  graphics_circle_fill(x + 30, y - 10, r, 50, 200, 80);
  graphics_circle_fill(x, y - 20, r, 50, 200, 80);
  graphics_circle_fill(x - 30, y -15, r, 50, 200, 80);
  
  
 return; 
}



