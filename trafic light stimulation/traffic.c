#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //sleep purpose
#include <stdbool.h>

typedef enum {RED, YELLOW, GREEN} Light;

typedef struct {
    Light traffic;
    Light pedestrian;
    int timer; 
} Lane;

void printLight(Light l) {
    if(l == RED) printf("RED   ");
    else if(l == YELLOW) printf("YELLOW");
    else printf("GREEN ");
}

void display(Lane lanes[], int numLanes) {
    printf("\nTraffic Lights Status:\n");
    for(int i=0; i<numLanes; i++){
        printf("Lane %d - Traffic: ", i+1);
        printLight(lanes[i].traffic);
        printf(" | Pedestrian: ");
        printLight(lanes[i].pedestrian);
        printf("\n");
    }
}

int main() {
    Lane lanes[2]; 
    int greenTime = 5;
    int yellowTime = 2;
    int redTime = 5;
    bool pedestrianRequest = false;

    
    for(int i=0;i<2;i++){
        lanes[i].traffic = RED;
        lanes[i].pedestrian = RED;
        lanes[i].timer = 0;
    }

    while(1) {
       
        lanes[0].traffic = GREEN;
        lanes[0].pedestrian = RED;
        lanes[1].traffic = RED;
        lanes[1].pedestrian = GREEN;
        display(lanes, 2);
        sleep(greenTime);

  
        lanes[0].traffic = YELLOW;
        lanes[0].pedestrian = RED;
        display(lanes,2);
        sleep(yellowTime);

       
        lanes[0].traffic = RED;
        lanes[0].pedestrian = GREEN;
        lanes[1].traffic = GREEN;
        lanes[1].pedestrian = RED;
        display(lanes,2);
        sleep(greenTime);

       
        lanes[1].traffic = YELLOW;
        lanes[1].pedestrian = RED;
        display(lanes,2);
        sleep(yellowTime);

        if(rand()%10 == 0) { 
            printf("\nEmergency vehicle detected! All lanes RED.\n");
            for(int i=0;i<2;i++){
                lanes[i].traffic = RED;
                lanes[i].pedestrian = RED;
            }
            display(lanes,2);
            sleep(3);
        }
    }

    return 0;
}