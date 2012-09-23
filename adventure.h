/* 
 * File:   adventure.h
 * Author: Baldur
 *
 * Created on 23. September 2012, 03:19
 */

#ifndef ADVENTURE_H
#define	ADVENTURE_H

#include "console.h"

#ifdef	__cplusplus
extern "C" {
#endif


	typedef unsigned int State;


	typedef struct {
		enum TextColor	char_color;
		const char*		char_name;
		const char*		message;

	} Dialog;



	typedef struct {
		State			state;
		const char*		title;

	} Choice;



	Dialog mkDialog(enum TextColor color, const char *char_name, const char *mnessage);
	Choice mkChoice(State state, const char *message);



	void playDialog(Dialog dlg);



	State selectChoice(int num, ...);


#ifdef	__cplusplus
}
#endif

#endif	/* ADVENTURE_H */

