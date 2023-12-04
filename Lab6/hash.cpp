#include <math.h>
#include <string.h>

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int foldShift(long long key, int addressSize) {
    string str = to_string(key);
    int sum = 0;
    for (int i = 0; i < static_cast<int>(str.length()); i += addressSize) {
        string chunk = str.substr(i, addressSize);
        sum += stoi(chunk);
    }
    int modulo = 1;
    for (int i = 0; i < addressSize; i++) {
        modulo *= 10;
    }
    return sum % modulo;
}

int rotation(long long key, int addressSize) {
    string str = to_string(key);
    char rotatePart = str.back();
    str.pop_back();
    str = rotatePart + str;
    long long rotatedKey = stoll(str);

    return foldShift(rotatedKey, addressSize);
}

long int midSquare(long int seed) {
    int square = seed * seed;
    return (square / 100) % 10000;
}
long int moduloDivision(long int seed, long int mod) {
    return seed % mod;
}
long int digitExtraction(long int seed, int* extractDigits, int size) {
    int add = 0;
    int e = 0;
    int t_seed = seed;
    int s_size = 0;
    while (t_seed > 0) {
        t_seed /= 10;
        s_size++;
    }
    for (int i = 0; i < size; i++) {
        int modi = pow(10, s_size - extractDigits[i]);
        e = ((seed % modi) - (seed % (modi / 10))) / (modi / 10);
        e *= pow(10, size - i - 1);
        add += e;
    }
    return add;
}

int pairMatching(vector<int>& nums, int target) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    int pairs = 0;
    for (int num : nums) {
        int complement = target - num;
        if (freq[num] > 0 && freq[complement] > 0) {
            if (num == complement && freq[num] < 2) {
                continue;
            }
            pairs++;
            freq[num]--;
            freq[complement]--;
        }
    }

    return pairs;
}