#include <vector>
#include <iostream>

struct Neuron;
template <typename Self>
struct SomeNeurons {
    template <typename T>
    void connect_to(T &other);
};

struct Neuron : SomeNeurons<Neuron> {
    std::vector<Neuron *> in, out;
    unsigned int id;
    Neuron() {
        static int id{1};
        this->id = id++;
    }

    void connect_to(Neuron &other) {
        out.push_back(&other);
        other.in.push_back(this);
    }

    Neuron *begin() { return this; }
    Neuron *end() { return this + 1; }

    friend std::ostream &operator<<(std::ostream &os, const Neuron &nr) {
        for (Neuron *n : nr.in) {
            os << n->id << "\t-->\t[" << nr.id << "]" << std::endl;
        }
        for (Neuron *n : nr.in) {
            os << "[" << nr.id << "]\t-->\t" << n->id << std::endl;
        }
        return os;
    }
};

struct NeuronLayer : std::vector<Neuron>, SomeNeurons<NeuronLayer> {
    NeuronLayer(int count) {
        while (count-- > 0) {
            emplace_back(Neuron{});
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const NeuronLayer &nl) {
        for (auto &n : nl) os << n;
        return os;
    }
};

template <typename Self>
template <typename T>
void SomeNeurons<Self>::connect_to(T &other) {
    for (Neuron &from : static_cast<Self *>(this)) {
        for (Neuron &to : other) {
            from.out.push_back(&other);
            to.in.push_back(&from);
        }
    }
}

int main() {
    Neuron n1, n2;
    n1.connect_to(n2);

    NeuronLayer l1{2}, l2{3};
    std::cout << l1 << std::endl;
    return 0;
}