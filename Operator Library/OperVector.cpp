

#include "DenchicPts.h"
#include <vector>

//                          Operator Work

template<typename Type>
ostream& operator<<(ostream& out, const vector<Type>& vector) { // Вывод вектора через cout
	return out << '[' << Join(vector, ',') << ']';
}

istream& operator>>(istream& stream, vector<string>& vector) { // Вводит значения вектора string
	string i;
	cout << "Enter a space to finish." << endl;
	while (getline(stream, i)) {
		if (i == " ")
			break;
		vector.push_back(i);
	}
	return stream;
}
template<typename Type>
typename enable_if<!is_same<Type, char>::value,
	vector<Type>>::type
	// Складывает два вектора элементов одного типа и возвращает новый вектор (первая версия)
	operator+(const vector<Type>& p, const vector<Type>& m) {
	vector<Type> result;
	size_t minSize = min(p.size(), m.size());
	for (size_t i = 0; i < minSize; i++) {
		result.push_back(p[i] + m[i]);
	}
	if (p.size() > m.size())
		for (size_t i = minSize; i < p.size(); i++) {
			result.push_back(p[i]);
		}
	else
		for (size_t i = minSize; i < m.size(); i++) {
			result.push_back(m[i]);
		}

	return result;
}

template<typename Type1, typename Type2>
vector<typename common_type<Type1, Type2>::type>
// Складывает два вектора элементов разных типов и возвращает новый вектор (вторая версия)
operator+(const vector<Type1>& a, const vector<Type2>& b) {
	using ResultType = typename common_type<Type1, Type2>::type;
	vector<ResultType> result;

	size_t n = min(a.size(), b.size());
	for (size_t i = 0; i < n; ++i) {
		result.push_back(static_cast<ResultType>(a[i]) + static_cast<ResultType>(b[i]));
	}

	if (a.size() > n) {
		for (size_t i = n; i < a.size(); ++i) {
			result.push_back(static_cast<ResultType>(a[i]));
		}
	}
	else if (b.size() > n) {
		for (size_t i = n; i < b.size(); ++i) {
			result.push_back(static_cast<ResultType>(b[i]));
		}
	}

	return result;
}

template<typename Type>
typename enable_if<is_same<Type, int>::value || is_same<Type, float>::value || is_same<Type, double>::value,
	vector<Type>>::type
	// Вычитает один вектор из другого и возвращает новый вектор (для арифметических типов)
	operator-(const vector<Type>& p, const vector<Type>& m) {
	vector<Type> result;
	size_t minSize = min(p.size(), m.size());
	for (size_t i = 0; i < minSize; i++) {
		result.push_back(p[i] - m[i]);
	}
	if (p.size() > m.size()) {
		for (size_t i = minSize; i < p.size(); i++) {
			result.push_back(p[i]);
		}
	}
	else {
		for (size_t i = minSize; i < m.size(); i++) {
			result.push_back(-m[i]);
		}
	}
	return result;
}

template<typename Type, typename Type2>
typename enable_if<is_arithmetic<Type>::value&& is_arithmetic<Type2>::value,
	vector<float>>::type
	// Делит один вектор на другой и возвращает новый вектор (для арифметических типов) Варинт для типа float
	operator/(const vector<Type>& p, const vector<Type2>& m) {
	vector<float> result;
	size_t minSize = min(p.size(), m.size());
	for (size_t i = 0; i < minSize; i++) {
		result.push_back(static_cast<float>(p[i]) / static_cast<float>(m[i]));
	}
	if (p.size() > m.size()) {
		for (size_t i = minSize; i < p.size(); i++) {
			result.push_back(static_cast<float>(p[i]));
		}
	}
	else {
		for (size_t i = minSize; i < m.size(); i++) {
			result.push_back(1.0f);// деление на ноль в математике даёт 1 
		}
	}
	return result;
}

template<typename Type1, typename Type2>
typename enable_if<is_arithmetic<Type1>::value&& is_arithmetic<Type2>::value,
	vector<typename common_type<Type1, Type2>::type>>::type
	// Умножает один вектор на другой и возвращает новый вектор (для арифметических типов)
	operator*(const vector<Type1>& p, const vector<Type2>& m) {
	using ResultType = typename common_type<Type1, Type2>::type;
	vector<ResultType> result;
	size_t minSize = min(p.size(), m.size());
	for (size_t i = 0; i < minSize; i++) {
		result.push_back(static_cast<ResultType>(p[i]) * static_cast<ResultType>(m[i]));
	}
	if (p.size() > m.size()) {
		for (size_t i = minSize; i < p.size(); i++) {
			result.push_back(static_cast<ResultType>(p[i]));
		}
	}
	else {
		for (size_t i = minSize; i < m.size(); i++) {
			result.push_back(static_cast<ResultType>(m[i]));
		}
	}
	return result;
}

//                              Default Function
// 
// 
// Выводит на экран первые max элементов вектора
template<typename Type>
void VectorOut(const vector<Type>& vectr, const int& max) {
	for (size_t i = 0; i < max; i++)
	{
		cout << vectr[i] << " ";
	}
}
template<typename Type>
void VectorOut(const vector<Type>& vectr, const int& min, const int& max) {
	for (size_t i = min; i < max; i++)
	{
		cout << vectr[i] << " ";
	}
}
template <typename Type, typename = enable_if_t<is_arithmetic_v<Type>>>
void VectorFill(vector<Type>& vectr, const int max, size_t amount) {
	for (size_t i = 0; i < amount; i++)
		vectr.push_back(rand() % max);
}
template <typename Type, typename = enable_if_t<is_arithmetic_v<Type>>>
void VectorFill(vector<Type>& vectr, const int min, const int max, size_t amount) {
	for (size_t i = 0; i < amount; i++) {
		vectr.push_back(min + rand() % (max - min + 1));
	}
}


template <typename Type, typename = enable_if_t<is_arithmetic_v<Type>>>
vector<Type> VectorFill(const Type& max, const size_t& amount) {
	vector<Type> vectr;
	for (size_t i = 0; i < amount; i++)
		vectr.push_back(rand() % max);

	return vectr;
}