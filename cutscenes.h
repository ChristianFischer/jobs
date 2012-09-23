/* 
 * File:   cutscenes.h
 * Author: Baldur
 *
 * Created on 23. September 2012, 00:33
 */

#ifndef CUTSCENES_H
#define	CUTSCENES_H

#include "adventure.h"


#ifdef	__cplusplus
extern "C" {
#endif

	void playCutsceneIntro();

	void playCutsceneOutro_JustGoing(Dialog dlg);
	void playCutsceneOutro_CallMeAnAmbulance();
	void playCutsceneOutro_Flaming();

	void playCutsceneOutro_Won();


#ifdef	__cplusplus
}
#endif

#endif	/* CUTSCENES_H */

