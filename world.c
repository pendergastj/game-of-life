#include "world.h"
#include <stdlib.h>
#include <stdio.h>

static Cell** World;
static Cell** Changes;

static unsigned int Width;
static unsigned int Height;

Cell
get_cell(unsigned int x, unsigned int y)
{
  return World[y][x];
}

void
set_cell(unsigned int x, unsigned int y, Cell cell)
{
  Changes[y][x] = cell;
}

void
init_world(unsigned int width, unsigned int height)
{
  // init the 2D array
  World = calloc(height, sizeof(Cell*));
  Changes = calloc(height, sizeof(Cell*));

  for (int y = 0; y < height; ++y) {
    World[y] = calloc(width, sizeof(Cell*));
    Changes[y] = calloc(width, sizeof(Cell*));
  }

  // set the dimension
  Width = width;
  Height = height;
}

void
free_world()
{
  for (int y = 0; y < Height; ++y) {
    free(World[y]);
    free(Changes[y]);
  }
  free(World);
  free(Changes);
}

void
swap_buffers()
{
  for (int y = 0; y < Height; ++y)
    for (int x = 0; x < Width; ++x) {
      World[y][x] = Changes[y][x];
    }
}

void
display_world()
{
  static const char pallete[] = { '.', '#' };
  for (unsigned int y = 0; y < Height; ++y) {
    for (unsigned int x = 0; x < Width; ++x) {
      putchar(pallete[get_cell(x, y)]);
    }
    putchar('\n');
  }
}
