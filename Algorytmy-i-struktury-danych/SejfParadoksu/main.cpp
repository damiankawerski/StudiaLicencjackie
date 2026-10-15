#include <iostream>
using namespace std;

void double_insertion_sort(string *product_names, int *product_weights, int n) {
    for(int i = 1; i < n; i++) {
        string inserted_product_name = product_names[i];
        int inserted_product_weight = product_weights[i];
        int j = i - 1;
        while(j >= 0 && product_weights[j] > inserted_product_weight) {
            product_names[j + 1] = product_names[j];
            product_weights[j + 1] = product_weights[j];
            j = j - 1;
        }
        product_names[j + 1] = inserted_product_name;
        product_weights[j + 1] = inserted_product_weight;
    }
}

long minimal_energy(int *product_weights, int n) {
    long weight_in_array = 0;
    long energy = 0;
    for(int i = 0; i < n; i++) {
        energy += weight_in_array + product_weights[i];
        weight_in_array += product_weights[i];
    }
    return energy;
}

void print_products(string *product_names, int n) {
    for(int i = 0; i < n; i++) {
        cout << product_names[i] << " ";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string product_names[n];
        int product_weights[n];
        for(int i = 0; i < n; i++) {
            cin >> product_names[i] >> product_weights[i];
        }
        double_insertion_sort(product_names, product_weights, n);
        cout << minimal_energy(product_weights, n) << endl;
        print_products(product_names, n);
    }
    return 0;
}

// 2
// 5
// rower_elektryczny-1453 12
// smartfon-1890 1
// dron_z_kamera-2000pne 4
// przenosna_lodowka-753 8
// teleporter_do_kawy-2024 4
// 3
// skaner_mysli-1984 7
// teletransporter-3210pne 133
// noktowizor-1410 1