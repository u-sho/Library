#include <utility>

#define divmod(n, d) std::make_pair((n) / (d), (n) % (d))

int main() {
	divmod(45, 7);  // [6, 3]
	divmod(7, 3);   // [2, 1]
}
