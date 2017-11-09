#include <iostream>
#include <vector>

class List {
public:
    explicit List(size_t size) {
        cursor = 0;
        for (size_t i = 0; i<size; i++) {
            list.push_back(1);
        }
    }

    int getNextTrue() {
        while (true) {
            next();
            if (list[cursor] == 1) {
                return cursor;
            }
        }
    }

    inline void nextRound() {
        for (int i = 0; i < 8; i++) {
            cursor = getNextTrue();
        }
    }

    inline int getCursor() const {
        return cursor;
    }

    inline void setCursor(int index) {
        cursor = index;
    }

    inline void set(int index, bool color) {
        list[index] = color;
    }

    inline bool getCurrent() const {
        return list[cursor];
    }

    inline bool at(int index) const {
        return list[index];
    }

private:
    inline void next() {
        if (cursor == (list.size() - 1)) {
            cursor = 0;
        }
        else {
            cursor++;
        }
    }
    std::vector<int> list;
    size_t cursor;
};

int main() {
    int n;
    std::cin >> n;

    List believer(n * 2);

    int drop = 0;

    while (drop != n) {
        believer.nextRound();

        if (believer.getCurrent() == 1) {
            believer.set(believer.getCursor(), 0);
        }
        else {
            int index = believer.getNextTrue();
            believer.set(index, 0);
        }

        believer.setCursor(believer.getNextTrue());
        drop++;
    }

    for (int k = 0; k<n * 2; k++) {
        if (believer.at(k) == 1) {
            std::cout << "@";
        }
        else {
            std::cout << "+";
        }
    }
    std::cout<<"\n";
    return 0;
}
