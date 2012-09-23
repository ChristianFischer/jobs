#include "cutscenes.h"
#include "console.h"

#include <stdio.h>

#ifdef	__cplusplus
extern "C" {
#endif


#define CHR_LINE_UD		'\xB3'
#define CHR_LINE_LR		'\xC4'
#define CHR_LINE_UL		'\xD9'
#define CHR_LINE_UR		'\xC0'
#define CHR_LINE_DL		'\xBF'
#define CHR_LINE_DR		'\xDA'
#define CHR_LINE_ULR	'\xC1'
#define CHR_LINE_UDR	'\xC3'
#define CHR_LINE_UDL	'\xB4'
#define CHR_LINE_DLR	'\xC2'
#define CHR_LINE_UDLR	'\xC5'


	void printC(unsigned short x, unsigned short y, char c) {
		setCursorPosition(x, y);
		printf("%c", c);
	}


	void printCharacter(unsigned int x, unsigned int y) {
		setCursorPosition(x-1, y-3);	printf(" O ");
		setCursorPosition(x-1, y-2);	printf("-|-");
		setCursorPosition(x-1, y-1);	printf(" | ");
		setCursorPosition(x-1, y-0);	printf("/ \\");
	}


	void printShop() {
		int i;

		setTextColor(LightGray, Black);

		for(i=0; i<80; i++) {
			printC(i, 17, CHR_LINE_LR);
		}

		// board
		setCursorPosition(14, 17);
		printf("%c   %c", CHR_LINE_UL, CHR_LINE_UR);
		setCursorPosition(14, 16);
		printf("%c   %c", CHR_LINE_UD, CHR_LINE_UD);
		setCursorPosition(14, 15);
		printf("%c%c%c%c%c", CHR_LINE_DR, CHR_LINE_LR, CHR_LINE_LR, CHR_LINE_LR, CHR_LINE_DL);

		// door
		printC(50, 17, CHR_LINE_ULR);
		printC(55, 17, CHR_LINE_ULR);

		for(i=12; i<17; i++) {
			printC(50, i, CHR_LINE_UD);
			printC(55, i, CHR_LINE_UD);
		}

		printC(50, 15, CHR_LINE_UDR);

		setCursorPosition(50, 11);
		printf("%c%c%c%c%c%c", CHR_LINE_DR, CHR_LINE_LR, CHR_LINE_LR, CHR_LINE_LR, CHR_LINE_LR, CHR_LINE_DL);

		// apple logo - shining white!
		setTextColor(White, Black);
		setCursorPosition(30,  2);		printf(" _");
		setCursorPosition(30,  3);		printf(" \\|__  ___");
		setCursorPosition(30,  4);		printf("  /  \\/  /");
		setCursorPosition(30,  5);		printf(" /      |");
		setCursorPosition(30,  6);		printf("|        \\");
		setCursorPosition(30,  7);		printf("|         |");
		setCursorPosition(30,  8);		printf(" \\       /");
		setCursorPosition(30,  9);		printf("  \\_____/");
	}




	void printSteve() {
printf("                                                                                \n");
printf("                                  `,                                            \n");
printf("                               ``+';,+#+:.                                      \n");
printf("                            ``:;##++'++@@@@@,                                   \n");
printf("                         `.+'#@###@#@@@@@@@@@@#                                 \n");
printf("                        :@#######@##@@@@@@@@@@@@@,                              \n");
printf("                      .#@########@@##@@@@@@@@#@@@@@                             \n");
printf("                     +@@##@######@##@##@#@@@@@@@#@@@.                           \n");
printf("                    @##@#@#@####################@#@@@;                          \n");
printf("                  :@@@##@@####+##+++#+++########@@@@@@+                         \n");
printf("                 ,@@@####+##+++++++'+#+#+########@@@@@@'                        \n");
printf("                #@@@##@##+++'+#+++++'+++++++++++###@@@@@#                       \n");
printf("               #+@@##@#'';'''++''++'';'+++++++++++###@@@@@                      \n");
printf("              ,#@#@@#+';''''+'''''+'';'''+''++''+++#@@@@@@+                     \n");
printf("              +@##@#+';;:;''''';';'++'';''';''''''++##@@@@#:                    \n");
printf("             +#@@@##;,:,:,;';;':;;:;;;;'';;;;;;''''++###@@@@                    \n");
printf("            .#@@@@#':,:::,:;;::::;,,;;;;;':;;;;;'''++##@@@@@,                   \n");
printf("            '@@##+':,,:,,,,,:;:,,.,.,::;';;:;;;;;;''+###@@@@@`                  \n");
printf("           +@@####,,,..,,:,,,,,,.,....,::;':;::;;;'+++###@@@@;                  \n");
printf("          `#@@###+:,,..,:,,,,...........::;::;:;;'''++###@@@@@`                 \n");
printf("          #@@@@##;,,..,,,,,...`..```...`.:::::;;'''+'++###@@@@#                 \n");
printf("         .##@@##+,,,,,.,,.,...```````...`,,,:::;;;''+++###@@@@#,                \n");
printf("         ##@#@##;,,........````````````...,,,,::;;;'+++###@@@@#@                \n");
printf("         ##@@##+:,......```````````````.`...,,,::;'''++###@@@@#@,               \n");
printf("         #@#@@@+,,,.....````````````````.....,,,:;;''++####@@@@@@               \n");
printf("        ###@@@#',,......`````````````````....,,,:;''+++##@#@@@##@+              \n");
printf("        #@@@@##',.......``````````````````...,,:::''+++###@#@@####              \n");
printf("        #@@@@#@;.....,..`````````````````....,,,::'+++#####@@##@@+`             \n");
printf("       `#++####;,.......`````` ``````````.,...,,,:;'+++####@@@##@#              \n");
printf("       .;;#@#@#;,.......`````````````````.,..,,,:;;'+##+##@@###@#@              \n");
printf("        ''#@##+;,.......`````````````````.,..,,::;''++++##@####@#@              \n");
printf("        ;+###@'',.......````````````````....`,::;;''++++###@####+#`             \n");
printf("        ;+++#+#',......`````````````````...`.,;:::;;''++#+##+#####              \n");
printf("        ++'+@+#',,..,..`.```````````````.....,:::::;;;++####++##@@.             \n");
printf("        +;;##:';:,.....`.````````````````.`...,,,::;;;+####+#+##@#,             \n");
printf("        '++++,+':,,....`.`````````````````...,,,,:::;'++####'+##@#;             \n");
printf("        ;'##',,::,,....````````````````````.....,;:;;;++#####++#@@#             \n");
printf("       ;:;;+:,:';,,,.`.````````````````````.....,,,,:;+++###@'#@#@#`            \n");
printf("       `;;,;;:,':,,....`````````````````````....,,,::;'++###@+####:`            \n");
printf("      ;'#;:;+::':...`..``````````````````.``.....,,,::''+##@@#+#@@@@@.          \n");
printf("     .'+':#'#;;;,,....````````````````````.`....,:,,::;'+##@@@+#@@@@@@          \n");
printf("     :@#;'@+#:+:,,...````````````````````.`...,,,,,,,::;+##@@@##@@@@@@          \n");
printf("     ;@#'+#@+;',,,,`..````````...``````````...,,,,,.,,:'++##@@##@@@@@@          \n");
printf("     :@','+@';':,::;;,,````````.`....``...`.,,,,,,,,;''+++###@@@@@@@@@          \n");
printf("     :@;:'+'+';,,,'+###':.```.`.``..,.......,,,::;';;'++##@##@@@@@@@@@          \n");
printf("     ,@:::'+#':,,:;;'@@#+#';:......,`.,....,:'++#';;+####@@##@@#@@@@@@          \n");
printf("     .+::,;;##:..',..,'+`,';:'#':,::`...,,;'+#+'@#+++#,##@@###@@@@@@@'          \n");
printf("      ''''+'+++,.:.::;.:;'#@@@#'+'',....:'##@;@@@@@@@#+#'#@@###@@@@@@           \n");
printf("      ;#####;:#;.,,:;'@##@.@@+#@;':.```.;#@@'#@+,#@@'##+####@##@@@@@@           \n");
printf("      ;+###+',.;,.,:;@@'`@@@#;##+;:````.:#@+@#;,@@+#'@##+######@@@@@@           \n");
printf("      ,'#+,,;,,+,,.,+;:,` @#';++;::````.,#@#@##;.+';;'@##++####@##@@@           \n");
printf("      ,'#',,;:.`;`..,``.,``,,;::..,..`.'##@@#'',:;;;'++##+'++#####@@@           \n");
printf("      `,++:,;:,`@`;`...````...:;..:,```.,+;##;:,..,,,:+#','####@#@@@@           \n");
printf("       :'#+.':,.`;@'`...`.`..,;;. ;.``..:+#.@+;,....,:'':'''###@@@@@#           \n");
printf("       ;.:':',,..`::..````.,,,:`...`....;###+#;;:,,:;;;:,:;'+##@#@@@'           \n");
printf("       .'.::':,,...`..`````...`....````,:#+#++':,,,..,,,.::+#####@@#,           \n");
printf("        :.:;+:,,..``.``````..`.,.```````;+#++';:...`...,,:;+###@#@@#`           \n");
printf("        ,..::;,,,,....``````...,.``````.:+#+++;:,,`..,,::,'+####+@@#            \n");
printf("        :...;;,,..,.,``````,..,.```````.;+##'';,,,,,,:::.;'+#@@##@@#            \n");
printf("        ;..,,;;:,,.....``....,,`,``````.;'+#++;,,,,,,;`:;'+###@##@@@            \n");
printf("        `,.,:'::,:,.,.`......``,```````.,;+#@#';,..`.;';;'+#@@@@##@`            \n");
printf("         ;,.'+;',:,,,....`......````````,'##@@+;:::::;';;+##@#@##@#             \n");
printf("          ,.,';':':,::,.`....,.`.```````:####@+;::::::''+'###@@##+'             \n");
printf("          `:`:'';;:;,,....`..`...``````.:##+'@#;::,,::;'###@@#@#+;              \n");
printf("            ;.'''::::,,```.......```````:+#++##+;:,,:;;'+###@#@@;               \n");
printf("            ;,;:::';;,,.```.`.,.````````,+###@@+':,::''+##@@###@:               \n");
printf("            :,;::;::::,.```..:.```,`````,+#@@@#+;;::;''+##@@###@:               \n");
printf("            ,,::,,,;;;...`.`..`````.```.:@@@@@#+';;:;;+##@#+###@`               \n");
printf("            `.:.;;:.;:,.....,.```.`.``,,'@@@@@@#+';';;+##@@#+@##                \n");
printf("             ,,.:,:,:,,...`..`.`.`:;',,'#@@@@@#++#;;+;+##+######                \n");
printf("             ,,.:;..;,.,....,,,.,::;';'#+@@@@#@###;#;+'#@+'####@                \n");
printf("             .,;.,:.,:,,..,,:,;,::,,+#';++##@#@@+##+#++##;+@####                \n");
printf("              ;,,,,.,,.,.,:;;;::,;,;;,#++'#+@#+@##++##'#+#+###@+                \n");
printf("              ,;:`,.:..,,;;:'+;';':';;+#+'+#@@####@#@+#@#'+##@@:                \n");
printf("               .,,,.`:,,.:+##:;;;;'#:;'#;'+###@@@@@@;;#++'+@#@@`                \n");
printf("               `,:,,.,::;;;+#@##+''''''''+@@@@@@@##+;'#++'+##@@                 \n");
printf("                .,:,,,,,;+#+@+'';;,.,:,:::'+###@@#++;+++#######                 \n");
printf("                `:..,;.,,;+##::.,....`.,,::+'++##+#'++;+'@#@##`                 \n");
printf("                 ,,.,.;.:;#@+,,,..``````..,,''++#++''#''+###@@                  \n");
printf("                 `..,;::':+@:,,...`.,:;:;;;:'+'###+:;#+#+#####                  \n");
printf("                  .:,;''+'##:,:,:,,:;':;';+'+++###';;#@@@###@#,                 \n");
printf("                  `,;##+;++:,,..:,;;'';##+';#####+;:+#@#++#@@#@                 \n");
printf("                   :';,,;+';:,..,,:'++;##;+@####++;;'@##@##@@@@`                \n");
printf("                   ;;;'+;#';:,,....';';'+++###''';;:@@@#@#@@@@#@                \n");
printf("                   :.`;#;::;'',:.`..,.,`,:;:++':+'''+#@#@#@@@@@@@`              \n");
printf("                   `+...+'';:;,,:.......,;''+';,::#+++@@@@@@@@@@@@.             \n");
printf("                    '+:;,'+`::;:'..,;.,;:+;+#;::;+'##@@@@@@@@@@@@@@`            \n");
printf("                    ''+,;+;';,.:',';;'';,'+##';#++###@#@@@@@@@@@@@@@@           \n");
printf("                    '''',;::,,`.:;::'',;+##;;+#'''@#@@@@@@@@@@@@@@@@@@@@+:      \n");
printf("                    +'';;;':..`.,+;;+:+'++#;;:#++##@@@@@@@@@@@@@@@@@@@@@@@@,    \n");
printf("                    #;::;#,:: :.:;:++';`.##'+'';+#@@@@@@@@@@@@@@@@@@@@@@@@@@@,  \n");
printf("                    @':;:;#;#;,,;#'#++```+@'++;##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("                    @+:;,:;+@+.;++...,:..:@#+'+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("                    #@::::;;+###'.```..,;:@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("                  `##@@:::;;;++@..````..,;+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("                .#@@@@@@':,:;;+#..`````...:+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("               @@@@@@@@@@#,,;,'+:,```````..,#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("              @@@@@@@@@@@@@@;,;;;;````````...@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("           ,@@@@@@@@@@@@@@@@@@+,+',.`````````.'@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("         `@@@@@@@@@@@@@@@@@@@@@'``.,`````````.,;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("        +@@@@@@@@@@@@@@@@@@@@@+```..,````````.,::@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("      #@@@@@@@@@@@@@@@@@@@@@@@ ```.`.,````````:,:;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("    #@@@@@@@@@@@@@@@@@@@@@@@@@```.```..```````.;:'#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("  @@@@@@@@@@@@@@@@#@@@@@@@@@@@``.`````````````,';;+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf(";@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,``.`.``````````:';'##@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("@@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@``````..`````.,';'+###@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("@@@@@@@@@@@@@@@@@@@#@@@@@@@@@#`.``````,...`..:';++#@;#@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@;..,``````.,,...,:;;++#@#'@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("@@@@@@@@@@@@@@@@@@@#@@@@@@@@.'.`,``````,:,,,,:;;++#@#'+@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("@@@@@@@@@@@@@@@@@@@@@@#@@@@#'...`.````,,:,,:,;:;++#@@#+@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	}



	void playCutsceneIntro() {
		clearScreen();
		printShop();

		setTextColor(Cyan, Black);
		printCharacter(12, 16);

		int i;
		for(i=0; i<28; i++) {
			setTextColor(Green, Black);
			printCharacter(48 - i, 16);

			sleepMilliSeconds(100);

			if (i != 27) {
				int j;
				for(j=12; j<=16; j++) {
					setCursorPosition(48 - i - 1, j);
					printf("   ");
				}
			}
		}

		setCursorPosition(0, 20);
	}



	playCutsceneOutro_JustGoing(Dialog dlg) {
		clearScreen();
		printShop();

		setTextColor(Cyan, Black);
		printCharacter(12, 16);

		setTextColor(Green, Black);
		printCharacter(21, 16);

		setCursorPosition(0, 19);
		playDialog(dlg);

		// leaving animation
		int i;
		for(i=0; i<28; i++) {
			setTextColor(Green, Black);
			printCharacter(21 + i, 16);

			sleepMilliSeconds(100);

			int j;
			for(j=12; j<=16; j++) {
				setCursorPosition(21 + i - 1, j);
				printf("   ");
			}
		}

		setCursorPosition(0, 23);
	}




	playCutsceneOutro_CallMeAnAmbulance() {
		int t;
		for(t=0; t<4; t++) {
			clearScreen();
			printShop();

			setTextColor(Cyan, Black);
			printCharacter(12, 16);

			setTextColor(Green, Black);

			switch(t) {
				case 0: {
					printCharacter(21, 16);
					break;
				}

				case 1: {
					printCharacter(30, 16);
					break;
				}

				case 2: {
					printCharacter(39, 16);
					break;
				}

				case 3: {
					printCharacter(48, 16);
					break;
				}
			}

			setCursorPosition(0, 19);
			
			switch(t) {
				case 0: {
					Dialog dlg = { Green, "Kunde",
									"Nun, ich glaube es ist besser, ich gehe jetzt."
					};

					playDialog(dlg);

					break;
				}

				case 1: {
					Dialog dlg = { Green, "Kunde",
									"Ich werde ein anderes "
									"Mobilfunktelefonfachgesch&auml;ft aufsuchen."
					};

					playDialog(dlg);

					break;
				}
				case 2: {
					Dialog dlg = { Green, "Kunde",
									"Und dort ein neues Mobilfunktelefon erwerben."
					};

					playDialog(dlg);

					break;
				}
				case 3: {
					Dialog dlg = { Green, "Kunde",
									"Dann kann ich Hilfe f&uuml;r sie rufen.\n"
									"Warten Sie einfach solange hier."
					};

					playDialog(dlg);

					break;
				}
			}
		}

		setCursorPosition(0, 23);
	}


	void playCutsceneOutro_Flaming() {
		clearScreen();
		printShop();

		setTextColor(Cyan, Black);
		printCharacter(12, 16);

		setTextColor(Green, Black);
		printCharacter(21, 16);

		setCursorPosition(0, 19);
		Dialog dlg = { Green, "Kunde",
						"Was? Meine Seele?\n"
						"Satanistisches, gottloses Gesindel!\n\n"
						"*Der Kunde h&auml;lt pl&ouml;tzlich einen Brandsatz in seiner Hand*"
		};

		playDialog(dlg);

		// leaving animation
		int i;
		for(i=0; i<28; i++) {
			setTextColor(Green, Black);
			printCharacter(21 + i, 16);

			sleepMilliSeconds(100);

			int j;
			for(j=12; j<=16; j++) {
				// print 'flames'
				int f;
				for(f=0; f<5; f++) {
					unsigned short x = (rand() % 60) + 4;
					unsigned short y = (rand() % 5)  + 12;
					setCursorPosition(x, y);

					switch(rand() % 4) {
						case 0: setTextColor(Yellow,   Black); break;
						case 1: setTextColor(Red,      Black); break;
						case 2: setTextColor(LightRed, Black); break;
						case 3: setTextColor(White,    Black); break;
					}

					printf("*");
				}


				setCursorPosition(21 + i - 1, j);
				printf("   ");
			}
		}

		setCursorPosition(0, 23);

		return;
	}


	void playCutsceneOutro_Won() {
		clearScreen();
		printShop();

		setTextColor(Cyan, Black);
		printCharacter(12, 16);

		setTextColor(Green, Black);
		printCharacter(21, 16);

		setCursorPosition(0, 19);
		setTextColor(Pink, Black);

		printMessage(
						"Herzlichen Gl&uuml;ckwunsch.\n"
						"Sie haben es geschafft, einer armen Seele das Licht zu bringen."
		);

		return;
	}


#ifdef	__cplusplus
}
#endif

