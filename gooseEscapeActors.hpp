/*
START OF gooseEscapeActors.hpp
*/

#ifndef GOOSE_ESCAPE_ACTORS
#define GOOSE_ESCAPE_ACTORS
#include <iostream>
#include <cmath>
#include <BearLibTerminal.h>
#include <time.h>
#include "gooseEscapeUtil.hpp"

using namespace std;

//General actor class with code that apply to all moving elements in the game
class Actor
{  	
  protected: 
	int actorChar;      
    int location_x, location_y;

  public:
	Actor();
    Actor(char initPlayerChar, int x0, int y0);
    
    int get_x() const;
    int get_y() const;
    string get_location_string() const;
    
    void change_char(char new_actor_char);
    bool can_move(int delta_x, int delta_y) const;
    void update_location(int delta_x, int delta_y);
    void put_actor() const;
};

//child classes of the Actor class that give properties to different characters

//just initializes player with its proper character
class Protagonist : public Actor
{
  public:
	Protagonist();
	Protagonist(int x0, int y0);
};

//goose, monster that chases protagonist and flies over walls
class Flier : public Actor
{	
  public: 	
	Flier();
	Flier(int x0, int y0);
	
	//function to chase the player over walls 
	void chase(Actor & player, int game_board[NUM_BOARD_Y][NUM_BOARD_X], int turn);
};

//moose bounces from wall to wall
class Bouncer : public Actor
{
  private:
	int move_sign;
	bool horizontal;

  public:
	Bouncer();
	Bouncer(int x0, int y0);
    
    void bounce(int game_board[NUM_BOARD_Y][NUM_BOARD_X]);
};

#endif

/*

------------------------------------
END OF gooseEscapeActors.hpp
------------------------------------

*/
