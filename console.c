#include "console.h"

#if _WIN32
#include <windows.h>
#endif


#ifdef	__cplusplus
extern "C" {
#endif


	void clearScreen() {
		#ifdef _WIN32
			HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD coord = {0, 0};
			DWORD count;
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo(hStdOut, &csbi);
			FillConsoleOutputCharacter(hStdOut, ' ',
									   csbi.dwSize.X * csbi.dwSize.Y,
									   coord, &count);
			SetConsoleCursorPosition(hStdOut, coord);
		#else
			#error Unknown Platform
		#endif
	}


	void setCursorVisible(int visible) {
		#if _WIN32
			CONSOLE_CURSOR_INFO ci = {10, visible ? TRUE : FALSE};
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
		#else
			#error Unknown Platform
		#endif
	}


	void disableConsoleScrolling() {
		#if _WIN32
			HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD size = {80, 23};
			SetConsoleScreenBufferSize(hStdOut, size);
		#else
			#error Unknown Platform
		#endif
	}


	void setCursorPosition(unsigned short x, unsigned short y) {
		#if _WIN32
			COORD coords = { x, y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , coords);
		#else
			#error Unknown Platform
		#endif
	}


	void getCursorPosition(unsigned short* x, unsigned short* y) {
		#if _WIN32
			HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO SBInfo;
			GetConsoleScreenBufferInfo(hStdOut, &SBInfo);

			(*x) = SBInfo.dwCursorPosition.X;
			(*y) = SBInfo.dwCursorPosition.Y;
		#else
			#error Unknown Platform
		#endif
	}


	void setTextColor(enum TextColor foreground, enum TextColor background) {
		#if _WIN32
			WORD color = (background << 4) + (foreground);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		#else
			#error Unknown Platform
		#endif
	}



	void sleepSeconds(int seconds) {
		#if _WIN32
			Sleep(seconds * 1000);
		#else
			#error Unknown Platform
		#endif
	}


	void sleepMilliSeconds(int ms) {
		#if _WIN32
			Sleep(ms);
		#else
			#error Unknown Platform
		#endif
	}



#ifdef	__cplusplus
}
#endif
