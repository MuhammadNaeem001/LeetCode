class PeekingIterator : public Iterator {
private:
    bool hasPeeked;
    int peekedValue;

public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        hasPeeked = false;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!hasPeeked) {
            peekedValue = Iterator::next();
            hasPeeked = true;
        }
        return peekedValue;
    }

    // Returns the next element and advances the iterator.
    int next() {
        if (hasPeeked) {
            hasPeeked = false;
            return peekedValue;
        }
        return Iterator::next();
    }

    // Returns true if the iteration has more elements.
    bool hasNext() const {
        return hasPeeked || Iterator::hasNext();
    }
};
