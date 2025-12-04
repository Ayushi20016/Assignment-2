#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN 0

// clamp value between 0 and 100
int clamp(int value) {
    if(value > MAX) return MAX;
    if(value < MIN) return MIN;
    return value;
}

// Random unique actions
void getRandomActions(int actions[], int totalActions) {
    for(int i = 0; i < 3; i++) {
        actions[i] = rand() % totalActions;
        // Ensure no repeat actions
        for(int j = 0; j < i; j++) {
            if(actions[i] == actions[j]) {
                i--;
                break;
            }
        }
    }
}

// Print name of action
void printActionName(int id) {
    switch(id) {
        case 0: printf("Feed your pet"); break;
        case 1: printf("Play with your pet"); break;
        case 2: printf("Clean your pet"); break;
        case 3: printf("Ignore your pet"); break;
        case 4: printf("Do homework instead"); break;
        case 5: printf("Scroll Instagram instead"); break;
        case 6: printf("Give pet a treat"); break;
        case 7: printf("Take pet for a walk"); break;
        case 8: printf("Let your pet sleep"); break;
        case 9: printf("Give pet a bath"); break;
    }
}

int main() {
    srand(time(NULL));

    int happiness = rand() % 51 + 25;   
    int hunger = rand() % 51 + 25;      
    int cleanliness = rand() % 51 + 25; 

    int actions[3];
    int choice;

    printf("\n? Your Cute Pet Game ?\n");

    while(1) {

        printf("\nPet Status:\n");
        printf("Happiness   : %d\n", happiness);
        printf("Hunger      : %d\n", hunger);
        printf("Cleanliness : %d\n", cleanliness);

        // lose condition
        if(happiness == 0 || hunger == 0 || cleanliness == 0) {
            printf("\n?? Your pet is suffering. You Lose!\n");
            break;
        }

        // win condition
        if(happiness == 100 || hunger == 100 || cleanliness == 100) {
            printf("\n?? Your pet is thriving. You Win!\n");
            break;
        }

        getRandomActions(actions, 10);

        printf("\nChoose an action:\n");
        for(int i = 0; i < 3; i++) {
            printf("%d. ", i+1);
            printActionName(actions[i]);
            printf("\n");
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 3) {
            printf("Invalid choice.\n");
            continue;
        }

        int action = actions[choice - 1];

        switch(action) {
            case 0: hunger += 20; cleanliness -= 5; break;
            case 1: happiness += 20; hunger -= 10; cleanliness -= 5; break;
            case 2: cleanliness += 20; happiness -= 5; break;
            case 3: happiness -= 20; hunger -= 10; cleanliness -= 10; break;
            case 4: happiness -= 10; hunger -= 5; break;
            case 5: happiness -= 15; cleanliness -= 5; break;
            case 6: hunger += 10; happiness += 5; break;
            case 7: happiness += 10; cleanliness -= 5; break;
            case 8: happiness += 5; hunger -= 5; break;
            case 9: cleanliness += 25; happiness -= 5; break;
        }

        happiness = clamp(happiness);
        hunger = clamp(hunger);
        cleanliness = clamp(cleanliness);
    }

    return 0;
}

