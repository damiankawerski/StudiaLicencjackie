#include <iostream>
#include <climits>
using namespace std;

struct client_node {
    long long processing_time;
    client_node *next;
};

class fifo_queue {
private:
    client_node *head;
    client_node *tail;
    long long size;
public:
    fifo_queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    bool is_empty() {
        return head == nullptr;
    }

    void add_last(long long time_to_process) {
        client_node* new_client = new client_node;
        new_client->processing_time = time_to_process;
        new_client->next = nullptr;

        if (is_empty()) {
            head = new_client;
            tail = new_client;
        } else {
            tail->next = new_client;
            tail = new_client;
        }
        size++;
    }

    void remove_first() {
        if (is_empty()) {
            return;
        }

        client_node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    client_node* get_head() {
        return head;
    }

    long long get_size() const {
        return size;
    }
};

class cash_register {
public:
    fifo_queue queue;
    long long waiting_time;
    char flag;

    cash_register() {
        waiting_time = 0;
        flag = 'z';
    }

    void set_flag(char flag) {
        this->flag = flag;
    }

    void add_client(long long time_to_process) {
        queue.add_last(time_to_process);
        waiting_time += time_to_process;
    }

    long long get_size() {
        return queue.get_size();
    }

    void remove_first() {
        queue.remove_first();
    }

    void process_clients(long long time) {
        while(time > 0 && !queue.is_empty()) {
            time--;
            queue.get_head()->processing_time--;
            waiting_time--;
            if(queue.get_head()->processing_time <= 0) {
                queue.remove_first();
                if (queue.is_empty()) {
                    break;
                }
            }
        }
    }
};

long long find_shortest_line_by_time(cash_register* registers, long long num_registers) {
    long long shortest_line = -1;
    long long shortest_time = LLONG_MAX;
    for (long long i = 0; i < num_registers; i++) {
        if(registers[i].flag == 'o' && registers[i].waiting_time < shortest_time) {
            shortest_time = registers[i].waiting_time;
            shortest_line = i;
        }
    }
    return shortest_line;
}

void show_results(cash_register registers[], long long num_registers) {
    for (long long j = 0; j < num_registers - 1; j++) {
        if(registers[j].flag == 'z') {
            cout << "K" << j << ": z, ";
        } else if(registers[j].flag == 'o') {
            cout << "K" << j << ": " << registers[j].get_size() << "o " << registers[j].waiting_time << "s, ";
        }
    }
    if(registers[num_registers - 1].flag == 'z') {
        cout << "K" << num_registers - 1 << ": z";
    } else if(registers[num_registers - 1].flag == 'o') {
        cout << "K" << num_registers - 1 << ": " << registers[num_registers - 1].get_size() << "o " << registers[num_registers - 1].waiting_time << "s";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    long long simulation_time, num_registers, efficiency, time_to_pay;
    cin >> simulation_time >> num_registers >> efficiency >> time_to_pay;
    cash_register registers[num_registers];
    while(simulation_time > 0) {
        char flag;
        cin >> flag;
        if(flag == 'o') {
            long long index;
            cin >> index;
            registers[index].set_flag(flag);
        } else if (flag == 'z') {
            long long index;
            cin >> index;
            registers[index].set_flag(flag);
            registers[index].remove_first();
            while(!registers[index].queue.is_empty()) {
                long long shortest_line = find_shortest_line_by_time(registers, num_registers);
                registers[shortest_line].add_client(registers[index].queue.get_head()->processing_time);
                registers[index].remove_first();
                registers[index].waiting_time = 0;
            }
        } else if (flag == 'k') {
            long long time, items;
            cin >> time >> items;
            if(simulation_time - time < 0) {
                time = simulation_time;
                for(long long i = 0; i < num_registers; i++) {
                    if(registers[i].flag == 'o') {
                        registers[i].process_clients(time);
                    }
                }
                break;
            }
            for(long long i = 0; i < num_registers; i++) {
                if(registers[i].flag == 'o') {
                    registers[i].process_clients(time);
                }
            }
            long long shortest_line = find_shortest_line_by_time(registers, num_registers);
            registers[shortest_line].add_client(items * efficiency + time_to_pay);
            simulation_time -= time;
        }
    }
    show_results(registers, num_registers);
    return 0;
}