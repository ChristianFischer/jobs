#include "adventure.h"

#include <malloc.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#ifdef	__cplusplus
extern "C" {
#endif



	Dialog mkDialog(enum TextColor color, const char *char_name, const char *message) {
		Dialog dlg = { color, char_name, message };
		return dlg;
	}


	Choice mkChoice(State state, const char *message) {
		Choice choice = { state, message };
		return choice;
	}




	void printMessage(const char *message, int indent, int delay_per_char) {
		int textlen = strlen(message);
		int cursor_pos = indent;
		char last_char = '\0';

		int i=0;
		for(i=0; i<textlen; i++) {
			char current_char  = message[i];
			char char_to_print = '\0';
			int do_newline = 0;

			switch(current_char) {
				case '\n': {
					do_newline = 1;

					// longer pause for paragraph
					if (last_char == '\n') {
						sleepMilliSeconds(500);
					}

					break;
				}

				case '&': {
					int begin = i;

					while(i < textlen && message[i] != ';') {
						i++;
					}

					int size = i - begin;
					char *code = malloc(size + 1);
					memset(code, '\0', size + 1);
					strncpy(code, &(message[begin]), size);

					if (strcmp(code, "&Auml") == 0) {
						char_to_print = '\x8E';
					}

					if (strcmp(code, "&Ouml") == 0) {
						char_to_print = '\x99';
					}

					if (strcmp(code, "&Uuml") == 0) {
						char_to_print = '\x9A';
					}

					if (strcmp(code, "&auml") == 0) {
						char_to_print = '\x84';
					}

					if (strcmp(code, "&ouml") == 0) {
						char_to_print = '\x94';
					}

					if (strcmp(code, "&uuml") == 0) {
						char_to_print = '\x9A';
					}

					if (strcmp(code, "&szlig") == 0) {
						char_to_print = '\xE1';
					}

				//	printf("||%c||%s||", char_to_print, code);

					free(code);

					break;
				}

				default: {
					char_to_print = current_char;
					break;
				}
			}

			if (char_to_print) {
				printf("%c", char_to_print);
				sleepMilliSeconds(delay_per_char);
				++cursor_pos;
			}

			if (do_newline || (cursor_pos >= 78)) {
				printf("\n");

				int j;
				for(j=0; j<indent; j++) {
					printf(" ");
				}

				cursor_pos = indent;
			}

			last_char = current_char;
		}

		return;
	}


	void playDialog(Dialog dlg) {
		setTextColor(dlg.char_color, Black);
		printf(dlg.char_name);

		setTextColor(White, Black);
		printf(": ");

		int indent = 2 + strlen(dlg.char_name);
		printMessage(dlg.message, indent, 30);

		printf("\n\n");
		sleepMilliSeconds(1000);

		return;
	}


	State selectChoice(int num, ...) {
		Choice **choices = malloc(num * sizeof(Choice*));
		va_list args;
		va_start(args, num);

		int i;
		for(i=0; i<num; i++) {
			Choice *c = va_arg(args, Choice*);
			choices[i] = c;
		}

		// print all choices
		setTextColor(Pink, Black);

		for(i=0; i<num; i++) {
			printf(" [%d] ", (i+1));
			printMessage(choices[i]->title, 5, 0);
			printf("\n");
		}

		// short delay to prevent accidental keypresses
		sleepMilliSeconds(200);
		Choice *selected_choice = NULL;
		int selected = 0;

		do {
			int value = (getch() - '0' - 1);

			if (value >= 0 && value < num) {
				selected = value;
				selected_choice = choices[selected];
				break;
			}
		}
		while(1);

		unsigned short x;
		unsigned short y;
		getCursorPosition(&x, &y);
		setCursorPosition(0, y - num + selected);

		setTextColor(White, Pink);
		printf(" [%d] ", (selected + 1));
		printMessage(selected_choice->title, 5, 0);

		// wait a moment
		sleepMilliSeconds(300);

		// clear the choice selection
		setTextColor(White, Black);
		for(i=0; i<num; i++) {
			setCursorPosition(0, y - num + i);
			printf("                                                                                ");
		}

		// reset cursor position
		setCursorPosition(0, y - 2);

		va_end(args);
		free(choices);

		return selected_choice->state;
	}


#ifdef	__cplusplus
}
#endif
