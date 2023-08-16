#include <stdio.h>

// Define constants for directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define UP 4
#define DOWN 5

// Function to move the spacecraft based on its current direction
void moveF(int *position, int direction)
{
    switch (direction)
    {
    case NORTH:
        position[1]++;
        break;
    case SOUTH:
        position[1]--;
        break;
    case EAST:
        position[0]++;
        break;
    case WEST:
        position[0]--;
        break;
    case UP:
        position[2]++;
        break;
    case DOWN:
        position[2]--;
        break;
    }
}

void moveB(int *position, int direction)
{
    switch (direction)
    {
    case NORTH:
        position[1]--;
        break;
    case SOUTH:
        position[1]++;
        break;
    case EAST:
        position[0]--;
        break;
    case WEST:
        position[0]++;
        break;
    case UP:
        position[2]--;
        break;
    case DOWN:
        position[2]++;
        break;
    }
}

// Function to turn the spacecraft left
void turn_left(int *direction)
{
    (*direction) = ((*direction) - 1 + 4) % 4; // Modulus to ensure direction stays within [0, 3]
}

// Function to turn the spacecraft right
void turn_right(int *direction)
{
    (*direction) = ((*direction) + 1) % 4;
}

// Function to turn the spacecraft up
void turn_up(int *direction)
{
    if (*direction < UP)
    {
        (*direction) = UP;
    }
}

// Function to turn the spacecraft down
void turn_down(int *direction)
{
    if (*direction < UP)
    {
        (*direction) = DOWN;
    }
}

// Function to reset the spacecraft to its initial state
void reset(int *position, int *direction)
{
    position[0] = position[1] = position[2] = 0;
    *direction = NORTH;
}

int main()
{
    int initialPosition[3] = {0, 0, 0};
    int direction = NORTH;
    printf("Chandrayaan 3\nInitial position: (0,0,0)\nInitial direction: North (N)\n");

    while (1)
    {
        char command;
        printf("Enter a valid command (f, b, l, r, u, d, q to quit, x to reset): ");
        scanf(" %c", &command);

        switch (command)
        {
        case 'f':
            moveF(initialPosition, direction);
            break;
        case 'b':
            moveB(initialPosition, direction);
            break;
        case 'l':
            turn_left(&direction);
            break;
        case 'r':
            turn_right(&direction);
            break;
        case 'u':
            turn_up(&direction);
            break;
        case 'd':
            turn_down(&direction);
            break;
        case 'q':
            return 0; // Exit the program
        case 'x':
            reset(initialPosition, &direction);
            printf("Spacecraft reset to initial position.\n");
            break;
        default:
            printf("Invalid command\n");
            break;
        }

        const char *directionNames[] = {"N", "E", "S", "W", "Up", "Down"};
        printf("Final Position: (%d, %d, %d)\n", initialPosition[0], initialPosition[1], initialPosition[2]);
        printf("Direction: %s\n", directionNames[direction]);
    }

    return 0;
}