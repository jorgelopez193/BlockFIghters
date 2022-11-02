typedef struct character_struct{
 
 char color;
 int r, g, b;
 int x;
 int y;
 double theta;
 int jumptracker;		//prevents double jumping
 int jump_rate;			
 int boundary;			//security measure, set to zero if at a boundary, prevents movement in y direction
 int theta_rate;
 int charwidth;
 int swordDirection;
 int swordtheta;
 int direction;
 int swordtheta_rate;
 int y1OG;
 int collision;
 int swordtipx;
 int swordtipy;
 int HP;
 int lives;
 char initials[5];
 int attacktracker;
  
}character;
