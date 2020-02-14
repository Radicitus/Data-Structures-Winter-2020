#include "Wordset.hpp"
#include <string>
#include <cmath>

const int BASE_TO_USE = 37; 
const double LOAD_LIMIT = 0.25;



// returns s, as a number in the given base, mod the given modulus
int hashFunction(std::string s, int base, int mod)
{
    int stringSum = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
        stringSum += (s[i] - 'a') * int(pow(base, i));
    }
    return stringSum % mod;
}

WordSet::WordSet()
= default;

WordSet::~WordSet()
{
    delete[] bucket;
}

void WordSet::insert(std::string s)
{
    if ((entries + 1) / double(SIZES[bucketSize]) >= LOAD_LIMIT) {rehash();}

    bucket[probe(s, BASE_TO_USE, SIZES[bucketSize], bucket)] = s;



}

bool WordSet::contains(std::string s) const
{
    int hashCode = probe(s, BASE_TO_USE, SIZES[bucketSize], bucket);
    return !bucket[hashCode].empty();
}

// return how many distinct strings are in the set
int WordSet::getCount() const
{
	return entries;
}

// return how large the underlying array is.
int WordSet::getCapacity() const
{
    return SIZES[bucketSize];
}

void WordSet::rehash() {
    bucketSize++;
    auto * tempBucket = new std::string[SIZES[bucketSize]];
    for (int i = 0; i < SIZES[bucketSize - 1]; ++i) {
        if (bucket[i].empty()) { continue;} //Skip over the loop if the value is empty string
        tempBucket[probe(bucket[i], BASE_TO_USE, SIZES[bucketSize], tempBucket)] = bucket[i];
    }
    delete[] bucket;
    bucket = tempBucket;
}

int WordSet::probe(std::string & string, int base, int size, std::string * b) {

    unsigned int probeCounter = 0;
    int hashCode = hashFunction(string, base, size);
    while (!b[hashCode].empty() || b[hashCode] != string) {
        hashCode = (hashCode + int(pow(probeCounter, 2))) % size;
        probeCounter++;
    }

    return hashCode;
}