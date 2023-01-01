#include <iostream>;
#include <ctime> 

using namespace std;

void quickSort(int arr[], int size) {

	int l = 0;
	int r = size - 1;
	int pivot = arr[size / 2];
	do {
		while (arr[l] < pivot) l++;
		while (arr[r] > pivot) r--;

		if (l <= r) {
			swap(arr[l], arr[r]);
			l++;
			r--;
		}

	} while (l <= r);

	if (r > 0) quickSort(arr, r + 1);
	if (l < size) quickSort(&arr[l], size - l);
}




int main() {
	const int length = 1000;
	int arr[length];

	for (int i = 0; i < length; i++) {
		arr[i] = rand() % 10000;
	}

	unsigned int startTime = clock();
	quickSort(arr, length);
	unsigned int endTime = clock();

	for (int i = 0; i < length; i++) {
		cout << arr[i] << '\n';
	}

	unsigned int deltaTime = endTime - startTime;
	cout << deltaTime << '\n';
	return 0;
}