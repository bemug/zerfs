#ifndef __BALL__
#define __BALL__

class Hero;

class Ball {
	private:
		int x;
		int y;
		Hero *hero;
		
	public:
		Ball(int, int);
};

#endif
