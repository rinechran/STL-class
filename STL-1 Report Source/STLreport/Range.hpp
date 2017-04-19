
#pragma once

#include <vector>

template <class T>
class impRange {
public:
	constexpr impRange(T _s, T _e);
	constexpr auto begin();
	constexpr auto end();
private:
	std::vector<T> _data;

};

template <class T>
constexpr auto Range(T _s, T _e);


template <class T>
constexpr auto Range(T _s, T _e) {
	return impRange<T>(_s, _e);
}

template<class T>
inline constexpr impRange<T>::impRange(T _s, T _e) {
	_data.reserve((int)_e - (int)_s);
	for (T i = _s; i < _e; ++i) {
		_data.push_back(i);
	}
}

template<class T>
inline constexpr auto impRange<T>::begin() {
	return _data.begin();
}

template<class T>
inline constexpr auto impRange<T>::end() {
	return _data.end();
}
