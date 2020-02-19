#pragma once

typedef enum {
	DEAD,
	ALIVE
} Cell;

Cell	// returns the cell at x, y
get_cell(unsigned int x, unsigned int y);

void	// sets the cell at x, y
set_cell(unsigned int x, unsigned int y, Cell cell);

void	// allocates the world
init_world(unsigned int width, unsigned int height);

void	// deallocates the world
free_world();

void	// swap the read and write buffers
swap_buffers();

void
display_world();