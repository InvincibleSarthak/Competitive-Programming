//Unique Concept
//Number of zeroes depends upon the number of factors of 2 and 5 in the prime factors of the number. More precisely only the number of 5s
//We need to divide the number by i just to take care of that extra five that occurs in case of 25, 125, 625,...


int Solution::trailingZeroes(int A) {
    int count = 0; 
    for (int i = 5; A / i >= 1; i *= 5) 
        count += A / i; 
    return count; 
}
