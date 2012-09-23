/* 
 * File:   main.c
 * Author: Baldur
 *
 * Created on 22. September 2012, 16:18
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "console.h"
#include "cutscenes.h"
#include "adventure.h"



#define DLG_SJ			Cyan, "Stefan J."
#define DLG_CUST		Green, "Kunde"




enum {
	Adv_Beginning,
		Adv_Sorry_Hamwanich,
		Adv_Sorry_Gemuesetheke,
		Adv_OfferEiFon,

	Adv_Presenting_EiFon,
		Adv_Presenting_EiFon_TheNEWeiFon,
		Adv_Presenting_EiFon_FromTheFuhrer,
		Adv_Presenting_EiFon_SoBeautyful,

	Adv_Customer_Decision,

	Adv_Customer_WantsLTE,
	Adv_Customer_WantsLTE_Arguments,
	Adv_Customer_WantsLTE_Arg_Radiation,
	Adv_Customer_WantsLTE_Arg_NotSupportedByServers,
	Adv_Customer_WantsLTE_Arg_GetALife,

	Adv_Customer_WantsBiggerScreen,
	Adv_Customer_WantsBiggerScreen_Arguments,

	Adv_Customer_WantsFasterCPU,
	Adv_Customer_WantsFasterCPU_Arguments,

	Adv_Customer_WantsToBuy,

	Adv_Customer_Leaves,
};






/*
 * 
 */
