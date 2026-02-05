/********
 * Fichier: vecteur.hpp
 * Auteurs: A. Samson
 * Date: 02 février 2026
 * Description: Déclaration de la classe Vecteur 
 * et implémentation de ses méthodes.
 *
 * Ce fichier ne fait pas partie de la distribution de Graphicus.
********/
#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <cassert>
#include <new>
#include <fstream>

using namespace std;

template<class TYPE>
class Vecteur {
private:
	TYPE* _tab;
	int _dim;
	int _currentIndex;

public:
	Vecteur(); 
	Vecteur(int dim);
	Vecteur(const Vecteur<TYPE>& vec);
	~Vecteur();

	int size() const;
	void clear();
	void push_back(const TYPE& value);
	void remove(int index);
	void print(std::ostream& output) const;
	void resize(int newDim);
	TYPE& at(int index) const;
	bool isEmpty() const;

	int getCurrentIndex() const;
	void setCurrentIndex(int index);
	TYPE& getCurrentItem() const;

	const bool operator==(const Vecteur<TYPE>& vect) const;
	const Vecteur<TYPE>& operator=(const Vecteur<TYPE>& vect);
	Vecteur<TYPE> operator+(const Vecteur<TYPE>& vect) const;
	const Vecteur<TYPE> operator+=(const Vecteur<TYPE>& vect);
	TYPE& operator[](int position) const;

	Vecteur<TYPE>& operator++();  // Pré-incrémentation: passe à l'item suivant
	Vecteur<TYPE>& operator--();  // Pré-décrémentation: passe à l'item précédent

	friend ostream& operator<<(ostream& output, const Vecteur<TYPE>& vec);
	friend istream& operator>>(istream& input, Vecteur<TYPE>& vec);
};

template<class TYPE>
Vecteur<TYPE>::Vecteur() {
	_tab = nullptr;
	_dim = 0;
	_currentIndex = 0;
}

template<class TYPE>
Vecteur<TYPE>::Vecteur(int dim) {
	assert(dim >= 0);

	if (dim == 0) {
		_dim = 0;
		_tab = nullptr;
		_currentIndex = 0;
	}
	else {
		try {
			_dim = dim;
			_tab = new TYPE[dim];
			_currentIndex = 0;
		}
		catch (bad_alloc) {
			exit(EXIT_FAILURE);
		}
	}
}

template<class TYPE>
Vecteur<TYPE>::Vecteur(const Vecteur<TYPE>& vec) {
	if (vec._dim == 0) {
		_tab = nullptr;
		_dim = 0;
		_currentIndex = 0;
	}
	else {
		_dim = vec._dim;
		_tab = new TYPE[vec._dim];
		_currentIndex = vec._currentIndex;

		for (int i = 0; i < _dim; i++)
			*(_tab + i) = *(vec._tab + i);
	}
}

template<class TYPE>
Vecteur<TYPE>::~Vecteur() {
	clear();
}

template<class TYPE>
int Vecteur<TYPE>::size() const {
	return _dim;
}

template<class TYPE>
void Vecteur<TYPE>::clear() {
	delete[] _tab;
	_tab = nullptr;
	_dim = 0;
	_currentIndex = 0;
}

template<class TYPE>
void Vecteur<TYPE>::push_back(const TYPE& value) {
	_dim++;
	TYPE* newTab = new TYPE[_dim];

	for (int i = 0; i < _dim - 1; i++)
		*(newTab + i) = *(_tab + i);

	*(newTab + (_dim - 1)) = value;
	delete[] _tab;

	_tab = newTab;
}

template<class TYPE>
void Vecteur<TYPE>::remove(int index) {
	assert(index >= 0 && index < _dim);
	if (_dim == 1) {
		clear();
	}
	else {
		TYPE* newTab = new TYPE[_dim - 1];
		for (int i = 0, j = 0; i < _dim; i++) {
			if (i != index) {
				*(newTab + j) = *(_tab + i);
				j++;
			}
		}
		delete[] _tab;
		_tab = newTab;
		_dim--;
	}
}

