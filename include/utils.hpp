#pragma once

template<typename T>
void inplace_selection_sort(T* array, int n, bool (*pred)(T&,T&)) {
	for (int i=0; i < n; i++) {
		int ptr = i;
		for (int k=ptr+1; k < n; k++) {
			if (pred(array[ptr], array[k])) {
				T temp = array[ptr];
				array[ptr] = array[k];
				array[k] = temp;
			}
		}
	}
}