int main(int argc, char** arg) {
	State state = Adv_Beginning;

	// initialize random number generator
	srand(time(NULL));

	int the_NEW_eiFon_count				= 0;
	int fuehrer_argument_used			= 0;
	int customer_wants_lte				= 1;
	int customer_wants_faster_cpu		= 1;
	int customer_wants_bigger_screen	= 1;

	int lte_arg_radiation_used			= 0;
	int lte_arg_serversupport_used		= 0;

	// make the cursor disappearing
	setCursorVisible(0);
	disableConsoleScrolling();
	
	playCutsceneIntro();

	do {
		switch(state) {
			//<editor-fold defaultstate="collapsed" desc=" Intro ">
			case Adv_Beginning: {
				Dialog dlg = { Cyan, "Stefan J",
								"Einen sch&ouml;nen guten Tag, mein Herr.\nWie kann ich behilflich sein?" }
				;

				Dialog dlg2 = { Green, "Ein potentieller Kunde",
								"Meinen Gru&szlig;, werter Herr Mobilfunktelefon-\nfachverk&auml;ufer!\n\n"
								"Ich w&auml;re an dem Erwerb eines neuen Mobilfunktelefons\ninteressiert." }
				;

				playDialog(dlg);
				playDialog(dlg2);

				Choice a = { Adv_Sorry_Hamwanich,    "Tut mir leid, so etwas gibt es hier nicht." };
				Choice b = { Adv_Sorry_Gemuesetheke, "Tut mir leid, das hier ist die Gem&uuml;setheke." };
				Choice c = { Adv_OfferEiFon,         "Ich hab hier was f&uuml;r Sie." };
				state = selectChoice(3, &a, &b, &c);

				break;
			}

			case Adv_Sorry_Hamwanich: {
				Dialog dlg = { DLG_SJ, "Tut mir leid, derartige Ware f&uuml;hren wir hier nicht." };
				playDialog(dlg);

				state = Adv_Customer_Leaves;

				break;
			}

			case Adv_Sorry_Gemuesetheke: {
				Dialog dlg = { DLG_SJ, "Tut mir leid, hier ist die Gem&uuml;setheke.\n"
										"Versuchen Sie es später noch einmal."
				};
				playDialog(dlg);

				state = Adv_Customer_Leaves;

				break;
			}
				
			case Adv_Customer_Leaves: {
				sleepSeconds(1);

				Dialog dlg = { Green, "Kunde",
								"Oh, wenn das so ist, suche ich woanders mein Gl&uuml;ck.\n"
								"Auf wiedersehen."
				};

				playCutsceneOutro_JustGoing(dlg);

				return (EXIT_FAILURE);
			}

			case Adv_OfferEiFon: {
				Dialog dlg1 = { DLG_SJ,
								"Ah! Hier sind Sie genau richtig!\n\n"
								"Wir haben hier das neue eiFon, welches soeben frisch in diesen\n"
								"bescheidenen Laden geliefert wurde.\n"
								"Es gibt derzeit nichts vergleichbares auf der Welt."
				};

				Dialog dlg2 = { DLG_CUST,
								"Mein Herr, sie belieben zu scherzen?\n"
								"Ich glaube kaum, da&szlig; dieses Ger&auml;t meinen "
								"Anforderungen gerecht werden\nk&ouml;nnte."
				};

				playDialog(dlg1);
				playDialog(dlg2);

				state = Adv_Presenting_EiFon;

				break;
			}

			case Adv_Presenting_EiFon: {
				Choice c1 = { Adv_Presenting_EiFon_TheNEWeiFon,
								"Es ist das NEUE eiFon!"
				};
				Choice c2 = { Adv_Presenting_EiFon_FromTheFuhrer,
								"Dieses eiFon wurde von unserem F&uuml;hrer "
								"h&ouml;chstpers&ouml;nlich angefertigt."
				};
				Choice c3 = { Adv_Presenting_EiFon_SoBeautyful,
								"Dieses eiFon besticht durch seine Sch&ouml;nheit und Eleganz."
				};

				if (fuehrer_argument_used) {
					state = selectChoice(2, &c1, &c3);
				}
				else {
					state = selectChoice(3, &c1, &c2, &c3);
				}

				break;
			}

			case Adv_Presenting_EiFon_FromTheFuhrer: {
				// this option resets the NEW eiFon counter.
				the_NEW_eiFon_count = 0;

				// the fuehrer argument cannot be used any more.
				fuehrer_argument_used = 1;

				Dialog dlg1 = { DLG_SJ,
								"Dieses eiFon wurde von unserem F&uuml;hrer "
								"h&ouml;chstpers&ouml;nlich angefertigt.\n\n"
								"Es tr&auml;gt den Geist des Gro&szlig;en Meisters in sich.\n\n"
								"*ein Scheinwerfer wirft dabei einen markanten Lichtkegel auf das\neiFon herab*"
				};

				Dialog dlg2 = { DLG_CUST,
								"Ah... gewiss...\n"
								"*Der Kunde betrachtet einen Moment lang das eiFon "
								"mit einem and&auml;chtigem Blick*\n\n"
								"Doch was kann mir dieses Ger&auml;t nun bieten, "
								"damit ich einen Kauf in\n"
								"Erw&auml;gung ziehen k&ouml;nnte?"
				};

				playDialog(dlg1);
				playDialog(dlg2);

				state = Adv_Presenting_EiFon;

				break;
			}

			case Adv_Presenting_EiFon_TheNEWeiFon: {
				++the_NEW_eiFon_count;

				state = Adv_Presenting_EiFon;

				Dialog dlg1 = { DLG_SJ,
								"Es ist das NEUE eiFon!"
				};

				playDialog(dlg1);

				switch(the_NEW_eiFon_count) {
					case 1: {
						Dialog dlg2 = { DLG_CUST,
										"Ja.. gewiss ist es besser als das alte, aber..."
						};

						playDialog(dlg2);

						break;
					}

					case 2: {
						Dialog dlg2 = { DLG_CUST,
										"Nun, das sagten Sie bereits..."
						};

						playDialog(dlg2);

						break;
					}

					case 3: {
						Dialog dlg2 = { DLG_CUST,
										"Ich verstehe, aber was sind Ihre Argumente?"
						};

						playDialog(dlg2);

						break;
					}

					case 4: {
						Dialog dlg2 = { DLG_CUST,
										"Mein Herr, Sie scheinen mir reichlich verwirrt."
						};

						playDialog(dlg2);

						break;
					}

					case 5: {
						playCutsceneOutro_CallMeAnAmbulance();
						return (EXIT_FAILURE);
					}
				}

				break;
			}

			case Adv_Presenting_EiFon_SoBeautyful: {
				Dialog dlg1 = { DLG_SJ,
								"Dieses eiFon besticht durch seine Sch&ouml;nheit und Eleganz.\n"
								"Durch dieses Kunstwerk werden Sie sich von der Masse an ordin&auml;ren\n"
								"Mobilfunktelefonen abheben und der Mittelpunkt eines jeden\n"
								"gesellschaftlichen Ereignisses darstellen."
				};

				Dialog dlg2 = { DLG_CUST,
								"Ja, da haben Sie recht.\n"
								"Ich will ja schlie&szlig;lich auch mit einem ganz besonderem Exemplar "
								"meinen individuellen Geschmack ausdr&uuml;cken."
				};

				playDialog(dlg1);
				playDialog(dlg2);

				state = Adv_Customer_Decision;

				break;
			}

			case Adv_Customer_Decision: {
				State possibilities[10];
				int poss_count = 0;

				if (customer_wants_lte) {
					possibilities[poss_count] = Adv_Customer_WantsLTE;
					++poss_count;
				}

			//	if (customer_wants_bigger_screen) {
			//		possibilities[poss_count] = Adv_Customer_WantsBiggerScreen;
			//		++poss_count;
			//	}

			//	if (customer_wants_faster_cpu) {
			//		possibilities[poss_count] = Adv_Customer_WantsFasterCPU;
			//		++poss_count;
			//	}

				if (poss_count) {
					int r = abs(rand()) % poss_count;
					state = possibilities[r];
				}
				else {
					state = Adv_Customer_WantsToBuy;
				}

				break;
			}
			//</editor-fold>

			//<editor-fold defaultstate="collapsed" desc=" Customer wants LTE ">
			case Adv_Customer_WantsLTE: {
				Dialog dlg1 = { DLG_CUST,
								"Nun, ich hoffe, dieses Ger&auml;t ist auch in der Lage, "
								"mit Hilfe der neuesten Mobilfunktechnologien zu kommunizieren, "
								"damit ich auch am gesellschaftlichen Leben teilnehmen "
								"und mich mit meinen Kontakten unterhalten kann."
				};

				playDialog(dlg1);
				state = Adv_Customer_WantsLTE_Arguments;

				break;
			}

			case Adv_Customer_WantsLTE_Arguments: {
				Choice c1 = { Adv_Customer_WantsLTE_Arg_Radiation,
								"Denken Sie an die gef&auml;hrliche Strahlung."
				};

				Choice c2 = { Adv_Customer_WantsLTE_Arg_NotSupportedByServers,
								"Bedenken Sie, da&szlig; viele Server das gar nicht unterst&uuml;tzen."
				};

				Choice c3 = { Adv_Customer_WantsLTE_Arg_GetALife,
								"Es gibt auch ein Leben au&szlig;erhalb des Internets."
				};

				break;
			}
			//</editor-fold>

			case Adv_Customer_WantsToBuy: {
				printf("almost won...");
				return (EXIT_SUCCESS);
				break;
			}
		}
	}
	while(1);

	return (EXIT_SUCCESS);
}

