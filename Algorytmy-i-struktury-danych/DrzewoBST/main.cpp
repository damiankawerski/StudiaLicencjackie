#include <iostream>

using namespace std;

struct frequency_node {
    int counter;
    int frequency;
    int wave_length;
    frequency_node* right;
    frequency_node* left;

    frequency_node(int frequency, int wave_length) {
        this->frequency = frequency;
        this->right = nullptr;
        this->left = nullptr;
        this->wave_length = wave_length;
        this->counter = 1;
    }
};

class frequency_bst_tree {
public:
    frequency_node* root;

    frequency_bst_tree() {
        this->root = nullptr;
    }

    frequency_node* insert(frequency_node* node, int frequency, int wave_length) {
        if(node == nullptr)
            return new frequency_node(frequency, wave_length);
        if(frequency < node->frequency)
            node->left = insert(node->left, frequency, wave_length);
        else if(frequency > node->frequency)
            node->right = insert(node->right, frequency, wave_length);
        else if (wave_length > node->wave_length) {
            node->right = insert(node->right, frequency, wave_length);
        } else if (wave_length < node->wave_length) {
            node->left = insert(node->left, frequency, wave_length);
        } else {
            node->counter++;
        }

        return node;
    }

    void in_order(frequency_node* node) {
        if(node == nullptr)
            return;
        in_order(node->left);
        for(int i = 0; i < node->counter; i++) {
            cout << "(" << node->frequency << "," << node->wave_length << ") ";
        }
        in_order(node->right);
    }
};

struct year_node {
    int year;
    year_node* right;
    year_node* left;
    frequency_bst_tree* frequency_tree;

    year_node(int year, int frequency, int wave_length) {
        this->year = year;
        this->right = nullptr;
        this->left = nullptr;
        this->frequency_tree = new frequency_bst_tree();
        this->frequency_tree->root = this->frequency_tree->insert(this->frequency_tree->root, frequency, wave_length);
    }
};

class year_bst_tree {
public:
    year_node* root;

    year_bst_tree() {
        this->root = nullptr;
    }

    year_node* insert(year_node* node, int year, int frequency, int wave_length) {
        if(node == nullptr)
            return new year_node(year, frequency, wave_length);
        if(year < node->year)
            node->left = insert(node->left, year, frequency, wave_length);
        else if(year > node->year)
            node->right = insert(node->right, year, frequency, wave_length);
        else
            node->frequency_tree->root = node->frequency_tree->insert(node->frequency_tree->root, frequency, wave_length);
        return node;
    }

    void in_order(year_node* node) {
        if(node == nullptr)
            return;
        in_order(node->left);
        cout << node->year << ": ";
        node->frequency_tree->in_order(node->frequency_tree->root);
        cout << '\n';
        in_order(node->right);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int time_travels;
    bool is_ready = true;
    int years;
    float frequency, wave_length;
    cin >> time_travels;
    year_bst_tree* year_tree = new year_bst_tree();

    while (time_travels > 0) {
        time_travels--;

        cin >> years >> frequency >> wave_length;

        float sound_speed = frequency * wave_length / 100;

        if((frequency > 20000 || frequency < 20) || (sound_speed < 313 || sound_speed > 350)) {
            continue;
        }

        if(year_tree->root == nullptr) {
            year_tree->root = year_tree->insert(year_tree->root, years, static_cast<int>(frequency), static_cast<int>(wave_length));
            continue;
        }

        if(frequency < 275 || frequency > 325) {
            is_ready = false;
        }

        year_tree->root = year_tree->insert(year_tree->root, years, static_cast<int>(frequency), static_cast<int>(wave_length));
    }

    if(year_tree->root == nullptr) {
        cout << "NIE\n";
        return 0;
    }

    year_tree->in_order(year_tree->root);
    string result = is_ready ? "TAK" : "NIE";
    cout << result << '\n';
    delete year_tree;
    return 0;
}