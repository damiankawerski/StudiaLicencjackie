#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>

class TreeType {
public:
    std::string name;
    std::string color;
    std::string texture;

    TreeType(const std::string& name, const std::string& color, const std::string& texture)
        : name(name), color(color), texture(texture) {}

    void draw(int x, int y) const {
        std::cout << "Rysuję drzewo: " << name << " z kolorem " << color
                  << " i teksturą " << texture << " na (" << x << ", " << y << ")\n";
    }
};

class TreeFactory {
private:
    std::unordered_map<std::string, std::shared_ptr<TreeType>> types;

public:
    std::shared_ptr<TreeType> getTreeType(const std::string& name, const std::string& color, const std::string& texture) {
        std::string key = name + "_" + color + "_" + texture;
        if (types.find(key) == types.end()) {
            types[key] = std::make_shared<TreeType>(name, color, texture);
        }
        return types[key];
    }
};

class Tree {
private:
    int x, y;
    std::shared_ptr<TreeType> type;

public:
    Tree(int x, int y, std::shared_ptr<TreeType> type) : x(x), y(y), type(type) {}

    void draw() const {
        type->draw(x, y);
    }
};

class Forest {
private:
    std::vector<Tree> trees;
    TreeFactory factory;

public:
    void plantTree(int x, int y, const std::string& name, const std::string& color, const std::string& texture) {
        auto type = factory.getTreeType(name, color, texture);
        trees.emplace_back(x, y, type);
    }

    void draw() const {
        for (const auto& tree : trees)
            tree.draw();
    }
};


int main() {
    Forest forest;
    forest.plantTree(1, 2, "Dąb", "Zielony", "Liście1");
    forest.plantTree(3, 4, "Dąb", "Zielony", "Liście1");
    forest.plantTree(5, 6, "Sosna", "Ciemnozielony", "Igły");

    forest.draw();

    return 0;
}
