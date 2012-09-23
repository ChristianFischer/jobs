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
	Adv_Customer_WantsLTE_Done,

	Adv_Customer_WantsBiggerScreen,
	Adv_Customer_WantsBiggerScreen_Arguments,
	Adv_Customer_WantsBiggerScreen_Arg_Ergnomy,
	Adv_Customer_WantsBiggerScreen_Arg_MoviesFitScreen,
	Adv_Customer_WantsBiggerScreen_Arg_BagsDontFit,
	Adv_Customer_WantsBiggerScreen_Done,

	Adv_Customer_WantsFasterCPU,
	Adv_Customer_WantsFasterCPU_Arguments,

	Adv_Customer_WantsToBuy,
	Adv_Customer_WantsToBuy_Decision,
	Adv_Customer_WantsToBuy_MadeInChina,
	Adv_Customer_WantsToBuy_Soul,
	Adv_Customer_WantsToBuy_Price,
	Adv_Customer_WantsToBuy_Price_Crazy,
	Adv_Customer_WantsToBuy_Price_Sparabo,
	Adv_Customer_WantsToBuy_Price_Sparabo_Yes,
	Adv_Customer_WantsToBuy_Price_Sparabo_No,
	Adv_Customer_WantsToBuy_Price_SorryNeed,
	Adv_Customer_WantsToBuy_iMovie,
	Adv_Customer_WantsToBuy_iMovie_Fuehrer,
	Adv_Customer_WantsToBuy_iMovie_Movies,
	Adv_Customer_WantsToBuy_iMovie_Offer,

	Adv_Customer_Leaves,
};






