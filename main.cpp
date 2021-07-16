#include <iostream>
#include <vector>

#include "Benchmarker.h"

void quick_sort(std::vector<int>& list, int low, int high);
void quick_sort(std::vector<int>& list);

int partition(std::vector<int>& list, int low, int high);
void swap(std::vector<int>& list, int index1, int index2);
void print_list(const std::vector<int>& list);
void print_quicksort_info(int pivot, int low, int high);

void bubble_sort(std::vector<int>& list);

void quick_sort(std::vector<int>& list) {
	InstrumentationTimer timer(__FUNCSIG__);
	quick_sort(list, 0, list.size() - 1);
}

void quick_sort(std::vector<int>& list, int low, int high) {
	if (low < high) {
		int pivot = partition(list, low, high);
		quick_sort(list, low, pivot - 1);
		quick_sort(list, pivot + 1, high);
	}
}

int partition(std::vector<int>& list, int low, int high) {
	int pivot = list[high];
	int swap_index = (low - 1);  
	for (int j = low; j <= high - 1; j++) {
		if (list[j] < pivot)
		{
			swap_index++;
			swap(list, swap_index, j);
		}
	}
	swap(list, swap_index + 1, high);
	return (swap_index + 1);
}

void swap(std::vector<int>& list, int index1, int index2) {
	int temp = list[index1];
	list[index1] = list[index2];
	list[index2] = temp;
}

void print_list(const std::vector<int>& list) {
	std::cout << '{';
	for (auto& item : list) {
		std::cout << " " << item;
	}
	std::cout << " }" << std::endl;
}

void print_quicksort_info(int pivot, int low, int high) {
	std::cout << "Pivot: " << pivot << ", Low: " << low << " High: " << high << std::endl;
}

void bubble_sort(std::vector<int>& list) {
	InstrumentationTimer timer(__FUNCSIG__);
	for (int i = list.size() - 1; i >= 0; i--) {
		for (int j = 0; j < list.size() - 1; j++) {
			if (j == i)
				break;

			if (list[j] > list[j + 1]) {
				swap(list, j, j + 1);
			}
		}
	}
}

int main() {
	Instrumentor::Get().BeginSession("Sorting Algorithms");
	std::vector<int> list = { 9, 7, 5, 11, 12, 2, 14, 3, 10, 6 };
	quick_sort(list);

	std::cout << "Quicksort: ";
	print_list(list);

	list = { 9, 7, 5, 11, 12, 2, 14, 3, 10, 6 };
	bubble_sort(list);
	std::cout << "Bubblesort: ";
	print_list(list);
}
