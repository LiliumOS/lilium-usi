
#include <stdlib.h>
#include <random.h>
#include <stdint.h>

#define DISTORT_ONE (0x6a09e667f3bcc908ULL)
#define DISTORT_TWO (0xbb67ae8584caa73bULL)

#define STRETCH (0xCE95CE95UL)

#define A_ONE (777206658847ULL)
#define A_TWO (603803122327ULL)

#define C_ONE (13ULL)
#define C_TWO (257ULL)

#define MASK (0xFFFFFFFFFFFFULL)

#define __LEFT_ROTATE64(__val, __n) (((__val)<<__n) | ((__val) >> (64-__n)))

#define STRETCH_SEED(__seed)  ((__LEFT_ROTATE64(__seed, 11) ^ __LEFT_ROTATE64(__seed, 17)) + (__LEFT_ROTATE64(__seed, 23) ^ __LEFT_ROTATE64(__seed, 31))) 

#define INIT_SEED (STRETCH_SEED(STRETCH))

#define SEED_CALC(__seed, __a, __b) (((((__seed) >> 32) ^ (__seed)) * (__a) + (__b)) & MASK)

#define SEED_CALC1(__seed) SEED_CALC((__seed) ^ DISTORT_ONE, A_TWO, C_ONE)
#define SEED_CALC2(__seed) SEED_CALC((__seed) ^ DISTORT_TWO, A_ONE, C_TWO)

static struct rand_state {
    uint64_t state1;
    uint64_t state2;
} __rand_state = {.state1 = SEED_CALC1(INIT_SEED), .state2 = SEED_CALC2(INIT_SEED)};

void srand(unsigned seed) {
    uint64_t cast_seed = ((uint64_t)seed) * STRETCH;
    uint64_t seed_stretch = STRETCH_SEED(cast_seed);
    __rand_state.state1 = SEED_CALC1(seed_stretch);
    __rand_state.state2 = SEED_CALC2(seed_stretch);
}



int rand(void) {
    uint64_t cross = __rand_state.state1;
    __rand_state.state1 = (__rand_state.state1 * A_ONE + C_ONE) & MASK;
    __rand_state.state2 = (__rand_state.state2 * A_TWO + C_ONE) & MASK;
    

    int res = (__rand_state.state1 ^ __rand_state.state2) >> 17;

    uint64_t temp = __rand_state.state1;
    __rand_state.state1 = ((__rand_state.state2 * A_ONE + cross) & MASK);
    __rand_state.state2 = (temp * A_TWO + C_ONE) & MASK;
    
    return res;

}

