/************************************************************************************
 * This file was developed as part of CS3841 Design of Operating Systems at the
 * Milwaukee School of Engineering.  This file is copyright 2008-2015 by MSOE.
 *
 * $Author: wws $
 * $Revision: 1.1 $
 * $Name:  $
 * This file manages the motion of the users paddle.  It is responsible for
 * reading commands from the keyboard and processing them appropriately.
 *
 ************************************************************************************/
#define PADDLECTRL_C

/************************************************************************************
 * External Includes
 ************************************************************************************/
#include <curses.h>
#include <pthread.h>
#include "pong.h"
#include "ballctrl.h"
#include <unistd.h>

/************************************************************************************
 * Private structure / type definitions
 ************************************************************************************/
#define PADDLE_SIZE (5)

/************************************************************************************
 * Private function / method prototypes
 ************************************************************************************/
static void drawPaddle(int center);
static void undrawPaddle(int center);

/************************************************************************************
 * Constant declarations / table declarations
 ***********************************************************************************/
int maxx;
/************************************************************************************
 * Method header:
 * Function name: drawPaddle
 * Function purpose: This function is responsible for drawing the paddle on the screen.
 * Function parameters:
 *                   int center - This is an integer value representing the center of
 *                                the paddle.
 * Function return value: None
 ************************************************************************************/
static void drawPaddle(int center) {
	int i;

	for (i = center - (PADDLE_SIZE / 2); i <= center + (PADDLE_SIZE / 2); i++) {
		move(i, maxx);
		addch('|');
	}
}

/************************************************************************************
 * Method header:
 * Function name: undrawPaddle
 * Function purpose: This function is responsible for undrawing the paddle on the screen.
 * Function parameters:
 *                   int center - This is an integer value representing the center of
 *                                the paddle.
 * Function return value: None
 ************************************************************************************/
static void undrawPaddle(int center) {
	int i;

	for (i = center - (PADDLE_SIZE / 2); i <= center + (PADDLE_SIZE / 2); i++) {
		move(i, maxx);
		addch(' ');
	}
}

/************************************************************************************
 * Method header:
 * Function name: moveme
 * Function purpose: This function is responsible for moving the users paddle.
 *                   It is spawned as a thread and ewill exit if and when quit is no longer true.
 * Function parameters:
 *                   void *vp - This is a pointer to the parameters passed into the
 *                              thread.  At the present time, this parameter is not used.
 * Function return value: void* This is the return value when the thread exits.
 *                              Currently, it is always NULL, as no data is directly
 *                              returned by the thread.
 ************************************************************************************/
// Run the user's paddle
void *moveme2(void* vp) {
	int ch;

	// get the extents of the screen

	int maxy;

	getmaxyx(win, maxy, maxx);

	int vpos = maxy / 2;
	maxx -= 3; //player two is on the opposite side of the board
	// draw the default paddle
	drawPaddle(vpos);

	if (comcontrol2 == 1) {
		int basecomdelay = 1000000 / difficulty; //change speed based on difficulty if computer controlled
		while (!quit) {
			noecho();
			if (vpos > bally) { // The user has pressed the up arrow.  Move the paddle one pixel upwards if possible.
				undrawPaddle(vpos);
				vpos--;
				if (vpos < PADDLE_SIZE / 2 + 3) {
					vpos = PADDLE_SIZE / 2 + 3;
				}
				drawPaddle(vpos);
			} else if (vpos > bally) { // The user has pressed the down arrow.  Move the paddle one pixel downward if possible.
				undrawPaddle(vpos);
				vpos++;
				if (vpos > ((maxy - 2) - (PADDLE_SIZE / 2))) {
					vpos = ((maxy - 2) - (PADDLE_SIZE / 2));
				}
				drawPaddle(vpos);
			}
			usleep(basecomdelay);
		}
	} else {
		while (!quit) {
			noecho();
			ch = getch();
			switch (ch) {

			case 'w': // The user has pressed the w key.  Move the paddle one pixel upwards if possible.
				undrawPaddle(vpos);
				vpos--;
				if (vpos < PADDLE_SIZE / 2 + 3) {
					vpos = PADDLE_SIZE / 2 + 3;
				}
				drawPaddle(vpos);
				break;
			case 's': // The user has pressed the s key.  Move the paddle one pixel downward if possible.
				undrawPaddle(vpos);
				vpos++;
				if (vpos > ((maxy - 2) - (PADDLE_SIZE / 2))) {
					vpos = ((maxy - 2) - (PADDLE_SIZE / 2));
				}
				drawPaddle(vpos);
				break;
			case 'q': // The user has pressed the quiz button.  Exit the game.
				quit = true;
				break;
			default:
				break;
			}
		}
	}
	return NULL;
}

