#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> heap;
    bool is_min_heap;

    // ta funkcja przywraca własności kopca w przypadku DODANIA ELEMENTU - instert
    void heap_up() {
        int index = heap.size() - 1;
        while (index > 0) {
            int parent = (index - 1) / 2;
            if ((is_min_heap && heap[index] < heap[parent]) || (!is_min_heap && heap[index] > heap[parent])) { // minimalny || maksymalny kopiec - po prostu wstawiamy w tablicy jak w sorted_array
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Ta funkcja służy do przywracania własności kopca w przypadku USUNIECIA ELEMENTU - extract i change_max_val
    void heap_down(int index) {
        int size = heap.size();
        while (index < size) {
            int root = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && ((is_min_heap && heap[left] < heap[root]) || (!is_min_heap && heap[left] > heap[root]))) {
                root = left;
            }
            if (right < size && ((is_min_heap && heap[right] < heap[root]) || (!is_min_heap && heap[right] > heap[root]))) {
                root = right;
            }

            if (root != index) {
                swap(heap[index], heap[root]);
                index = root;
            } else {
                break;
            }
        }
    }

public:

    Heap(bool is_min_heap) {
        this->is_min_heap = is_min_heap;
    }

    // Dajemy size - 1 bo ostatni element jest dodany
    void insert(int value) {
        heap.push_back(value);
        heap_up();
    }

    void print() {
        for(int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    bool is_empty() {
        return heap.empty();
    }

    void change_max_val(int new_val) {
        if(heap.empty()) {
            return;
        }

        heap[0] += new_val;

        heap_down(0);
    }

    int extract_root() {
        if(heap.empty()) {
            return 0;
        }
        int top = heap[0];     //  Pobieram wartość ekstremanlna
        heap[0] = heap.back(); // Zamieniam zeby przechować wartość
        heap.pop_back();        // Usuwam ostatnią bo dałem na początek
        heap_down(0);     // Przywracam własność kopca
        return top;
    }

    int get_root() {
        return heap[0];
    }
};

int calculate_tax(Heap& min_heap, Heap& max_heap) {
    int tax = 0;

    while(!max_heap.is_empty() && !min_heap.is_empty()) {
        int min_val = min_heap.extract_root();
        int max_val = max_heap.extract_root();

        tax += max_val * min_val;
    }

    return tax;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int clients;
    cin >> clients;

    while(clients--) {
        Heap min_heap(true);
        Heap max_heap(false);
        int products;
        cin >> products;

        while(products--) {
            int value;
            char action;
            cin >> action;

            if(action == 'a') {
                cin >> value;
                max_heap.insert(value);
                cin >> value;
                min_heap.insert(value);
            }
            if(action == 'p' && !max_heap.is_empty()) {
                cin >> value;
                if(max_heap.get_root() + value > 0) {
                    max_heap.change_max_val(value);
                }
            } else if (action == 'p' && max_heap.is_empty()) {
                cin >> value;
            }
        }
//        cout << "Min heap: ";
//        min_heap.print();
//        cout << "Max heap: ";
//        max_heap.print();
        cout << calculate_tax(min_heap, max_heap) << endl;
    }
}
