
#include <iostream>
#include <cstdint>

class Power
{
public:
    Power(float _a = 3.1415, float _b = 2.718) {
        a = _a, b = _b;
    }
    void set(float a_val, float b_val) {
        a = a_val;
        b = b_val;
    }
    float calculate() {
        return pow(a, b);
    }
private:
    float a;
    float b;
    float result;
};



class RGBA
{
public:
    RGBA(uint8_t _R, uint8_t _G, uint8_t _B, uint8_t _A) {
        m_red = _R, m_green = _G, m_blue = _B, m_alpha = _A;
    }
    void print_rgba();
private:
    std::uint8_t m_red, m_green, m_blue, m_alpha;
};

void RGBA::print_rgba() {
    std::cout << "\n";
    std::cout << m_red + 0 << " " << m_green + 0 << " " << m_blue + 0 << " " << m_alpha + 0 << std::endl;
}


class Stack
{
public:
    void reset() {
        for (int i = 0; i < 10; i++) {
            Arr[i] = 0;
        };
        deep = 0;
    }
    bool push(int _val) {
        if (deep == 10) return false;
        for (int i = deep; i > 0; i--) {
            Arr[i] = Arr[i - 1];
        }
        Arr[0] = _val;
        deep++;
        return true;
    }
    int pop() {
        deep--;
        int ret = Arr[0];
        for (int i = 0; i < deep; i++) {
            Arr[i] = Arr[i + 1];
        }
        return ret;
    }
    void print() {
        std::cout << "\n";
        std::cout << "( ";
        for (int i = deep; i > 0; i--) {
            std::cout << Arr[i - 1] << " ";
        };
        std::cout << ")" << std::endl;
    }
private:
    int Arr[10];
    int deep;
};

int main()
{
    //_____________1_____________________
    Power P;
    std::cout << P.calculate();
    P.set(5.32, 3.23);
    std::cout << "\n";
    std::cout << P.calculate();

    //_____________2_____________________
    RGBA light(0, 0, 0, 255);
    light.print_rgba();

    //_____________3_____________________
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    // stack.print();
    stack.push(7);
    // stack.print();
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
