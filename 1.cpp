#include <iostream>
#include <random>
#include <set>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

vector<long int> GenerateAllRandomVector(const long int& n) {
    vector<long int> all_random_vector;
    all_random_vector.reserve(n);

    for (long int i = 0; i < n; i++) {
        all_random_vector.push_back(i);
    }

    long int size = all_random_vector.size();

    for (long int i = 0; i < n; i++) {
        long int k = rand() % (size - i);
        swap(all_random_vector[i], all_random_vector[k]);
    }

    return all_random_vector;
}

int main() {
    const long int n = 100000000;

    auto all_random_vector = GenerateAllRandomVector(n); // Создан вектор случайных чисел.

//    for (auto e : all_random_vector)
//        cout << e << " ";
//    cout << endl;

    set<long int> testing_set;
    auto time = clock();
    for (const auto& element : all_random_vector) // Инсёртим во множество случайные элементы
        testing_set.insert(element);
    cout << "inserting in set " << n << " elements takes: " << clock() - time << " ms" << endl;

    // Отсортируем all_random_vector
    time = clock();
    sort(all_random_vector.begin(), all_random_vector.end());
    cout << "sorting vector with " << n << " random elements takes: " << clock() - time << " ms" << endl;

    // Интересное наблюдение: для n = 100'000'000
    // inserting in set 100000000 elements takes: 109590 ms
    // sorting vector with 100000000 random elements takes: 251094 ms
    // заметны существенные отклонения в сложности
}
