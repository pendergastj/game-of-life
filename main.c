#include "world.h"
#include <stdlib.h>

int
main()
{
  int is_running = 1;

  init_world(50, 10);

  while (is_running) {

		for (int r = 0; r < 10; ++r) {

      const unsigned int x = rand() % 50;
      const unsigned int y = rand() % 10;

      set_cell(x, y, 1);
    }

    swap_buffers();
    system("cls");
    display_world();
  }

  free_world();
}