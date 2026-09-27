#include <cstddef>
#include <vector>

int main() {
    const std::vector<int> values{10, 20, 30};
    for (std::size_t i = 0; i < values.size(); ++i) {
        (void)values.at(i);
    }
}
