
cmake_minimum_required(VERSION 2.8)

set(CMAKE_LEGACY_CYGWIN_WIN32 0) # Remove when CMake >= 2.8.4 is required


project(jobs)


add_executable(
		jobs
		main.c
		adventure.c
		console.c
		cutscenes.c
)

