// We know that if the k-th bulb has n different factors,
// it will be toggled n times. if n is odd, the bulb will
// be turned on finally or otherwise be turned off.
// We also know that if p is a factor of k, then k / p must
// also be a factor of p. Usually, n should be even because 
// the factor p and k / p always appear pairwisely, except for 
// one situation, when p = k / p. In this case, p and k / p 
// are the same numbers, which indicates that k is squre of p.
// So we can draw a conclusion that if k is a squre number,
// then the bulb will be keeped on, or it will be turned off.

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
