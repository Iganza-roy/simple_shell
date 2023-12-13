// shell.c

#include "shell.h"

void run_shell(int argc, char *argv[]) {
	// Check if there are command-line arguments (non-interactive mode)
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			execute_cmd(argv[i]);
		}
		return;
	}
}
