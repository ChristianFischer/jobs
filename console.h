/* 
 * File:   console.h
 * Author: Baldur
 *
 * Created on 22. September 2012, 16:32
 */

#ifndef CONSOLE_H
#define	CONSOLE_H

#ifdef	__cplusplus
extern "C" {
#endif


	enum TextColor {
		Black,
		DarkBlue,
		DarkGreen,
		DarkCyan,
		DarkRed,
		DarkMagenta,
		DarkYellow,
		LightGray,
		DarkGray,
		LightBlue,
		LightGreen,
		LightCyan,
		LightRed,
		LightMagenta,
		LightYellow,
		White,


		Blue		= DarkBlue,
		Green		= DarkGreen,
		Red			= DarkRed,
		Magenta		= DarkMagenta,
		Pink		= LightMagenta,
		Brown		= DarkYellow,
		Yellow		= LightYellow,
		Cyan		= LightCyan,
	};



	void clearScreen();


	void setCursorVisible(int visible);


	void disableConsoleScrolling();


	void setCursorPosition(unsigned short x, unsigned short y);


	void getCursorPosition(unsigned short *x, unsigned short *y);


	void setTextColor(enum TextColor foreground, enum TextColor background);


	void sleepSeconds(int seconds);
	void sleepMilliSeconds(int seconds);


	char waitForKey();


#ifdef	__cplusplus
}
#endif

#endif	/* CONSOLE_H */