int theGame() {
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

	int screen_arg_ergonomy_used		= 0;
	int screen_arg_movies_used			= 0;
	int screen_arg_bags_used			= 0;

	int buying_made_in_china_avail		= 1;
	int buying_price_ok					= 0;
	int buying_soul_ok					= 0;
	int buying_imovie_ok				= 0;

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
										"Versuchen Sie es sp&auml;ter noch einmal."
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

				state = selectChoice(
								3,
								&c1,
								(fuehrer_argument_used ? NULL : &c2),
								&c3
				);

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

				if (customer_wants_bigger_screen) {
					possibilities[poss_count] = Adv_Customer_WantsBiggerScreen;
					++poss_count;
				}

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
								"mit Hilfe der\nneuesten Mobilfunktechnologien zu kommunizieren, "
								"damit ich auch am\ngesellschaftlichen Leben teilnehmen "
								"und mich mit meinen Kontakten\naustauschen kann."
				};

				playDialog(dlg1);
				state = Adv_Customer_WantsLTE_Arguments;

				break;
			}

			case Adv_Customer_WantsLTE_Arguments: {
				if (lte_arg_radiation_used && lte_arg_serversupport_used) {
					Dialog dlg = { DLG_CUST,
									"Ich denke Sie haben Recht.\n"
									"Vermutlich sollte ich auf eine solch gef&auml;hrliche und unn&uuml;tze\n"
									"Technologie besser verzichten."
					};

					playDialog(dlg);

					customer_wants_lte = 0;

					state = Adv_Customer_Decision;
				}
				else {
					Choice c1 = { Adv_Customer_WantsLTE_Arg_Radiation,
									"Denken Sie an die gef&auml;hrliche Strahlung."
					};

					Choice c2 = { Adv_Customer_WantsLTE_Arg_NotSupportedByServers,
									"Bedenken Sie, da&szlig; viele Anbieter das gar nicht unterst&uuml;tzen."
					};

					Choice c3 = { Adv_Customer_WantsLTE_Arg_GetALife,
									"F&uuml;r ein gesellschaftliches Leben ist das doch gar nicht notwendig."
					};

					state = selectChoice(
									3,
									(lte_arg_radiation_used ? NULL : &c1),
									(lte_arg_serversupport_used ? NULL : &c2),
									&c3
					);
				}

				break;
			}

			case Adv_Customer_WantsLTE_Arg_Radiation: {
				Dialog dlg1 = { DLG_SJ,
								"Denken Sie an die gef&auml;hrliche Strahlung, welche durch diese Art\n"
								"von Funkwellen verursacht wird.\n"
								"Sie l&auml;sst Ihre Testikel schrumpfen und Ihr Gehirn kochen.\n"
								"Das wollen Sie doch nicht ernsthaft riskieren?"
				};

				Dialog dlg2 = { DLG_CUST,
								"Grundg&uuml;tiger!\nDas ist mir bisher noch gar nicht in den Sinn gekommen."
				};

				playDialog(dlg1);
				playDialog(dlg2);

				lte_arg_radiation_used = 1;
				state = Adv_Customer_WantsLTE_Arguments;

				break;
			}

			case Adv_Customer_WantsLTE_Arg_NotSupportedByServers: {
				Dialog dlg1 = { DLG_SJ,
								"Bedenken Sie, da&szlig; viele Anbieter das gar nicht unterst&uuml;tzen.\n"
								"Hierbei geht es ausschlie&szlig;lich darum, da&szlig; Telekommunikations-\ntechnologieanbieter "
								"ihren Kunden f&uuml;r teuer Geld Dinge aufschwatzen wollen, die sie gar nicht ben&ouml;tigen."
				};

				Dialog dlg2 = { DLG_CUST,
								"Hm.. im Grunde Stimme ich Ihnen da zu..."
				};

				playDialog(dlg1);
				playDialog(dlg2);

				lte_arg_serversupport_used = 1;
				state = Adv_Customer_WantsLTE_Arguments;

				break;
			}

			case Adv_Customer_WantsLTE_Arg_GetALife: {
				Dialog dlg1 = { DLG_SJ,
								"F&uuml;r ein gesellschaftliches Leben ist die Art der\nKommunikationstechnologie "
								"doch im Grunde unerheblich.\n"
								"Schlie&szlig;lich sollte man seine Kontakte ja nicht nur &uuml;ber "
								"soziale\nNetzwerke pflegen."
				};

				Dialog dlg2 = { DLG_CUST,
								"Haha... Sie sind lustig...\n\n"
								"Kommen Sie erst einmal im 21. Jahrhundert an!"
				};

				playDialog(dlg1);
				sleepSeconds(1);

				playCutsceneOutro_JustGoing(dlg2);

				return (EXIT_FAILURE);
			}
			//</editor-fold>

			//<editor-fold defaultstate="collapsed" desc=" Customer wants bigger screen ">
			case Adv_Customer_WantsBiggerScreen: {
				Dialog dlg1 = { DLG_CUST,
								"Allerdings fiel mir doch auf, da&szlig; dieses Ger&auml;t im Vergleich "
								"zu anderen einen doch recht kleinen Bildschirm besitzt.\n"
								"Wie soll man denn in der Lage sein, hiermit Kinofilme in ihrer besten\n"
								"Qualit&auml;t genie&szlig;en zu k&ouml;nnen?"
				};

				playDialog(dlg1);
				state = Adv_Customer_WantsBiggerScreen_Arguments;

				break;
			}

			case Adv_Customer_WantsBiggerScreen_Arguments: {
				if (screen_arg_ergonomy_used && screen_arg_movies_used) {
					Dialog dlg = { DLG_CUST,
									"Nun, jetzt wo Sie das sagen...\n"
									"Offentsichlich haben die Entwickler dieses guten St&uuml;cks "
									"doch sehr\nintensiv dar&uuml;ber nachgedacht."
					};

					playDialog(dlg);

					customer_wants_bigger_screen = 0;

					state = Adv_Customer_Decision;
				}
				else {
					Choice c1 = { Adv_Customer_WantsBiggerScreen_Arg_Ergnomy,
									"Die Gr&ouml;&szlig;e des eiFons wurde auf bestm&ouml;gliche Ergonomie hin angepasst."
					};

					Choice c2 = { Adv_Customer_WantsBiggerScreen_Arg_MoviesFitScreen,
									"Wir bieten speziell angepasste eiFilme f&uuml;r optimale Bildqualit&auml;t an."
					};

					Choice c3 = { Adv_Customer_WantsBiggerScreen_Arg_BagsDontFit,
									"Gr&ouml;&szlig;ere Telefone passen nicht mehr in die meisten Taschen."
					};

					state = selectChoice(
									3,
									(screen_arg_ergonomy_used ? NULL : &c1),
									(screen_arg_movies_used ? NULL : &c2),
									(screen_arg_bags_used ? NULL : &c3)
					);
				}

				break;
			}

			case Adv_Customer_WantsBiggerScreen_Arg_Ergnomy: {
				Dialog dlg1 = { DLG_SJ,
								"Die Gr&ouml;&szlig;e des eiFons wurde auf bestm&ouml;gliche Ergonomie hin\nangepasst.\n"
								"So ist sichergestellt, da&szlig; es ein jeder bequem in einer Hand zu\nhalten vermag."
				};

				Dialog dlg2 = { DLG_CUST,
								"Nat&uuml;rlich - das ist ja auch wichtig."
				};

				playDialog(dlg1);
				playDialog(dlg2);

				screen_arg_ergonomy_used = 1;
				state = Adv_Customer_WantsBiggerScreen_Arguments;

				break;
			}

			case Adv_Customer_WantsBiggerScreen_Arg_MoviesFitScreen: {
				Dialog dlg1 = { DLG_SJ,
								"Wir bieten speziell angepasste eiFilme f&uuml;r optimale Bildqualit&auml;t\nan. "
								"Bei all diesen Filmen wird ihnen der Unterschied zur\nKinoleinwand kaum auffallen."
				};

				Dialog dlg2 = { DLG_CUST,
								"Tats&auml;chlich?"
				};

				playDialog(dlg1);
				playDialog(dlg2);

				screen_arg_movies_used = 1;
				state = Adv_Customer_WantsBiggerScreen_Arguments;

				break;
			}

			case Adv_Customer_WantsBiggerScreen_Arg_BagsDontFit: {
				Dialog dlg1 = { DLG_SJ,
								"Wir haben eine Studie durchgef&uuml;hrt, die ergab, da&szlig; diese "
								"Gr&ouml;&szlig;e den\nverf&uuml;gbaren Platz der meisten Taschen optimal "
								"ausnutzt.\n"
								"Somit werden sie keinerlei Transportprobleme mit Ihrem Mobilfunk-\ntelefon bekommen."
				};

				Dialog dlg2 = { DLG_CUST,
								"An so etwas habe ich bisher noch gar nicht gedacht."
				};

				playDialog(dlg1);
				playDialog(dlg2);

				screen_arg_bags_used = 1;
				state = Adv_Customer_WantsBiggerScreen_Arguments;

				break;
			}
			//</editor-fold>

			//<editor-fold defaultstate="collapsed" desc=" Customer wants to buy ">
			case Adv_Customer_WantsToBuy: {
				Dialog dlg1 = { DLG_CUST,
								"Ich denke, Sie haben mich &uuml;berzeugt.\n"
								"Was wird es mich kosten, um dieses Wunderwerk "
								"deutscher Ingenieurs-\nkunst mein Eigen nennen zu k&ouml;nnen?"
				};
				
				playDialog(dlg1);
				
				state = Adv_Customer_WantsToBuy_Decision;

				break;
			}

			case Adv_Customer_WantsToBuy_Decision: {
				Choice c1 = { Adv_Customer_WantsToBuy_MadeInChina,
								"Sagten Sie \"deutsche Ingenieurskunst\"?"
				};
				Choice c2 = { Adv_Customer_WantsToBuy_Price,
								"Nur ein kleines Verm&ouml;gen..."
				};
				Choice c3 = { Adv_Customer_WantsToBuy_Soul,
								"Da w&auml;re noch der Vertrag bez&uuml;glich Eurer Seele..."
				};
				Choice c4 = { Adv_Customer_WantsToBuy_iMovie,
								"Au&szlig;erdem w&auml;re da noch unser eiFilm Abonnement..."
				};

				state = selectChoice(
							4,
							(buying_made_in_china_avail ? &c1 : NULL),
							(buying_price_ok ? NULL : &c2),
							(buying_soul_ok  ? NULL : &c3),
							(buying_imovie_ok ? NULL : &c4)
				);

				// only available the first time
				buying_made_in_china_avail = 0;

				break;
			}

			case Adv_Customer_WantsToBuy_MadeInChina: {
				Dialog dlg1 = { DLG_SJ,
								"Sagten Sie \"deutsche Ingenieurskunst\"?\n"
								"Nun, eigentlich lassen wir diese Apparate billig in China fertigen."
				};
				Dialog dlg2 = { DLG_CUST,
								"Oh, wenn das so ist, suche ich mir ein anderes Fachgesch&auml;ft,\n"
								"bei dem ich besser die heimische Wirtschaft st&auml;rken kann."
				};

				playDialog(dlg1);
				sleepSeconds(1);
				playCutsceneOutro_JustGoing(dlg2);

				return (EXIT_FAILURE);
			}

			case Adv_Customer_WantsToBuy_Price: {
				Dialog dlg1 = { DLG_SJ,
								"Nur ein kleines Verm&ouml;gen..."
				};
				Dialog dlg2 = { DLG_CUST,
								"WAS? Sind Sie verr&uuml;ckt?"
				};

				Choice c1 = { Adv_Customer_WantsToBuy_Price_Crazy,
								"Definitiv!"
				};
				Choice c2 = { Adv_Customer_WantsToBuy_Price_Sparabo,
								"F&uuml;r Sie lege ich noch ein Jumba-Sparabo oben drauf."
				};
				Choice c3 = { Adv_Customer_WantsToBuy_Price_SorryNeed,
								"Tut mir leid, da kann ich nichts machen."
				};

				playDialog(dlg1);
				playDialog(dlg2);
				state = selectChoice(3, &c1, &c2, &c3);

				break;
			}

			case Adv_Customer_WantsToBuy_Price_Crazy: {
				Dialog dlg1 = { DLG_SJ,
								"Definitiv!"
				};

				playDialog(dlg1);
				sleepSeconds(1);
				state = Adv_Customer_Leaves;

				break;
			}

			case Adv_Customer_WantsToBuy_Price_Sparabo: {
				Dialog dlg1 = { DLG_SJ,
								"F&uuml;r Sie lege ich noch ein Jumba-Sparabo oben drauf.\n"
								"Im ersten Monat kostenlos!"
				};
				Dialog dlg2 = { DLG_CUST,
								"Sie meinen, ich kann damit jeden Monat bares Geld sparen?"
				};

				Choice c1 = { Adv_Customer_WantsToBuy_Price_Sparabo_Yes,
								"Aber sicher!"
				};
				Choice c2 = { Adv_Customer_WantsToBuy_Price_Sparabo_No,
								"Ha ha ha"
				};

				playDialog(dlg1);
				playDialog(dlg2);

				state = selectChoice(2, &c1, &c2);

				break;
			}

			case Adv_Customer_WantsToBuy_Price_Sparabo_Yes: {
				Dialog dlg1 = { DLG_SJ,
								"Aber sicher!\n"
								"Ich kann gar nicht in Worte fassen, welche Reicht&uuml;mer sich Ihnen\n"
								"hiermit er&ouml;ffnen."

				};

				playDialog(dlg1);

				state = Adv_Customer_WantsToBuy_Decision;
				buying_price_ok = 1;

				break;
			}

			case Adv_Customer_WantsToBuy_Price_Sparabo_No: {
				Dialog dlg1 = { DLG_CUST,
								"Ha ha ha ...\n"
								"*der Verk&auml;ufer wischt sich eine Lachtr&auml;ne aus dem Auge*\n\n"
								"Nun, genaugenommen ist das alles nur Betrug..."
				};

				playDialog(dlg1);
				sleepSeconds(1);
				state = Adv_Customer_Leaves;

				break;
			}

			case Adv_Customer_WantsToBuy_Price_SorryNeed: {
				Dialog dlg1 = { DLG_CUST,
								"Tut mir leid, da kann ich nichts machen.\n"
								"Das Benzin f&uuml;r meine Yachten ist teuer geworden..."
				};

				playDialog(dlg1);
				sleepSeconds(1);
				state = Adv_Customer_Leaves;

				break;
			}

			case Adv_Customer_WantsToBuy_iMovie: {
				Dialog dlg1 = { DLG_SJ,
								"Au&szlig;erdem w&auml;re da noch unser eiFilm Abonnement..."
				};
				Dialog dlg2 = { DLG_CUST,
								"Das h&ouml;rt sich interessant an. Was hat es damit auf sich?"
				};

				Choice c1 = { Adv_Customer_WantsToBuy_iMovie_Movies,
								"Wir bieten Ihnen g&uuml;nstige Filme f&uuml;r Ihr eiFon an."
				};
				Choice c2 = { Adv_Customer_WantsToBuy_iMovie_Offer,
								"Nur heute k&ouml;nnen Sie das Filmpaket f&uuml;r den halben Preis buchen."
				};

				playDialog(dlg1);
				playDialog(dlg2);
				state = selectChoice(2, &c1, &c2);

				break;
			}

			case Adv_Customer_WantsToBuy_iMovie_Fuehrer: {
				break;
			}

			case Adv_Customer_WantsToBuy_iMovie_Movies: {
				Dialog dlg1 = { DLG_SJ,
								"Wir bieten Ihnen g&uuml;nstige Filme f&uuml;r Ihr eiFon an.\n"
								"Somit k&ouml;nnen Sie jederzeit f&uuml;r ein klitzekleines Entgelt "
								"auf eine\nnicht n&auml;her spezifizierte Anzahl Filme zugreifen."
				};
				Dialog dlg2 = { DLG_CUST,
								"Nun, das h&ouml;rt sich so an, als k&ouml;nne ich kaum darauf verzichten.\n"
								"Ich nehme es!"
				};

				playDialog(dlg1);
				playDialog(dlg2);
				buying_imovie_ok = 1;

				state = Adv_Customer_WantsToBuy_Decision;

				break;
			}

			case Adv_Customer_WantsToBuy_iMovie_Offer: {
				Dialog dlg1 = { DLG_SJ,
								"Nur heute k&ouml;nnen Sie das Filmpaket f&uuml;r den halben Preis buchen."
				};
				Dialog dlg2 = { DLG_CUST,
								"Hm, ich glaube nicht da&szlig; ich das gebrauchen kann..."
				};

				playDialog(dlg1);
				playDialog(dlg2);

				state = Adv_Customer_WantsToBuy_Decision;

				break;
			}
			//</editor-fold>

			//<editor-fold defaultstate="collapsed" desc=" Capture Soul ">
			case Adv_Customer_WantsToBuy_Soul: {
				if (buying_imovie_ok && buying_price_ok) {
					Dialog dlg1 = { DLG_SJ,
									"Da w&auml;re noch der Vertrag bez&uuml;glich Eurer Seele..."
					};
					Dialog dlg2 = { DLG_CUST,
									"Bei diesem wundervollen Angebot &uuml;berschreibe ich doch mit "
									"Freuden meine Seele.\n\n"
									"*Ein Strahlen erhellt die Augen des Kunden, gl&uuml;cklich, in "
									"unsere\nGemeinschaft eingegliedert zu sein*"
					};

					playDialog(dlg1);
					playDialog(dlg2);

					sleepSeconds(1);

					playCutsceneOutro_Won();

					return (EXIT_SUCCESS);
				}
				else {
					playCutsceneOutro_Flaming();
					return (EXIT_FAILURE);
				}

				break;
			}
			//</editor-fold>
		}
	}
	while(1);

	return (EXIT_SUCCESS);
}

int main(int argc, char** arg) {
	setTextColor(White, Black);

	do {
		int result = theGame();

		switch(result) {
			case EXIT_SUCCESS: {
				return EXIT_SUCCESS;
			}

			case EXIT_FAILURE: {
				setTextColor(Red, Black);
				printMessage(
							"Ihre Mission ist fehlgeschlagen!\n"
							"Sie haben es nicht geschafft, diese arme Seele zum Licht zu bringen.\n\n"
							"Noch ein Versuch?\n\n\n",
							0, 30
				);

				Choice c1 = { 1, "Aber sicher!" };
				Choice c2 = { 1, "Vielleicht?" };
				Choice c3 = { 0, "N&ouml;." };

				if (selectChoice(3, &c1, &c2, &c3) == 0) {
					return EXIT_FAILURE;
				}

				break;
			}
		}
	}
	while(1);

	return EXIT_SUCCESS;
}