template<class TYPE>
void Vecteur<TYPE>::print(std::ostream& output) const {
	for (int i = 0; i < _dim; i++)
		output << *(_tab + i) << " ";
}

template<class TYPE>
void Vecteur<TYPE>::resize(int newDim) {
	assert(newDim >= 0);

	if (_dim == newDim)
		return;
	if (newDim == 0)
		clear();
	else {
		TYPE* newTab = new TYPE[newDim];
		for (int i = 0; (i < _dim && i < newDim); i++)
			*(newTab + i) = *(_tab + i);
		delete _tab;
		_tab = newTab;
		_dim = newDim;
	}
}
template<class TYPE>
TYPE& Vecteur<TYPE>::at(int index) const {
	assert(index >= 0 && index < _dim);
	return *(_tab + index);
}

template<class TYPE>
inline bool Vecteur<TYPE>::isEmpty() const {
	return _dim == 0;
}

template<class TYPE>
int Vecteur<TYPE>::getCurrentIndex() const {
	return _currentIndex;
}

template<class TYPE>
void Vecteur<TYPE>::setCurrentIndex(int index) {
	assert(index >= 0 && index < _dim);
	_currentIndex = index;
}

template<class TYPE>
TYPE& Vecteur<TYPE>::getCurrentItem() const {
	assert(_currentIndex >= 0 && _currentIndex < _dim);
	return *(_tab + _currentIndex);
}

template<class TYPE>
const bool Vecteur<TYPE>::operator==(const Vecteur<TYPE>& vect) const
{
	if (_dim == vect._dim)
	{
		for (int i = 0; i < _dim; i++)
			if (this->at(i) != vect.at(i))
				return false;
		return true;
	}
	else
		return false;
}

template<class TYPE>
const Vecteur<TYPE>& Vecteur<TYPE>::operator=(const Vecteur<TYPE>& vect) {
	if (this == &vect)
		return *this;

	clear();

	_tab = new TYPE[vect._dim];
	_dim = vect._dim;

	for (int i = 0; i < _dim; i++)
		*(_tab + i) = *(vect._tab + i);

	return *this;
}

template<class TYPE>
Vecteur<TYPE> Vecteur<TYPE>::operator+(const Vecteur<TYPE>& vect) const {
	Vecteur<TYPE> newVect(_dim + vect._dim);

	for (int i = 0; i < newVect._dim; i++)
	{
		if (i < _dim)
			*(newVect._tab + i) = *(_tab + i);
		else
			*(newVect._tab + i) = *(vect._tab + i - _dim);
	}

	return newVect;
}

template<class TYPE>
const Vecteur<TYPE> Vecteur<TYPE>::operator+=(const Vecteur<TYPE>& vect) {
	*this = operator+(vect);
	return *this;
}

template<class TYPE>
TYPE& Vecteur<TYPE>::operator[](int position) const {
	return this->at(position);
}

template<class TYPE>
Vecteur<TYPE>& Vecteur<TYPE>::operator++() {
	if (_currentIndex < _dim - 1)
		_currentIndex++;
	return *this;
}

template<class TYPE>
Vecteur<TYPE>& Vecteur<TYPE>::operator--() {
	if (_currentIndex > 0)
		_currentIndex--;
	return *this;
}

template<class TYPE>
ostream& operator<<(ostream& output, const Vecteur<TYPE>& vec) {
	vec.print(output);
	return output;
}

template<class TYPE>
istream& operator>>(istream& input, Vecteur<TYPE>& vec) {
	int size;
	input >> size;

	vec.clear();
	vec.resize(size);

	for (int i = 0; i < size; i++) {
		TYPE value;
		input >> value;
		vec[i] = value;
	}

	return input;
}

#endif