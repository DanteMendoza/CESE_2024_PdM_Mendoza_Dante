#include "API_hcsr04FSM.h"

#define NEAR_VALUE 30
#define NORMAL_VALUE_LOW 31
#define NORMAL_VALUE_HIGH 69
#define FAR_VALUE 70

// Variable de estado (global)
static hcsr04State_t hcsr04State = NEAR_STATE;

// Inicialización de la máquina de estados finitos
void hcsr04FSM_init(void) {
	hcsr04State = NEAR_STATE;
}

// Función para actualizar la máquina de estados finitos
void hcsr04FSM_update(uint16_t distance) {
    // Lógica para la transición de estados
    switch (hcsr04State) {
        case NEAR_STATE:
            if (distance <= NEAR_VALUE) {
                hcsr04State = NEAR_STATE;
            } else if (distance >= NORMAL_VALUE_LOW && distance <= NORMAL_VALUE_HIGH) {
                hcsr04State = NORMAL_STATE;
            } else {
                hcsr04State = FAR_STATE;
            }
            break;

        case NORMAL_STATE:
            if (distance <= NEAR_VALUE) {
                hcsr04State = NEAR_STATE;
            } else if (distance >= NORMAL_VALUE_LOW && distance <= NORMAL_VALUE_HIGH) {
                hcsr04State = NORMAL_STATE;
            } else {
                hcsr04State = FAR_STATE;
            }
            break;

        case FAR_STATE:
            if (distance >= FAR_VALUE) {
                hcsr04State = FAR_STATE;
            } else if (distance >= NORMAL_VALUE_LOW && distance <= NORMAL_VALUE_HIGH) {
                hcsr04State = NORMAL_STATE;
            } else {
                hcsr04State = NEAR_STATE;
            }
            break;

        default:
        	hcsr04FSM_init();
            break;
    }
}
