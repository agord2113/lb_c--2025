#include <iostream>

class Tree {
public:
    virtual void draw() {
        std::cout << "Base Tree Drawing" << std::endl;
    }
};

class Tree1 : public Tree {
public:
    void draw() override {
        std::cout << "Drawing 1:" << std::endl;
        std::cout << "  八" << std::endl;
        std::cout << " //\\\\" << std::endl;
    }
};

class Tree2 : public Tree {
public:
    void draw() override {
        std::cout << "Drawing 2:" << std::endl;
        std::cout << "  A" << std::endl;
        std::cout << " /** " << std::endl;
    }
};

class Tree3 : public Tree {
public:
    void draw() override {
        std::cout << "Drawing 3:" << std::endl;
        std::cout << "  A" << std::endl;
        std::cout << " /++\\" << std::endl;
    }
};

int main() {
    Tree* trees[3];

    trees[0] = new Tree1();
    trees[1] = new Tree2();
    trees[2] = new Tree3();

    for (int i = 0; i < 3; ++i) {
        trees[i]->draw();
        std::cout << std::endl;
    }

    // Clean up memory
    for (int i = 0; i < 3; ++i) {
        delete trees[i];
    }

    return 0;
}
