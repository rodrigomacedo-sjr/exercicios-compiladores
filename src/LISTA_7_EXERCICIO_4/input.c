/*
 * text_adventure.c
 * A simple text-based dungeon crawler game in C
 * No external dependencies beyond the standard library.
 * Compile with: gcc -o text_adventure text_adventure.c
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 6
#define MAX_INVENTORY 10
#define MAX_NAME_LENGTH 32

// Tile types
enum Tile { TILE_EMPTY, TILE_WALL, TILE_ENEMY, TILE_TREASURE, TILE_EXIT };

// Enemy structure
typedef struct {
  char name[MAX_NAME_LENGTH];
  int hp;
  int attack;
} Enemy;

// Player structure
typedef struct {
  char name[MAX_NAME_LENGTH];
  int hp;
  int attack;
  int x, y;
  int inventory[MAX_INVENTORY]; // indexes of found treasures
  int invCount;
} Player;

// Map
enum Tile map[MAP_HEIGHT][MAP_WIDTH];

// Function prototypes
void init_map();
void place_player(Player *p);
void print_map(const Player *p);
void init_player(Player *p);
void game_loop(Player *p);
void move_player(Player *p, int dx, int dy);
void encounter(Player *p);
void combat(Player *p, Enemy *e);
void pickup_treasure(Player *p);
void show_status(const Player *p);
int get_int_input();

int main() {
  srand((unsigned)time(NULL));
  Player player;

  init_map();
  init_player(&player);
  place_player(&player);
  printf("Welcome, %s, to the Dungeon of C!\n", player.name);
  game_loop(&player);
  return 0;
}

// Initialize map with walls and random contents
void init_map() {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      if (y == 0 || y == MAP_HEIGHT - 1 || x == 0 || x == MAP_WIDTH - 1) {
        map[y][x] = TILE_WALL;
      } else {
        int r = rand() % 100;
        if (r < 10)
          map[y][x] = TILE_WALL;
        else if (r < 20)
          map[y][x] = TILE_ENEMY;
        else if (r < 25)
          map[y][x] = TILE_TREASURE;
        else
          map[y][x] = TILE_EMPTY;
      }
    }
  }
  // Place exit
  map[MAP_HEIGHT - 2][MAP_WIDTH - 2] = TILE_EXIT;
}

// Initialize player stats and name
void init_player(Player *p) {
  printf("Enter your hero's name: ");
  if (fgets(p->name, MAX_NAME_LENGTH, stdin)) {
    size_t len = strlen(p->name);
    if (len && p->name[len - 1] == '\n')
      p->name[len - 1] = '\0';
  }
  p->hp = 20;
  p->attack = 5;
  p->invCount = 0;
}

// Place player at random empty location
void place_player(Player *p) {
  int x, y;
  do {
    x = rand() % MAP_WIDTH;
    y = rand() % MAP_HEIGHT;
  } while (map[y][x] != TILE_EMPTY);
  p->x = x;
  p->y = y;
}

// Print map around player
void print_map(const Player *p) {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      if (p->x == x && p->y == y)
        printf("@ ");
      else {
        switch (map[y][x]) {
        case TILE_EMPTY:
          printf(". ");
          break;
        case TILE_WALL:
          printf("# ");
          break;
        case TILE_ENEMY:
          printf("E ");
          break;
        case TILE_TREASURE:
          printf("$ ");
          break;
        case TILE_EXIT:
          printf("X ");
          break;
        }
      }
    }
    printf("\n");
  }
}

// Main game loop
void game_loop(Player *p) {
  char cmd;
  while (1) {
    print_map(p);
    show_status(p);
    printf("Move (WASD) or (Q)uit: ");
    cmd = getchar();
    while (getchar() != '\n')
      ;
    cmd = tolower(cmd);
    if (cmd == 'q') {
      printf("Goodbye, %s!\n", p->name);
      break;
    }
    int dx = 0, dy = 0;
    if (cmd == 'w')
      dy = -1;
    else if (cmd == 's')
      dy = 1;
    else if (cmd == 'a')
      dx = -1;
    else if (cmd == 'd')
      dx = 1;
    else {
      printf("Invalid command.\n");
      continue;
    }
    move_player(p, dx, dy);
  }
}

// Move player and handle tile interactions
void move_player(Player *p, int dx, int dy) {
  int nx = p->x + dx;
  int ny = p->y + dy;
  if (nx < 0 || nx >= MAP_WIDTH || ny < 0 || ny >= MAP_HEIGHT)
    return;
  enum Tile t = map[ny][nx];
  if (t == TILE_WALL) {
    printf("You bump into a wall.\n");
    return;
  }
  p->x = nx;
  p->y = ny;
  if (t == TILE_ENEMY)
    encounter(p);
  else if (t == TILE_TREASURE)
    pickup_treasure(p);
  else if (t == TILE_EXIT) {
    printf("You found the exit! You win!\n");
    exit(0);
  }
  map[ny][nx] = TILE_EMPTY;
}

// Encounter enemy
void encounter(Player *p) {
  Enemy e;
  // Random simple enemy
  strcpy(e.name, "Goblin");
  e.hp = 8 + rand() % 5;
  e.attack = 2 + rand() % 3;
  printf("A wild %s appears! HP: %d, ATK: %d\n", e.name, e.hp, e.attack);
  combat(p, &e);
}

// Combat loop
void combat(Player *p, Enemy *e) {
  char choice;
  while (p->hp > 0 && e->hp > 0) {
    printf("(A)ttack or (R)un? ");
    choice = getchar();
    while (getchar() != '\n')
      ;
    choice = tolower(choice);
    if (choice == 'a') {
      e->hp -= p->attack;
      printf("You strike the %s for %d damage.\n", e->name, p->attack);
      if (e->hp <= 0) {
        printf("You defeated the %s!\n", e->name);
        return;
      }
    } else if (choice == 'r') {
      if (rand() % 100 < 50) {
        printf("You escape successfully!\n");
        return;
      } else {
        printf("Failed to escape!\n");
      }
    } else {
      printf("Invalid choice.\n");
      continue;
    }
    // Enemy attacks
    p->hp -= e->attack;
    printf("The %s hits you for %d damage.\n", e->name, e->attack);
    if (p->hp <= 0) {
      printf("You have been defeated... Game Over.\n");
      exit(0);
    }
  }
}

// Pickup treasure
void pickup_treasure(Player *p) {
  if (p->invCount < MAX_INVENTORY) {
    p->inventory[p->invCount++] = rand() % 100; // random item ID
    printf("You found a mysterious treasure! Inventory slots used: %d/%d\n",
           p->invCount, MAX_INVENTORY);
    if (p->invCount == MAX_INVENTORY) {
      printf(
          "Your inventory is full! You feel powerful! HP and ATK increased.\n");
      p->hp += 10;
      p->attack += 2;
    }
  } else {
    printf("You found treasure, but your inventory is full. You leave it.\n");
  }
}

// Show player status
void show_status(const Player *p) {
  printf("[%s] HP: %d, ATK: %d, Pos: (%d,%d)\n", p->name, p->hp, p->attack,
         p->x, p->y);
  printf("Inventory: %d/%d\n", p->invCount, MAX_INVENTORY);
}

// Helper to read integer
int get_int_input() {
  char buf[16];
  if (!fgets(buf, sizeof(buf), stdin))
    return 0;
  return atoi(buf);
}
