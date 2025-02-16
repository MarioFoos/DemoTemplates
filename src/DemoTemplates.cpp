#include <iostream>
#include <vector>
#include <type_traits>
#include <concepts>

using namespace std;

// Función template
template<typename T>
T getMax(T a, T b)
{
	return (a > b) ? a : b;
}

// Clase template
template <typename T1, typename T2>
class Pair
{
	private:
	    T1 first_;
	    T2 second_;	public:
	public:
	    // Constructor que inicializa los miembros
	    Pair(const T1& first, const T2& second)
	        : first_(first), second_(second) {}
		virtual ~Pair(){}

	    // Métodos para obtener los valores almacenados
	    T1 first() const { return first_; }
	    T2 second() const { return second_; }

};

// Función base (caso de terminación)
void printArgs()
{
    std::cout << std::endl;
}

// Función recursiva que imprime cada argumento
template<typename T, typename... Args>
void printArgs(T first, Args... args)
{
    std::cout << first << " ";
    printArgs(args...);
}

// Alias para std::vector<T>
template<typename T>
using Vec = std::vector<T>;

// Función template que solo se habilita si T es un tipo entero
template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type getSquare(T x)
{
	return x*x;
}

// Función template con auto
template<typename T, typename U>
auto sumar(T a, U b)
{
	return a + b;
}

// Template con uso de if constexpr
template<typename T>
void checkType(T x)
{
	if constexpr(std::is_integral_v<T>)
	{
		std::cout << "Es un tipo integral" << endl;
	}
	else
	{
		std::cout << "No es un tipo integral" << endl;
	}
}

// Fold expression para sumar todos los argumentos
template<typename ... Args>
auto sumatoria(Args ... args)
{
	return (args + ...);
}

// Fold expression para imprimir todos los argumentos
template<typename... Args>
void imprimir(Args... args)
{
    ((std::cout << args << " "), ...);
    std::cout << "\n";
}

// Clase para probar la deducción de tipo
template<typename T>
class SimpleClass
{
	private:
		T value;
	public:
		SimpleClass(T _value) : value(_value){}
};

// Definición de un concept que requiere que un tipo sea integral
template<typename T>
concept Entero = std::integral<T>;

template<Entero T>
T duplicar(T x) {
    return 2*x;
}

// Una función que suma dos números, pero solo si el tipo admite la operación de suma.
template<typename T>
requires std::integral<T> || std::floating_point<T>
T triplicar(T a)
{
	return 3*a;
}

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();

int main()
{
	//test1();
	//test2();
	//Vec<int> numeros = {1, 2, 3, 4};
	//test3();
	//test4();
    //SimpleClass w{123};  // Se deduce que T es int
	//test6();
	//test7();

	//std::cout << "duplicar: " << duplicar(6) << std::endl;

	std::cout << "triplicar: " << triplicar(6) << std::endl;

	return 0;
}

void test7()
{
	std::cout << sumatoria(1, 2, 3, 4, 5) << std::endl;

	imprimir(7, "Hola", 9.8);
}

void test6()
{
	checkType(5);
	checkType(3.14);
}

void test5()
{
	std::cout << sumar(5, 6.5) << endl;
	std::cout << sumar(4, 3) << endl;
}

void test4()
{
    auto lambda = [](auto a, auto b) { return a + b; };

    std::cout << lambda(2, 3) << std::endl;
    std::cout << lambda(2.5, 3.5) << std::endl;
}

void test3()
{
	int n1 = 5;
	long int n2 = 3;

	std::cout << getSquare(n1) << std::endl;
	std::cout << getSquare(n2) << std::endl;
	//std::cout << square(5.5);		// Error de compilación
}

void test2()
{
    // Imprimir varios valores de distintos tipo
    printArgs(7, "Hola", 9.8);
}
void test1()
{
	// Uso de la función plantilla para dos tipos distintos
    int a = 10, b = 20;
    std::cout << "Max entre " << a << " y " << b << " es " << max(a, b) << "\n";

    double x = 15.5, y = 12.3;
    std::cout << "Max entre " << x << " y " << y << " es " << max(x, y) << "\n";

    // Instanciación de Pair con int y double
    Pair<int, double> p1(17, 9.8);
    std::cout << "p1: (" << p1.first() << ", " << p1.second() << ")\n";

    // Instanciación de Pair con std::string y int
    Pair<std::string, int> p2("Primero", 20);
    std::cout << "p2: (" << p2.first() << ", " << p2.second() << ")\n";
}
